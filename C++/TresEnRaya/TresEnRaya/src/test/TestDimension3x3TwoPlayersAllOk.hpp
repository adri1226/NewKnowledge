#ifndef TEST_HPP
#define TEST_HPP

#include "../controller/PlayTurnController.hpp"
#include "../controller/StartController.hpp"
#include "../view/PlayTurnViewBase.hpp"
#include "../view/StartGameViewBase.hpp"
#include "view/PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk.hpp"
#include "view/PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw.hpp"
#include "view/StartGameViewTestSpanishDimension3x3TwoPlayersAllOk.hpp"

class TestDimension3x3TwoPlayersAllOk
{
public:
	TestDimension3x3TwoPlayersAllOk();

	void Rows();
	void Columns();
	void Diagonals();
	void FirstPlayerWin();
	void SecondPlayerWin();
	void Draw();

private:
	void RowAllRight();
    void RowAllRightFirstRow(std::string winnerName);
    void RowAllRightSecondRow(std::string winnerName);
    void RowAllRightThirdRow(std::string winnerName);
	void RowAllLeft();
    void RowAllLeftFirstRow(std::string winnerName);
    void RowAllLeftSecondRow(std::string winnerName);
    void RowAllLeftThirdRow(std::string winnerName);
	void RowInMiddle();
    void RowInMiddleFirstRowLeftRightMiddle(std::string winnerName);
    void RowInMiddleFirstRowRightLeftMiddle(std::string winnerName);
    void RowInMiddleSecondRowLeftRightMiddle(std::string winnerName);
    void RowInMiddleSecondRowRightLeftMiddle(std::string winnerName);
    void RowInMiddleThirdRowLeftRightMiddle(std::string winnerName);
    void RowInMiddleThirdRowRightLeftMiddle(std::string winnerName);
	void ColumnAllBelow();
    void ColumnAllBelowFirstColumn(std::string winnerName);
    void ColumnAllBelowSecondColumn(std::string winnerName);
    void ColumnAllBelowThirdColumn(std::string winnerName);
	void ColumnAllAbove();
    void ColumnAllAboveFirstColumn(std::string winnerName);
    void ColumnAllAboveSecondColumn(std::string winnerName);
    void ColumnAllAboveThirdColumn(std::string winnerName);
	void ColumnInMiddle();
    void ColumnInMiddleFirstColumTopBottomMiddle(std::string winnerName);
    void ColumnInMiddleFirstColumnBottomTopMiddle(std::string winnerName);
    void ColumnInMiddleSecondColumnTopBottomMiddle(std::string winnerName);
    void ColumnInMiddleSecondColumnBottomTopMiddle(std::string winnerName);
    void ColumnInMiddleThirdColumnTopBottomMiddle(std::string winnerName);
    void ColumnInMiddleThirdColumnBottomTopMiddle(std::string winnerName);
	void DiagonalMain();
    void DiagonalMainTopToBottom(std::string winnerName);
    void DiagonalMainBottomToTop(std::string winnerName);
    void DiagonalMainTopBottomMiddle(std::string winnerName);
    void DiagonalMainBottomTopMiddle(std::string winnerName);
	void DiagonalSecondary();
    void DiagonalSecondaryTopToBottom(std::string winnerName);
    void DiagonalSecondaryBottomToTop(std::string winnerName);
    void DiagonalSecondaryTopBottomMiddle(std::string winnerName);
    void DiagonalSecondaryBottomTopMiddle(std::string winnerName);
	void Dimension3x3TwoPlayersAllOk(std::string testName, std::vector<Coordenate> allMoves, std::string nameWinner);

};

#endif // TEST_HPP
