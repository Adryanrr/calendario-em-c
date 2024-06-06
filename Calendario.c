#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <locale.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

FILE *arquivo;

void criarArquivo(){
    arquivo = fopen("Lembretes.txt", "a");
    if (arquivo == NULL) {
    printf("Não foi possível abrir o arquivo.\n");
    exit(1);
  }
  fclose(arquivo);
}

#define MAXIMO_LEMBRETES 10

struct lembrete{
    char descricao[250];
    int ano;
    int mes;       
    int dia;          
};

struct lembrete lembretes[MAXIMO_LEMBRETES];
int contagem;
int mesArray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Função de manipulação de terminal
void limparTerminal();
void menuPrincipal();
void logoCalendario();
void saida();
void opcao();

// 
void creditosDesenvolvedores();
void gerenicarLembretes();
void calendarioIcev();
void calendario();
void criarLembretes();
void menuCalendario();

int main(){
    criarArquivo();
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

printf("\n");
printf("\n");                                                           

}

void menuPrincipal(){
    setlocale(LC_ALL,"Portuguese_Brazil");
    int opMenuPrincipal;

    limparTerminal();
    logoCalendario();

    printf("  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("  ┃                              MENU PRINCIPAL                               ┃\n");
    printf("  ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("  ┃                                                                           ┃\n");
    printf("  ┃        ┏━━━━━━━━━━(1)━━━━━━━━━┑           ┏━━━━━━━━━━(2)━━━━━━━━━┑        ┃\n");
    printf("  ┃               Calendario                       Criar Lembrete             ┃\n");
    printf("  ┃        ┗━━━━━━━━━━━━━━━━━━━━━━┙           ┗━━━━━━━━━━━━━━━━━━━━━━┙        ┃\n");
    printf("  ┃        ┏━━━━━━━━━━(3)━━━━━━━━━┑           ┏━━━━━━━━━━(4)━━━━━━━━━┑        ┃\n");
    printf("  ┃           Gerenciar Lembretes               Calendario Academico          ┃\n");
    printf("  ┃        ┗━━━━━━━━━━━━━━━━━━━━━━┙           ┗━━━━━━━━━━━━━━━━━━━━━━┙        ┃\n");
    printf("  ┃        ┏━━━━━━━━━━(5)━━━━━━━━━┑           ┏━━━━━━━━━━(0)━━━━━━━━━┑        ┃\n");
    printf("  ┃                Creditos                             Saida                 ┃\n");
    printf("  ┃        ┗━━━━━━━━━━━━━━━━━━━━━━┙           ┗━━━━━━━━━━━━━━━━━━━━━━┙        ┃\n");
    printf("  ┃                                                                           ┃\n");
    printf("  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\n");                                                          

    printf("Digite Qual opção você deseja acessar: ");
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
        gerenicarLembretes(lembretes);
        break;
    case 4: 
        limparTerminal();
        calendarioIcev();
        break;
    case 5:
        limparTerminal();
        creditosDesenvolvedores();
        break;
    case 0:
        limparTerminal();
        saida();
        break;
    default:
        printf("Opção invalida, tente novamente! \n");
        sleep(2);
        logoCalendario();
        limparTerminal();
        menuPrincipal();
      }
}

// Inicio da gestão de lembretes

void verificarValidade(){
    
    struct lembrete lembrete;
    while (true){
        if (lembrete.mes == 4 || lembrete.mes == 6 || lembrete.mes == 9 || lembrete.mes == 11){
            if (lembrete.dia > 30) {
                printf("Dia não adequado. \n");
                printf("Digite o dia: ");
                scanf("%d", &lembrete.dia); // entrada do usuario para o dia
                continue;
            }
        } else if (lembrete.mes == 2) {
            if (((lembrete.ano % 4) == 0 && (lembrete.ano % 100 != 0)) || (lembrete.ano % 400 == 0)){
                mesArray[1] = 29;
                if (lembrete.dia > 29) {
                    printf("Dia não adequado. \n");
                    printf("Digite o dia: ");
                    scanf("%d", &lembrete.dia); // entrada do usuario para o dia
                    continue;
                }
            } else {
                if (lembrete.dia > 28){
                    printf("Dia não adequado. \n");
                    printf("Digite o dia: ");
                    scanf("%d", &lembrete.dia); // entrada do usuario para o dia
                    continue;
                }
            }
            
        }
        break;
    }
}

void criarLembretes() {

    logoCalendario();

    if (contagem >= MAXIMO_LEMBRETES) {
        printf("Número máximo de lembretes atingido! \n");
        return;
    }

    FILE *arquivo = fopen("Lembretes.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo! \n");
        return;
    }

    struct lembrete lembrete;

    printf("Digite o dia do lembrete: \n");
    scanf("%d", &lembrete.dia);
    while (lembrete.dia <1 || lembrete.dia > 31){
        printf("Dia não adequado. \n");
        printf("Digite o dia: ");
        scanf("%d", &lembrete.dia);
    }
    getchar();

    printf("Digite o mês do lembrete: \n");
    scanf("%d", &lembrete.mes);
    while (lembrete.mes < 1 || lembrete.mes > 12){
        printf("Mês não adequado. \n");
        printf("Digite outro mês: ");
        scanf("%d", &lembrete.mes);    
    }
    getchar(); 

    printf("Digite o ano do lembrete: \n");
    scanf("%d", &lembrete.ano);
    while (lembrete.ano < 0) {
        printf("Ano não adequado. \n");
        printf("Digite o ano: ");
        scanf("%d", &lembrete.ano);
    }
    getchar(); 

    printf("Digite a descrição do lembrete: \n");
    fgets(lembrete.descricao, 150, stdin);
    lembrete.descricao[strcspn(lembrete.descricao, "\n")] = '\0'; // Remover a nova linha

    fprintf(arquivo, "Data: %02d/%02d/%d\n", lembrete.dia, lembrete.mes, lembrete.ano);
    fprintf(arquivo, "Descrição: %s\n", lembrete.descricao);

    fclose(arquivo);
    contagem++;

    limparTerminal();
    printf("Criado com sucesso! \n");
    sleep(2);
    limparTerminal();
    logoCalendario();
    menuPrincipal();
}

