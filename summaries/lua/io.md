# io

Fornece uma API para a manipulação de entradas e saídas.

<br>

> io.stdin: arquivo de entrada padrão.

> io.stdout: arquivo de saída padrão.

> io.stderr: arquivo de saída responsável por armazenar as mensagens de erro.

<br>

||Funções||
|:-:|:-:|:-:
|<a href="#1">io.close</a> |<a href="#5">io.open</a>  |<a href="#9">io.tmpfile</a>|
|<a href="#2">io.flush</a> |<a href="#6">io.output</a>|<a href="#10">io.type</a>  |
|<a href="#3">io.input</a> |<a href="#7">io.popen</a> |<a href="#11">io.write</a> |
|<a href="#4">io.lines</a> |<a href="#8">io.read</a>  ||

<br>

Além de funções, a biblioteca `io` também disponibiliza uma série de métodos, os quais pode ser usados por variáveis que armazenam arquivos abertos. Ambos estão listados abaixo:

<br>

|Métodos||
|:-:|:-:|
|<a href="#12">file:close</a>|<a href="#16">file:seek</a>   |
|<a href="#13">file:flush</a>|<a href="#17">file:setvbuf</a>|
|<a href="#14">file:lines</a>|<a href="#18">file:write</a>  |
|<a href="#15">file:read</a> ||

<br>

<br>
<hr>
<br>

<h3 id="1">io.close([string=io.stdout])</h3>

* Comportamento: fecha um arquivo.
* Retorno: nenhum.

<br>
<hr>
<br>

<h3 id="2">io.flush()</h3>

* Comportamento: salva todos os dados gravados em `io.stdout`.
* Retorno: nenhum.

<br>
<hr>
<br>

<h3 id="3">io.input([string])</h3>

* Comportamento: define `string` como o arquivo de entrada padrão.
* Retorno: caso `string` seja omitido, retornará o arquivo de entrada padrão, do contrário, não terá retorno.

<br>
<hr>
<br>

<h3 id="4">io.lines([string=io.stdout, [...="l"]])</h3>

* Comportamento: abre `string` em modo de leitura.
* Retorno: uma função interadora, que executa e retorna valores de acordo com os argumentos presentes em `...`.

<br>

| <span id="reads"><code>...</code></span> | Descrição |
|:-:|:-:|
| "n" | Lê e retorna números (podem haver espaços vazios à esquerda e um sinal) |
| "a" | Lê o arquivo inteiro, partindo da posição atual. |
| "l" | Lê a linha atual e descarta o caractere de fim da linha. |
| "L" | Lê a linha atual e mantém o caractere de fim da linha. |
|`number`| Lê um cadeia de caracteres com no máximo `number` *bytes* e a retorna. |

<br>
<hr>
<br>

<h3 id="5">io.open(string0, [string1="r"])</h3>

* Comportamento: abre `string0` em modo `string1`.
* Retorno: um "arquivo" ou, em caso de falha, `nil` e uma mensagem de erro.

<br>

| <span id="modes">Modos</span> | Descrição |
|:-:|:--|
| "r"  | leitura |
| "w"  | escrita |
| "a"  | acréscimo |
| "r+" | atualização (dados anteriores são preservados) |
| "w+" | atualização (dados anteriores são descartados) |
| "a+" | atualização de acréscimo (dados anteriores são preservadores; a gravação só pode ocorrer no final do arquivo) |

<br>
<hr>
<br>

<h3 id="6">io.output([string])</h3>

* Comportamento: define `string` como o arquivo de saída padrão.
* Retorno: O arquivo de saída padrão se `string` for omitido, caso contrário não terá retorno.

<br>
<hr>
<br>

<h3 id="7">io.popen(string0, [string1="r"])</h3>

* Comportamento: executa `string0`, que deve ser um comando do sistema operacional, e armazena sua saída em um arquivo, o qual tem seu [modo](#modes) definido por `string1`.
* Retorno: o arquivo criado.

<br>

> [!IMPORTANT]
> Alguns sistemas operacionais podem não permitir esse tipo de interação.

<br>
<hr>
<br>

<h3 id="8">io.read(...)</h3>

* Comportamento: lê o arquivo de entrada padrão, de acordo com os [modos de leitura](#reads) fornecidos por `...`.
* Retorno: uma cadeia de caracteres para cada argumento presente em `...`. Caso seja chamada sem argumentos, retornará qualquer cadeia de caracteres introduzida pela usuário.

<br>
<hr>
<br>

<h3 id="9">io.tmpfile()</h3>

* Comportamento: cria um arquivo temporário, que é descartado ao fim do programa.
* Retorno: o "arquivo", em caso de sucesso.

<br>
<hr>
<br>

<h3 id="10">io.type(variable)</h3>

* Comportamento: verifica se `variable` armazena um arquivo.
* Retorno: `"file"` caso seja um arquivo aberto, `"file closed"` caso seja um arquivo fechado ou `nil` caso não seja um arquivo.

<br>
<hr>
<br>

<h3 id="11">io.write(...)</h3>

* Comportamento: escreve `...` no arquivo de saída padrão.
* Retorno: `io.stdout` ou `nil`, em caso de falha.

<br>
<hr>
<br>

<h3 id="12">file:close()</h3>

* Comportamento: fecha `file`.
* Retorno: caso feche um arquivo retornado por [`io.popen`](#7), retornará o mesmo que `os.execute`, do contrário não terá retorno.

<br>
<hr>
<br>

<h3 id="13">file:flush()</h3>

* Comportamento: salva todos os dados gravados em `file`.
* Retorno: nenhum

<br>
<hr>
<br>

<h3 id="14">file:lines(...)</h3>

* Comportamento: abre `file` em modo de leitura.
* Retorno: uma função interadora, que executa e retorna valores de acordo com os argumentos presentes em `...` ([que pode ser...](#reads)).

<br>
<hr>
<br>

<h3 id="15">file:read([...="l"])</h3>

* Comportamento: lê `file`, de acordo com os [modos de leitura](#reads) fornecidos por `...`.
* Retorno: uma cadeia de caracteres para cada argumento presente em `...`.

<br>
<hr>
<br>

<h3 id="16">file:seek([string="cur", [number=0]]</h3>

* Comportamento: movimenta o "cursor" do arquivo em `number` *bytes* a partir de `"set"`, `"cur"` ou `"end"`.
* Retorno: a nova posição do "cursor" do arquivo ou `nil`, e uma mensagem de erro, em caso de falha.

<br>
<hr>
<br>

<h3 id="17">file:setvbuf(string, [number])</h3>

* Comportamento: define o modo de *bufferrização* de `file` em `"no"` (nenhum), `"full"` (completo) ou `"line"` (por linha).
* Retorno: nenhum.

<br>
<hr>
<br>

<h3 id="18">file:write(..)</h3>

* Comportamento: escreve `...` em `file`.
* Retorno: `file` ou `nil`, em caso de falha.

<br>
<hr>
<br>
