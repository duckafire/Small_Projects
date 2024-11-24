#include <lua5.3/lua.h>
#include <lua5.3/lualib.h>
#include <lua5.3/lauxlib.h>

lua_State *L;

int main(void){
	L = luaL_newstate();

	// print, type, ...
	luaL_openlibs(L);

	luaL_dostring(L, "print('Hello world!')");

	lua_close(L);
	return 0;
}
