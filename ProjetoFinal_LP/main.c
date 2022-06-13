#include <stdio.h>
#include <stdlib.h>
#define T 1000
#include "produto.h"
#include <locale.h>

/*
    TRABALHO DE LINGUAGEM DE PROGRAMAÇÃO
    REALIZADO PELOS ALUNOS DA FATEC DE MOGI MIRIM

    -GABRIEL TRANI AVANCINI
    -GUILHERME DA SILVA FREIRE
    -VINÍCIUS SILVA DE JESUS
*/

int main(){

    setlocale(LC_ALL,"Portuguese");

    Produto * vetProd[T];
    inicializar(vetProd, T);
    int pos = 0;
    int opc = 0;
    int codProd = 0;
    int qtd = 0;
    int auxCadBool = 0;
    do{
        printf("Menu Principal\n");
        printf("1. Cadastrar\n");
        printf("2. Procurar\n");
        printf("3. Comprar\n");
        printf("4. Vender\n");
        printf("5. Listar\n");
        printf("9. Fim\n");
        printf("--------------\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opc);
        switch(opc){
            case 1:
                auxCadBool = cadastrar(vetProd, pos);
                if( auxCadBool == 1){
                    pos++;
                }
                limpar();
                break;
            case 2:
                fflush(stdin);
                printf("Digite o codigo do produto a procurar: ");
                scanf("%d", &codProd);
                procurar(vetProd, pos, codProd);
                limpar();
                break;
            case 3:
               fflush(stdin);
                printf("Digite o codigo do produto a comprar: ");
                scanf("%d", &codProd);
                printf("Digite a quantidade da compra: ");
                scanf("%d", &qtd);
                comprar(vetProd, pos, codProd, qtd);
                limpar();
                break;
            case 4:
                fflush(stdin);
                printf("Digite o codigo do produto a vender: ");
                scanf("%d", &codProd);
                printf("Digite a quantidade da venda: ");
                scanf("%d", &qtd);
                vender(vetProd, pos, codProd, qtd);
                limpar();
                break;
            case 5:
                listar(vetProd, pos);
                limpar();
                break;
            case 9:
                printf("\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }while(opc!=9);
    printf("Programa Finalizado.\n");
    return 0;
}
