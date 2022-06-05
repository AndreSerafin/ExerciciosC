#include <stdio.h>
#include <vector>
#include <algorithm>

/*Sabe-se que um documento so pode ser cadastrado para um cliente que ja exista. Considere que podem existir,no maximo,15 clientes e 30 documentos.Crie um vetor 
para clientes e outro para documentos.Crie um menu para a realizacao de cada uma das operacoes especificadas a seguir.
a)Cadastrar clientes- nao pode existir mais que um cliente comomesmo codigo.
b)Cadastrar documentos-ao cadastrar um documento,seadata de pagamento for maior queadata de venci mento,calcular o campo'juros'do registro documentos
(5% sobreovalor original do documento).
c)Excluir clientes-um cliente so podera ser excluído se nao existir nenhum documento associadoaele.
d)Excluir documentos individuais-por meio de seu numero.Caso o documento nao exista,o programa devera mostrar a mensagem Documento nao encontrado.
e)Excluir documentos por cliente - o programa devera informar o codigo do cliente e excluir todos os seus documentos.Casoocliente nao exista,devera mostrar 
a mensagem Cliente nao encontrado.
f)Excluir documentos por período- o programa devera informar a data inicial e a data final e excluir todos os documentos que possuam data de vencimento nesse 
período.
g)Alterar as informacoes sobre os clientes- so nao pode ser alterado o codigo do cliente.
h)Mostrar o total de documentos de determinado cliente.
i)Sair.
Quando forem excluídos clientes ou documentos,os vetores deverao ser reorganizados,ou seja, todas as posicoes nao preenchidas dos vetores deverao ficar no 
final.Exemplo:se for necessario excluir o numero 8 do vetor a seguir,tanto o 9 quantoo 1 deverao ser movidos uma casa para a esquerda e a ultima posicao 
devera ficar livre para uma nova inclusao.*/

typedef struct {

    int codCliente;
    char nome[50];
    int telefone;
    char endereco;

}Clientes;

typedef struct{

    int numDocumento;
    int codCliente;
    int dataVencimento;
    int dataPagamento;
    float valor;
    float juros;
}Documento;

int main(){



}

