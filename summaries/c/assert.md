# assert
Fornece duas macros destinadas a depuração.

---

### assert(int)
###### 

* Comportamento: em ***tempo de execução***, interromperá a execução do programa, caso
`int==0` e imprimirá uma mensagem de erro, do contrário nada será feito.
* Retorno: nenhum.
	
---

### static\_assert(int, string)
###### 

* Comportamento: em ***tempo de compilação***, interromperá a execução do programa, caso
`int==0` e imprimirá `string`, do contrário nada será feito.
* Retorno: nenhum.
	
---

#### Fontes:
* [wikipedia: assert.h](https://en.wikipedia.org/wiki/assert.h )
* [tutotialspoint: static\_assert](https://www.tutorialspoint.com/c_standard_library/assert_h.htm )

---
