#include "StartGameView.hpp"

StartGameView::StartGameView(): StartGameViewBase(){}

StartGameView::StartGameView(std::shared_ptr<Language> language): StartGameViewBase(language){}

std::shared_ptr<Language> StartGameView::getLanguage()
{
	size_t languageSelected;
	do{
		printf(_language->getMessage(Language::Message::LanguageChoose));

	    for(size_t language{0}; language < _languagesAvailables.getNumberLanguages(); language++)
	    {
	        std::stringstream ssPrint;
	        ssPrint << "\n\t" << language << " - " << _languagesAvailables.toVectorString()[language];

	        printf(ssPrint.str().c_str());
	    }

	    printf(_language->getMessage(Language::Message::LanguageSelected));
		std::cin >> languageSelected;
	}
	while(languageSelected < 0 || languageSelected >  (_languagesAvailables.getNumberLanguages()-1));

	std::shared_ptr<Language> language = LanguageFactory::createLanguage(static_cast<LanguagesAvailables::Availables>(languageSelected));
	_language = language;

	return language;
}

Dimension StartGameView::getDimension(size_t minimalDimension, size_t maximalDimension, bool incorrect)
{
	Dimension dimension;

	if(incorrect)
		printf(_language->getMessage(Language::Message::DimensionIncorrect), minimalDimension, minimalDimension, maximalDimension, maximalDimension);
	else
		printf(_language->getMessage(Language::Message::DimensionGet), minimalDimension, minimalDimension, maximalDimension, maximalDimension);

	std::cin >> dimension.numberRows >> dimension.numberColumns;

	return dimension;
}

std::string StartGameView::getPlayerName()
{
	std::string playerName;

	printf(_language->getMessage(Language::Message::PlayerEnterName));

	std::cin >> playerName;

	return playerName;
}

std::pair<size_t, Piece> StartGameView::getPiece(std::vector<Piece> piecesAvailable)
{
	size_t pieceSelectedAt;

	do
	{
		printf(_language->getMessage(Language::Message::PieceChoose));

		for(size_t piece{0}; piece < piecesAvailable.size(); piece++)
		{
			std::stringstream ssPrint;
			ssPrint << "\n\t" << piece << " - " << piecesAvailable.at(piece).toString();

			printf(ssPrint.str().c_str());
		}

		printf(_language->getMessage(Language::Message::PieceSelected));

		std::cin >> pieceSelectedAt;
	}
	while(pieceSelectedAt < 0 || pieceSelectedAt > (piecesAvailable.size()-1));

	std::pair<size_t, Piece> pairPositionInVectorAndPiece = std::make_pair(pieceSelectedAt, piecesAvailable.at(pieceSelectedAt));

	return pairPositionInVectorAndPiece;
}

size_t StartGameView::getNumberPlayers(size_t minimalNumberPlayers, size_t maximalNumberPlayers, bool incorrect)
{
	size_t numberPlayers;

	if(incorrect)
		printf(_language->getMessage(Language::Message::NumberOfPlayerIncorrect), minimalNumberPlayers, maximalNumberPlayers);
	else
		printf(_language->getMessage(Language::Message::NumberOfPlayerGet), minimalNumberPlayers, maximalNumberPlayers);

	std::cin >> numberPlayers;

    return numberPlayers;
}

bool StartGameView::isIAPlayer()
{
    bool isIAPlayer = false;
    char iaPlayer;
    bool isCharCorrect = false;

    do
    {
        printf(_language->getMessage(Language::Message::IsIAPlayer));
        std::cin >> iaPlayer;
        isCharCorrect = iaPlayer == 's' || iaPlayer == 'n';
    }
    while (!isCharCorrect);

    isIAPlayer = iaPlayer == 's';

    return isIAPlayer;
}
