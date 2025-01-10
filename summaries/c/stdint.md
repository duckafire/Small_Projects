# stdint
Fornece diversas definições de tipos de inteiros, as quais possuem tamanho variável ou fixo. Além de macros responsável por armazenar o tamanho mínimo e máximo de cada um desses tipos.

<br>

> [!TIP]
> Diferença entre [`stdint.h` e `inttypes.h`](https://stackoverflow.com/questions/7597025/difference-between-stdint-h-and-inttypes-h "Stackoverflow")

<br>

> [!TIP]
> Tipos prefixados por `u`, como `uint8_t`, são `unsigned` (o mesmo para macros prefixadas por `U`).

<br>

### Inteiros

##### Tipos

<br>

| Assinado  | Não assinado |
| :-:       | :-:          |
| intmax\_t | uintmax\_t   |

> Inteiros com a largura máxima suportada.

<br>


| Assinado | Não assinado |
| :-:      | :-:          |
| int8\_t  | uint8\_t     |
| int16\_t | uint16\_t    |
| int32\_t | uint32\_t    |
| int64\_t | uint64\_t    |

> Inteiros com largura fixa (em *bytes*) de 8, 16, 32 e 64.

<br>

| Assinado        | Não assinado     |
| :-:             | :-:              |
| int\_least8\_t  | uint\_least8\_t  |
| int\_least16\_t | uint\_least16\_t |
| int\_least32\_t | uint\_least32\_t |
| int\_least64\_t | uint\_least64\_t |

> Inteiros com largura mínima (em *bytes*) de 8, 16, 32 e 64.

<br>

| Assinado        | Não assinado     |
| :-:             | :-:              |
| int\_fast8\_t   | uint\_fast8\_t   |
| int\_fast16\_t  | uint\_fast16\_t  |
| int\_fast32\_t  | uint\_fast32\_t  |
| int\_fast64\_t  | uint\_fast64\_t  |

> Inteiros com largura máxima (em *bytes*) de 8, 16, 32 e 64.

<br>

| Assinado  | Não assinado |
| :-:       | :-:          |
| intptr\_t | uintptr\_t   |

> Tipo inteiro capaz de armazenar valores oriundos de ponteiros `void`.

<br>

##### Macros

| Mínimo                | Máximo                | Valor **estimado**                  |
| :-:                   | :-:                   | :-:                                 |
| INTMAX\_MIN           | INTMAX\_MAX           | (-)9.223.372.036.854.775.807        |
| -                     | UINTMAX\_MAX          | 18.446.744.073.709.551.615          |
| INT**N**\_MIN         | INT**N**\_MAX         | exatamente (-)(2 ^ (**N** - 1)) - 1 |
| -                     | UINT**N**\_MAX        | exatamente (2 ^ **N**) - 1          |
| INT\_LEAST**N**\_MIN  | INT\_LEAST**N**\_MAX  | (-)(2 ^ (**N** - 1)) - 1            |
| -                     | UINT\_LEAST**N**\_MAX | (2 ^ **N**) - 1                     |
| INT\_FAST**N**\_MIN   | INT\_FAST**N**\_MAX   | (-)(2 ^ (**N** - 1)) - 1            |
| -                     | UINT\_FAST**N**\_MAX  | (2 ^ **N**) - 1                     |
| INTPTR\_MIN           | INTPTR\_MAX           | (-)32.767                           |
| -                     | UINTPTR\_MAX          | 65535                               |

<br>

> [!NOTE]
> **N** é referente aos valores 8, 16, 32 e 64, logo cada macro com **N** possui três variante com valores distintos.

<br>

### Outros

##### Macros

<br>

| Tipo           | Mínimo           | Máximo           | Valor **estimado**   |
| :-:            | :-:              | :-:              | :--                  |
| size\_t        |                  | SIZE\_MAX        | 18446744073709551615 |
| ptrdiff\_t     | PTRDIFF\_MIN     | PTRDIFF\_MAX     | (-)65535             |
| sig\_atomic\_t | SIG\_ATOMIC\_MIN | SIG\_ATOMIC\_MAX | (-)127 se `sig_atomic_t` for assinado; 0, 255 caso contrário |
| wchar\_t       | WCHAR\_MIN       | WCHAR\_MAX       | (-)127 se `wchar_t` for assinado; 0, 255 caso contrário      |
| wint\_t        | WINT\_MIN        | WINT\_MAX        | (-)32767 se `wint_t` for assinado; 0, 65535 caso contrário   |

<br>

##### Macross-função

<br>

| Idetificador | Descrição |
| :-:          | :--       |
| INTMAX\_C    | expande um inteiro do tipo `intmax_t`      |
| UINT\_MAX\_C | expande um inteiro do tipo `uintmax_t`     |
| INT**N**\_C  | expande um inteiro do tipo `int_leastN_t`  |
| UINT**N**\_C | expande um inteiro do tipo `uint_leastN_t` |

<br>

> [!NOTE]
> **N** é referente aos valores 8, 16, 32 e 64, logo cada macro com **N** possui três variante com valores distintos.

<br>

#### Fontes:
* [wikibooks: stdint.h](https://en.wikibooks.org/wiki/c_programming/stdint.h )
* [cplusplus: types and macros list](https://cplusplus.com/reference/cstdint/ )
* [cppreference: full types and macros list](https://en.cppreference.com/w/cpp/types/integer )

<hr>
