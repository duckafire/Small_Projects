# limits
Define constantes responsáveis por delimitar os valores mínimos e máximos de dados tipos primitivos.

<br>

| Tipo                   | Mínimo     | Máximo      | Valor **estimado**   |
| :--                    | :--        | :--         | :--                  |
| signed char            | SCHAR\_MIN | SCHAR\_MAX  | (-)127               |
| char                   | CHAR\_MIN  | CHAR\_MAX   | (SCHAR\_MIN ou 0)  SCHAR\_MAX ou UCHAR\_MAX |
| unsigned char          | -          | UCHAR\_MAX  | 255                  |
| short int              | SHRT\_MIN  | SHRT\_MAX   | (-)32.767            |
| unsigned short int     | -          | USHRT\_MAX  | 65535                |
| int                    | INT\_MIN   | INT\_MAX    | (-)32.767            |
| unsigned int           | -          | UINT\_MAX   | 65535                |
| long int               | LONG\_MIN  | LONG\_MAX   | (-)2.147.483.647     |
| unsigned long int      | -          | ULONG\_MAX  | 4294967295           |
| long long int          | LLONG\_MIN | LLONG\_MAX  | (-)9.223.372.036.854.775.807 |
| unsigned long long int | -          | ULLONG\_MAX | 18446744073709551615 |

<br>

* CHAR\_BIT: Quantidade de bits necessários para se representar uma variável do tipo char.  
* MB\_LEN\_MAX: Comprimento máximo de vários *bytes* de um caractere em todas as localidades.  

<hr>

#### Fontes:
* [cplusplus: limits.h](https://cplusplus.com/reference/climits/)

<hr>
