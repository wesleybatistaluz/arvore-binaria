#include<stdio.h>
#include<stdlib.h>
// wesley Batista luz - Estrutura de dados
typedef struct reg_no{
  struct reg_no *ptr_esquerda;
  int dado;
  struct reg_no *ptr_direita;
}tipo_no;

typedef tipo_no **tipo_arvore;


tipo_arvore criar_arvore()
{
  return (tipo_no**)malloc(sizeof(tipo_no*));
}
// 164- recursiva
void incluir_no_recursivo(tipo_no **sub_raiz,int dado)
{
  if(*sub_raiz==NULL)
  {
    *sub_raiz=(tipo_no*)malloc(sizeof(tipo_no));
    (*sub_raiz)->dado=dado;
    (*sub_raiz)->ptr_esquerda=NULL;
    (*sub_raiz)->ptr_direita=NULL;
  }
  else
  {
    if(dado<(*sub_raiz)->dado)
    {
      incluir_no_recursivo(&((*sub_raiz)->ptr_esquerda),dado);
    }
    else
    {
      if(dado>(*sub_raiz)->dado)
      {
        incluir_no_recursivo(&((*sub_raiz)->ptr_direita),dado);
      }
    }
  }

}
// questao 164 -iterativa
void incluir_no_iterativo(tipo_no **sub_raiz, int dado){
  
  while(*sub_raiz!=NULL)
  {    
    if(dado<(*sub_raiz)->dado){
      sub_raiz=(&(*sub_raiz)->ptr_esquerda);
    }
    else if(dado>(*sub_raiz)->dado){
      sub_raiz=(&(*sub_raiz)->ptr_direita);
    }        
  }

  *sub_raiz= (tipo_no *) malloc(sizeof(tipo_no));
  (*sub_raiz)->ptr_esquerda=NULL;
  (*sub_raiz)->dado=dado;
  (*sub_raiz)->ptr_direita=NULL;
 
}
// 165
void listar_pre_ordem(tipo_no **sub_raiz)
{
  if((*sub_raiz)!= NULL)
  {
    printf("%d ",(*sub_raiz)->dado);
    listar_pre_ordem(&((*sub_raiz)->ptr_esquerda));
    listar_pre_ordem(&((*sub_raiz)->ptr_direita));
  }
}
// 166
void listar_em_ordem(tipo_no **sub_raiz)
{
  if((*sub_raiz)!= NULL)
  {
    listar_em_ordem(&((*sub_raiz)->ptr_esquerda));
    printf("%d ",(*sub_raiz)->dado);
    listar_em_ordem(&((*sub_raiz)->ptr_direita));
  }
}


// 167
void listar_pos_ordem(tipo_no **sub_raiz)
{
  if((*sub_raiz)!= NULL)
  {
    listar_pos_ordem(&((*sub_raiz)->ptr_esquerda));
    listar_pos_ordem(&((*sub_raiz)->ptr_direita));
    printf("%d ",(*sub_raiz)->dado);
  }
}
// Questao 168
int verificar_elemento(tipo_no **sub_raiz,int dado)
{

  if(*sub_raiz==NULL)
    return 0;

  else
  {
    if(dado==(*sub_raiz)->dado)
        return 1;

    else if(dado<(*sub_raiz)->dado)
    verificar_elemento(&((*sub_raiz)->ptr_esquerda),dado);

    else if(dado>(*sub_raiz)->dado)
    verificar_elemento(&((*sub_raiz)->ptr_direita),dado);
  }
 
}

// Questao 169
int excluir_maior(tipo_no **sub_raiz)
{
  int dado;
  tipo_no *auxiliar;

  if((*sub_raiz)!=NULL)
  {
    if((*sub_raiz)->ptr_direita!=NULL)
    {
     return excluir_maior(&((*sub_raiz)->ptr_direita));
    }
    else
    {
      dado=(*sub_raiz)->dado;
      auxiliar= *sub_raiz;
      *sub_raiz=(*sub_raiz)->ptr_esquerda;
      free(auxiliar);
      return dado;
    }
  }
  return -1;
}
// Questao 170
int excluir_menor(tipo_no **sub_raiz)
{
  int dado;
  tipo_no *auxiliar;

  if((*sub_raiz)!=NULL)
  {
    if((*sub_raiz)->ptr_esquerda!=NULL)
    {
      return excluir_menor(&((*sub_raiz)->ptr_esquerda));
    }
    else
    {
      dado=(*sub_raiz)->dado;
      auxiliar= *sub_raiz;
      *sub_raiz=(*sub_raiz)->ptr_direita;
      free(auxiliar);
      return dado;
    }
  }
  return -1;
}

int excluir_valor(tipo_no **sub_raiz, int dado)
{
    tipo_no *auxiliar;
    if ((*sub_raiz) != NULL)
    {
        if (dado < (*sub_raiz)->dado)
        {
            return excluir_valor(&((*sub_raiz)->ptr_esquerda), dado);
        }
        else
        {
            if (dado > (*sub_raiz)->dado)
            {
                return excluir_valor(&((*sub_raiz)->ptr_direita), dado);
            }
            else
            {
                if ((*sub_raiz)->ptr_esquerda == NULL)
                {
                    auxiliar = *sub_raiz;
                    *sub_raiz = (*sub_raiz)->ptr_direita;
                    free(auxiliar);
                }
                else
                {
                    if ((*sub_raiz)->ptr_direita == NULL)
                    {
                        auxiliar = *sub_raiz;
                        *sub_raiz = (*sub_raiz)->ptr_esquerda;
                        free(auxiliar);
                    }
                    else
                    {
                        (*sub_raiz)->dado = excluir_maior(&((*sub_raiz)->ptr_esquerda));
                    }
                }
                return dado;
            }
        }
    }
    return -1;
}


