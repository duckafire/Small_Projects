# io
Fornece uma pequena *API* para a manipulação de entradas e saídas.

---

* `io.stdin`: arquivo de entrada padrão.
* `io.stdout`: arquivo de saída padrão.
* `io.stderr`: arquivo de saída responsável por armazenar as mensagens de erro.

---

||Funções||
|:-:|:-:|:-:
|[io.close](#1) |[io.open](#5)  |[io.tmpfile](#9)   |
|[io.flush](#2) |[io.output](#6)|[io.type](#10)     |
|[io.input](#3) |[io.popen](#7) |[io.write](#11)    |
|[io.lines](#4) |[io.read](#8)  |[file:setvbuf(#12)]|

> [!TIP]
> *Fluxos de arquivo* recebem alguns métodos, estes estão destacados com `*`.
> 
> ``` lua
> -- example
> io.close(foo)
> foo:close()
> ```

---

### *io.close([string=io.stdout])
###### 1

* Comportamento: fecha um *fluxo*.
* Retorno: nenhum.

---

### *io.flush()
###### 2

* Comportamento: força que os dados salvos nos *buffers* de `io.stdout` sejam impressos
nele.
* Retorno: nenhum.

---

### io.input([string])
###### 3

* Comportamento: define `string` como o arquivo de entrada padrão.
* Retorno: um valor booleano indicando se a operação foi bem sucedida ou `io.stdout`,
caso `string==nil`.

---

### *io.lines([string=io.stdout, [...="l"]])
###### 4

* Comportamento: abre um arquivo, nomeado como `string`, em *modo de leitura*.
* Retorno: uma função de interação, que executa e retorna valores de acordo com os argumentos presentes em `...` (na ordem em que eles aparecem).

###### Ler

| `...`  | Descrição |
| :-:    |:-:        |
| "n"    | Lê e retorna números (podem haver espaços vazios à esquerda e um sinal) |
| "a"    | Lê o arquivo inteiro, partindo da posição atual.                        |
| "l"    | Lê a linha atual e descarta o caractere de fim da linha.                |
| "L"    | Lê a linha atual e mantém o caractere de fim da linha.                  |
|`number`| Lê um cadeia de caracteres com no máximo `number` *bytes* e a retorna.  |

---

### io.open(string0, [string1="r"])
###### 5

* Comportamento: abre um arquivo, nomeado como `string0`, em modo `string1`.
* Retorno: um *fluxo* ou, em caso de falha, `nil` e uma mensagem de erro.

###### Modos

| `string1` | Descrição |
| :-:       | :--       |
| "r"       | leitura   |
| "w"       | escrita   |
| "a"       | acréscimo |
| "r+"      | atualização (dados anteriores são preservados) |
| "w+"      | atualização (dados anteriores são descartados) |
| "a+"      | atualização de acréscimo (dados anteriores são preservadores; a gravação só pode ocorrer no final do arquivo) |

---

### io.output([string])
###### 6

* Comportamento: define `string` como o arquivo de saída padrão.
* Retorno: O `io.stdout` padrão se `string` for omitido, caso contrário não terá retorno.

---

### io.popen(string0, [string1="r"])
###### 7

* Comportamento: executa `string0`, que deve ser um comando do sistema operacional, e
armazena sua saída em um *fluxo*, o qual tem seu [modo](#Modos) definido por `string1`.
* Retorno: o *fluxo* criado.

> [!IMPORTANT]
> Alguns sistemas operacionais podem não permitir esse tipo de interação.

---

### *io.read(...)
###### 8

* Comportamento: lê o arquivo de entrada padrão, de acordo com os [modos de leitura](#Ler)
fornecidos por `...`.
* Retorno: uma cadeia de caracteres para cada argumento presente em `...`. Caso seja
chamada sem argumentos, retornará qualquer cadeia de caracteres introduzida pela usuário.

> [!TIP]
> Utilize essa função para coletar dados do usuário.
> 
> ``` lua
> local user_input
> 
> user_input = io.read()
> ```

---

### io.tmpfile()
###### 9

* Comportamento: cria um arquivo temporário, que é descartado ao fim do programa.
* Retorno: o *fluxo*, em caso de sucesso.

---

### io.type(variable)
###### 10

* Comportamento: verifica se `variable` armazena um *fluxo*.
* Retorno: `"file"` caso seja um *fluxo* aberto, `"closed file"` caso seja um *fluxo*
fechado ou `nil` caso não seja um *fluxo*.

---

### *io.write(...)
###### 11

* Comportamento: escreve `...` no arquivo de saída padrão.
* Retorno: `io.stdout` ou `nil`, em caso de falha.

---

### file:setvbuf(string, [number])
###### 12

* Comportamento: define o modo de *bufferrização* de `file` em `"no"` (nenhum), `"full"` (completo) ou `"line"` (por linha).
* Retorno: nenhum.

> [!IMPORTANT]
> Ao contrário dos demais métodos dos *fluxos de arquivo*, este não possui uma versão
> equivalente.

---
