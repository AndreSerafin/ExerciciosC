#define MAX 100

struct aluno {
    int matricula;
    char nome[40];
    float n1, n2, n3;
};

typedef struct lista Lista;

Lista* cria_lista();

void libera_lista(Lista* li);

int tamanho_lista(Lista* li);

int lista_cheia(Lista* li);

int lista_vazia(Lista* li);