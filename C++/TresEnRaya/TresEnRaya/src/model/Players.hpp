#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include <iostream>
#include <vector>
#include <algorithm>

#include "Player.hpp"

class Players
{
public:
    Players();

    void addPlayer(Player player);
    void removePlayer(Player player);
    std::shared_ptr<Player> getPlayerAt(size_t position);
    size_t getNumberPlayers();

private:
    std::vector<Player> _players;
};

#endif // PLAYERS_HPP
