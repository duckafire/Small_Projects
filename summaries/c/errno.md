# errno
Fornece uma variável global chamada **errno**, cujo valor é alterado por algumas funções das bibliotecas padrão, quando as mesmas passam por algum erro, seja ele fatal ou não.

<br>

* extern int **errno** = 0;

<br>
	
| Valores | Erro								      |
| :-:     | :--       							      |
| 0       | Nenhum erro (valor incial)    		      |
| 1       | Operação não permitida        		      |
| 2       | Nenhum arquivo ou diretório encontrado    |
| 3       | Esse processo não existe        	      |
| 4       | Chamada de sistema interrompida           |
| 5       | Erro de Entrada/Saída (E/S; I/O)          |
| 6       | Nenhum dispositivo ou endereço encontrado |
| 7       | A lista de argumentos é muito longa       |
| 8       | Erro de formato Exec (executável)	      |
| 9       | Número de arquivo incorreto               |
| 10      | Nenhum processo filho        		      |
| 11      | Tentar novamente        			      |
| 12      | Sem memória        					      |
| 13      | Permissão negada        			      |

* Bibliotecas distintas podem adicionar mais possibilidades de valores para *errno*.

<br>
<hr>
<br>

#### Fontes:
* https://en.wikipedia.org/wiki/Errno.h
* https://www.geeksforgeeks.org/error-handling-in-c/

<br>
<hr>
