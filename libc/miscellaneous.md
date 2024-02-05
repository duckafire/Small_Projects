
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<float.h>
A biblioteca "float.h" em C não fornece funções. Ela é utilizada para definir constantes relacionadas a valores de ponto flutuante, como limites máximos e mínimos representáveis. Aqui estão algumas constantes comuns presentes nesta biblioteca:
float.h
Constante FLT_DIG
    Descrição: Número de dígitos decimais precisos representáveis para um tipo float.
    Uso: Usado para determinar a precisão decimal máxima de variáveis do tipo float.
Constante FLT_EPSILON
    Descrição: Menor número positivo representável tal que 1.0 + FLT_EPSILON != 1.0.
    Uso: Útil para comparar números de ponto flutuante quanto à igualdade aproximada.
Constante FLT_MANT_DIG
    Descrição: Número de dígitos binários significativos na mantissa de um tipo float.
    Uso: Informa sobre a precisão e a representação interna de números em ponto flutuante.
Constante FLT_MAX
    Descrição: Maior valor finito representável para um tipo float.
    Uso: Indica o valor máximo que uma variável do tipo float pode armazenar.
Constante FLT_MIN
    Descrição: Menor valor normalizado representável para um tipo float.
    Uso: Indica o valor mínimo positivo que uma variável do tipo float pode representar.
Essas constantes são usadas para lidar com limites e características de variáveis de ponto flutuante, fornecendo informações úteis para programadores que trabalham com aritmética de ponto flutuante em C.

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<inttypes.h>
A biblioteca "inttypes.h" em C fornece tipos e macros para manipulação de formatos inteiros. No entanto, ela não possui funções próprias. A principal utilização desta biblioteca é a definição de tipos inteiros com larguras específicas, o que é especialmente útil para garantir portabilidade em diferentes sistemas.
Aqui estão alguns tipos definidos pela biblioteca e suas descrições:
inttypes.h
Tipos Inteiros Fixos
    int8_t
    int16_t
    int32_t
    int64_t
Descrição:
    Tipos inteiros com larguras fixas de 8, 16, 32 e 64 bits, respectivamente.
Uso:
    Esses tipos são úteis quando é necessário garantir que o tamanho dos inteiros seja específico, independentemente da plataforma.
Tipos Inteiros Sem Sinal Fixos
    uint8_t
    uint16_t
    uint32_t
    uint64_t
Descrição:
    Tipos inteiros sem sinal com larguras fixas de 8, 16, 32 e 64 bits, respectivamente.
Uso:
    Semelhante aos tipos inteiros com sinal, esses tipos garantem larguras específicas para variáveis sem sinal.
Macros para Formatação
    PRIi8
    PRIi16
    PRIi32
    PRIi64
    PRIu8
    PRIu16
    PRIu32
    PRIu64
Descrição:
    Macros usadas como especificadores de formato para impressão ou leitura de valores inteiros usando printf ou scanf.
Uso:
    Essas macros ajudam a garantir portabilidade ao formatar ou ler inteiros de diferentes tamanhos.
Essa biblioteca é valiosa para desenvolvedores que precisam lidar com tamanhos específicos de inteiros em sistemas diversos, proporcionando consistência na manipulação de tipos inteiros fixos.

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<iso646.h>
A biblioteca "iso646.h" em C não contém funções; ela é utilizada para fornecer alternativas mnemônicas para alguns operadores lógicos. Essa biblioteca define nomes adicionais para operadores lógicos padrão, o que pode tornar o código mais legível. Aqui estão as alternativas fornecidas:
iso646.h
Palavras-chave Alternativas
    and
    and_eq
    bitand
    bitor
    compl
    not
    not_eq
    or
    or_eq
    xor
    xor_eq
Descrição:
    Essas palavras-chave são alternativas mnemônicas para os operadores lógicos padrão (&&, &=, &, |, ~, !, !=, ||, |=, ^, ^=).
