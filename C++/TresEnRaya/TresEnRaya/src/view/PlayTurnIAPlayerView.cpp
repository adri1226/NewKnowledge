#include "PlayTurnIAPlayerView.hpp"

PlayTurnIAPlayerView::PlayTurnIAPlayerView(): PlayTurnViewBase()
{
    _board = nullptr;
    initializePosibleWins();
}

PlayTurnIAPlayerView::PlayTurnIAPlayerView(std::shared_ptr<Language> language)
    : PlayTurnViewBase(language)
{
    _board = nullptr;
    initializePosibleWins();
}

PlayTurnIAPlayerView::PlayTurnIAPlayerView(std::shared_ptr<Language> language, std::shared_ptr<const Board> board)
    : PlayTurnViewBase(language), _board(board)
{
    initializePosibleWins();
}

Coordenate PlayTurnIAPlayerView::getCoordenate(Dimension boardDimension, const char *playerName, bool incorrect)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Coordenate coordenate;

    if(_board != nullptr)
    {
        std::vector<Coordenate> coordenatePosibleWin = getEmptySquareInBoard(boardDimension);
        coordenate = getPossibleWin(coordenatePosibleWin);
    }
    else
    {
        int x = std::rand() % boardDimension.numberRows;
        int y = std::rand() % boardDimension.numberColumns;
        coordenate = Coordenate(x, y);
    }

    return coordenate;
}

// PUEDO SACAR ESTO A UNA CLASE COMUN TANTO PARA EL CONTROLADOR COMO PARA LA IA
void PlayTurnIAPlayerView::initializePosibleWins()
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
}

std::vector<Coordenate> PlayTurnIAPlayerView::getEmptySquareInBoard(Dimension boardDimension)
{
    std::vector<Coordenate> coordenatesEmpty;

    for(int coordX{0}; coordX < boardDimension.numberRows; coordX++)
    {
        for(int coordY{0}; coordY < boardDimension.numberColumns; coordY++)
        {
            Coordenate coordEmpty{coordX, coordY};

            if(_board->isSquareEmpty(coordEmpty))
            {
                coordenatesEmpty.push_back(coordEmpty);
            }
        }
    }

    return coordenatesEmpty;
}

Coordenate PlayTurnIAPlayerView::getPossibleWin(std::vector<Coordenate> coordenatePosibleWin)
{
    Coordenate coordenate;
    std::vector<Coordenate> coordenateDiscarted;

    size_t coorRandom;
    bool isPosibleWin = false;
    WinValidator winValidator{_board};

    // Si puedo ganar la pongo, sino cojo otra hasta que me quede sin piezas
    do
    {
        coorRandom = std::rand() % coordenatePosibleWin.size();

        isPosibleWin = winValidator.isWin(coordenatePosibleWin[coorRandom]);

        if(!isPosibleWin)
        {
            Coordenate coordNoWin = coordenatePosibleWin[coorRandom];
            coordenatePosibleWin.erase(coordenatePosibleWin.begin() + coorRandom);
            coordenateDiscarted.push_back(coordNoWin);
        }
    }
    while(!isPosibleWin && !coordenatePosibleWin.empty());

    // Si me quedo sin piezas cojo una al azar de las descartadas
    if(coordenatePosibleWin.empty())
    {
        coordenate = coordenateDiscarted[std::rand() % coordenateDiscarted.size()];
    }
    else
    {
        coordenate = coordenatePosibleWin[coorRandom];
    }

    return coordenate;
}
