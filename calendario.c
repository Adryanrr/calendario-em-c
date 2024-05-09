#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Function prototypes
void limparTerminal();
void MenuPrincipal();
void MenuCriarLembrete();
void CalendarioIcev();
// ------------------------------
void MenuVisualizarLembretes();
void VisualizarLembretesSemana();
void VisualizarLembretesMes();
void VisualizarLembretesAno();
// ------------------------------
void MenuAnalisarLembretes();

int main(){
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
    int opMenuPrincipal;

    printf("+==================================================+\n");
    printf("| 1 - Criar Lembretes    | 2 - Visualizar Lembretes \n");
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
        CalendarioIcev();
    default:
        limparTerminal();
        MenuPrincipal();
        break;
    }
}

void MenuCriarLembrete(){
    float dataLembrete, horaLembrete;
    char descricaoLembrete[120];

    printf("+====================================================+\n");
    printf("|               Menu Criar Lembretes                 |\n");
    printf("+====================================================+\n");
    printf("|       Inserir Data     |         Inserir Hora      |\n");
    printf("+====================================================+\n");
    printf("|     Inserir Descrição  |        Menu Principal     |\n");
    printf("+====================================================+\n");

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
    printf("|          Como você deseja visualizar os lembretes?     |\n");
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
    default:
        limparTerminal();
        MenuPrincipal();
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
    scanf("%d", &opMenuAnalisar);
}

void VisualizarLembretesSemana(){
  printf("+=======|========================================================================================================+|\n");
  printf("|HORARI0|    SEGUNDA    |    TERÇA    |    QUARTA    |    QUINTA     |    SEXTA    |    SABADO    |    DOMINGO    |\n");
  printf("|-------|---------------|-------------|--------------|---------------|-------------|--------------|---------------|\n");
  printf("| 00:00 |               |             |              |               |             |              |               |\n");
  printf("|       |               |             |              |               |             |              |               |\n");
  printf("| 00:00 |               |             |              |               |             |              |               |\n");
  printf("|-------|---------------|-------------|--------------|---------------|------------ |--------------|---------------|\n");
  printf("| 00:00 |               |             |              |               |             |              |               |\n");
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
void CalendarioIcev(){
    printf("+=======|========================================================================+||\n");
    printf("|HORARI0|    SEGUNDA    |    TERÇA    |    QUARTA    |    QUINTA     |  SEXTA     ||\n");
    printf("|-------|---------------|-------------|--------------|---------------|------------||\n");
    printf("| 14:30 |               |             |              |               |            ||\n");
    printf("|       |               |             |              |               |            ||\n");
    printf("| 16:10 |               |             |              |               |            ||\n");
    printf("|-------|---------------|-------------|--------------|---------------|------------||\n");
    printf("| 16:20 |               |             |              |               |            ||\n");
    printf("|       |               |             |              |               |            ||\n");
    printf("| 18:00 |               |             |              |               |            ||\n");
    printf("|-------|---------------|-------------|--------------|---------------|------------||\n");
    printf("| 18:10 |               |             |              |               |            ||\n");
    printf("|       |               |             |              |               |            ||\n");
    printf("| 20:00 |               |             |              |               |            ||\n");
    printf("|-------|---------------|-------------|--------------|---------------|------------||\n");
    printf("| 20:10 |               |             |              |               |            ||\n");
    printf("|       |               |             |              |               |            ||\n");
    printf("| 22:00 |               |             |              |               |            ||\n");
    printf("+=======|+=======================================================================+||\n");

}