Uso:
    Ao incluir "iso646.h" em um programa, é possível usar essas palavras-chave como alternativas mais legíveis para os operadores lógicos padrão. Por exemplo, and pode ser usado no lugar de &&, or no lugar de ||, etc. Isso pode tornar o código mais expressivo e fácil de ler, especialmente em contextos que envolvem expressões lógicas complexas. No entanto, essa biblioteca não é amplamente utilizada na prática, e muitos programadores preferem os operadores padrão.

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<limits.h>
A biblioteca "limits.h" em C não contém funções, mas fornece constantes relacionadas aos limites de tipos de dados inteiros. Aqui estão algumas das constantes mais comuns definidas por "limits.h":
limits.h
Constantes para Tipos Inteiros
    CHAR_BIT
        Descrição: Número de bits em um byte.
        Tipo: int
    SCHAR_MIN
        Descrição: Valor mínimo para um tipo signed char.
        Tipo: signed char
    SCHAR_MAX
        Descrição: Valor máximo para um tipo signed char.
        Tipo: signed char
    UCHAR_MAX
        Descrição: Valor máximo para um tipo unsigned char.
        Tipo: unsigned char
    CHAR_MIN
        Descrição: Valor mínimo para um tipo char.
        Tipo: char
    CHAR_MAX
        Descrição: Valor máximo para um tipo char.
        Tipo: char
    SHRT_MIN
        Descrição: Valor mínimo para um tipo short.
        Tipo: short
    SHRT_MAX
        Descrição: Valor máximo para um tipo short.
        Tipo: short
    USHRT_MAX
        Descrição: Valor máximo para um tipo unsigned short.
        Tipo: unsigned short
    INT_MIN
        Descrição: Valor mínimo para um tipo int.
        Tipo: int
    INT_MAX
        Descrição: Valor máximo para um tipo int.
        Tipo: int
    UINT_MAX
        Descrição: Valor máximo para um tipo unsigned int.
        Tipo: unsigned int
    LONG_MIN
        Descrição: Valor mínimo para um tipo long.
        Tipo: long
    LONG_MAX
        Descrição: Valor máximo para um tipo long.
        Tipo: long
    ULONG_MAX
        Descrição: Valor máximo para um tipo unsigned long.
        Tipo: unsigned long
    LLONG_MIN
        Descrição: Valor mínimo para um tipo long long.
        Tipo: long long
    LLONG_MAX
        Descrição: Valor máximo para um tipo long long.
        Tipo: long long
    ULLONG_MAX
        Descrição: Valor máximo para um tipo unsigned long long.
        Tipo: unsigned long long
Essas constantes são usadas para obter informações sobre os limites de representação para diferentes tipos de dados inteiros em uma implementação específica de C. Elas ajudam a garantir a portabilidade do código ao lidar com diferentes sistemas e compiladores.

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<locale.h>
A biblioteca "locale.h" em C fornece funções para manipulação de informações de localidade, como formatação de números, datas e caracteres. Aqui estão algumas das funções disponíveis:
locale.h
Função setlocale
char *setlocale(int category, const char *locale);
Descrição:
    Parâmetros:
        category: Categoria de informações de localidade (LC_ALL, LC_COLLATE, LC_CTYPE, LC_MONETARY, LC_NUMERIC, LC_TIME).
        locale: String representando a localidade desejada ou NULL para obter a localidade atual.
Uso:
    A função setlocale configura ou recupera as informações de localidade para a categoria especificada. Se locale for NULL, a função retorna a localidade atual para a categoria especificada. Caso contrário, ela tenta configurar a localidade para o valor fornecido.
Função localeconv
struct lconv *localeconv(void);
Descrição:
    Parâmetros:
        Nenhum.
Uso:
    A função localeconv retorna um ponteiro para uma estrutura lconv contendo informações de formatação para a localidade atual. Essas informações incluem símbolos de moeda, separadores de milhar e decimal, entre outros.
Função isdigit
int isdigit(int c);
Descrição:
    Parâmetro:
        c: Caractere.
Uso:
    A função isdigit verifica se o caractere c é um dígito decimal de 0 a 9, de acordo com as informações de localidade.
Função toupper
int toupper(int c);
Descrição:
    Parâmetro:
        c: Caractere.
Uso:
    A função toupper converte o caractere c para maiúscula de acordo com as informações de localidade.
