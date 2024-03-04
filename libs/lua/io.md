# io
Oferece dois estilos diferentes de manipulação de arquivos:
  * Descritores **imprícitos**: <br>
&emsp; Os quais executam operações para definir um arquivo padrão de entrada e saída, centralizando esses respectivos eventos nele. Eles são fornecidas por `io.`.
  * Descritores **explícitos**: <br>
&emsp; Para usar estes, se faz necessário atribuir um retorno válido de `io.open` à alguma variável, o que irá permitir que tal variável tenha acesso aos seguintes métodos:
`close`, `flush`, `lines`, `read`, `seek`, `setvbuf` e `write`.

### Descritores padrão
A tabela `io` fornece três descritores de arquivos pré-definidos, derivados de C, os quais nunca são fechados.

| Nomes     | Descrição                                                                                 |
| :-:       | :-:                                                                                       |
| io.stdin  | Fornece uma leitura de fluxo de entrada, gerada, por exemplo, por um teclado              |
| io.stdout | Fornece, para exibição, determinados dados para *dispositivos* de saída, como o *console* |
| io.stderr | Fluxo padrão para mensagens de erro fatais, as quais são exibidas no *console*            |

> Em caso de falha, ambas as funções retornarão `nil`, uma mensagem de erro e um código de erro (que vária de acordo com o *OS*). <br>
> Em sistemas não [*Posix*](https://pt.wikipedia.org/wiki/POSIX "Wikipédia: O que é Posix?"), caso hajam muitos fluxos em execução, as mensagens de erro (em caso de falha) por
não ser seguras, tendo em vista que tais mensagens dependem da variável global `errno`, de C.

## Funções
* [close](#1 "Implícito")
* [flush](#2 "Implícito")
* [input](#3 "Implícito")
* [lines](#4 "Implícito")
* [open](#5 "Implícito")
* [ouput](#6 "Implícito")
* [popen](#7 "Implícito")
* [read](#8 "Implícito")
* [tmpfile](#9 "Implícito")
* [type](#10 "Implícito")
* [write](#11 "Implícito")
* [file:close](#12 "Explícito")
* [file:flush](#13 "Explícito")
* [file:lines](#14 "Explícito")
* [file:read](#15 "Explícito")
* [file:seek](#16 "Explícito")
* [file:setvbuf](#17 "Explícito")
* [file:write](#18 "Explícito")

> `file` é um exemplo de variável que armazena um retorno de `io.open`.

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 1
* io.close([file])
	* file: Uma variável que armazene um arquivo.
	* Usos: Fecha `file`, caso ele não seja especificado, fecha o arquivo de saída padrão (definido por `io.output`).
	* Retorno: Sem retorno.

> Arquivos também são fechados pelo Coletor de Lixo, mas isso leva um tempo imprevisível para ocorrer.

``` lua
local file = io.open("emxaple.txt", "r")
io.close(file)

local fil2 = io.open("emxaple.txt", "r")
io.output(fil2) -- set fil2 like default output file
io.close() -- close fil2
```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 2
* io.flush()
	* Sem parâmetros.
	* Usos: Garante que as alterações feitas no arquivo de saída padrão (definido por `io.output`) sejam salvas.
	* Retorno: Sem retorno.

``` lua
local file = io.open("example.txt", "w")
io.output(file)

io.write( io.read() )

io.flush()
io.close()
```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 3
* io.input(parameter1, parameter2)
	* parameter1: blank. | parameter2: blank.
	* Usos: Blank.
	* Retorno: Blank.

``` lua

```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 4
* io.lines(parameter1, parameter2)
	* parameter1: blank. | parameter2: blank.
	* Usos: Blank.
	* Retorno: Blank.

``` lua

```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 5
* io.open(parameter1, parameter2)
	* parameter1: blank. | parameter2: blank.
	* Usos: Blank.
	* Retorno: Blank.

``` lua

```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 6
* io.output(parameter1, parameter2)
	* parameter1: blank. | parameter2: blank.
	* Usos: Blank.
	* Retorno: Blank.

``` lua

```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 7
* io.popen(parameter1, parameter2)
	* parameter1: blank. | parameter2: blank.
	* Usos: Blank.
	* Retorno: Blank.

``` lua

```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 8
* io.read(parameter1, parameter2)
	* parameter1: blank. | parameter2: blank.
	* Usos: Blank.
	* Retorno: Blank.

``` lua

```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 9
* io.tmpfile(parameter1, parameter2)
	* parameter1: blank. | parameter2: blank.
	* Usos: Blank.
	* Retorno: Blank.

``` lua

```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 10
* io.type(parameter1, parameter2)
	* parameter1: blank. | parameter2: blank.
	* Usos: Blank.
	* Retorno: Blank.

``` lua

```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 11
* io.write(parameter1, parameter2)
	* parameter1: blank. | parameter2: blank.
	* Usos: Blank.
	* Retorno: Blank.

``` lua

```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 12
* file:close()
	* Sem parâmetros.
	* Usos: Fecha `file`.
	* Retorno: Ao fechar um arquivo aberto com `io.popen`, retornará o mesmo que caso `os.execute`, caso contrário, não terá um retorno.

> Arquivos também são fechados pelo Coletor de Lixo, mas isso leva um tempo imprevisível para ocorrer.

``` lua
local file = io.open("emxaple.txt", "r")
file:close()

local fil2 = io.open("emxaple.txt", "r")
io.output(fil2)
io.output():close()
```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 13
* file:flush()
	* Sem parâmetros.
	* Usos: Garante que as alterações feitas em `file` sejam salvas.
	* Retorno: Sem retorno.

``` lua
local file = io.open("example.txt", "w")

file:write( file:read() )

file:flush()
file:close()
```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 14
* file:lines(parameter1, parameter2)
	* parameter1: blank. | parameter2: blank.
	* Usos: Blank.
	* Retorno: Blank.

``` lua

```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 15
* file:read(parameter1, parameter2)
	* parameter1: blank. | parameter2: blank.
	* Usos: Blank.
	* Retorno: Blank.

``` lua

```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 16
* file:seek(parameter1, parameter2)
	* parameter1: blank. | parameter2: blank.
	* Usos: Blank.
	* Retorno: Blank.

``` lua

```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 17
* file:setvbuf(parameter1, parameter2)
	* parameter1: blank. | parameter2: blank.
	* Usos: Blank.
	* Retorno: Blank.

``` lua

```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 18
* file:write(parameter1, parameter2)
	* parameter1: blank. | parameter2: blank.
	* Usos: Blank.
	* Retorno: Blank.

``` lua

```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

#### Fontes:
* https://lua.org/manual/5.4/

<br>

-----
* ###### [Para o topo](#io)
-----
