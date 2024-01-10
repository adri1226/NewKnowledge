#include "Spanish.hpp"

Spanish::Spanish()
{
    _allMessage[CoordenateGet] 				= "%s introduzca la coordenada (Filas %d, Columnas %d): ";
    _allMessage[CoordenateIncorrect] 		= "%s coordenadas incorrectas, vuelva a introducirlas (Filas %d, Columnas %d): ";
    _allMessage[DimensionGet] 				= "Introduzca las dimensiones del tablero (fila columna). Minimo ha de ser de %dx%d y máximo de %dx%d:";
    _allMessage[DimensionIncorrect] 		= "Las dimensiones son incorrectas. Minimo ha de ser de %dx%d y máximo de %dx%d. Introduzcalas de nuevo:";
    _allMessage[LanguageChoose] 			= "Seleccione un idioma de la lista.";
    _allMessage[LanguageSelected] 			= "\nLenguaje seleccionado:";
    _allMessage[NumberOfPlayerGet] 			= "¿Cuantos jugadores van a jugar? (Minimo %d, Maximo %d):";
    _allMessage[NumberOfPlayerIncorrect] 	= "El numero de jugadores es incorrecto, introduzcalo de nuevo (Minimo %d, Maximo %d):";
    _allMessage[PieceChoose] 				= "Seleccione una pieza de la lista.";
    _allMessage[PieceSelected] 				= "\nPieza seleccionada:";
    _allMessage[PlayerEnterName]			= "Introduzca el nombre:";
    _allMessage[PlayerWinner] 				= "Ha ganado %s ¡ENHORABUENA!\n";
    _allMessage[GameDraw] 					= "Habeis quedado empate.\n";
    _allMessage[Loading]					= "Cargando";
    _allMessage[IsIAPlayer]                 = "¿El jugador es un IA?(si = s, no = n):";
}

