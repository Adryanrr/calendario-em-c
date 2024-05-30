#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdbool.h>
#include <stdbool.h>

#define MAXIMO_LEMBRETES 10

struct lembrete{
    char nome[50];
    char descricao[250];
    int ano;
    int mes;       
    int dia; 
};
struct lembrete lembretes[MAXIMO_LEMBRETES];


// Fun??es de interface do usu?rio
void limparTerminal();
void menuPrincipal();
void logoCalendario();

// Fun??o de lembretes
// ---------------------


// ---------------------

// Fun??es de manipula??o de datas






// Fun??es espec?ficas do calend?rio
void visualizarLembretes();
void calendarioIcev();
void calendario();
void criarLembretes();
void menuCalendario();

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

printf(" ??????? ?????? ???     ????????????   ??????????  ?????? ??????? ??? ???????  \n");
printf("???????????????????     ?????????????  ??????????????????????????????????????? \n");
printf("???     ???????????     ??????  ?????? ??????  ?????????????????????????   ??? \n");
printf("???     ???????????     ??????  ?????????????  ?????????????????????????   ??? \n");
printf("???????????  ?????????????????????? ?????????????????  ??????  ??????????????? \n");
printf(" ??????????  ??????????????????????  ???????????? ???  ??????  ?????? ???????  \n");
}
                                                                              

void menuPrincipal(){
    setlocale(LC_ALL,"Portuguese_Brazil");
    int opMenuPrincipal;

    printf("+===================================================================+\n");
    printf("|                                                                   |\n");
    printf("|         1 - Calendario                 2 - Criar Lembrete         |\n");
    printf("|                                                                   |\n");
    printf("|     3 - Visualizar Lembrete          4 - Calendario Academico     |\n");
    printf("|                                                                   |\n");
    printf("|                           0 - Exit                                |\n");
    printf("+===================================================================+\n");
    printf("Digite Qual op??o voc? deseja acessar: \n");
    scanf("%d", &opMenuPrincipal);

    switch (opMenuPrincipal){
    case 1:
        limparTerminal();
        calendario();
        break;
    case 2:
        limparTerminal();
        criarLembretes();
        break;
    case 3:
        limparTerminal();
        visualizarLembretes();
        break;
    case 4: 
        limparTerminal();
        calendarioIcev();
        break;
    case 0:
        limparTerminal();
        printf("Obrigado, volte sempre! \n");
        break;
      default:
        printf("Op??o inv?lida, tente novamente! \n");
        sleep(2);
        logoCalendario();
        limparTerminal();
        menuPrincipal();
      }
}
// Inicio da gest?o de lembretes


void criarLembretes(){
    struct lembrete lembretes[100];
    printf("Digite o nome do lembrete: \n");
    scanf("%s", &lembretes[0].nome);
    printf("Digite o ano do lembrete: \n");
    scanf("%d", &lembretes[0].ano);
    printf("Digite o m?s do lembrete: \n");
    scanf("%d", &lembretes[0].mes);
    printf("Digite o dia do lembrete: \n");
    scanf("%d", &lembretes[0].dia);

    visualizarLembretes();
}


void numeroLembretes(struct lembrete lembretes[]){
    int i;
    int numLembretes = 0;
    for(i = 0; i < MAXIMO_LEMBRETES; i++){
        if(lembretes[i].dia != 0){ // assumindo que 'dia' ? um campo em 'struct lembrete' e que '0' indica um lembrete vazio
            numLembretes++;
        }
    }
    printf("numero de lembres ?: %d \n", numLembretes);
}    



void visualizarLembretes(){
    int op;
    printf("O que deseja visualizar? \n");
    printf("Pressione 1: visualizar numero de lembretes \n");
    printf("Pressione 2: visualizar lista de lembretes \n");
    scanf("%d", &op);
    switch (op){
    case 1:
        numeroLembretes(lembretes);
        printf("Pressione 0 para voltar ao menu principal: \n");    
        break;
    case 2:
        printf("em constru??o \n");
        break;
    default:
        break;
    }    
    // listar lembretes
}

void menuLembretes() {
    printf("Pressione 1: criar lembretes \n"); // direcionar para a fun??o de criar lembrete
    printf("Pressione 2: visualizar lembretes \n");
    printf("Pressione 3: para voltar \n");
    // fun??o principal para o calend?rio
}

// Final da gest?o de lembretes

// inicio da gest?o de calendario

static const char *MonthDisplay[] = {
    "Janeiro", "Fevereiro", "Mar?o", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro",
    "Outubro", "Novembro", "Dezembro"};
int year, mes, dia, x, day2;
signed char c; // entrada do usu?rio para mudan?a de calend?rio
int mesArray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void menuCalendario() {
    printf("Voc? selecionou %s %d, %d \n", MonthDisplay[mes - 1], dia, year);
    printf("   - Para alternar entre os dias, use (a) para o dia anterior e (d) para o pr?ximo dia. \n");
    printf("   - Para alternar entre os meses, use (w) para o m?s anterior e (s) para o pr?ximo m?s.\n\n");

    menuLembretes();
}

