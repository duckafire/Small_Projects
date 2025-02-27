[req]: https://github.com/duckafire/Small_Projects/blob/main/summaries/lua/basic.md#17

# Package
Conjunto majoritário de variáveis, utilizadas por [`require`](req) para carregar "módulos".

---

* `package.config`: armazena uma série de caracteres usados em algumas configurações, os
quais são separados por ponto e vírgula. Ambos encontram-se abaixo:
	* separador de diretórios: `/` (`\` no *Windows*).
	* separador de *templates* (em um caminho): `;`.
	* pontos de substituição em um *template*: `?`.
	* caractere: `!` (no *Windows*, ele é substituído pelo caminho do executável).
	* caractere usado para interromper a leitura desta cadeia: `-` (por padrão).

* `package.cpath`: cadeia de caracteres, que armazena o caminho usado por [`require`][req]
para localizar um carregador C.

* `package.loaded`: tabela usada por [`require`][req] para controlar quais módulos foram
carregados. Está é apenas uma referência, logo, sua manipulação não gera efeitos na tabela
real.

* `package.path`: cadeia de caracteres, que armazena o caminho usado por [`require`][req]
para localizar um carregador Lua.

* `package.preload`: tabela responsável por armazenar carregadores para módulos
específicos. Está é apenas uma referência, logo, sua manipulação não gera efeitos na tabela
real.

* `package.searchers`: tabela usada por [`require`][req] para controlar como carregar
módulos. Seus valores são funções buscadoras que são chamadas em ordem crescente por
[`require`][req], usando o argumento passado para ele nelas.

---

|Funções                 |
|:-:                     |
|[package.loadlib](#1)   |
|[package.searchpath](#2)|

---

### package.loadlib(string0, string1)
###### 1

* Comportamento: carrega uma biblioteca dinâmica (`libfoo.so`) e extraí uma função da
mesma, onde `string0` é o caminho para a biblioteca e `string1` é a função que será obtida.
* Retorno: a função `string1` em caso de sucesso, do contrário retornará `nil` e uma
mensagem de erro

> [!IMPORTANT]
> Essa função não é suportada pelo *Padrão C* e seu uso depende do sistema operacional em
> questão, sendo suportada apenas no: Windows, Mac, Linux, OS X, Solaris, BDS e outros Unix
> que suportam `dlfcn` padrão.

---

### package.searchpath(string0, string1, [string2=".", [string3=IN!NOTE]])
###### 2

* Comportamento: procura pela biblioteca `string0`, em todos os caminhos fornecidos à
`string1`.
* Retorno: o caminho para `string0`.

> [!IMPORTANT]
> Ao atribuir diferentes caminhos a `string1`, se torna necessário utilizar `;` para
> separá-los (`"./a/foo.so;./b/foo.so"`); 

> [!NOTE]
> `string3` (por padrão) é igual ao separador de diretórios padrão do sistema; todas as
> ocorrências de `string2` são substituídas por `string3`.

> [!TIP]
> Caso o caractere `?` seja encontrado em `string1`, ele será substituído por `string0`.
> Por exemplo (dado que `string0="foo"`):
> `"./c/d/?.so;./?.so"` -> `"./c/d/foo.so;.foo.so"`.

---
