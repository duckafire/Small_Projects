# locale
Disponibiliza ferramentas para o controle da localização da aplicação.

---

## Índice

* [Macros](#1)
* [`struct lconv`](#2)
* [Funções](#3)
	* [`setlocale`](#3-1)
	* [`localeconv`](#3-2)
---

### Macros
###### 1

* As macros servem para definir quais funções do *Padrão C* serão afetadas pela alteração
na localização (por [`setlocale`](#3-1)).
	* `LC_ALL`: todos abaixo.
	* `LC_COLATE`: comparações de cadeias de caracteres.
	* `LC_CTYPE`: classificação e conversão.
	* `LC_MONETARY`: formato monetário para `localeconv`.
	* `LC_NIMERIC`: separador decimal para `localconv`.
	* `LC_TIME`: para formação de data e hora com `strftime`.
	* `LC_MESSAGES`: respostas do sistema.

---

### struct lconv
###### 2

* Intuito: armazenar informações relacionadas a localização.
* Membros:

#### Formatos numéricos não monetários

| Identificador  | Intuito |
| :--            | :--     |
| decimal\_point | caractere usado como ponto decimal. |
| thousands\_sep | caractere usado como ponto milhar. |
| grouping       | tamanhos dos grupos de dígitos (ex: `"320" -> 111.11`). |

#### Formatos numéricos monetários

| Identificador       | Intuito |
| :--                 | :--     |
| mon\_decimal\_point | caractere usado como ponto decimal. |
| mon\_thousands\_sep | caractere usado como ponto milhar. |
| mon\_grounping      | tamanho dos grupos de dígitos |
| positive\_sign      | cadeia dada a valores não negativos. |
| negative\_sign      | cadeia dada a valores negativos. |

#### Formatos monetários locais

| Identificador     | Intuito |
| :--               | :--     |
| currency\_symbol  | cadeia utilizada como símbolo monetário pela localidade atual. |
| frac\_digits      | número de dígitos após um ponto decimal. |
| p\_cs\_procedes   | `1` se `currency_symbol` for colocado antes de um valor não negativo, `0` caso contrário. |
| n\_cs\_procedes   | `1` se `currency_symbol` for colocado antes de um valor negativo, `0` caso contrário. |
| p\_sep\_by\_space | separação entre `currency_symbol`, `positive_sign` e um valor não negativo. |
| n\_sep\_by\_space | separação entre `currency_symbol`, `negative_sign` e um valor negativo. |
| p\_sign\_posn     | posição de um `positive_sign` em um valor não negativo. |
| n\_sign\_posn     | posição de um `negative_sign` em um valor negativo. |

#### Formatos monetários internacionais

| Identificador          | Intuito |
| :--                    | :--     |
| int\_curr\_symbol      | cadeia utilizada como símbolo monetário internacional pela moeda da localidade atual. |
| int\_frac\_digits      | número de dígitos após um ponto decimal. |
| int\_p\_cs\_procedes   | `1` se `int_curr_symbol` for colocado antes de um valor não negativo, `0` caso contrário. |
| int\_n\_cs\_procedes   | `1` se `int_curr_symbol` for colocado antes de um valor negativo, `0` caso contrário. |
| int\_p\_sep\_by\_space | separação entre `int_curr_symbol`, `positive_sign` e um valor não negativo. |
| int\_n\_sep\_by\_space | separação entre `int_curr_symbol`, `negative_sign` e um valor negativo. |
| int\_p\_sign\_posn     | posição de um `positive_sign` em um valor não negativo. |
| int\_n\_sign\_posn     | posição de um `negative_sign` em um valor negativo. |

> [!NOTE]
> Todos os membros são ponteiros dos tipo `char`.

---

### Funções
###### 3

#### char\* setlocale(int, const char\*)
###### 3-1

* Comportamento: define ou obtém a localização atual do programa.
* Retorno: se `const char*` for diferente de `NULL`, retornará uma cadeia de caracteres
associada a localização definida, do contrário a cadeia representará a localização atual.
Se `int` e/ou `const char*` forem inválidos, retornará `NULL`.

> [!NOTE]
> Use [estas macros](#2) como argumeto para `int`.

---

#### struct lconv\* localeconv(void)
###### 3-2

* Comportamento: obtém o endereço da localização atual.
* Retorno: um ponteiro para uma estrutura contendo os dados da localização atual.

---

### Fontes:
* [wikibooks: locale.h](https://en.wikibooks.org/wiki/C_Programming/locale.h )
* [cppreference: struct lconv](https://en.cppreference.com/w/c/locale/lconv )
* [tutorialspoint: macros](https://www.tutorialspoint.com/c_standard_library/c_function_setlocale.htm )
* [cppreference: localeconv](https://en.cppreference.com/w/c/locale/localeconv )
* [microsoft: setlocale](https://learn.microsoft.com/pt-br/cpp/c-runtime-library/reference/setlocale-wsetlocale?view=msvc-170 )

---
