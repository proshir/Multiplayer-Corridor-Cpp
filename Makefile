LibDir=Client/Libs/
LibsDir=Server/Libs/
GmDir=$(LibsDir)GameLibs/
CnDir=$(LibDir)ClientLibs/
SvDir=$(LibsDir)ServerLibs/
all:
	g++ -pthread -o Client/Client.out Client/Client.cpp $(CnDir)httplib.h $(LibDir)HttpClientCorridor.h $(CnDir)ConnectConfig.cpp $(CnDir)ConsoleWork.cpp $(CnDir)GameMap.cpp 
	g++ -pthread -o Server/Server.out Server/Server.cpp $(SvDir)httplib.h $(LibsDir)HttpServerCorridor.h $(SvDir)ServerConfig.cpp $(SvDir)ConsoleWork.cpp $(GmDir)Player.cpp $(GmDir)MapGame.cpp 