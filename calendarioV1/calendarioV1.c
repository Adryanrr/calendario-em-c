#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Function prototypes
void limparTerminal();
void MenuPrincipal();
void MenuCriarLembrete();
void calendarioIcev();
// ------------------------------
void MenuVisualizarLembretes();
void VisualizarLembretesSemana();
void VisualizarLembretesMes();
void VisualizarLembretesAno();
// ------------------------------
void MenuAnalisarLembretes();

int main(){
    limparTerminal();
    MenuPrincipal(); 
    return 0;
}

void limparTerminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void MenuPrincipal(){
    setlocale(LC_ALL,"Portuguese_Brazil");
    int opMenuPrincipal;

    printf("+==================================================+\n");
    printf("| 1 - Criar Lembretes    | 2 - Visualizar Lembretes|\n");
    printf("+==================================================+\n");
    printf("| 3 - Analisar Lembretes |   4 - Calendario Icev   |\n");
    printf("+==================================================+\n");
    printf("|           0 - Para sair da Aplicação             |\n");
    printf("+==================================================+\n");
    printf("Digite Qual opção você deseja acessar: \n");
    scanf("%d", &opMenuPrincipal);

    switch (opMenuPrincipal){
    case 1:
        limparTerminal();
        MenuCriarLembrete();
        break;
    case 2:
        limparTerminal();
        VisualizarLembretesAno();
        break;
    case 3:
        limparTerminal();
        MenuAnalisarLembretes();
    case 4: 
        limparTerminal();
        calendarioIcev();
    default:
        limparTerminal();
        printf("Obrigado, volte sempre! \n");
        break;
    }
}

void MenuCriarLembrete(){
    float dataLembrete, horaLembrete;
    char descricaoLembrete[120];

    //printf("+====================================================+\n");
    //printf("|               Menu Criar Lembretes                 |\n");
    //printf("+====================================================+\n");
    //printf("|       Inserir Data     |         Inserir Hora      |\n");
    //printf("+====================================================+\n");
    //printf("|     Inserir Descrição  |        Menu Principal     |\n");
    //printf("+====================================================+\n");

    printf("Insira a Data: \n");
    scanf("%f", &dataLembrete);
    printf("Insira a Hora: \n");
    scanf("%f", &horaLembrete);
    printf("Insira a Descrição do Lembrete: \n");
    scanf("%s", &descricaoLembrete);
}

void MenuVisualizarLembretes(){
    int opMenuVisualizarLembretes;

    printf("+========================================================+\n");
    printf("|          Como vocçã deseja visualizar os lembretes?     |\n");
    printf("+========================================================+\n");
    printf("|          1 - Semana          |         2 - Mês         |\n");
    printf("+========================================================+\n");
    printf("|           3 - Ano            |    4 - Menu Principal   |\n");
    printf("+========================================================+\n");
    printf("Digite Qual opção você deseja acessar: \n");
    scanf("%d", &opMenuVisualizarLembretes);
    
    switch (opMenuVisualizarLembretes){
    case 1:
        limparTerminal();
        VisualizarLembretesSemana();
        break;
    case 2:
        limparTerminal();
        VisualizarLembretesMes();
        break;
    case 3:
        limparTerminal();
        VisualizarLembretesAno();
        break;
    case 4:
        limparTerminal();
        MenuPrincipal();
    default:
        limparTerminal();
        printf("Operação invalida \n");
        break;
    }
}

void MenuAnalisarLembretes(){
    int opMenuAnalisar;

    printf("+=================================================+\n");
    printf("|    1- Modificar Data   |   2- Modificar Hora    |\n");
    printf("+=================================================+\n");
    printf("| 3- Modificar Descrição |    4- Menu Principal   |\n");
    printf("+=================================================+\n");
    printf("Digite Qual opção você deseja acessar: \n");
    scanf("%d", &opMenuAnalisar);
}

void VisualizarLembretesSemana(){
  printf("+=======|========================================================================================================+|\n");
  printf("|HORARI0|    SEGUNDA    |    TER�A    |    QUARTA    |    QUINTA     |    SEXTA    |    SABADO    |    DOMINGO    |\n");
  printf("|-------|---------------|-------------|--------------|---------------|-------------|--------------|---------------|\n");
  printf("| 00:00 |               |             |              |               |             |              |               |\n");
  printf("|       |               |             |              |               |             |              |               |\n");
  printf("| 00:00 |               |                     |              |               |             |              |               |\n");
  printf("|       |               |             |              |               |             |              |               |\n");
  printf("| 00:00 |               |             |              |               |             |              |               |\n");
  printf("|-------|---------------|-------------|--------------|---------------|-------------|--------------|---------------|\n");
  printf("| 00:00 |               |             |              |               |             |              |               |\n");
  printf("|       |               |             |              |               |             |              |               |\n");
  printf("| 00:00 |               |             |              |               |             |              |               |\n");
  printf("|-------|---------------|-------------|--------------|---------------|-------------|--------------|---------------|\n");
  printf("| 00:00 |               |             |              |               |             |              |               |\n");
  printf("|       |               |             |              |               |             |              |               |\n");
  printf("| 00:00 |               |             |              |               |             |              |               |\n");
  printf("+=======|+======================================================================================================+||\n");
}
void VisualizarLembretesMes(){
    printf("A função Visualizar lembretes por semana está em criação \n");
}
void VisualizarLembretesAno(){
    printf("A função Visualizar lembretes por ano está em criação \n");
}
void calendarioIcev(){
    int opCalendarioIcev;

    printf("+=======|=========================================================================================+||\n");
    printf("|HORARI0|    SEGUNDA    |    TERÇA    |    QUARTA    |    QUINTA     |    SEXTA   |    SABADO      ||\n");
    printf("|-------|---------------|-------------|--------------|---------------|-----------------------------||\n");
    printf("| 14:30 |  Arquiterura  |  Matematica | Arquiterura  |  Algoritimo   | Algoritimo |                ||\n");
    printf("|       |       de      |   Discreta  |     de       |       e       |      e     |                ||\n");
    printf("| 16:10 |  computadores |             | computadores |  Programação  | Programação|                ||\n");
    printf("|-------|---------------|-------------|--------------|---------------|------------|----------------||\n");
    printf("| 16:20 |               |  Engenharia |  Matematica  |   Engenharia  |  Projeto   |                ||\n");
    printf("|       | Seminarios I  |      de     |   Discreta   |       de      |     de     |                ||\n");
    printf("| 18:00 |               |   Software  |              |    Software   | Extensão I |                ||\n");
    printf("|-------|---------------|-------------|--------------|---------------|------------|----------------||\n");
    printf("| 18:10 |               |             |              |               |            |                ||\n");
    printf("|       |   Ingles I    |             |              |               |            |                ||\n");
    printf("| 20:00 |               |             |              |               |            |                ||\n");
    printf("|-------|---------------|-------------|--------------|---------------|------------|----------------||\n");
    printf("| 20:10 |               |             |              |               |            |                ||\n");
    printf("|       |               |             |              |               |            |                ||\n");
    printf("| 22:00 |               |             |              |               |            |                ||\n");
    printf("+=======|+========================================================================================+||\n");

    printf("Digite 0 para voltar ao menu principal: \n");
    scanf("%d", &opCalendarioIcev);

    switch (opCalendarioIcev){
    case 0:
        limparTerminal();
        MenuPrincipal();
        break;  
    default:
        printf("opção invalida \n");
        break;
    }
}