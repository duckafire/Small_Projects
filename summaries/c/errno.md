# errno
Fornece uma variável global, utilizada, por diversas funções do *Padrão C*, para deter
códigos de erros não fatais.

---

[math]: https://github.com/duckafire/small_projects/blob/main/summaries/c/math.md

* `EDOM` (*DOMain error*): usada por funções, de [math.h][math], que "aceitam" apenas
valores não negativos, para indicar que um valor negativo lhe foi dado.

* `ERANG` (*RANGe error*): dado a `errno` por funções cujo valor calculado para retorno
extrapola o limite de seu tipo.

* `EILSE` (*ILlegal SEquence*): utilizado por funções destinadas a manipulação de
caracteres *multibyte*, quando estas encontram sequências inválidas.

---

### extern int errno;
###### 

* Intuito: armazena códigos de erros que ocorreram durante a execução de dadas funções do
*Padrão C*

> [!IMPORTANT]
> O valor de seus códigos numéricos varia entre plataformas (exceto para aquelas
> apresentadas acima). Veja os código para:
> 
> * [Windows](https://learn.microsoft.com/en-us/cpp/c-runtime-library/errno-constants?vi"+yew=msvc-170)
> * [Unix](https://www.gnu.org/software/libc/manual/html_node/Error-Codes.html).

---

#### Fontes:
* [wikipedia: errno.h](https://en.wikipedia.org/wiki/errno.h )
* [cplusplus: standard macros](https://cplusplus.com/reference/cerrno/errno/ )

---
