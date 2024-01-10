#include "TestDimension3x3TwoPlayersAllOk.hpp"

TestDimension3x3TwoPlayersAllOk::TestDimension3x3TwoPlayersAllOk(){}

void TestDimension3x3TwoPlayersAllOk::Rows()
{
	RowAllRight();
	RowAllLeft();
	RowInMiddle();
}

void TestDimension3x3TwoPlayersAllOk::Columns()
{
	ColumnAllBelow();
	ColumnAllAbove();
	ColumnInMiddle();
}

void TestDimension3x3TwoPlayersAllOk::Diagonals()
{
	DiagonalMain();
    DiagonalSecondary();
}

void TestDimension3x3TwoPlayersAllOk::FirstPlayerWin()
{
    std::cout << "TEST: First player win" << std::endl;

    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(0, 2));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(0, 0));
    std::string winnerName = "Ana";

    Dimension3x3TwoPlayersAllOk("", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::SecondPlayerWin()
{
    std::cout << "TEST: Second player win" << std::endl;

    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(1, 2));
    allMoves.push_back(Coordenate(2, 0));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(0, 0));
    std::string winnerName = "David";

    Dimension3x3TwoPlayersAllOk("", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::Draw()
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(2, 1));
    allMoves.push_back(Coordenate(2, 2));
    allMoves.push_back(Coordenate(2, 0));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(1, 2));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(0, 2));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(0, 0));

    std::cout << "TEST: Draw" << std::endl;

    std::shared_ptr<StartGameViewTestSpanishDimension3x3TwoPlayersAllOk> starGameView = std::make_shared<StartGameViewTestSpanishDimension3x3TwoPlayersAllOk>();
    std::shared_ptr<Language> language = starGameView->getLanguage();

    StartController startController(starGameView, language);

    Game game(startController.initializeGame());

    bool isNumberCallsOfGetPlayerNameCorrect = starGameView->getNumberCallsOfGetPlayerName() == 2;
    if(!isNumberCallsOfGetPlayerNameCorrect)
    {
        std::cout << "\tERROR: No se ha llamado 2 veces a getPlayerName" << std::endl;
        return;
    }

    bool isDimensionCorrect = game.getDimension().numberRows == 3 && game.getDimension().numberColumns == 3;
    bool isNumberPlayersCorrect = game.getNumberPlayers() == 2;

    if(!isDimensionCorrect)
    {
        std::cout << "\t\tERROR: No son las mismas dimensiones" << std::endl;
        return;
    }

    if(!isNumberPlayersCorrect)
    {
        std::cout << "\tERROR: No son el mismo numero de jugadores" << std::endl;
        return;
    }

    std::shared_ptr<PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw> turnView = std::make_shared<PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw>(language, allMoves, "");
    std::vector<std::shared_ptr<PlayTurnViewBase>> turnViews;
    turnViews.push_back(turnView);
    turnViews.push_back(turnView);

    PlayTurnController turnController(game, turnViews);

    turnController.playGame();

    bool isTestCorrect = isDimensionCorrect && isNumberPlayersCorrect && turnView->getIsTestCorrect();

    if(isTestCorrect)
    {
        std::cout << "\tOK" << std::endl;
    }
    else
    {
        std::cout << "\t\tERROR" << std::endl;
    }
}

void TestDimension3x3TwoPlayersAllOk::RowAllRight()
{
    std::cout << "TEST: Rows from left to right" << std::endl;

    std::string winnerName = "Ana";

    RowAllRightFirstRow(winnerName);
    RowAllRightSecondRow(winnerName);
    RowAllRightThirdRow(winnerName);
}

