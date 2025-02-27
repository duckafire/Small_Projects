# Basic
Oferece duas variáveis globais e uma série de funções básicas para usos diversos e
essenciais.

---

* `_G`: Tabela global responsável por armazenar o ambiente de identificadores globais.
Lua não à utiliza diretamente. Alterar seu valor mão afeta nenhum ambiente, e vice-versa.

* `_VERSION`: Variável global que armazena o número da versão da linguagem Lua.

> [!TIP]
> Utilize `_G` para explicitar identificadores globais.
> 
> ``` lua
> _G.foo = 0
> 
> function _G.msg()
> 	print("Hello world!")
> end
> ```

---

|| Funções ||
|:-:|:-:|:-:|
|[assert](#1)        |[next](#9)     |[require](#17)     |
|[collectgarbage](#2)|[pairs](#10)   |[select](#18)      |
|[dofile](#3)        |[pcall](#11)   |[setmetatable](#19)|
|[error](#4)         |[print](#12)   |[tonumber](#20)    |
|[getmetatable](#5)  |[rawequal](#13)|[tostring](#21)    |
|[ipairs](#6)        |[rawget](#14)  |[type](#22)        |
|[load](#7)          |[rawlen](#15)  |[xpcall](#23)      |
|[loadfile](#8)      |[rawset](#16)  | |

---

### assert(boolean, [string="assertion failed!"])
###### 1

* Comportamento: interrompe o programa, e imprime `string`, caso `boolean == false`.
* Retorno: nenhum.

---

### collectgarbage([string="collect", [number=nil]])
###### 2

* Comportamento: ordenar que o coletor de lixo execute uma determinada ação.
* Retorno: os retornos variam de acordo com o valor de `string`. Ambos estão listados abaixo (alguns não têm retorno):

---

| Ação          | Descrição                                                        |
| :-:           | :--                                                              |
| `"collect"`   | Realiza um ciclo de coleta                                       |
| `"stop"`      | Interrompe a coleta automática                                   |
| `"restart"`   | Reinicia a execução do ciclo de coleta automática                |
| `"count"`     | **Retorna** a memória total em uso (em `Kbytes`)                 |
| `"isrunning"` | **Retorna** um booleano que indica se o coletor está em execução |
| `"setpause"`  | Define `arg` como novo valor para a *pausa do coletor* e **retorna** o valor anterior |
| `"step"`      | Executa uma etapa do coletor de lixo, usando `arg` para definir seu "tamanho". `==0`: etapa básica (indivisível); `>0`: o coletor tratará esse valor como se fosse uma quantidade de memória (em `Kbytes`) em uso. **Retorna** `true` se a etapa concluir um ciclo de coleta |

---

### dofile([string="stdin"])
###### 3

* Comportamento: executa o conteúdo de `string` (que deve ser o nome de um arquivo) como se
fosse parte do arquivo em questão.
* Retorno: todos os valores retornados pelo trecho.

---

### error(string, [number=1])
###### 4

* Comportamento: imprime `string` no console e especifica informações de posição de acordo com o valor de `number`.
* Retorno: nenhum.

| Valor | Descrição                                          |
| :-:   | :--                                                |
| 0     | Omite a posição (linha) do erro.                   |
| 1     | Especifica a posição do erro.                      |
| 2     | Especifica a posição da função que chamou `error`. |

---

### getmetatable(table)
###### 5

* Comportamento: verifica se o objeto possui um *metatable*.
* Retorno: o endereço da *metatable* ou `nil`, caso `table` não possua nenhum *metatable*.

> [!NOTE]
> Caso a *metatable* de `table` possua o *metamethod* `__metatable`, o valor de tal
> membro será retornado.

---

### ipairs(table)
###### 6

* Comportamento: permite acessar uma função de interação.
* Retorno: uma função de interação, `table` e `0`.

> [!IMPORTANT]
> Tal função irá percorrer todos os índices numéricos de `table` de maneira ordenada. Ela
> também retornará pares de índice e valor para cada interação realizada.

---

### load(string0, [string1="=(load)", [string2="bt", [table=_G]]])
###### 7

* Comportamento: executa o código Lua presente em `string0`.
* Retorno: uma função (contendo o conteúdo de `string0`) ou `nil`, em caso de falha.

> [!IMPORTANT]
> Os seguinte valores são suportados por `string2`.
> 
> * `"t"`: apenas formato de texto.
> * `"b"`: apenas formato binário.
> * `"bt"`: formato de texto e binário.

> [!NOTE]
> `string1` é o nome do trecho, o qual será usado em mensagens de erro.

> [!TIP]
> Se um tabela diferente de `_G` for dada à `table`, o conteúdo de `string0` perderá
> acesso à funções do *Padrão Lua*, a menos que uma referência esteja presente na tabela
> dada à `table`.
> 
> ``` lua
> -- generate an error
> local foo = {n = 0}
> 
> load("print(n)", "foo", nil, tmp)()
> ```
> 
> ``` lua
> -- not generate an error
> local foo = {n = 0, print = print}
>
> load("print(n)", "foo", nil, tmp)()
> ```

---

### loadfile([string0="stdin", [string1="t", [table=_G]]])
###### 8

* Comportamento: executa o código Lua presente em `string0`.
* Retorno: uma função (contendo o conteúdo de `string0`) ou `nil`, em caso de falha.

> Os seguinte valores são suportados por `string1`.
> 
> * `"t"`: apenas formato de texto.
> * `"b"`: apenas formato binário.
> * `"bt"`: formato de texto e binário.

---

### next(table, number)
###### 9

* Comportamento: percorre os índices de `table`.
* Retorno: `number+1` e `table[ number+1 ]` se `number~=nil` e `table[number] ~= nil`.
Ou `nil`, caso `#table==number`.

---

### pairs(table)
###### 10

* Comportamento: executa o *metamethod* `__pairs`, caso `table` o possua.
* Retorno: o valor retornado por `__pairs` ou [`next`](#9), `table` e `nil`.

---

### pcall(function_, [...])
###### 11

* Comportamento: chama `function_` em "modo protegido".
* Retorno: `true` mais os retorno de `function_` ou `false` mais uma dada mensagem de
erro, caso `function_` falhe (erro).

> [!IMPORTANT]
> Erros fatais gerados por funções protegidas não encerrarão o programa.

> [!NOTE]
> Os valores dados a `...` serão utilizados por `function_0` como argumento.

---

### print(...)
###### 12

* Comportamento: imprime todos os seus argumentos no console. Ambos são convertidos para cadeias de caracteres e separados por uma tabulação. Uma quebra de linha é posta no final.
* Retorno: nenhum.

> [!NOTE]
> Ambos os argumentos atribuídos serão convertidos para cadeias de caracteres; uma
> tabulação será utilizada para separar os elementos; uma quebra de linha será
> automaticamente posta no fim da linha.

---

### rawequal(number0, number1)
###### 13

* Comportamento: verifica se seus argumentos são iguais, sem chamar o *metamethod* `__eq`.
* Retorno: o resultado booleano da comparação.

---

### rawget(table, number)
###### 14

* Comportamento: acessa `table[number]`, sem chamar o *metamethod* `__index`.
* Retorno: o valor acessado ou `nil`, caso ele não exista.

---

### rawlen(tab_str)
###### 15

* Comportamento: retorno o comprimento de `tab_str`, sem chama o *metamethod* `__len`.
* Retorno: o comprimento de `tbl_str`.

---

### rawset(table, number0, number1)
###### 16

* Comportamento: atribui `number1` a `table[number0]`, sem chamar o *metamethod*
`__newindex`.
* Retorno: `tbl`.

---

### require(string)
###### 17

* Comportamento: executa o conteúdo de um arquivo nomeado como `string`, mas apenas caso o
mesmo já não tenha sido carregado.
* Retorno: os possíveis retornos de `string` mais `true`, mas apenas em caso de sucesso
no carregamento.

> [!IMPORTANT]
> Em `string`, os diretório devem ser separados por `.`, ao invés de `/`; a extensão `.lua`
> **não** não deve ser escrita.

---

### select(number|"#", ...)
###### 18

* Comportamento: retorna dados valores de `...` ou calcula quantos estão detidos nele,
baseado valor de seu primeiro argumento.
* Retorno: retornará todos os valores detidos em `...` a partir do índice `number`, caso
seu primeiro argumento seja um número; a quantidade de valores detidos em `...`, caso seu
primeiro argumento seja igual a `"#"`.

> [!NOTE]
> Se `number<0` a indexação ocorrerá a partir do final de `...`;

---

### setmetatable(table, metatable)
###### 19

* Comportamento: define `metatable` como sendo a *metatable* de `table`.
* Retorno: `table`.

> [!IMPORTANT]
> Se `metatable==nil` a função removerá a *metatable* atual de `table`, a menos que tal
> *metatable* possua o membro `__metatable`.

---

| Metamétodo    | Argumentos | Comportamento |
| :-:           | :-:        |:--            |
| `__index`     | index      | disparado ao tentar acessar um índice indefinido (`nil`) na tabela. Caso sele seja uma função, a mesma será chamada, caso seja uma tabela, o índice `index` dela será acessado |
| `__newindex`  | id, v      | disparado ao tentar atribuir algum valor a um índice indefinido (`nil`) na tabela. Caso ele seja uma função, a mesma será chamada, caso seja uma tabela, a atribuíção será feita nela |
| `__call`      | ...        | disparado ao tentar chamar a tabela como uma função (`table()`) |
| `__concat`    | value      | disparado ao tentar concatenar a tabela com outro valor `..`, mas apenas para o primeiro valor |
| `__unm`       | -          | disparado ao usar `-` para tornar um valor negativo (`-table`) |
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
| `__len`       | -          | disparado quando `"#"` é usado na tabela |
| `__iter`      | -          | interador personalizado para interação genérica (`for`) |

* Todos os *metamethod*s possuem, pelo menos, um parâmetro (exceto `__metatable` e `__mode`): a tabela que o recebeu.

---

> [IMPORTANT]
> #### Resumo de tabelas fracas
> 
> São aquelas cujos seus índices e/ou valores podem, eventualmente, serem deletados pelo
> coletor de lixo. Por exemplo:
>
> ``` lua
> local tbl, id = {}, nil
> 
> -- as chaves de "tbl" foram definidas como fracas
> -- opções para "__mode":
> ---- "k": índices (chaves) fracas
> ---- "v": valores fracos
> ---- "kv": índices (chaves) e valores fracos
> ---- "s": chaves de cadeias de caracteres
> setmetatable(tbl, {\_\_mode = "k"})
> 
> -- "id" recebe uma tabela e ela é usada como índice
> -- para "1" em "tbl"
> id = {}
> tbl[id] = 1
> 
> -- "id" recebe uma nova tabela, assim perdendo a
> -- tabela anterior, que era a única forma de acessar
> -- o valor "1" em "tbl", logo "1" passou a ser
> -- inacessível, assim, eventualmente, ele será
> -- removido pelo coletor de lixo e sua memória será
> -- liberada
> id = {}
> tbl[id] = 2
> 
> -- forçação da coleta de lixo, para que a memória
> -- do índice perdido seja liberada
> collectgarbage()
> ```

> [!NOTE]
> Fonte: [roblox docs (metatables)](https://create.roblox.com/docs/en-us/luau/metatables).

> [!TIP]
> Veja também: [Guia completo para iniciantes sobre *metatables*](https://devforum.roblox.com/t/full-beginner-guide-to-metatables-what-are-they-every-metamethod-explained/2505946)

---

### tonumber(number0, [number1=10])
###### 20

* Comportamento: converte `number0` para número, com base em `number1`.
* Retorno: o valor convertido, ou `nil`, caso `number0` seja inválido para a operação.

> [!TIP]
> `number1` pode ser qualquer número entre `2-36`.
> 
> Tente:
> 
> * `8` para octal.
> * `10` para decimal.
> * `16` para hexadecimal.

---

### tostring(foo)
###### 21

* Comportamento: chama o *metamethod* `__tostring` de `foor` ou converte `foo` em uma
cadeia de caracteres, caso `foo` não o possua.
* Retorno: o retorno de `__tostring` ou `foo` em formato de cadeia de caracteres.

---

### type(foo)
###### 22

* Comportamento: obtém o tipo de `foo`.
* Retorno: `"nil"`, `"number"`, `"string"`, `"boolean"`, `"table"`, `"function"`,
`"thread`" ou `"userdata"`, a depender do tipo de `foo`.

---

### xpcall(function_0, function_1, [...])
###### 23

* Comportamento: chama `function_0` em "modo protegido".
* Retorno: `true` mais os retorno de `function_0`, `false` mais os possíveis retornos de
`function_1` ou `false` mais uma dada mensagem de erro (caso `function_1` falhe).

> [!IMPORTANT]
> Erros fatais gerados por funções protegidas não encerrarão o programa.

> [!NOTE]
> Os valores dados a `...` serão utilizados por `function_0` como argumento; o possível
> error fatal de `function_0` será passado como argumento para `function_1`.

---
