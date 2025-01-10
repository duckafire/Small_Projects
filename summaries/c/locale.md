# locale
Disponibiliza ferramentas para o controle da localização da aplicação.

<hr>

## Índice

* <a href="#1">Macros</a>
* <a href="#2"><code>struct lconv</code></a>
* <a href="#3">Funções</a>
	* <a href="#3-1"><code>setlocale</code></a>
	* <a href="#3-2"><code>localeconv</code></a>

<hr>

<h3 id="1">Macros</h3>

* As macros servem para definir quais funções do *Padrão C* serão afetadas pela alteração na localização (por `setlocale`).
	* `LC_ALL`: todos abaixo.
	* `LC_COLATE`: comparações de cadeias de caracteres.
	* `LC_CTYPE`: classificação e conversão.
	* `LC_MONETARY`: formato monetário para `localeconv`.
	* `LC_NIMERIC`: separador decimal para `localconv`.
	* `LC_TIME`: para formação de data e hora com `strftime`.
	* `LC_MESSAGES`: respostas do sistema.

<hr>

<h3 id="2">struct lconv</h3>

* Intuito: armazenar informações relacionadas a localização.
* Membros:

#### Formatos numéricos não monetários

| Tipo  | Identificador  | Intuito |
| :-:   | :-:            | :--     |
| char\*| decimal\_point | caractere usado como ponto decimal. |
| char\*| thousands\_sep | caractere usado para separar grupos de numéros anteriores a pontos decimais. |
| char\*| grouping       | cadeia cujos elementos indicam o tamanho de um grupo de digitos. |

#### Formatos numéricos monetários

| Tipo  | Identificador       | Intuito |
| :-:   | :-:                 | :--     |
| char\*| mon\_decimal\_point | caractere usado como ponto decimal. |
| char\*| mon\_thousands\_sep | caractere usado para separar grupos de numéros anteriores a pontos decimais. |
| char\*| mon\_grounping      | cadeia cujos elementos indicam o tamanho de um grupo de digitos. |
| char\*| positive\_sign      | cadeia usada indicar números positivos. |
| char\*| negative\_sign      | cadeia usada indicar números negativos. |

#### Formatos monetários locais

| Tipo  | Identificador     | Intuito |
| :-:   | :-:               | :--     |
| char\*| currency\_symbol  | símbulo usado pela moeda da localização C atual. |
| char  | frac\_digits      | número de digitos após um ponto decimal, para exibir uma quantidade monetária. |
| char  | p\_cs\_procedes   | `1` se `currency_symbol` for colocado antes de um valor positivo, `0` caso contrário. |
| char  | n\_cs\_procedes   | `1` se `currency_symbol` for colocado antes de um valor negativo, `0` caso contrário. |
| char  | p\_sep\_by\_space | separação entre `currency_symbol`, `positive_sign` e um valor monetário positivo. |
| char  | n\_sep\_by\_space | separação entre `currency_symbol`, `negative_sign` e um valor monetário negativo. |
| char  | p\_sign\_posn     | posição de um `positive_sign` em um valor monetário positivo. |
| char  | n\_sign\_posn     | posição de um `negative_sign` em um valor monetário negativo. |

#### Formatos monetários internacionais

| Tipo  | Identificador          | Intuito |
| :-:   | :-:                    | :--     |
| char\*| int\_curr\_symbol      | símbulo usado pela moeda internacional da localização C atual. |
| char  | int\_frac\_digits      | número de digitos após um ponto decimal, para exibir uma quantidade monetária internacional. |
| char  | int\_p\_cs\_procedes   | `1` se `currency_symbol` for colocado antes de um valor positivo internacional, `0` caso contrário. |
| char  | int\_n\_cs\_procedes   | `1` se `currency_symbol` for colocado antes de um valor negativo internacional, `0` caso contrário. |
| char  | int\_p\_sep\_by\_space | separação entre `currency_symbol`, `positive_sign` e um valor monetário positivo internacional. |
| char  | int\_n\_sep\_by\_space | separação entre `currency_symbol`, `negative_sign` e um valor monetário negativo internacional. |
| char  | int\_p\_sign\_posn     | posição de um `positive_sign` em um valor monetário positivo internacional. |
| char  | int\_n\_sign\_posn     | posição de um `negative_sign` em um valor monetário negativo internacional. |

<hr>

<h3 id="3">Funções</h3>

<h4 id="3-1">char* setlocale(int, const char*)</h4>

* Comportamento: define ou obtém a localização atual do programa.
* Retorno: se `const char*` for diferente de `NULL`, retornará uma cadeia de caracteres associada a localização definida, do contrário a cadeia representará a localização atual. Se `int` e/ou `const char*` forem inválidos, retornará `NULL`.

<br>

> [!NOTE]
> Use <a href="#2">estas macros</a> como argumeto para `int`.

<br>

<hr>

<h4 id="3-2">struct lconv* localeconv(void)</h4>

* Comportamento: obtém o endereço da localização atual.
* Retorno: um ponteiro para uma estrutra contento os dados da localização atual.

<hr>

### Fontes:
* [wikibooks: locale.h](https://en.wikibooks.org/wiki/C_Programming/locale.h )
* [cppreference: struct lconv](https://en.cppreference.com/w/c/locale/lconv )
* [tutorialspoint: macros](https://www.tutorialspoint.com/c_standard_library/c_function_setlocale.htm )
* [cppreference: localeconv](https://en.cppreference.com/w/c/locale/localeconv )
* [microsoft: setlocale](https://learn.microsoft.com/pt-br/cpp/c-runtime-library/reference/setlocale-wsetlocale?view=msvc-170 )

<hr>
