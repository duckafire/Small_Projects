# limits
Define constantes responsáveis por delimitar os valores mínimos e máximos de dados tipos
primitivos.

| Tipo                   | Mínimo     | Máximo      | Valor **estimado** |
| :--                    | :--        | :--         | :--              |
| signed char            | SCHAR\_MIN | SCHAR\_MAX  | (-)127           |
| char                   | CHAR\_MIN  | CHAR\_MAX   | \*?              |
| unsigned char          | -          | UCHAR\_MAX  | 255              |
| short int              | SHRT\_MIN  | SHRT\_MAX   | (-)32.767        |
| unsigned short int     | -          | USHRT\_MAX  | 65.535           |
| int                    | INT\_MIN   | INT\_MAX    | (-)32.767        |
| unsigned int           | -          | UINT\_MAX   | 65.535           |
| long int               | LONG\_MIN  | LONG\_MAX   | (-)2.147.483.647 |
| unsigned long int      | -          | ULONG\_MAX  | 4.294.967.295    |
| long long int          | LLONG\_MIN | LLONG\_MAX  | (-)9.223.372.036.854.775.807 |
| unsigned long long int | -          | ULLONG\_MAX | 18.446.744.073.709.551.615 |

* `CHAR_BIT`: Comprimento máximo de uma variável do tipo `char`.
* `MB_LEN_MAX`: Comprimento máximo de um caractere *multibyte* em todas as localidades.

> [!NOTE]
> `*?`: O tamanho estimado de `char` é:
>
> * Mínimo: `SCHAR_MIN` *ou* `0`
> * Máximo: `SCHAR_MAX` *ou* `UCHAR_MAX`

---

#### Fontes:
* [cplusplus: limits.h](https://cplusplus.com/reference/climits/ )

---
