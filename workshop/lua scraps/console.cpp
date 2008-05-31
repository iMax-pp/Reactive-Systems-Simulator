#include <iostream>
#include <string>
#include "lua.hpp"

using namespace std;

lua_State* L;

string tmpString;

static int myPrint(lua_State *L)
{
	int n = lua_gettop(L);
	int i;

	for (i = 1; i <= n; i++)
	{
		tmpString = luaL_checkstring(L, i);
		cout << tmpString;
	}
	
	cout << endl;	

	return 0;
}

int main ( int argc, char *argv[] )
{
	L = lua_open();

	lua_register(L, "print", myPrint);

	char cmd[100];

	cout << "Start of console loop. Basic assignments and print function are implemented. ex: print(\"hello\")" << endl;

	while(true)
	{
		cout << "> ";
		cin.getline(cmd, 100);
		luaL_dostring(L, cmd);
	}

	lua_close(L);

	return 0;
}
