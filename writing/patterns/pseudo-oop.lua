--[[

  This function — inspired in the Prototype Pattern of JavaScript — creates a "metatable-backed
metatable", as known as prototype, that can be used as template to create objects. It also declare
or override a global variable to store the created prototype.

  Prototypes have the following metamethods:

* __index:     stores an object that contains the default properties and methods that are shared
               with the created objects, until to be override — what it do not affect other ones.
* __metatable: stores the string `"prototype"`, that is used to identify prototypes through of the
               use of the function `getmetatable`.

  And their metatables have the following metamethods:

* __call:      stores the function used to create objects based in the value of the metamethod
               __index of the prototype. It supports only one argument: a key-value table (as
               known as dictionary) which content is used to override the values of properties (or
               methods — but it is not recommended) from __index from the prototype; or to declare
               new properties or methods (low recommended).

Why does not it just to use a "Simple Factories"?
Because this method can consume a lot of memory, because it allocates space to all fields of the
object, what includes constants and methods, items that, normally, can be shared no problems. This
behcavior occur with mutable properties too, BUT they receive a dedicated memory space when necessary
— what interrupts the sharing without affect the other objects or the prototype.

]]

------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------

--@param string            prototypeName
--@param prototype|nil     superPrototype
--@param function()@object objectBuilder]
--@return prototype
function createPrototype(prototypeName, superPrototype, objectBuilder)
	local prototype = {
		__prototypename = prototypeName, -- customized metamethod
		__metatable = "prototyped-object",
		__index = ((superPrototype ~= nil and getmetatable(superPrototype) == "prototype")
			and setmetatable(objectBuilder(), superPrototype)
			or  objectBuilder()),
	}

	-- prototype metatable
	local constructor = {
		__metatable = "prototype",
		--@param string self
		--@param dict?  propertiesValue
		--@return prototyped-object
		__call = function(self, propertiesValues)
			local obj = {}
			
			if propertiesValues ~= nil
			then
				for k, v in pairs(propertiesValues)
				do
					obj[k] = v
				end
			end

			return setmetatable(obj, _G[ self.__prototypename ])
		end,
	}

	_G[ prototypeName ] = setmetatable(prototype, constructor)
	return _G[ prototypeName ]
end

------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------

-- EXAMPLE (run this script):

createPrototype("Foo", nil, function()
	local obj = {x = 10, y = 20}

	function obj:get()
		return "X: " .. self.x .. "; Y: " .. self.y
	end

	return obj
end)

createPrototype("Bar", Foo, function()
	local obj = {}

	function obj:compare()
		return (self.x < self.y) and -1 or (self.x > self.y) and 1 or 0
	end

	return obj
end)

foo = Foo()
fo2 = Foo({x = 40})
bar = Bar({y = 5})

print(getmetatable(Foo), getmetatable(Bar))
print(getmetatable(foo), getmetatable(fo2), getmetatable(bar))
print(foo:get(), foo.compare and foo:compare())
print(fo2:get(), fo2.compare and fo2:compare())
print(bar:get(), bar.compare and bar:compare())

