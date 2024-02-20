# Basic
Oferece duas variáveis globais e uma série de funções báscias para usos diversos e essenciais.

> _G: **Variável global** que armazena o ambiente global. LUA não usa essa variável em sim; Alterar seu valor não afeta nenhum ambiente, e vice-versa. <br>
> _VERSION: **Variável global** que possui a versão do interpretador LUA em execução.

## Funções
* [assert](#1)
* [collectgarbage](#2)
* [dofile](#3)
* [error](#4)
* [getmetatable](#5)
* [ipairs](#6)
* [load](#7)
* [loadfile](#8)
* [next](#9)
* [pairs](#10)
* [pcall](#11)
* [print](#12)
* [rawequal](#13)
* [rawget](#14)
* [rawlen](#15)
* [require](#16)
* [select](#17)
* [setmetatable](#18)
* [tonumber](#19)
* [tostring](#20)
* [type](#21)
* [warn](#22)
* [xpcall](#23)

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 1
* assert(exp, [msg])
	* exp: Expressão booleana. | msg: Mensagem de erro customizada ("assertion failed!" por padrão).
	* Uso: Verifica se `exp` é verdadeiro, caso não, interrompe o programa e imprime a mensagem espeficada, em `msg`, no console.
	* Retorno: Sem retorno.

``` lua
assert(true, ">>> Program end <<<")-- not stop the program

assert(0 < 0, ">>> Program end <<<")-- stop the program
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 2
* collectgarbage([action], [arg])
	* action: A ação que será executada pelo coletor de lixo. | arg: Valor opcional, requerido por (algumas ações): `step`.
	* Uso: Permiti ordenar que o coletor de lixo execute uma deteminada ação.
	* Retorno: Apenas as ações `count`, `step` geram retorno(s).

| Ação         | Descrição |
| :-:          | :-:       |
| collect      | Realiza um ciclo de coleta (padrão) |
| stop         | Interrompe a coleta automatica |
| restart      | Reinicia a execução da coleta automática |
| count        | Permite retorna a memória total em uso (em `Kbytes`). |
| step         | Executa um passo da coleta de lixo. Seu "tamanho" é controlado por `arg`, e caso seja `0` executará uma etapa básica (indivisível), caso contrário, o coletor tratará esse valor como se fosse uma quantidade de memória (em `Kbytes`) em uso. Permite o retorno de `true`, caso a etapa conclua um ciclo de coleta. |
| isrunning    | Permite retornar `true` caso o coletor esteja em execução. |
| incremental  | Altera o modo do coletor para *incremental*. Essa configuração pode ser seguida por três números (`arg`, `arg2` e `arg3`): O intervalo entre os ciclos (pausa), o multiplicador de passos e o tamanho do degrau (´0´ = valor não alterado; [sobre](https://lua.org/manual/5.4/manual.html#2.5.1 "Coleta Incremental")) |
| generational | Altera o modo do coletor para *geracional*. Essa configuração pode ser seguida por dois números (`arg` e `arg2`): O multiplicador menor e o maior (do coletor de lixo; ´0´ = valor não alterado; [sobre](https://lua.org/manual/5.4/manual.html#2.5.2 "Coleta Geracional")). |

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 3
* dofile([file])
	* file: Nome de um arquivo `.lua` (`stdin` caso seja omitido).
	* Uso: Executa o conteúdo de um arquivo como se fosse parte do código.
	* Retorno: Todos os valores retornados pelo trecho.

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

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 4
* error(msg, [level])
	* msg: Mensagem de erro que será imprimida no console. | level: Posição do erro que será imprimida no console junto a `msg`, onde `0` omite essa informação, `1` (padrão) especifica a posição de `error`, `2` especifica a posição da função que chamou `error`; e assim por diante.
	* Uso: Imprime `msg` no console e especifica informações de posição de acordo com o valor de `level`.
	* Retorno: Sem retorno.

``` lua
local function transform(n)
	if n < 0 then
		error('"n" is not positive', 2)
	end
	
	return n * -1
end
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 5
* getmetatable(object)
	* object: Uma metatabela (`metatable`).
	* Uso: Verifica se o objeto possui alguma metatabela.
	* Retorno: caso `object` possua uma metatabela, retornará o endereço de memória da mesma, caso não, retornará seu endereço de memória, mas caso `object` não seja uma tabela, retornará `nil`.

``` lua
local a = {}
a.__index = a
local b = {}
local c = setmetatable(b, a)-- "a" is the metatable of "c"

print(a)               -- table: "a address"
print(getmetatable(c)) -- table: "a address"
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 6
* ipairs(tbl)
	* tbl: Uma tabela, preferencialmente, com índices numéricos ordenados.
	* Uso: Intera entre os pares índice-valor de `tbl`, até o primeiro índice ausente. Comumente usada para percorrer tabelas com índices númericos ordenados, com `for`.
	* Retorno: Uma função interadora, a tabela usada em `tbl` e `0`.

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

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 7
* load(ld, [source], [mode], [env])
	* ld: Uma cadeira de caracteres. | source: Uma cadeia de caracteres, usada para mensagens de erro e depuração (`ld` ou ´"=(load)" por padrão´). | mode: Especifica o modo de compilação, onde `t` (padrão) trata códigos como texto (string) e `b` trata como binário. | env: Tabela que conterá o ambiente global, ou seja, se alguma variável "global" for solicitada, por algo presente em `ld`, os valores presentes nesta tabela serão usados.
	* Uso: Carrega/compila/interpreta `ld` como código LUA, de acordo com `mode`. É úil para carregar arquivos externos, já que os mesmos são "lidos/carregados" em formato de string. Códigos binários malformados geram erros apropriados; entretanto LUA não verifica sua consistência; A execução de códigos de `bytes` criado com códigos maliciosos pode travar o interpretador.
	* Retorno: Uma função caso a compilação seja bem suscedida ou `nil` caso não seja.

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

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 8
* loadfile([file_name], [mode], [env])
	* file_name: Nome do arquivo que contém o conteúdo a ser interpretado. | mode: Especifica o modo de compilação, onde `t` (padrão) trata códigos como texto (string) e `b` trata como binário. | env: Tabela que conterá o ambiente global.
	* Uso: Funciona da mesma maneira que [`load`](#7), mas exige (opconalmente) um arquivo ao invés de uma string.
	* Retorno: Uma função caso a compilação seja bem suscedida ou `nil` caso não seja..

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

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 9
* next(tbl, id)
	* tbl: Uma tabela. | id: Um índice, numérico.
	* Uso: Percorre uma tabela (`tbl`), obtendo o valor armazenado no índice `id + 1`.
	* Retorno: Baseado em `id + 1`, retonará este índice e seu valor respectivo, caso `id` seja omitido (`nil`), retornará o índice e o valor inicial, e caso `id` seja o último índice de `tbl`, ou caso `tbl` seja uma tabela vazia, retornará `nil`.

``` lua
local tbl = {9, 8, 7, 6, 5, 4, 3, 2, 1}

local i, v = next(tbl, 6)

-- i = 7 (- 1 = 6[i] -> 3[v])
-- v = 2
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 10
* pairs(tbl)
	* tbl: Um tabela.
	* Uso: Caso `tbl` tenha o metamétodo `__pairs`, chamará-o (como uma função) usando `tbl` como argumento, caso contrário, retornará valores que permitirão a interação sobre todos os pares índice–valor da tabela `tbl` com `for`. Comumente usada para percorrer tabelas com índices númericos fora de ordem (`tbl = {[1] = 9, [2] = nil, [3] = 7}`), com `for`.
	* Retorno: Os valores de retorno antes citados, sendo eles a função `[next](#9)`, `tbl` e `nil`.

``` lua
local tbl = {[4] = 9, [7] = 8, [13] = 7}

for i, v in pairs(tbl) do print(i.." "..v) end-- 4 9 |-| 13 7 |-| 7 8

setmetatable(tbl, {__pairs = function(t) print("Hello World!") end})
pairs(tbl)-- Hello World!
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 11
* pcall(func, [arg])
	* func: A função que será chamda. | Os argumentos que serão atribuídos a `func`.
	* Uso: Chama a `func` em "modo protegido", ou seja, caso haja algum erro em `func` ele não parará o programa e nem será imprimido no console.
	* Retorno: `true` e os possíveis retornos de `func` caso não haja nenhum erro na mesma, caso contrário, retornará `false` e um erro.

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

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 12
* print(...)
	* (...): Valores para serem imprimidos no console.
	* Uso: Imprime todos os seus argumentos no console, de maneira **não formatada**. Argumentos diferentes, quando imprimidos, são separados por uma tabulação.
	* Retorno: Sem retorno.

``` lua
print("Hello World!") -- Hello World!
print(1, 2, 3, 4, 5)  -- 1    2    3    4    5
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 13
* rawequal(v1, v2)
	* v1: Valor que será comparado com `v2`. | v2: Valor que será comparado com `v1`.
	* Uso: Verifica se dois valores são iguais, sem chamar o metamétodo `__eq`.
	* Retorno: `true` caso sejam iguais ou `false` caso contrário.

``` lua
rawequal(1,   1) -- true
rawequal(1, "1") -- false
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 14
* rawget(tbl, id)
	* tbl: Um tabela. | id: Um índice numérico de `tbl`.
	* Uso: Obtem o valor armazenado no índice `id` de `tbl`, sem chamar o metamétodo `__index`.
	* Retorno: O valor obtido.

``` lua
local tbl = {9, 8, 7, 6, 5}
rawget(tbl, 2) -- 8
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 15
* rawlen(tbl_string)
	* tbl_string: Uma tabela ou cadeia de caracteres.
	* Uso: Retorno o comprimento de `tbl_string`, sem chama o metamétodo `__leg`.
	* Retorno: O comprimento de `tbl_string`.

``` lua
rawlen("Hello World!") -- 12
rawlen({9, 8, 7, 6})   -- 4
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 16
* rawset(tbl, id, newValue)
	* tbl: Um tabela. | id: Um índice numérico de `tbl`. | newValue: Um novo valor para `tbl[id]`.
	* Uso: Atribui `newValue` para o índice `id` de `tbl`, sem chamar o metamétodo `__newindex`.
	* Retorno: `tbl`, com seu índice (`id`) alterado.

``` lua
local tbl = {9, 8, 7, 6, 5}
rawset(tbl, 2, 12) -- tbl[2] = 12
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 17
* select(id, ...)
	* id: Um valor numérico (ou `"#"`). | (...): .
	* Uso: Retorna valores de acordo com o valor de `id`.
	* Retorno: Todos os argumentos em `...`, de `id` até último (da esquerda para a direta, caso seja positivo, ou da direita para a esquerda,c aso contrário). Caso seja `id` igual a `"#"` retornará a quantidade de argumentos em `...`.

``` lua
local a, b, c

a, b, c = select("#", 9, 8, 7) -- 3, nil, nil
a, b, c = select( 1,  9, 8, 7) -- 9, 8, 7
a, b, c = select(-1,  9, 8, 7) -- 7, 8, 9
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 18
* setmetatable(tbl, mtbl)
	* tbl: Uma tabela. | mtbl: Uma metatabela.
	* Uso: Atribui `mtbl` como uma metatabela para `tbl`. Caso `mtbl` for `nil`, removerá a metatabela de `tbl`. Caso `tbl` tenha uma campo `__metatable`, gerará um erro.
	* Retorno: `tbl`.

``` lua
local tbl = {}

setmetatable(tbl, {__call = function() return "Hello World!" end})-- add __call
local txt = tbl()) -- txt = "Hello World!"

setmetatable(tbl, {__add  = function(...) local temp = {...} return 20 + temp[2] end}) -- remove __call and add __add
local add = tbl + 5 -- add = 20 + 5

setmetatable(tbl, nil) -- remove: __add

setmetatable(tbl, {__metatable = function() return "__metatable" end}) -- add __call
setmetatable(tbl, {__call = function() return "Hello World!" end}) -- generates an error
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 19
* tonumber(value, [base])
	* value: Valor que será convertido. | base: Usada para a conversão (qualquer valor entre 2-36; 10 por padrão).
	* Uso: Converte `value` para número, caso ele seja uma string válida (contendo apenas números).
	* Retorno: O valor convertido, ou `nil`, caso não seja possível converter `value`.

``` lua
tonumber("1")  -- 1
tonumber("a")  -- nil
tonumber(0xda) -- 218
tonumber("88", 15) -- 128
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 20
* tostring(value)
	* value: Valor de qualquer tipo.
	* Uso: Converte `value` em uma cadeia de caracteres, mas caso `value` possua um campo `__tostring`, ele será chamado com `value` como argumento.
	* Retorno: Uma cadeia de caracteres convertida ou o returno de `__tostring` (caso este campo esteja presente em `value`).

``` lua
tostring(true) -- "true"
tostring(1234) -- "1234"

local value, qtt = {}
setmetatable(value, {__tostring = function(Self) return #Self end})
qtt = tostring(value) -- qtt = 0

for i = 1, 5 do value[i] = i end
qtt = tostring(value) -- qtt = 5
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 21
* type(value)
	* value: Valor de qualquer tipo.
	* Uso: Obtem o tipo de `value`.
	* Retorno: O tipo de `value` em formato de string (podendo ser "nil", "number", "string", "boolean", "table", "function", "thread" ou "userdata").

``` lua
local str, num, boo = 1, "a", false
local tStr, tNum, tBoo

tStr = type(str) -- "number"
tNum = type(num) -- "string"
tBoo = type(boo) -- "boolean"
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 22
* warn(...)
	* (...): Uma quantidade não definida de strings. Por convensão, mensganens de peça única, que comecem com `@`, são destinadas ao próprio sistema de alerta.
	* Uso: Imprime um aviso no console, semelhante a uma mensagem de erro, mas que não interrompe o programa. Chamá-la com `@on` (re)inicia a emissão de avisos, e `@off` à desativa.
	* Retorno: Sem retorno.

``` lua
warn("@on")
warn("Hello", " ", "World", "!") -- Lua warning: Hello World!
warn("@off")
warn("No print", ":(")
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 23
* xpcall(func, erro, [arg])
	* func: A função que será chamda. | erro: Função que será chamada caso `func` possua algum erro. | arg: Os argumentos que serão atribuídos a `func`.
	* Uso: Semelhantemente a `pcall`, esta chama `func` em modo protegido, mas, caso haja algum erro, ela chamará `erro`, com a mensagem de erro como parâmetro.
	* Retorno: `true` e os possíveis retornos de `func` caso não haja nenhum erro na mesma, caso contrário, retornará o retorno de `erro` (que usará a mensagem de erro como primeiro argumento; caso existente) e `false`.

``` lua
local function add(a, b)
	return a + b, a - b
end

local function ifErrror(msg)
	return "THE ERROR IS: "..msg)
end

local func, erro = xpcall(add, ifErrror, 1, false)
-- func = false
-- erro = THE ERROR IS: main.lua:2: attempt to perform arithmetic on a boolean value (local 'b')

local fun2, rtn1, rtn2 = xpcall(add, 2, 3)
-- fun2 = true
-- rtn1 = 5
-- rtn2 = -1
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

#### Fontes:
* https://lua.org/manual/5.4/

<br>

-----
* ###### [Para o topo](#basic)
-----
