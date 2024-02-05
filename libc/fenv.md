# fenv
(5) Fornece funções para manipulação de ambientes de ponto flutuante (conjunto de características e regras que regem a representação e manipulação de números de ponto flutuante em um OS)

1. int **fegetround**(void);
	* Nenhum.
	* fegetround();
	* Retorna o modo de arredondamento atual do ambiente de ponto flutuante.

2. int **fesetround**(int round_mode);
	* round_mode: Modo de arredondamento desejado.
	* *fesetrounf(FE_UPWARD);* // FE_TONEAREST (para o mais próximo);  FE_DOWNWARD (para o menor valor; truncamento); FE_UPWARD (para o maior valor; +inf); FE_TOWARDZERO (para zero)
	* Configura o modo de arredondamento do ambiente de ponto flutuante.

3. int **fegetenv**(fenv_t *envp);
	* envp: Ponteiro para a estrutura de ambiente de ponto flutuante.
	* *fegetenv(&variable);*
	* Salva o estado atual do ambiente de ponto flutuante na estrutura apontada por seu parâmetro.

4. int **fesetenv**(const fenv_t *envp);
	* envp: Ponteiro para a estrutura de ambiente de ponto flutuante.
	* *fesetenv(*variable);*
	* Configura o ambiente de ponto flutuante de acordo com o estado salvo na estrutura apontada por seu parâmetro.

5. int **feupdateenv**(const fenv_t *envp);
	* envp: Ponteiro para a estrutura de ambiente de ponto flutuante.
	* *feupdateenv();*
	* Atualiza o ambiente de ponto flutuante com base no estado salvo na estrutura apontada por seu parâmetro.
