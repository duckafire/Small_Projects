# errno
Fornece uma variável global chamada **errno**, seu valor é alterado por diversas funções da biblioteca padrão, para indicar erros.

<br>

-----
<br>

* extern int **errno**;
	* 0: valor incial.
	* É uma variável global que armazena valores de erro. Seu valor é alterado sempre que uma função encontrar um erro.
	
| Valores | Erro								  |
| :-:     | :-:       							  |
| 1       | Operação não permitida        		  |
| 2       | Nenhum arquivo ou diretório        	  |
| 3       | Esse processo não existe        	  |
| 4       | Chamada de sistema interrompida       |
| 5       | Erro de E/S        					  |
| 6       | Nenhum dispositivo ou endereço        |
| 7       | A lista de argumentos é muito longa   |
| 8       | Erro de formato Exec        		  |
| 9       | Número de arquivo incorreto           |
| 10      | Nenhum processo filho        		  |
| 11      | Tentar novamente        			  |
| 12      | Sem memória        					  |
| 13      | Permissão negada        			  |

* ###### Bibliotecas distintas podem adicionar mais possibilidades de valores para *errno*.

``` c
#include <stdio.h> // fopen
#include <errno.h>

int main(){

	FILE* file = fopen("example.txt", "r");
	// errno = 2
	
	return 0;
}

```

<br>

-----
<br>

#### Fontes:
* https://en.wikipedia.org/wiki/Errno.h
* https://www.geeksforgeeks.org/error-handling-in-c/

<br>

-----
