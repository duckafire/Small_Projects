# assert
Fornece duas macros destinadas a depuração.

<hr>

<h3>assert(int)</h3>

* Comportamento: **durante a EXECUÇÃO do programa**, caso `int` seja igual a `0`, interrompe a execução do programa e imprime uma mensagem de erro, do contrário nada é feito.
* Retorno: nenhum.
	
<hr>

<h3>static_assert(int, string)</h3>

* Comportamento: **durante a COMPILAÇÃO do programa**, caso `int` seja igual a `0`, interrompe o processo do compilador e imprime `string`, do contrário nada é feito.
* Retorno: nenhum.
	
<hr>

#### Fontes:
* [wikipedia: assert.h](https://en.wikipedia.org/wiki/assert.h )
* [tutotialspoint: static\_assert](https://www.tutorialspoint.com/c_standard_library/assert_h.htm )

<hr>
