-- it is a line comment
--[[
	it is a block comment
]]


-- LOCAL DECLARATION
local a -- a == nil
local b, c, d = 10, false -- b == 10 | c == false | d == nil

local function lfunc() end

local anony = function() end -- anonymous function, also known like
                             -- "arrow function" in JavaScript and
                             -- "lambda function" in Java

a = 20       -- attribution
local a = 16 -- redeclaration 


-- GLOBAL DECLARATION
A = "value" -- it needs of a value
B, C, D = 10, false -- D == nil

function gfunc() end

A = "other value" -- attribution

-- the table `_G` can be used as prefix to
-- declare and to use global identificators
_G.foo = "VALUE"


-- TABLES
local table1 = { 9, "8", false } -- declarations
local table2 = { foo = "foo", bar = true }
local table3 = { function() end }
local table4 = { methodLike = function() end }

local req
req = table1[1] -- requests
req = table2.foo --[[ OR ]], table2["foo"]
req = table3[1]
req = table4.method
req = table4.methodLike()
req = table4["methodLike"]()

local abomination = {
	1,
	"foo",
	bar = 400,
	89,
	function() end,
	{
		0,
		false,
		564,
		"foo",
	},
	foo = 1.1,
	98e2,
	foobar = function() end,
}

local toIncrement = {}

toIncrement[19]  = 24.24
toIncrement[-19] = function() end
toIncrement["foo"] = false
toIncrement.foo = "any"

function toIncrement.method()
	-- no "self-reference" (`self`)
	-- local req = self[19] -- ERROR
end

function toIncrement:method2()
	-- with "self-reference" (`self`)
	local req = self[19] -- 24.24
end

toIncrement[{}] = 34 -- "weak key" (just avoid)
toIncrement[function() end] = 90
toIncrement[toIncrement] = "zero"
toIncrement[false] = true
-- toIncrement[nil] = "ERROR"


-- IDENTIFIERS DEFINED AS `nil` DO NOT EXIST

local itHasNil -- tecnically YET this do not exist

req = itHasNil

itHasNil = {9, nil, 7}
req = itHasNil[2]
req = itHasNil[9494939]

itHasNil = {foo = false, bar = "string"}
req = itHasNil.foobar

-- ACCESS THEM DO NOT CAUSE ERRORS, BUT TO TRY USE THEM
-- TO MAKE OPERATIONS IT WILL CAUSE

--[[ errors:

req = itNil.foo
req = itNil + 80
req = itNil.."string"
req = itNil()
req = itNil[12]
req = itHasNil.foobar.foo
req = itHasNil.foobar()

]]


-- PARAMETERS AND ARGUMENTS:
-- parameter: identifier defined between the parentesis
--            of a function, during its declaration.
-- argument:  value gived to a function parameter.

local function anyFunc(a, b, c) end
anyFunc(10) -- a == 10 | b == nil | c == nil

-- there is like to define default value to parameters
-- of the following manner

local function withDefault(foo)
	-- more about in "CONDITIONALS"
	foo = foo or "default"
end

-- `...` can be used to allow that a function
-- receive undefined quantities of arguments

local function undefinedQuant(...)
	local args = {...} -- it create an array with the values
	print(...) -- print all values
end


-- METATABLES AND METAMETHODS
-- metatable:  tables containg special properties, that
--             dictate how "associated" tables must behave
--             in determinated situations.
-- metamethod: behavior properties fo metatables.

-- setmetatable(table, metatable): it associate a metatable to
--                                 a table. It replace the
--                                 metatable associataed, case
--                                 there is any. `nil` will
--                                 unlink the metatable already
--                                 associated, case there is any.
-- getmetatable(table): return the address of the metatable
--                      associated to `table`.

-- this matter is not complex, but it is a little
-- long, so I will make just some examples about.

local metatable = {
	-- metamethod executed always that the associated
	-- table is used as a function
	__call = function()
		print("I'm NOT a function!")
	end
}

local dummy = {}

setmetatable(dummy, metatable)
dummy()

setmetatable(dummy, { -- it replace the last
	-- metamethod executed always that the associated
	-- table is used in an addition operation
	__add = function()
		return 1
	end,
	-- metamethod executed always that the associated
	-- table is used in an subtraction operation
	__sub = function()
		return -1
	end
})

req = dummy + 1 -- 2
req = dummy - 1 -- 0

setmetatable(dummy, nil) -- remove the last metatable
                         -- associated to `dummy`


-- CONDITIONS AND TERNARIES

local foo, bar

if false then
	foo = 1
end

if false then
	foo = 1
elseif false then
	foo = 2
end

foo = false and 1 or 0
if false then
	foo = 1
else
	foo = 0
end

foo = false and 1 or false and 2 or 0
if false then
	foo = 1
elseif false then
	foo = 2
else
	foo = 0
end

foo = foo or 0
if foo ~= nil then
	foo = foo
else
	foo = 0
end

foo = foo or bar or 0
if foo ~= nil then
	foo = foo
elseif bar ~= nil then
	foo = bar
else
	foo = 0
end

-- insert "true booleans" in ternary tend to generate
-- strange behaviors, but undestandable

-- return `0` instead `false`
tern = true and false or 0

-- even with parentesis
tern = (true) and false or 0


-- LOOPS

-- 1, 2, 3, ...
for i = 1, 10 do end

-- 1, 3, 5, ...
for i = 1, 10, 2 do end

-- "normal array" interation (ascending order)
for index, values in ipairs(table) do end

-- "any array" interation (random order)
for index, values in pairs(table) do end

-- loop while true
while true do
	break
end

-- loop while false
repeat
	break
until false

-- "do-while" like
repeat
	break
until not (true)


-- GOTO
local quant = 0

::label::

quant = quant + 1

if quant > 10 then
	goto finish
end

goto label

::finish::

-- the labels are based in scope, like variables

--[[ errors:

do
	::private::
end

goto private -- ERROR

]]