Essas funções são utilizadas para lidar com aspectos relacionados à localização, como formatação de números, datas e caracteres, tornando o código mais adaptável a diferentes regiões e idiomas.

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<math.h>
Aqui estão 30 funções da biblioteca "math.h" em C, seguindo a abordagem inicial de fornecer uma breve descrição e os parâmetros principais:
    acos(double x)
        Descrição: Retorna o arco cosseno de x em radianos.
        Parâmetro: x - Valor cujo arco cosseno será calculado.
    asin(double x)
        Descrição: Retorna o arco seno de x em radianos.
        Parâmetro: x - Valor cujo arco seno será calculado.
    atan(double x)
        Descrição: Retorna o arco tangente de x em radianos.
        Parâmetro: x - Valor cujo arco tangente será calculado.
    cosh(double x)
        Descrição: Retorna o cosseno hiperbólico de x.
        Parâmetro: x - Valor para calcular o cosseno hiperbólico.
    exp(double x)
        Descrição: Retorna a exponencial de x (e^x).
        Parâmetro: x - Expoente da exponencial.
    log(double x)
        Descrição: Retorna o logaritmo natural de x.
        Parâmetro: x - Valor para calcular o logaritmo natural.
    log10(double x)
        Descrição: Retorna o logaritmo em base 10 de x.
        Parâmetro: x - Valor para calcular o logaritmo em base 10.
    sinh(double x)
        Descrição: Retorna o seno hiperbólico de x.
        Parâmetro: x - Valor para calcular o seno hiperbólico.
    tan(double x)
        Descrição: Retorna a tangente do ângulo x (em radianos).
        Parâmetro: x - Ângulo em radianos.
    sqrt(double x)
        Descrição: Retorna a raiz quadrada de x.
        Parâmetro: x - Número do qual se deseja calcular a raiz quadrada.
    pow(double base, double exponent)
        Descrição: Retorna base elevado à potência de exponent.
        Parâmetros: base - Base da potência, exponent - Expoente.
    ceil(double x)
        Descrição: Retorna o menor número inteiro maior ou igual a x.
        Parâmetro: x - Valor a ser arredondado para cima.
    floor(double x)
        Descrição: Retorna o maior número inteiro menor ou igual a x.
        Parâmetro: x - Valor a ser arredondado para baixo.
    fabs(double x)
        Descrição: Retorna o valor absoluto de x.
        Parâmetro: x - Valor para calcular o valor absoluto.
    fmod(double x, double y)
        Descrição: Retorna o resto da divisão de x por y.
        Parâmetros: x - Numerador, y - Denominador.
    trunc(double x)
        Descrição: Retorna a parte inteira de x (truncamento).
        Parâmetro: x - Valor para calcular a parte inteira.
    round(double x)
        Descrição: Retorna o valor de x arredondado para o inteiro mais próximo.
        Parâmetro: x - Valor a ser arredondado.
    remainder(double x, double y)
        Descrição: Retorna o resto da divisão de x por y.
        Parâmetros: x - Numerador, y - Denominador.
    fmin(double x, double y)
        Descrição: Retorna o menor valor entre x e y.
        Parâmetros: x - Primeiro valor, y - Segundo valor.
    fmax(double x, double y)
        Descrição: Retorna o maior valor entre x e y.
        Parâmetros: x - Primeiro valor, y - Segundo valor.
    hypot(double x, double y)
        Descrição: Retorna a hipotenusa de um triângulo retângulo com lados de comprimento x e y.
        Parâmetros: x - Comprimento do primeiro lado, y - Comprimento do segundo lado.
    fdim(double x, double y)
        Descrição: Retorna a diferença positiva entre x e y.
        Parâmetros: x - Primeiro valor, y - Segundo valor.
    exp2(double x)
        Descrição: Retorna 2 elevado à potência de x.
        Parâmetro: x - Expoente.
    expm1(double x)
        Descrição: Retorna e^x - 1, evitando a perda de precisão para valores de x próximos a zero.
        Parâmetro: x - Expoente.
    cbrt(double x)
        Descrição: Retorna a raiz cúbica de x.
        Parâmetro: x - Número do qual se deseja calcular a raiz cúbica.
    fabsf(float x)
        Descrição: Retorna o valor absoluto de x (para números de ponto flutuante).
        Parâmetro: x - Valor para calcular o valor absoluto.
    ceilf(float x)
        Descrição: Retorna o menor número inteiro maior ou igual a x (para números de ponto flutuante).
        Parâmetro: x - Valor a ser arredondado para cima.
    floorf(float x)
        Descrição: Retorna o maior número inteiro menor ou igual a x (para números de ponto flutuante).
        Parâmetro: x - Valor a ser arredondado para baixo.
    sinf(float x)
        Descrição: Retorna o seno do ângulo x (para números de ponto flutuante).
        Parâmetro: x - Ângulo em radianos.
    cosf(float x)
        Descrição: Retorna o cosseno do ângulo x (para números de ponto flutuante).
        Parâmetro: x - Ângulo em radianos

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<setjmp.h>
A biblioteca setjmp.h em C possui apenas uma função principal, que é a setjmp. Abaixo está a descrição detalhada da função:
    Função setjmp:
        Descrição breve: Salva o estado do ambiente para posterior restauração usando longjmp.
        Tipo: int
        Parâmetros:
            jmp_buf env: Buffer para armazenar o ambiente.
        Descrição completa: A função setjmp é usada para salvar o estado do ambiente em env, permitindo que mais tarde o programa retorne a esse estado usando a função longjmp. Isso é útil para implementar exceções ou para sair de maneira não usual de uma função sem executar todas as instruções intermediárias.
