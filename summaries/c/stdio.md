# stdio
Fornece várias funções para a manipulação de fluxos de entrada e saída (E/S), provindos de teclados, impressoras, terminais e qualquer outro tipo de arquivo suportado pelo sistema.

<hr>

> BUFSIZ: tamanho do *buffer* usado pela função <a href="9"><code>setbuf</code></a>. <br>
> EOF: caractere de fim de arquivo. <br>
> FILENAME\_MAX: largura máxima do nome de um arquivo. <br>
> FOPEN\_MAX: limite de arquivos abertos em simultâneo. <br>
> L\_tmpnam: largura mínima do nome de um arquivo temporário. <br>
> TMP\_MAX: limite de arquivos temporários abertos em simultâneo. <br>

<br>

> [!NOTE]
> Também são fornecidas macros para trabalhar com funções especificas, sendo elas: <a href="#10">_IOFBF, _IOLBF, _IONBF (para <code>setvbuf</code>)</a>; <a href="#39">SEEK_SET, SEEK_CUR, SEEK_END (para <code>fseek</code>)</a>.

<br>

<hr>

> fpos\_t: estrutura designada à armazenar informações sobre a posição atual do *cursor* de um arquivo.
> FILE: estrutura responsável por armazenar o *fluxo* (*de dados*), vulgo *stream*, de um determinado arquivo. Estado do arquivo (aberto ou fechado), <a href="#file-mode">modo de interação</a>, posição do *cursor* de leitura e/ou escrita são algumas das informações armazenadas neste. Seus valores são iniciados por funções deste cabeçalho, como <a href="#7"><code>fopen</code></a>.

<br>

> [!IMPORTANT]
> O conteúdo de `FILE` **não é um arquivo**, mas sim um *fluxo de dados* (vulgo *stream*), capaz de manipular um dado arquivo.

<br>

> [!NOTE]
> O termo *cursor*, no contexto deste documento, refere-se a posição onde o próximo caractere será escrito ou a posição em que está o próximo caractere a ser lido.

<br>

> [!NOTE]
> `FILE` não precisa ser um ponteiro, entretanto as funções detsa biblioteca o aceitam e retornam apenas como ponteiro.

<br>

> [!TIP]
> Funções cujos identificadores iniciam com `f` exigem um ponteiro, do tipo `FILE`, como argumento (exceto <a href="#7"><code>fopen</code></a>).

<br>

