# stdbool
Adiciona 4 macros relacionados a valores booleanos (tipo e valores), permitindo a declaração explicita destes.

<br>

| Macros | Valor |
| :-:    | :-:   |
| bool   | Tipo booleano (`int`)  |
| true   | 1     |
| false  | 0     |
| __bool_true_false_are_defined | 1 |

<br>

``` c
int main(){
	
	bool isHungry  = true;  // == int isHungry  = 1;
	bool isThirsty = false; // == int isThirsty = 0;
	
	return 0;
}
``` 

<br>

-----
<br>

> Tendo em vista que o tipo `int` e os valores `1` e `0` podem ser usados para está finalidade, é possível afirmar/constatar
> que as adições trazidas por esta biblioteca são apenas visuais, tendo o intuito de facilitar a leitura do código.

<br>

-----
<br>

#### Fontes:
* https://www.geeksforgeeks.org/bool-in-c/
* https://pt.wikipedia.org/wiki/Stdbool.h

<br>

-----
