#include "StartGameViewTestSpanishDimension3x3ErrorNumberPlayers.hpp"

StartGameViewTestSpanishDimension3x3ErrorNumberPlayers::StartGameViewTestSpanishDimension3x3ErrorNumberPlayers(): StartGameViewBase()
{
	_numberCallsOFGetNumberPlayers = 0;
	_numberCallsOfGetDimension = 0;
}

StartGameViewTestSpanishDimension3x3ErrorNumberPlayers::StartGameViewTestSpanishDimension3x3ErrorNumberPlayers(std::shared_ptr<Language> language): StartGameViewBase(language)
{
	_numberCallsOFGetNumberPlayers = 0;
	_numberCallsOfGetDimension = 0;
}

std::shared_ptr<Language> StartGameViewTestSpanishDimension3x3ErrorNumberPlayers::getLanguage()
{
	return nullptr;
}

Dimension StartGameViewTestSpanishDimension3x3ErrorNumberPlayers::getDimension(size_t minimalDimension, size_t maximalDimension, bool incorrect)
{
	if(_numberCallsOfGetDimension == 0 || _numberCallsOfGetDimension == 1)
	{
		_numberCallsOfGetDimension++;
		return Dimension{0, 0};
	}
	else
	{
		_numberCallsOfGetDimension++;
		return Dimension{3, 3};
	}
}

std::string StartGameViewTestSpanishDimension3x3ErrorNumberPlayers::getPlayerName()
{
    return "";
}

std::pair<size_t, Piece> StartGameViewTestSpanishDimension3x3ErrorNumberPlayers::getPiece(std::vector<Piece> piecesAvailable)
{
	return std::make_pair(0, piecesAvailable[0]);
}

size_t StartGameViewTestSpanishDimension3x3ErrorNumberPlayers::getNumberPlayers(size_t minimalNumberPlayers, size_t maximalNumberPlayers, bool incorrect)
{
	if(_numberCallsOFGetNumberPlayers == 0 || _numberCallsOFGetNumberPlayers == 1)
	{
		_numberCallsOFGetNumberPlayers++;
		return 9;
	}
	else
	{
		_numberCallsOFGetNumberPlayers++;
		return 2;
	}
}

int StartGameViewTestSpanishDimension3x3ErrorNumberPlayers::getNumberCallsOfGetNumberPlayers()
{
	return _numberCallsOFGetNumberPlayers;
}

int StartGameViewTestSpanishDimension3x3ErrorNumberPlayers::getNumberCallsOfGetDimension()
{
	return _numberCallsOfGetDimension;
}

bool StartGameViewTestSpanishDimension3x3ErrorNumberPlayers::isIAPlayer()
{
    return false;
}