Lembre-se de que setjmp.h não é uma biblioteca extensa, e a função setjmp é a única presente nela.

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<signal.h>
A biblioteca signal.h em C fornece funções relacionadas ao tratamento de sinais. Aqui estão algumas das principais funções dessa biblioteca:

    Função signal:
        Descrição breve: Configura o tratamento de um sinal específico.
        Tipo: void (*func)(int)
        Parâmetros:
            int signum: Número do sinal.
            void (*func)(int): Ponteiro para a função de tratamento do sinal.
        Descrição completa: A função signal é usada para especificar como o programa deve lidar com um sinal específico (signum). O parâmetro func é um ponteiro para a função que será chamada quando o sinal ocorrer.

    Função raise:
        Descrição breve: Gera um sinal.
        Tipo: int
        Parâmetros:
            int signum: Número do sinal a ser gerado.
        Descrição completa: A função raise gera um sinal especificado por signum no próprio processo, permitindo simular a ocorrência de um sinal.

Essas são algumas das principais funções da biblioteca signal.h. Note que o tratamento de sinais é uma parte avançada da programação C e deve ser usado com cuidado.

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<stdalign.h>
A biblioteca stdalign.h em C define macros para controle de alinhamento de objetos. Aqui estão as principais macros dessa biblioteca:

    Macro alignas:
        Descrição breve: Especifica o alinhamento de um objeto ou tipo.
        Uso: alignas(expression)
        Descrição completa: A macro alignas especifica o alinhamento requerido para um objeto ou tipo. Pode ser usado para garantir que os objetos tenham um alinhamento específico na memória.

    Macro alignof:
        Descrição breve: Retorna o alinhamento de um tipo ou objeto.
        Uso: alignof(type) ou alignof(expression)
        Descrição completa: A macro alignof retorna o alinhamento necessário para um tipo ou objeto. Isso é útil para garantir que os objetos estejam alinhados corretamente na memória.

Essas são as principais macros da biblioteca stdalign.h. Elas são utilizadas principalmente para controlar o alinhamento de objetos na memória, o que pode ser crucial para otimização e compatibilidade em sistemas específicos.

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<stdarg.h>
A biblioteca stdarg.h em C fornece funcionalidades para lidar com funções variádicas, ou seja, funções que aceitam um número variável de argumentos. No entanto, não há funções diretamente relacionadas nessa biblioteca. Em vez disso, ela define macros e tipos que facilitam a implementação de funções variádicas.

A principal estrutura definida é va_list, e as principais macros são:

    Macro va_start:
        Descrição breve: Inicializa o objeto va_list para acessar os argumentos variáveis.
        Uso: va_start(ap, last_arg)
        Descrição completa: A macro va_start é usada no início de uma função variádica para inicializar o objeto va_list para acessar os argumentos variáveis. last_arg é o último parâmetro fixo conhecido da função.

    Macro va_arg:
        Descrição breve: Acessa o próximo argumento variável da lista.
        Uso: va_arg(ap, type)
        Descrição completa: A macro va_arg é usada para acessar o próximo argumento variável da lista, especificando o tipo do argumento como o segundo parâmetro.

    Macro va_end:
        Descrição breve: Finaliza o uso do objeto va_list.
        Uso: va_end(ap)
        Descrição completa: A macro va_end é usada para finalizar o uso do objeto va_list após a leitura de todos os argumentos variáveis.

Essas macros são fundamentais para criar funções que podem receber um número variável de argumentos. Geralmente, essas funções são usadas em situações em que é necessário lidar com uma quantidade indefinida de argumentos, como em funções de formatação de texto, por exemplo.

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<stdatomic.h>
A biblioteca stdatomic.h em C fornece suporte para operações atômicas, permitindo a execução segura de operações em ambientes concorrentes. No entanto, ela não possui funções tradicionais como em outras bibliotecas. Em vez disso, ela define tipos e macros para operações atômicas. Aqui estão alguns dos principais componentes:

    Tipo atomic_flag:
        Descrição breve: Tipo para implementar flags de operações atômicas.
        Descrição completa: O tipo atomic_flag é um tipo usado para implementar flags de operações atômicas, garantindo que certas operações sejam executadas sem serem interrompidas por outras threads.

    Tipo atomic_bool, atomic_char, atomic_int, etc.:
        Descrição breve: Tipos para implementar variáveis atômicas de diferentes tipos.
        Descrição completa: Esses tipos são usados para criar variáveis que suportam operações atômicas, garantindo consistência e evitando condições de corrida em ambientes multithread.

    Macros ATOMIC_VAR_INIT, ATOMIC_FLAG_INIT:
        Descrição breve: Macros para inicialização de objetos atômicos.
        Descrição completa: Essas macros são usadas para inicializar objetos atômicos, fornecendo valores iniciais.

    Funções de operação atômica (e.g., atomic_store, atomic_load, atomic_exchange):
        Descrição breve: Realizam operações atômicas em variáveis atômicas.
        Descrição completa: Essas funções permitem operações atômicas como armazenar um valor, carregar um valor ou trocar um valor em uma variável atômica, garantindo que essas operações ocorram sem serem interrompidas por outras threads.

