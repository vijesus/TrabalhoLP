struct produto{
    int codigo;
    char descricao[51];
    int quantidade;
    double preco;
};
typedef struct produto Produto;

void inicializar(Produto *p[], int tamanho);

int cadastrar(Produto *p[], int posicao);

void procurar(Produto *p[],int tamanho, int codigo);

void comprar(Produto *p[], int tamanho, int codigo, int qtd);

void vender(Produto *p[], int tamanho, int codigo, int qtd);

void listar(Produto *p[], int tamanho);

void imprimir(Produto *p);

void limpar();

void linha();

void linhaLonga();
