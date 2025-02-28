# stdbool
Adiciona 4 macros para explicitar o uso de valores booleanos, assim facilitando a leitura
do código.

---

| Macros   | Valor   |
| :-:      | :-:     |
| `bool`   | `_Bool` |
| `true`   | `1`     |
| `false`  | `0`     |

> A macro `__bool_true_false_are_defined` (`1`) também está inclusa neste cabeçalho.

> [!NOTE]
> `_Bool` é um tipo, com tamanho suficiente para armazenar `0` ou `1`.

---

#### Fontes:
* [wikipedia: stdbool.h](https://en.wikipedia.org/wiki/c_data_types#stdbool.h )

---
