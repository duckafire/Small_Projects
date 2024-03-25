# io
Oferece dois estilos diferentes de manipulação de arquivos:
  * Descritores **imprícitos**: <br>
&emsp; Executam suas ações com base nos arquivos de entrada e saída definidos pelo usuário. Eles são fornecidas por `io.`.
  * Descritores **explícitos**: <br>
&emsp; São métodos disponíveis para variáveis que armazenem identificadores dee arquivos (abertos). São eles: `close`, `flush`, `lines`, `read`, `seek`, `setvbuf` e `write`.

<br>

> As funções [em](#funções) estão etiquetadas de acordo com o que foi dito acima.

<br>

### Descritores padrão
A tabela `io` fornece três descritores (variáveis) de arquivos pré-definidos, derivados de C, os quais nunca são fechados.

| Nomes     | Descrição                                                                       |
| :-:       | :-:                                                                             |
| io.stdin  | Armazena o fluxo de entrada, gerado, por exemplo, por um teclado.               |
| io.stdout | Armazena determinados dados para uso em *dispositivos* de saída (console, ...). |
| io.stderr | Armazena mensagens de erro fatais, as quais são exibidas no *console*           |

> Em caso de falha, a maioria destas funções retornarão `nil`, uma mensagem de erro e um código de erro (que vária de acordo com o *OS*), já as demais gerarão um erro fatal. <br>
> Em sistemas não [*Posix*](https://pt.wikipedia.org/wiki/POSIX "Wikipédia: O que é Posix?"), caso hajam muitos fluxos em execução, as mensagens de erro (em caso de falha) podem
> não ser seguras, tendo em vista que tais mensagens dependem da variável global `errno`, de C.

<br>

### Modos de leitura

| Nomes | Função (descrição do modo)                                                                                     |
| :-:   | :-:                                                                                                            |
| "r"   | Leitura                                                                                                        |
| "w"   | Escrita                                                                                                        |
| "a"   | Adição                                                                                                         |
| "r+"  | Atualização, todos os dados anteriores são preservados                                                         |
| "w+"  | Atualização todos os dados anteriores são apagados                                                             |
| "a+"  | Atualização de edição, todos os dados anteriores são presevados, a ecrita é permitida apenas no fim do arquivo |

> Alguns sistemas exigem um `"b"`, no fim das cadeias, para a abertura de arquivos em binário.

<br>

### Formatos de leitura

| Formatos | Descrição                                                                                                                                                                |
| :-:      | :-:                                                                                                                                                                      |
| "n"      | Lê um numeral e o retorna, seguindo as conveções lexicais de LUA. P ter espaços a esquerda e um sinal. Sempre lê a seguênca de entrada mais longa que é um profixo válido para um numeral; caso o prefixo não forme um numeral valído (ex: "", "0x", "3.4e-") ou seja muito longo (>200), será descartado e gerará uma falha para retorno. |
| "a"      | Lê todo o arquivo, começando da posição atual. Ao fim, retorna uma cadeia vazia. Nunca falha.                                                                            |
| "l"      | Lê a próxima linha pulando o fim da linha e retornando `nil` no final.                                                                                                   |
| "L"      | Lê a próxima linha mantendo o fim da linha (se presente) e retornando `nil` no final.                                                                                    |
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
	* Usos: Fecha `file`, caso ele não seja especificado, fecha o arquivo de saída padrão (definida por `io.output`).
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
	* Usos: Garante que as alterações presentes no *buffer* do arquivo de saída padrão (definido por `io.output`) sejam salvas.
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
	* file: Indetificador de arquivo (variável).
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
	* Usos: Abre `filename` e gera uma função interadora que funciona sobre ele, usando `...` como parâmetro(s) a cada chamada. O arquivo será fechado quando a função interadora não conseguir mais ler arquivos ou ao encontrar um `break` (com "`for` genérico").
	* Retorno: Uma função interadora, dois valores `nil` com espaços reservados e o identificador do arquivo. Quando sua função interadora chega ao fim do arquivo, ela retorna `nil`.

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
	* Retorno: Um manipulador de arquivo ou `nil` e uma mensagem de erro, em caso de falha.

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
	* file: Indetificador de arquivo (variável).
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
> [Modos de leitura](#modosdeleitura).

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
	* (...): Formatos de leitura, que especificam o que ler (`"l"` por padrão).
	* Usos: Lê o arquivo de entrada padrão de acordo com as especificações dos formatos especificados em `...`.
	* Retorno: Para cada formato dado por `...`, retornará uma cadeia de caracteres ou um número com os caracteres lidos. Caso chamada sem argumentos, retornará o que for escrito no console (pelo usuário).

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
	* Retorno: Em caso de sucesso, retornará um indentificador para o arquivo criado.

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
	* Usos: Verifica se `var` é um arquivo e, caso seja, se ele está aberto ou fechado.
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
	* Retorno: Ao fechar um arquivo aberto com `io.popen`, retornará o mesmo que `os.execute`, caso contrário, não terá um retorno.

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
	* Usos: Garante que as alterações presentes no *buffer* de `file` sejam salvas.
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
	* Usos: Abre `file` e gera uma função interadora que funciona sobre ele.
	* Retorno: Uma função interadora, dois valores `nil` com espaços reservados e o identificador do arquivo. Quando está função interadora chega ao fim do arquivo ela retorna `nil`.

> Ao contrário de `io.lines`, a função interadora, retornada por esta função, não fecha `file` após o fim do *loop*.

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
	* Usos: Lê `file` de acordo com as especificações dadas em `...` (`"l"` por padrão).
	* Retorno: Para cada formato, retornará uma cadeia de caracteres ou um número com os caracteres lidos. Caso chamada sem argumentos, retornará o que for escrito no console (pelo usuário).

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
* file:seek([whence], [[offset]])
	* whence: Ponto incial da medida (`"cur"` por padrão). | offset: Ponto final da medida (`0` por padrão).
	* Usos: Estabelece a **posição atual** de `file`, usada pelo formato de feitura [`"a"`](formatosdeleitura). Através da medida: **posição atual** (`whence`) + `offset`.
	* Retorno: A posição definida como atual para `file` ou a posição atual (caso chamada sem parâmetros) ou, em caso de falha, `0` e uma mensagem de erro.

> `whence` pode assumir os seguintes valores:
>> `"set"` -> Início do arquivo. <br>
>> `"cur"` -> Posição atual. <br>
>> `"end"` -> Fim do arquivo. <br>

``` lua
local file = io.open("example.txt", "a+")
print("[ CONSOLE ]\n")

-- initial = 0; final = 
print(file:read("a").."\n")

file:seek("set", 12) -- 12 (10 + 2)
print(file:read("a").."\n")

file:seek("end", -5) -- 17 (15 + 2)
print(file:read("a"))

file:close()
```

```
[ CONSOLE ]

0
0123456789
0123456789

12
0123456789

17
56789
```

> Quebras de linha (`"\n"`) são interpretadas caracteres, logo cada quebra de linha acrescenta mais dois ao "comprimento" do arquivo.

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 17
* file:setvbuf(mode, [size])
	* mode: O modo que será usado | size: Especifica o tamanho do *buffer*, em *bytes* (um "tamanho apropriado" por padrão).
	* Usos: Define o modo de *bufferização* de `file`.
	* Retorno: Sem retorno.

> `mode` pode assumir os seguintes valores:
>> `"no"`   -> Sem *bufferização* (resultados instatâneos para qualquer operação de saída). <br>
>> `"full"` -> *Bufferização* completa (a operação é realizada quando o *buffer* está cheio ou quando o usuário chamar `io.flush()`). <br>
>> `"line"` -> *Bufferização* de linha (a *bufferização* ocorre quando uma quebra de linha é produzida ou se ouver a entrada de arquivos especiais, como um "dispositivo" terminal). <br>

``` lua
local file = io.open("example.txt", "w")
file:setvbuf("full")

file:write("Hello World!")

file:flush()
file:close()
```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 18
* file:write(...)
	* (...): Cadeias de caracteres (ou números).
	* Usos: Escreve os argumentos presente em `...` no *buffer* de `file`.
	* Retorno: `file` ou, em caso de falha, retornará `file` e uma mensagem de erro.

``` lua
local file = io.open("example.txt", "w")

file:write("Hello World!")
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
