<h1 id="0">Basic</h1>

Oferece duas variáveis globais e uma série de funções báscias para usos diversos e essenciais.

<br>

> \_G: **Tabela global** que armazena o ambiente global. LUA não usa essa variável em sim. Alterar seu valor não afeta nenhum ambiente, e vice-versa.

> \_VERSION: *Variável global* que possui a versão do interpretador LUA em execução.

<br>

|| Funções ||
|:-:|:-:|:-:|
|<a href="#1">assert</a>        |<a href="#9">next</a>     |<a href="#17">require</a>
|<a href="#2">collectgarbage</a>|<a href="#10">pairs</a>   |<a href="#18">select</a>      |
|<a href="#3">dofile</a>        |<a href="#11">pcall</a>   |<a href="#19">setmetatable</a>|
|<a href="#4">error</a>         |<a href="#12">print</a>   |<a href="#20">tonumber</a>    |
|<a href="#5">getmetatable</a>  |<a href="#13">rawequal</a>|<a href="#21">tostring</a>    |
|<a href="#6">ipairs</a>        |<a href="#14">rawget</a>  |<a href="#22">type</a>        |
|<a href="#7">load</a>          |<a href="#15">rawlen</a>  |<a href="#23">xpcall</a>      |
|<a href="#8">loadfile</a>      |<a href="#16">rawset</a>  | |

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="1">assert(bool, [string="assertion failed!"])</h3>

* Comportamento: interrompe o programa, e imprime `string`, caso `bool == false`.
* Retorno: nenhum.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="2">collectgarbage([string="collect", [number=nil] ])</h3>

* Comportamento: ordenar que o coletor de lixo execute uma deteminada ação.
* Retorno: os retornos variam de acordo com o valor de `string`. Ambos está listados abaixo. Alguns não têm retorno.

<br>

| Ação          | Descrição                                                                             |
| :-:           | :--                                                                                   |
| `"collect"`   | Realiza um ciclo de coleta                                                            |
| `"stop"`      | Interrompe a coleta automática                                                        |
| `"restart"`   | Reinicia a execução da coleta automática                                              |
| `"count"`     | **Retorna** a memória total em uso (em `Kbytes`)                                      |
| `"isrunning"` | **Retorna** um booleano que indica se o coletor está em execução                      |
| `"setpause"`  | Define `arg` como novo valor para a _pausa do coletor_ e **retorna** o valor anterior |
| `"step"`      | Executa uma etapa do coletor de lixo, usando `arg` para definir seu "tamanho". `==0` etapa básica (indivisível); `>0` o coletor tratará esse valor como se fosse uma quantidade de memória (em `Kbytes`) em uso. **Retorna** `true` se a etapa concluir um ciclo de coleta |

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="3">dofile([string=stdin])</h3>

* Argumentos:
* Comportamento: executa o conteúdo de `string` como se fosse parte do arquivo em questão. `string` deve conter a extensão `.lua`.
* Retorno: todos os valores retornados pelo trecho.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="4">error(string, [number=1])</h3>

* Comportamento: imprime `string` no console e especifica informações de posição de acordo com o valor de `number`.
* Retorno: nenhum.

| Valor | Descrição                                          |
| :-:   | :--                                                |
| 0     | Omite a posição (linha) do erro.                   |
| 1     | Especifica a posição do erro.                      |
| 2     | Especifica a posição da função que chamou `error`. |

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="5">getmetatable(table)</h3>

* Comportamento: verifica se o objeto possui algum metamétodo.
* Retorno: caso haja um metámetodo em `table`, seu endereço, do contrário, o endereço de `table`. `nil` caso `table` não seja uma tabela. Caso `table` possua o metamétodo `__metatable`, o valor dele será retornado.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="6">ipairs(table)</h3>

* Comportamento: permite acessar uma função interadora, que retorna chave e valor.
* Retorno: uma função interadora, `table` e `0`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="7">load(string0, [string1="=(load)", [string2="bt", [table=_G] ] ])</h3>

* Comportamento: executa o código Lua presente em `string0`.
* Retorno: uma função ou `nil`, em caso de falha.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="8">loadfile([string0=stdin, [string1="t", [table=_G] ] ])</h3>

