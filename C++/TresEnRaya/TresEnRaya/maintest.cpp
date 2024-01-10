//============================================================================
// Name        : TresEnRaya.cpp
// Author      : Adrian Fenandez Gomez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unistd.h>
using namespace std;

#include "src/test/TestDimension3x3TwoPlayersAllOk.hpp"
#include "src/test/TestDimension3x3TwoPlayersSpanishError.hpp"

int main()
{
    TestDimension3x3TwoPlayersAllOk test;
    test.Rows();
    test.Columns();
    test.Diagonals();
    test.FirstPlayerWin();
    test.SecondPlayerWin();
    test.Draw();

    TestDimension3x3TwoPlayersSpanishError testError;
    testError.IncorrectDimensionAndNumberPlayers();
    testError.IncorrectCoordenate();

    int a = 1;

    cout << "Introduzca un numero para terminar... ";
    cin >> a;

    cout << "Fin de programa" << endl; // prints !!!Hello World!!!
    return 0;
}
