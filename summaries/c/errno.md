# errno
Fornece uma variável global.

<hr>

* `EDO`M (*domain error*; erro de domínio): usado por funções de [`math.h`](https://github.com/duckafire/small_projects/blob/main/summaries/c/math.md), para indicar que um valor negativo foi utilizado como argumento para uma dada funções que "aceita" manipular apenas valores *reais positivos* (*domínio*).
* `ERANG`E (*range error*; erro de alcance): valor atribuído a `errno` por funções cujo resultado extrapola o valor máximo representável por seu retorno.
* `EILSE`Q (*Illegal sequence*; sequencia ilegal): recebido por `errno` quando funções de manipulação de caracteres *multibytes* encontram sequências inválidas.

<hr>

<h3>extern int errno;</h3>

* Intuito: armazena códigos de erros que ocorreram durante a execução de dadas funções padrão da linguagem C.

<br>

> [!IMPORTANT]
> O significado de seus códigos numéricos pode variar entre plataformas distintas, exceto para as macros vindas do Padrão C (que estão acima). Veja: [Windows](https://learn.microsoft.com/en-us/cpp/c-runtime-library/errno-constants?vi"+yew=msvc-170); [Linux](https://www.gnu.org/software/libc/manual/html_node/Error-Codes.html).

<br>

<hr>

#### Fontes:
* [wikipedia: errno.h](https://en.wikipedia.org/wiki/errno.h )
* [cplusplus: standard macros](https://cplusplus.com/reference/cerrno/errno/ )

<hr>
