#include<string.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<locale.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

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
    printf("|         1 - Calendario                 2 - Criar Lembrete         |\n");
    printf("|                                                                   |\n");
    printf("|     3 - Visualizar Evento           4 - Calendario Academico      |\n");
    printf("|                                                                   |\n");
    printf("|                           0 - Exit                                |\n");
    printf("+===================================================================+\n");
    printf("Digite Qual opção você deseja acessar: \n");
    scanf("%d", &opMenuPrincipal);

    switch (opMenuPrincipal){
    case 1:
        limparTerminal();
        printf("Calendario \n");
        break;
    case 2:
        limparTerminal();
        printf("Criar Lembrete \n");
        break;
    case 3:
        limparTerminal();
        printf("Visualizar Evento \n");
        break;
    case 4: 
          limparTerminal();
        printf("Calendario Academico \n");
    case 0:
        limparTerminal();
        printf("Obrigado, volte sempre! \n");
      default:
        printf("Opção inválida, tente novamente! \n");
        limparTerminal();
        menuPrincipal();
      }
}

// Inicio da gestão de lembretes

void criarLembretes() {
    printf("Pressione 1: para criar evento\n");
    printf("Pressione 2: para deletar evento\n");
    printf("Pressione 3: para sair\n\n");
    // função principal para o calendário
}

// Final da gestão de lembretes

// inicio da gestão de calendario

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

int main() {
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
    return 0;
}

// Final da gestão de calendario

void calendarioIcev(){
    int operecao;

    printf("+=======|==========================================================================+\n");
    printf("|HORARI0|    SEGUNDA    |    TERÇA    |    QUARTA    |    QUINTA     |    SEXTA    |\n");
    printf("|-------|---------------|-------------|--------------|---------------|-------------|\n");
    printf("| 14:30 |  Arquiterura  |  Matematica | Arquiterura  |  Algoritimo   | Algoritimo  |\n");
    printf("|       |       de      |   Discreta  |     de       |       e       |      e      |\n");
    printf("| 16:10 |  computadores |             | computadores |  Programação  | Programação |\n");
    printf("|-------|---------------|-------------|--------------|---------------|-------------|\n");
    printf("| 16:20 |               |  Engenharia |  Matematica  |   Engenharia  |  Projeto    |\n");
    printf("|       | Seminarios I  |      de     |   Discreta   |       de      |     de      |\n");
    printf("| 18:00 |               |   Software  |              |    Software   | Extensão I  |\n");
    printf("|-------|---------------|-------------|--------------|---------------|-------------|\n");
    printf("| 18:10 |               |             |              |               |             |\n");
    printf("|       |   Ingles I    |             |              |               |             |\n");
    printf("| 20:00 |               |             |              |               |             |\n");
    printf("+=======|+=========================================================================+\n");
    printf("Digite 0 para voltar ao menu principal: \n");
    scanf("%d", &operecao);

    switch (operecao){
    case 0:
        limparTerminal();
        MenuPrincipal();
        break;  
    default:
        printf("opção invalida! \n");
        break;
    }
}