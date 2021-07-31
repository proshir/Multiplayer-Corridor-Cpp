#include "ServerConfig.h"
ServerConfig::ServerConfig(string _serverName,string _address,int _port,int _maxPlayers,pair<int,int> _gameSize):
    serverName(_serverName),address(_address),port(_port),maxPlayers(_maxPlayers),gameSize(_gameSize){
}