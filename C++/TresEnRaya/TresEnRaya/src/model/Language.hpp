#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

class Language
{
public:
	enum Message
	{
	    CoordenateGet,
	    CoordenateIncorrect,
	    DimensionGet,
	    DimensionIncorrect,
	    LanguageChoose,
	    LanguageSelected,
	    NumberOfPlayerGet,
	    NumberOfPlayerIncorrect,
	    PieceChoose,
		PieceSelected,
	    PlayerEnterName,
	    PlayerWinner,
		GameDraw,
        Loading,
        IsIAPlayer
	};

    const char* getMessage(Message message);

protected:
    std::map<Message, std::string> _allMessage;
};

#endif // LANGUAGE_H