> [!TIP]
> *Buffer* pode ser definido como: um espaço de memória temporário criado para armazenar dados até que eles sejam devidamente processados ou copiados para um determinado local. Veja mais sobre [aqui](https://stackoverflow.com/questions/27993971/understanding-buffering-in-c#27994228 "Stackoverflow").

<br>

* Como padrão, este cabeçalho disponibiliza três *fluxos*, que são abertos e fechados automaticamente após a respectiva inicialização e finalização do programa. São eles:
	* `stdin`: armazenar as entradas do usuário (geralmente teclado).
	* `stdout`: armazenar as saída dos programas. Na maioria dos sistemas, seu conteúdo é direcionado ao console (geralmente na tela).
	* `stderr`: armazenar as saída de erros e avisos dos programas. Na maioria dos sistemas, seu conteúdo é direcionado ao console (geralmente na tela).

<br>

> [!NOTE]
> "Fechar", manualmente, qualquer um desses "arquivos" acarretará em erros ao tentar utilizar algumas das funções deste cabeçalho.

<br>

<hr>

|                            |                           |                             |  FUNÇÕES                  |                          |                           |                            |
| :-:                        | :-:                       | :-:                         | :-:                       | :-:                      | :-:                       | :-:                        |
| **Operações com arquivos** | **Acesso a arquivos**     | **E/S formatada**           | **E/S de caracteres**     | **E/S direta**           | **Posição do cursor**     | **Manipulação de erros**   |
| <a href="#1">remove</a>    | <a href="#5">fclose</a>   | <a href="#11">fprintf</a>   | <a href="#25">fgetc</a>   | <a href="#36">fread</a>  | <a href="#38">fgetpos</a> | <a href="#43">clearerr</a> |
| <a href="#2">rename</a>    | <a href="#6">fflush</a>   | <a href="#12">fscanf</a>    | <a href="#26">fgets</a>   | <a href="#37">fwrite</a> | <a href="#39">fseek</a>   | <a href="#44">feof</a>     |
| <a href="#3">tmpfile</a>   | <a href="#7">fopen</a>    | <a href="#13">printf</a>    | <a href="#27">fputc</a>   |                          | <a href="#40">fsetpos</a> | <a href="#45">ferror</a>   |
| <a href="#4">tmpnam</a>    | <a href="#8">freopen</a>  | <a href="#14">scanf</a>     | <a href="#28">fputs</a>   |                          | <a href="#41">ftell</a>   | <a href="#46">perror</a>   |
|                            | <a href="#9">setbuf</a>   | <a href="#15">snprintf</a>  | <a href="#29">getc</a>    |                          | <a href="#42">rewind</a>  |                            |
|                            | <a href="#10">setvbuf</a> | <a href="#16">sprintf</a>   | <a href="#30">getchar</a> |                          |                           |                            |
|                            |                           | <a href="#17">sscanf</a>    | <a href="#31">gets</a>    |                          |                           |                            |
|                            |                           | <a href="#18">vfprintf</a>  | <a href="#32">putc</a>    |                          |                           |                            |
|                            |                           | <a href="#19">vfscanf</a>   | <a href="#33">putchar</a> |                          |                           |                            |
|                            |                           | <a href="#20">vprintf</a>   | <a href="#34">puts</a>    |                          |                           |                            |
|                            |                           | <a href="#21">vscanf</a>    | <a href="#35">ungetc</a>  |                          |                           |                            |
|                            |                           | <a href="#22">vsnprintf</a> |                           |                          |                           |                            |
|                            |                           | <a href="#23">vsprintf</a>  |                           |                          |                           |                            |
|                            |                           | <a href="#24">vsscanf</a>   |                           |                          |                           |                            |

<br>

### Operações com arquivos

<h4 id="1">int remove(const char*)</h4>

* Comportamento: deleta um arquivo, ou um directório vazio, de nome `const char*`.
* Retorno: `0` em caso de sucesso ou um valor diferentes de `0`, caso contrário.

<hr>

<h4 id="2">int rename(const char 0*, const char 1*)</h4>

* Comportamento: renomeia um arquivo, ou um directório, de nome `const char 0*` para `const char 1*`.
* Retorno: `0` em caso de sucesso ou um valor diferentes de `0`, caso contrário.

<hr>

<h4 id="3">FILE* tmpfile(void)</h4>

* Comportamento: cria um arquivo binário temporário em <a href="#file-mode">modo</a> `"wb+"`, com um nome garantidamente diferentes dos demais arquivos existentes.
* Retorno: o ponteiro (`FILE`) do arquivo temporário criado ou `NULL`, em caso de falha.

<br>

> [!NOTE]
> O arquivo será automaticamente deletado após ser fechado (com <a href="#5"><code>fclose</code></a>) ou após o programa ser encerrado com sucesso. Caso o programa seja execerrado anomalamente, a elimitação do arquivo temporário criado dependerá do sistema e da implementação da biblioteca.

<br>

<hr>

<h4 id="4">char* tmpnam(char*)</h4>

* Comportamento: gera um nome de arquivo único e armazena-o em `char*`.
* Retorno: o endereço de `char*`, caso a mesma seja diferente de `NULL`, do contrário, retorna o endereço de uma variável estática (que contem o nome gerado), cujo valor é alterado a cada nova chamada de `tmpnam`.

<br>

> [!CAUNTION]
> Dado que entre a definição de `char*` e seu uso (por exemplos em <a href="#7"><code>fopen</code></a>), um arquivo de mesmo nome pode ser gerado por outro programa ou, até mesmo, por um agente malicioso (causando assim conflitos e vazamentos de dados), seu uso é desencorajado. *Recomendo* o uso de <a href="3"><code>tmpfile</code></a> em seu lugar, pois tal função criar o arquivo temporário imediatamente após gerar seu nome único.

<br>

> [!NOTE]
> `char*` deve ser uma cadeia de caracteres com largura igual a `L_tmpnam`, por exemplo: `char foo[L_tmpnam]`.

<br>

<hr>

<br>

### Acesso a arquivos

<h4 id="5">int fclose(FILE*)</h4>

* Comportamento: encerra um *fluxo* (`FILE`), desassociando-o totalmente do arquivo a qual ele, anteriormente, tinha acesso e liberando o espaço que foi ocupado na memória. Descartando o conteúdo salvo no *buffer* de entrada e escrevendo (no arquivo) o conteúdo armazenado no *buffer* de saída.
* Retorno: `0` em caso de sucesso ou `EOF`, caso contrário.

<br>

> [!IMPORTANT]
> Mesmo que a chamada falhe, o `FILE*` perderá acesso ao arquivo (que estava sob sua posse) e aos *buffers* do mesmo.

<br>

> [!NOTE]
> Após seu uso: o conteúdo presente no *buffer* de entrada, do *fluxo* em questão, será descartado; o conteúdo presente no *buffer* de saída será escrito no arquivo antes associado ao *fluxo*.

<br>

<hr>

<h4 id="6">int fflush(FILE*)</h4>

* Comportamento: força a gravação dos dados presentes no *buffer* de saída  (de `FILE*`) no arquivo sob sua custodia, mas apenas caso `FILE*` esteja em <a href="#file-mode">modo</a> `"w"` ou `"a"` (e sua última operação de E/S tenha sido de entrada), caso contrário, nada ocorrerá. Se `FILE*==NULL`, sua chamada afetará todos os *buffers* abertos, em todos os fluxos, que sejam compatíveis com as exigências antes citadas.
* Retorno: `0` caso a operação seja bem sucedida,' `FILE*` não se encaixe nas exigências ou caso `FILE*` não possua nenhum *buffer*. Em caso de falha, retornará `EOF`.

<hr>

<h4 id="7">FILE* fopen(const char 0*, const char 1*)</h4>

* Comportamento: associado `FILE*` (em *fluxo*) a um arquivo com nome `const char 0*`, em <a href="#file-mode">modo</a> `const char 1*`.
* Retorno: *fluxo* que foi associado ao arquivo.

<br>

<h5 id="file-mode">Modos de abertura</h5>

| Modo | Descrição |
| :-:  | :--       |
| "r"  | Abre um arquivo existente para leitura. |
| "w"  | Cria um arquivo para escrita. Caso o arquivo já exista, ele será substituído por um arquivo em branco e seu conteúdo será descartado.                   |
| "a"  | Abre um arquivo, com seu *cursor* posicionado no final do mesmo. Cria o arquivo, caso ele não exista.                                                   |
| "r+" | Abre um arquivo existente para leitura e escrita.                                                                                                       |
| "w+" | Cria um arquivo para leitura e escrita. Caso o arquivo já exista, ele será substituído por um arquivo em branco e seu conteúdo será descartado.         |
| "a+" | Abre um arquivo existente para leitura e escrita, onde (apenas) a posição de escrita é fixada no final do arquivo. Cria o arquivo, caso ele não exista. |

<br>

> [!IMPORTANT]
> As cadeias de caracteres acima permitem abrir arquivos em formato de texto, para abri-los em formato binário basta sufixar suas cadeias com `'b'` (`"rb"`, `"r+b"`, `"rb+"`, ...), seja antes ou após o `'+'`.

<br>

> [!NOTE]
> Caso o arquivo em questão não refira-se a um dispositivo interativo, o *fluxo* será, por padrão, __*full buffering*__ (veja <a href="#10"><code>setvbuf</code></a>).

<br>

<hr>

<h4 id="8">FILE* freopen(const char 0*, const char 1*, FILE*)</h4>

* Comportamento: se `const char 0*!=NULL`, associa o arquivo de nome `const char 0*` a `FILE*`, em <a href="#file-mode">modo</a> `const char 1*`; se `const char 0*==NULL`, altera o <a href="#file-mode">modo</a> de `FILE*` para `const char 1*`.
* Retorno: `FILE*` ou `NULL`, em caso de falha.

<br>

> [!IMPORTANT]
> Diferentes implementações desta biblioteca podem adicionar restrições e condições para a troca de <a href="#file-mode">modo</a> do *fluxo* (`FILE*`).

<br>

> [!NOTE]
> Antes da associação ocorrer, caso hajam outro arquivo associado a `FILE*`, `freopen` **tentará** desassociá-lo.

<br>

> [!NOTE]
> Após a operação, os *indicador de error* e *indicador de final no arquivo*, de `FILE*`, serão "limpos" (como se <a href="#43"><code>clearerr</code></a> tivesse sido chamado).

<br>

> [!TIP]
> Chamar `freopen("log.txt", "w", stdout)` direcionará todas as saídas de funções como <a href="#13"><code>printf</code></a> para o arquivo `log.txt`, ao invés do terminal. Já chamar `freopen("data.txt", "r", stdin)` fará com que chamadas de funções como <a href="#30"><code>getchar</code></a> busquem os caracteres de `data.txt` ao invés de coletarem o conteúdo digitado pelo usuário no terminal.

<br>

<hr>

<h4 id="9">void setbuf(FILE*, char*)</h4>

* Comportamento: associa `char*` como *buffer* para `FILE*`, baseado no seu <a href="#file-mode">modo</a>.
* Retorno: nenhum.

<br>

> [!IMPORTANT]
> Esse função deve ser usadas após `FILE*` ser associado ao seu arquivo e antes de qualquer operação de E/S ocorrer em `FILE*`.

<br>

> [!TIP]
> Um *buffer de fluxo* (*de dados*), vulgo *stream buffer*, é um bloco de dados que atua como intermediário entre operações de E/S e um dado arquivo, onde: para saídas, o *buffer* irá gravar os valores no arquivo após chegar ao limite de sua capacidade de armazenamento, limpando-se logo após a operação de gravação ser finalizada; para entradas, o *buffer* recebe o conteúdo do arquivo até estourar sua capacidade (*full buffering*) ou obter uma quebra de linha (*line buffering*), passando-os para os agentes que o solicitaram e limpando-se em seguida.

<br>

> [!TIP]
> Uma chamada dessa função é equivalente a chamar <a href="#10"><code>setvbuf</code></a> usando `_IOFBF` como modo e `BUFSIZ` como tamanho.

<br>

<hr>

<h4 id="10">int setvbuf(FILE*, char*, int, size_t)</h4>

* Comportamento: executa o mesmo trabalho de <a href="#9"><code>setbuf</code></a>, com o acréssimo de permitir especificar o *modo* (`int`) de *bufferização* de `FILE*` e o tamanho (`size_t`) do *buffer* que será criado.
* Retorno: `0` em caso de sucesso ou um valor diferentes de `0`, caso contrário.

<br>

<h5 id="buf-mode">Modos de *bufferização*</h5>

| Macro   | Nome             | Entrada | Saída |
| :-:     | :-:              | :--     | :--   |
| \_IOFBF | *Full buffering* | Quando uma operação de entrada é solicitada e o *buffer* está vazio. | Quando o *buffer* atinge seu limite ou após <a href="#6"><code>fflush</code></a> ser usado. |
| \_IOLBF | *Line buffering* | Quando uma quebra de linha é obtida, uma operação de entrada é solicitada e o *buffer* está vazio. | Quando um caractere de quebra de linha (`'\n'`) é inserido ou quando o *buffer* chega ao seu limite. |
| \_IONBF | *No buffering*   | O conteúdo é retirado diretamente do arquivo. | O conteúdo é lido diretamente do arquivo. |

<br>

> [!IMPORTANT]
> O valor de `size_t` só será relevante caso `char*==NULL && (int==_IOFBF || int==_IOLBF)`.

<br>

> [!IMPORTANT]
> Esse função deve ser usadas após `FILE*` ser associado ao seu arquivo e antes de qualquer operação de E/S ocorrer em `FILE*`.

<br>

> [!NOTE]
> `int==_IONBF` fará com que `char*` e `size_t` sejam ignorados.

<br>

> [!TIP]
> Um *buffer de fluxo* (*de dados*), vulgo *stream buffer*, é um bloco de dados que atua como intermediário entre operações de E/S e um dado arquivo, onde: para saídas, o *buffer* irá gravar os valores no arquivo após chegar ao limite de sua capacidade de armazenamento, limpando-se logo após a operação de gravação ser finalizada; para entradas, o *buffer* recebe o conteúdo do arquivo até estourar sua capacidade (*full buffering*) ou obter uma quebra de linha (*line buffering*), passando-os para os agentes que o solicitaram e limpando-se em seguida.

<br>

<hr>

<br>

### E/S formatada

<h5 id="print-format">Formatos de impressão</h5>

* Estas são combinações de caracteres estruturadas da seguinte maneira: `%[bandeira][largura][.[precisão]][comprimento]especificador`

| Especificador | Descrição                                 | Exemplo      |
| :-:           | :--                                       | :-:          |
| %             | O caractere `'%'`                         | %            |
| a/A           | Hexadecimal de ponto flutuante            | -0xc.90fep-2 |
| c             | Um caractere qualquer                     | a            |
| d/i           | Inteiros decimais assinados               | 29           |
| e/E           | Notação científica (mantissa/expoente)    | 3.9265e+2    |
| f/F           | Decimais de ponto flutuante               | 28.1         |
| g/G           | Representação curta de um valor           | 13.18        |
| n             | Não imprime nada, mas escreve o número de caracteres escritos, até o momento, em "seus" argumento respectivo, que deve ser um inteiro assinado |  |
| o             | Inteiros octais não assinados             | 7            |
| p             | Endereço de um ponteiro                   | 0xa50b5a37   |
| s             | Cadeia de caracteres terminada com `'\0'` | exemplo      |
| u             | Inteiros decimais não assinados           | 409          |
| x/X           | Inteiros hexadecimais não assinados       | 0xf          |

<br>

> [!IMPORTANT]
> Diferença entre os caracteres maiúsculos e minúsculos: maiúsculos imprimem apenas letras maiúsculos (`0xA`); minúsculos imprimem apenas letra minúsculas (`0xa`). Para `f/F` a diferença entre ambos evidencia-se ao tentar imprimir `INF`, `INFINITY` e/ou `NAN`.

<br>

> [!IMPORTANT]
> Para saída `d` e `i` são sinônimos, mas para entrada, por exemplo com <a href="#14"><code>scanf</code></a>, diferenciam-se no fato de que `i` interpetará valores iniciados com `0x` como hexadecimais, valores iniciados com `0` como obtais e os demais como decimais, já `d` irá intepretar todos como sendo decimais. **Ambos inteiros**.

<br>

> [!TIP]
> Funções que suportam estes formatos contam com um *"parâmetro variável"* (`...`), que é reponsável por armazenar os valores que serão postos no lugar das *combinações*, sendo capaz de armazenar um número indefinido de valores. As substituições ocorrem ordenadamente, ou seja, a primeira *combinação* será substituída pelo primeira valor armazenado no *"parâmetro variável"*, a segunda pelo segundo e assim por diante, até que o número máximo de um dos dois seja alcançado.

<br>

| Bandeira | Descrição                                                                            |
| :-:      | :--                                                                                  |
| -        | Altera a posição de incremento para a direita (o incremento será feito com espaços). |
| +        | Prefixas valores numéricos positivos com `+` e negativos com `-` (o último é padrão).|
| *espaço* | Incrementa à esquerda de um dado valor com espaços, até que sua *largura* seja igual a que foi especificada. Mesmo que nenhuma *largura* seja especifícada um espaço adicional será adicionado para valores positivos. |
| #        | Para os *especificadores* `o/x/X` prefixa valores, diferentes de `0`, por, respectivamente, `0/0x/0X`. Já para `aAeEfFgG` força a impressão de um ponto decimal, mesmo que não hajam valores após ele.|
| 0        | Incrementa à esquerda de um dado valor com zeros, até que sua *largura* seja igual a que foi especificada. Caso nenhuma *largura* seja especifícada, nada ocorrerá. |

<br>

| Largura | Descrição                                                                                                                  |
| :-:     | :--                                                                                                                        |
| n       | Inteiro contendo a largura, em quatidade de digitos, do valor a ser imprimido. Não quebra valores que ultrapassam o limite.|
| *       | Indica que a largura será especificada por um argumento que prefixará o valor a ser imprimido.                             |


<br>

| Precisão | Descrição                                 |
| :-:      | :--                                       |
| n        | Para `d/i/o/u/x/X` é equivalente a *largura n*; para `a/A/e/E/f/F` indica quantos números devem ser escritos após a vírgula (`6` por padrão); para `g/G` é a quatidade máxima de digitos significativos para impressão; para `s` é o número de caracteres a ser imprimido (por padrão imprimirá até `'\0'` ser encontrado); se apenas o `'.'` for especificado, `0` será usado para padrão. |
| *        | Indica que a largura será especificada por um argumento que prefixará o valor a ser imprimido. |

<br>

> Responsável por modificar o comprimento de um tipo de dado.

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

<br>

> [!TIP]
> Caso o valor destinado a `"%s"`/`"%p"` seja `NULL`, `"(null)"`/`"(nil)"` será impresso.

<br>

<h4 id="11">fprintf</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="12">fscanf</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="13">printf</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="14">scanf</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="15">snprintf</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="16">sprintf</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="17">sscanf</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="18">vfprintf</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="19">vfscanf</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="20">vprintf</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="21">vscanf</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="22">vsnprintf</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="23">vsprintf</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="24">vsscanf</h4>

* Comportamento:
* Retorno:

<hr>

<br>

### E/S de caracteres

<h4 id="25">fgetc</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="26">fgets</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="27">fputc</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="28">fputs</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="29">getc</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="30">getchar</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="31">gets</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="32">putc</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="33">putchar</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="34">puts</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="35">ungetc</h4>

* Comportamento:
* Retorno:

<hr>

<br>

### E/S direta

<h4 id="36">fread</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="37">fwrite</h4>

* Comportamento:
* Retorno:

<hr>

<br>

### Posição do cursor

<h4 id="38">fgetpos</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="39">fseek</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="40">fsetpos</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="41">ftell</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="42">rewind</h4>

* Comportamento:
* Retorno:

<hr>

<br>

#### Manipulação de erros

<h4 id="43">clearerr</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="44">feof</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="45">ferror</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="46">perror</h4>

* Comportamento:
* Retorno:

<hr>

<br>

### Fontes:
* [cplusplus: stdio.h](https://cplusplus.com/reference/cstdio/ )
* [microsoft: fflush](https://learn.microsoft.com/pt-br/cpp/c-runtime-library/reference/fflush?view=msvc-170 )
* [wikipedia: print formats](https://en.wikipedia.org/wiki/Printf#Type_field )
* [cplusplus: example of print formats + format formula](https://cplusplus.com/reference/cstdio/fprintf/ )

<hr>
