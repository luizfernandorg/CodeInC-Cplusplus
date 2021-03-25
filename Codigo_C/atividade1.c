#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct {
    int cliente_id;
    //- nome (suponha um nome com, no máximo, 30 caracteres)
    char nome[30];
    char sobrenome[30];
    //- ano de nascimento
    int idade;
    //- montante de gastos realizados no mês (quanto o clinte pagou em suas compras dentro do mês corrente)
    float montante;// não consegui faze funcionar com float ou double, causa erro no programa
} cliente;

#define CURRENT_SIZE_VECTOR sizeof(cliente)*10
#define CLEAR "cls" // "clear" on Linux, "cls" on Windows

// - incluir um novo cliente
int incluir_cliente(cliente * clientes, int * counter_clientes, int * current_size_vetor);

// - remover cliente - atualizar o montante de compras do cliente realizadas no mês corrente
void remover_cliente(cliente * clientes, int * counter_clientes);

// - zerar todos os montantes de compras por ocasião da virada de mês
void zerar_montantes_virada_mes(cliente * clientes,int * counter_clientes);

// - listar o cliente melhor comprador
void melhor_comprador(cliente * clientes,int * counter_clientes);

// - exibir um montante de compras de um cliente específico.
void exibir_montante(cliente * clientes,int * counter_clientes);

int main(void)
{
    /*
     * está opção funciona bem no Linux usando gcc,
     * no Windows, não consegui fazer funcionar com 
     * MinGW e nem com Microsoft Visual Studio
     * mesmo setando LC_ALL para "Portuguese"
     */
    setlocale(LC_ALL, "pt_BR.UTF-8");
        
    int counter_clientes = 0;
    int current_size_vetor = CURRENT_SIZE_VECTOR/sizeof(cliente);//10
    int resultado;
    cliente * clientes = (cliente *)malloc(CURRENT_SIZE_VECTOR);
    if(clientes == NULL){
        free(clientes);
        return 1;
    }
    system(CLEAR);
    printf("Bem-vindo ao gerenciador de clientes: \n");
    while(1){
        int op;
        printf("Opções do programa: \n");
        printf("\t 0 - Sair do programa\n");
        printf("\t 1 - incluir um novo cliente\n");
        printf("\t 2 - remover cliente\n");
        printf("\t 3 - zerar todos os montantes\n");
        printf("\t 4 - listar o cliente melhor comprador\n");
        printf("\t 5 - exibir um montante de compras de um cliente específico\n");

        printf("Digite uma opção de 0 a 5: ");
        scanf("%d", &op);

        if(op == 1){
            resultado = incluir_cliente(clientes, &counter_clientes, &current_size_vetor);
            if(resultado){
                break;
            }
            counter_clientes++;
        } else if (op == 2) {
            remover_cliente(clientes,&counter_clientes);
        } else if (op == 3) {
            zerar_montantes_virada_mes(clientes,&counter_clientes);
        } else if (op == 4) {
            melhor_comprador(clientes,&counter_clientes);
        } else if (op == 5) {
            exibir_montante(clientes,&counter_clientes);
        } else if (op == 0) {
            printf("Obrigado por usar o gerenciador de clientes! Programa encerrado.\n");
            break;
        } else {
            printf("Voce digitou uma opção errada, programa encerrado!\n");
        }
        system(CLEAR);
    }
    free(clientes);
    return 0;
}
// - incluir um novo cliente
int incluir_cliente(cliente * clientes, int * counter_clientes,int * current_size_vetor){
    int op = 0;
    while(1){
        cliente cliente;
        cliente.cliente_id = *counter_clientes+1;

        if(*counter_clientes == *current_size_vetor-1){
            clientes = realloc(clientes, CURRENT_SIZE_VECTOR);
            if(clientes == NULL){
                printf("Erro - Houve uma falha ao realocar memória\n");
                free(clientes);
                return 1;
            }
            *current_size_vetor += CURRENT_SIZE_VECTOR/sizeof(cliente);
        }
        system(CLEAR);
        printf("Até o momento há %d cliente(s) cadastrados!\n\n", *counter_clientes);
        printf("Nome do cliente: ");
        scanf("%s", cliente.nome);
        
        printf("Sobrenome do cliente: ");
        scanf("%s", cliente.sobrenome);

        printf("\nDigite a idade: ");
        scanf("%d", &cliente.idade);

        printf("\nDigite o montante no formato xxx.xx: ");
        scanf("%f", &cliente.montante);

        clientes[*counter_clientes] = cliente;

        printf("Você deseja inserir novo cliente 1-sim, 0-não: ");
        scanf("%d", &op);
        if(op){
            *(counter_clientes) += 1;
        } else {
            break;
        }
    }
    return 0;
}

