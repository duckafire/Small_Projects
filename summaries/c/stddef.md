# stddef
Define um conjunto de tipos e macros comumente utilizados por outras bibliotecas do
*Padrão C*.

---

| Tipo       | Valor                                              |
| :--        | :--                                                |
| ptrdiff\_t | Tipo inteiro com tamanho suficiente para armazenar o resultado de
qualquer subtração entre ponteiros. |
| size\_t    | Tipo inteiro com tamanho suficiente para armazenar o comprimento de
qualquer tipo. |
| wchar\_t   | Tipo com tamanho suficiente para armazenar caracteres *multibyte*. |

---

* `NULL`: endereço nulo (`(void*)0`).

* `offsetof(type, member)`: retorna o número de *bytes* de deslocamento anteriores a um
membro específico de uma `struct` ou `union`.
	* `type`: nome da `struct` ou `union`.
	* `member`: membro da `struct` ou `union`.

> [!IMPORTANT]
> Alguns dos usos de `offsetof` incluem o empacotamento de estruturas de dados.
> [Veja](https://www.embedded.com/learn-a-new-trick-with-the-offsetof-macro/ "Sobre 'offsetof'").

---

#### Fontes:
* [tutorialspoint: stddef.h](https://www.tutorialspoint.com/c_standard_library/stddef_h.htm )
* [embedded: tips and trucks to offsetof](https://www.embedded.com/learn-a-new-trick-with-the-offsetof-macro/ )

---
