#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Function prototypes
void MenuPrincipal();
void MenuCriarLembrete();
void MenuVisualizarLembretes();
void MenuAnalisarLembretes();

int main(){
    MenuPrincipal(); 
    return 0;
}

void MenuPrincipal(){
    int opMenuPrincipal;

    printf("+==================================================+\n");
    printf("| 1 - Criar Lembretes    | 2 - Visualizar Lembretes |\n");
    printf("+==================================================+\n");
    printf("| 3 - Analisar Lembretes |        4 - Sair         |\n");
    printf("+==================================================+\n");
    printf("Digite Qual opção você deseja acessa: \n");
    scanf("%d", &opMenuPrincipal);

    switch (opMenuPrincipal){
    case 1:
        MenuCriarLembrete();
        break;
    case 2:
        MenuVisualizarLembretes();
        break;
    case 3:
        MenuAnalisarLembretes();
        break;
    case 4:
        printf("Deseja sair do calendário? \n");
        break;
    default:
        MenuPrincipal();
        break;
    }
}

void MenuCriarLembrete(){
    printf("+====================================================+\n");
    printf("|    1 - Inserir Data    |     2 - Inserir Hora      |\n");
    printf("+====================================================+\n");
    printf("| 3 - Inserir Descrição  |    4 - Menu Principal     |\n");
    printf("+====================================================+\n");
}

void MenuVisualizarLembretes(){
    int opMenuVisualizarLembretes;

    printf("+========================================================+\n");
    printf("|          1 - Semana          |         2 - Mês         |\n");
    printf("+========================================================+\n");
    printf("|           3 - Ano            |    4 - Menu Principal   |\n");
    printf("+========================================================+\n");
    scanf("%d", &opMenuVisualizarLembretes);
    switch (opMenuVisualizarLembretes){
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
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