#include <stdio.h>
#include"tad_arvore.h"

// WEsley Batista luz - Estrutura de dados
int main(void) {
  tipo_arvore arvore,arvore_copia;
  int dado,opcao,resultado_exclusao, quantidade=0, soma=0;

  arvore= criar_arvore();
  arvore_copia = criar_arvore();

  do
  {
     printf("\n\n0 - Sair\n");
        printf("1 - Incluir na árvore de forma recursiva\n");
        printf("2 - Incluir na árvore de forma iterativa\n");
        printf("3 - Listar Pré-ordem\n");
        printf("4 - Listar em ordem\n");
        printf("5 - Listar Pós-ordem\n");
        printf("6 - Excluir maior\n");
        printf("7 - Excluir menor\n");
        printf("8 - Excluir valor\n");
        printf("9 - buscar elemento na arvore\n");
        printf("10 - Media dos valores da arvore\n");
        printf("11 - Quantidade de NULLs da arvore\n");
        printf("12 -Quantidade de elementos multiplos de 3\n");
        printf("13 - Quantidade de Nós da arvore\n");
        printf("14 - Quantidade de Folhas\n");
        printf("15 - Saber Altura da arvore\n");
        printf("16- Verificar se é estritamente binaria\n");
        printf("17 - Copiar arvore\n");
        printf("18 - Verificar se a arvore é de busca\n");
        
       
        
        printf("Entre com a sua opção:");
        scanf("%d", &opcao);
        switch (opcao)
        {
          case 1: printf("\nDigite um valor:");
                  scanf("%d",&dado);
                  incluir_no_recursivo(arvore,dado);
                  break;

          case 2: printf("\nDigite um valor:");
                  scanf("%d",&dado);
                  incluir_no_iterativo(arvore, dado);
                  break;
  
          case 3: listar_pre_ordem(arvore);
                    break;

          case 4: listar_em_ordem(arvore);
                  break;

          case 5: listar_pos_ordem(arvore);
                  break;

          case 6: dado = excluir_maior(arvore);
                  printf("\nDado excluido: %d", dado);
                  break;

          case 7: dado = excluir_menor(arvore);
                  printf("\nDado excluido: %d", dado);
                  break;

          case 8: printf("Entre com um valor a excluir:");
                  scanf("%d", &dado);
                  resultado_exclusao = excluir_valor(arvore, dado);
                  break;
          
          case 9: printf("\nDigite um valor:");
                  scanf("%d",&dado);
                  if(verificar_elemento(arvore,dado)==1)
                    printf("\nO elemento faz parte da arvore.");
                  else
                    printf("\nO elemento nao faz parte da arvore.");
                  break;
                   
          case 10:
                  
                   printf("Media sem ponteiro: %2.f",media_sem_ponteiro(arvore));

                   
                   break;

          case 11: 
                    printf ("\nQuantidade de nulls = %d", quantidade_de_null(arvore)); 
                    break;

          case 12: 
                  printf("numero multiplos de 3: %d",calcular_quantidade_de_multiplos (arvore));
                  break;

          case 13: printf("\nQuantidadede de nós:%d", contarNos(arvore));
                   break;

          case 14: printf("Quantidade de Folhas: %d",numero_de_folhas(arvore));
                  break;

          case 15: printf("Altura da arvore: %d",altura_arvore(arvore));
                   break;

          case 16: if(estritamente_binario(arvore)==1)
                      printf("\nA arvore é estritamente binaria");
                   else
                      printf("\nA arvore não é estritamente binaria");
                   break;

          case 17: copiar_arvore(arvore,arvore_copia);
                   break;
          case 18: if (verificar_arvore_de_busca(arvore)){
                        printf("\nA Arvore é de busca"); 
                    }
                    else{
                        printf("\nA Arvore nao é de busca");
                    }
                    break;  
          
          
        }
  }while(opcao!=0); 
  

  return 0;
}