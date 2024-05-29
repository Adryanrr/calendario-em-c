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

// Funções específicas do calendário
void visualizarLembretes();
void calendarioIcev();
void calendario();

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

void logoCalendario(){

printf(" ██████╗ █████╗ ██╗     ███████╗███╗   ██╗██████╗  █████╗ ██████╗ ██╗ ██████╗  \n");
printf("██╔════╝██╔══██╗██║     ██╔════╝████╗  ██║██╔══██╗██╔══██╗██╔══██╗██║██╔═══██╗ \n");
printf("██║     ███████║██║     █████╗  ██╔██╗ ██║██║  ██║███████║██████╔╝██║██║   ██║ \n");
printf("██║     ██╔══██║██║     ██╔══╝  ██║╚██╗██║██║  ██║██╔══██║██╔══██╗██║██║   ██║ \n");
printf("╚██████╗██║  ██║███████╗███████╗██║ ╚████║██████╔╝██║  ██║██║  ██║██║╚██████╔╝ \n");
printf(" ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝ ╚═════╝  \n");
                                                                              
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


// calendario 
static const char *MonthDisplay[] = {
    "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro",
    "Outubro", "Novembro", "Dezembro"};
int year, mes, dia, x, day2;
signed char c; // entrada do usuário para mudança de calendário
int mesArray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void menu() {
    printf("Pressione 1: para criar evento\n");
    printf("Pressione 2: para deletar evento\n");
    printf("Pressione 3: para sair\n\n");
    // função principal para o calendário
}

void GerarCalendario() {
    // Fonte da linha acima: cadaeit.net
    system("setterm -bold on");                                    // cabeçalho em negrito
    printf("\n         %s    %d \n", MonthDisplay[mes - 1], year); // cabeçalho
    printf("\nDOM  SEG  TER  QUA  QUI  SEX  SAB\n");
    system("setterm -bold off");

    for (day2 = 1; day2 <= x; day2++) { // day2 é o contador
        printf("     ");
    } // inicializa a posição do primeiro dia

    for (day2 = 1; day2 <= mesArray[mes - 1]; day2++) {
        // preenche o calendário
        if (dia == day2) { // torna a saída vermelha
            printf("\e[5;31;40m%2d\e[0m", dia); // não pisca
        } else {
            printf("%2d", day2);
        }
        if (((day2 + x) % 7) > 0) { // passa para a próxima linha após sábado
            printf("   ");
        } else {
            printf("\n ");
        }
    }
    printf("\n");
}

void calendario() {
    system("clear");
    system("setterm -bold on"); // cabeçalho em negrito
    printf("Calendário de Eventos \n");
    system("setterm -bold off");

    printf("Digite o ano: ");
    scanf("%d", &year); // entrada do usuário para o ano
    while (year < 0) {
        printf("Ano não adequado. \n");
        printf("Digite o ano: ");
        scanf("%d", &year); // entrada do usuário para o ano
    }

    printf("Digite o mês: ");
    scanf("%d", &mes); // entrada do usuário para o mês
    while (mes < 1 || mes > 12) {
        printf("Mês não adequado. \n");
        printf("Digite o mês: ");
        scanf("%d", &mes); // entrada do usuário para o mês
    }

    printf("Digite o dia: ");
    scanf("%d", &dia); // entrada do usuário para o dia
    while (dia < 1 || dia > 31) {
        printf("Dia não adequado. \n");
        printf("Digite o dia: ");
        scanf("%d", &dia); // entrada do usuário para o dia
    }

    // Verifica validade do dia para o mês
    while (true) {
        if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            if (dia > 30) {
                printf("Dia não adequado. \n");
                printf("Digite o dia: ");
                scanf("%d", &dia); // entrada do usuário para o dia
                continue;
            }
        } else if (mes == 2) {
            if (((year % 4) == 0 && (year % 100 != 0)) || (year % 400 == 0)) {
                mesArray[1] = 29;
                if (dia > 29) {
                    printf("Dia não adequado. \n");
                    printf("Digite o dia: ");
                    scanf("%d", &dia); // entrada do usuário para o dia
                    continue;
                }
            } else {
                if (dia > 28) {
                    printf("Dia não adequado. \n");
                    printf("Digite o dia: ");
                    scanf("%d", &dia); // entrada do usuário para o dia
                    continue;
                }
            }
        }
        break;
    }

    // Calcula o primeiro dia do mês
    x = 1;
    x = (x += mes < 3 ? year : year - 2, 23 * mes / 9 + x + 4 + year / 4 - year / 100 + year / 400) % 7;
    if ((year % 4) == 0 && ((year % 100) != 0 || (year % 400) == 0)) {
        mesArray[1] = 29;
        if (mes == 1 || mes == 2) {
            x--;
            if (x < 0) {
                x = 6;
            }
        }
    } else {
        mesArray[1] = 28;
    }

    // Imprimindo calendário
    system("clear");
    GerarCalendario();
    printf("Você selecionou %s %d, %d \n", MonthDisplay[mes - 1], dia, year);
    printf("   - Para alternar entre os dias, use (a) para o dia anterior e (d) para o próximo dia. \n");
    printf("   - Para alternar entre os meses, use (w) para o mês anterior e (s) para o próximo mês.\n\n");
    menu();
    
    while (true) {
        scanf(" %c", &c); // leia o comando do usuário

        if (c == '1') {
            // Chamar função para criar evento
            printf("Função de criar evento não implementada.\n");
            GerarCalendario();
        } else if (c == '2') {
            // Chamar função para deletar evento
            printf("Função de deletar evento não implementada.\n");
            GerarCalendario();
        } else if (c == '3') {
            system("clear");
            system("setterm -bold on");
            printf("\n\n\n TENHA UM ÓTIMO DIA ENQUANTO EU PROGRAMO ISSO!!  :)) \n\n\n\n");
            system("setterm -bold off");
            break;
        } else if (c == 'w') { // mês anterior
            if (mes == 1) {
                year--;
                mes = 12;
            } else {
                mes--;
            }
            if (dia > mesArray[mes - 1]) {
                dia = mesArray[mes - 1];
            }
            GerarCalendario();
        } else if (c == 's') { // próximo mês
            if (mes == 12) {
                mes = 1;
                year++;
            } else {
                mes++;
            }
            if (dia > mesArray[mes - 1]) {
                dia = mesArray[mes - 1];
            }
            GerarCalendario();
        } else if (c == 'a') { // dia anterior
            if (dia == 1) {
                if (mes == 1) {
                    mes = 12;
                    year--;
                } else {
                    mes--;
                }
                dia = mesArray[mes - 1];
            } else {
                dia--;
            }
            GerarCalendario();
        } else if (c == 'd') { // próximo dia
            if (dia == mesArray[mes - 1]) {
                dia = 1;
                if (mes == 12) {
                    mes = 1;
                    year++;
                } else {
                    mes++;
                }
            } else {
                dia++;
            }
            GerarCalendario();
        } else {
            printf("Resposta inválida. Por favor, tente novamente. \n");
            GerarCalendario();
        }
    }
}

