#include "Players.hpp"

Players::Players(){}

void Players::addPlayer(Player player)
{
	_players.push_back(player);
}

void Players::removePlayer(Player player)
{
	_players.erase(std::remove(_players.begin(), _players.end(), player), _players.end());
}

std::shared_ptr<Player> Players::getPlayerAt(size_t position)
{
	if(position > _players.size())
		return nullptr;
	return std::make_shared<Player>(_players.at(position));
}

size_t Players::getNumberPlayers()
{
	return _players.size();
}
