# Conteúdo
* [add\_executable()](#1)
* [cmake\_minimum\_required()](#2)
* [project()](#3)
* [set()](#4)
* [unset()](#5)
* [configure\_file()](#6)
* [target\_include\_directories()](#7)

<h2 id="1">add_executable()</h2>

### `add_executable(<name> <options ...> <source ...>)`
* \<name>: corresponde ao nome do alvo lógico, ele deve ser único em todo o projeto. Sua escrita está a mêrce das conveções da plataforma em questão (`<name>.exe`, `<name>`, `...`). Mais informações referentes ao executável:
	* [RUNTIME\_OUTPUT\_DIRECTORY](https://cmake.org/cmake/help/latest/prop_tgt/RUNTIME_OUTPUT_DIRECTORY.html#prop_tgt:RUNTIME_OUTPUT_DIRECTORY)
	* [OUTPUT\_NAME](https://cmake.org/cmake/help/latest/prop_tgt/OUTPUT_NAME.html#prop_tgt:OUTPUT_NAME)
	* [cmake-buildsystem()](https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#manual:cmake-buildsystem(7))
* \<options ...>: opções relacionadas ao produto do processo de compilação do executável em questão. São elas:
	* WIN32: define `WIN32_EXECUTABLE` e constrói um executável com a função de entrada `WinMain`, de modo a que o mesmo seja um executável para GUI ao invés de um executável para Terminal, mas apenas caso a montagem seja executado em uma máquina com Windows. Mais sobre `WinMain`:
		* [CMAKE\_MFC\_FLAG](https://cmake.org/cmake/help/latest/variable/CMAKE_MFC_FLAG.html#variable:CMAKE_MFC_FLAG)
		* [CMAKE\_WIN32\_EXECUTABLE](https://cmake.org/cmake/help/latest/variable/CMAKE_WIN32_EXECUTABLE.html#variable:CMAKE_WIN32_EXECUTABLE)
	* MACOSX\_BUNDLE: constrói um aplicativo _bundle_, quando montado em um macOS ou IOS, que é um executável para GUI que pode ser executado com [_Finder_](https://www.howtogeek.com/716913/what-is-finder-on-a-mac/). Mais sobre aplicativos _bundle_:
		* [MACOSX\_BUNDLE\_INFO\_PLIST](https://cmake.org/cmake/help/latest/prop_tgt/MACOSX_BUNDLE_INFO_PLIST.html#prop_tgt:MACOSX_BUNDLE_INFO_PLIST)
		* [CMAKE\_MACOSX\_BUNDLE](https://cmake.org/cmake/help/latest/variable/CMAKE_MACOSX_BUNDLE.html#variable:CMAKE_MACOSX_BUNDLE)
	* EXCLUDE\_FROM\_ALL: especifica que os demais arquivos presentes na chamada de `add_executable` não devem ser adicionados ao alvo `all`, assim, ao executar `make` (por exemplo), os arquivos presentes não serão usados na construção do executável. Isso é útil para evitar a compilação de arquivos de exemplo. Ainda será possível compilá-los, mas um alvo especifico deverá ser convocado.
* \<source ...>: arquivos que serão usados para compilar o programa em questão.

### `add_executable(<name> IMPORTED [GLOBAL])`
* \<name>: [GOTO](#1)
* IMPORTED: importa um arquivo executável localizado fora do diretório do projeto. Ele pode ser referenciado como qualquer outro nome de alvo, exceto que, por padrão, ele ficará visível apenas para o diretório no qual foi criado e abaixo.
* [GLOBAL]: torna o nome do alvo visualmente global.

### `add_executable(<name> ALIAS <target>)`
* \<name>: [GOTO](#1)
* ALIAS: especifica um apelido para \<name>, que será usado em seu lugar, em todos os casos.
* \<target>: referência para \<name>. Ele não pode ser um `ALIAS`.

<h2 id="2">cmake_minimum_required()</h2>

### `cmake_minimum_required(VERSION <min>[...<policy_max>] [FATAL_ERROR])`
* VERSION: indica que a verão mínima será especificada.
* \<min>: versão miníma, do Cmake, exigida para executar o _script_ em questão.
* `...`: "conecção" entre \<min> e \<policy-max>.
* \<policy-max>: versão máxima, do Cmake, exigida para executar o _script_em questão;
* FATAL\_ERROR: ficou em desuso a partir da versão 2.6. Em versão <2.6, ela especificava que um error deveria ser gerado após a interrupção do _script_, ao invés de apenas uma mensagem. Em versões >=2.6, ela é ignorada.

<br>

> [!WARNING]
> Para evitar todo e qualquer tipo de erro e/ou problema, é **extremamente** recomendado chamar `cmake_minimum_required()` na primeira linha do primeiro arquivo (caso hajam outros) Cmake do projeto.

<br>

<h2 id="3">project()</h2>

### `project(<name> <languages ...>)`
* \<name>: nome do projeto.
* \<languages ...> linguagens de programação usadas nos arquivos do projeto.


### `project(<name> [VERSION <major>[.<minor>[.<patch>[.<tweak>]]]] [DESCRIPTION <text>] [HOMEPAGE_URL <url>] [LANGUAGES <languages...>]`
* \<name>: [GOTO](#3)
* [VERSION: indica que a versão do projeto será especificada.
* \<major>[.\<minor>[.\<patch>[.\<tweak>]]]]: Versão do projeto.
* [DESCRIPTION: indica que a descrição do projeto será especificada.
* \<text>]: decrição do projeto.
* [HOMEPAGE\_URL: indica que a URL de um site, possivelmente relacionado com o projeto, será especificado.
* \<url>]: URL de um site.
* [LANGUAGES: indica que a(s) linguagem(ns) usada(s) no projeto será(ão) especificadas.
* \/languages>]: [GOTO](#3)


<h2 id="4">set()</h2>

### `set(<variable> <value ...> [PARENT_SCOPE])`
* \<variable>: **variável normal** que será criada ou que receberá um novo valor.
* \<value ...>: valor que será atribuído a variável.
* [PARENT\_SCOPE]: especifica que \<variable> deve ser definida no topo do escopo atual.

### `set(<variable> <value ...> CACHE <type> <docstring> [FORCE])`
* \<variable>: **variável de cache** [GOTO](#4)
* \<value ...>: [GOTO](#4)
* CACHE: indica que o tipo de variável de cache será especificado.
* \<type>: tipo da variável de cache: `BOOL` (`ON`/`OFF`), `FILEPATH`, `PATH`, `STRING` e `INTERNAL`.
* \<docstring>: descrição da função/uso da variável em questão.
* [FORCE]: especifica que o valor deve ser atribuído a variável mesmo que ela já possua um valor.

### `set(ENV{<variable>} [<value>])`
* ENV{: prefixo usado para ler variáveis de ambiente (`$ENV{var}`).
* \<variable>}: **variável de ambiente** [GOTO](#4)
* \<value>: [GOTO](#4)

<br>

> [!NOTE]
> Caso \<value> não seja especificado, a variável tornará-se indefinida, semelhante a `unset(<variable>)`

<br>

<h2 id="5">unset()</h2>

### `unset(<variable> [CACHE | PARENT_SCOPE)`
* \<variable>: variável que será removida do escopo atual, assim tornando-se indefinida.
* [CACHE |: especifica que a _versão cache_ de \<variable> deve ser removida, ao invés da _versão normal_.
* PARENT\_SCOPE]: especifica que a variável deve ser removida do topo do escopo atual.

### `unset(ENV{<variable>})`
* ENV{: [GOTO](#4)
* \<variable>}: variável que será removida do grupo das *Variáveis de Ambiente*.

<h2 id="6">configure_file()</h2>

### `configure_file(<input> <output> [NO_SOURCE_PERMISSIONS | USE_SOURCE_PERMISSIONS | FILE_PERMISSIONS <permissions ...>] [COPYONLY] [ESCAPE_QUOTES] [@ONLY] [NEWLINE_STYLE [UNIX|DOS|WIN32|LF|CRLF]])`
* \<input>: arquivo base cujos códigos presentes baseiam-se nas instruções presentes em `CMakeLists.txt`.
* \<output>: arquivo que será criado e conterá o *conteúdo modificado* de \<input>. Caso em seu caminho hajam pastas inexistente, estas serão criadas durante a execução.
* [NO\_SOURCE\_PERMISSIONS |: especifica que \<output> **NÃO** deve herdar as permissões (`rwx`) de \<input>.
* USE\_SOURCE\_PERMISSIONS |: especifica que \<output> não deve herdar as permissões (`rwx`) de \<input>.
* [FILE\_PERMISSIONS: indica que as permissões de \<output> serão especificadas.
* \<permissions...>]]: as permissões (`rwx`) de \<output>.
* [COPYONLY]: especifica que o conteúdo de \<input> deve ser copiado para \<output> sem sofrer nenhum tipo de alteração (**não** pode ser usado em conjunto com NEWLINE\_STYLE).
* [ESCAPE\_QUOTES]: converte os caracteres de escape para a convensão de C.
* [@ONLY]: Restringe a substituição de variáveis para apenas aqueles entre `@` (`@var@`), assim não alterando variável entre `${}` (`${var}`).
* [NEWLINE\_STYLE: indica que o *estilo* da quebra de linha para \<output> será especificado (**não** pode ser usado em conjunto com COPYONLY).
* [UNIX|DOS|WIN32|LF|CRLF]]: estilo da quebra de linha: `\n` (UNIX/LF) ou `/r/n` (DOS/WIN32/CRLF).

<h2 id="7">target_include_directories()</h2>

### `target_include_directories(<target> [SYSTEM] [AFTER | BEFORE] <INTERFACE | PUBLIC | PRIVATE> [items0...] [<INTERFACE | PUBLIC | PRIVATE> [items1...] ...])`
* \<target>: um identificador criado por `add_executable()` ou `add_library()`, que deve ser diferente de qualquer alvo ALIAS.
* [SYSTEM]: especifica que os diretório são destinados como diretórios de inclusão do sistema em algumas plataformas.
* [BEFORE |: prefixa os itens.
* AFTER]: sufixa os itens.
* \<INTERFACE |: preenche> INTERFACE\_INCLUDE\_DIRECTORIES.
* PUBLIC |: preenche: INCLUDE\_DIRECTORIES e INTERFACE\_INCLUDE\_DIRECTORIES.
* PRIVATE>: preenche: INCLUDE\_DIRECTORIES.
* `...`: representa a possibilidade de chamadas repetidas para o mesmo alvo (\<target>), as quais anexam itens na ordem de chamada.

<br>

<div>
<span style="padding:0px;margin:0px;font-size:20px;"><strong>Fontes:</strong></span>
<details><summary><span style="font-size:12px">[...]</span></summary>
<ul>
<li><a href="https://cmake.org/cmake/help/latest/command/add_executable.html">cmake.org/.../add_executable.html</a></li>
<li><a href="https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html">cmake.org/.../cmake_minimum_required.html</a></li>
<li><a href="https://cmake.org/cmake/help/latest/command/project.html">cmake.org/.../project.html</a></li>
<li><a href="https://cmake.org/cmake/help/latest/command/set.html">cmake.org/.../set.html</a></li>
<li><a href="https://cmake.org/cmake/help/latest/command/unset.html">cmake.org/.../unset.html</a></li>
<li><a href="https://cmake.org/cmake/help/latest/command/configure_file.html">cmake.org/.../configure_file.html</a></li>
<li><a href="https://cmake.org/cmake/help/latest/command/target_include_directories.html">cmake.org/.../target_include_directories.html</a></li>
</ul>
</details>
</div>