//171 media sem usar ponteiro
float media_sem_ponteiro(tipo_no **sub_raiz){
  return soma_elementos(sub_raiz) / contarNos(sub_raiz);
}

//172. Construir uma função para retornar o número de NULLs presentes em uma árvore.

int quantidade_de_null (tipo_no** sub_raiz){
    if ((*sub_raiz) != NULL) 
       return 0+ quantidade_de_null (&((*sub_raiz)->ptr_esquerda))+ quantidade_de_null (&((*sub_raiz)->ptr_direita));      
    
    else // sempre que for vazio retorna 1
      return 1;   
}
//173. Construir uma função para retornar a soma dos valores dos nós.
int soma_elementos(tipo_no **sub_raiz) 
{
  if((*sub_raiz)== NULL)
   {
        return 0;
   }
   else
        return (*sub_raiz)->dado + soma_elementos(&((*sub_raiz)->ptr_esquerda)) + soma_elementos((&((*sub_raiz)->ptr_direita)));

}
//174. Construir uma função para retornar o número de nós cujos valores sãomúltiplos de três.
int calcular_quantidade_de_multiplos (tipo_no** sub_raiz)
{
     
    if ((*sub_raiz) != NULL)
    {
        if ((*sub_raiz)->dado % 3 == 0)
             return 1+ calcular_quantidade_de_multiplos (&((*sub_raiz)->ptr_esquerda))+ calcular_quantidade_de_multiplos (&((*sub_raiz)->ptr_direita));  //se for primo incrementa e testa percorrendo todos da esquerda e direita

         else 
           return 0+ calcular_quantidade_de_multiplos (&((*sub_raiz)->ptr_esquerda))+ calcular_quantidade_de_multiplos (&((*sub_raiz)->ptr_direita)); // se n for primo nao incrementa e continua percorrendo os da direita e esquerda testando a condição

    }
    else // se a lista for vazia retorna 0
      return 0;

}


//175. Construir uma função para retornar o número de nós de uma árvore.
int contarNos(tipo_no **sub_raiz)
{
   if((*sub_raiz)== NULL)
   {
        return 0;
   }
   else
        return 1 + contarNos(&((*sub_raiz)->ptr_esquerda)) + contarNos((&((*sub_raiz)->ptr_direita)));
}
//176. Construir uma função para retornar o número de folhas de uma árvore.
int numero_de_folhas(tipo_no **sub_raiz)
{
  if((*sub_raiz) == NULL)
    return 0;
  else
  {
    if(((*sub_raiz)->ptr_esquerda == NULL) &&((*sub_raiz)->ptr_direita==NULL))
      return 1;
    else
      return numero_de_folhas(&((*sub_raiz)->ptr_esquerda)) + numero_de_folhas(&(*sub_raiz)->ptr_direita);
  }
}
//177. Construir uma função para retornar a altura de uma árvore.
int altura_arvore(tipo_no **sub_raiz)
{
  int altura_esquerda, altura_direita;

  if ((*sub_raiz) == NULL)
  {
      return -1; // altura da árvore vazia
  }
  else
  {
    altura_esquerda = altura_arvore(&((*sub_raiz)->ptr_esquerda));
    altura_direita = altura_arvore(&((*sub_raiz)->ptr_direita));
    if (altura_esquerda< altura_direita)
        return altura_direita + 1;

    else
      return altura_esquerda + 1;
  }
}

/*178. Construir uma função para verificar se uma árvore é estritamente binária
(uma árvore é estritamente binária caso todos os seus nós possuam 2 filhos ou
sejam folhas).*/
int estritamente_binario(tipo_no **sub_raiz)
{
  if((*sub_raiz) != NULL)
  {
    if((((*sub_raiz)->ptr_esquerda == NULL) &&((*sub_raiz)->ptr_direita!=NULL)) || (((*sub_raiz)->ptr_esquerda != NULL) &&((*sub_raiz)->ptr_direita==NULL)))
    
      return 0;
    
    else
      return estritamente_binario(&((*sub_raiz)->ptr_esquerda))&& estritamente_binario(&(*sub_raiz)->ptr_direita);
  }
  return 1;
}
/*179. Construir uma função para criar uma cópia de uma árvore.*/

void copiar_arvore (tipo_no** sub_raiz, tipo_no** sub_raiz_copia)
{
     
    if ((*sub_raiz) != NULL)
    {
       incluir_no_recursivo(sub_raiz_copia, (*sub_raiz)->dado);
       copiar_arvore(&((*sub_raiz)->ptr_esquerda), sub_raiz_copia); 
       copiar_arvore(&((*sub_raiz)->ptr_direita), sub_raiz_copia);
    }
}
/*182. Escreva uma função que decida se uma dada árvore binária é ou não é de
busca.*/
int verificar_arvore_de_busca (tipo_no** sub_raiz)
{
     
    if ((*sub_raiz) != NULL){
      if (((*sub_raiz)->dado > verificar_arvore_de_busca(&((*sub_raiz)->ptr_esquerda))) || ((*sub_raiz)->dado < verificar_arvore_de_busca(&((*sub_raiz)->ptr_direita))))
      return 1;
    }
    return 0;
}










