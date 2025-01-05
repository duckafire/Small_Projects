# stdarg
Fornece um conjunto de quatro macros e um tipo que podem ser usados para acessar os argumentos indefinidos (`...`) de uma dada função.

<br>

* va\_list: tipo dos parâmetros, argumentos e retorno dos macros abaixo.

<br>
<hr>
<br>

<h3>va_start(va_list, last_func_arg)</h3>
* Comportamento: inicializa a lista.
* Retorno: nenhum.

> [!IMPORTANT]
> `last_func_arg` é referente ao último argumento da função, antes de `...` (`void example(int foo, ...)`).

<br>
<hr>
<br>

<h3>va_arg(va_list, type)</h3>
* Comportamento: obtém cada um dos valores da lista, a cada chamada.
* Retorno: cada um dos valores presentes na list, na ordem em que eles são obtidos.

<br>

> [!IMPORTANT]
> `type` é o tipo do valor extraído da lista. Uma lista pode possuir valores de tipos diversos, mas o tipo correto deve ser informado a `var_arg`.

<br>

> [!IMPORTANT]
> `va_arg` não consegue identificar o final da lista, o que pode levá-lo a retornar lixo.

<br>

> [!TIP]
> Especifique o comprimento da lista como último parâmetro da função (`void foo(int len, ...)`), ou use um "valor de quebra" (`NULL`, `-1`, ...), para interromper a leitura da lista, assim evitando o lixo.

<br>
<hr>
<br>

<h3>va_end(va_list)</h3>
* Comportamento: finaliza a lista.
* Retorno: nenhum.

<br>
<hr>
<br>
	
<h3>va_copy(va_list0, va_list1);</h3>
* Comportamento: copia a lista de argumentos de `va_list1` para `va_list0`.
* Retono: nenhum.

<br>
<hr>
<br>

#### Fontes:
* https://en.wikipedia.org/wiki/Stdarg.h#References
* https://www.techonthenet.com/c\_language/standard\_library\_functions/stdarg\_h/va\_arg.php

<br>
<hr>