O uso principal dessa biblioteca está em situações em que é necessário garantir que certas operações em variáveis ocorram atomicamente, sem serem interrompidas por operações de outras threads. Isso é essencial para evitar condições de corrida e garantir a consistência dos dados em ambientes concorrentes.

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<stdbool.h>
A biblioteca stdbool.h em C não contém funções, mas sim um tipo e algumas macros que facilitam o uso de valores booleanos. Aqui estão os principais componentes:

    Tipo _Bool:
        Descrição breve: Tipo de dados booleano.
        Descrição completa: O tipo _Bool é usado para representar valores booleanos, que podem ser true (verdadeiro) ou false (falso). Pode ser usado em expressões booleanas e é muitas vezes utilizado em conjunto com as macros definidas nesta biblioteca.

    Macro bool:
        Descrição breve: Define o tipo bool como _Bool.
        Descrição completa: A macro bool é usada para definir o tipo bool como _Bool, facilitando a declaração de variáveis booleanas.

    Macros true e false:
        Descrição breve: Representam os valores verdadeiro e falso, respectivamente.
        Descrição completa: Essas macros representam os valores booleanos true (verdadeiro) e false (falso) e são frequentemente usadas em expressões booleanas.

    Macros boolalpha, noboolalpha:
        Descrição breve: Controla a exibição de valores booleanos.
        Descrição completa: A macro boolalpha é usada para imprimir ou formatar valores booleanos como "true" ou "false", enquanto noboolalpha restaura o comportamento padrão.

Esses componentes da biblioteca stdbool.h são úteis para melhorar a legibilidade do código ao utilizar valores booleanos de forma mais expressiva. O uso do tipo _Bool e das macros bool, true, e false facilita o desenvolvimento de código mais claro e conciso quando se trabalha com lógica booleana.

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<stddef.h>
A biblioteca stddef.h em C não fornece funções, mas sim tipos e macros relacionadas a ponteiros e tamanhos de objetos. Aqui estão os principais componentes:

    Tipo ptrdiff_t:
        Descrição breve: Tipo usado para representar a diferença entre dois ponteiros.
        Descrição completa: O tipo ptrdiff_t é usado para representar a diferença (ou distância) entre dois ponteiros. Pode ser usado em contextos onde a diferença de posição entre dois ponteiros é relevante.

    Tipo size_t:
        Descrição breve: Tipo usado para representar tamanhos de objetos.
        Descrição completa: O tipo size_t é usado para representar tamanhos de objetos em bytes. É comumente utilizado para parâmetros e valores de retorno relacionados a operações de alocação de memória.

    Tipo wchar_t:
        Descrição breve: Tipo usado para representar caracteres de largura estendida.
        Descrição completa: O tipo wchar_t é usado para representar caracteres de largura estendida, que podem ser necessários para representar caracteres especiais em alguns conjuntos de caracteres.

    Macro NULL:
        Descrição breve: Valor nulo para ponteiros.
        Descrição completa: A macro NULL é usada para representar um ponteiro nulo. Pode ser utilizado para inicializar ponteiros ou verificar se um ponteiro não aponta para nenhum objeto.

Esses são os principais componentes da biblioteca stddef.h. Ela é especialmente útil para garantir portabilidade e consistência em programas C, uma vez que define tipos padrão para representar tamanhos e diferenças entre ponteiros.

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<stdint.h>
A biblioteca stdint.h em C não fornece funções, mas sim tipos inteiros de largura fixa e macros relacionadas. Aqui estão os principais componentes:

    Tipos inteiros de largura fixa (e.g., int8_t, int16_t, uint8_t, uint16_t):
        Descrição breve: Tipos inteiros com largura fixa em bits.
        Descrição completa: Esses tipos garantem uma largura fixa em bits, como int8_t para um inteiro de 8 bits e uint16_t para um inteiro sem sinal de 16 bits. São úteis quando a precisão do tamanho do tipo é crucial, especialmente em situações de manipulação de dados de hardware ou comunicação de rede.

    Tipos inteiros de largura mínima (e.g., int_least8_t, int_least16_t, uint_least8_t, uint_least16_t):
        Descrição breve: Tipos inteiros com largura mínima garantida em bits.
        Descrição completa: Esses tipos garantem uma largura mínima em bits, permitindo a escolha de tipos que atendam a requisitos mínimos de tamanho. São úteis quando se precisa de eficiência de armazenamento e ainda precisa garantir um tamanho mínimo.

    Tipos inteiros de largura rápida (e.g., int_fast8_t, int_fast16_t, uint_fast8_t, uint_fast16_t):
        Descrição breve: Tipos inteiros com largura rápida em bits.
        Descrição completa: Esses tipos garantem uma largura rápida em bits, permitindo a escolha de tipos que ofereçam desempenho eficiente. São úteis quando é necessária eficiência computacional e o tamanho exato não é crítico.

    Tipos inteiros máximos (e.g., intmax_t, uintmax_t):
        Descrição breve: Tipos inteiros com largura máxima suportada pelo compilador.
        Descrição completa: Esses tipos representam os inteiros com a maior largura suportada pelo compilador. São úteis quando se precisa da maior precisão possível, independentemente da largura exata.

