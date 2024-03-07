# assert
Possui uma função que verifica expressões booleanas.

<br>

* void **assert**(int expr);
	* expr: Expressão (booleana).
	* Uso: Verificar a validade de uma expressão durante a execução do programa. Encerra o programa e gera um erro caso a expressão passada seja falsa.
	* Retorno: Sem retorno.
	
``` c
#include <assert.h>

int main(){
	
	assert(0 == 0); // is true, not stop the program 
	
	assert(0 != 0); // is false, stop the program and print the mensage of error on console
	
	return toReturn;

}
```

<br>

-----
<br>

#### Fontes:
* https://en.wikipedia.org/wiki/Assert.h
* https://petbcc.ufscar.br/assert/

<br>

-----
