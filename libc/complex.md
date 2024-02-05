# complex (6; 0)
Fornece funções para a manipulação de números complexos
(números formados por uma parte real e uma parte imaginária, por exemplo "a + !b", que em C é representado por "a + b * I").

1. double **cabs**(double complex n);
	* n: Número complexo.
	* *cabs((19 + 14 * I));*
	* Retorna o módulo (magnitude) do número.
	
2. double **carg**(double complex n);
	* n: Número complexo.
	* *carg((1 + 52 * I));*
	* Retorna o ângulo do número.

3. double **cimag**(doucle complex n);
	* n: Número complexo.
	* *cimag((9 + 57 * I));*
	* Retorna a parte imaginária do número.

4. double **creal**(double complex n);
	* n: Número complexo.
	* *creal(51 + 8 * I);*
	* Retorna a parte real do número.

5. double complex **cexp**(double complex n);
	* n: Número complexo.
	* *cexp((45 + 9 * I));*
	* Retorna a exponencial complexa (e^z).
	
6. double complex **clog**(double complex n);
	* n: Número complexo.
	* *clog((2 + 1 * I));*
	* Retorna o logaritmo natural.

7. double complex **cpow**(double complex base, double complex exp);
	* base: Base da exponenciação | exp: Expoente da exponenciação.
	* *cpow((14 + 17 * I), (21 * 3 * I));*
	* Retorna o resultado da elevação de um valor complexo a um valor complexo (expoenciação).

8. double complex **cconj**(double complex n);
	* n: Número complexo.
	* *cconf((49 + 4 * I));*
	* Retorna o conjunto do número.

9. double complex **csqrt**(double complex n);
	* n: Número complexo.
	* *csqrt((11 + 6 * I));*
	* Retorna a raiz quadrada do número.