Esses tipos e macros da biblioteca stdint.h são projetados para melhorar a portabilidade e garantir uma manipulação precisa de tamanhos de dados em diferentes plataformas. Eles são particularmente valiosos em situações onde a precisão do tamanho é crucial, como em programação de sistemas e embarcada.

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<stdio.h>
A biblioteca stdio.h em C fornece funções para entrada e saída padrão. Abaixo estão algumas das principais funções dessa biblioteca:

    Função printf:
        Descrição breve: Formata e imprime uma saída formatada para a saída padrão.
        Tipo: int
        Parâmetros:
            const char* format: String de formato que especifica a formatação da saída.
            ...: Lista de argumentos variáveis conforme especificado pelo formato.
        Descrição completa: A função printf é usada para imprimir dados formatados na saída padrão (geralmente a tela). Ela aceita uma string de formato e uma lista de argumentos correspondentes ao formato, formatando e exibindo os dados conforme especificado.

    Função scanf:
        Descrição breve: Lê entrada formatada da entrada padrão.
        Tipo: int
        Parâmetros:
            const char* format: String de formato que especifica a leitura esperada.
            ...: Lista de ponteiros para variáveis onde os valores lidos serão armazenados.
        Descrição completa: A função scanf é usada para ler dados formatados da entrada padrão (geralmente o teclado). Assim como printf, ela usa uma string de formato para determinar como interpretar a entrada.

    Função fopen:
        Descrição breve: Abre um arquivo.
        Tipo: FILE* (ponteiro para a estrutura de arquivo)
        Parâmetros:
            const char* filename: Nome do arquivo a ser aberto.
            const char* mode: Modo de abertura (leitura, escrita, etc.).
        Descrição completa: A função fopen é usada para abrir um arquivo no sistema de arquivos. Ela retorna um ponteiro para a estrutura de arquivo associada ao arquivo aberto, permitindo operações subsequentes.

    Função fclose:
        Descrição breve: Fecha um arquivo previamente aberto.
        Tipo: int
        Parâmetros:
            FILE* stream: Ponteiro para a estrutura de arquivo a ser fechada.
        Descrição completa: A função fclose é usada para fechar um arquivo previamente aberto. Isso libera os recursos associados ao arquivo e torna o ponteiro de arquivo inválido.

Essas são apenas algumas das funções fornecidas pela biblioteca stdio.h. Elas são essenciais para a entrada e saída padrão, bem como para operações de arquivo em programas C.

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<stdlib.h>
A biblioteca stdlib.h em C fornece funções relacionadas a alocação de memória, conversões de string para outros tipos, geração de números aleatórios e controle de processo. Aqui estão algumas das principais funções dessa biblioteca:

    Função malloc:
        Descrição breve: Aloca um bloco de memória.
        Tipo: void*
        Parâmetros:
            size_t size: Tamanho em bytes do bloco de memória a ser alocado.
        Descrição completa: A função malloc é usada para alocar um bloco de memória contígua de tamanho especificado. Retorna um ponteiro para a primeira posição do bloco de memória ou NULL se a alocação falhar.

    Função free:
        Descrição breve: Libera um bloco de memória alocado por malloc ou calloc.
        Tipo: void
        Parâmetros:
            void* ptr: Ponteiro para o bloco de memória a ser liberado.
        Descrição completa: A função free é usada para liberar a memória alocada previamente por malloc, calloc, ou realloc. Após chamar free, o bloco de memória pode ser reutilizado para futuras alocações.

    Função calloc:
        Descrição breve: Aloca blocos de memória inicializados com zero.
        Tipo: void*
        Parâmetros:
            size_t num_items: Número de elementos.
            size_t size: Tamanho em bytes de cada elemento.
        Descrição completa: A função calloc aloca um bloco de memória para um número especificado de elementos, todos inicializados com zero. Retorna um ponteiro para o primeiro byte do bloco de memória.

    Função realloc:
        Descrição breve: Realloca um bloco de memória previamente alocado.
        Tipo: void*
        Parâmetros:
            void* ptr: Ponteiro para o bloco de memória a ser realocado.
            size_t size: Novo tamanho em bytes.
        Descrição completa: A função realloc é usada para alterar o tamanho de um bloco de memória previamente alocado. Pode expandir ou encolher o bloco, mantendo seu conteúdo original o máximo possível.

    Função atoi:
        Descrição breve: Converte uma string para um inteiro.
        Tipo: int
        Parâmetros:
            const char* str: String a ser convertida.
        Descrição completa: A função atoi converte uma string representando um número inteiro em um valor inteiro equivalente.