void opcao(){
    int op = 0;
    printf("\nPressione 1 para voltar ao menu principal \n");
    printf("Pressione 2 para criar um lembrete \n");
    scanf("%d", &op);
    getchar(); // Consumir o '\n' deixado por scanf

    switch (op) {
        case 1:
            limparTerminal();
            menuPrincipal();
            break;
        case 2:
            limparTerminal();
            criarLembretes();
            break;
        default:
            printf("Operação inválida \n");
            break;
    }
}

void listarLembretes() {

    logoCalendario();

    FILE *arquivo = fopen("Lembretes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo! \n");
        return;
    }

    limparTerminal();
    printf("Lista de lembretes: \n");
    char linha[300];
    int i = 1;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strncmp(linha, "Data:", 5) == 0) {
            printf("%d. %s", i, linha); // Mostra a linha da data
            if (fgets(linha, sizeof(linha), arquivo)) {
                printf("   %s", linha); // Mostra a linha da descrição
            }
            i++;
        }
    }
    fclose(arquivo);

    opcao();
}

void listarNumeroLembretes() {
    limparTerminal();
    logoCalendario();
    printf("Número de lembretes criados é: %d \n", contagem);
    opcao();
}

// Função para deletar lembrete
void deletarLembrete() {

    logoCalendario();
    printf("Menu Remoção de lembrete \n");
    FILE *arquivo = fopen("Lembretes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo! \n");
        return;
    }

    limparTerminal();
    printf("Lista de lembretes: \n");
    char linha[300];
    int i = 1;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strncmp(linha, "Data:", 5) == 0) {
            printf("%d. %s", i, linha); // Mostra a linha da data
            if (fgets(linha, sizeof(linha), arquivo)) {
                printf("   %s", linha); // Mostra a linha da descrição
            }
            i++;
        }
    }
    fclose(arquivo);

    printf("\nDigite o número do lembrete que deseja deletar: ");
    int op;
    scanf("%d", &op);

    if (op < 1 || op >= i) {
        printf("Opção inválida! \n");
        limparTerminal();
        return gerenicarLembretes();
    }

    arquivo = fopen("Lembretes.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir o arquivo! \n");
        return;
    }

    i = 1;
    int deletar = 0;
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strncmp(linha, "Data:", 5) == 0) {
            if (i == op) {
                deletar = 1;
            } else {
                deletar = 0;
            }
            i++;
        }
        if (!deletar) {
            fputs(linha, temp);
        }
    }
    fclose(arquivo);
    fclose(temp);

    remove("Lembretes.txt");
    rename("temp.txt", "Lembretes.txt");

    limparTerminal();
    printf("Lembrete deletado com sucesso! \n");
    sleep(2);
    limparTerminal();
    logoCalendario();
    menuPrincipal();
}


