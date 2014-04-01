#include <Windows.h>
#include "Game.hpp"

int main(){
//debug
	//AllocConsole();
	//FILE* pOut; 
	//FILE* pIn; 
	//FILE* pErr;
	//freopen_s(&pIn,"conin$","r", stdin);
	//freopen_s(&pOut, "conout$","w",stdout);
	//freopen_s(&pErr, "conout$","w",stderr);
//
	Resources resources;
	Game game;
	game.run();
}