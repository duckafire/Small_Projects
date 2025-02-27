# string
Fornece uma gama de funções destinadas a manipulação de cadeias de caracteres.

> [!TIP]
> *Fluxos de arquivo* recebem alguns métodos, estes estão destacados com `*`.
> 
> ``` lua
> -- example
> string.len(str)
> str:len()
> ("Hello world!"):len()
> ```
>
> Funções que solicitam índices de caracteres também aceitam valores negativos, os quais
> referenciam posições partidas do final da cadeia de caracteres em questão.

---

### Padrão

Este é um conjunto de caracteres especiais, semelhante ao conjunto
[*regex*](https://en.wikipedia.org/wiki/Regular_expression "Wikipédia") (porém limitado),
próprio da linguagem Lua. Ambos são usados em correspondências de sintaxe pela funções:
[`string.find`](#4), [`string.gmatch`](#6), [`string.gsub`](#7) e [`string.match`](#10).

* Fontes:
	* [Lua manual 5.3](https://lua.org/manual/5.3/manual.html#6.4.1)
	* [Rip Tutorial](https://riptutorial.com/lua/example/20315/lua-padrãoing)
	* [Cheatography](https://cheatography.com/ambigious/cheat-sheets/lua-string-patterns/)

| Classes de caracteres | Tipo de caractere representado |
| :-:| :--                              |
| %a | a-z; A-Z                         |
| %c | caracteres de controle           |
| %d | 0-9                              |
| %g | caracteres imprimíveis (-espaço) |
| %l | a-z                              |
| %p | caracteres de pontuação          |
| %s | espaço                           |
| %u | A-Z                              |
| %w | caracteres alfanuméricos         |
| %x | 0-f                              |
| %z | zero                             |
| .  | qualquer caractere               |

---

| Caractere | Modificação |
| :-: | :-- |
| +   | `1=>` ocorrências |
| *   | `0=>` ocorrências |
| -   | `0>=` ocorrências |
| ?   | 0-1 ocorrência (opcional) |

---

| Outros   | Descrição |
| :-:      | :-- |
| *A*      | um alfanumérico específico diferente de `^$()%.[]*+-?`  |
| % *A*    | um caractere não alfanumérico (representa ele próprio) |
| %b *A Z* | qualquer cadeia de caracteres que comece com *A* e termine com *Z* (ambos são QUALQUER caractere) |
| %n       | quantidade de repetições |
| [ _set _]   | conjunto de caracteres; a correspondência deve ser igual     |
| [\^ *set*] | conjunto de caracteres; a correspondência deve ser diferente |
| %f[ *set*] | uma fronteira, onde o caractere anterior a *set* não deve pertencer a ele |

---

### Formato de (des)empacotamento

As funções `string.pack`, `string.packsize` e `string.unpack` solicitam um dos seguintes formatos como primeiro argumento: 

[le]: https://en.m.wikipedia.org/wiki/Endianness
[be]: https://en.m.wikipedia.org/wiki/Endianness

| Cadeias | Descrição |
| :-: | :-- |
| < | define a "ordem de *bytes*" como [_little endian_][le] |
| > | define a "ordem de *bytes*" como [_big endian_][be] |
| = | define a "ordem de *bytes*" como nativa da máquina cujo código está sendo executado |
| ![ *n*] | define o alinhamento máximo para `n` (nativo por padrão) |
| b | um `char` assinado |
| B | um `char` sem sinal |
| h | um `short` assinado (tamanho nativo) |
| H | um `short` sem sinal (tamanho nativo) |
| l | um `long` assinado (tamanho nativo) |
| L | um `long` sem sinal (tamanho nativo) |
| j | um `lua_Integer` |
| J | um `lua_Unsigned` |
| T | um `size_t` (tamanho nativo) |
| i[ *n*] | um `int` com `n` *bytes* (tamanho nativo) |
| I[ *n*] | um `unsigned int` com `n` *bytes* (tamanho nativo) |
| f | um `float` (tamanho nativo) |
| d | um `double` (tamanho nativo) |
| n | um `lua_Number` |
| c *n* | uma cadeia de caracteres, de tamanho fixo, com `n` *bytes* |
| z | uma cadeia de caracteres terminada com `\0` |
| s[ *n*] | uma cadeia de caracteres precedida por seu comprimento codificado como um inteiro sem sinal (`size_t` por padrão) |
| x | um *byte* de preenchimento |
| X *op* | um item vazio que se alinha de acordo com *op* |
| "" | espaço vazio (ignorado) |

---

||Funções||
|:-:|:-:|:-:|
|[string.byte](#1)  |[string.gsub](#7)     |[string.rep](#13)    |
|[string.char](#2)  |[string.len](#8)      |[string.reverse](#14)|
|[string.dump](#3)  |[string.lower](#9)    |[string.sub](#15)    |
|[string.find](#4)  |[string.match](#10)   |[string.unpack](#16) |
|[string.format](#5)|[string.pack](#11)    |[string.upper](#17)  |
|[string.gmatch](#6)|[string.packsize](#12)||

---

### *string.byte(string, [number0=1, [number1=number0]])
###### 1

* Comportamento: obtém os códigos numéricos, de `string`, do caractere de índice `number0`
até `number1`.
* Retorno: os códigos numéricos.

> [!IMPORTANT]
> Tais códigos podem não ser portáveis entre plataformas.

---

### string.char(...)
###### 2

* Comportamento: converte uma série de códigos numéricos em caracteres e, em seguida, os
agrupa em uma cadeia.
* Retorno: a cadeia de caracteres.

> [!IMPORTANT]
> Tais códigos podem não ser portáveis entre plataformas.

---

### string.dump(function_, [boolean=false])
###### 3

* Comportamento: converte uma função em código binário. Caso `boolean==true`, a versão
binária de `function_` poderá não incluir todas as informações de depuração sobre a função,
como forma de economizar espaço.
* Retorno: uma cadeia de caracteres contendo uma representação binária de `function_`.

---

### *string.find(string, substring, [number=1, [boolean=false]])
###### 4

* Comportamento: procura pela primeira ocorrência de `substring` em `string`, a partir do
caractere de índice `number`. `boolean==true` especifica que o [Padrão](#padrão) não deve
ser usado.
* Retorno: o índice do primeiro e do último caractere de `substring`, encontrado em
`string`. Ou `nil`, caso nada seja encontrado.

---

### *string.format(string, ...)
###### 5

* Comportamento: formata `string`, substituindo os "caracteres mágicos" dela por um
argumento respectivo presente em `...`.
* Retorno: `string` com as formatações especificadas.

> [!TIP]
>  Os "caracteres mágicos" seguem o
> [padrão C](https://cplusplus.com/reference/cstdio/printf/).

---

### *string.gmatch(string, pattern)
###### 6

* Comportamento: obtém uma função de interação, que interage sobre os caracteres de
`string`.
* Retorno: uma função de interação, que retora uma fração de `string`, equivalente ao
[Padrão](#padrão) fornecido em `pattern`.

---

### *string.gsub(string, pattern, str_tab_func, [number=nil])
###### 7

* Comportamento: substitui todas (ou `number` vezes) as ocorrências de `str_tab_func` em
`string`, baseado em [Padrão](#padrão).
* Retorno: uma cadeia de caracteres com os respectivos trechos substituídos.

> [!IMPORTANT]
> `foo` pode ser uma cadeia de caracteres, uma tabela ou uma função, onde:
> 
> * Cadeia: seu conteúdo substituirá os trechos de `string`.
> * Tabela: o trecho capturado será usado como índice para obter um de seus valores,
> o qual será utilizado para sobrescrever os trechos de `string`.
> * Função: o trecho capturado lhe será dado como argumento e seu retorno substituirá os
> trechos de `string`.
>
> As operações com tabelas e funções só ocorrerão caso os valores obtidos sejam diferentes
> de valores booleanos e `nil`.

> [!TIP]
> `gsub` significa: _"Global SUBstituition"_.

---

### *string.len(string)
###### 8

* Comportamento: calcula o comprimento de `string`, considerando *zeros*
(`\0`, `\00`, `\000`).
* Retorno: comprimento.

---

### *string.lower(string)
###### 9

* Comportamento: converte todos os caracteres alfabéticos maiúsculos de `string` para
minúsculo.
* Retorno: uma cadeia de caracteres com as alterações.

> [!NOTE]
> A definição do que é um letra minúscula e maiúscula depende do local.

---

### *string.match(string, pattern, [number=1])
###### 10

* Comportamento: obtém a primeira ocorrência de um trecho de `string`, equivalente a
`pattern`, a partir do caractere de índice `number`.
* Retorno: o trecho ou `nil`, caso ele não seja encontrado.

---

### string.pack(format, ...)
###### 11

* Comportamento: compacta, em formato binário (especificado por `format`), o conteúdo de
`...`.
* Retorno: a cadeia de caracteres resultante em formato binário.

---

### string.packsize(format)
###### 12

* Comportamento: obtém o tamanho de um [formato](#formato-de-desempacotamento) de
compactação binária.
* Retorno: tamanho, em *bytes*.

---

### *string.rep(string0, number, [string1=""])
###### 13

* Comportamento: cria uma cadeia de caracteres resultante da concatenação de `string0`
`number` vezes consigo mesma, com cada cópia de `string0` sendo separado por `string1`.
* Retorno: a cadeia de caracteres criada.

---

### *string.reverse(string)
###### 14

* Comportamento: reverte `string`.
* Retorno: resultado.

---

### *string.sub(string, number0, [number1=-1])
###### 15

* Comportamento: obtém um trecho de `string`, partindo do caractere de índice `number0` até
`number1`.
* Retorno: trecho.

---

### string.unpack(format, string, [number=1])
###### 16

* Comportamento: descompacta os valores binários presentes em `string` (criada por
[`string.pack`](#11)), a partir da posição `number`, baseado-se em `format`.
* Retorno: os valores obtidos, mais a posição do primeiro *byte* não lido.

---

### *string.upper(string)
###### 17

* Comportamento: converte todos os caracteres alfabéticos minúsculos de `string` para
maiúsculo.
* Retorno: uma cadeia de caracteres com as alterações.

> [!NOTE]
> A definição do que é um letra minúscula e maiúscula depende do local.

---
