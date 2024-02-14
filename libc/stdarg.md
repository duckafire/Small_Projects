# stdarg
Fornece um conjunto de quatro macros e um tipo que podem ser usados, ordenadamente, para obter os argumentos de uma função, quando a quantidade de parâmetros dela
é indefinida (`...`).

> va_list: Tipo dos parâmetros e retorno dos macros abaixo.

* void va_start(va_list arg, last_arg)
	* arg: Uma variável do tipo `va_list`. | last_arg: Última parâmetro antes da lista de argumentos variáveis (`...`), da função a qual ela está sendo usada.
	* Usos: Inicializa o argumento passado como `arg` para ser posteriormente usado por `va_arg` e `va_end`.
	* Retorno: Sem retorno.

* type va_arg(va_list arg, type)
	* arg: Variável inicializada, anteriormente, por `va_start`. | type: Tipo dos valores retornados por esta função.
	* Usos: Obtém cada um dos valores armazenados em `arg`, um a um, em ordem, a cada chamada. Não consegue indetificar o fim da lista de argumentos, podendo gerar valores imprevisíveis (lixo).
	* Retorno: Cada um dos valores presentes em `arg`, na ordem em que eles são obtidos. Atribuíndo o tipo especificado em `type` a eles.

* void va_end(va_list arg)
	* arg: Variável inicializada, anteriormente, por `va_start` e (opcionalmente) ultilizada por `va_arg`.
	* Usos: Finaliza à lista presente na variável passado para `arg`, tornando-a indefinida.
	* Retorno: Sem retorno.
	
* void va_copy(va_list arg1, va_list arg2);
	* arg1: A variável, do tipo `va_list`, que receberá um novo valor. | arg2: Variável inicializada por `va_start`.
	* Usos: Copia os valores armazenados em `arg2` para `arg1`.
	* Retono: Sem retorno.

``` c
#include <stdio.h>  // printf
#include <stdarg.h>

void unlimited(int n, ...){
	
	va_list queue;
	va_start(queue,n);
	
	va_list queu2;
	va_copy(queu2, queue);
	
	printf("[ START ]\n");
	
	printf("\n");
	for(int i = 1; i <= 5; i++) printf("%c\n", va_arg(queue, int));
	printf("\n");
	for(int i = 1; i <= 5; i++) printf("%c\n", va_arg(queu2, int));
	printf("\n");
	
	va_end(queue);
	
	printf("[ END ]\n");
	
	return;
}

int main(){
	
	printf("[ CONSOLE ]\n\n");
	
	unlimited(0, 'A', 'B', 'C', 'D', 'E');
	
	printf("\n\n[ Press ENTER ]"); // pause
	getchar();
	return 0;
}
```

```
[ CONSOLE ]

[ START ]

A
B
C
D
E

A
B
C
D
E

[ END ]


[ Press ENTER ]
```

<br>

-----
<br>

#### Fontes:
* https://en.wikipedia.org/wiki/Stdarg.h#References
* https://www.tutorialspoint.com/c_standard_library/stdarg_h.htm
* https://www.techonthenet.com/c_language/standard_library_functions/stdarg_h/va_arg.php
* https://isolution.pro/pt/t/c-standard-library/stdarg-h/biblioteca-c-stdarg-h
* https://linux.die.net/man/3/va_start

<br>

-----
