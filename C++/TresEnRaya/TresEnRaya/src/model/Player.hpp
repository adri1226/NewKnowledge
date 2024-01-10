#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <memory>

#include "../others/Piece.hpp"
#include "../others/Coordenate.hpp"
#include "Language.hpp"

class Player
{
public:
    Player(std::string name, Piece piece);

    friend std::ostream& operator<<(std::ostream& os, const Player& obj);
    bool operator==(const Player& player) const;

    Piece getPiece();
    std::string getName();

private:
    std::string _name;
    Piece _onePiece;
};

#endif //PLAYER_HPP
