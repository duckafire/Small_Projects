# io
Oferece dois estilos diferentes de manipulação de arquivos:
  * Descritores **imprícitos**: <br>
&emsp; Os quais executam operações para definir um arquivo padrão de entrada e saída, centralizando esses respectivos eventos nele. Ela é fornecida por `io.`.
  * Descritores **explícitos**: <br>
&emsp; Para usar estes, se faz necessário atribuir um retorno válido de `io.open` à alguma variável, o que irá permitir que tal variável tenha acesso aos seguintes métodos:

| Método       | Parâmetro | Descrição |
| :-:          | :-:       | :-:       |
| file:close   | Nenhum    | Fecha `file`. A coleta de lixo também pode fechar arquivos, mas em momentos imprevísiveis. Retornará os mesmos valores de `os.execute`, caso feche um arquivo retornado de `io.open`. |
| file:flush   | Nenhum    | Salva os dados escritos em `file`. |
| file:lines   | (...)     | Retorna uma **função interadora** (usável em `for`), que lê `file` à cada chamada, de acordo com os formatos fornecidos (`""` por padrão). Não fecha o arquivo ao fim do *loop*, ao contrário de `io.lines`. |
| file:read    | (...)     | Lê `file` e retorna valores de acordo com os formatos especificados (os quais encontram-se na tabela abaixo desta). |
| file:seek    |  |           |
| file:setvbuf |  |           |
| file:write   |  |           |

##### Formatos de leitura

| Nomes    | Descrição |
| :-:      | :-:       |
| "n"      | Lê um numeral (que pode ter espaços em branco À esquerda e/ou um sinal) e o retorna como `int` ou `float`, seguindo as regras lexicais de LUA. Preferenciamente a sequência mais longa (max: 200). Gerará uma falha, em caso de invalidez. |
| "a"      | Lê `file` por inteiro, iniciando na posição corrente. No fim de `file`, retornará a cadeia de caracteres vazia; nunca falha. |
| "l"      |  |
| "L"      |  |
| "number" |  |

> `file` é uma variável de exemplo (ela armazena um retorno de `io.open`).

### Descritores padrão
A tabela `io` fornece três descritores de arquivos pré-definidos, derivados de C, os quais nunca são fechados.
| Nomes  | Descrição                                                                                 |
| :-:    | :-:                                                                                       |
| stdin  | Fornece uma leitura de fluxo de entrada, gerada, por exemplo, por um teclado              |
| stdout | Fornece, para exibição, determinados dados para *dispositivos* de saída, como o *console* |
| stderr | Fluxo padrão para mensagens de erro fatais, as quais são exibidas no *console*            |

> Em caso de falha, ambas as funções retornarão `nil`, uma mensagem de erro e um código de erro (que vária de acordo com o *OS*).
> Em sistemas não [*Posix*](https://pt.wikipedia.org/wiki/POSIX "Wikipédia: O que é Posix?"), caso hajam muitos fluxos em execução, as mensagens de erro (em caso de falha) por
não ser seguras, tendo em vista que tais mensagens dependem da variável global `errno`, de C.

## Funções
* [](#1)

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

###### 1
* name(parameter1, parameter2)
	* parameter1: blank. | parameter2: blank.
	* Usos: Blank.
	* Retorno: Blank.

``` lua

```

<br>

-----
* ###### [Para o topo](#io)
-----
<br>

#### Fontes:
* https://lua.org/manual/5.4/

<br>

-----
* ###### [Para o topo](#io)
-----
