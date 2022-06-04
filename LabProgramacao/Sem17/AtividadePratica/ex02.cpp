#include <stdio.h>
#include <vector>
#include <algorithm>

bool contem(int num, std::vector<int> &v){
    bool contem = false;
    if (std::count(v.begin(), v.end(), num)) {
        contem = true;
    }else {
        contem = false;
    }

    return contem;
}

int main()
{
    std::vector<int> teste;
    int vai,foi;
    bool ira;

    printf("numero de elementos:");
    scanf("%d", &foi);
    getchar();

    for (int i = 0;i < foi;i++){
        printf("Digite o numero da matricula: ");
        scanf("%d", &vai);

        ira = contem(vai, teste); 
        
        if (ira == true) {
            do{
                teste.push_back(vai);
                printf("Invalido!\nDigite um novo numero: ");
                scanf("%d", &vai);
                getchar();
                ira = contem(vai, teste);
                teste.push_back(vai);
            }while(ira != false);
        }else{
            teste.push_back(vai);
            continue;
        }
        
    }

    
    
    /*int key;
    scanf("%d", &key);
 
    if (std::count(v.begin(), v.end(), key)) {
        printf("Achou");
    }
    else {
        printf("Nao ta aqui");
    }*/
}

