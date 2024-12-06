<h1 id="0">string</h1>

Fornece uma gama de funções destinadas a manipulação de cadeias de caracteres.

<br>

> [!IMPORTANT]
> Ambas as funções desta biblioteca podem ser usadas como métodos, em cadeias de caracteres, o que dispensa o fornecimento de uma cadeia de caracteres como primeiro argumento (`string.upper(STR) == STR:upper()`). Entretanto, caso o primeiro argumento esperado pela função em questão não deva ser uma cadeia de caracteres, um erro poderá ocorrer.

<br>

> [!IMPORTANT]
> Funções que solicitam índices de caracteres também aceitam valores negativos, os quais referenciam posições partidas do final da cadeia de caracteres em questão.

<br>

<h3 id="pattern-match"><em>Pattern matching</em></h3>

Este é um conjunto de caracteres especiais, semelhante ao conjunto [_regex_](https://en.wikipedia.org/wiki/Regular_expression "Wikipédia") limitado, própria da linguagem Lua. Ambos são usados em correspondências de sintaxe pela funções: [`string.find`](#4), [`string.gmatch`](#6), [`string.gsub`](#7) e [`string.match`](#10).

* Fontes:
	* [Lua manual 5.3](https://lua.org/manual/5.3/manual.html#6.4.1)
	* [Rip Tutorial](https://riptutorial.com/lua/example/20315/lua-pattern-matching)
	* [Cheatography](https://cheatography.com/ambigious/cheat-sheets/lua-string-patterns/)

| Classes de caracteres | Tipo de caractere representado |
| :-:| :-:      |
| %a | a-z; A-Z |
| %c | caracteres de controle           |
| %d | 0-9      |
| %g | caracteres imprimíveis (-espaço) |
| %l | a-z      |
| %p | caracteres de pontuação          |
| %s | espaço   |
| %u | A-Z      |
| %w | caracteres alfanuméricos         |
| %x | 0-f      |
| %z | zero     |
| .  | qualquer caractere |

| Caractere | Modificação |
| :-: | :-: |
| +   | `1=>` ocorrências |
| *   | `0=>` ocorrências |
| -   | `0>=` ocorrências |
| ?   | 0-1 ocorrência (opcional) |

| Outros   | Descrição |
| :-:      | :-: |
| _A_      | um alfnumérico específico diferente de `^$()%.[]*+-?`  |
| % _A_    | um caractere não alfanumérico (representa ele próprio) |
| %b _A Z_ | qualquer cadeia de caracteres que comece com _A_ e termine com _Z_ (ambos são QUALQUER caractere) |
| %n       | quantidade de repetições |
| [ _set _]   | conjunto de caracteres; a correspondência deve ser igual     |
| [\^ _set_ ] | conjunto de caracteres; a correspondência deve ser diferente |
| %f[ _set_ ] | uma fronteira, onde o caractere anterior a _set_ não deve pertencer a ele |

<br>

### Formato de (des)empacotamento
<h3 id="pack-format"><em>Formato de (des)empacotamento</em></h3>

As funções `string.pack`, `string.packsize` e `string.unpack` solicitam um dos seguintes formatos como primeiro argumento (os quais representam o formato de compactação binária de cada caractere da cadeia que uma (ou mais) função, dentre as citadas anteriormente, está tratando.

| Cadeias | Descrição |
| :-: | :-: |
| < | define a "ordem de _bytes_" como [_little endian_](https://en.m.wikipedia.org/wiki/Endianness) |
| > | define a "ordem de _bytes_" como [_big endian_](https://en.m.wikipedia.org/wiki/Endianness) |
| = | define a "ordem de _bytes_" como nativa da máquina cujo código está sendo executado |
| ![ _n_ ] | define o alinhamento máximo para `n` (nativo por padrão) |
| b | um `char` assinado |
| B | um `char` sem sinal |
| h | um `short` assinado (tamanho nativo) |
| H | um `short` sem sinal (tamanho nativo) |
| l | um `long` assinado (tamanho nativo) |
| L | um `long` sem sinal (tamanho nativo) |
| j | um `lua_Integer` |
| J | um `lua_Unsigned` |
| T | um `size_t` (tamanho nativo) |
| i[ _n_ ] | um `int` com `n` _bytes_ (tamanho nativo) |
| I[ _n_ ] | um `unsigned int` com `n` _bytes_ (tamanho nativo) |
| f | um `float` (tamanho nativo) |
| d | um `double` (tamanho nativo) |
| n | um `lua_Number` |
| c _n_ | uma cadeia de caracteres, de tamanho fixo, com `n` _bytes_ |
| z | uma cadeia de caracteres terminada com `\0` |
| s[ _n_ ] | uma cadeia de caracteres precedida por seu comprimento codificado como um inteiro sem sinal (`size_t` por padrão) |
| x | um _byte_ de preenchimento |
| X _op_ | um item vazio que se alinha de acordo com _op_ |
| "" | espaço vazio (ignorado) |

<br>

||Funções||
|:-:|:-:|:-:|
|<a href="#1">string.byte</a>  |<a href="#7">string.gsub</a>     |<a href="#13">string.rep</a>    |
|<a href="#2">string.char</a>  |<a href="#8">string.len</a>      |<a href="#14">string.reverse</a>|
|<a href="#3">string.dump</a>  |<a href="#9">string.lower</a>    |<a href="#15">string.sub</a>    |
|<a href="#4">string.find</a>  |<a href="#10">string.match</a>   |<a href="#16">string.unpack</a> |
|<a href="#5">string.format</a>|<a href="#11">string.pack</a>    |<a href="#17">string.upper</a>  |
|<a href="#6">string.gmatch</a>|<a href="#12">string.packsize</a>||

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="1">string.byte(string, [number0=1, [number1=number0]])</h3>

* Comportamento: obtém os códigos numéricos, de `string`, do caractere de índice `number0` até `number1`.
* Retorno: os códigos numéricos.

<br>

> [!IMPORTANT]
> Tais códigos podem não ser portáveis entre plataformas.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="2">string.char(...)</h3>

* Comportamento: converte uma série de códigos numéricos em caracteres e, em seguida, os agrupa em uma cadeia.
* Retorno: a cadeia de caracteres.

<br>

> [!IMPORTANT]
> Tais códigos podem não ser portáveis entre plataformas.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="3">string.dump(function_, [boolean=false])</h3>

* Comportamento: converte uma função em código binário. Caso `boolean==true`, a versão binária de `function_` poderá não incluir todas as informações de depuração sobre a função, como forma de economizar espaço.
* Retorno: uma cadeia de caracteres contend uma representação binária de `function_`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="4">string.find(string, substring, [number=1, [boolean=false]])</h3>

* Comportamento: procura pela primeira ocorrência de `substring` em `string`, a partir do caractere de índice `number`. `boolean==true` especifica que o <a href="#pattern-match"><em>Pattern Matching</em></a> não deve ser usado.
* Retorno: o índice da primeira e da última ocorrência ocorrência de `substring`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="5">string.format(string, ...)</h3>

* Comportamento: formata `string`, substituindo os "caracteres mágicos" dela por um argumento respectivo, presente em `...`.
* Retorno: uma cadeia de caracteres com as formatações.

<br>

> [!TIP]
>  Os "caracteres mágicos" seguem o [padrão C](https://cplusplus.com/reference/cstdio/printf/).

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="6">string.gmatch(string, pattern)</h3>

* Comportamento: obtém uma função interadora, que intera sobre os caracteres de `string`.
* Retorno: uma função interadora, que retora uma fração de `string`, equivalente ao <a href="#pattern-match"><em>Pattern Matching</em></a> fornecido em `pattern`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="7">string.gsub(string, pattern, str_tab_func, [number=nil])</h3>

* Comportamento: substitui todas (ou `number` vezes) as ocorrências de `str_tab_func` em `string`, baseado em <a href="#pattern-match"><code>pattern</code></a>.
* Retorno: uma cadeia de caracteres com os respectivos trechos substituídos.

<br>

> [!IMPORTANT]
> `str_tab_func` (como o próprio nome dá a entender), pode ser uma cadeia de caracteres, tabelas ou função, caso ele seja uma: cadeia de caracteres, ela própria irá substituir os trechos de `string`; tabela, o caractere obtido pela função interadora será usado como chave para obtém um de seus índices, caso um valor não seja encontrado (`nil`) ou seja booleano ou `nil` (explicitamente), nenhuma substituíção ocorrerá; função, o caractere obtido pela função interadora lhe será usado como argumento e seu retorno (caso diferente de booleano e `nil`) substituirá os trechos de `string`.

<br>

> [!NOTE]
> `gsub` significa: _"Global SUBstituition"_.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="8">string.len(string)</h3>

* Comportamento: calcula o comprimento de `string`, considerando _zeros_.
* Retorno: comprimento.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="9">string.lower(string)</h3>

* Comportamento: converte todos os caracteres alfabéticos maiúsculos de `string` para minúsculo.
* Retorno: uma cadeia de caracteres com as alterações.

<br>

> [!NOTE]
> A definição de o que é um letra minúscula depende do local.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="10">string.match(string, pattern, [number=1])</h3>

* Comportamento: obtém a primeira ocorrência de um trecho de `string`, equivalente a `pattern`, a partir do caractere de índice `number`.
* Retorno: o trecho ou `nil`, caso ele não seja encontrado.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="11">string.pack(format, ...)</h3>

* Comportamento: compacta, em formato binário (especificado por `format`), o conteúdo de `...`.
* Retorno: a cadeia de caracteres resultante em formato binário.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="12">string.packsize(format)</h3>

* Comportamento: obtém o tamanho de um <a href="#pattern-match">formato</a> de compactação binária de cadeias de caracteres.
* Retorno: tamanho, em _bytes_.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="13">string.rep(string0, number, [string1=""])</h3>

* Comportamento: cria uma cadeia de caracteres resultante da concatenação de `string0` `number` vezes consigo mesma, com cada cópia de `string0` sendo separado por `string1`.
* Retorno: a cadeia de caracteres criada.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="14">string.reverse(string)</h3>

* Comportamento: reverte `string`.
* Retorno: `string` invertida.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="15">string.sub(string, number0, [number1=-1])</h3>

* Comportamento: obtém um trecho de `string`, partindo do caractere de índice `number0` até `number1`.
* Retorno: trecho.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="16">string.unpack(format, string, [number=1])</h3>

* Comportamento: descompacto os valores binários presentes em `string` (criada por [`string.pack`](#11)), a partir da posição `number` e baseado em `format`.
* Retorno: os valores obtidos, mais a posição do primeiro _byte_ não lido.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="17">string.upper(string)</h3>

* Comportamento: converte todos os caracteres alfabéticos minúsculos de `string` para maiúsculo.
* Retorno: uma cadeia de caracteres com as alterações.

<br>

> [!NOTE]
> A definição de o que é um letra maiúscula depende do local.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>
