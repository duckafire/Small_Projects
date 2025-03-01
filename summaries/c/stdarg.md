# stdarg
Fornece meios de se trabalhar com filas de argumentos indefinidos (`...`).

---

* `va_list`: tipo capaz de armazenar a fila de argumentos indefinidos.

---

### va\_start(va\_list, foo)
###### 

* Comportamento: inicializa `va_list`.
* Retorno: nenhum.

> [!IMPORTANT]
> `foo` deve ser o último argumento da função, ou seja, aquele anterior à fila.

---

### va\_arg(va\_list, type)
###### 

* Comportamento: obtém e remove um item de `va_list`.
* Retorno: o item obtido.
* 
> [!CAUTION]
> `va_arg` é incapaz de identificar o final da lista.

> [!IMPORTANT]
> `type` é o tipo do valor extraído da lista (`char`, `int`, ...).

---

### va\_end(va\_list)
###### 

* Comportamento: encerra `va_list`.
* Retorno: nenhum.

---
	
### va\_copy(va\_list0, va\_list1)
###### 

* Comportamento: copia o conteúdo de `va_list1` para `va_list0`.
* Retorno: nenhum.

---

#### Fontes:
* [wikipedia: stdarg.h](https://en.wikipedia.org/wiki/stdarg.h )
* [technthenet: example](https://www.techonthenet.com/c_language/standard_library_functions/stdarg_h/va_arg.php )

---
