#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <conio.h>
/*1-Cadastrar clientes no arquivo criado.
2-Incluir recebimentos no arquivo criado.
3-Excluir clientes e, consequentemente, todos os seus recebimentos, dos arquivos criados.
4-Alterar o cadastro de clientes. O usuário deve informar o código do cliente que será alterado.*/

struct Cliente
{
    int cod_cli;
    char nome[100];
    char endereco[100];
};

struct Recebimentos
{
    int num_doc;
    float valor_doc;
    int dia_Emis, mes_Emis, ano_Emis;
    int dia_Venc, mes_Venc, ano_Venc;
    int cod_cli;
};

void cadastraCliente(char arq[]){

    Cliente cliente;
    FILE *file = fopen(arq, "ab");

    if(file != NULL){
        printf("Codigo do cliente: \n . ");
        scanf("%d", &cliente.cod_cli);
        getchar();
        printf("Nome do cliente: \n . ");
        fgets(cliente.nome, 100, stdin);
        printf("Endereco: \n . ");
        fgets(cliente.endereco, 100, stdin);
        fwrite(&cliente, sizeof(Cliente), 1, file);
        fclose(file);
    }else{
        printf("Falha ao cadastrar cliente!");
    }
    
}

void incluiRecebimentos(char arq[]){

    Recebimentos recebimentos;
    FILE *file = fopen(arq, "ab");

    if(file != NULL){
        printf("Numero do documento: \n . ");
        scanf("%d", &recebimentos.num_doc);
        printf("Valor do documento: \n . ");
        scanf("%f", &recebimentos.valor_doc);
        printf("Data de emissao: \n . ");
        scanf("%d%*c%d%*c%d", &recebimentos.dia_Emis, &recebimentos.mes_Emis, &recebimentos.ano_Emis);
        printf("Data de vencimento: \n . ");
        scanf("%d%*c%d%*c%d", &recebimentos.dia_Venc, &recebimentos.mes_Venc, &recebimentos.ano_Venc);
        printf("Codigo do cliente: \n . ");
        scanf("%d", &recebimentos.cod_cli);
        fwrite(&recebimentos, sizeof(Recebimentos), 1 , file);
        fclose(file);
    }else{
        printf("Falha ao Incluir Recebimento!");
    }
    
}

void excluiArquivo(char arq[]){

    FILE *file = fopen(arq, "wb");
    fclose(file);
}

void listaClientesERecebimentos(char arqCli[], char arqReceb[]){
    
    Cliente cliente;
    Recebimentos recebimentos;
    int icli = 1, irec = 1, id;
     
    FILE *fcli = fopen(arqCli, "rb");
    FILE *frec = fopen(arqReceb, "rb");
    

    if(fcli && frec != NULL) {
        printf("Lista de Clientes: \n");
        printf("-----------------------------\n");
        while(!feof(fcli)){
            if(fread(&cliente, sizeof(Cliente), 1, fcli)){
            printf("\nIndice: %d\n\n", icli);
            printf("Codigo do cliente: %d\n", cliente.cod_cli);
            printf("Nome: %s", cliente.nome);
            printf("Endereco: %s\n", cliente.nome);
            icli++;
            }
        }
        fclose(fcli);
        printf("-----------------------------\n");
        
        printf("\nLista de Recebimentos: \n");
        printf("-----------------------------\n");
        while (fread(&recebimentos, sizeof(Recebimentos), 1, frec)){
            printf("\nIndice: %d\n\n", irec);
            printf("Numero documento: %d\n", recebimentos.num_doc);
            printf("Valor: %.2f\n", recebimentos.valor_doc);
            printf("Data de emissao: %d/%d/%d\n", recebimentos.dia_Emis, recebimentos.mes_Emis, recebimentos.ano_Emis);
            printf("Data de vencimento: %d/%d/%d\n", recebimentos.dia_Venc, recebimentos.mes_Venc, recebimentos.ano_Venc);
            printf("Codigo do cliente: %d\n", recebimentos.cod_cli);
            irec++;
        }
        printf("-----------------------------\n");
        fclose(frec);
    }
}

