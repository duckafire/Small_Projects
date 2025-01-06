# math

Biblioteca matemática contendo funções capazes de realizar operações simples com números.

<hr>

* math.huge: infinito.
* math.maxinteger: maior número inteiro armazenável.
* math.mininteger: menor número inteiro armazenável.
* math.pi: valor de [*pi*](https://en.wikipedia.org/wiki/Pi "Wikipédia").

<br>

> [!NOTE]
> Fonte extra: [Tutorials Point](https://www.tutorialspoint.com/lua/lua_math_library.htm)

<br>

> [!NOTE]
> `number` foi abreviado para `n`.

<br>

<hr>

||Funções||
|:-:|:-:|:-:|
|<a href="#1">math.abs</a>   |<a href="#12">math.fmod</a>  |<a href="#23">math.randomseed</a>|
|<a href="#2">math.acos</a>  |<a href="#13">math.frexp</a> |<a href="#24">math.sin</a>       |
|<a href="#3">math.asin</a>  |<a href="#14">math.ldexp</a> |<a href="#25">math.sinh</a>      |
|<a href="#4">math.atan</a>  |<a href="#15">math.log</a>   |<a href="#26">math.sqrt</a>      |
|<a href="#5">math.atan2</a> |<a href="#16">math.log10</a> |<a href="#27">math.tan</a>       |
|<a href="#6">math.ceil</a>  |<a href="#17">math.max</a>   |<a href="#28">math.tanh</a>      |
|<a href="#7">math.cos</a>   |<a href="#18">math.min</a>   |<a href="#29">math.tointeger</a> |
|<a href="#8">math.cosh</a>  |<a href="#19">math.modf</a>  |<a href="#30">math.type</a>      |
|<a href="#9">math.deg</a>   |<a href="#20">math.pow</a>   |<a href="#31">math.ult</a>       |
|<a href="#10">math.exp</a>  |<a href="#21">math.rad</a>   ||
|<a href="#11">math.floor</a>|<a href="#22">math.random</a>||

<hr>

<h3 id="1">math.abs(n)</h3>

* Comportamento: converte `n` para seu valor absoluto.
* Retorno: resultado da conversão.

<br>

> [!NOTE]
> O valor absoluto de `-1` é `1` e o valor obsoluto de `1` é `1`.

<br>

<hr>

<h3 id="2">math.acos(n)</h3>

* Comportamento: calcula o [arco cosseno](https://en.wikipedia.org/wiki/Inverse_trigonometric_functions "Wikipédia") de `n`.
* Retorno: resultado em radianos.

<hr>

<h3 id="3">math.asin(n)</h3>

* Comportamento: calcula o [arco seno](https://en.wikipedia.org/wiki/Inverse_trigonometric_functions "Wikipédia") de `n`.
* Retorno: resultado em radianos.

<hr>

<h3 id="4">math.atan(n)</h3>

* Comportamento: calcula a [arco tangente](https://en.wikipedia.org/wiki/Inverse_trigonometric_functions "Wikipédia") de `n`.
* Retorno: resultado em radianos.

<hr>

<h3 id="5">math.atan2(y, [x=1])</h3>

* Comportamento: calcula a [arco tangente](https://en.wikipedia.org/wiki/Inverse_trigonometric_functions "Wikipédia") de `y` e `x`, usando seus sinais para encontrar o quadrante do resultado.
* Retorno: resultado em radianos.

<hr>

<h3 id="6">math.ceil(n)</h3>

* Comportamento: converte `n` em um valor inteiro.
* Retorno: menor inteiro maior ou igual a `n`.

<hr>

<h3 id="7">math.cos(n)</h3>

* Comportamento: calcula o [cosseno](https://en.wikipedia.org/wiki/Trigonometric_functions "Wikipédia") de `n`.
* Retorno: resultado em radianos.

<hr>

<h3 id="8">math.cosh(n)</h3>

* Comportamento: calcula o [cosseno hiperbólico](https://en.wikipedia.org/wiki/Hyperbolic_functions "Wikipédia") de `n`.
* Retorno: resultado em radianos.

<hr>

<h3 id="9">math.deg(n)</h3>

* Comportamento: converte radianos para graus.
* Retorno: resultado.

<hr>

<h3 id="10">math.exp(n)</h3>

* Comportamento: calcula o [exponencial](https://en.wikipedia.org/wiki/Exponential_function "Wikipédia") de `n` (`~2.71 ^ n`).
* Retorno: resultado.

<hr>

<h3 id="11">math.floor()</h3>

* Comportamento: converte `n` em um valor inteiro.
* Retorno: maior inteiro menor ou igual a `n`.

<hr>

<h3 id="12">math.fmod(n0, n1)</h3>

* Comportamento: calcula o resto de `n0 / n1`.
* Retorno: resultado (o sinal do valor retornado é igual ao sinal de `n0`).

<hr>

<h3 id="13">math.frexp(n)</h3>

* Comportamento: obtém a [*mantissa*](https://en.wikipedia.org/wiki/Significand "Wikipédia") e o *expoente* de um número de ponto flutuante (`n`).
* Retorno: um intervalo de `0.5` a `1.0` (`-1.0` a `-0.5` para valores negativos) e o expoente de `n`.

<br>

> [!NOTE]
> A *mantissa* multiplicada por `2` elevado ao *expoente* é igual a `n` (`math.frexp(8.0) >> 0.5, 4 >> 0.5 * 2 ^ 4 = 8.0`).

<br>

<hr>

<h3 id="14">math.ldexp(n0, n1)</h3>

* Comportamento: converte um valor de ponto flutuante em formato de [*mantissa*](https://en.wikipedia.org/wiki/Significand "Wikipédia") (`n0`) e *expoente* (`n1`).
* Retorno: valor numérico de ponto flutuante.

<br>

> [!TIP]
> Veja também: <a href="#13">math.frexp</a>

<br>

<hr>

<h3 id="15">math.log(n)</h3>

* Comportamento: calcula o [logaritmo natual](https://en.wikipedia.org/wiki/Natural_logarithm "Wikipédia") de `n`.
* Retorno: resultado.

<hr>

<h3 id="16">math.log10(n)</h3>

* Comportamento: calcula o [logaritmo](https://en.wikipedia.org/wiki/Logarithm "Wikipédia") de `n` na base `10`.
* Retorno: resultado.

<hr>

<h3 id="17">math.max(n, [...])</h3>

* Comportamento: obtém o maior valor dentre os argumentos.
* Retorno: valor obtido.

<hr>

<h3 id="18">math.min(n, [...])</h3>

* Comportamento: obtém o menor valor dentre os argumentos.
* Retorno: valor obtido.

<hr>

<h3 id="19">math.modf(n)</h3>

* Comportamento: separa `n` em antes e depois da vírgula.
* Retorno: a parte inteira e a parte fracionária de `n`.

<hr>

<h3 id="20">math.pow(n0, n1)</h3>

* Comportamento: realiza uma exponenciação (`n0 ^ n1`).
* Retorno: resultado.

<hr>

<h3 id="21">math.rad(n)</h3>

* Comportamento: converte graus para radianos.
* Retorno: resultado.

<hr>

<h3 id="22">math.random([n0, [n1]])</h3>

* Comportamento: gera um inteiro pseudo-aleatório.
* Retorno: um valor entre `0.0` e `1.0` (caso chamada sem argumentos), um valor entre de `1` até `n0` (caso `n1` seja omitido) ou um valor de `n0` até `n1` (caso ambos sejam especificados).

<br>

> [!NOTE]
> Números de ponto flutuante não são aceitos como argumentos.

<br>

> [!NOTE]
> `n1` não pode ser menor que `n0`.

<br>

<hr>

<h3 id="23">math.randomseed(n)</h3>

* Comportamento: define `n` como sendo a *semente* do gerador de números pseudo-aleatórios.
* Retorno: nenhum.

<hr>

<h3 id="24">math.sin(n)</h3>

* Comportamento: calcula o [seno](https://en.wikipedia.org/wiki/Trigonometric_functions "Wikipédia") de `n`.
* Retorno: resultado em radianos.

<hr>

<h3 id="25">math.sinh(n)</h3>

* Comportamento: calcula o [seno hiperbólico](https://en.wikipedia.org/wiki/Hyperbolic_functions "Wikipédia") de `n`.
* Retorno: resultado em radianos.

<hr>

<h3 id="26">math.sqrt(n)</h3>

* Comportamento: calcula a raiz quadrada de `n` (equivalente a `n ^ 0.5`).
* Retorno: resultado.

<hr>

<h3 id="27">math.tan(n)</h3>

* Comportamento: calcula a [tangente](https://en.wikipedia.org/wiki/Trigonometric_functions "Wikipédia") de `n`.
* Retorno: resultado em radianos.

<hr>

<h3 id="28">math.tanh(n)</h3>

* Comportamento: calcula a [tangente hiperbólica](https://en.wikipedia.org/wiki/Hyperbolic_functions "Wikipédia") de `n`.
* Retorno: resultado em radianos.

<hr>

<h3 id="29">math.tointeger(n)</h3>

* Comportamento: converte `n` em um valor inteiro.
* Retorno: caso `n` não seja um valor inteiro (ou uma cadeia de caracteres válida), retornará `nil`, do contrário, retornará o valor convertido.

<hr>

<h3 id="30">math.type(n)</h3>

* Comportamento: obtém o tipo de `n`.
* Retorno: `"integer"`, `"float"` ou `nil`.

<hr>

<h3 id="31">math.ult(n0, n1)</h3>

* Comportamento: compara `n0` com o valor absoluto de `n1`.
* Retorno: `true`, caso `n0` seja menor que o valor absoluto de `n1`, do contrário, `false`.

<hr>
