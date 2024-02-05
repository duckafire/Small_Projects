# errno (0; 1)
Fornece uma variável global chamada **errno**, seu valor é alterado por diversas funções da biblioteca padrão, para indicar erros.

1. extern int **errno**;
	* Armazena códigos de error retornados por várias funções da bilioteca padrão de C. Quando uma função encontra um erro, ela modifica o valor de **errno** para indicar o tipo
		especifico de erro que ocorreu.
	* Possíveis valores (podem variar entre sistemas operacionais distintos):
		
		| Nome    | Descrição												   |     | Nome         | Descrição 											|
		| :-:     | :-:       												   | :-: | :-:          | :-:       											|
		| EINVAL  | Argumento inválido          							   |     | EEXIST       | O arquivo ou diretório já existe          			|
		| ENOMEM  | Falha na alocação de memória  					           |     | ENOTDIR      | Não é um diretório          							|
		| EIO     | Erro de entrada/saída        						       |     | ENOTEMPTY    | Diretório não vazio         						 	|
		| EFAULT  | Endereço inválido         								   |     | EOVERFLOW    | Valor resultante muito grande para ser armazenado     |
		| EACESS  | Permissão negada        								   |     | EWOULDBLOCK  | Operação bloqueada ou exigiria bloqueio          		|
		| ENOSPC  | Sem espaço disponível no dispositivo     			       |     | ENRAGE       | Resultado fora do alcance          					|
		| EPERM   | Operação não permitida         							   |     | EISDIR       | É um diretório, quando deveria ser um arquivo regular |
		| EAGAIN  | Recurso temporariamente indisponível         			   |     | ENODEV       | Dispositivo não encontrado          					|
		| ENFILE  | Tabela de arquivos do processo cheia         			   |     | ENOSYS       | Função não implementada          						|
		| EMFILE  | Limite de descritores do arquivo atigindo    	 	       |     | ENAMETOOLONG | Nome do arquivo muito longo          					|
		| EPIPE   | *Tubo/pipe* quebrado          							   |     | ECONNRESET   | Conexão resetada pelo *peer*          				|
		| EINTR   | Chamada de sistema interrompida por sinal         		   |     | ECONNREFUSED | Conexão recusada          							|
		| ENOTTY  | Não é um terminal        								   |     | ETIMEDOUT    | Conexão expirou          								|
		| ESPIPE  | Busca em *pipe* ou dispositivo de armazenamento sequencial |     | ENETUNREACH  | Rede inalcançável          							|
		| ENXIO   | Dispositivo ou endereço inválido          				   |     | ENOMSG       | Sem mensagem do tipo desejado          				|