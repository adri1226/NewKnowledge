#include "PlayTurnController.hpp"

PlayTurnController::PlayTurnController(Game game, std::vector<std::shared_ptr<PlayTurnViewBase>> views):
    _game(game), _views(views)
{
	_posibleWins.push_back(std::vector<Coordenate>{Coordenate(1, 0), Coordenate(2, 0)});
		// Las dos coordenadas a la derecha en la misma fila
	_posibleWins.push_back(std::vector<Coordenate>{Coordenate(-1, 0), Coordenate(-2, 0)});
		// Las dos coordenadas a la izquierda en la misma fila
	_posibleWins.push_back(std::vector<Coordenate>{Coordenate(0, 1), Coordenate(0, 2)});
		// Las dos coordenadas encima en la misma columna
	_posibleWins.push_back(std::vector<Coordenate>{Coordenate(0, -1), Coordenate(0, -2)});
		// Las dos coordenadas debajo en la misma columna
	_posibleWins.push_back(std::vector<Coordenate>{Coordenate(-1, 0), Coordenate(1, 0)});
		// Las dos coordenadas una a la izquierda en la fila y la otra en la derecha de la fila
	_posibleWins.push_back(std::vector<Coordenate>{Coordenate(0, 1), Coordenate(0, -1)});
		// Las dos coordenadas una encima en la columna y la otra debajo en la columna
	_posibleWins.push_back(std::vector<Coordenate>{Coordenate(1, 1), Coordenate(2, 2)});
		// Las dos coordenadas de la diagonal de la derecha en la fila y arriba en la columna
	_posibleWins.push_back(std::vector<Coordenate>{Coordenate(1, -1), Coordenate(2, -2)});
		// Las dos coordenadas de la diagonal de la derecha en la fila y debajo en la columna
	_posibleWins.push_back(std::vector<Coordenate>{Coordenate(-1, 1), Coordenate(-2, 2)});
		// Las dos coordenadas de la diagonal de la izquierda en la fila y arriba en la columna
	_posibleWins.push_back(std::vector<Coordenate>{Coordenate(-1, -1), Coordenate(-2, -2)});
		// Las dos coordenadas de la diagonal de la izquierda en la fila y abajo en la columna
	_posibleWins.push_back(std::vector<Coordenate>{Coordenate(1, 1), Coordenate(-1, -1)});
		// Las dos coordenadas de la diagonal una a la dercha y arriba, y la otra a la izquierda y debajo
	_posibleWins.push_back(std::vector<Coordenate>{Coordenate(1, -1), Coordenate(-1, 1)});
		// Las dos coordenadas de la diagonal una a la derecha y abajo, y la otra a la izquierda y encima

	_ischeckConditionToWinInProgress = false;
}

void PlayTurnController::playGame()
{

	bool isWin = false;
	bool isOver = false;
    WinValidator winValidator{_game.getBoard()};
	do
	{
        getActualView()->cleanScreen();
        getActualView()->showBoard(*_game.getBoard());

		Coordenate coordenate = playTurn(_game.getActualPlayer());
		isOver = _game.isOver();

        isWin = checkWin(coordenate);

		_game.increseTurn();

	}while(!isOver && !isWin);

    getActualView()->showBoard(*_game.getBoard());

	if(isWin)
	{
        size_t previousTurn = _game.getTurn() - 1;
        getViewByTurn(previousTurn)->showWinner(_game.getPlayerByTurn(previousTurn)->getName().c_str());
	}
	else if(isOver)
	{
        getActualView()->showGameDraw();
	}
}

bool PlayTurnController::putPiece(Piece piece, Coordenate coordenate)
{
	return _game.putPiece(piece, coordenate);
}

Coordenate PlayTurnController::playTurn(std::shared_ptr<Player> player)
{
	Coordenate coordenate;

	bool isPieceCorrect = true;

	do
	{
        coordenate = getActualView()->getCoordenate(_game.getDimension(), player->getName().c_str(), !isPieceCorrect);
		isPieceCorrect = putPiece(player->getPiece(), coordenate);
	}while(!isPieceCorrect);

	return coordenate;
}