void gerenicarLembretes() {
    int op;
    logoCalendario();
    printf("Gerenciador de lembretes: \n");
    printf("\n");
    printf("O que deseja realizar? \n");
    printf("Pressione 1: visualizar os lembretes \n");
    printf("Pressione 2: visualizar número de lembretes \n");
    printf("Pressione 3: Deletar um lembrete \n");
    printf("Pressione 0: Para voltar ao menu principal \n");
    scanf("%d", &op);

    switch (op) {
        case 1:
            listarLembretes();
            break;
        case 2: 
            listarNumeroLembretes();
            break;    
        case 3:
            deletarLembrete();
            break;
        case 0:
            menuPrincipal();
            break;
        default:
            limparTerminal();
            printf("Opção inválida! \n");
            printf("Retornando ao meunu principal \n");
            sleep(2.5);
            menuPrincipal();
            break;
    }
}

// Final da gestão de lembretes

// inicio da gestão de calendario

static const char *MonthDisplay[] = {
    "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro",
    "Outubro", "Novembro", "Dezembro"};
int ano, mes, dia, DeterminarDia, day2;
signed char c; // entrada do usuario para mudança de calendario

void menuCalendario() {
    printf("\n");
    printf("Você selecionou %s %d, %d \n", MonthDisplay[mes - 1], dia, ano);
    printf("\n");
    printf("Navegação: \n");
    printf("- Use (a) para o dia anterior e (d) para o próximo dia. \n");
    printf("- Use (w) para o mês anterior e (s) para o próximo mês.\n");
    printf("\n");

    printf("Pressione 1: criar lembretes \n"); // direcionar para a função de criar lembrete
    printf("Pressione 2: visualizar numero de lembretes \n");
    printf("Pressione 3: para voltar \n");
    printf("\n");

    printf("Selecionou: ");
    printf("\e[?25l");
    // função principal para o calendario
}

void GerarCalendario() {
    
    limparTerminal();
    logoCalendario();
    system("setterm -bold on"); // cabeçalho em negrito
    printf("            Calendario            \n");
    system("setterm -bold off");

    system("setterm -bold on");                                    // cabeçalho em negrito
    printf("\n         %s    %d \n", MonthDisplay[mes - 1], ano); // cabeçalho
    printf("\nDOM  SEG  TER  QUA  QUI  SEX  SAB\n");
    system("setterm -bold off");

    for (day2 = 1; day2 <= DeterminarDia; day2++) { // day2 e o contador
        printf("     ");
    } // inicializa a posição do primeiro dia

    for (day2 = 1; day2 <= mesArray[mes - 1]; day2++) {
        // preenche o calendario
        if (dia == day2) { // torna a saida vermelha
            printf("\e[5;31;40m%2d\e[0m", dia); // não pisca
        } else {
            printf("%2d", day2);
        }
        if (((day2 + DeterminarDia) % 7) > 0) { // passa para a proxima linha após sábado
            printf("   ");
        } else {
            printf("\n ");
        }
    }
    printf("\n");
}

