#include "PlayTurnRealPlayerView.hpp"

PlayTurnRealPlayerView::PlayTurnRealPlayerView(): PlayTurnViewBase(){}

PlayTurnRealPlayerView::PlayTurnRealPlayerView(std::shared_ptr<Language> language): PlayTurnViewBase(language){}

Coordenate PlayTurnRealPlayerView::getCoordenate(Dimension boardDimension, const char * playerName, bool incorrect)
{
	size_t x, y;

	if(incorrect)
		printf(_language->getMessage(Language::Message::CoordenateIncorrect), playerName, boardDimension.numberRows, boardDimension.numberColumns);
	else
		printf(_language->getMessage(Language::Message::CoordenateGet), playerName, boardDimension.numberRows, boardDimension.numberColumns);

	std::cin >> x >> y;

	return Coordenate(x, y);
}
