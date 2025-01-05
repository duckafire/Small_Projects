# stddef
Define um conjunto de tipos e macros comumente utilizados por outras bibliotecas padrão C.

<br>

| Tipo       | Valor                                              |
| :--        | :--                                                |
| ptrdiff\_t | Armazena o resultado de um subtração de ponteiros  |
| size\_t    | Armazena o tamanho de objetos em áreas na memória  |
| wchar\_t   | Armazena caracteres com tamanho acima de um *byte* |

<br>
<hr>
<br>

* NULL: endereço nulo (zero), usado para especificar que um dado ponteiro está "vazio".
* offsetof(type, member): retorna o número de *bytes* de deslocamento antes de um elemento específico de uma `struct` ou `union`.
	* type: nome da `struct` ou `union`.
	* member: membro da `struct` ou `union`.

<br>

> [!IMPORTANTE]
> Alguns dos usos de `offsetof` incluem o empacotamento de estruturas de dados e a descrição de como os dados `EEPROM` são armazenados. [Veja](https://www.embedded.com/learn-a-new-trick-with-the-offsetof-macro/ "Sobre 'offsetof'").

<br>
<hr>
<br>

#### Fontes:
* https://www.tutorialspoint.com/c\_standard\_library/stddef\_h.htm
* https://en.wikibooks.org/wiki/C\_Programming/stddef.h
* https://publications.gbdirect.co.uk/c\_book/chapter2/integral\_types.html
* https://www.embedded.com/learn-a-new-trick-with-the-offsetof-macro/

<br>
<hr>