void calendario() {
    logoCalendario();

    printf("Digite o dia: ");
    scanf("%d", &dia); // entrada do usuario para o dia
    while (dia < 1 || dia > 31) {
        printf("Dia não adequado. \n");
        printf("Digite o dia: ");
        scanf("%d", &dia); // entrada do usuario para o dia
    }

    printf("Digite o mês: ");
    scanf("%d", &mes); // entrada do usuario para o mês
    while (mes < 1 || mes > 12) {
        printf("Mês não adequado. \n");
        printf("Digite o mês: ");
        scanf("%d", &mes); // entrada do usuario para o mês
    }

    printf("Digite o ano: ");
    scanf("%d", &ano); // entrada do usuario para o ano
    while (ano < 0) {
        printf("Ano não adequado. \n");
        printf("Digite o ano: ");
        scanf("%d", &ano); // entrada do usuario para o ano
    }

    // Verifica validade do dia para o mês
    while (true) {
        if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            if (dia > 30) {
                printf("Dia não adequado. \n");
                printf("Digite o dia: ");
                scanf("%d", &dia); // entrada do usuario para o dia
                continue;
            }
        } else if (mes == 2) {
            if (((ano % 4) == 0 && (ano % 100 != 0)) || (ano % 400 == 0)) {
                mesArray[1] = 29;
                if (dia > 29) {
                    printf("Dia não adequado. \n");
                    printf("Digite o dia: ");
                    scanf("%d", &dia); // entrada do usuario para o dia
                    continue;
                }
            } else {
                if (dia > 28) {
                    printf("Dia não adequado. \n");
                    printf("Digite o dia: ");
                    scanf("%d", &dia); // entrada do usuario para o dia
                    continue;
                }
            }
        }
        break;
    }

    // Calcula o primeiro dia do mês
    DeterminarDia = 1;
    DeterminarDia = (DeterminarDia += mes < 3 ? ano : ano - 2, 23 * mes / 9 + DeterminarDia + 4 + ano / 4 - ano / 100 + ano / 400) % 7;
    if ((ano % 4) == 0 && ((ano % 100) != 0 || (ano % 400) == 0)) {
        mesArray[1] = 29;
        if (mes == 1 || mes == 2) {
            DeterminarDia--;
            if (DeterminarDia < 0) {
                DeterminarDia = 6;
            }
        }
    } else {
        mesArray[1] = 28;
    }

    // Imprimindo calendario
    limparTerminal();
    GerarCalendario();
    menuCalendario();
    
    while (true) {
        scanf(" %c", &c); // leia o comando do usuario

        if (c == '1') {
            limparTerminal();
            criarLembretes();
        } else if (c == '2') {
            // Chamar função para gerenciar lembrete
            limparTerminal();
            listarNumeroLembretes();
        } else if (c == '3') {
            limparTerminal();
            logoCalendario();
            menuPrincipal();
            break;
        } else if (c == 'w') { // mês anterior
            if (mes == 1) {
                ano--;
                mes = 12;
            } else {
                mes--;
            }
            if (dia > mesArray[mes - 1]) {
                dia = mesArray[mes - 1];
            }
            limparTerminal();
            logoCalendario();
            GerarCalendario();
            menuCalendario();
        } else if (c == 's') { // proximo mês
            if (mes == 12) {
                mes = 1;
                ano++;
            } else {
                mes++;
            }
            if (dia > mesArray[mes - 1]) {
                dia = mesArray[mes - 1];
            }
            limparTerminal();
            logoCalendario();
            GerarCalendario();
            menuCalendario();
        } else if (c == 'a') { // dia anterior
            if (dia == 1) {
                if (mes == 1) {
                    mes = 12;
                    ano--;
                } else {
                    mes--;
                }
                dia = mesArray[mes - 1];
            } else {
                dia--;
            }
            limparTerminal();
            logoCalendario();
            GerarCalendario();
            menuCalendario();
        } else if (c == 'd') { // proximo dia
            if (dia == mesArray[mes - 1]) {
                dia = 1;
                if (mes == 12) {
                    mes = 1;
                    ano++;
                } else {
                    mes++;
                }
            } else {
                dia++;
            }
            limparTerminal();
            logoCalendario();
            GerarCalendario();
            menuCalendario();
        } else {
            printf("Resposta inválida. Por favor, tente novamente. \n");
            limparTerminal();
            logoCalendario();
            GerarCalendario();
            menuCalendario();
        }
    }

}

