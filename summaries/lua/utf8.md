# utf8

Fornece suporte para a manipulação de caracteres oriundos da [(tabela) UTF-8](https://en.wikipedia.org/wiki/UTF-8 "Wikipedia").

<hr>

* utf8.charpattern: cadeia de caracteres que armazena o padrão referente a uma sequência de caracteres nativos da (tabela) UTF-8, especificamente `"[\0-\x7F\xC2-\xF4][\x80-\xBF]*"`.

<hr>

|Funções|
|:-:|
|<a href="#1">utf8.char</a>     |
|<a href="#2">utf8.codes</a>    |
|<a href="#3">utf8.codepoint</a>|
|<a href="#4">utf8.len</a>      |
|<a href="#5">utf8.offset</a>   |

<hr>

<h3 id="1">utf8.char(...)</h3>

* Comportamento: converte os valores (numéricos) passados para `...` em seus respectivos caracteres UTF-8.
* Retorno: uma cadeia de caracteres resultante da operação.

<hr>

<h3 id="2">utf8.codes(string)</h3>

* Comportamento: permite acessar uma função interadora.
* Retorno: uma função interadora, que intera com cada caractere de `string` e retorna ele junto ao seu código UTF-8.

<hr>

<h3 id="3">utf8.codepoint(string, [number0=1, [number1=number0]])</h3>

* Comportamento: obtém o código UTF-8 de `string`, do índice `number0` até `number1`.
* Retorno: os códigos UTF-8.

<hr>

<h3 id="4">utf8.len(string, [number0=1, [number1=number0]])</h3>

* Comportamento: calcula a quantidade de caracteres UTF-8 presente em `string`, do índice `number0` até `number1`.
* Retorno: a quantidade de caracteres UTF-8 ou, caso um caractere inválido seja encontrado, `false` e o índice desse caractere.

<hr>

<h3 id="5">utf8.offset(string, number0, [number1=1])</h3>

* Comportamento: obtém a posição, em `bytes`, do caractere de índice `number0` (a partir do índice `number1`) em `string`.
* Retorno: a posição do caractere, em `bytes`.

<br>

> [!IMPORTANT]
> Grande parte dos caracteres oriundos da (tabela) UTF-8 são compostos por mais de um `bytes`, logo, essa função pode ser de grande importância para monitorar a "posição real" de dados caracteres em uma cadeia. Por exemplo `utf8.offset("Olá!", 3)`, retorna `4`, pois `á` tem dois `bytes` de tamanho.

<br>

<hr>
