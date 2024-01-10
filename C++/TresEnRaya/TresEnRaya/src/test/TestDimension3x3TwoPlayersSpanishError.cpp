#include "TestDimension3x3TwoPlayersSpanishError.hpp"

TestDimension3x3TwoPlayersSpanishError::TestDimension3x3TwoPlayersSpanishError(){}

void TestDimension3x3TwoPlayersSpanishError::IncorrectDimensionAndNumberPlayers()
{
	std::cout << "TEST: Incorrect dimension and number players" << std::endl;

	std::shared_ptr<StartGameViewTestSpanishDimension3x3ErrorNumberPlayers> starGameView = std::make_shared<StartGameViewTestSpanishDimension3x3ErrorNumberPlayers>();
	std::shared_ptr<Language> language = starGameView->getLanguage();

    StartController startController(starGameView, language);
	startController.initializeGame();

	bool isCallsOfGetDimensionCorrect = starGameView->getNumberCallsOfGetDimension() == 3;
	if(!isCallsOfGetDimensionCorrect)
	{
		std::cout << "\tERROR: Incorrect number of calls to get dimension" << std::endl;
	}

	bool isCallsOfGetNumberPlayersCorrect = starGameView->getNumberCallsOfGetNumberPlayers() == 3;
	if(!isCallsOfGetNumberPlayersCorrect)
	{
		std::cout << "\tERROR: Incorrect number of calls to get numbers of players" << std::endl;
	}

	bool isTestCorrect = isCallsOfGetDimensionCorrect && isCallsOfGetNumberPlayersCorrect;
	if (isTestCorrect)
	{
		std::cout << "\tOK" << std::endl;
	}
    else
    {
        std::cout << "\tERROR" << std::endl;
    }
}

void TestDimension3x3TwoPlayersSpanishError::IncorrectCoordenate()
{
    std::cout << "TEST: Incorrect coordenate" << std::endl;

    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(0, 2));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(7, 5));
    allMoves.push_back(Coordenate(0, 0));
    std::string nameWinner = "Ana";

    std::shared_ptr<StartGameViewTestSpanishDimension3x3TwoPlayersAllOk> starGameView = std::make_shared<StartGameViewTestSpanishDimension3x3TwoPlayersAllOk>();
    std::shared_ptr<Language> language = starGameView->getLanguage();

    StartController startController(starGameView, language);

    Game game(startController.initializeGame());

    std::shared_ptr<PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk> turnView = std::make_shared<PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk>(language, allMoves, nameWinner);
    std::vector<std::shared_ptr<PlayTurnViewBase>> turnViews;
    turnViews.push_back(turnView);
    turnViews.push_back(turnView);

    PlayTurnController turnController(game, turnViews);

    turnController.playGame();

    bool isTestCorrect = turnView->getNumberCallsGetCoordenate() == 8;

    if(isTestCorrect)
    {
        std::cout << "\t\tOK" << std::endl;
    }
    else
    {
        std::cout << "\t\tERROR" << std::endl;
    }
}
