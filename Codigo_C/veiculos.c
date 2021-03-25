#include <stdio.h>
#include <stdlib.h>

struct veiculo
{
    //- marca do veículo
    char marca[50];
    //- modelo - ano de fabricação
    char modelo[50];
    int ano;
    //- placa (formato XXX-YYYY; onde X denota as letras e Y denota os números da placa).
    char placa[9];
};

int index_empty = 0;
struct veiculo vetor_de_veiculos[10];

// Definicao de funcoes

//- Listar os veículos cadastrados;
void lista_veiculos();
//- Inserir um novo veículo;
void inserir_veiculo();
//- Listar os veículos filtrando-se por ano de fabricação;
void lista_veiculos_por_ano(int ano);
//- Listar os veículos com o ano de fabricação acima de um certo valor especificado pelo usuário
void lista_veiculos_por_ano_maior(int ano);
//- Listar os veículos filtrando-se pelo modelo.
void lista_veiculos_por_modelo(char modelo[]);

void ordenar();

int main(int argc, char const *argv[])
{
    printf("Ola, bem-vindo ao gerenciador de veiculos!\n");
       
    while(1){
        int opcao;
        int ano;
        char modelo[50];
        printf("Essa sao suas opcoes: \n");
        printf("\t 0 - sair do programa;\n");
        printf("\t 1 - cadastrar um veiculo;\n");
        printf("\t 2 - listar veiculos;\n");
        printf("\t 3 - listar veiculos por um ano especifico;\n");
        printf("\t 4 - listar veiculos por um ano maior que o especificado;\n");
        printf("\t 5 - listar veiculos por modelo especifico;\n");
        printf("Digite uma opcao de 0 a 5: ");
        scanf("%d",&opcao);
        printf("\n");

        if(opcao == 1) {
            int length = sizeof(vetor_de_veiculos)/sizeof(vetor_de_veiculos[0]);
            if(index_empty < length){
                inserir_veiculo();
            }else{
                printf("Inserido o numero maximo de veiculos!");
            }            
        } else if (opcao == 2) {
            lista_veiculos();
        } else if (opcao == 3) {
            printf("Digite o ano: ");
            scanf("%d", &ano);
            lista_veiculos_por_ano(ano);
        } else if (opcao == 4) {
            printf("Digite o ano: ");
            scanf("%d", &ano);
            lista_veiculos_por_ano_maior(ano);
        } else if (opcao == 5) {
            printf("Digite o modelo do veiculo: ");
            scanf("%s", modelo);
            lista_veiculos_por_modelo(modelo);
        } else if (opcao == 0) {
            printf("Obrigado por usar o gerenciador de veiculos! Programa encerrado.");
            break;
        } else {
            printf("Voce digitou um opcao errada, programa encerrado!");
            break;
        }
    }
    return 0;
}

//- Listar os veículos cadastrados;
void lista_veiculos(){
    
    for(int i = 0; i < index_empty; i++){
        printf("\nMarca: %s\n", vetor_de_veiculos[i].marca);
        printf("Modelo: %s\n", vetor_de_veiculos[i].modelo);
        printf("Ano: %d\n", vetor_de_veiculos[i].ano);
        printf("Placa: %s\n", vetor_de_veiculos[i].placa);
        printf("\n");
    }
}
//- Inserir um novo veículo;
void inserir_veiculo(){
    struct veiculo novo_veiculo;
    printf("\nDigite a marca: ");
    scanf("%s", novo_veiculo.marca);
    
    printf("\nDigite o modelo: ");
    scanf("%s", novo_veiculo.modelo);
    
    printf("\nDigite o ano: ");
    scanf("%d", &novo_veiculo.ano);
    
    printf("\nDigite a placa: ");
    scanf("%s", novo_veiculo.placa);
    
    printf("\n");
    vetor_de_veiculos[index_empty] = novo_veiculo;
    ordenar();
    index_empty++;
}
//- Listar os veículos filtrando-se por ano de fabricação;
void lista_veiculos_por_ano(int ano){
    for(int i = 0; i < index_empty; i++){
        if(vetor_de_veiculos[i].ano == ano){
            printf("\nMarca: %s\n", vetor_de_veiculos[i].marca);
            printf("Modelo: %s\n", vetor_de_veiculos[i].modelo);
            printf("Ano: %d\n", vetor_de_veiculos[i].ano);
            printf("Placa: %s\n", vetor_de_veiculos[i].placa);
        }
        printf("\n");
    }
}
//- Listar os veículos com o ano de fabricação acima de um certo valor especificado pelo usuário
void lista_veiculos_por_ano_maior(int ano){
    
    for(int i = 0; i < index_empty; i++){
        if(vetor_de_veiculos[i].ano > ano){
            printf("\nMarca: %s\n", vetor_de_veiculos[i].marca);
            printf("Modelo: %s\n", vetor_de_veiculos[i].modelo);
            printf("Ano: %d\n", vetor_de_veiculos[i].ano);
            printf("Placa: %s\n", vetor_de_veiculos[i].placa);
        }
        printf("\n");
    }
}
//- Listar os veículos filtrando-se pelo modelo.
void lista_veiculos_por_modelo(char modelo[50]){
    
    for(int i = 0; i < index_empty; i++){
        int ret = strcmp(vetor_de_veiculos[i].modelo, modelo);
        if(ret == 0){
            printf("\nMarca: %s\n", vetor_de_veiculos[i].marca);
            printf("Modelo: %s\n", vetor_de_veiculos[i].modelo);
            printf("Ano: %d\n", vetor_de_veiculos[i].ano);
            printf("Placa: %s\n", vetor_de_veiculos[i].placa);
        }
        printf("\n");
    }
}
void ordenar(){
    
    for(int i=0; i < index_empty; i++){
        int minimo = i;
        for(int x = i + 1; x < index_empty+1; x++){
            if(vetor_de_veiculos[minimo].ano > vetor_de_veiculos[x].ano){
                minimo = x;
            }
        }
        struct veiculo temp = vetor_de_veiculos[i];
        vetor_de_veiculos[i] = vetor_de_veiculos[minimo];
        vetor_de_veiculos[minimo] = temp;
    }
}