// - remover cliente - atualizar o montante de compras do cliente realizadas no mês corrente
void remover_cliente(cliente * clientes, int * counter_clientes){
    // pegar o cliente
    int id;
    int op;
    int resposta = 0;
 
    while(1){
        system(CLEAR);
        if(*counter_clientes < 1){
            printf("Nao ha clientes no cadastro\n");
            printf("\nDigite 0 para sair");
            scanf("%d",&op);
            if(!op)
                break;
        }
        for(int i = 0; i < *counter_clientes; i++){
            printf("Cliente ID: %d\n", clientes[i].cliente_id);
            printf("Nome: %s %s\n", clientes[i].nome, clientes[i].sobrenome);
            printf("\n");
        }
        printf("Informe a ID para remover ou 0 para voltar ao menu principal: ");
        scanf("%d", &id);
        if(id == 0){
            return;
        } else if ( id > clientes[*counter_clientes-1].cliente_id ){
            printf("\nCliente inexistente!");
            continue;
        }
        
        printf("\nExcluir cliente %s %s (1-sim, 0-não):", clientes[id-1].nome, clientes[id-1].sobrenome);
        scanf("%d",&resposta);
        if(resposta){
            if(*counter_clientes <= 1 || *counter_clientes-1 == id-1){
                cliente cliente;
                clientes[id-1] = cliente;
            }else{
                // fazer um loop no vetor, e reposicionar os clientes no vetor e atualizar a posição de espaço vago
                for(int i = id-1; i < *counter_clientes-1; i++){
                    clientes[i+1].cliente_id -= 1;
                    clientes[i] = clientes[i+1];
                }
            }
            *counter_clientes -= 1; 
        }
    }
}

// - zerar todos os montantes de compras por ocasião da virada de mês
void zerar_montantes_virada_mes(cliente * clientes,int * counter_clientes){
    int op;
    system(CLEAR);
    for(int i =0; i < *counter_clientes; i++){
        clientes[i].montante = 0;
    }
    printf("Montantes zerados de %d cliente(s)!\n", *counter_clientes);
    printf("\nDigite 0 para voltar ao menu principal");
    scanf("%d", &op);
    if(!op)
        return;
}

// - listar o cliente melhor comprador
void melhor_comprador(cliente * clientes,int * counter_clientes){
    int id_maior_valor = 0;
    int op;
    system(CLEAR);
    for(int i = 0; i < *counter_clientes-1; i++){
        if(clientes[i].montante > clientes[i+1].montante){
            id_maior_valor = i;
        } else {
            id_maior_valor = i+1;            
        }
    }
    printf("\n%s %s e o melhor comprador(a) com um montante de R$ %.2f reais!\n", clientes[id_maior_valor].nome, clientes[id_maior_valor].sobrenome, clientes[id_maior_valor].montante);
    printf("\nDigite 0 para voltar ao menu principal: ");
    scanf("%d", &op);
    if(!op)
        return;
}

// - exibir um montante de compras de um cliente específico.
void exibir_montante(cliente * clientes,int * counter_clientes){
    // pegar o cliente
    int id;
    int op;
    system(CLEAR);
    if(*counter_clientes < 1){
        printf("Nao ha clientes no cadastro\n");
        printf("Digite 0 para voltar ao menu principal");
        scanf("%d", &op);
        if(!op)
            return;
    }
    
    while(1){
        system(CLEAR);
        for(int i = 0; i < *counter_clientes; i++){
            printf("Cliente ID: %d\n", clientes[i].cliente_id);
            printf("Nome: %s %s\n", clientes[i].nome, clientes[i].sobrenome);
            printf("\n");
        }
        printf("\nDigite a ID ou 0 para voltar ao menu principal: ");
        scanf("%d", &id);
        if(id == 0){
            return;
        } else if ( id > clientes[*counter_clientes-1].cliente_id ){
            printf("\nCliente inexistente!");
            continue;
        } else {
            printf("Cliente %s %s tem um montante de R$ %0.2f reais\n", clientes[id-1].nome, clientes[id-1].sobrenome, clientes[id-1].montante);
            int resposta;
            printf("\nVoce deseja ver outro cliente 1-sim, 0-nao? ");
            scanf("%d", &resposta);
            if(!resposta){
                return;
            }
        }        
    }    
}