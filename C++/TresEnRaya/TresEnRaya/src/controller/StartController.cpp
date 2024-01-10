#include "StartController.hpp"

StartController::StartController(std::shared_ptr<StartGameViewBase> view, std::shared_ptr<Language> language)
    : _view(view), _language(language)
{
    _piecesAvailable.push_back(Piece(Piece::Color::White));
    _piecesAvailable.push_back(Piece(Piece::Color::Black));
    _piecesAvailable.push_back(Piece(Piece::Color::Red));
    _piecesAvailable.push_back(Piece(Piece::Color::Purple));
}

Game StartController::initializeGame()
{
    _board = std::make_shared<Board>(initializeBoard());
    Players players = initiliazePlayers();
    Game game(*_board, players);
    return game;
}

std::vector<std::shared_ptr<PlayTurnViewBase>> StartController::initializePlayTurnViews()
{
    return _viewsPlayTurn;
}

Board StartController::initializeBoard()
{
    Dimension boardDimension;
    bool isBoardCorrect = true;

    do
    {
        boardDimension = _view->getDimension(MIN_ROW_COLUMN, MAX_ROW_COLUM, !isBoardCorrect);
        isBoardCorrect = boardDimension.numberColumns >= MIN_ROW_COLUMN && boardDimension.numberColumns <= MAX_ROW_COLUM
        		&& boardDimension.numberRows >= MIN_ROW_COLUMN && boardDimension.numberRows <= MAX_ROW_COLUM;
    } while(!isBoardCorrect);

    return Board{boardDimension};
}

Player StartController::intiliazePlayer()
{
	std::string name = _view->getPlayerName();

	std::pair<size_t, Piece> pairPositionInVectorAndPiece = _view->getPiece(_piecesAvailable);

    Player player {name, pairPositionInVectorAndPiece.second};

    _piecesAvailable.erase(_piecesAvailable.begin() + pairPositionInVectorAndPiece.first);
    
    return player;
}

Player StartController::intiliazeIAPlayer()
{
    std::string name = "IA";

    std::pair<size_t, Piece> pairPositionInVectorAndPiece = _view->getPiece(_piecesAvailable);

    Player player {name, pairPositionInVectorAndPiece.second};

    _piecesAvailable.erase(_piecesAvailable.begin() + pairPositionInVectorAndPiece.first);

    return player;
}

Players StartController::initiliazePlayers()
{
    size_t numberPlayers;
    bool isNumberPlayersCorrect = true;

    do
    {
        numberPlayers = _view->getNumberPlayers(MIN_NUMBER_PLAYERS, MAX_NUMBER_PLAYERS, !isNumberPlayersCorrect);
        isNumberPlayersCorrect = numberPlayers >= MIN_NUMBER_PLAYERS && numberPlayers <= MAX_NUMBER_PLAYERS;
    }while(!isNumberPlayersCorrect);

    Players players;
    for (size_t numPlayer{0}; numPlayer < numberPlayers; numPlayer++)
    {
        bool isIAPlayer = _view->isIAPlayer();
        std::shared_ptr<PlayTurnViewBase> playTurnView;
        if(isIAPlayer)
        {
            Player player = intiliazeIAPlayer();
            playTurnView = std::make_shared<PlayTurnIAPlayerView>(_language, _board);
            players.addPlayer(player);
        }
        else
        {
            Player player = intiliazePlayer();
            playTurnView = std::make_shared<PlayTurnRealPlayerView>(_language);
            players.addPlayer(player);
        }
        _viewsPlayTurn.push_back(playTurnView);
    }
    
    return players;
}
