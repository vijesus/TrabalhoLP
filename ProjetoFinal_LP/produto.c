#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

void inicializar(Produto *p[], int tamanho){
    for(int i=0; i<tamanho; i++){
        p[i] = NULL;
    }
}


int cadastrar(Produto *p[], int posicao){
    int cProd = 0;
    int codExiste = 0;

    p[posicao] = (Produto*) malloc(sizeof(Produto));
    fflush(stdin);

    printf("Digite o codigo do produto: ");
    scanf("%d", &cProd);

    for(int i=0; i<posicao; i++){
        if(p[i]->codigo == cProd){
            linha();
            printf("***Codigo ja existe!***\n");
            codExiste = 1;
            break;
        }
    }
    if(codExiste == 0){
        p[posicao]->codigo = cProd;

        fflush(stdin);
        printf("Digite a descricao do produto: ");
        scanf("%[^\n]", p[posicao]->descricao);

        fflush(stdin);
        printf("Digite a quantidade inicial do produto: ");
        scanf("%d", &p[posicao]->quantidade);

        fflush(stdin);
        printf("Digite o preco do produto: ");
        scanf("%lf", &p[posicao]->preco);
        linhaLonga();
        printf("***Produto cadastrado com sucesso!***\n");
        return 1;
    }else{
        return 0;
    }
}

void procurar(Produto *p[],int tamanho, int codigo){

    for(int i=0; i<tamanho; i++){
        if(p[i]->codigo == codigo){
            linha();
            imprimir(p[i]);
            return;
        }
    }
    linha();
    printf("***Codigo nao encontrado!***\n");
}

void comprar(Produto *p[], int tamanho, int codigo, int qtd){
    for(int i=0; i<tamanho; i++){
        if(p[i]->codigo == codigo){
            p[i]->quantidade += qtd;
            linhaLonga();
            printf("***Quantidade alterada com sucesso!***\n");
            return;
        }
    }
    linha();
    printf("***Codigo nao encontrado***\n");
}

void vender(Produto *p[], int tamanho, int codigo, int qtd){
    for(int i=0; i<tamanho; i++){
        if(p[i]->codigo == codigo){
            if(p[i]->quantidade >= qtd){
                p[i]->quantidade -= qtd;
                linhaLonga();
                printf("Quantidade alterada com sucesso!\n\n");
                return;
            }else{
                linhaLonga();
                printf("***Quantidade de venda maior que a do estoque***\n");
                printf("***Quantidade atual = %d ***\n", p[i]->quantidade);
                return;
            }
        }
    }
    linhaLonga();
    printf("***Codigo nao encontrado!***\n");
}

void listar(Produto *p[], int tamanho){
    linha();
    for(int i=0; i<tamanho; i++){
        imprimir(p[i]);
    }
}

void imprimir(Produto *p){
    printf("     Codigo: %d \n", p->codigo);
    printf("  Descricao: %s \n", p->descricao);
    printf(" Quantidade: %d \n", p->quantidade);
    printf("      Preco: %.2f \n", p->preco);
    linha();
}

void limpar(){
    printf("\n");
    system("pause");
    system("cls");
}

void linha(){
    printf("-----------------\n");
}

void linhaLonga(){
    printf("-------------------------------------\n");
}
