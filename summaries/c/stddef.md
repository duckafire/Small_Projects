# stddef
Define algumas macros e variáveis, as quais estão presentes em outras bibliotecas *padrão* da linguagem C.

##### Variáveis

| Nome      | Especificação     | Valor                                         |
| :-:       | :-:               | :-:                                           |
| ptrdiff_t | signed integral   | Resultado da subtração de dois ponteiros      |
| size_t    | unsigned integral | Retorno de `sizeof()`                         |
| wchar_t   | integral          | Tamanho de uma constante de caracteres largos |

##### Macros

> **NULL**
>> Valor de uma constante de ponteiro zero/nulo.

> **offsetof(type, member_designator)**
>> Retorna o número de bytes de deslocamento antes de um elemento específico de uma `struct` ou `union`.
>>> *type*: Nome da `struct` ou `union`.
>>> *member_designator*: Membro da `struct` ou `union`.

* ###### [Alguns dos usos de `offsetof` incluem o empacotamento de estruturas de dados e a descrição de como os dados `EEPROM` são armazenados.](https://www.embedded.com/learn-a-new-trick-with-the-offsetof-macro/ "Sobre 'offsetof'")
	
``` c
#include <stdio.h> // printf ; getchar
#include <stddef.h>

int main(){
	
	union     dog{ int age; float height; char name[25]; };
	typedef union{ int age; float height; char name[25]; }defDog;
	
	struct     man{ int age; float height; char name[25]; union dog pet; };
	typedef struct{ int age; float height; char name[25];    defDog pet; }defMan;
	
	typedef struct{ int age; float height; char name[25]; struct pet{ int age; float height; char name[25]; }pet; }finalMan;
	
	printf("[ CONSOLE ]\n\n");
	
	printf("%d - ", offsetof(defDog, name));
	printf("%d\n\n", offsetof(union dog, name));
	
	printf("%d - ", offsetof(struct man, name));
	printf("%d\n\n", offsetof(defMan, name));
	
	printf("%d - ", offsetof(struct man, pet.name ));
	printf("%d\n\n", offsetof(defMan, pet.name));
	
	printf("%d\n", offsetof(finalMan, pet.name));
	
	printf("\n\n[ Press ENTER ]"); // paused
	getchar();
	return 0;
}
```

```
[ CONSOLE ]

0 - 0

8 - 8

36 - 36

44


[ Press ENTER ]
```
	
<br>

-----
<br>

#### Fontes:
* https://www.tutorialspoint.com/c_standard_library/stddef_h.htm
* https://en.wikibooks.org/wiki/C_Programming/stddef.h
* https://publications.gbdirect.co.uk/c_book/chapter2/integral_types.html
* https://www.embedded.com/learn-a-new-trick-with-the-offsetof-macro/

<br>

-----
