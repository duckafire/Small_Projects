# math
Biblioteca matemática contendo funções capazes de realizar operações simples com números.

---

* `math.huge`: representação do infinito.
* `math.maxinteger`: maior número inteiro armazenável.
* `math.mininteger`: menor número inteiro armazenável.
* `math.pi`: valor de aproximado de [*pi*](https://en.wikipedia.org/wiki/Pi "Wikipédia").

> [!NOTE]
> Fonte extra: [Tutorials Point](https://www.tutorialspoint.com/lua/lua_math_library.htm)

> [!NOTE]
> `number` foi abreviado para `n`.

[acos]: https://en.wikipedia.org/wiki/Inverse_trigonometric_functions "Wikipédia"
[asin]: https://en.wikipedia.org/wiki/Inverse_trigonometric_functions "Wikipédia"
[atan]: https://en.wikipedia.org/wiki/Inverse_trigonometric_functions "Wikipédia"
[cos]: https://en.wikipedia.org/wiki/Trigonometric_functions "Wikipédia"
[cosh]: https://en.wikipedia.org/wiki/Hyperbolic_functions "Wikipédia"
[expon]: https://en.wikipedia.org/wiki/Exponential_function "Wikipédia"
[mant]: https://en.wikipedia.org/wiki/Significand "Wikipédia"
[logn]: https://en.wikipedia.org/wiki/Natural_logarithm "Wikipédia"
[log]: https://en.wikipedia.org/wiki/Logarithm "Wikipédia
[sin]: https://en.wikipedia.org/wiki/Trigonometric_functions "Wikipédia"
[sinh]: https://en.wikipedia.org/wiki/Hyperbolic_functions "Wikipédia"
[tan]: https://en.wikipedia.org/wiki/Trigonometric_functions "Wikipédia"
[tanh]: https://en.wikipedia.org/wiki/Hyperbolic_functions "Wikipédia"

---

||Funções||
|:-:|:-:|:-:|
|[math.abs](#1)   |[math.fmod](#12)  |[math.randomseed](#23)|
|[math.acos](#2)  |[math.frexp](#13) |[math.sin](#24)       |
|[math.asin](#3)  |[math.ldexp](#14) |[math.sinh](#25)      |
|[math.atan](#4)  |[math.log](#15)   |[math.sqrt](#26)      |
|[math.atan2](#5) |[math.log10](#16) |[math.tan](#27)       |
|[math.ceil](#6)  |[math.max](#17)   |[math.tanh](#28)      |
|[math.cos](#7)   |[math.min](#18)   |[math.tointeger](#29) |
|[math.cosh](#8)  |[math.modf](#19)  |[math.type](#30)      |
|[math.deg](#9)   |[math.pow](#20)   |[math.ult](#31)       |
|[math.exp](#10)  |[math.rad](#21)   ||
|[math.floor](#11)|[math.random](#22)||

---

### math.abs(n)
###### 1

* Comportamento: converte `n` para seu valor absoluto.
* Retorno: resultado da conversão.

> [!NOTE]
> O valor absoluto de `-1` é `1`, já o valor absoluto de `1` é `1`.

---

### math.acos(n)
###### 2

* Comportamento: calcula o [arco cosseno][acos] de `n`.
* Retorno: resultado em radianos.

---

### math.asin(n)
###### 3

* Comportamento: calcula o [arco seno][asin] de `n`.
* Retorno: resultado em radianos.

---

### math.atan(n)
###### 4

* Comportamento: calcula a [arco tangente][atan] de `n`.
* Retorno: resultado em radianos.

---

### math.atan2(y, [x=1])
###### 5

* Comportamento: calcula a [arco tangente][atan] de `y` e `x`, usando seus sinais para
encontrar o quadrante do resultado.
* Retorno: resultado em radianos.

---

### math.ceil(n)
###### 6

* Comportamento: converte `n` em um valor inteiro.
* Retorno: menor inteiro maior ou igual a `n`.

> [!TIP]
> `math.ceil(1.5)` retorna `2`, pois ele é o menor valor interior dentre aqueles maiores
> que `1.5`.

---

### math.cos(n)
###### 7

* Comportamento: calcula o [cos][cos] de `n`.
* Retorno: resultado em radianos.

---

### math.cosh(n)
###### 8

* Comportamento: calcula o [cosseno hiperbólico][cosh] de `n`.
* Retorno: resultado em radianos.

---

### math.deg(n)
###### 9

* Comportamento: converte radianos para graus.
* Retorno: resultado.

---

### math.exp(n)
###### 10

* Comportamento: calcula o [expon][expon] de `n` (`~2.71 ^ n`).
* Retorno: resultado.

---

### math.floor()
###### 11

* Comportamento: converte `n` em um valor inteiro.
* Retorno: maior inteiro menor ou igual a `n`.
* 
> [!TIP]
> `math.floor(1.5)` retorna `1`, pois ele é o maior valor interior dentre aqueles menores
> que `1.5`.

---

### math.fmod(n0, n1)
###### 12

* Comportamento: calcula o resto de `n0 / n1`.
* Retorno: resultado (o sinal do valor retornado é igual ao sinal de `n0`).

---

### math.frexp(n)
###### 13

* Comportamento: obtém a [*mantissa*][mant] e o *expoente* de um número de ponto flutuante
(`n`).
* Retorno: um intervalo de `0.5` a `1.0` (`-1.0` a `-0.5` para valores negativos) e o
expoente de `n`.

> [!NOTE]
> A *mantissa* multiplicada por `2` elevado ao *expoente* é igual a `n` (`math.frexp(8.0) >> 0.5, 4 >> 0.5 * 2 ^ 4 = 8.0`).

---

### math.ldexp(n0, n1)
###### 14

* Comportamento: converte um valor de ponto flutuante em formato de [*mantissa*][mant]
(`n0`) e *expoente* (`n1`).
* Retorno: valor numérico de ponto flutuante.

> [!TIP]
> Veja também: [math.frexp](#13)

---

### math.log(n)
###### 15

* Comportamento: calcula o [logaritmo natural][logn] de `n`.
* Retorno: resultado.

---

### math.log10(n)
###### 16

* Comportamento: calcula o [log](logaritmo") de `n` na base `10`.
* Retorno: resultado.

---

### math.max(n, [...])
###### 17

* Comportamento: obtém o maior valor dentre os argumentos.
* Retorno: o maior argumento.

---

### math.min(n, [...])
###### 18

* Comportamento: obtém o menor valor dentre os argumentos.
* Retorno: o menor argumento.

---

### math.modf(n)
###### 19

* Comportamento: separa `n` em antes e depois da vírgula.
* Retorno: a parte inteira e a parte fracionária de `n`.

---

### math.pow(n0, n1)
###### 20

* Comportamento: realiza uma exponenciação (`n0 ^ n1`).
* Retorno: resultado.

---

### math.rad(n)
###### 21

* Comportamento: converte graus para radianos.
* Retorno: resultado.

---

### math.random([n0, [n1]])
###### 22

* Comportamento: gera um inteiro pseudoaleatório.
* Retorno: um valor entre `0.0` e `1.0` (caso chamada sem argumentos); um valor de `1` até
`n0` (caso `n1` seja omitido); ou um valor de `n0` até `n1` (caso ambos sejam
especificados).

> [!NOTE]
> Números de ponto flutuante não são aceitos como argumentos; `n1` não pode ser menor que
> `n0`.

---

### math.randomseed(n)
###### 23

* Comportamento: define `n` como sendo a *semente* do gerador de números pseudoaleatórios.
* Retorno: nenhum.

---

### math.sin(n)
###### 24

* Comportamento: calcula o [sin][sin] de `n`.
* Retorno: resultado em radianos.

---

### math.sinh(n)
###### 25

* Comportamento: calcula o [seno hiperbólico][sinh] de `n`.
* Retorno: resultado em radianos.

---

### math.sqrt(n)
###### 26

* Comportamento: calcula a raiz quadrada de `n` (equivalente a `n ^ 0.5`).
* Retorno: resultado.

---

### math.tan(n)
###### 27

* Comportamento: calcula a [tan][tan] de `n`.
* Retorno: resultado em radianos.

---

### math.tanh(n)
###### 28

* Comportamento: calcula a [tangente hiperbólica][tanh] de `n`.
* Retorno: resultado em radianos.

---

### math.tointeger(n)
###### 29

* Comportamento: converte `n` em um valor inteiro.
* Retorno: caso `n` não seja um valor inteiro (ou uma cadeia de caracteres válida),
retornará `nil`, do contrário, retornará o valor convertido.

---

### math.type(n)
###### 30

* Comportamento: obtém o tipo numérico de `n`.
* Retorno: `"integer"`, `"float"` ou `nil`.

---

### math.ult(n0, n1)
###### 31

* Comportamento: compara `n0` com o valor absoluto de `n1`.
* Retorno: um valor booleano indicando se `n0` é menor que o valor absoluto de `n1`.

---
