# Basic
Oferece uma série de funções báscias para usos diversos e essenciais.

> _G: **Variável global** que armazena o ambiente global. LUA não usa essa variável em sim; Alterar seu valor não afeta nenhum ambiente, e vice-versa.
> _VERSION: **Variável global** que possui o valor do interpretador LUA em execução.

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
* [xpcall](#22)

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 1
* assert(exp, [msg])
	* exp: Expressão booleana. | msg: Mensagem de erro customizada ("assertion failed!" por padrão).
	* Uso: Verifica se `exp` é verdadeiro, caso não, interrompe o programa e imprime a mensagem espeficada em `msg` no console.
	* Retorno: Sem retorno.

``` lua
assert(true, ">>> Program end <<<")-- not stop the program

assert(false, ">>> Program end <<<")-- stop the program
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 2
* collectgarbage([action, [arg]])
	* action: A ação que será executada pelo coletor de lixo. | arg: Valor opcional, requerido por (algumas ações): `step`
	* Uso: Permiti ordenar que o coletor de lixo execute uma deteminada ação.
	* Retorno: Apenas as ações `count`, `step` geram retorno(s).

| Ação         | Descrição |
| :-:          | :-:       |
| collect      | Realiza um ciclo de coleta (padrão) |
| stop         | Para a coleta automatica |
| restart      | Reinicia a execução da coleta automática |
| count        | Permite retorna a memória total em uso (em `Kbytes`). |
| step         | Executa um passo da coleta de lixo. Seu "tamanho" é controlado por `arg`, onde `0` executará uma etapa básica (indivisível) e, caso seja diferente de `0`, o coletor tratará esse valor como se fosse uma quantidade de memória (em `Kbytes`) em uso. Permite o retorno de `true`, caso a etapa conclua um ciclo de coleta. |
| isrunning    | Permite retornar `true` caso o coletor esteja em execução. |
| incremental  | Altera o modo do coletor para *incremental*. Esa configuração pode ser seguida por três números (`arg`, `arg2` e `arg3`): O intervalo entre os ciclos (pausa), o multiplicador de passos e o tamanho do degrau (´0´ = valor não alterado; [sobre](https://lua.org/manual/5.4/manual.html#2.5.1 "Coleta Incremental")) |
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

local txt, txt2 = dofile("call.lua")

print("[ CONSOLE ]\n")
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
	* Retorno: caso `object` possua uma metatabela, retornará o endereço de memória da mesma, caso não, retornará o valor de `object` (seu endereço, caso seja uma função ou tabela).

``` lua
local a = {}
a.__index = a
local b = {}
local c = setmetatable(b, a)-- "a" is the metatable of "c"

print(a)               -- table: "a address"
print(getmetatable(c)) -- table: "a address"

local d = {}
local e
local f = function() end
local g = 1

print(d) -- table: "d adress"
print(e) -- nil
print(f) -- function: "f address"
print(g) -- 1
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 6
* ipairs(tbl)
	* tbl: Uma tabela.
	* Uso: Intera entre os pares índice-valor de `tbl`, até o primeiro índice ausente.
	* Retorno: Uma função interadora, `tbl` e `0`.

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
* load(id, [source, [mode, [env]]])
	* parameter1: blank. | parameter2: blank.
	* Uso: Blank.
	* Retorno: Blank.

``` lua
local call = load("print('Hello World!')")
call()
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 1
* type name(type parameter1, type parameter2)
	* parameter1: blank. | parameter2: blank.
	* Uso: Blank.
	* Retorno: Blank.

``` c
int main(){
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 1
* type name(type parameter1, type parameter2)
	* parameter1: blank. | parameter2: blank.
	* Uso: Blank.
	* Retorno: Blank.

``` c
int main(){
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 1
* type name(type parameter1, type parameter2)
	* parameter1: blank. | parameter2: blank.
	* Uso: Blank.
	* Retorno: Blank.

``` c
int main(){
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 1
* type name(type parameter1, type parameter2)
	* parameter1: blank. | parameter2: blank.
	* Uso: Blank.
	* Retorno: Blank.

``` c
int main(){
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 1
* type name(type parameter1, type parameter2)
	* parameter1: blank. | parameter2: blank.
	* Uso: Blank.
	* Retorno: Blank.

``` c
int main(){
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 1
* type name(type parameter1, type parameter2)
	* parameter1: blank. | parameter2: blank.
	* Uso: Blank.
	* Retorno: Blank.

``` c
int main(){
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 1
* type name(type parameter1, type parameter2)
	* parameter1: blank. | parameter2: blank.
	* Uso: Blank.
	* Retorno: Blank.

``` c
int main(){
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 1
* type name(type parameter1, type parameter2)
	* parameter1: blank. | parameter2: blank.
	* Uso: Blank.
	* Retorno: Blank.

``` c
int main(){
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 1
* type name(type parameter1, type parameter2)
	* parameter1: blank. | parameter2: blank.
	* Uso: Blank.
	* Retorno: Blank.

``` c
int main(){
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 1
* type name(type parameter1, type parameter2)
	* parameter1: blank. | parameter2: blank.
	* Uso: Blank.
	* Retorno: Blank.

``` c
int main(){
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 1
* type name(type parameter1, type parameter2)
	* parameter1: blank. | parameter2: blank.
	* Uso: Blank.
	* Retorno: Blank.

``` c
int main(){
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 1
* type name(type parameter1, type parameter2)
	* parameter1: blank. | parameter2: blank.
	* Uso: Blank.
	* Retorno: Blank.

``` c
int main(){
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 1
* type name(type parameter1, type parameter2)
	* parameter1: blank. | parameter2: blank.
	* Uso: Blank.
	* Retorno: Blank.

``` c
int main(){
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 1
* type name(type parameter1, type parameter2)
	* parameter1: blank. | parameter2: blank.
	* Uso: Blank.
	* Retorno: Blank.

``` c
int main(){
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#basic)
-----
<br>

###### 1
* type name(type parameter1, type parameter2)
	* parameter1: blank. | parameter2: blank.
	* Uso: Blank.
	* Retorno: Blank.

``` c
int main(){
	
	return 0;
}
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
