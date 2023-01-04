typedef struct reg_no tipo_no;
typedef tipo_no **tipo_arvore;
// wesley Batista luz - Estrutura de dados
tipo_arvore criar_arvore();
void incluir_no_recursivo(tipo_no **sub_raiz, int dado);
void listar_pre_ordem(tipo_no **sub_raiz);
void listar_em_ordem(tipo_no **sub_raiz);
void listar_pos_ordem(tipo_no **sub_raiz);
int verificar_elemento(tipo_no **sub_raiz,int dado);
int excluir_maior(tipo_no **sub_raiz);
int excluir_menor(tipo_no **sub_raiz);
int excluir_valor(tipo_no **sub_raiz, int dado);
void incluir_no_iterativo(tipo_no **sub_raiz,int dado);
int quantidade_de_null (tipo_no** sub_raiz);

float media_sem_ponteiro(tipo_no **sub_raiz);
int soma_elementos(tipo_no **sub_raiz) ;
int calcular_quantidade_de_multiplos (tipo_no** sub_raiz);
int contarNos(tipo_no **sub_raiz);
int numero_de_folhas(tipo_no **sub_raiz);
int altura_arvore(tipo_no **sub_raiz);
int estritamente_binario(tipo_no **sub_raiz);
void copiar_arvore (tipo_no** sub_raiz, tipo_no** sub_raiz_copia);
int verificar_arvore_de_busca (tipo_no** sub_raiz);

