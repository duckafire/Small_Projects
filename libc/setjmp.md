# stdjmp
Adiciona ferramentas capazes de manipular o fluxo de execução do código (semelhante a um `goto`, mas de maneira global), através do uso de um tipo, uma macro e uma função,
os quais são definidos nesta biblioteca, e estão listadas de maneira respectiva abaixo. 

* jmp_buf
	* Tipo (matriz) usado como parâmetro e argumento em `setjmp` e `longjmp`, resposável por armazenar dados sobre o ambiente atual.

* int setjmp(jmp_buf env)
	* env: Matriz do tipo `jmp_buf` que será usada para armazenar o ambiente atual.
	* Usos: Armazena o ambiente atual na matriz especificada como argumento para `env`, para uso posterior por `longjmp`.
	* Retorno: 0 caso seja chamada diretamente ou o valor do parâmetro `value`, da função `longjmp`, após o primeiro "salto" (usando a mesma matriz).

* void longjmp(jmp_buf env, int value)
	* env: Matriz que contém o ambiente salvo (por `setjmp`). | value: Valor que será passado para `jmp_buf` após o primeiro salto. Caso seja 0, o valor passado será 1.
	* Usos: Restaura o ambiente salvo na matriz especificada como argumento para `env` (oriunda de `setjmp`).
	* Retorno: Não possui retorno.
	
<br>

> Segundo o livro **Expert C Programming**, escrito por *Peter Van Der Linden*, o ambiente, ou seja, o que `setjmp` salva, consiste em: <br>
> "Uma cópia do contador do programa e o ponteiro atual na parte superior da pilha (`stack`)." <br>
> Nas palavras dele: <br>
> "Setjmp saves a copy of the program counter and the current pointer to the top of the stack." <br>
> Mais algumas definições sobre o que compõe e/ou o que são os ambientes salvos por `setjmp` podem ser encontradas [aqui](https://stackoverflow.com/questions/14685406/practical-usage-of-setjmp-and-longjmp-in-c).

<br>

``` c
#include <stdio.h>  // printf
#include <setjmp.h>

jmp_buf memory;
jmp_buf loop;

void timer(void){
	
	int tics = 0;
	setjmp(loop);
	
	tics++;
	printf("Timer: %d\n", tics);
	
	if(tics <= 5) longjmp(loop, tics); else longjmp(memory, 1);
	
	printf("[ JUMP HERE ]\n"); // never printed
	
	return;
}

int main(){
	
	printf("[ CONSOLE ]\n");
	
	int rtn = setjmp(memory); // ReTorN
	
	printf("Main: %d\n", rtn);
	
	if(rtn == 0) timer();
	
	printf("[ END ]\n");
	
	printf("\n\n[ Press ENTER ]"); // pause
	getchar();
	
	return 0;
}
```

```
[ CONSOLE ]
Main: 0
Timer: 1
Timer: 2
Timer: 3
Timer: 4
Timer: 5
Timer: 6
Main: 1
[ END ]


[ Press ENTER ]
```

<br>

-----
<br>

#### Fontes:
* https://en.wikipedia.org/wiki/Setjmp.h
* https://www.tutorialspoint.com/c_standard_library/setjmp_h.htm
* https://petbcc.ufscar.br/setjmp/
* https://www.techonthenet.com/c_language/standard_library_functions/setjmp_h/longjmp.php
* https://isolution.pro/pt/t/c-standard-library/setjmp-h/biblioteca-c-setjmp-h
* https://stackoverflow.com/questions/14685406/practical-usage-of-setjmp-and-longjmp-in-c
* https://stackoverflow.com/questions/25266832/exactly-what-program-state-does-setjmp-save

<br>

-----
