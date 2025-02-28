# stdjmp
Adiciona ferramentas capazes de manipular o fluxo de execução do código, semelhante a um
`goto` com alcance global.

---

* `jmp_buf`: tipo capa de armazenar dados referentes ao ambiente atual.

---

### setjmp(jmp\_buf)
###### 

* Comportamento: salva os dados do "estado" atual do programa em `jmp_buf`.
* Retorno: `0`, caso seja chamada diretamente, ou o segundo argumento de `longjmp`, caso
ela tenha executado um salto utilizando o mesmo argumento de `setjmp`.

> [!TIP]
> Veja algumas definições para o que seria o ["estado"](https://stackoverflow.com/questions/25266832/exactly-what-program-state-does-setjmp-save "Stackoverflow").

---

### void longjmp(jmp\_buf, int)
###### 

* Comportamento: restaura o ambiente salvo em `jmp_buf`, ou seja, executa um salto à última
chamada de `set_jmp` que utilizou `jmp_buf`.
* Retorno: nenhum.

> [!IMPORTANT]
> Se `int==0`, `1` será utilizado em seu lugar.

---

#### Fontes:
* [wikipedia: setjmp.h](https://en.wikipedia.org/wiki/setjmp.h )
* [technthenet: example](https://www.techonthenet.com/c_language/standard_library_functions/setjmp_h/longjmp.php )

---
