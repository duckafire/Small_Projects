# stddef
Define um conjunto de tipos e macros comumente utilizados por outras bibliotecas padrão C.

<hr>

| Tipo       | Valor                                              |
| :--        | :--                                                |
| ptrdiff\_t | Armazena o resultado de um subtração de ponteiros  |
| size\_t    | Armazena o tamanho de objetos em áreas na memória  |
| wchar\_t   | Armazena caracteres com tamanho acima de um *byte* |

<hr>

* NULL: endereço nulo (zero), usado para especificar que um dado ponteiro está "vazio".
* offsetof(type, member): retorna o número de *bytes* de deslocamento antes de um elemento específico de uma `struct` ou `union`.
	* type: nome da `struct` ou `union`.
	* member: membro da `struct` ou `union`.

<br>

> [!IMPORTANT]
> Alguns dos usos de `offsetof` incluem o empacotamento de estruturas de dados e a descrição de como os dados `EEPROM` são armazenados. [Veja](https://www.embedded.com/learn-a-new-trick-with-the-offsetof-macro/ "Sobre 'offsetof'").

<br>

<hr>

#### Fontes:
* [tutorialspoint: stddef.h](https://www.tutorialspoint.com/c_standard_library/stddef_h.htm)
* [embedded: tips and trucks to offsetof](https://www.embedded.com/learn-a-new-trick-with-the-offsetof-macro/)

<hr>
