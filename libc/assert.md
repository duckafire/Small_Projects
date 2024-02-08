# assert
Possui uma função que verifica expressões booleanas.

<br>

-----
<br>

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

<br>

-----
<br>

#### Fonte:
* https://en.wikipedia.org/wiki/Assert.h
* https://petbcc.ufscar.br/assert/

<br>

-----
