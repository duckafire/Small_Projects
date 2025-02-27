# utf8
Fornece suporte para a manipulação de caracteres oriundos da
[(tabela) UTF-8](https://en.wikipedia.org/wiki/UTF-8 "Wikipedia").

---

* `utf8.charpattern`: cadeia de caracteres que armazena o padrão referente a uma sequência
de caracteres nativos da (tabela) UTF-8, especificamente
`"[\0-\x7F\xC2-\xF4][\x80-\xBF]*"`.

---

|Funções|
|:-:|
|[utf8.char](#1)     |
|[utf8.codes](#2)    |
|[utf8.codepoint](#3)|
|[utf8.len](#4)      |
|[utf8.offset](#5)   |

---

### utf8.char(...)
###### 1

* Comportamento: converte os valores (numéricos) passados para `...` em seus respectivos
caracteres UTF-8.
* Retorno: uma cadeia de caracteres resultante da operação.

---

### utf8.codes(string)
###### 2

* Comportamento: permite acessar uma função de interação.
* Retorno: uma função de interação, que interage com cada caractere de `string`.

> [!NOTE]
> A função retornada retornará em pares: a representação gráfica do caractere mais seu
> código UTF-8.

---

### utf8.codepoint(string, [number0=1, [number1=number0]])
###### 3

* Comportamento: obtém o código UTF-8 de `string`, do índice `number0` até `number1`.
* Retorno: os códigos UTF-8.

---

### utf8.len(string, [number0=1, [number1=number0]])
###### 4

* Comportamento: calcula a quantidade de caracteres UTF-8 presente em `string`, do índice
`number0` até `number1`.
* Retorno: a quantidade de caracteres UTF-8 ou, caso um caractere inválido seja encontrado,
`false` e o índice desse caractere.

---

### utf8.offset(string, number0, [number1=1])
###### 5

* Comportamento: obtém a posição, em *bytes*, do caractere de índice `number0` (a partir do
índice `number1`) em `string`.
* Retorno: a posição do caractere, em *bytes*.

> [!IMPORTANT]
> Grande parte dos caracteres oriundos da (tabela) UTF-8 são compostos por mais de um
> `bytes`, logo, essa função pode ser de grande importância para monitorar a "posição real"
> de dados caracteres em uma cadeia. Por exemplo `utf8.offset("Olá!", 3)`, retorna `4`,
> pois `á` tem dois `bytes` de tamanho.

---
