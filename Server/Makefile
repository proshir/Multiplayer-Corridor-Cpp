LibDir=Libs/
SvDir=$(LibDir)ServerLibs/
GmDir=$(LibDir)GameLibs/
all:
	g++ -pthread -o Server.out Server.cpp $(SvDir)httplib.h $(LibDir)HttpServerCorridor.h $(SvDir)ServerConfig.cpp $(SvDir)ConsoleWork.cpp $(GmDir)Player.cpp $(GmDir)MapGame.cpp 
