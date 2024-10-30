<h1 id="0">Basic</h1>

Oferece duas variáveis globais e uma série de funções báscias para usos diversos e essenciais.

<br>

> _G: **Tabela global** que armazena o ambiente global. LUA não usa essa variável em sim. Alterar seu valor não afeta nenhum ambiente, e vice-versa.

> _VERSION: **Variável global** que possui a versão do interpretador LUA em execução.

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

<h3 id="1">assert(cond, [msg="assertion failed!"])</h3>

* Argumentos:
	* cond: booleano.
	* msg: cadeia de caracteres.
* Comportamento: interrompe o programa, e imprime `msg`, caso `exp == false`.
* Retorno: nenhum.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="2">collectgarbage([action="collect", [arg=nil] ])</h3>

* Argumentos:
	* action: cadeia de caracteres; listada abaixo.
	* arg: número; usado apenas por: `"setpause"` e `"step"`.
* Comportamento: ordenar que o coletor de lixo execute uma deteminada ação.
* Retorno: os retornos variam de acordo com o valor de `action`. Ambos está listados abaixo. Alguns não têm retorno.

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

<h3 id="3">dofile([file=stdin])</h3>

* Argumentos:
	* file: cadeia de caracteres; apenas arquivos `.lua`.
* Comportamento: executa o conteúdo de `file` como se fosse parte do arquivo em questão.
* Retorno: todos os valores retornados pelo trecho.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="4">error(msg, [level=1])</h3>

* Argumentos:
	* msg: cadeia de caracteres.
	* level: número; listado abaixo.
* Comportamento: imprime `msg` no console e especifica informações de posição de acordo com o valor de `level`.
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

<h3 id="5">getmetatable(tbl)</h3>

* Argumentos:
	* tbl: tabela.
* Comportamento: verifica se o objeto possui algum metamétodo.
* Retorno: caso haja um metámetodo em `tbl`, seu endereço, do contrário, o endereço de `tbl`. `nil` caso `tbl` não seja uma tabela. Caso `tbl` possua o metamétodo `__metatable`, o valor dele será retornado.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="6">ipairs(tbl)</h3>

* Argumentos:
	* tbl: tabela.
* Comportamento: intera, em pares (índice e valor), `tbl` até o primeiro índice ausente (`==nil`).
* Retorno: uma função interadora, `tbl` e `0`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="7">load(chunk, [chuckname="=(load)", [mode="bt", [env=_G] ] ])</h3>

* Argumentos:
	* chunk: cadeira de caracteres ou função.
	* chunkname: cadeia de caracteres; usada para se referir ao conteúdo de `chunk` em mensagens de erro e informações de depuração.
	* mode: cadeia de caracteres; `"t"` texto; `"bt"` texto e binários.
	* env: tabela; ambiente customizado.
* Comportamento: executa o código Lua presente em `chuck`.
* Retorno: uma função ou `nil`, em caso de falha.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="8">loadfile([file=stdin, [mode="t", [env=_G] ] ])</h3>

* Argumentos:
	* chunk: cadeira de caracteres; nome de um arquivo Lua.
	* mode: cadeia de caracteres; `"t"` texto; `"bt"` texto e binários.
	* env: tabela; ambiente customizado.
* Comportamento: executa o código Lua presente em `file`.
* Retorno: uma função ou `nil`, em caso de falha.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="9">next(tbl, id)</h3>

* Argumentos:
	* tbl: tabela.
	* id: número.
* Comportamento: percorre os índices de `tbl`.
* Retorno: caso `id~=nil`, o próximo índice e seu valor, caso contrário, o primeiro índice e seu valor; caso `id==#tbl`, retornará `nil`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="10">pairs(tbl)</h3>

* Argumentos:
	* tbl: tabela.
