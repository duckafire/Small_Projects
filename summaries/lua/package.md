# Package
Conjunto de majoritária de variáveis, utilizadas por [`require`](https://github.com/duckafire/Small_Projects/blob/main/summaries/lua/basic.md#17) para carregar "módulos".

<hr>

* `package.config`: armazena uma série de caracteres usados em algumas configurações, os quais são separados por ponto e vírgula. Ambos encontram-se abaixo:
	* separador de directórios: `/` (`\` no *Windows*).
	* separador de templates (em um caminho): `;`.
	* pontos de substituição em um template: `?`.
	* caractere: `!` (no *Windows*, ele é substituído pelo caminho do executável).
	* caractere usado para interromper a leitura desta cadeia: `-` (por padrão).
* `package.cpath`: cadeia de caracteres, que armazena o caminho usado por [`require`](https://github.com/duckafire/Small_Projects/blob/main/summaries/lua/basic.md#17) para localizar um carregador C.
* `package.loaded`: tabela usada por [`require`](https://github.com/duckafire/Small_Projects/blob/main/summaries/lua/basic.md#17) para controlar quais módulos foram carregados. Está é apenas uma referência, logo, sua manipulação não gera efeitos na tabela real.
* package.path: cadeia de caracteres, que armazena o caminho usado por [`require`](https://github.com/duckafire/Small_Projects/blob/main/summaries/lua/basic.md#17) para localizar um carregador Lua.
* `package.preload`: tabela responsável por armazenar carregadores para módulos específicos. Está é apenas uma referência, logo, sua manipulação não gera efeitos na tabela real.
* `package.searchers`: tabela usada por [`require`](https://github.com/duckafire/Small_Projects/blob/main/summaries/lua/basic.md#17) para controlar como carregar módulos. Seus valores são funções buscadores que são chamadas em ordem crescente por [`require`](https://github.com/duckafire/Small_Projects/blob/main/summaries/lua/basic.md#17), usando o argumento passado para ele nelas.

<hr>

|Funções|
|:-:|
|<a href="#1">package.loadlib</a>|
|<a href="#2">package.searchpath</a>|

<hr>

<h3 id="1">package.loadlib(string0, string1)</h3>

* Comportamento: carrega uma biblioteca dinamica (`libfoo.so`) e extraí uma função da mesma, onde `string0` é o caminho para a biblioteca e `string1` é a função que será obtida.
* Retorno: a função `string1` em caso de sucesso, do contrário retornará `nil` e uma mensagem de erro

<br>

> [!IMPORTANT]
> Essa função não é suportada pelo *Padrão C* e seu uso depende do sistema operacional em questão, sendo suportada apenas no: Windows, Mac, Linux, OS X, Solaris, BDS e outros Unix que surpotam `dlfcn` padrão.

<br>

<hr>

<h3 id="2">package.searchpath(string0, string1, [string2=".", [string3=IN!NOTE]])</h3>

* Comportamento: procura pela biblioteca `string0`, em todos os caminhos fornecidos por `string1`.
* Retorno: o caminho para `string0`.

<br>

> [!IMPORTANT]
> Ao atribuir diferentes caminhos a `string1`, se torna necessário utilizar `;` para separá-los (`"./a/foo.so;./b/foo.so"`); 

<br>

> [!NOTE]
> `string3` (por padrão) é igual ao separador de diretórios padrão do sistema.

<br>

> [!NOTE]
> Todas as ocorrências de `string2` são substituídas por `string3`.

<br>

> [!TIP]
> Caso o caractere `?` seja encontrado em `string1`, ele será substituído por `string0`. Por exemplo (dado que `string0="foo"`): `"./c/d/?.so;./?.so"` -> `"./c/d/foo.so;./foo.so"`.

<br>

<hr>
