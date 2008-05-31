#include <iostream>
#include "lua.hpp"

using namespace std;

int main (void) 
{
	lua_State *L = lua_open(); 

		int setting;

		if(luaL_loadfile(L,"setting.lua") || lua_pcall(L,0,0,0))
		{
			cout << "Error failed to load " << lua_tostring(L,-1) << endl;
		}
		else
		{
			lua_getglobal(L,"setting");
			if(lua_isnumber(L,-1))
			{
				setting = lua_tonumber(L,-1);
			}
			else
			{  
				cout << "Error setting is NAN" << endl;
			}
		}

	lua_close(L);

	cout << "setting is: " << setting << endl;

	return 0;
}
