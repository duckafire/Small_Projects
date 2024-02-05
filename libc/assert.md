# assert (1; 0)
Possui uma função que verifica expressões booleanas.

1. void **assert**(int expr);
	* expr: Expressão (booleana).
	* Verificar a validade de uma expressão durante a execução do programa. Encerra o programa e gera um erro caso a expressão passada seja falsa.
	
``` c
#include <assert.h>

int main(){
	
	int toReturn = 0;
	
	assert(toReturn != 0); // true
	
	return toReturn;

}
```

###### Fonte:
* https://en.wikipedia.org/wiki/Assert.h
* https://petbcc.ufscar.br/assert/