// Final da gestão de calendario

void calendarioIcev(){

    printf("                                ██╗ ██████╗███████╗██╗   ██╗ \n");
    printf("                                ██║██╔════╝██╔════╝██║   ██║ \n");
    printf("                                ██║██║     █████╗  ██║   ██║ \n");
    printf("                                ██║██║     ██╔══╝  ╚██╗ ██╔╝ \n");
    printf("                                ██║╚██████╗███████╗ ╚████╔╝  \n");
    printf("                                ╚═╝ ╚═════╝╚══════╝  ╚═══╝   \n");
    printf("                               Instituto de Ensino Superior  \n"); 
    printf("\n"); 
    
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃                       CALENDARIO ACADEMICO ENGENHARIA DE SOFTWARE TURMA ADA                    ┃\n");
    printf("┣━━━━━━━━━┳━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━┫\n");
    printf("┃         ┃                 ┃                ┃                 ┃                ┃                ┃\n");
    printf("┃ HORARI0 ┃     SEGUNDA     ┃     TERÇA      ┃     QUARTA      ┃     QUINTA     ┃      SEXTA     ┃\n");
    printf("┃         ┃                 ┃                ┃                 ┃                ┃                ┃\n");
    printf("┣━━━━━━━━━╋━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━┫\n");
    printf("┃  14:30  ┃   Arquitetura   ┃   Matematica   ┃   Arquitetura   ┃   Algoritimo   ┃   Algoritimo   ┃\n");
    printf("┃         ┃        de       ┃    Discreta    ┃       de        ┃        e       ┃       e        ┃\n");
    printf("┃  16:10  ┃   computadores  ┃                ┃  computadores   ┃   Programação  ┃   Programação  ┃\n");
    printf("┣━━━━━━━━━┻━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━┫\n");
    printf("┃  16:20  ┃                 ┃   Engenharia   ┃   Matematica    ┃   Engenharia   ┃     Projeto    ┃\n");
    printf("┃         ┃   Seminarios I  ┃       de       ┃    Discreta     ┃       de       ┃       de       ┃\n");
    printf("┃  18:00  ┃                 ┃    Software    ┃                 ┃    Software    ┃    Extensão I  ┃\n");
    printf("┣━━━━━━━━━╋━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━┫\n");
    printf("┃  18:10  ┃                 ┃                ┃                 ┃                ┃                ┃\n");
    printf("┃         ┃     Ingles I    ┃                ┃                 ┃                ┃                ┃\n");
    printf("┃  20:00  ┃                 ┃                ┃                 ┃                ┃                ┃\n");
    printf("┗━━━━━━━━━┻━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━┛\n");
    printf("\n"); 
    printf("\n"); 
   
    printf("Digite 0 para voltar ao menu principal: \n");

    int operecao;
    scanf("%d", &operecao);

    switch (operecao){
    case 0:
        limparTerminal();
        menuPrincipal();
        break;  
    default:
        printf("opção invalida! \n");
        break;
    }
}

