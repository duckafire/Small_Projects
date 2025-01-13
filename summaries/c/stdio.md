# stdio
Fornece várias funções para a manipulação de fluxos de entrada e saída (E/S), provindos de teclados, impressoras, terminais e qualquer outro tipo de arquivo suportado pelo sistema.

<hr>

> **Uso geral:**
> BUFSIZ: tamanho do *buffer* usado pela função <a href="9"><code>setbuf</code></a>.
> EOF: caractere de fim de arquivo.
> FILENAME\_MAX: largura máxima do nome de um arquivo.
> FOPEN\_MAX: potencial limite de arquivos abertos em simultâneo.
> L\_tmpnam: largura mínima do nome de um arquivo temporário.
> TMP\_MAX: quantidade de arquivos temporários.

<br>

> <strong>Uso com <a href="#10"><code>setvbuf</code></a></strong>
> \_IOFBF: (<strong><i>full buffering</i></strong>) na saída, os dados são armazenados quando o *buffer* está cheio (ou liberado); na entrada, o *buffer* é preenchido caso uma operação de entrada seja solicitada e o mesmo esteja vazio.
> \_IOLBF: (<strong><i>line buffering</i></strong>) na saída, os dados são armazenados quando um caractere de quebra de linha (`'\n'`) é inserido ou quando o *buffer* está cheio (ou liberado), o que vier primeiro; na entrada, o *buffer* é preenchido, até o primeiro caractere de quebra de linha, após a solicitação de uma operação de entrada, mas apenas caso o mesmo esteja vazio.
> \_IONBF: (<strong><i>no buffering</i></strong>) nenhum *buffer* é usado. Cada operação de E/S é executada o mais depressa possível.

<br>

> <strong>Uso com <a href="#39"><code>fseek</code></a></strong>
> SEEK\_CUR: refere-se a posição inicial do arquivo.
> SEEK\_END: refere-se a posição do *cursor* do arquivo.
> SEEK\_SET: refere-se a posição final do arquivo. 

<hr>

> fpos\_t: estrutura designada à armazenar informações sobre a posição atual do *cursor* de um arquivo.
> FILE: estrutura cujos membros são destinados a conter informações sobre um dado arquivo. Seus valores são iniciados por funções deste cabeçalho, como <a href="#7"><code>fopen</code></a>.

<br>

> [!NOTE]
> O termo *cursor*, no contexto deste documento, refere-se a posição do próximo caractere a ser escrito ou lido.

<br>

> [!NOTE]
> `FILE` não precisa ser um ponteiro, mas isso facilita sua manipulação, logo é fortemente recomendado e disseminado.

<br>

> `stdin`, `stdout` e `stderr` são ponteiros (`FILE`) padrão deste cabeçalho, cuja respectiva finalidade é;
> > armazenar as entradas do usuário (geralmente teclado).
> > armazenar as saída dos programas. Na maioria dos sistemas, seu conteúdo é direcionado ao console (geralmente na tela).
> > armazenar as saída de erros e avisos dos programas. Na maioria dos sistemas, seu conteúdo é direcionado ao console (geralmente na tela).

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

<h4 id="4">remove</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="4">rename</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="4">tmpfile</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="4">tmpnam</h4>

* Comportamento:
* Retorno:

<hr>

<br>

### Acesso a arquivos

<h4 id="5">fclose</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="6">fflush</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="7">fopen</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="8">freopen</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="9">setbuf</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="10">setvbuf</h4>

* Comportamento:
* Retorno:

<hr>

<br>

### E/S formatada

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

<hr>
