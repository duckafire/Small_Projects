# stdio
Fornece várias funções para a manipulação de fluxos de entrada e saída (E/S), provindos de
teclados, impressoras, terminais e qualquer outro tipo suportado pelo sistema.

[errno]: https://github.com/duckafire/small_projects/blob/main/summaries/c/errno.md "Resumo da errno.h"
[stdarg]: https://github.com/duckafire/small_projects/blob/main/summaries/c/stdarg.md "Resumo da errno.h"

---

* `BUFSIZ`: tamanho do *buffer* usado pela função [`setbuf`](#9).
* `EOF`: caractere de fim de arquivo.
* `FILENAME_MAX`: largura máxima do nome de um arquivo.
* `FOPEN_MAX`: limite de arquivos abertos em simultâneo.
* `L_tmpnam`: largura mínima do nome de um arquivo temporário.
* `TMP_MAX`: limite de arquivos temporários abertos em simultâneo.

> [!NOTE]
> Também são fornecidas macros para trabalhar com funções especificas, sendo elas:
>
> * `_IOFBF`, `_IOLBF`, `_IONBF` para [`setvbuf`](#10)
> * `SEEK_SET`, `SEEK_CUR`, `SEEK_END` para [`fseek`)](#39).

---

* `fpos_t`: estrutura designada à armazenar informações sobre a posição atual do *cursor*
de um *fluxo*.

* `FILE`: estrutura responsável por armazenar o *fluxo* (de dados) de um determinado
arquivo.

> [!NOTE]
> O termo *cursor*, no contexto deste documento, refere-se a posição onde o próximo
> caractere será escrito ou a posição em que está o próximo caractere a ser lido.

> [!TIP]
> *Buffer* pode ser definido como: um espaço de memória temporário criado para armazenar
> dados até que eles sejam devidamente processados ou copiados para um determinado local.
> Veja mais sobre [aqui](https://stackoverflow.com/questions/27993971/understanding-buffering-in-c#27994228 "Stackoverflow").

---

* Por padrão, este cabeçalho disponibiliza três *fluxos*, que são abertos e fechados
automaticamente após a respectiva inicialização e finalização do programa. São eles:
	* `stdin`: armazenar as entradas do usuário (geralmente efetuadas por meio do teclado).
	* `stdout`: armazenar as saída dos programas. Na maioria dos sistemas, seu conteúdo é
	direcionado ao console (geralmente na tela).
	* `stderr`: armazenar as saída de erros e avisos dos programas. Na maioria dos
	sistemas, seu conteúdo é direcionado ao console (geralmente na tela).

> [!NOTE]
> Fechar, manualmente, qualquer um desses *fluxos* acarretará em erros ao tentar utilizar
> algumas das funções deste cabeçalho.

---

|             |              |                | FUNÇÕES      |             |              |               |
| :-:         | :-:          | :-:            | :-:          | :-:         | :-:          | :-:           |
|Operaç. arqu.|Acesso a arqu.| E/S formatada  |E/S de caract.| E/S direta  |Pos. do cursor|Manip. de erros|
|[remove](#1) |[fclose](#5)  |[fprintf](#11)  |[fgetc](#25)  |[fread](#36) |[fgetpos](#38)|[clearerr](#43)|
|[rename](#2) |[fflush](#6)  |[fscanf](#12)   |[fgets](#26)  |[fwrite](#37)|[fseek](#39)  |[feof](#44)    |
|[tmpfile](#3)|[fopen](#7)   |[printf](#13)   |[fputc](#27)  |             |[fsetpos](#40)|[ferror](#45)  |
|[tmpnam](#4) |[freopen](#8) |[scanf](#14)    |[fputs](#28)  |             |[ftell](#41)  |[perror](#46)  |
|             |[setbuf](#9)  |[snprintf](#15) |[getc](#29)   |             |[rewind](#42) |               |
|             |[setvbuf](#10)|[sprintf](#16)  |[getchar](#30)|             |              |               |
|             |              |[sscanf](#17)   |[gets](#31)   |             |              |               |
|             |              |[vfprintf](#18) |[putc](#32)   |             |              |               |
|             |              |[vfscanf](#19)  |[putchar](#33)|             |              |               |
|             |              |[vprintf](#20)  |[puts](#34)   |             |              |               |
|             |              |[vscanf](#21)   |[ungetc](#35) |             |              |               |
|             |              |[vsnprintf](#22)|              |             |              |               |
|             |              |[vsprintf](#23) |              |             |              |               |
|             |              |[vsscanf](#24)  |              |             |              |               |

### Operações com arquivos

#### int remove(const char\*)
###### 1

* Comportamento: deleta um arquivo, ou um diretório vazio, de nome `const char*`.
* Retorno: `0` em caso de sucesso ou um valor diferentes de `0`, caso contrário.

> [!TIP]
> Em muitas implementações dessa biblioteca, erros ocorridos durante a execução desta
> função alterarão o valor de [`errno`][errno].

---

#### int rename(const char\*0, const char\*1)
###### 2

* Comportamento: renomeia um arquivo, ou um diretório, de nome `const char*0` para
`const char*1`.
* Retorno: `0` em caso de sucesso ou um valor diferentes de `0`, caso contrário.

> [!TIP]
> Em muitas implementações dessa biblioteca, erros ocorridos durante a execução desta
> função alterarão o valor de [`errno`][errno].

---

#### FILE\* tmpfile(void)
###### 3

* Comportamento: cria um arquivo temporário em [modo](#modos-de-abertura) `"wb+"`, com um
nome garantidamente diferentes dos demais arquivos existentes.
* Retorno: o endereço do *fluxo* do arquivo criado ou `NULL`, em caso de falha.

> [!IMPORTANT]
> O arquivo será automaticamente deletado após ser fechado (com [`fclose`](#5)) ou após o
> programa ser encerrado com sucesso. Caso o programa seja encerrado anomalamente, a
> eliminação do arquivo temporário criado dependerá do sistema e da implementação da
> biblioteca.

---

#### char\* tmpnam(char\*)
###### 4

* Comportamento: gera um nome de arquivo único e armazena-o em `char*`.
* Retorno: o endereço de `char*` ou o endereço de um ponteiro estático, caso a mesma seja diferente de `NULL`, do contrário, retorna o endereço de uma variável estática (que contem o nome gerado), cujo valor é alterado a cada nova chamada de `tmpnam`.

> [!CAUTION]
> Dado que entre a definição de `char*` e seu uso (por exemplos em [`fopen`](#7)), um
> arquivo de mesmo nome pode ser gerado por outro programa, seu uso é desencorajado.
> *Recomendo* a utilização de [`tmpfile`](3) em seu lugar, dado que tal função criar o
> arquivo imediatamente após gerar seu nome.

> [!NOTE]
> `char*` deve ser uma cadeia de caracteres com largura igual a `L_tmpnam`, por exemplo:
> `char foo[L_tmpnam]`.

---

### Acesso a arquivos

#### int fclose(FILE\*)
###### 5

* Comportamento: encerra um *fluxo* (`FILE`), desassociando-o totalmente do arquivo a qual
ele, anteriormente, tinha acesso e liberando o espaço que foi ocupado na memória.
* Retorno: `0`, em caso de sucesso, ou `EOF`, caso contrário.

> [!IMPORTANT]
> Mesmo que a chamada falhe, o `FILE*` perderá acesso ao arquivo e aos *buffers* do mesmo.

> [!NOTE]
> Após seu uso: o conteúdo presente no *buffer* de entrada, do *fluxo* em questão, será
> descartado; o conteúdo presente no *buffer* de saída será escrito no arquivo.

---

#### int fflush(FILE\*)
###### 6

* Comportamento: força a gravação dos dados presentes no *buffer* de saída (de `FILE*`) no
arquivo sob sua custodia, mas apenas caso `FILE*` encaixe-se nas **exigências**.
* Retorno: `0` caso a operação seja bem sucedida, `FILE*` não se encaixe nas
**exigências** ou caso `FILE*` não possua nenhum *buffer*. Em caso de falha, retornará
`EOF` e atualizará [errno][errno].

> [!IMPORTANT]
> **Exigências**:
> 
> `FILE*` deve estar em modo `"w"`.
> `FILE*` deve estar em modo `"a"` e sua última operação de E/S deve ter sido de entrada.
> 
> Caso ambas sejam descumpridas, `fflush` não fará nada.

> [!NOTE]
> Se `FILE*==NULL`, `fflush` afetará **todos** os *buffers* abertos, em todos os *fluxos*
> que sejam compatíveis com as **exigências** antes citadas.

---

#### FILE\* fopen(const char\*0, const char\*1)
###### 7

* Comportamento: cria um *fluxo* para um arquivo de nome `const char*`, em
[modo](#modos-de-abertura).
* Retorno: o *fluxo* criado.

##### Modos de abertura

| Modo | Descrição |
| :-:  | :--       |
| "r"  | Abre um arquivo existente para leitura. |
| "w"  | Cria um arquivo para escrita. Caso o arquivo já exista, ele será substituído por um arquivo em branco e seu conteúdo será descartado.                   |
| "a"  | Abre um arquivo, com seu *cursor* posicionado no final do mesmo. Cria o arquivo, caso ele não exista.                                                   |
| "r+" | Abre um arquivo existente para leitura e escrita.                                                                                                       |
| "w+" | Cria um arquivo para leitura e escrita. Caso o arquivo já exista, ele será substituído por um arquivo em branco e seu conteúdo será descartado.         |
| "a+" | Abre um arquivo existente para leitura e escrita, onde (apenas) a posição de escrita é fixada no final do arquivo. Cria o arquivo, caso ele não exista. |

> [!IMPORTANT]
> As cadeias acima dão acesso a arquivos de texto, para acessas arquivos binários adicione
> `'b'` (`"rb"`; `"rb+"`; `"r+b"`).

> [!NOTE]
> Caso o arquivo em questão não refira-se a um dispositivo interativo, o *fluxo* será, por
> padrão, __*full buffering*__. Veja [`setvbuf`](#10)).

> [!TIP]
> Em muitas implementações dessa biblioteca, erros ocorridos durante a execução desta
> função alterarão o valor de [`errno`][errno].

---

#### FILE\* freopen(const char\*0, const char\*1, FILE\*)
###### 8

* Comportamento: se `const char*0!=NULL`, associa o arquivo de nome `const char*0` a
`FILE*`, em [modo](#modos-de-abertura) `const char*1`; se `const char*0==NULL`, altera o
[modo](#modos-de-abertura) de `FILE*` para `const char*1`.
* Retorno: `FILE*` ou `NULL`, em caso de falha.

> [!IMPORTANT]
> Diferentes implementações desta biblioteca podem adicionar restrições e condições para a
> troca de [modo](#modos-de-abertura) do *fluxo*.

> [!NOTE]
> Antes da associação ocorrer, caso hajam outro arquivo associado a `FILE*`, `freopen`
> **tentará** desassociá-lo.
> 
> Após a operação, os *indicador de error* e *indicador de final no arquivo*, de `FILE*`,
> serão "limpos".

> [!TIP]
> Chamar `freopen("log.txt", "w", stdout)` direcionará todas as saídas de funções
> para o arquivo `log.txt`. Já chamar `freopen("data.txt", "r", stdin)` fará com que
> chamadas de funções de entrada busquem caracteres em `data.txt`.
> 
> Em muitas implementações dessa biblioteca, erros ocorridos durante a execução desta
> função alterarão o valor de [`errno`][errno].

---

#### void setbuf(FILE\*, char\*)
###### 9

* Comportamento: associa `char*` como *buffer* para `FILE*`, baseado no seu
[modo](#modos-de-abertura).
* Retorno: nenhum.

> [!CAUTION]
> Essa função deve ser usadas após `FILE*` ser associado ao seu arquivo e antes de
> qualquer operação de E/S ocorrer em `FILE*`.

> [!NOTE]
> Um *buffer de fluxo* (*de dados*), vulgo *stream buffer*, é um bloco de dados que atua
> como intermediário entre operações de E/S e um dado arquivo, onde:
> 
> * Para saídas, o *buffer* gravará os valores no arquivo após chegar ao limite de sua
> capacidade de armazenamento, limpando-se logo após a operação de gravação ser finalizada.
> 
> * Para entradas, o *buffer* receberá o conteúdo do arquivo até estourar sua capacidade
> (*full buffering*) ou obter uma quebra de linha (*line buffering*). Em seguida, em
> compartilhará seu conteúdo com agentes que venham a solicitá-lo, limpando-se logo após.

> [!TIP]
> Uma chamada dessa função é equivalente a chamar [`setvbuf`](#10) usando `_IOFBF` como
> modo e `BUFSIZ` como tamanho.

---

#### int setvbuf(FILE\*, char\*, int, size\_t)
###### 10

* Comportamento: executa o mesmo trabalho de [`setbuf`](#9), com o acréscimo de permitir
especificar o *modo* (`int`) de *bufferização* de `FILE*` e o tamanho (`size_t`) do
*buffer* que será criado.
* Retorno: `0`, em caso de sucesso, ou um valor diferentes de `0`, caso contrário.

##### Modos de *bufferização*

| Macro   | Nome             | Entrada | Saída |
| :-:     | :-:              | :--     | :--   |
| \_IOFBF | *Full buffering* | Quando uma operação de entrada é solicitada e o *buffer* está vazio. | Quando o *buffer* atinge seu limite ou após [`fflush`](#6) ser usado. |
| \_IOLBF | *Line buffering* | Quando uma quebra de linha é obtida, uma operação de entrada é solicitada e o *buffer* está vazio. | Quando um caractere de quebra de linha (`'\n'`) é inserido ou quando o *buffer* chega ao seu limite. |
| \_IONBF | *No buffering*   | O conteúdo é retirado diretamente do arquivo. | O conteúdo é lido diretamente do arquivo. |

> [!IMPORTANT]
> O valor de `size_t` só será relevante caso:
> `(char\*==NULL && (int==_IOFBF || int==_IOLBF)) == true`.
> 
> Essa função deve ser usada após `FILE*` ser associado ao seu arquivo e antes de qualquer
> operação de E/S ocorrer com seu *fluxo*.

> [!NOTE]
> Um *buffer de fluxo* (*de dados*), vulgo *stream buffer*, é um bloco de dados que atua
> como intermediário entre operações de E/S e um dado arquivo, onde:
> 
> * Para saídas, o *buffer* gravará os valores no arquivo após chegar ao limite de sua
> capacidade de armazenamento, limpando-se logo após a operação de gravação ser finalizada.
> 
> * Para entradas, o *buffer* receberá o conteúdo do arquivo até estourar sua capacidade
> (*full buffering*) ou obter uma quebra de linha (*line buffering*). Em seguida, em
> compartilhará seu conteúdo com agentes que venham a solicitá-lo, limpando-se logo após.

> [!TIP]
> `int==_IONBF` fará com que `char*` e `size_t` sejam ignorados.

---

### E/S formatada

##### Formatos de impressão

* Usadas por "funções *print*", estas são combinações de caracteres, estruturadas da
seguinte maneira: `%[bandeira][largura][.[precisão]][comprimento]especificador`

| Especificador | Descrição                                 | Exemplo      |
| :-:           | :--                                       | :-:          |
| %             | O caractere `'%'`                         | %            |
| a/A           | Hexadecimal de ponto flutuante            | -0xc.90fep-2 |
| c             | Um caractere qualquer                     | a            |
| d/i           | Inteiros decimais assinados               | 29           |
| e/E           | Notação científica (mantissa/expoente)    | 3.9265e+2    |
| f/F           | Decimais de ponto flutuante               | 28.1         |
| g/G           | Representação curta de um valor           | 13.18        |
| n             | Não imprime nada, mas atribui o número de caracteres escritos, até o momento, em "seu" argumento respectivo, que deve ser o endereço de um inteiro assinado |  |
| o             | Inteiros octais não assinados             | 7            |
| p             | Endereço de um ponteiro                   | 0xa50b5a37   |
| s             | Cadeia de caracteres terminada com `'\0'` | exemplo      |
| u             | Inteiros decimais não assinados           | 409          |
| x/X           | Inteiros hexadecimais não assinados       | 0xf          |

> [!IMPORTANT]
> Diferença entre os caracteres:
> 
> * Maiúsculos imprimem apenas letras maiúsculos (`0xA`).
> * Minúsculos imprimem apenas letra minúsculas (`0xa`).
>
> Para `f/F` a diferença entre ambos evidencia-se ao tentar imprimir `INF`, `INFINITY`
> e/ou `NAN`.

> [!TIP]
> Funções que suportam estes formatos contam com um *"parâmetro variável"* (`...`), que é
> responsável por armazenar os valores que serão postos no lugar das *combinações*. As
> substituições ocorrem ordenadamente, ou seja, a primeira *combinação* será substituída
> pelo primeira valor armazenado no *"parâmetro variável"*, a segunda pelo segundo e assim
> por diante, até que todos os *formatos* sejam "lidos".

| Bandeira | Descrição                                                                            |
| :-:      | :--                                                                                  |
| -        | Altera a posição de incremento para a direita (o incremento será feito com espaços). |
| +        | Prefixará valores numéricos positivos com `+` |
| *espaço* | Incrementa à esquerda de um dado valor com espaços, até que sua *largura* seja igual a que foi especificada. Mesmo que nenhuma *largura* seja especificada um espaço adicional será adicionado para valores positivos. |
| #        | Para os *especificadores* `o/x/X`: prefixará valores diferentes de `0` com, respectivamente, `0/0x/0X`. Já para `aAeEfFgG`: forçará a impressão de um ponto decimal (`1.00`)|
| 0        | Incrementa à esquerda de um dado valor com zeros, até que sua *largura* seja igual a que foi especificada. Caso nenhuma *largura* seja especificada, nada ocorrerá. |

* Largura: `n`, ou `*` (indica que a largura será especificada por um argumento que prefixará o valor a ser imprimido)
	* Quantidade de dígitos que compõem o valor a ser imprimido. Não quebra valores que ultrapassam o limite.


* Precisão: `n`, ou `*` (indica que a largura será especificada por um argumento que
prefixará o valor a ser imprimido)
	* `d/i/o/u/x/X`: equivalente a *largura n*.
	* `a/A/e/E/f/F`: indica quantos números devem ser escritos após a vírgula (`6` por
	padrão).
	* `g/G`: quantidade máxima de dígitos significativos para impressão.
	* `s`: número de caracteres a ser imprimido (por padrão imprimirá até `'\0'` ser
	encontrado).

> [!NOTE]
> Se apenas o `'.'` for especificado, `0` será usado para padrão.

###### Comprimento

> Indica o comprimento do tipo de dado que será imprimido.

| Comprimento |               |                        |                 |         |            |        |                 |
| :-:         | :--           | :--                    | :--             | :--     | :--        | :--    | :--             |
| Código      | d i           | u o x X                | f F e E g G a A | c       | s          | p      | n               |
| (nenhum)    | int           | unsigned int           | double          | int     | char\*     | void\* | int\*           |
| hh          | signed char   | unsigned char          |                 |         |            |        | signed char\*   |
| h           | short int     | unsigned short int     |                 |         |            |        | short int\*     |
| l           | long int      | unsigned long int      |                 | wint\_t | wchar\_t\* |        | long int\*      |
| ll          | long long int | unsigned long long int |                 |         |            |        | long long int\* |
| j           | intmax\_t     | uintmax\_t             |                 |         |            |        | intmax\_t\*     |
| z           | size\_t       | size\_t                |                 |         |            |        | size\_t\*       |
| t           | ptrdiff\_t    | ptrdiff\_t             |                 |         |            |        | ptrdiff\_t\*    |
| L           |               |                        | long double     |         |            |        |                 |

> [!NOTE]
> Caso o valor destinado a `"%s"`/`"%p"` seja `NULL`, `"(null)"`/`"(nil)"` será impresso.

##### Formatos de impressão

* Usadas por "funções *scanf*", estas são combinações de caracteres estruturadas da
seguinte maneira: `%[*][largura][comprimento]especificador`


| Especificador | Descrição                                 |
| :-:           | :--                                       |
| %             | O caractere `'%'`                         |
| a/e/f/g       | Dígitos decimais contendo opcionalmente: um ponto flutuante; `+` ou `-` como prefixos; `e` ou `E`, junto a um inteiro decimal, como sufixo |
| c             | O próximo caractere. Se a *largura* for diferente de `1`, uma quantidade igual de caracteres será capturada                                |
| d             | Qualquer dígitos decimal, opcionalmente prefixado por `+` ou `-`                                                                           | 
| i/u           | Inteiros octais (prefixados por `0`), hexadecimais (prefixados por `0x`) ou decimais (*opcionalmente* prefixados por `+` ou `-`) assinados/não assinados |
| n             | Não imprime nada, mas atribui o número de caracteres escritos, até o momento, em seu argumento respectivo, que deve ser o endereço de um inteiro assinado |
| o             | Qualquer dígito octal, opcionalmente prefixado por `+` ou `-`                                                                                  |
| p             | Uma cadeia de caracteres que representa um ponteiro. O modelo do endereço depende do sistema operacional e da implementação da biblioteca (mas será o mesmo de [`fprintf`](#11)) |
| s             | Todos os caracteres que não são *espaços em branco*                                   |
| x             | Qualquer dígito hexadecimal, opcionalmente prefixado por `0x` ou `0X` e/ou `+` ou `-` |

---

* Outros:
	* \*: indica que os caracteres lidos **não** devem ser armazenados no destino.
	* largura: indica quantos caracteres serão lidos e capturados.
	* comprimento: indica o comprimento do tipo de dado que será capturado
	([Veja](#comprimento)).

---

> [!WARNING]
> Para funções que utilizam `va_list` espera-se que este seja inicializado antes de seu
> uso e encerrado após o mesmo. Veja [stdarg][stdarg].

#### int fprintf(FILE\*, const char\*, ...)
###### 11

* Comportamento: formata `const char*` com os valores de `...` e a imprime em `FILE*`.
* Retorno: total de caracteres que foram imprimido ou um valor negativo, caso um erro
ocorra.

> [!NOTE]
> Caso um erro de escrita ocorra, o *indicador de erro* de `FILE*` será atualizado. (veja
> [ferror](#45)); se um erro de codificação de caracteres *multibyte* acontecer durante a
> impressão, o valor de [`errno`][errno] será atualizado.

---

#### int fscanf(FILE\*, const char\*, ...)
###### 12

* Comportamento: lê e formata, baseado em `const char*`, o conteúdo de `FILE*`, para ser
armazenado em algum endereço presente em `...`.
* Retorno: em caso de sucesso, retornará a quantidade de itens de `...` que foram
preenchidos com sucesso, caso um erro ocorra ou o fim do arquivo seja atingido, definirá o
*indicador de erro* de [`ferror`](#45) ou [`feof`](#44) e, caso nenhum dado tenha sido
gravado, retornará `EOF`.

> [!NOTE]
> Se ocorrer um erro de codificação de caracteres *multibyte* ao ler, [`errno`][errno] terá
> seu valor alterado para `EILSEQ`.

---

#### int printf(const char\*, ...)
###### 13

* Comportamento: formata `const char*` com os valores de `...` e a imprime em `stdout`.
* Retorno: total de caracteres que foram imprimido ou um valor negativo, caso um erro
ocorra.

> [!NOTE]
> Caso um erro de escrita ocorra, o *indicador de erro* de `FILE*` será atualizado. (veja
> [ferror](#45)); se um erro de codificação de caracteres *multibyte* acontecer durante a
> impressão, o valor de [`errno`][errno] será atualizado.

---

#### int scanf(const char\*, ...)
###### 14

* Comportamento: lê e formata, baseado em `const char*`, o conteúdo de `stdin`, para ser
armazenado em algum endereço presente em `...`.
* Retorno: em caso de sucesso, retornará a quantidade de itens de `...` que foram
preenchidos com sucesso, caso um erro ocorra ou o fim do arquivo seja atingido, definirá o
*indicador de erro* de [`ferror`](#45) ou [`feof`](#44) e, caso nenhum dado tenha sido
gravado, retornará `EOF`.

> [!NOTE]
> Se ocorrer um erro de codificação de caracteres *multibyte* ao ler, [`errno`][errno] terá
> seu valor alterado para `EILSEQ`.

---

#### int snprintf(char\*, size\_t, const char\*, ...)
###### 15

* Comportamento: formata `const char*` com os valores de `...` e a imprime em `char*`,
que deve ter até `size_t` de largura.
* Retorno: total de caracteres gravados em `char*` (menos `'\0'`) ou um valor negativo, em
caso de erro.

---

#### int sprintf(char\*, const char\*, ...)
###### 16

* Comportamento: formata `const char*` com os valores de `...` e a imprime em `char*`.
* Retorno: total de caracteres gravados em `char*` (menos `'\0'`) ou um valor negativo, em
caso de erro.

---

#### int sscanf(const char\*0, const char\*1, ...)
###### 17

* Comportamento: lê e formata, baseado em `const char*1`, o conteúdo de `const char*0`,
para ser armazenado em algum endereço presente em `...`.
* Retorno: em caso de sucesso, retornará a quantidade de itens de `...` que foram
preenchidos com sucesso, caso um erro ocorra e nenhum dado tenha sido gravado, retornará
`EOF`.

---

#### int vfprintf(FILE\*, const char\*, va\_list)
###### 18

* Comportamento: formata `const char*` com os valores de `va_list` e a imprime em
`FILE*`.
* Retorno: total de caracteres que foram imprimido ou um valor negativo, caso um erro
ocorra.

> [!NOTE]
> Caso um erro de escrita ocorra, o *indicador de erro* de `FILE*` será atualizado. (veja
> [ferror](#45)); se um erro de codificação de caracteres *multibyte* acontecer durante a
> impressão, o valor de [`errno`][errno] será atualizado.

---

#### int vfscanf(FILE\*, const char\*, va\_list)
###### 19

* Comportamento: lê e formata, baseado em `const char*`, o conteúdo de `stdin`, para ser
armazenado em algum endereço presente em `va_list`.
* Retorno: em caso de sucesso, retornará a quantidade de itens de `va_list` que foram
preenchidos com sucesso, caso um erro ocorra ou o fim do arquivo seja atingido, definirá o
*indicador de erro* de [`ferror`](#45) ou [`feof`](#44) e, caso nenhum dado tenha sido
gravado, retornará `EOF`.

> [!NOTE]
> Se ocorrer um erro de codificação de caracteres *multibyte* ao ler, [`errno`][errno] terá
> seu valor alterado para `EILSEQ`.

---

#### int vprintf(FILE\*, const char\*, va\_list)
###### 20

* Comportamento: formata `const char*` com os valores de `va_lis` e a imprime em `stdout`.
* Retorno: total de caracteres que foram imprimido ou um valor negativo, caso um erro
ocorra.

> [!NOTE]
> Caso um erro de escrita ocorra, o *indicador de erro* de `FILE*` será atualizado. (veja
> [ferror](#45)); se um erro de codificação de caracteres *multibyte* acontecer durante a
> impressão, o valor de [`errno`][errno] será atualizado.

---

#### int vscanf(FILE\*, const char\*, va\_list)
###### 21

* Comportamento: lê e formata, baseado em `const char*`, o conteúdo de `stdin`, para ser
armazenado em algum endereço presente em `...`.
* Retorno: em caso de sucesso, retornará a quantidade de itens de `va_list` que foram
preenchidos com sucesso, caso um erro ocorra ou o fim do arquivo seja atingido, definirá o
*indicador de erro* de [`ferror`](#45) ou [`feof`](#44) e, caso nenhum dado tenha sido
gravado, retornará `EOF`.

> [!NOTE]
> Se ocorrer um erro de codificação de caracteres *multibyte* ao ler, [`errno`][errno] terá
> seu valor alterado para `EILSEQ`.

---

#### int vsnprintf(char\*, size\_t, const char\*, va\_list)
###### 22

* Comportamento: formata `const char*` com os valores de `va_list` e a imprime em
`char*`, que deve ter até `size_t` de largura.
* Retorno: total de caracteres gravados em `char*` (menos `'\0'`) ou um valor negativo, em
caso de erro.

---

#### int vsprintf(char\*, const char\*, va\_list)
###### 23

* Comportamento: formata `const char*` com os valores de `va_list` e a imprime em
`char*`.
* Retorno: total de caracteres gravados em `char*` (menos `'\0'`) ou um valor negativo, em
caso de erro.

---

#### int vsscanf(const char\*0, const char\*1, va\_list)
###### 24

* Comportamento: lê e formata, baseado em `const char*1`, o conteúdo de `const char*0`,
para ser armazenado em algum endereço presente em `va_list`.
* Retorno: em caso de sucesso, retornará a quantidade de itens de `va_list` que foram
preenchidos com sucesso, caso um erro ocorra e nenhum dado tenha sido gravado, retornará
`EOF`.

---

### E/S de caracteres

#### int fgetc(FILE\*)
###### 25

* Comportamento: obtém o caractere (um `char`) atualmente apontado pelo *cursor* de
`FILE*`.
* Retorno: o caractere obtido (como `int`) ou `EOF`, caso um erro de leitura ocorra
(atualiza [`ferror`](#45)) ou o fim do arquivo seja encontrado (atualiza [`feof`](#44)).

> [!NOTE]
> [`fgetc`](#25) e [`getc`](#29) são equivalente, exceto que, em algumas implementações
> desta biblioteca, [`getc`](#29) pode estar definida como uma macro.

---

#### int fgets(char\*, int, FILE\*)
###### 26

* Comportamento: lê o conteúdo de `FILE*`, e o armazena em `char*`, até que: `int`
caracteres sejam lidos; uma quebra de linha seja encontrada (ela será adicionada a
`char*`); o fim do arquivo seja encontrado.
* Retorno: `char*`, caso algum caractere tenha sido gravado na mesma; `NULL`, caso o final
do arquivo tenha sido encontrado e nenhum caractere tenha sido gravado em `char*`
(atualizar [`feof`](#44)) ou um erro de leitura tenha ocorrido (atualiza [`ferror`](#45);
mesmo que algo tenha sido gravado em `char*`).

---

#### int fputc(int, FILE\*)
###### 27

* Comportamento: escreve um caractere em `FILE*`, na posição de seu *cursor*.
* Retorno: `int` ou, caso um erro ocorra, `EOF` (atualiza [`ferror`](#45)).

> [!NOTE]
> [`fputc`](#27) e [`putc`](#32) são equivalente, exceto que, em algumas implementações
> desta biblioteca, [`putc`](#32) pode estar definida como uma macro.

---

#### char\* fputs(const char\*, FILE\*)
###### 28

* Comportamento: escreve o conteúdo de `const char*` em `FILE*`, a partir da posição de
seu *cursor*.
* Retorno: em caso de sucesso, um valor diferente de zero, do contrário `EOF` (atualiza
[`ferror`](#45)).

---

#### int getc(FILE\*)
###### 29

* Comportamento: obtém o caractere (um `char`) atualmente apontado pelo *cursor* de
`FILE*`.
* Retorno: o caractere obtido (como `int`) ou `EOF`, caso um erro de leitura ocorra
(atualiza [`ferror`](#45)) ou o fim do arquivo seja encontrado (atualiza [`feof`](#44)).

> [!NOTE]
> [`fgetc`](#25) e [`getc`](#29) são equivalente, exceto que, em algumas implementações
> desta biblioteca, [`getc`](#29) pode estar definida como uma macro.

---

#### int getchar(void)
###### 30

* Comportamento: obtém o caractere (um `char`) atualmente apontado pelo *cursor* de
`stdin`.
* Retorno: o caractere obtido (como `int`) ou `EOF`, caso um erro de leitura ocorra
(atualiza [`ferror`](#45)) ou o fim do arquivo seja encontrado (atualiza [`feof`](#44)).

---

#### char\* gets(char\*)
###### 31

* Comportamento: lê o conteúdo de `stdin`, e o armazena em `char*`, até que: uma quebra de
linha seja encontrada (ela **não** será adicionada a `char*`); o fim do arquivo seja
encontrado.
* Retorno: `char*` caso algum caractere tenha sido gravado na mesma; `NULL` caso o final
do arquivo tenha sido encontrado e nenhum caractere tenha sido gravado em `char*`
(atualizar [`feof`](#44)) ou um erro de leitura tenha ocorrido (atualiza [`ferror`](#45);
mesmo que algo tenha sido gravado em `char*`).

> [!WARNING]
> Essa função não está mais disponível a partir do `C11` e `C++14`

---

#### int putc(int, FILE\*)
###### 32

* Comportamento: escreve um caractere em `FILE*`, na posição de seu *cursor*.
* Retorno: `int` ou, caso um erro ocorra, `EOF` (atualiza [`ferror`](#45)).

> [!NOTE]
> [`fputc`](#27) e [`putc`](#32) são equivalente, exceto que, em algumas implementações
> desta biblioteca, [`putc`](#32) pode estar definida como uma macro.

---

#### int putchar(int)
###### 33

* Comportamento: escreve um caractere em `stdout`, na posição de seu *cursor*.
* Retorno: `int` ou, caso um erro ocorra, `EOF` (atualiza [`ferror`](#45)).

---

#### int puts(const char\*)
###### 34

* Comportamento: escreve o conteúdo de `const char*` em `stdout`, a partir da posição de
seu *cursor*, e o sufixa com uma quebra de linha (`'\n'`).
* Retorno: em caso de sucesso, um valor diferente de zero, do contrário `EOF` (atualiza
[`ferror`](#45)).

---

#### int ungetc(int, FILE\*)
###### 35

* Comportamento: "desfaz" a última leitura de `FILE*`, reposicionando o último caractere
lido (`int`) de volta no *fluxo*.
* Retorno: `int` ou `EOF` (se a operação falhar).

> [!WARNING]
> Algumas implementações desta biblioteca não permitem múltiplas chamadas desta função, o
> que gerará uma falha a partir do segundo uso.

> [!IMPORTANT]
> Essa função é incapaz de alterar arquivos, apenas seu *fluxo*, logo chamá-la com `int`
> sendo diferente do último caractere lido de `FILE*` (com [`fgetc`](#25) por exemplo) não
> modificará o conteúdo do arquivo em questão, apenas de seu *fluxo* (modificação essa que
> será perdida ao chamar [`fseek`](#39), [`fsetpos`](#40) ou [`rewind`](#42)).

> [!NOTE]
> Chamar está função desativa o *indicador de final de arquivo* (se ele estiver ativado;
> veja [`feof`](#44)) e se: em [modo](#modos-de-abertura) binário, move o *cursor* um
> *byte* para trás; em [modo](#modos-de-abertura) texto, a posição do *cursor* será
> definida apenas após os caracteres *retornados* serem lidos ou descartados.

> [!TIP]
> Qualquer "[modo](#modos-de-abertura) de *fluxo*" pode ser afetado por está função.

---

### E/S direta

#### size\_t fread(void\*, size\_t0, size\_t1, FILE\*)
###### 36

* Comportamento: lê um total de `size_t1` elementos (que devem ter `size_t0` de
comprimento) vindos de `FILE*` e os armazena em `void*` (que deve ser um vetor caso
`size_t1` seja maior que `1`).
* Retorno: o total de elementos lidos com sucesso.

> [!NOTE]
> Se `size_t0==0`, nada ocorrerá; caso um erro ocorra ou o final do arquivo seja
> encontrado, seus respectivos indicadores (de `FILE*`) serão atualizados (veja [`ferror`]
> (#45) e [`feof`](#44)).

---

#### size\_t fwrite(void\*, size\_t0, size\_t1, FILE\*)
###### 37

* Comportamento: grava um total de `size_t1` elementos (que devem ter `size_t0` de
comprimento) em `FILE*`, vindos de `void*` (que deve ser um vetor caso `size_t1` seja
maior que `1`).
* Retorno: o total de elementos gravados com sucesso.

> [!NOTE]
> Se `size_t0==0`, nada ocorrerá; caso um erro ocorra o *indicador de erro* (de `FILE*`)
> será atualizado (veja [`ferror`](#45)).


---

### Posição do cursor

#### int fgetpos(FILE\*, fpos\_t\*)
###### 38

* Comportamento: obtém os dado sobre a posição atual do *cursor* de `FILE*` e o
armazena-os em `fpos_t*`.
* Retorno: `0`, em caso de sucesso, ou um valor diferente de `0`, caso contrário.

> [!NOTE]
> Ao falhar, essa função, também, define um valor para [`errno`][errno], o qual varia
> entre sistemas distintos.

---

#### int fseek(FILE\*, long, int)
###### 39

* Comportamento: altera a posição atual do *cursor* de `FILE*` para `int` (que deve ser
algumas das macros abaixo) *mais* `long`.
* Retorno: 0` ou, em caso de falha, um valor diferente de `0` (mais a atualização do
*indicador de erro*, veja [`ferror`](#45)).

| Macro     | Representação              |
| :-:       | :--                        |
| SEEK\_SET | Posição inicial do *fluxo* |
| SEEK\_CUR | Posição atual do *cursor*  |
| SEEK\_END | Posição final do *fluxo*   |

> [!NOTE]
> Sua chamada reinicia o *indicador de final do arquivo* (veja [`feof`](#44)).

---

#### int fsetpos(FILE\*, const fpos\_t\*)
###### 40

* Comportamento: define a posição atual do *cursor* de `FILE*`, com base nas informações
contidas em `fpos_t*`.
* Retorno: `0`, em caso de sucesso, ou um valor diferente de `0`, caso contrário.

> [!NOTE]
> Ao falhar, essa função, também, define um valor para [`errno`][errno], o qual varia
> entre sistemas distintos.

---

#### long ftell(FILE\*)
###### 41

* Comportamento: obtém a posição atual do *cursor* de `FILE*`, em decimal.
* Retorno: em caso de sucesso, o valor obtido, do contrário, `-1`.

> [!NOTE]
> Para arquivos: binários, o valor obtido representa a quantidade de *bytes* do início do
> arquivo até a posição atual do *cursor*; texto, o valor obtido pode não ter significado,
> mas ainda pode ser usado para restaurar a posição do *cursor* com [`fseek`](#39).

---

#### void rewind(FILE\*)
###### 42

* Comportamento: altera a posição do *cursor* de `FILE*` para o ponto inicial.
* Retorno: nenhum.

> [!NOTE]
> Em caso de sucesso, os *indicadores de erro e final do arquivo* de `FILE*` serão limpos
> (veja, respectivamente, [`ferror`](#45) e [`feof`](#44)).

---

#### Manipulação de erros

#### void clearerr(FILE\*)
###### 43

* Comportamento: redefine os *indicadores de error e de final de arquivo* de `FILE*`.
* Retorno: nenhum.

> [!TIP]
> Veja [`ferror`](#45) e [`feof`](#44).

---

#### int feof(FILE\*)
###### 44

* Comportamento: verifica se o *indicador de final de arquivo* de `FILE*` está definido.
* Retorno: em caso de sucesso, um valor diferente de `0`, do contrário, `0`.

> [!NOTE]
> Esse indicador é definido por qualquer função de leitura de *fluxo* (como [`fgetc`](#25))
> que tente ler o final do arquivo ou além dele.

> [!TIP]
> As seguinte funções redefinem esse indicador: [`clearerr`](#43), [`rewind`](#42),
> [`fseek`](#39), [`fsetpos`](#40) ou [`freopen`](#8).

---

#### int ferror(FILE\*)
###### 45

* Comportamento: verifica se o *indicador de erro* de `FILE*` está definido.
* Retorno: em caso de sucesso, um valor diferente de `0`, do contrário, `0`.

> [!NOTE]
> Esse indicador é definido por qualquer função que seja afetada por alguma falha durante a
> manipulação de um dado *fluxo*.

> [!TIP]
> As seguinte funções redefinem esse indicador: [`clearerr`](#43), [`rewind`](#42) ou
> [`freopen`](#8).

---

#### void perror(const char\*)
###### 46

* Comportamento: converte o código de erro armazenado em [`errno`][errno] em uma mensagem
(cadeia de caracteres) e a imprime em `stderr`, com uma quebra de linha (`'\n'`) como
sufixo.
* Retorno: nenhum.

> [!NOTE]
> Caso `const char*` seja diferente de `NULL`, seu conteúdo será impresso como prefixo a
> mensagem (`": "` os separará); a mensagem gerada depende da plataforma.

---

### Fontes:
* [cplusplus: stdio.h](https://cplusplus.com/reference/cstdio/ )
* [microsoft: fflush](https://learn.microsoft.com/pt-br/cpp/c-runtime-library/reference/fflush?view=msvc-170 )
* [wikipedia: print formats](https://en.wikipedia.org/wiki/Printf#Type_field )
* [cplusplus: example of print formats + format formula](https://cplusplus.com/reference/cstdio/fprintf/ )

---