* Comportamento: executa o código Lua presente em `file`.
* Retorno: uma função ou `nil`, em caso de falha.

<br>

> Use `string1="bt"` para ler textos binários.

<br>

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="9">next(table, number)</h3>

* Comportamento: percorre os índices de `table`.
* Retorno: caso `number~=nil`, o próximo índice e seu valor, caso contrário, o primeiro índice e seu valor; caso `number==#tbl`, retornará `nil`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="10">pairs(table)</h3>

* Comportamento: executa `__pairs`, com `table` como argumento, mas apenas caso `table` o possua, do contrário, gerar apenas um retorno.
* Retorno: [`next`](#9), `table` e `nil` ou o retorno de `__pairs`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="11">pcall(function_, [argumentn=nil])</h3>

* Comportamento: chama a `function_` em "modo protegido", ou seja, caso haja algum erro em `function_` ele não parará o programa e nem será imprimido no console.
* Retorno: caso não hajam erros, retornará `true` e os possíveis retornos de `function_`, do contrário, retornará `false` e uma cadeia de caracteres contendo o erro em questão.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="12">print(...)</h3>

* Comportamento: imprime todos os seus argumentos no console. Ambos são comvertidos para cadeias de caracteres e separados por uma tabulação. Uma quebra de linha é posta no final.
* Retorno: nenhum.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="13">rawequal(number0, number1)</h3>

* Comportamento: verifica `number0` e `number1`, sem chamar o metamétodo `__eq`.
* Retorno: o resultado da comparação, em booleano.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="14">rawget(table, number)</h3>

* Comportamento: obtém o valor armazenado em `table[number]`, sem chamar o metamétodo `__index`.
* Retorno: o valor obtnumbero ou `nil`, caso ele não exista.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="15">rawlen(table|string)</h3>

* Comportamento: retorno o comprimento de `<table | string>`, sem chama o metamétodo `__leg`.
* Retorno: o comprimento de `tbl_str`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="16">rawset(table, number0, number1)</h3>

* Comportamento: atribui `number1` a `table[number0]`, sem chamar o metamétodo `__newindex`.
* Retorno: `tbl`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="17">require(string)</h3>

* Argumentos:
	* file: cadeia de caracteres; separado por `.` ao invés de `/`; sem a extensão `.lua`.
* Comportamento: carrega o conteúdo de `file` para uso no arquivo que o chamou, mas apenas caso ele não tenha sido carregado anteriormente.
* Retorno: o possível retorno de `file` ou, em caso de sucesso no carregamento, `true`.

<br>

> Em `string`, aos diretórios devem ser separados por `.`, ao invés de `/`; a extensão `.lua` não é necessária.

<br>

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="18">select(number|"#", ...)</h3>

* Comportamento: repassa os argumentos passados em `...` ou conta sua quantidade, dependendo do valor de `number`.
* Retorno: todos os argumentos (`...`) a partir da posição `number`; caso `number<0` a indexação ocorrerá a partir do final; caso `number=="#"`, retornará a quantidade de argumentos presentes em `...`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="19">setmetatable(table, metatable)</h3>

* Comportamento: atribui `metatable` a `table`. Caso `metatable==nil`, removerá o metamétodo de `table`, caso haja algum. Caso `table` tenha uma campo `__metatable`, gerará um erro.
* Retorno: `table`.

<br>

| Metamétodo    | Argumentos | Comportamento |
| :-:           | :-:        |:--            |
| `__index`     | index      | disparado ao tentar acessar um índice indefinido (`nil`) na tabela. Caso sele seja uma função, a mesma será chamada, caso seja uma tabela, o índice `index` dela será acessado |
| `__newindex`  | id, v      | disparado ao tentar atribuir algum valor a um índice indefinido (`nil`) na tabela. Caso ele seja uma função, a mesma será chamada, caso seja uma tabela, a atribuíção será feita nela |
| `__call`      | ...        | disparado ao tentar chamar a tabela como uma função (`table()`) |
| `__concat`    | value      | disparado ao tentar concatenar a tabela com outro valor `..`, mas apenas para o primeiro valor |
| `__unm`       | -          | disparado ao usar `-` para tornar um valor negativo (`-var`) |
| `__add`       | value      | disparado ao usar `+`, mas apenas para o primeiro item |
| `__sub`       | value      | disparado ao usar `-`, mas apenas para o primeiro item |
| `__mul`       | value      | disparado ao usar `*`, mas apenas para o primeiro item |
| `__div`       | value      | disparado ao usar `/`, mas apenas para o primeiro item |
| `__idiv`      | value      | disparado ao usar `//`, mas apenas para o primeiro item |
| `__mod`       | value      | disparado ao usar `%`, mas apenas para o primeiro item |
| `__pow`       | value      | disparado ao usar `^`, mas apenas para o primeiro item |
| `__tostring`  | -          | disparado quando a tabela é usada em [`tostring`](#21) |
| `__metatable` | -          | altera o retorno de [`getmetatable`](#5) |
| `__eq`        | value      | disparado ao usar `==`, mas apenas para o primeiro item |
| `__lt`        | value      | disparado ao usar `<`, mas apenas para o primeiro item |
| `__le`        | value      | disparado ao usar `<=`, mas apenas para o primeiro item |
| `__mode`      | -          | define o modo de uma [*tabela fraca*](https://www.lua.org/pil/17.html) |
| `__gc`        | -          | disparado quando a tabela é coletada como lixo |
| `__len`       | -          | disparado quando "#" é usado na tabela |
| `__iter`      | -          | interador personalizado para interação genérica (`for`) |

* Todos os metamétodos possuem, pelo menos, um parâmetro (exceto `__metatable` e `__mode`): a tabela que o recebeu.

<br>

#### Resumo de tabelas fracas
são aquelas cujos seus índices e/ou valores podem, eventualmente, serem deletados pelo coletor de lixo. Por exemplo:

``` lua
local tbl, id = {}, nil

-- as chaves de "tbl" foram definidas como fracas
-- opçõespara "__mode":
---- "k": índices (chaves) fracas
---- "v": valores fracos
---- "kv": índices (chaves) e valores fracos
---- "s": chaves de cadeias de caracteres
setmetatable(tbl, {/_/_mode = "k"})

-- "id" recebe uma tabela e ela é usada como índice
-- para "1" em "tbl"
id = {}
tbl[id] = 1

-- "id" recebe uma nova tabela, assim perdendo a
-- tabela anterior, que era a única forma de acessar
-- o valor "1" em "tbl", logo "1" passou a ser
-- inacessível, assim, eventualmente, ele será
-- removido pelo coletor de lixo e sua memória será
-- liberada
id = {}
tbl[id] = 2

-- forcação da coleta de lixo, para que a memória
-- do índice perdido seja liberada
collectgarbage()
```

<br>

> [Fonte](https://create.roblox.com/docs/en-us/luau/metatables)
> Veja também: [Guia completo para iniciantes sobre metatabelas](https://devforum.roblox.com/t/full-beginner-guide-to-metatables-what-are-they-every-metamethod-explained/2505946)

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="20">tonumber(number0, [number1=10])</h3>

* Comportamento: converte `number0` para número, caso ele seja válido, de acordo com `number1`.
* Retorno: o valor convertido, ou `nil`, caso `number0` seja inválido.

<br>

> `number1` pode ser qualquer valor entre dois e trinta e seis.

<br>

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="21">tostring(some_type)</h3>

* Comportamento: converte `some_type` em uma cadeia de caracteres. Caso `value` possua o metamétodo `__tostring`, ele será chamado com `some_type` como argumento.
* Retorno: uma cadeia de caracteres convertida ou o retorno de `__tostring`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="22">type(some_type)</h3>

* Comportamento: obtem o tipo de `some_type`.
* Retorno: `"nil"`, `"number"`, `"string"`, `"boolean"`, `"table"`, `"function"`, `"thread`" ou `"userdata"`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="23">xpcall(function_, string, [argumentn=nil])</h3>

* Comportamento: chama a `function_` em "modo protegido". Caso ocorra algum stringo, `err` é chamada, com o erro como argumento.
* Retorno: caso não hajam stringos, `true` e os possíveis retornos de `function_`, do contrário, `false` e os possíveis retornos de `err`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>