* Comportamento: executa `__pairs`, com `tbl` como argumento, mas apenas caso `tbl` o possua, do contrário, gerar apenas um retorno.
* Retorno: [`next`](#9), `tbl` e `nil` ou o retorno de `__pairs`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="11">pcall(func, [arg=nil])</h3>

* Argumentos:
	* func: função.
	* arg: qualquer.
* Comportamento: chama a `func` em "modo protegido", ou seja, caso haja algum erro em `func` ele não parará o programa e nem será imprimido no console.
* Retorno: caso não hajam erros, retornará `true` e os possíveis retornos de `func`, do contrário, retornará `false` e uma cadeia de caracteres contendo o erro em questão.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="12">print(...)</h3>

* Argumentos:
	* (...): qualquer.
* Comportamento: imprime todos os seus argumentos no console. Ambos são comvertidos para cadeias de caracteres e separados por uma tabulação. Uma quebra de linha é posta no final.
* Retorno: nenhum.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="13">rawequal(v1, v2)</h3>

* Argumentos:
	* v1: número.
	* v2: número.
* Comportamento: verifica `v1` e `v2`, sem chamar o metamétodo `__eq`.
* Retorno: o resultado da comparação, em booleano.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="14">rawget(tbl, id)</h3>

* Argumentos:
	* tbl: tabela.
	* id: número.
* Comportamento: obtém o valor armazenado em `tbl[id]`, sem chamar o metamétodo `__index`.
* Retorno: o valor obtido ou `nil`, caso ele não exista.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="15">rawlen(tbl_str)</h3>

* Argumentos:
	* tbl\_str: tabela ou cadeia de caracteres.
* Comportamento: retorno o comprimento de `tbl_str`, sem chama o metamétodo `__leg`.
* Retorno: o comprimento de `tbl_str`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="16">rawset(tbl, id, newValue)</h3>

* Argumentos:
	* tbl: tabela.
	* id: número.
	* newValue: um novo valor para `tbl[id]`.
* Comportamento: atribui `newValue` a `tbl[id]`, sem chamar o metamétodo `__newindex`.
* Retorno: `tbl`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="17">require(file)</h3>

* Argumentos:
	* file: cadeia de caracteres; separado por `.` ao invés de `/`; sem a extensão `.lua`.
* Comportamento: carrega o conteúdo de `file` para uso no arquivo que o chamou, mas apenas caso ele não tenha sido carregado anteriormente.
* Retorno: o possível retorno de `file` ou, em caso de sucesso no carregamento, `true`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="18">select(id, ...)</h3>

* Argumentos:
	* id: número ou `"#"`.
	* (...): qualquer.
* Comportamento: baseada em retorno.
* Retorno: todos os argumentos (`...`) a partir da posição `id`; caso `id<0` a indexação ocorrerá a partir do final; caso `id=="#"`, retornará a quantidade de argumentos presentes em `...`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="19">setmetatable(tbl, mtbl)</h3>

* Argumentos:
	* tbl: tabela.
	* mtbl: metatabela (uma tabela com um metamétodo).
* Comportamento: atribui `mtbl` a `tbl`. Caso `mtbl==nil`, removerá o metamétodo de `tbl`, caso haja algum. Caso `tbl` tenha uma campo `__metatable`, gerará um erro.
* Retorno: `tbl`.

<br>

| Metamétodo    | Argumentos | Comportamento |
| :-:           | :-:        |:--            |
| `__index`     | index      | disparado ao tentar acessar um índice indefinido (`nil`) na tabela. Caso sele seja uma função, a mesma será chamada, caso seja uma tabela, o índice `index` dela será acessado |
| `__newindex`  | id, v      | disparado ao tentar atribuir algum valor a um índice indefinido (`nil`) na tabela. Caso ele seja uma função, a mesma será chamada, caso seja uma tabela, a atribuíção será feita nela |
| `__call`      | ...        | disparado ao tentar chamar a tabela como uma função (`tbl()`) |
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
setmetatable(tbl, {__mode = "k"})

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

* [Fonte](https://create.roblox.com/docs/en-us/luau/metatables)
* Veja também: [Guia completo para iniciantes sobre metatabelas](https://devforum.roblox.com/t/full-beginner-guide-to-metatables-what-are-they-every-metamethod-explained/2505946)

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="20">tonumber(value, [base=10])</h3>

* Argumentos:
	* value: cadeia de caracteres.
	* base: número; qualquer valor entre 2-36.
* Comportamento: converte `value` para número, caso ele seja válido, de acordo com `base`.
* Retorno: o valor convertido, ou `nil`, caso `value` seja inválido.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="21">tostring(value)</h3>

* Argumentos:
	* value: número.
* Comportamento: converte `value` em uma cadeia de caracteres. Caso `value` possua o metamétodo `__tostring`, ele será chamado com `value` como argumento.
* Retorno: uma cadeia de caracteres convertida ou o retorno de `__tostring`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="22">type(item)</h3>

* Argumentos:
	* item: qualquer.
* Comportamento: obtem o tipo de `value`.
* Retorno: `"nil"`, `"number"`, `"string"`, `"boolean"`, `"table"`, `"function"`, `"thread`" ou `"userdata"`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>

<h3 id="23">xpcall(func, err, [arg=nil])</h3>

* Argumentos:
	* func: função.
	* arg: qualquer.
* Comportamento: chama a `func` em "modo protegido", ou seja, caso haja algum erro em `func` ele não parará o programa e nem será imprimido no console.
* Retorno: caso não hajam erros, retornará `true` e os possíveis retornos de `func`, do contrário, retornará `false` e uma cadeia de caracteres contendo o erro em questão.

* Argumentos:
	* func: função.
	* err: função;
	* arg: qualquer.
* Comportamento: chama a `func` em "modo protegido". Caso ocorra algum erro, `err` é chamada, com o erro como argumento.
* Retorno: caso não hajam erros, `true` e os possíveis retornos de `func`, do contrário, `false` e os possíveis retornos de `err`.

<br>
<hr>
<ul><li><a href="#0">Voltar ao topo</a></li></ul>
<hr>
<br>