void alterarCliente(char arq[]) {

    FILE *file = fopen(arq, "rb+");
    Cliente cliente;
    int i = 1, id;
    
    if(file != NULL) {
        printf("\nLista de clientes: \n");
        printf("-------------------------");
        while(fread(&cliente, sizeof(Cliente), 1, file)){
            
            printf("\nIndice: %d\n\n", i);
            printf("Codigo cliente: %d\n", cliente.cod_cli);
            printf("Nome cliente: %s", cliente.nome);
            printf("Endereco: %s", cliente.endereco);
            i++;
        }
        printf("-------------------------\n");

        printf("Digite o indice do cliente que deseja alterar: ");
        scanf("%d", &id);
        getchar();
        id--;

        if(id >= 0 && id < i - 1){
            printf("Digite o novo cadastro: \n");
            printf("Codigo Cliente: \n . ");
            scanf("%d", &cliente.cod_cli);
            printf("Nome: \n . ");
            getchar();
            fgets(cliente.nome, sizeof(cliente.nome),stdin);
            printf("Endereco: \n . ");
            fgets(cliente.endereco, sizeof(cliente.endereco),stdin);
            fseek(file, id * sizeof(Cliente), SEEK_SET);
            fwrite(&cliente, sizeof(Cliente), 1, file);
        }
        fclose(file);


    }else{
        printf("Erro ao abrir o arquivo!");
    }

}

void excluiCliente(char arqCli[], char arqRec[]){
    
    
    Cliente cliente;
    Recebimentos recebimentos;
    int icli = 1, irec = 1;

    char tempCli[] = {"tempClientes.dat"};
    char tempRec[] = {"tempRecebimentos.dat"};

    FILE *fcli = fopen(arqCli, "rb");
    FILE *frec = fopen(arqRec, "rb");

    FILE *frec_temp = fopen(tempRec, "wb");
    FILE *fcli_temp = fopen(tempCli, "wb");

    if(fcli && frec != NULL) {
        
        listaClientesERecebimentos(arqCli,arqRec);

        char nome[100];
        printf("Digite o nome do cliente que deseja excluir: ");
        getchar();
        fgets(nome, sizeof(nome),stdin);
        
        while(!feof(fcli)){
            fread(&cliente, sizeof(Cliente), 1, fcli);
            if(strcmp(nome, cliente.nome)) {
                fwrite(&cliente, sizeof(Cliente), 1, fcli_temp);
            }
        }

        rewind(fcli);

        while(!feof(fcli) && !feof(frec)){
            rewind(frec);
            fread(&cliente, sizeof(Cliente), 1, fcli);
                fread(&recebimentos, sizeof(Recebimentos), 1, frec);
                if(recebimentos.cod_cli != cliente.cod_cli) {
                    fwrite(&recebimentos, sizeof(Recebimentos), 1, frec_temp);
                }
        }

        fclose(fcli);
        fclose(frec);
        fclose(fcli_temp);
        fclose(frec_temp);
        remove(arqCli);
        rename(tempCli, arqCli);
        remove(arqRec);
        rename(tempRec, arqRec);
    }
}

main(){
    
    char clientes[] = {"clientes.dat"};
    char recebimentos[] = {"recebimentos.dat"};

    int op;

    do{

        system("cls");
        printf("\n|---------------------------------|\n");
        printf("|          Menu de opcoes         |\n");
        printf("|     0. Finalizar programa:      |\n");
        printf("|     1. Cadastrar clientes:      |\n");
        printf("|    2. Incluir recebimentos:     |\n");
        printf("| 3. Lista cliente e recebimento: |\n");
        printf("|      4. Excluir cliente:        |\n");
        printf("| 5. Alterar cadastro de clientes:|\n");
        printf("|  6. Excluir todos os registros: |\n");
        printf("|---------------------------------|\n\n");

        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            cadastraCliente(clientes);
            break;
        case 2:
            system("cls");
            incluiRecebimentos(recebimentos);
            break;
        case 3:
            system("cls");
            listaClientesERecebimentos(clientes, recebimentos);
            getch();
            break;

        case 4:
            system("cls");
            excluiCliente(clientes, recebimentos);
            break;
        case 5:
            system("cls");
            alterarCliente(clientes);
        case 6:
            system("cls");
            excluiArquivo(clientes);
            excluiArquivo(recebimentos);
            break;
        default:
            system("cls");
            printf("Opcao invalida!");
            break;
        }
    
    
    }while (op !=0);
    

}