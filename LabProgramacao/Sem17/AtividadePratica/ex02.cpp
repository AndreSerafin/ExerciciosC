#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <locale.h>
#include <conio.h>

std::vector<int> codsClientes;
std::vector<int> numsDocumentos;

typedef struct {

    int codCliente;
    char nome[50];
    int telefone;
    char endereco[100];

}Clientes;

typedef struct{

    int numDocumento;
    int codCliente;
    int diaVenc, mesVenc, anoVenc;
    int diaPag, mesPag, anoPag;
    float valor;
    float juros = valor * 0.05;

}Documentos;

bool contem(int num, std::vector<int> &v){
    bool contem = false;
    if (std::count(v.begin(), v.end(), num)) {
        contem = true;
    }else {
        contem = false;
    }

    return contem;
}

std::vector<Documentos> registrarDocumentos() {
    
    std::vector<Documentos> documentos;
    int n, num;
    bool aux;

    printf("Quantidade de documentos que serao cadastrados: \n"); 
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        Documentos d; 
        printf("\nNumero do documento: \n • ");
        scanf("%d", &num);

        aux = contem(num, numsDocumentos);

        if(aux == true) {
            int cont = 0;
            do{
                numsDocumentos.push_back(num);
                printf("Numero Invalido!\nDigite novamente: \n • ");
                scanf("%d", &num);
                aux = contem(num, numsDocumentos);
                numsDocumentos.push_back(num);
                d.numDocumento = num;
                cont++;
                if(cont > 10){
                    break;
                }
            }while(aux == true);
        }else{
            numsDocumentos.push_back(num);         
            d.numDocumento = num;
        }

        printf("Codigo do cliente: \n • ");
        scanf("%d", &d.codCliente);
        printf("Data de vencimento (dd/mm/aaaa): \n • ");
        scanf("%d%*c%d%*c%d", &d.diaVenc, &d.mesVenc, &d.anoVenc);
        while(d.diaVenc > 31 || d.mesVenc > 12 || d.anoVenc < 0){
            printf("Data Invalida!\nDigite novamente: \n • ");
            scanf("%d%*c%d%*c%d", &d.diaVenc, &d.mesVenc, &d.anoVenc);                
        }
        printf("Data de pagamento (dd/mm/aaaa): \n • ");
        scanf("%d%*c%d%*c%d", &d.diaPag, &d.mesPag, &d.anoPag);
        while(d.diaPag > 31 || d.mesPag > 12 || d.anoPag < 0){
            printf("Data Invalida!\nDigite novamente: \n • ");
            scanf("%d%*c%d%*c%d", &d.diaPag, &d.mesPag, &d.anoPag);                
        }
        printf("Valor pago \n • ");
        scanf("%f", &d.valor);
        if(d.anoPag > d.anoVenc || d.mesPag > d.mesVenc){
            d.valor += (d.valor * 0.05);
            //printf("Fora do prazo");
        }else if(d.diaPag > d.diaVenc && d.mesPag == d.mesVenc){
            d.valor += (d.valor * 0.05);
            //printf("Fora do prazo");
        }else if(d.diaVenc > d.diaVenc && d.anoPag == d.anoPag){
            d.valor += (d.valor * 0.05);
            //printf("Fora do prazo");
        }

        documentos.push_back(d);
    }

    return documentos;
}

std::vector<Clientes> registarClientes() {

    std::vector<Clientes> cliente;
    int n, cod;
    bool aux;

    printf("Quantidade de clientes que serao cadastrados: \n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        Clientes c;
        printf("\nCodigo do cliente:\n • ");
        scanf("%d", &cod);
        
        aux = contem(cod, codsClientes);

        if(aux == true) {
            do{
                codsClientes.push_back(cod);
                printf("Codigo Invalido!\nDigite novamente:\n • ");
                scanf("%d", &cod);
                aux = contem(cod, codsClientes);
                codsClientes.push_back(cod);
                c.codCliente = cod;
            }while(aux == true);
        }else{
            codsClientes.push_back(cod);         
            c.codCliente = cod;
        }

        getchar();
        printf("Nome do cliente:\n • ");
        fgets(c.nome, sizeof(c.nome), stdin);
        printf("Telefone:\n • ");
        scanf("%d", &c.telefone);
        getchar();
        printf("Endereco:\n • ");
        fgets(c.endereco, sizeof(c.endereco), stdin);
        
        cliente.push_back(c);

    }
    return cliente;
}