void TestDimension3x3TwoPlayersAllOk::RowAllRightFirstRow(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(0, 2));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(0, 0));

    Dimension3x3TwoPlayersAllOk("First Row", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::RowAllRightSecondRow(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(1, 2));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(1, 0));

    Dimension3x3TwoPlayersAllOk("Second Row", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::RowAllRightThirdRow(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(2, 2));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(2, 1));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(2, 0));

    Dimension3x3TwoPlayersAllOk("Third Row", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::RowAllLeft()
{
    std::cout << "TEST: Rows from right to left" << std::endl;

    std::string winnerName = "Ana";

    RowAllLeftFirstRow(winnerName);
    RowAllLeftSecondRow(winnerName);
    RowAllLeftThirdRow(winnerName);
}

void TestDimension3x3TwoPlayersAllOk::RowAllLeftFirstRow(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(0, 2));

    Dimension3x3TwoPlayersAllOk("First Row", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::RowAllLeftSecondRow(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(1, 2));

    Dimension3x3TwoPlayersAllOk("Second Row", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::RowAllLeftThirdRow(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(2, 0));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(2, 1));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(2, 2));

    Dimension3x3TwoPlayersAllOk("Third Row", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::RowInMiddleFirstRowLeftRightMiddle(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(0, 2));

    Dimension3x3TwoPlayersAllOk("First Row - Left right middle piece", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::RowInMiddleFirstRowRightLeftMiddle(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(0, 2));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(0, 0));

    Dimension3x3TwoPlayersAllOk("First Row - Right left middle piece", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::RowInMiddleSecondRowLeftRightMiddle(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(1, 2));

    Dimension3x3TwoPlayersAllOk("Second Row - Left right middle piece", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::RowInMiddleSecondRowRightLeftMiddle(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(1, 2));
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(1, 0));

    Dimension3x3TwoPlayersAllOk("Second Row - Right left middle piece", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::RowInMiddleThirdRowLeftRightMiddle(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(2, 1));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(2, 0));
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(2, 2));

    Dimension3x3TwoPlayersAllOk("Third Row - Left right middle piece", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::RowInMiddleThirdRowRightLeftMiddle(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(2, 1));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(2, 2));
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(2, 0));

    Dimension3x3TwoPlayersAllOk("Third Row - Right left middle piece", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::RowInMiddle()
{
	std::cout << "TEST: Rows last piece in middle" << std::endl;

    std::string winnerName = "Ana";

    RowInMiddleFirstRowLeftRightMiddle(winnerName);
    RowInMiddleFirstRowRightLeftMiddle(winnerName);
    RowInMiddleSecondRowLeftRightMiddle(winnerName);
    RowInMiddleSecondRowRightLeftMiddle(winnerName);
    RowInMiddleThirdRowLeftRightMiddle(winnerName);
    RowInMiddleThirdRowRightLeftMiddle(winnerName);
}

void TestDimension3x3TwoPlayersAllOk::ColumnAllBelow()
{
    std::cout << "TEST: Columns from top to bottom" << std::endl;

    std::string winnerName = "Ana";

    ColumnAllBelowFirstColumn(winnerName);
    ColumnAllBelowSecondColumn(winnerName);
    ColumnAllBelowThirdColumn(winnerName);
}

void TestDimension3x3TwoPlayersAllOk::ColumnAllBelowFirstColumn(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(2, 0));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(0, 0));

    Dimension3x3TwoPlayersAllOk("First Column", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::ColumnAllBelowSecondColumn(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(2, 1));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(0, 1));

    Dimension3x3TwoPlayersAllOk("Second Column", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::ColumnAllBelowThirdColumn(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(2, 2));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(1, 2));
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(0, 2));

    Dimension3x3TwoPlayersAllOk("Third Column", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::ColumnAllAbove()
{
    std::cout << "TEST: Columns from bottom to top" << std::endl;

    std::string winnerName = "Ana";

    ColumnAllAboveFirstColumn(winnerName);
    ColumnAllAboveSecondColumn(winnerName);
    ColumnAllAboveThirdColumn(winnerName);
}

void TestDimension3x3TwoPlayersAllOk::ColumnAllAboveFirstColumn(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(2, 0));

    Dimension3x3TwoPlayersAllOk("First Column", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::ColumnAllAboveSecondColumn(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(2, 1));

    Dimension3x3TwoPlayersAllOk("Second Column", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::ColumnAllAboveThirdColumn(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(0, 2));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(1, 2));
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(2, 2));

    Dimension3x3TwoPlayersAllOk("Third Column", allMoves, winnerName);
}


void TestDimension3x3TwoPlayersAllOk::ColumnInMiddle()
{
    std::cout << "TEST: Columns last piece in middle" << std::endl;

    std::string winnerName = "Ana";

    ColumnInMiddleFirstColumTopBottomMiddle(winnerName);
    ColumnInMiddleFirstColumnBottomTopMiddle(winnerName);
    ColumnInMiddleSecondColumnTopBottomMiddle(winnerName);
    ColumnInMiddleSecondColumnBottomTopMiddle(winnerName);
    ColumnInMiddleThirdColumnTopBottomMiddle(winnerName);
    ColumnInMiddleThirdColumnBottomTopMiddle(winnerName);
}

