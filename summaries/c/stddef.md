# stddef
Define algumas macros e variáveis, as quais estão presentes em outras bibliotecas *padrão* da linguagem C.

##### Variáveis

| Nome       | Especificação     | Valor                                         |
| :-:        | :-:               | :-:                                           |
| ptrdiff\_t | signed integral   | Resultado da subtração de dois ponteiros      |
| size\_t    | unsigned integral | Retorno de `sizeof()`                         |
| wchar\_t   | integral          | Tamanho de uma constante de caracteres largos |

##### Macros

* **NULL**
	* Valor de uma constante de ponteiro zero/nulo.
		* Especificamente: `0x0`

* **offsetof(type, member\_designator)**
	* Retorna o número de bytes de deslocamento antes de um elemento específico de uma `struct` ou `union`.
		* *type*: Nome da `struct` ou `union`.
		* *member\_designator*: Membro da `struct` ou `union`.

* ###### [Alguns dos usos de `offsetof` incluem o empacotamento de estruturas de dados e a descrição de como os dados `EEPROM` são armazenados.](https://www.embedded.com/learn-a-new-trick-with-the-offsetof-macro/ "Sobre 'offsetof'")
		
<br>
<hr>
<br>

#### Fontes:
* https://www.tutorialspoint.com/c\_standard\_library/stddef\_h.htm
* https://en.wikibooks.org/wiki/C\_Programming/stddef.h
* https://publications.gbdirect.co.uk/c\_book/chapter2/integral\_types.html
* https://www.embedded.com/learn-a-new-trick-with-the-offsetof-macro/

<br>
<hr>
