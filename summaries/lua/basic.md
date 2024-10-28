<h1 id="0">Basic</h1>

Oferece duas variáveis globais e uma série de funções báscias para usos diversos e essenciais.

<br>

> _G: **Tabela global** que armazena o ambiente global. LUA não usa essa variável em sim. Alterar seu valor não afeta nenhum ambiente, e vice-versa.

> _VERSION: **Variável global** que possui a versão do interpretador LUA em execução.

<br>

|| Funções ||
|:-:|:-:|:-:|
|[assert](#1)        |[next](#9)     |[select](#17)      |
|[collectgarbage](#2)|[pairs](#10)   |[setmetatable](#18)|
|[dofile](#3)        |[pcall](#11)   |[tonumber](#19)    |
|[error](#4)         |[print](#12)   |[tostring](#20)    |
|[getmetatable](#5)  |[rawequal](#13)|[type](#21)        |
|[ipairs](#6)        |[rawget](#14)  |[xpcall](#22)      |
|[load](#7)          |[rawlen](#15)  | |
|[loadfile](#8)      |[rawse](#16)   | |

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="1">assert(cond, [msg="assertion failed!"])</h3>

* Argumentos:
	* cond: booleano.
	* msg: cadeia de caracteres.
* Comportamento: interrompe o programa, e imprime `msg`, caso `exp == false`.
* Retorno: nenhum.

``` lua
local n1, n2 = 1, 2

assert(n1 < n2, ">>> Program end <<<") -- not stop the program

assert(n1 > n2, ">>> Program end <<<") -- stop the program
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="2">collectgarbage([action="collect", [arg=nil] ])</h3>

* Argumentos:
	* action: cadeia de caracteres; listada abaixo.
	* arg: número; usado apenas por: `"setpause"` e `"step"`.
* Comportamento: ordenar que o coletor de lixo execute uma deteminada ação.
* Retorno: os retornos variam de acordo com o valor de `action`. Ambos está listados abaixo. Alguns não têm retorno.

| Ação          | Descrição                                                                             |
| :-:           | :--                                                                                   |
| `"collect"`   | Realiza um ciclo de coleta                                                            |
| `"stop"`      | Interrompe a coleta automática                                                        |
| `"restart"`   | Reinicia a execução da coleta automática                                              |
| `"count"`     | **Retorna** a memória total em uso (em `Kbytes`)                                      |
| `"isrunning"` | **Retorna** um booleano que indica se o coletor está em execução                      |
| `"setpause"`  | Define `arg` como novo valor para a _pausa do coletor_ e **retorna** o valor anterior |
| `"step"`      | Executa uma etapa do coletor de lixo, usando `arg` para definir seu "tamanho". `==0` etapa básica (indivisível); `>0` o coletor tratará esse valor como se fosse uma quantidade de memória (em `Kbytes`) em uso. **Retorna** `true` se a etapa concluir um ciclo de coleta |

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="3">dofile([file=stdin])</h3>

* Argumentos:
	* file: cadeia de caracteres; apenas arquivos `.lua`.
* Comportamento: executa o conteúdo de `file` como se fosse parte do arquivo em questão.
* Retorno: todos os valores retornados pelo trecho.

``` lua
-- FILE ONE (main)

print("[ CONSOLE ]\n")

local txt, txt2 = dofile("call.lua")
print(txt..txt2)
```

``` lua
-- FILE TWO (call)

print("Hello World!")
return "\n:", "D"

```

```
[ CONSOLE ]

Hello World!

:D
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="4">error(msg, [level=1])</h3>

* Argumentos:
	* msg: cadeia de caracteres.
	* level: número; listado abaixo.
* Comportamento: imprime `msg` no console e especifica informações de posição de acordo com o valor de `level`.
* Retorno: nenhum.

| Valor | Descrição                                          |
| :-:   | :--                                                |
| 0     | Omite a posição (linha) do erro.                   |
| 1     | Especifica a posição do erro.                      |
| 2     | Especifica a posição da função que chamou `error`. |

``` lua
local function transform(n)
	if n < 0 then
		error('"n" is not positive', 2)
	end
	
	return n * -1
end
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="5">getmetatable(tbl)</h3>

* Argumentos:
	* tbl: tabela.
* Comportamento: verifica se o objeto possui algum metamétodo.
* Retorno: caso haja um metámetodo, seu endereço, do contrário, o endereço de `tbl`. `nil` caso `tbl` não seja uma tabela.

``` lua
local a = {}
a.__index = a
local b = {}
local c = setmetatable(b, a) -- "a" is the metatable of "c"

print(a)               -- table: "a address"
print(getmetatable(c)) -- table: "a address"
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="6">ipairs(tbl)</h3>

* Argumentos:
	* tbl: tabela.
* Comportamento: intera, em pares (índice e valor), `tbl` até o primeiro índice ausente (`==nil`).
* Retorno: uma função interadora, `tbl` e `0`.

``` lua
print("[ CONSOLE ]")

local tbl = {5, 4, nil, 2, 1}
local func, _tbl, zero = ipairs(tbl)

print(func)
print(_tbl)
print(zero)

for i, v do ipairs(tbl) do
	print(i..". "..v)
end
```

```
[ CONSOLE ]

function "func address"
table "_tbl address"
0

1 - 5
2 - 4
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="7">load(chunk, [chuckname="=(load)", [mode="bt", [env=_G] ] ])</h3>

* Argumentos:
	* chunk: cadeira de caracteres ou função.
	* chunkname: cadeia de caracteres; usada para se referir ao conteúdo de `chunk` em mensagens de erro e informações de depuração.
	* mode: cadeia de caracteres; `"t"` texto; `"bt"` texto e binários.
	* env: tabela; ambiente customizado.
* Comportamento: executa o código Lua presente em `chuck`.
* Retorno: uma função ou `nil` caso contrário, em caso de falha.

``` lua
local txt = "return 'Hello World!'"
local lTxt = load(txt)
local nTxt = lTxt() -- nTxt = "Hello World!"

local global = {
	add = 12,
	sub = -26,
	mlt = 3,
	div = 5,
}

local code = "return ((18 + add) // div + (sub - (sub * mlt)) / div) * mlt"
local calculation = load(code, nil, nil, global)
calculation() -- 49.2
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="8">loadfile([file=stdin, [mode="t", [env=_G] ] ])</h3>

* Argumentos:
	* chunk: cadeira de caracteres; nome de um arquivo Lua.
	* mode: cadeia de caracteres; `"t"` texto; `"bt"` texto e binários.
	* env: tabela; ambiente customizado.
* Comportamento: executa o código Lua presente em `file`.
* Retorno: uma função ou `nil` caso contrário, em caso de falha.

``` lua
-- FILE ONE (main)

local file = loadfile("example.lua")
local txt = file() -- txt = "Hello World!"
```

``` lua
-- FILE TWO (example)

local txt = "Hello World!"
return txt
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="9">next(tbl, id)</h3>

* Argumentos:
	* tbl: tabela.
	* id: número.
* Comportamento: percorre os índices de `tbl`.
* Retorno: caso `id~=nil`, o próximo índice e seu valor, caso contrário, o primeiro índice e seu valor; caso `id==#tbl`, retornará `nil`.

``` lua
local tbl = {9, 8, 7, 6}

local i, v = next(tbl, 2)

-- i = 3
-- v = 7
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="10">pairs(tbl)</h3>

* Argumentos:
	* tbl: tabela.
* Comportamento: executa `__pairs`, com `tbl` como argumento, mas apenas caso `tbl` o possua, do contrário, gerar apenas um retorno.
* Retorno: [`next`](#9), `tbl` e `nil` ou o retorno de `__pairs`.

``` lua
local tbl = {[4] = 9, [7] = 8, [13] = 7}

for i, v in pairs(tbl) do print(i.." "..v) end -- 4 9 |-| 13 7 |-| 7 8

setmetatable(tbl, {__pairs = function(t) print("Hello World!") end})
pairs(tbl) -- Hello World!
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="11">pcall(func, [arg=nil])</h3>

* Argumentos:
	* func: função.
	* arg: qualquer.
* Comportamento: chama a `func` em "modo protegido", ou seja, caso haja algum erro em `func` ele não parará o programa e nem será imprimido no console.
* Retorno: caso não hajam erros, retornará `true` e os possíveis retornos de `func`, do contrário, retornará `false` e uma cadeia de caracteres contendo o erro em questão.

``` lua
local function add(a, b)
	return a + b, a - b
end

local func, erro = pcall(add, 1, false)
-- func = false
-- erro = main.lua:2: attempt to perform arithmetic on a boolean value (local 'b')

local fun2, rtn1, rtn2 = pcall(add, 2, 3)
-- fun2 = true
-- rtn1 = 5
-- rtn2 = -1
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="12">print(...)</h3>

* Argumentos:
	* (...): qualquer.
* Comportamento: imprime todos os seus argumentos no console. Ambos são separados por uma tabulação. Uma quebra de linha é posta no final.
* Retorno: nenhum.

``` lua
print("Hello World!") -- Hello World!
print(1, 2, 3, 4, 5)  -- 1    2    3    4    5
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="13">rawequal(v1, v2)</h3>

* Argumentos:
	* v1: número.
	* v2: número.
* Comportamento: verifica `v1` e `v2`, sem chamar o metamétodo `__eq`.
* Retorno: o resultado da comparação, em booleano.

``` lua
rawequal(1,   1) -- true
rawequal(1, "1") -- false
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="14">rawget(tbl, id)</h3>

* Argumentos:
	* tbl: tabela.
	* id: número.
* Comportamento: obtém o valor armazenado em `tbl[id]`, sem chamar o metamétodo `__index`.
* Retorno: o valor obtido ou `nil`, caso ele não exista.

``` lua
local tbl = {9, 8, 7, 6, 5}
rawget(tbl, 2) -- 8
rawget(tbl, 6) -- nil
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="15">rawlen(tbl_str)</h3>

* Argumentos:
	* tbl\_str: tabela ou cadeia de caracteres.
* Comportamento: retorno o comprimento de `tbl_str`, sem chama o metamétodo `__leg`.
* Retorno: o comprimento de `tbl_str`.

``` lua
rawlen("Hello World!") -- 12
rawlen({9, 8, 7, 6})   -- 4
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="16">rawset(tbl, id, newValue)</h3>

* Argumentos:
	* tbl: tabela.
	* id: número.
	* newValue: um novo valor para `tbl[id]`.
* Comportamento: atribui `newValue` a `tbl[id]`, sem chamar o metamétodo `__newindex`.
* Retorno: `tbl`.

``` lua
local tbl = {9, 8, 7, 6, 5}
rawset(tbl, 2, 12) -- tbl[2] = 12
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="17">select(id, ...)</h3>

* Argumentos:
	* id: número ou `"#"`.
	* (...): qualquer.
* Comportamento: baseada em retorno.
* Retorno: todos os argumentos (`...`) a partir da posição `id`; caso `id<0` a indexação ocorrerá a partir do final; caso `id=="#"`, retornará a quantidade de argumentos presentes em `...`.

``` lua
local a, b, c

a, b, c = select("#", 9, "8", true) -- 3, nil, nil
a, b, c = select( 1,  9, "8", true) -- 9, "8", true
a, b, c = select(-2,  9, "8", true) -- true, 8, nil
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="18">setmetatable(tbl, mtbl)</h3>

* Argumentos:
	* tbl: tabela.
	* mtbl: metatabela (uma tabela com um metamétodo).
* Comportamento: atribui `mtbl` a `tbl`. Caso `mtbl==nil`, removerá o metamétodo de `tbl`, caso haja algum. Caso `tbl` tenha uma campo `__metatable`, gerará um erro.
* Retorno: `tbl`.

``` lua
local tbl = {}

setmetatable(tbl, {__call = function() return "Hello World!" end})-- add '__call'
local txt = tbl() -- txt = "Hello World!"

setmetatable(tbl, {__add  = function(...) local temp = {...} return 20 + temp[2] end}) -- remove '__call' and add '__add'
local add = tbl + 5 -- add = 20 + 5

setmetatable(tbl, nil) -- remove: __add

setmetatable(tbl, {__metatable = function() return "__metatable" end}) -- add '__call'
setmetatable(tbl, {__call = function() return "Hello World!" end}) -- generates an error
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="19">tonumber(value, [base=10])</h3>

* Argumentos:
	* value: cadeia de caracteres.
	* base: número; qualquer valor entre 2-36.
* Comportamento: converte `value` para número, caso ele seja válido, de acordo com `base`.
* Retorno: o valor convertido, ou `nil`, caso `value` seja inválido.

``` lua
tonumber("1")  -- 1
tonumber("a")  -- nil
tonumber(0xda) -- 218
tonumber("88", 15) -- 128
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="20">tostring(value)</h3>

* Argumentos:
	* value: número.
* Comportamento: converte `value` em uma cadeia de caracteres. Caso `value` possua o metamétodo `__tostring`, ele será chamado com `value` como argumento.
* Retorno: uma cadeia de caracteres convertida ou o retorno de `__tostring`.

``` lua
tostring(true) -- "true"
tostring(1234) -- "1234"

local value = {}
setmetatable(value, {__tostring = function(Self) return #Self end})

local qtt = tostring(value) -- qtt = 0
for i = 1, 5 do value[i] = i end
qtt = tostring(value) -- qtt = 5
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="21">type(item)</h3>

* Argumentos:
	* item: qualquer.
* Comportamento: obtem o tipo de `value`.
* Retorno: `"nil"`, `"number"`, `"string"`, `"boolean"`, `"table"`, `"function"`, `"thread`" ou `"userdata"`.

``` lua
local str, num, boo = 1, "a", false
local tStr, tNum, tBoo

tStr = type(str) -- "number"
tNum = type(num) -- "string"
tBoo = type(boo) -- "boolean"
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="22">xpcall(func, err, [arg=nil])</h3>

* Argumentos:
	* func: função.
	* arg: qualquer.
* Comportamento: chama a `func` em "modo protegido", ou seja, caso haja algum erro em `func` ele não parará o programa e nem será imprimido no console.
* Retorno: caso não hajam erros, retornará `true` e os possíveis retornos de `func`, do contrário, retornará `false` e uma cadeia de caracteres contendo o erro em questão.

* Argumentos:
	* func: função.
	* err: função;
	* arg: qualquer.
* Comportamento: chama a `func` em "modo protegido". Caso ocorra algum erro, `err` é chamada, com o erro como argumento.
* Retorno: caso não hajam erros, `true` e os possíveis retornos de `func`, do contrário, `false` e os possíveis retornos de `err`.

``` lua
local function add(a, b)
	return a + b, a - b
end

local function ifErrror(msg)
	return "AN ERROR WAS HAPPEN: "..msg)
end

local func, erro = xpcall(add, ifErrror, 1, false)
-- func = false
-- erro = AN ERROR WAS HAPPEN: main.lua:2: attempt to perform arithmetic on a boolean value (local 'b')

local fun2, rtn1, rtn2 = xpcall(add, 2, 3)
-- fun2 = true
-- rtn1 = 5
-- rtn2 = -1
```

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>
