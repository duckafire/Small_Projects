# io
Oferece dois estilos diferentes de manipulação de arquivos:
  * Descritores **imprícitos**: <br>
&emsp; Os quais executam operações para definir um arquivo padrão de entrada e saída, centralizando esses respectivos eventos nele. Eles são fornecidas por `io.`.
  * Descritores **explícitos**: <br>
&emsp; Para usar estes, se faz necessário atribuir um retorno válido de `io.open` à alguma variável, o que irá permitir que tal variável tenha acesso aos seguintes métodos:
`close`, `flush`, `lines`, `read`, `seek`, `setvbuf` e `write`.

<br>

### Descritores padrão
A tabela `io` fornece três descritores de arquivos pré-definidos, derivados de C, os quais nunca são fechados.

| Nomes     | Descrição                                                                                 |
| :-:       | :-:                                                                                       |
| io.stdin  | Fornece uma leitura de fluxo de entrada, gerada, por exemplo, por um teclado              |
| io.stdout | Fornece, para exibição, determinados dados para *dispositivos* de saída, como o *console* |
| io.stderr | Fluxo padrão para mensagens de erro fatais, as quais são exibidas no *console*            |

> Em caso de falha, a maioria destas funções retornarão `nil`, uma mensagem de erro e um código de erro (que vária de acordo com o *OS*), já as demais gerarão um erro fatal. <br>
> Em sistemas não [*Posix*](https://pt.wikipedia.org/wiki/POSIX "Wikipédia: O que é Posix?"), caso hajam muitos fluxos em execução, as mensagens de erro (em caso de falha) por
não ser seguras, tendo em vista que tais mensagens dependem da variável global `errno`, de C.

<br>

### Modos de leitura

| Nomes | Função (descrição do modo)                                                                                              |
| :-:   | :-:                                                                                                                     |
| "r"   | Leitura                                                                                                                 |
| "w"   | Escrita                                                                                                                 |
| "a"   | Adição                                                                                                                  |
| "r+"  | Atualização, todos os dados anteriores são preservados                                                                  |
| "w+"  | Atualização todos os dados anteriores são apagados                                                                      |
| "a+"  | Atualização de edição, todos os dados anteriores são presevados, a ecrita é permitida apenas no fim do arquivo          |

> Alguns sistemas exigem um `"b"`, no fim das cadeias, para a bertura de arquivos em binário.

<br>

### Formatos de leitura

| Formatos | Descrição                                                                                                                                                                |
| :-:      | :-:                                                                                                                                                                      |
| "n"      | Lê um numeral e o retorna, seguindo as conveções lexicais de LUA (podendo ele ter espaços a esquerda e um sinal). Sempre lê a seguênca de entrada mais longa que é um profixo válido para um numeral; caso o prefixo não forme um numeral valído (ex: "", "0x", "3.4e-") ou seja muito longo (>200), será descartado e gerará uma falha para retorno. |
| "a"      | Lê todo o arquivo, começando da posição atual. Ao fim, retorna uma cadeia vazia. Nunca falha.                                                                            |
| "l"      | Lê a próxima linha pulando o fim da linha e retornando `nil` no fim.                                                                                                     |
| "L"      | Lê a próxima linha mantendo o fim da linha (se presente) e retornando `nil` no fim.                                                                                      |
| "number" | Lê uma cadeia com no máximo `number` (= qualquer número) *bytes* e retorna `nil` no fim. Caso `number == 0`, não lerá nada e retornará `""`, ou `nil` ao fim do arquivo. |

> `"l"` e `"L"` devem ser usados apenas para arquivos de texto.

<br>

## Funções
* [close](#1 "Implícito")
* [flush](#2 "Implícito")
* [input](#3 "Implícito")
* [lines](#4 "Implícito")
* [open](#5 "Implícito")
* [output](#6 "Implícito")
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

<br>

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
* io.input([file])
	* file: Nome de um arquivo ou variável que armazene um arquivo.
	* Usos: Define `file` como arquivo de entrada padrão.
	* Retorno: O arquivo de entrada padrão se `file` for omitido, caso contrário não terá retorno.

``` lua
io.input("example.txt")

-- is equal:

local any = io.open("example.txt", "r")
```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 4
* io.lines([filename], [...])
	* filename: Nome de um arquivo. | (...): Formatos de leitura para cada chamada da função interadora (`"l"` por padrão).
	* Usos: Abre `filename` e gera uma função interadora que funciona sobre ele, usando `...` como parâmetro(s) a cada chamada. O arquivo será fechado quando a função interadora não conseguir mais ler arquivos ou ao encontrar um`break` (em `for`).
	* Retorno: Uma função interadora, dois valores `nil` com espaços reservados e o identificador do arquivo. Quando sua função interadora chega ao fim do arquivo ela retorna `nil`.

``` lua
-- MAIN

for v in io.lines("example.txt") do
	print(v)
end 

-- io.lines()
-- is equal:
-- io.input():io.lines("l")
```

> Conteúdo de `example.txt` imprido no console:

```
[ CONSOLE ]

example.txt
End of file
```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 5
* io.open(filename, [mode])
	* filename: Arquivo que será aberto. | mode: Modo de manipulação para `filename` (`"r"` por padrão).
	* Usos: Abre `filename` no modo especificado por `mode`.
	* Retorno: Um manipulador de arquivo ou `nil` e uma mensagem de erro em caso de falha.

> [Modos de leitura](#modosdeleitura)

``` lua
local fTxt = io.open("example_txt.txt")
local fLua = io.open("example_lua.lua")

local _nil, _error = io.open("file")
```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 6
* io.output(([file])
	* file: Nome de um arquivo ou variável que armazene um arquivo.
	* Usos: Define `file` como arquivo de saída padrão.
	* Retorno: O arquivo de saída padrão se `file` for omitido, caso contrário não terá retorno.

``` lua
io.output("example.txt")

-- is equal:

local any = io.open("example.txt", "r")
```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 7
* io.popen(program, [mode])
	* program: Um programa que será executado e lido | mode: Modo de manipulação para `filename` (`"r"` por padrão ou `"w"`).
	* Usos: Inicia `program` em um processo separado.
	* Retorno: Um manipulador de arquivo para ler dados de `program`.

> Está função não está disponível em todas as plataformas, pois é dependente do sistema. <br>
> [Modos de leitura](#modosdeleitura)

``` lua
-- "echo" is a CMD and BASH command,
-- it print "Hello World!" (messange)
-- in the console.
local file = io.popen("echo Hello World", "w")
file:close()
```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 8
* io.read(...)
	* (...): Formatos de leitura, que especificam o que ler.
	* Usos: Lê o arquivo de entrada padrão de acordo com as especificações dos formatos especificados em `...` (`"l"` por padrão).
	* Retorno: Para cada formato, retornará uma cadeia de caracteres ou um número com os caracteres lidos.

> [Formatos de leitura](#formatosdeleitura)

``` lua
local file = io.open("temp.txt", "r")
io.input(file)

io.read("a")

io.close()
```

```
[ CONSOLE ]

12345
abcde
```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 9
* io.tmpfile()
	* Sem parâmetros.
	* Usos: Cria um arquivo temporário, que é descartado com o termino do programa.
	* Retorno: Um indentificador para o arquivo criado.

``` lua
local tempFile = io.tmpfile()
```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 10
* io.type(var)
	* var: Uma variável contendo um indentificador de arquivo.
	* Usos: Verifica `var` é um arquivo e, caso seja, se ele está aberto ou fechado.
	* Retorno: `"file"` caso `var` seja um arquivo aberto, `"closed file"` caso seja um arquivo fechado ou `nil` caso não seja um indetificado de arquivo.

``` lua
local var = io.open("example.txt", "r")
local num = 49

io.type(var) -- "file"

var:close()

io.type(var) -- "closed file"

io.type(num) -- nil
```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 11
* io.write(...)
	* (...): Cadeias de caracteres (ou números).
	* Usos: Escreve os argumentos presente em `...` no arquivo de saída padrão.
	* Retorno: O arquivo de saída padrão ou, em caso de falha, retornará `file` e uma mensagem de erro.

``` lua
local file = io.open("example.txt", "w")
io.output(file)

io.write("Hello World!")
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
* file:lines([...])
	* (...): Formatos de leitura para cada chamada da função interadora (`"l"` por padrão).
	* Usos: Abre `file` e gera uma função interadora que funciona sobre ele. O arquivo será fechado quando a função interadora não conseguir mais ler arquivos ou ao encontrar um`break` (em `for`).
	* Retorno: Uma função interadora, dois valores `nil` com espaços reservados e o identificador do arquivo. Quando sua função interadora chega ao fim do arquivo ela retorna `nil`.

> Ao contrário de `io.lines`, a função interadora, retornada por esta função (`file:lines`), não fecha `file` após o fim do *loop*.

``` lua
-- MAIN

local file = io.open("example.txt")

for v in file:lines() do
	print(v)
end 

-- io.lines()
-- is equal:
-- io.input():io.lines("l")
```

> Conteúdo de `example.txt` imprido no console:

```
[ CONSOLE ]

example.txt
End of file
```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 15
* file:read(...)
	* (...): Formatos de leitura, que especificam o que ler.
	* Usos: Lê `file` de acordo com as especificações dos formatos especificados em `...` (`"l"` por padrão).
	* Retorno: Para cada formato, retornará uma cadeia de caracteres ou um número com os caracteres lidos.

> [Formatos de leitura](#formatosdeleitura)

``` lua
local file = io.open("temp.txt", "r")

file:read("a")

file:close()
```

```
[ CONSOLE ]

12345
abcde
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
* file:write(...)
	* (...): Cadeias de caracteres (ou números).
	* Usos: Escreve os argumentos presente em `...` em `file`.
	* Retorno: `file` ou, em caso de falha, retornará `file` e uma mensagem de erro.

``` lua
local file = io.open("example.txt", "w")

file:write("Hello World!")

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
