# stdjmp
Adiciona ferramentas capazes de manipular o fluxo de execução do código, semelhante a um `goto` com alcance global.

<hr>

* jmp\_buf: tipo matriz responsável por armazenar dados referentes ao ambiente atual. Usado pela macro `setjmp` e pela função `longjmp`.

<hr>

<h3>setjmp(jmp_buf)</h3>

* Comportamento: salva dados do "estado do programa" em `jmp_bug`.
* Retorno: `0`, caso seja chamada diretamente, ou o segundo argumento de `longjmp` (`int`), caso ele tenha executado um salto com o mesmo *buffer*.

<br>

> [!TIP]
> Algumas definições para o que seria o ["estado do programa"](https://stackoverflow.com/questions/25266832/exactly-what-program-state-does-setjmp-save "Stackoverflow").

<br>

<hr>

<h3>void longjmp(jmp_buf, int)</h3>

* Comportamento: restaura o ambiente salvo em `jmp_buf` e define `int` como valor de retorno para a próxima chamada de `setjmp`.
* Retorno: nenhum.

<br>

> [!IMPORTANT]
> Se `int==0`, ele será convertido para `1`.

<br>

> [!TIP]
> Dicas de [usos pŕaticos](https://stackoverflow.com/questions/14685406/practical-usage-of-setjmp-and-longjmp-in-c "Stackoverflow") para está biblioteca.

<br>

<hr>

#### Fontes:
* [wikipedia: setjmp.h](https://en.wikipedia.org/wiki/setjmp.h )
* [technthenet: example](https://www.techonthenet.com/c_language/standard_library_functions/setjmp_h/longjmp.php )

<hr>