bool PlayTurnController::checkWin(const Coordenate coordenate)
{
    // Para no empezar en los primeros turnos a calcular si se ha ganado cuando no hace falta porque no hay suficientes piezas
    // Para saber en que turno debo empezar a calcular sigo esa formula:
    // El 3 es porque se necesitan 3 piezas para ganar a las 3 en raya
    if(_game.getTurn() < ((_game.getNumberPlayers() * 3) - _game.getNumberPlayers())) return false;

    bool isWin = false;

    // Lanzo ya la función de forma asíncrona
    std::future<bool> posibleWin = std::async(std::launch::async, &PlayTurnController::checkConditionToWin, this, coordenate);

    // Lanzo la funcion de la barra de carga
    std::thread viewShowProgressBar(&PlayTurnController::progressCheckCondition, this);

    // Aqui se queda el hilo principal esperando a que se termine de ejecutar el hilo para recoger el valor
    isWin = posibleWin.get();

    // Hago join de la funcion de la barra de carga
    viewShowProgressBar.join();

    return isWin;
}

bool PlayTurnController::areFinish(std::vector<std::future<bool>> futures)
{
	bool areFinis = true;
	for(size_t i{0}; i < futures.size(); i++)
	{
		areFinis &= futures[i].valid();
	}

	return areFinis;
}

bool PlayTurnController::isPossibleWin(std::vector<std::future<bool>> futures)
{
	bool value = false;

	for(size_t i{0}; i < futures.size(); i++)
	{
		if(futures[i].valid())
		{
			value |= futures[i].get();
		}
	}

	return value;
}

bool PlayTurnController::checkConditionToWin(const Coordenate coordenate)
{
	_ischeckConditionToWinInProgress = false;

	bool isWin{false};

	std::vector<std::future<bool>> futures;
	size_t subVectorSize = _posibleWins.size() / NUM_THREADS;

	for(size_t actualFuture{0}; actualFuture < NUM_THREADS; actualFuture++)
	{
		size_t startPosition = actualFuture * subVectorSize;
		size_t endPosition = startPosition + subVectorSize;

		endPosition = std::min(endPosition, _posibleWins.size());

		std::vector<std::vector<Coordenate>> subPossibleWin(&_posibleWins[startPosition], &_posibleWins[endPosition]);

//		std::future<bool> isPossibleWin = std::async(std::launch::async, &checkHalfConditionToWin, this, coordenate, subPossibleWin);

        futures.push_back(std::async(std::launch::async, &PlayTurnController::checkHalfConditionToWin, this, coordenate, subPossibleWin));
	}

	bool isRunning = true;

	while(!isWin && isRunning)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));

//		isWin |= isPossibleWin(futures);
//		isRunning = areFinish(futures);

		for(size_t i{0}; i < futures.size(); i++)
		{
			if(futures[i].valid())
			{
				isWin |= futures[i].get();
			}

			isRunning &= futures[i].valid();
		}
//		isRunning = !isRunning;

	}


	_ischeckConditionToWinInProgress = true;
	return isWin;
}

bool PlayTurnController::checkHalfConditionToWin(const Coordenate coordenate, std::vector<std::vector<Coordenate>> posibleWins)
{
	bool isWin{false};
	size_t actualPosition{0};


	while(!isWin && actualPosition < posibleWins.size())
	{
		Coordenate coordenate2 = coordenate + posibleWins[actualPosition][0];
		Coordenate coordenate3 = coordenate + posibleWins[actualPosition][1];
		// METER UN SLEEP DE 5 SEGUNDOS
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

		isWin = areTicTacToe(coordenate, coordenate2, coordenate3);

		actualPosition++;
	}


	return isWin;
}

bool PlayTurnController::areTicTacToe(Coordenate coordenate1, Coordenate coordenate2,Coordenate coordenate3)
{
	if(_game.isCoodenateCorrect(coordenate1) && _game.isCoodenateCorrect(coordenate2) && _game.isCoodenateCorrect(coordenate3))
	{
		return areEquals(_game.getPieceAtTurn(coordenate1), _game.getPieceAtTurn(coordenate2), _game.getPieceAtTurn(coordenate3));
	}

	return false;
}

bool PlayTurnController::areEquals(const std::shared_ptr<Piece> first,const std::shared_ptr<Piece> second, const std::shared_ptr<Piece> third)
{
	if(first != nullptr && second != nullptr && third != nullptr)
	{
		if(*first == *second && *first == *third)
		{
			return true;
		}
	}

	return false;
}

void PlayTurnController::progressCheckCondition()
{
	while(!_ischeckConditionToWinInProgress)
	{
        getActualView()->showProgressBar();
    }
}

std::shared_ptr<PlayTurnViewBase> PlayTurnController::getViewByTurn(size_t turn)
{
    return _views.at(turn % _game.getNumberPlayers());
}

std::shared_ptr<PlayTurnViewBase> PlayTurnController::getActualView()
{
    return getViewByTurn(_game.getTurn());
}