void creditosDesenvolvedores(){

    printf("██████╗ ███████╗███████╗███████╗███╗   ██╗██╗   ██╗ ██████╗ ██╗    ██╗   ██╗███████╗██████╗  ██████╗ ██████╗ ███████╗███████╗\n");
    printf("██╔══██╗██╔════╝██╔════╝██╔════╝████╗  ██║██║   ██║██╔═══██╗██║    ██║   ██║██╔════╝██╔══██╗██╔═══██╗██╔══██╗██╔════╝██╔════╝\n");
    printf("██║  ██║█████╗  ███████╗█████╗  ██╔██╗ ██║██║   ██║██║   ██║██║    ██║   ██║█████╗  ██║  ██║██║   ██║██████╔╝█████╗  ███████╗\n");
    printf("██║  ██║██╔══╝  ╚════██║██╔══╝  ██║╚██╗██║╚██╗ ██╔╝██║   ██║██║    ╚██╗ ██╔╝██╔══╝  ██║  ██║██║   ██║██╔══██╗██╔══╝  ╚════██║\n");
    printf("██████╔╝███████╗███████║███████╗██║ ╚████║ ╚████╔╝ ╚██████╔╝███████╗╚████╔╝ ███████╗██████╔╝╚██████╔╝██║  ██║███████╗███████║\n");
    printf("╚═════╝ ╚══════╝╚══════╝╚══════╝╚═╝  ╚═══╝  ╚═══╝   ╚═════╝ ╚══════╝ ╚═══╝  ╚══════╝╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝\n");
    printf("\n");

    printf(" Laboratorio do professor chiquinho                                               \n");
    printf("                _________________                                                 \n");
    printf("               /                /|                                                \n");
    printf("              /                / |                                                \n");
    printf("             /________________/ /|                                                \n");
    printf("          ###|      ____      |//|                                                \n");
    printf("         #   |     /   /|     |/.|                                                \n");
    printf("        #  __|___ /   /.|     |  |_______________                                 \n");
    printf("      #  /      /   //||     |  /              /|                   ___           \n");
    printf("      #  /      /___// ||     | /              / |                 / \\ \\        \n");
    printf("      # /______/!   || ||_____|/              /  |                /   \\ \\       \n");
    printf("      #| . . .  !   || ||                    /  _________________/     \\ \\      \n");
    printf("      #|  . .   !   || //      ________     /  /\\________________  {   /  }      \n");
    printf("      /|   .    !   ||//~~~~~~/   0000/    /  / / ______________  {   /  /        \n");
    printf("     / |        !   |'/      /9  0000/    /  / / /             / {   /  /         \n");
    printf("   / #\\________!___|/      /9  0000/    /  / / /_____________/___  /  /          \n");
    printf("   / #     /_____\\/        /9  0000/    /  / / /_  /\\_____________\\/  /        \n");
    printf("  / #                      ``^^^^^^    /   \\ \\ . ./ / ____________   /          \n");
    printf(" +=#==================================/     \\ \\ ./ / /.  .  .  \\ /  /          \n");
    printf(" |#                                   |      \\ \\/ / /___________/  /            \n");
    printf("|#                                    |_______\\__/________________/              \n");
    printf("|                                      |               |  |  / /                  \n");
    printf("| @adryanrr                            |               |  | / /                   \n");
    printf("| @MatheusJuK                          |       ________|  |/ /________            \n");
    printf("| @Whuanderson                         |      /_______/    \\_________/\\         \n");
    printf("| @AndreNTeixeira                      |     /        /  /           \\ )         \n");
    printf("|                                      |             / /                          \n");
    printf("|                                      |            / /                           \n");
    printf("|                                      |          /___\\                          \n");
    printf("|                                      |           oo                             \n");
    printf("|______________________________________|                                          \n");

    printf("\n");
    
    int op;
    while (1) {
        printf("Escolha uma operação:\n");
        printf("1. Voltar ao menu principal\n");
        printf("2. Sair da aplicação\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                if ("Deseja voltar ao menu principal?") {
                    limparTerminal();
                    menuPrincipal();
                }
                break;
            case 2:
                if ("Deseja sair da aplicação?") {
                    limparTerminal();
                    printf("Saindo da aplicação...\n");
                    sleep(2);
                    limparTerminal();
                    return;
                }
                break;
            default:
                printf("Operação inválida!\nAguarde 2s!\n");
                sleep(2);
                limparTerminal();
                creditosDesenvolvedores();
                break;
        }
    }
}

void saida() {
    printf("\nObrigado! \n");
    sleep(2);
    limparTerminal();
}