void GerarCalendario() {
    // Fonte da linha acima: cadaeit.net
    system("setterm -bold on");                                    // cabe?alho em negrito
    printf("\n         %s    %d \n", MonthDisplay[mes - 1], year); // cabe?alho
    printf("\nDOM  SEG  TER  QUA  QUI  SEX  SAB\n");
    system("setterm -bold off");

    for (day2 = 1; day2 <= x; day2++) { // day2 ? o contador
        printf("     ");
    } // inicializa a posi??o do primeiro dia

    for (day2 = 1; day2 <= mesArray[mes - 1]; day2++) {
        // preenche o calend?rio
        if (dia == day2) { // torna a sa?da vermelha
            printf("\e[5;31;40m%2d\e[0m", dia); // n?o pisca
        } else {
            printf("%2d", day2);
        }
        if (((day2 + x) % 7) > 0) { // passa para a pr?xima linha ap?s s?bado
            printf("   ");
        } else {
            printf("\n ");
        }
    }
    printf("\n");
}

void calendario() {
    limparTerminal();
    system("setterm -bold on"); // cabe?alho em negrito
    printf("Calend?rio de Eventos \n");
    system("setterm -bold off");

    printf("Digite o ano: ");
    scanf("%d", &year); // entrada do usu?rio para o ano
    while (year < 0) {
        printf("Ano n?o adequado. \n");
        printf("Digite o ano: ");
        scanf("%d", &year); // entrada do usu?rio para o ano
    }

    printf("Digite o m?s: ");
    scanf("%d", &mes); // entrada do usu?rio para o m?s
    while (mes < 1 || mes > 12) {
        printf("M?s n?o adequado. \n");
        printf("Digite o m?s: ");
        scanf("%d", &mes); // entrada do usu?rio para o m?s
    }

    printf("Digite o dia: ");
    scanf("%d", &dia); // entrada do usu?rio para o dia
    while (dia < 1 || dia > 31) {
        printf("Dia n?o adequado. \n");
        printf("Digite o dia: ");
        scanf("%d", &dia); // entrada do usu?rio para o dia
    }

    // Verifica validade do dia para o m?s
    while (true) {
        if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            if (dia > 30) {
                printf("Dia n?o adequado. \n");
                printf("Digite o dia: ");
                scanf("%d", &dia); // entrada do usu?rio para o dia
                continue;
            }
        } else if (mes == 2) {
            if (((year % 4) == 0 && (year % 100 != 0)) || (year % 400 == 0)) {
                mesArray[1] = 29;
                if (dia > 29) {
                    printf("Dia n?o adequado. \n");
                    printf("Digite o dia: ");
                    scanf("%d", &dia); // entrada do usu?rio para o dia
                    continue;
                }
            } else {
                if (dia > 28) {
                    printf("Dia n?o adequado. \n");
                    printf("Digite o dia: ");
                    scanf("%d", &dia); // entrada do usu?rio para o dia
                    continue;
                }
            }
        }
        break;
    }

    // Calcula o primeiro dia do m?s
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

    // Imprimindo calend?rio
    limparTerminal();
    GerarCalendario();
    menuCalendario();
    
    while (true) {
        scanf(" %c", &c); // leia o comando do usu?rio

        if (c == '1') {
            // Chamar função para criar evento
            printf("Função de criar evento não implementada.\n");
            GerarCalendario();
            menuCalendario();
        } else if (c == '2') {
            // Chamar fun??o para deletar evento
            printf("Fun??o de deletar evento n?o implementada.\n");
            limparTerminal();
            GerarCalendario();
        } else if (c == '3') {
            limparTerminal();
            menuPrincipal();
            break;
        } else if (c == 'w') { // m?s anterior
            if (mes == 1) {
                year--;
                mes = 12;
            } else {
                mes--;
            }
            if (dia > mesArray[mes - 1]) {
                dia = mesArray[mes - 1];
            }
            limparTerminal();
            GerarCalendario();
            menuCalendario();
        } else if (c == 's') { // pr?ximo m?s
            if (mes == 12) {
                mes = 1;
                year++;
            } else {
                mes++;
            }
            if (dia > mesArray[mes - 1]) {
                dia = mesArray[mes - 1];
            }
            limparTerminal();
            GerarCalendario();
            menuCalendario();
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
            limparTerminal();
            GerarCalendario();
            menuCalendario();
        } else if (c == 'd') { // pr?ximo dia
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
            limparTerminal();
            GerarCalendario();
            menuCalendario();
        } else {
            printf("Resposta inv?lida. Por favor, tente novamente. \n");
            limparTerminal();
            GerarCalendario();
            menuCalendario();
        }
    }

}

// Final da gest?o de calendario

void calendarioIcev(){
    int operecao;

    printf("+=======|==========================================================================+\n");
    printf("|HORARI0|    SEGUNDA    |    TER?A    |    QUARTA    |    QUINTA     |    SEXTA    |\n");
    printf("|-------|---------------|-------------|--------------|---------------|-------------|\n");
    printf("| 14:30 |  Arquiterura  |  Matematica | Arquiterura  |  Algoritimo   | Algoritimo  |\n");
    printf("|       |       de      |   Discreta  |     de       |       e       |      e      |\n");
    printf("| 16:10 |  computadores |             | computadores |  Programa??o  | Programa??o |\n");
    printf("|-------|---------------|-------------|--------------|---------------|-------------|\n");
    printf("| 16:20 |               |  Engenharia |  Matematica  |   Engenharia  |  Projeto    |\n");
    printf("|       | Seminarios I  |      de     |   Discreta   |       de      |     de      |\n");
    printf("| 18:00 |               |   Software  |              |    Software   | Extens?o I  |\n");
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
        menuPrincipal();
        break;  
    default:
        printf("op??o invalida! \n");
        break;
    }
}