Essas são apenas algumas das funções fornecidas pela biblioteca stdlib.h. Elas são fundamentais para a manipulação de memória dinâmica, conversão de strings e outras operações essenciais em C.

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<stdnoreturn.h>
A biblioteca stdnoreturn.h em C não fornece funções, mas sim uma macro chamada noreturn. Aqui está o principal componente dessa biblioteca:

    Macro noreturn:
        Descrição breve: Indica que uma função nunca retorna.
        Uso: noreturn
        Descrição completa: A macro noreturn é usada para indicar ao compilador que uma função não deve retornar ao chamador. Isso é útil para funções que encerram o programa ou lançam exceções, informando ao compilador que não é necessário gerar código para lidar com um retorno dessas funções.

Essa macro é frequentemente usada em contextos onde uma função tem a intenção de encerrar o programa, como funções que chamam a função exit ou lançam exceções. O uso de noreturn ajuda o compilador a realizar otimizações específicas para essas situações e a gerar mensagens de aviso caso o código após a chamada da função não seja alcançável.

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<tgmath.h>
A biblioteca tgmath.h em C não fornece funções específicas, mas sim macros que adaptam funções matemáticas para trabalhar com argumentos de diferentes tipos, incluindo tipos primitivos e tipos definidos pelo usuário. Aqui estão algumas das principais macros dessa biblioteca:

    Macro cabs:
        Descrição breve: Retorna o valor absoluto de um número complexo.
        Tipo: Pode variar dependendo do tipo do argumento.
        Parâmetros: Pode variar dependendo do tipo do argumento.
        Descrição completa: A macro cabs é usada para calcular o valor absoluto de um número complexo. Pode ser usada com diferentes tipos de argumentos (float, double, long double) para adaptar-se automaticamente.

    Macro carg:
        Descrição breve: Retorna o argumento de um número complexo.
        Tipo: Pode variar dependendo do tipo do argumento.
        Parâmetros: Pode variar dependendo do tipo do argumento.
        Descrição completa: A macro carg é usada para retornar o argumento (ângulo) de um número complexo. Assim como cabs, ela se adapta automaticamente a diferentes tipos de argumentos.

    Macro cexp:
        Descrição breve: Calcula a exponenciação de um número complexo.
        Tipo: Pode variar dependendo do tipo do argumento.
        Parâmetros: Pode variar dependendo do tipo do argumento.
        Descrição completa: A macro cexp é usada para calcular a exponenciação de um número complexo. Ela se adapta automaticamente aos diferentes tipos de argumentos.

Essas são apenas algumas das macros oferecidas pela biblioteca tgmath.h. Elas permitem que as funções matemáticas sejam utilizadas de forma genérica, proporcionando flexibilidade no uso de tipos diferentes, incluindo tipos definidos pelo usuário.

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<threads.h>
A biblioteca threads.h em C11 introduz suporte para programação concorrente utilizando threads. Aqui estão algumas das principais funções dessa biblioteca:

    Função thrd_create:
        Descrição breve: Cria uma nova thread.
        Tipo: int
        Parâmetros:
            thrd_t* thr: Ponteiro para armazenar o identificador da nova thread.
            thrd_start_t func: Ponteiro para a função que a nova thread executará.
            void* arg: Argumento que será passado para a função da nova thread.
        Descrição completa: A função thrd_create cria uma nova thread que executa a função apontada por func com o argumento arg. O identificador da nova thread é armazenado em thr.

    Função thrd_exit:
        Descrição breve: Encerra a execução da thread atual.
        Tipo: void
        Parâmetros: int res: Resultado de saída da thread.
        Descrição completa: A função thrd_exit encerra a execução da thread atual, fornecendo um resultado de saída res. Isso encerra a thread e libera os recursos associados a ela.

    Função thrd_join:
        Descrição breve: Espera até que uma thread termine sua execução.
        Tipo: int
        Parâmetros:
            thrd_t thr: Identificador da thread a ser aguardada.
            int* res: Ponteiro para armazenar o resultado de saída da thread esperada.
        Descrição completa: A função thrd_join espera até que a thread identificada por thr termine sua execução. O resultado de saída da thread é armazenado em res.

    Função thrd_sleep:
        Descrição breve: Coloca a thread em espera por um período de tempo.
        Tipo: int
        Parâmetros:
            const struct timespec* time_point: Ponto no tempo até o qual a thread ficará em espera.
            struct timespec* remaining: Ponteiro para armazenar o tempo restante, caso a espera seja interrompida.
        Descrição completa: A função thrd_sleep coloca a thread em espera até o tempo especificado em time_point. O tempo restante (se houver) é armazenado em remaining.

