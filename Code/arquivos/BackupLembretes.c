#include<string.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<locale.h>
#include <stdbool.h>

typedef struct {
    int hora;
    int min;
    char nome[100];
}evento;

// Funções de interface do usuário
void limparTerminal();
void menuPrincipal();
void menuCalendario();
void logoCalendario();
char obterEscolha();

// Funções de manipulação de eventos
bool check(const evento *e);
evento* UIEvento();
void novoEvento(evento *e);
void adicionarEvento(evento lista[], const evento e, const int x);
void organizar(evento lista[], const int contador);
void organizarCorreto(evento lista[], int *contador, evento e);
void deletarEvento(evento lista[], int *contador);
void visualizarEvento(const evento e);
void mostrarEventos(const evento lista[], const int contador);
void exibirEventos(evento lista[], int contador);

// Funções de manipulação de datas
int eAnoBissexto(int ano);
int calcularPrimeiroDiaSemana(int ano, int mes);
void imprimirCalendario(int ano, int mes, int dia, int mesArray[]);
int intervalo1(const int minimo, const int maximo);
int intervalo2(const int minimo, const int maximo);
void obterDigitos(int num, char* primeiroDigito, char* segundoDigito);

int main(){
    limparTerminal();
    logoCalendario();
    menuPrincipal();
    return 0;
}

void limparTerminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void menuPrincipal(){
    setlocale(LC_ALL,"Portuguese_Brazil");
    int opMenuPrincipal;

    printf("+===================================================================+\n");
    printf("|         1 - Calendario              3 - Calendario Academico      |\n");
    printf("|                                                                   |\n");
    printf("|     2 - Visualizar Evento                   4 - Exit              |\n");
    printf("+===================================================================+\n");
    printf("Digite Qual opção você deseja acessar: \n");
    scanf("%d", &opMenuPrincipal);

    switch (opMenuPrincipal){
    case 1:
        limparTerminal();
        calendario();
        break;
    case 2:
        limparTerminal();
        novoEvento(NULL);
        break;
    case 3:
        limparTerminal();
        calendarioIcev();
        break;
    default:
        limparTerminal();
        printf("Obrigado, volte sempre! \n");
        break;
    }
}

void calendarioIcev(){
    printf("Calendario Academico\n");
}

// Inicio Evento

// verificar se o evento é nulo
bool check (const evento *e){
    return e==NULL;
} 

evento *UIEvento (){
    evento *e = (evento*) malloc(sizeof(evento));
    e ->hora = 0;
    e ->min = 0;
    strcpy(e -> nome, "");
    return e;
}

int intervalo1(const int minimo, const int maximo) {
    int input = 0;
    do {
        scanf("%2d", &input);
        if (input < minimo || input > maximo) {
            printf("Entrada incorreta, por favor tente novamente: ");
        }
    } while (input < minimo || input > maximo);
    return input;
}

int intervalo2(const int minimo, const int maximo) {
    int input = 0;
    do {
        scanf("%2d", &input);
        if (input < minimo || input > maximo) {
            printf("Entrada incorreta, por favor tente novamente: ");
        }
    } while (input < minimo || input > maximo);
    return input;
}

void novoEvento(evento *e){
    if (check(e)){
        e = UIEvento();
    }
    system("setterm -bold on");
    printf("\n \n  Novo  Evento  Selecionado  \n \n");
    system("setterm -bold off");
    printf("Digite a hora (0-23): ");
    e->hora = intervalo1(0, 23);
    printf("Digite o minuto (0-59): ");
    e->min = intervalo2(0, 59);
    puts("\n     NOME DO EVENTO     \n");
    printf("Por favor, inclua o nome ou descrição do evento: ");
    fgets(e->nome, 100, stdin);
    fgets(e->nome, 100, stdin);
    puts(" ----------------------------------");
    system("setterm -bold on");
    puts(" \nEvento Adicionado.");
    system("setterm -bold off");
}
void adicionarEvento(evento lista[], const evento e, const int x){
    if(check(&e)){
        return;
    }
    lista[x].hora = e.hora;
    lista[x].min = e.min;
    strcpy(lista[x].nome, e.nome);
}

void organizar (evento lista[], const int contador){
    int x,y,armazem1,armazem2;
    char nome2[100];
    for (x = 1; x < contador; x++){
        for (y = x; y > 0 && (lista[y].hora > lista[y].hora) || 
            (lista[y -1].hora == lista[y].hora) &&(lista[y - 1].min > lista[y].min);y--){
                armazem1 = lista[y - 1].hora;
                armazem2 = lista[y - 1].min;
                strcpy(nome2, lista[y - 1].nome);
                // evento 2
                lista[y - 1].hora = lista[y].hora;
                lista[y - 1].min = lista[y].min;
                strcpy(lista[y].nome,nome2);
            }   
    }
}
void organizarCorreto(evento lista[], int *contador, evento e){
    adicionarEvento(lista, e, *contador);
    (*contador)++;
    organizar(lista, *contador);
}
void obterDigitos(int num, char* primeiroDigito, char* segundoDigito) {
    *primeiroDigito = (num / 10) + '0';
    *segundoDigito = (num % 10) + '0';
}

void visualizarEvento(const evento e) {
    char primeiroDigitoHora, segundoDigitoHora;
    char primeiroDigitoMinuto, segundoDigitoMinuto;

    // Obter os dígitos da hora e minuto
    obterDigitos(e.hora, &primeiroDigitoHora, &segundoDigitoHora);
    obterDigitos(e.min, &primeiroDigitoMinuto, &segundoDigitoMinuto);

    // Imprimir a hora e o nome do evento
    printf("%c%c:%c%c  ~%s\n", primeiroDigitoHora, segundoDigitoHora, primeiroDigitoMinuto, segundoDigitoMinuto, e.nome);
}
void deletarEvento(evento lista[], int *contador) {
    int x;
    if (*contador == 0) {
        puts("\n Você não tem eventos para deletar. \n");
        return;
    }
    char temp[100];
    int locate;
    system("setterm -bold on");
    printf("\n    DELETAR EVENTO   \n");
    system("setterm -bold off");
    printf("\n Digite o número do evento que você deseja deletar: ");
    fgets(temp, 100, stdin);
    fgets(temp, 100, stdin);
    strtok(temp, "\n");
    locate = atoi(temp);
    //locate=locate-y;
    if (locate > *contador - 1) {
        printf("Nenhum evento encontrado\n");
        return;
    }
    for (x = locate; x < *contador - 1; x++) {
        lista[x].hora = lista[x + 1].hora;
        lista[x].min = lista[x + 1].min;
        strcpy(lista[x].nome, lista[x + 1].nome);
    }
    (*contador)--;
}

// Função para exibir os eventos
void exibirEventos(evento lista[], int contador) {
    printf("\n\nTodos Eventos \n");
    mostrarEventos(lista, contador);
    printf("\nSelecione (1) para criar um evento, (2) para deletar um evento, ou pressione (3) para voltar ao menu principal:\n");
    char escolha = obterEscolha();
    switch (escolha) {
    case '1':
        limparTerminal();
        novoEvento(&lista[contador]);
        organizarCorreto(lista, &contador, lista[contador]);
        exibirEventos(lista, contador);
        break;
    case '2':
        limparTerminal();
        deletarEvento(lista, &contador);
        exibirEventos(lista, contador);
        break;
    case '3':
        limparTerminal();
        menuPrincipal();
        break;
    default:
        limparTerminal();
        printf("Por favor, digite uma opção válida.\n");
        exibirEventos(lista, contador);
        break;
    }
}

// fim evento