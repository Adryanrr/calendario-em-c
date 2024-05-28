#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Function prototypes
void limparTerminal();
void MenuPrincipal();
void VisualizarCalendario();
// ------------------------------
void visualizarLembretes();
void VisualizarLembretesSemana();
void VisualizarLembretesMes();
void VisualizarLembretesAno();
// ------------------------------
void calendarioIcev();
// ------------------------------

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

    printf("+===================================================================+\n");
    printf("|         1 - Calendario              3 - Calendario Academico      |\n");
    printf("+===================================================================+\n");
    printf("|    2 - Visualizar Lembretes                 4 - Exit              |\n");
    printf("+===================================================================+\n");
    printf("Digite Qual opção você deseja acessar: \n");
    scanf("%d", &opMenuPrincipal);

    switch (opMenuPrincipal){
    case 1:
        limparTerminal();
        VisualizarCalendario();
        break;
    case 2:
        limparTerminal();
        visualizarLembretes();
        break;
    case 3:
        limparTerminal();
        calendarioIcev();
    default:
        limparTerminal();
        printf("Obrigado, volte sempre! \n");
        break;
    }
}
void VisualizarCalendario(){
    int opVisualizarCalendario;
    
    printf("+==================================================================+\n");
    printf("|    [1] - Visualizar outro Mês         [2] - Criar um lembrete    |\n");
    printf("+==================================================================+\n");
    printf("|                             0 - Exit                             |\n");
    printf("+==================================================================+\n");
    switch (opVisualizarCalendario){
    case 1:
        limparTerminal();
        TrocaMes();
        break;
    case 2:
        limparTerminal();
        CriarLembretes();
    default:
        limparTerminal();
        printf("Obrigado, volte sempre! \n");
        break;
    }
}
void visualizarLembretes(){
  printf("Em construção!!");
}
void calendarioIcev(){
    int opCalendarioIcev;

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
    scanf("%d", &opCalendarioIcev);

    switch (opCalendarioIcev){
    case 0:
        limparTerminal();
        MenuPrincipal();
        break;  
    default:
        printf("opção invalida! \n");
        break;
    }
}
void CriarLembretes(){
    char horaLembrete,descricaoLembrete[50];
    printf("Insira a Hora: XX:XX \n");
    scanf("%s", &horaLembrete);
    printf("Insira a Descrição do Lembrete: \n");
    scanf("%s", &descricaoLembrete);
}