void TestDimension3x3TwoPlayersAllOk::ColumnInMiddleFirstColumTopBottomMiddle(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(2, 0));

    Dimension3x3TwoPlayersAllOk("First Column - Top bottom middle piece", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::ColumnInMiddleFirstColumnBottomTopMiddle(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(2, 0));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(0, 0));

    Dimension3x3TwoPlayersAllOk("First Column - Bottom top middle piece", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::ColumnInMiddleSecondColumnTopBottomMiddle(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(2, 1));

    Dimension3x3TwoPlayersAllOk("Second Column - Top bottom middle piece", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::ColumnInMiddleSecondColumnBottomTopMiddle(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(2, 1));
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(0, 1));

    Dimension3x3TwoPlayersAllOk("Second Column - Bottom top middle piece", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::ColumnInMiddleThirdColumnTopBottomMiddle(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(1, 2));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(0, 2));
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(2, 2));

    Dimension3x3TwoPlayersAllOk("Third Column - Top bottom middle piece", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::ColumnInMiddleThirdColumnBottomTopMiddle(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(1, 2));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(2, 2));
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(0, 2));

    Dimension3x3TwoPlayersAllOk("Third Column - Bottom top middle piece", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::DiagonalMain()
{
    std::cout << "TEST: Diagonal Main" << std::endl;

    std::string winnerName = "Ana";

    DiagonalMainTopToBottom(winnerName);
    DiagonalMainBottomToTop(winnerName);
    DiagonalMainTopBottomMiddle(winnerName);
    DiagonalMainBottomTopMiddle(winnerName);
}

void TestDimension3x3TwoPlayersAllOk::DiagonalMainTopToBottom(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(2, 2));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(0, 0));

    Dimension3x3TwoPlayersAllOk("Top to bottom", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::DiagonalMainBottomToTop(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(2, 2));

    Dimension3x3TwoPlayersAllOk("Bottom to top", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::DiagonalMainTopBottomMiddle(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(2, 2));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(0, 0));

    Dimension3x3TwoPlayersAllOk("Top bottom middle piece", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::DiagonalMainBottomTopMiddle(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(0, 0));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(2, 2));

    Dimension3x3TwoPlayersAllOk("Bottom top middle piece", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::DiagonalSecondary()
{
    std::cout << "TEST: Diagonal Secondary" << std::endl;

    std::string winnerName = "Ana";

    DiagonalSecondaryTopToBottom(winnerName);
    DiagonalSecondaryBottomToTop(winnerName);
    DiagonalSecondaryTopBottomMiddle(winnerName);
    DiagonalSecondaryBottomTopMiddle(winnerName);
}

void TestDimension3x3TwoPlayersAllOk::DiagonalSecondaryTopToBottom(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(2, 0));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(0, 2));

    Dimension3x3TwoPlayersAllOk("Top to bottom", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::DiagonalSecondaryBottomToTop(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(0, 2));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(2, 0));

    Dimension3x3TwoPlayersAllOk("Bottom to top", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::DiagonalSecondaryTopBottomMiddle(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(2, 0));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(0, 2));

    Dimension3x3TwoPlayersAllOk("Top bottom middle piece", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::DiagonalSecondaryBottomTopMiddle(std::string winnerName)
{
    std::vector<Coordenate> allMoves;
    allMoves.push_back(Coordenate(1, 1));
    allMoves.push_back(Coordenate(1, 0));
    allMoves.push_back(Coordenate(0, 2));
    allMoves.push_back(Coordenate(0, 1));
    allMoves.push_back(Coordenate(2, 0));

    Dimension3x3TwoPlayersAllOk("Bottom top middle piece", allMoves, winnerName);
}

void TestDimension3x3TwoPlayersAllOk::Dimension3x3TwoPlayersAllOk(std::string testName,
		std::vector<Coordenate> allMoves, std::string nameWinner)
{
	std::cout << "\tTEST: " << testName << std::endl;

	std::shared_ptr<StartGameViewTestSpanishDimension3x3TwoPlayersAllOk> starGameView = std::make_shared<StartGameViewTestSpanishDimension3x3TwoPlayersAllOk>();
	std::shared_ptr<Language> language = starGameView->getLanguage();

    StartController startController(starGameView, language);

	Game game(startController.initializeGame());

    bool isNumberCallsOfGetPlayerNameCorrect = starGameView->getNumberCallsOfGetPlayerName() == 2;
    if(!isNumberCallsOfGetPlayerNameCorrect)
    {
        std::cout << "\t\tERROR: No se ha llamado 2 veces a getPlayerName" << std::endl;
        return;
    }

	bool isDimensionCorrect = game.getDimension().numberRows == 3 && game.getDimension().numberColumns == 3;
	bool isNumberPlayersCorrect = game.getNumberPlayers() == 2;

	if(!isDimensionCorrect)
	{
		std::cout << "\t\tERROR: No son las mismas dimensiones" << std::endl;
		return;
	}

	if(!isNumberPlayersCorrect)
	{
		std::cout << "\t\tERROR: No son el mismo numero de jugadores" << std::endl;
		return;
	}

	std::shared_ptr<PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk> turnView = std::make_shared<PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk>(language, allMoves, nameWinner);
    std::vector<std::shared_ptr<PlayTurnViewBase>> turnViews;
    turnViews.push_back(turnView);
    turnViews.push_back(turnView);

    PlayTurnController turnController(game, turnViews);

	turnController.playGame();

	if(!turnView->getIsNameWinnerCorrect())
	{
		std::cout << "\t\tERROR: No es el mismo ganador" << std::endl;
	}

    if(!turnView->getIsMessageWinnerCorrect())
    {
    	std::cout << "\t\tERROR: No es el mismo mensaje de ganador" << std::endl;
    }

    bool isTestCorrect = isDimensionCorrect && isNumberPlayersCorrect && turnView->getIsTestCorrect();

    if(isTestCorrect)
    {
    	std::cout << "\t\tOK" << std::endl;
    }
    else
    {
    	std::cout << "\t\tERROR" << std::endl;
    }
}