Essas são algumas das funções principais da biblioteca threads.h em C11. Elas são usadas para criar, gerenciar e sincronizar threads em programas concorrentes, proporcionando uma forma padrão de trabalhar com threads na linguagem C.

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<time.h>
A biblioteca time.h em C fornece funções relacionadas à manipulação de tempo e data. Aqui estão algumas das principais funções dessa biblioteca:

    Função time:
        Descrição breve: Obtém o tempo atual em segundos desde a "época" (1º de janeiro de 1970).
        Tipo: time_t
        Parâmetros: time_t* timer
        Descrição completa: A função time retorna o tempo atual em segundos desde a "época" (1º de janeiro de 1970). O valor é armazenado no ponteiro timer se este não for nulo.

    Função difftime:
        Descrição breve: Calcula a diferença em segundos entre dois tempos.
        Tipo: double
        Parâmetros:
            time_t time1
            time_t time2
        Descrição completa: A função difftime calcula a diferença em segundos entre os tempos especificados (time1 e time2). O resultado é retornado como um valor de ponto flutuante.

    Função asctime:
        Descrição breve: Converte uma estrutura struct tm em uma string representando a hora.
        Tipo: char*
        Parâmetros:
            const struct tm* timeptr
        Descrição completa: A função asctime converte a estrutura struct tm representando um tempo em uma string de caracteres. O formato geralmente inclui informações como dia da semana, mês, dia, hora, minuto, segundo e ano.

    Função ctime:
        Descrição breve: Converte o tempo atual em uma string de caracteres.
        Tipo: char*
        Parâmetros:
            const time_t* timer
        Descrição completa: A função ctime converte o tempo atual especificado pelo ponteiro timer em uma string de caracteres, seguindo um formato semelhante ao de asctime.

    Função gmtime:
        Descrição breve: Converte o tempo para uma estrutura struct tm no fuso horário UTC.
        Tipo: struct tm*
        Parâmetros:
            const time_t* timer
        Descrição completa: A função gmtime converte o tempo especificado pelo ponteiro timer para uma estrutura struct tm representando o tempo no fuso horário UTC.

Essas são algumas das principais funções da biblioteca time.h. Elas são usadas para manipulação, formatação e conversão de valores de tempo em programas C.

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<uchar.h>
Até o meu conhecimento mais recente em janeiro de 2022, não existe uma biblioteca padrão chamada "uchar.h" na linguagem de programação C. Pode ser que novas bibliotecas ou padrões tenham sido introduzidos após essa data.

Se houver uma atualização ou extensão para a linguagem C que inclui uma biblioteca chamada "uchar.h", recomendo consultar a documentação mais recente ou fontes confiáveis para obter informações detalhadas sobre as funções fornecidas por essa biblioteca.
User

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

<wchar.h>
A biblioteca wchar.h em C fornece funções para manipulação de caracteres de largura estendida (wide characters) e operações relacionadas a strings wide. Aqui estão algumas das principais funções dessa biblioteca:

    Função wmemset:
        Descrição breve: Preenche um bloco de memória wide com um valor específico.
        Tipo: wchar_t*
        Parâmetros:
            wchar_t* dest: Ponteiro para o bloco de memória a ser preenchido.
            wchar_t value: Valor a ser utilizado para preenchimento.
            size_t num: Número de caracteres a serem preenchidos.
        Descrição completa: A função wmemset preenche os primeiros num caracteres do bloco de memória apontado por dest com o valor wide value.

    Função wmemcpy:
        Descrição breve: Copia caracteres wide de um bloco de memória para outro.
        Tipo: wchar_t*
        Parâmetros:
            wchar_t* dest: Ponteiro para o bloco de memória de destino.
            const wchar_t* src: Ponteiro para o bloco de memória de origem.
            size_t num: Número de caracteres a serem copiados.
        Descrição completa: A função wmemcpy copia os primeiros num caracteres do bloco de memória apontado por src para o bloco de memória apontado por dest.

    Função wcslen:
        Descrição breve: Retorna o comprimento de uma string wide.
        Tipo: size_t
        Parâmetros:
            const wchar_t* str: Ponteiro para a string wide.
        Descrição completa: A função wcslen retorna o número de caracteres wide em str até (mas não incluindo) o caractere nulo de terminação.

    Função wcscmp:
        Descrição breve: Compara duas strings wide.
        Tipo: int
        Parâmetros:
            const wchar_t* str1: Ponteiro para a primeira string wide.
            const wchar_t* str2: Ponteiro para a segunda string wide.
        Descrição completa: A função wcscmp compara as strings wide str1 e str2. Retorna um valor inteiro que indica a relação entre as strings.

Essas são apenas algumas das funções fornecidas pela biblioteca wchar.h. Elas são utilizadas para manipular e comparar strings wide, que são úteis quando se trabalha com caracteres de largura estendida.

<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
<!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