std::vector<Clientes> alterarInformacoesClientes(std::vector<Clientes> &cli) {
    
    int cod;

    printf("Codigo do cliente:\n");
    scanf("%d", &cod);

    for (int i = 0; i < cli.size(); i++) {
        if(cli[i].codCliente == cod) {
            int op;
            do{
                printf("\n|----------------------|\n");
                printf("|       Alterar:       |\n");
                printf("|      0. Voltar:      |\n");
                printf("|       1. Nome:       |\n");
                printf("|     2. Telefone:     |\n");
                printf("|     3. Endereco:     |\n");
                printf("|----------------------|\n");
                
                scanf("%d", &op);

                switch(op) {
                    case 0: {
                        break;
                    }
                    case 1: {
                        printf("Nome: ");
                        getchar();
                        fgets(cli[i].nome, sizeof(cli[i].nome), stdin);
                        getch();
                        break;
                    }
                    case 2: {
                        printf("Telefone: ");
                        scanf("%d", &cli[i].telefone);
                        getch();
                        break;
                    }
                    case 3: {
                        printf("Endereco: ");
                        getchar();
                        fgets(cli[i].endereco, sizeof(cli[i].endereco), stdin);
                        getch();
                        break;
                    }default: {
                        printf("Opcao Invalida!\n");
                        getch();
                        break;
                    }
                }

            }while(op != 0);
        }
    }

    return cli;
}

std::vector<Clientes> excluirClientes(std::vector<Clientes> &cli, std::vector<Documentos> &docs) {

    char nome[50];
    int index;
    printf("\nNome do cliente: \n");
    fgets(nome, sizeof(nome), stdin);
    for (int i = 0; i < cli.size(); i++) {
        if(strcmp(cli[i].nome, nome) == 0){
            index = i;
        }
    }

    for(int j = 0; j < docs.size(); j++) {
        if(strcmp(cli[index].nome, nome) == 0 && cli[index].codCliente != docs[j].codCliente){
            cli.erase(cli.begin() + index);
        }else{
            printf("Impossivel excluir!");
            break;
        }
    }
    
    
    
    return cli;

}

std::vector<Documentos> excluirDocsPorNum(std::vector<Documentos> &docs) {

    int numDoc, index;
    bool aux = false;

    printf("\nNumero do documento: ");
    scanf("%d", &numDoc);

    for(int i = 0; i < docs.size(); i++) {
        if(numDoc == docs[i].numDocumento) {
           aux = true;
           index = i;
        }else{
            aux = false;
        }
    }

    if(aux == true) {
        docs.erase(docs.begin() + index);
    }else {
        printf("Nenhum documento encontrado!");
    }
    

    return docs;
}

std::vector<Documentos> excluirDocsPorCliente(std::vector<Clientes> &cli, std::vector<Documentos> &docs) {
    
    char nome[50];
    int index;

    printf("Nome do cliente: \n");
    fgets(nome, sizeof(nome), stdin);

    for (int i = 0; i < cli.size(); i++) {
        if(strcmp(cli[i].nome, nome) == 0){
            index = i;
        }
    }

    for(int i = 0; i < docs.size(); i++) {
        if(strcmp(cli[index].nome, nome) == 0 && docs[i].codCliente == cli[index].codCliente) {
            docs.erase(docs.begin() + i);
        }
    }

    return docs;
}

std::vector<Documentos> excluirDocsPorPeriodo(std::vector<Documentos> &docs) {

    int diaI, mesI, anoI, diaF, mesF, anoF, index;
    bool aux = false;
    printf("Data Inicial: \n");
    scanf("%d%*c%d%*c%d", &diaI, &mesI, &anoI);
    printf("Data Final: \n");
    scanf("%d%*c%d%*c%d", &diaF, &mesF, &anoF);

    for (int i = 0; i < docs.size(); i++) {
        if (docs[i].diaVenc >= diaI && docs[i].diaVenc <= diaF && docs[i].mesVenc >= mesI 
        && docs[i].mesVenc <= mesF && docs[i].anoVenc >= anoI && docs[i].anoVenc <= anoF) {
            aux = true;
            index = i;
        }
        if (docs[i].mesVenc >= mesI && docs[i].mesVenc <= mesF && docs[i].anoVenc >= anoI && docs[i].anoVenc <= anoF) {
            aux = true;
            index = i;
        }
        if (docs[i].anoVenc >= anoI && docs[i].anoVenc <= anoF) {
            aux = true;
            index = i;
        }
        if (aux == true) {
            docs.erase(docs.begin() + index);
        } 
    }


    return docs;

}

void mostrarUmCliente(std::vector<Clientes> &cli, std::vector<Documentos> &docs) {

    char nome[50];
    printf("Nome do cliente: ");
    fgets(nome, sizeof(nome), stdin);
    bool aux = false;
    int soma;
    
    printf("\n%s", nome);

    for(int i = 0; i < cli.size(); i++) {
        for(int j = 0; j < docs.size(); j++) {
            
            if(strcmp(cli[i].nome, nome) == 0 && cli[i].codCliente == docs[j].codCliente) {
                soma++;
                printf("\nNumero: %d\n", docs[j].numDocumento);
                printf("Codigo: %d\n", docs[j].codCliente);
                printf("Data de vencimento: %d/%d/%d\n", docs[j].diaVenc, docs[j].mesVenc, docs[j].anoVenc);
                printf("Data de pagamento: %d/%d/%d\n", docs[j].diaPag, docs[j].mesPag, docs[j].anoPag);
                printf("Valor: R$ %.2f\n", docs[j].valor);
            }

        }
    }
    printf("\nTotal de documentos: %d\n", soma);
}

