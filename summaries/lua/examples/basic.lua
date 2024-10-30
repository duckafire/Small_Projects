local function _assert()
	script("assert", false,
[[

local a, b = 1, 2

assert(a < b, "FALSE: 01")

-- it is commented for not
-- stop this program
-- assert(a == b, "FALSE: 02")

]])
end

local function _collectgarbage()
	script("collectgarbage", true,
[[

collectgarbage("stop")
print(collectgarbage("isrunning"))
collectgarbage("restart")
print(collectgarbage("isrunning"))
print(collectgarbage("count"))

]])
end


local function _dofile()
	script("dofile", true,
[[

dofile("files/code.lua")
dofile("files/code.lua")
dofile("files/code.lua")

]])
end

local function _error()
	script("errot", false,
[[

-- it is commented for not
-- stop this program
-- error("HELLO WORLD!")

]])
end

local function _getmetatable()
	script("getmetatable", true,
[[

local tbl = {}


setmetatable(tbl, {
__index = function()
	print("Hello world!")
end})

print(getmetatable(tbl))

]])
end

local function _ipairs()
	script("ipairs", true,
[[

local src = {9, 8, 7, 6, 5}

local func, tbl, zero = ipairs(src)

print(func, tbl, zero)

for index, value in ipairs(src) do
	print(index, value)
end

]])
end

local function _load()
	script("load", true,
[[

-- global
a = 15
b = 7

-- parenthesis in end, to call
-- "load" and it return
load("print('Hello world!')", "load-hello-world")()

-- or
local func = load("print(a + b)", "load-add", "t", _G)
func()

]])
end

local function _loadfile()
	script("loadfile", true,
[[

-- parenthesis in end, to call
-- "load" and it return
loadfile("files/code.lua")()
loadfile("files/code.lua") -- not called
loadfile("files/code.lua")()

]])
end

local function _next()
	script("next", true,
[[

local tbl = {9, 8, 7}
local void = {0}

print(next(tbl, 1))
print(next(tbl, 3))
print(next(void, 1))

]])
end

local function _pairs()
	script("pairs", true,
[[

local tbl = {9, 8, nil, 6, nil, 4}

for index, value in pairs(tbl) do
	print(i, index, value)
end

setmetatable(tbl, {
__pairs = function()
	print("Hello world!")
end})

pairs(tbl)

]])
end

local function _pcall()
	script("pcall", true,
[[

local function err(m)
	error(m)
end

local bool, msg
bool, msg = pcall(err, "HELLO WORLD!")

print(bool)
print(msg)
print("")

]])
end

local function _print()
	script("print", true,
[[

print("Hello world!")
print(1, 2, 3, 4, 5)
print(true, false, nil)

]])
end

local function _rawequal()
	script("rawequal", true,
[[

local tbl = {}

for i = 1, 2 do
	tbl[i] = {}

	setmetatable(tbl[i], {
	__eq = function()
		print("Hello world!")
	end})
end

-- compare and call "__eq" to first
print("0:", tbl[1] == tbl[2])
print("1:", tbl[2] == tbl[1])

-- only compare
print("2:", rawequal(tbl[1], tbl[2]))

]])
end

local function _rawget()
	script("rawget", true,
[[

local tbl = {}
local bag = {"SEARCHING IN BAG..."}

setmetatable(tbl, {__index = bag})

print(tbl[1])
print(rawget(tbl, 1))

]])
end

local function _rawlen()
	script("rawlen", true,
[[

local tbl = {1, 2, 3, 4, 5}

setmetatable(tbl, {
__len = function()
	print("Hello world!")
	-- it do not have return,
	-- then it will return "nil"
end})

print(#tbl)
print(rawlen(tbl))

]])
end

local function _rawset()
	script("rawset", true,
[[

local tbl = {}

setmetatable(tbl, {
__newindex = function()
	print("Hello world!")
end})

tbl[1] = 9
tbl[2] = 8
rawset(tbl, 3, 7)

print(tbl[1], tbl[2], tbl[3])

]])
end

local function _require()
	script("require", true,
[[

local msg = require("files.lib")

msg.hello_world()

]])
end

local function _select()
	script("select", true,
[[

print(select(2, "a", "b", "c"))
print(select(-1, "A", "B", "C"))
print(select("#", "(", "[", "{"))

]])
end

local function _setmetatable()
	script("setmetatable", false,
[[

local tbl = {0, 1, 2, 3, 4}
local tbl1 = {5, 6, 7, 8, 9}

setmetatable(tbl, {__index = tbl1})

local tbl2 = {0, 1, 2, 3, 4}
local mtbl = {
__call = function(t, ...)
	return {...}
end}

setmetatable(tbl, mtbl)

]])
end

local function _tonumber()
	script("tonumber", true,
[[

local str = "123"
local num = tonumber(str)

print(num == "123")
print(num == 123)

]])
end

local function _tostring()
	script("tostring", true,
[[

local boo = false
local str = tostring(boo)

print(boo == false)
print(str == false)
print(str == "false")

]])
end

local function _type()
	script("type", true,
[[

local v = {
	nil, 1, "1", true, {},
	function() end
}

for i = 1, #v do
	print(type(v[i]))
end

]])
end

local function _xpcall()
	script("xpcall", true,
[[

local function err(m)
	error(m)
end

local function treatment(em) -- error message
	print("[!] ERRORS OCURRED >> "..em)
end

xpcall(err, treatment, "HELLO WORLD!")

]])
end

local funcs = {_assert,_collectgarbage,_dofile,_error,_getmetatable,_ipairs,_load,_loadfile,_next,_pairs,_pcall,_print,_rawequal,_rawget,_rawlen,_rawset,_require,_select,_setmetatable,_tonumber,_tostring,_type,_xpcall}
while true do
	if head(false, "assert","collectgarbage","dofile","error","getmetatable","ipairs","load","loadfile","next","pairs","pcall","print","rawequal","rawget","rawlen","rawset","require","select","setmetatable","tonumber","tostring","type","xpcall") then
		enter(true)
		funcs[input]()
		enter()
	else
		break
	end
end
