-- THEORY:
--
-- A global function (class) receives: a class name; a pseudo-class to
-- extend (optional); and a "class factory" (function that creates, and
-- returns a prototype table).
--
-- It declares a global variable with the class name gave, that will
-- store a metatable which metamethod __index will point to a prototype
-- table (created with the "class factory"). If a prototype to extend
-- was given, the main prototype will receive it as a metatable.
--
-- The prototype will be linked to other metatable which metamethod __call
-- will store a class constructor, invoked when the prototype is called like
-- a function. The constructor will accept one optional argument, a table
-- which content will be putted in the created instance, that will returned.
--
-- PRACTICE:

-- class(name: string, classFactory: function)
-- class(name: string, classToExtend: table, classFactory: function)
function class(name, argB, argC)
	_G[ name ] = setmetatable(
		{ __index = (argC == nil and argB() or setmetatable(argC(), argB)) },
		{ __call  = function(self, ...)
			local obj = {}
			local constructorArgs = ({...})[1]
			
			if constructorArgs ~= nil then
				for k, v in pairs(constructorArgs) do
					obj[k] = v
				end
			end

			return setmetatable(obj, _G[ name ])
		end }
	)
end

-- TESTS -----------------------------------------------------------------------

class("Foo", function()
	local obj = {
		x = 10,
	}

	function obj:get()
		return self.x
	end

	return obj
end)

class("Bar", Foo, function()
	return {}
end)

foo = Foo()
bar = Bar()
baz = Bar({x = 400})
print(foo.x,     bar.x,     baz.x)
print(foo:get(), bar:get(), baz:get())