void mostrarTodosClientes(std::vector<Clientes> &cli) {
    for (int i = 0; i < cli.size(); i++) {
        printf("\nCodigo: %d\n", cli[i].codCliente);
        printf("Nome: %s", cli[i].nome);
        printf("Telefone: %d\n", cli[i].telefone);
        printf("Endereco: %s\n", cli[i].endereco);
    }
}

void mostrarTodosDocumentos(std::vector<Documentos> &docs) {
    for (int i = 0; i < docs.size(); i++) {
        printf("\nNumero: %d\n", docs[i].numDocumento);
        printf("Codigo: %d\n", docs[i].codCliente);
        printf("Data de vencimento: %d/%d/%d\n", docs[i].diaVenc, docs[i].mesVenc, docs[i].anoVenc);
        printf("Data de pagamento: %d/%d/%d\n", docs[i].diaPag, docs[i].mesPag, docs[i].anoPag);
        printf("Valor: R$ %.2f\n", docs[i].valor);
    }
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    int op;
    bool key = false;
    std::vector<Clientes> cli;
    std::vector<Documentos> docs;


    do{
    	system("cls");
        printf("\n|-------------------------------------------------------------------------|\n");
        printf("|                              Menu de opcoes:                            |\n");
        printf("|                          0. Finalizar programa:                         |\n");
        printf("|                          1. Cadastrar clientes:                         |\n");
        printf("|                        2. Cadastrar documentos:                         |\n");
        printf("|                 3. Mostar todos clientes cadastrados:                   |\n");
        printf("|                4. Mostar todos documentos cadastrados:                  |\n");
        printf("|                          5. Excluir clientes:                           |\n");
        printf("|                6. Excluir documentos a partir do numero:                |\n");
        printf("|                    7. Excluir documentos por cliente:                   |\n");
        printf("|                    8. Excluir documentos por periodo:                   |\n");
        printf("|                   9. Alterar informacoes de clientes:                   |\n");
        printf("|         10. Mostrar o total de documentos de determinado cliente:       |\n");
        printf("|-------------------------------------------------------------------------|\n\n");

        scanf("%d", &op);
        getchar();

        switch (op) {
            case 0: {
                break;
            }
            case 1: {
            	system("cls");
                cli = registarClientes();
                key = true;
                break;
            }
            case 2: {
            	system("cls");
                docs = registrarDocumentos();
                key = true;
                break;
            }
            case 3: {
            	system("cls");
                if (key == true) {
                    mostrarTodosClientes(cli);             
                }else{
                    printf("\nNenhum cliente registrado!\n");
                }
                getch();
                break;
            }
            case 4: {
            	system("cls");
                if (key == true) {
                    mostrarTodosDocumentos(docs);         
                }else{
                    printf("\nNenhum documento registrado!\n");
                }
                getch();
                break;
            }
            case 5: {
            	system("cls");
                if (key == true) {
                    cli = excluirClientes(cli, docs);             
                }else{
                    printf("\nNenhum cliente registrado!\n");
                }
                getch();
                break;
            }
            case 6: {
            	system("cls");
                if (key == true) {    
                    docs = excluirDocsPorNum(docs);
                }else{
                    printf("\nNenhum documento registrado!\n");
                }
                getch();
                break;
            }
            case 7: {
            	system("cls");
                if (key == true) {    
                    docs = excluirDocsPorCliente(cli, docs);
                }else{
                    printf("\nNenhum documento registrado!\n");
                }
                getch();
                break;
            }
            case 8: {
            	system("cls");
                if (key == true) {    
                    docs = excluirDocsPorPeriodo(docs);
                }else{
                    printf("\nNenhum documento registrado!\n");
                }
                getch();
                break;
            }
            case 9: {
            	system("cls");
                if (key == true) {
                    cli = alterarInformacoesClientes(cli);            
                }else{
                    printf("\nNenhum cliente registrado!\n");
                }
                getch();
                break;
            }
            case 10: {
            	system("cls");
                if (key == true) {
                    mostrarUmCliente(cli, docs);            
                }else{
                    printf("\nNenhum cliente registrado!\n");
                }
                getch();
                break;
            }
            default: {
            	system("cls");
                printf("Opcao Invalida!");
                getch();
                break;
            }
        }

    }while(op != 0);
}
