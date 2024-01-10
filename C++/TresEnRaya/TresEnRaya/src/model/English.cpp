#include "English.hpp"

English::English()
{
    _allMessage[CoordenateGet] 				= "%s enter the coordinate (Rows %d, Column %d): ";
    _allMessage[CoordenateIncorrect] 		= "%s incorrect coordinates, please enter them again (Rows %d, Column %d): ";
    _allMessage[DimensionGet] 				= "Enter the board dimensions (row column). Minimum should be %dx%d and maximun %dx%d:";
    _allMessage[DimensionIncorrect] 		= "The dimensions are incorrect. Minimum should be %dx%d and maximun %dx%d. Please enter them again:";
    _allMessage[LanguageChoose] 			= "Select a language from the list.";
    _allMessage[LanguageSelected] 			= "\nSelected language:";
    _allMessage[NumberOfPlayerGet] 			= "How many players will play? (Minimum %d, Maximum %d):";
    _allMessage[NumberOfPlayerIncorrect] 	= "The number of players is incorrect, enter it again (Minimum %d, Maximum %d):";
    _allMessage[PieceChoose] 				= "Select a piece from the list.";
    _allMessage[PieceSelected] 				= "\nSelected piece:";
    _allMessage[PlayerEnterName]			= "Enter the name:";
    _allMessage[PlayerWinner] 				= "%s has won! CONGRATULATIONS!\n";
    _allMessage[GameDraw] 					= "It's a draw.\n";
    _allMessage[Loading]					= "Loading";
    _allMessage[IsIAPlayer]                 = "The player is an IA?(yes = s, no = n):";
}

