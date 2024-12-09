# stdarg
Fornece um conjunto de quatro macros e um tipo que podem ser usados, ordenadamente, para obter os argumentos de uma função, quando a quantidade de parâmetros dela
é indefinida (`...`).

<br>

* va\_list: Tipo dos parâmetros, argumentos e retorno dos macros abaixo.

<br>

<h3>void va\_start(va\_list arg, last\_arg)</h3>
	* Comportamento: Inicializa o argumento passado como `arg` para ser posteriormente usado por `va\_arg` e `va\_end`.
	* Retorno: Sem retorno.

<br>
<hr>
<br>

<h3>type va\_arg(va\_list arg, type)</h3>
	* Comportamento: Obtém cada um dos valores armazenados em `arg`, um a um, em ordem, a cada chamada. Não consegue indetificar o fim da lista de argumentos, podendo gerar valores imprevisíveis (lixo).
	* Retorno: Cada um dos valores presentes em `arg`, na ordem em que eles são obtidos. Atribuíndo o tipo especificado em `type` a eles.

<br>
<hr>
<br>

<h3>void va\_end(va\_list arg)</h3>
	* Comportamento: Finaliza à lista presente na variável passado para `arg`, tornando-a indefinida.
	* Retorno: Sem retorno.

<br>
<hr>
<br>
	
<h3>void va\_copy(va\_list arg1, va\_list arg2);</h3>
	* Comportamento: Copia os valores armazenados em `arg2` para `arg1`.
	* Retono: Sem retorno.

<br>
<hr>
<br>

#### Fontes:
* https://en.wikipedia.org/wiki/Stdarg.h#References
* https://www.tutorialspoint.com/c\_standard\_library/stdarg\_h.htm
* https://www.techonthenet.com/c\_language/standard\_library\_functions/stdarg\_h/va\_arg.php
* https://isolution.pro/pt/t/c-standard-library/stdarg-h/biblioteca-c-stdarg-h
* https://linux.die.net/man/3/va\_start

<br>
<hr>
