io.write([[

Example to "basic" functions from Lua
By DuckAfire - duckafire.github.io/nest

]])

_G.input = ""

function head(...)
	io.write(">>>>>> Select an option <<<<<<\n\n")

	local items = {...}
	local isMain = items[1] -- boolean
	items[1] = (isMain) and "[EXIT]" or "[BACK]" -- default

	local largest = 0
	for i = 1, #items do
		if largest < #items[i] then
			largest = #items[i] + 2
		end
	end

	for i = 1, #items do
		io.write(tostring(i - 1).." "..items[i])
		
		for j = 1, largest - #items[i] + ((i < 11 and #items > 10) and 1 or 0) do
			io.write(" ")
		end

		if i % 3 == 0 then
			io.write("\n")
		end
	end

	io.flush()
	io.write("\n\nCode: ")
	input = tonumber(io.read())
	io.write("\n")

	if input == 0 then
		enter(true)
		if isMain then os.exit() end
		return false
	elseif input == nil then
		enter(true)
		io.write("[!] Unsupported value [!]\n\n")
		return false
	elseif input > #items then
		enter(true)
		io.write("[!] Invalid value [!]\n\n")
		return false
	end

	-- it is valid
	return true
end

function script(funcName, output, code)
	local top = "\n> Function \""..funcName.."\":\n"..code

	local arrows = ""
	for i = 1, #top // 2 do
		arrows = arrows..">"
		if i > 50 then break end
	end

	io.write(arrows..top)
	
	if output then
		io.write("> Output from \""..funcName.."\":\n\n")
	end

	load(code, funcName)()

	if output then
		io.write("\n")
	end
	io.write("> End\n"..arrows.."\n\n")
end

function enter(onlySpace)
	if not onlySpace then
		io.write("\n> Press [ENTER] to continue ")
		io.read()
	end
	for i = 1, 50 do
		io.write("\n")
	end
	io.flush()
end


enter(true)
while true do
	if head(true, "basic") then
		enter(true)
		if input == 1 then
			loadfile("basic.lua", "t", _G)()
		end
	end
end
