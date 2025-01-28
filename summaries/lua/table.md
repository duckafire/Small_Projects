# Table
Disponibiliza funções relativas a manipulação de tabelas com índices numéricos (os demais são ignorados).

<hr>

|Funções||
|:-:|:-:|
|<a href="#1">table.concat</a>|<a href="#5">table.remove</a>|
|<a href="#2">table.insert</a>|<a href="#6">table.sort</a>  |
|<a href="#3">table.move</a>  |<a href="#7">table.unpack</a>|
|<a href="#4">table.pack</a>  ||

<hr>

<h3 id="1">table.concat(table, [string="", [number0=1, [number1=#table]]])</h3>

* Comportamento: concatena os valores presente em `table`, do índice `number0` até o índice `number1`, posicionando `string` entre cada valor.
* Retorno: uma cadeia de caracteres resultante da concatenação dos valores presente em `table`.

<hr>

<h3 id="2">table.insert(table, [number=#table+1], some_type)</h3>

* Comportamento: insere `some_type` em `table`, no índice `number`.
* Retorno: nenhum.

<br>

> [!IMPORTANT]
> Caso `table[number]` já possuia um valor, ele será movido um índice para frente (`table[number+1]`), assim como seus sucessores, e `some_type` será atribuído a sua posição original.

<br>

<hr>

<h3 id="3">table.move(table0, number0, number1, number2, table1)</h3>

* Comportamento: copia os índices de `number0` até `number1` (de `table0`) para `table1`, a partir do índice `number2` (de `table1`), substituído valores já existente em `table1` durante o processo.
* Retorno: uma tabela, resultante da operação.

<hr>

<h3 id="4">table.pack(...)</h3>

* Comportamento: cria uma tabela com os valores fornecidos por `...`.
* Retorno: a tabela criada.

<hr>

<h3 id="5">table.remove(table, [number=#table])</h3>

* Comportamento: remove o valor armazenado no índice `number` de `table`.
* Retorno: o valor removido.

<br>

> [!IMPORTANT]
> Caso hajam um (ou mais) valor acima do índice `number` de `table`, ele (e os demais) serão movidos um índice para baixo (`table[number-1]`), assim tapando o possível "buraco" deixado pela remoção.

<br>

<hr>

<h3 id="6">table.sort(table, [function_=IN_BELOW)</h3>

* Comportamento: ordena os valores presentes em `table`, através do uso de `function_`.
* Retorno: nenhum.

<br>

``` lua
function_ = function(n0, n1)
	return n0 < n1
end
```

<br>

<hr>

<h3 id="7">table.unpack(table, [number0=1, [number1=#table]])</h3>

* Comportamento: expande o conteúdo presente em `table`, ou seja, "descompacta" a mesma (do índice `number0` até `number1`).
* Retorno: os valores que foram expandidos.

<hr>
