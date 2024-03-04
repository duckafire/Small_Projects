# table
Fornece algumas funções para manipulação de tabelas com índices numéricos. <br>
Algumas destas funções podem necessitar do comprimento de uma tabela, o que pode acarretar na chamada do metamétodo `__leg`, caso existente na tabela especificada.

## Funções
* [concat](#1)
* [insert](#2)
* [move](#3)
* [pack](#4)
* [remove](#5)
* [sort](#6)
* [unpack](#7)

<br>

-----
* ###### [Para o topo](#table)
-----
<br>

###### 1
* table.concat(tbl, [sep], [init], [last])
	* tbl: Uma tabela com índices numéricos. | sep: O caractere que será colocado entre cada valor de `tbl`. | init: O índice inicial (de `tbl`) à ser usado. | last: O índice final (de `tbl`) à ser usado.
	* Usos: Concatena todos os valores armazenados nos índices numéricos de `tbl`.
	* Retorno: Uma cadeia de caracteres contendo todos os valores armazenados nos índices numéricos de `tbl`.

``` lua
local peoples = {
	name = { Antônio, Pedro, José, Maria, Bianca },
	age  = { 86, 7, 29, 13, 32 },
}

local man = {
	name = table.concat(peoples.name, ", ",  1, 3), -- "Antônio, Pedro, José"
	age  = table.concat(peoples.age,  " - ", 1, 3), -- "86 - 7 - 29"
}

local woman = {
	name = table.concat(peoples.name, ", ",  4), -- "Maria, Bianca"
	age  = table.concat(peoples.age,  " - ", 4), -- "13 - 32"
}
```

<br>

-----
* ###### [Para o topo](#table)
-----
<br>

###### 2
* table.insert(tbl, [id], value)
	* tbl: Uma tabela numérica. | id: Índice que será preenchido por `value` (`#tbl + 1` por padrão). | value: Valor que será atríbuido à `tbl[id]`.
	* Usos: Adiciona `value` à `tbl`. Caso já exista um valor em `tbl[id]`, ele será "empurrado" para frente, junto com seus sucessores, e `value` tomará o seu lugar.
	* Retorno: Sem retorno.

``` lua
local planets = {"Mercury", "Venus", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"} -- 7

table.insert(planets, 3, "Earth") -- [2] = "Venus", [3] = "Earth", [4] = "Mars", ...

table.insert(planets, "Pluto") -- [9] = "Pluto"

-- NOTE: Pluto is not a planet.
```

<br>

-----
* ###### [Para o topo](#table)
-----
<br>

###### 3
* table.move(tbl1, init_1, last_1, init_2, [tbl2])
	* tbl1: Tabela que terá seus índices movidos. | init_1: Primeiro índice de `tbl1` a ser movido. | last_1: Último índice de `tbl1` a ser movido. | init_2: Índice de `tbl2`, que recebrá o primeiro índice (`init_1`) de `tbl1`. | `tbl2`: Tabela que armazenará os valores movidos de `tbl1` (caso `tbl2` seja omitido, `tbl2` será igual a `tbl1`).
	* Usos: "Move" os valores armazenados em `tbl1`, de `init_1` à `last_1`, para `tbl2` à partir do seu índice `init_2`, podendo substituir valores presentes em `tbl2`.
	* Retorno: A tabela resultante da "movimentação" dos valores de `tbl1` para `tbl2`.

``` lua
local tbl  = {"a", "b", "c"}
local tbl2 = table.move(tbl, 1, 3, 1, {1, 2, 3, 4, 5}) -- {"a", "b", "c", 4, 5}
local tbl3 = table.move(tbl, 1, 3, 6, {1, 2, 3, 4, 5}) -- {1, 2, 3, 4, 5, "a", "b", "c"}
local tbl4 = table.move(tbl, 3, 3, 3, {1, 2, 3, 4, 5}) -- {1, 2, "c", 4, 5}
```

<br>

-----
* ###### [Para o topo](#table)
-----
<br>

###### 4
* table.pack(...)
	* (...): Valores que serão "empacotados".
	* Usos: Cria uma tabela numérica contendo todos os valores presentes em `...`.
	* Retorno: A tabela criada.

``` lua
local bas = table.pack(17, 32, 12, 19) -- base
local add = table.pack(9, 8, 7, 6)
local sub = table.pack(1, 2, 3, 4)
local rst = {} -- ReSulT

for i = 1, #bas do
	local ad = bas[i] + add
	local su = bas[i] - sub
	
	rst[i] = ad * su
end

```

<br>

-----
* ###### [Para o topo](#table)
-----
<br>

###### 5
* table.remove(tbl, [id])
	* tbl: Uma tabela com índices numéricos. | id: O índice do valor a ser removido (`#tbl` por padrão).
	* Usos: Remove `tbl[id]` da mesma. Caso hajam outros valores "acima" de `tbl[id]`, os mesmos "cairão" de posição, ocupando o espaço deixado pela remoção.
	* Retorno: O valor removido.

``` lua
local tbl = {9, 8, 7, 6, 5}

table.remove(tbl)    -- {9, 8, 7, 6}
table.remove(tbl, 1) -- {8, 7, 6}

local seven = table.remove(tbl, 2)
```

<br>

-----
* ###### [Para o topo](#table)
-----
<br>

###### 6
* table.sort(tbl, [func])
	* tbl: Tabela com índices numéricos. | func: Função de tratamento, que recebrá dois valores e deverá retorna `true` ou `false`; permite um "tratamento" customizado.
	* Usos: Organiza os valores presentes em `tbl`, usando a função `func`, mas caso ela seja omitida, `<` será usado em seu lugar, logo, apenas valores numéricos poderão ser organizados.
	* Retorno: Sem retorno.

``` lua
local function ifString(A, B)
	local a = type(A) ~= "number" and tonumber(A) or A
	local b = type(B) ~= "number" and tonumber(B) or B

	return a < b
end

local number = {3, 7, 1, 6}
local string = {"3", "7", "1", "6"}

local noFunc   = table.sort(number) -- {1, 3, 6, 7}
local withFunc = table.sort(string, ifString) -- {1, 3, 6, 7}
```

<br>

-----
* ###### [Para o topo](#table)
-----
<br>

###### 7
* table.unpack(tbl, [init], [last])
	* tbl: Uma tabela com índices númericos. | init: O primeiro índice de `tbl` que será usado (`1` por padrão). | final: O último índice de `tbl` que será usado (`#tbl` por padrão).
	* Usos: "Desempacota" `tbl`.
	* Retorno: Retorna todos os valores armazenados em índices numéricos na tabela `tbl`.

``` lua
local tbl = {1, 2, 3}
local one, two, tree = table.unpack(tbl)
```

<br>

-----
* ###### [Para o topo](#table)
-----
<br>

#### Fontes:
* https://lua.org/manual/5.4/

<br>

-----
* ###### [Para o topo](#table)
-----
