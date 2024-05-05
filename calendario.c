#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Function prototypes
void MenuPrincipal();
void MenuCriarLembrete();
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

void MenuPrincipal(){
    int opMenuPrincipal;

    printf("+==================================================+\n");
    printf("| 1 - Criar Lembretes    | 2 - Visualizar Lembretes |\n");
    printf("+==================================================+\n");
    printf("| 3 - Analisar Lembretes |        4 - Sair         |\n");
    printf("+==================================================+\n");
    printf("Digite Qual opção você deseja acessar: \n");
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
    printf("Digite Qual opção você deseja acessar: \n");
    scanf("%d", &opMenuVisualizarLembretes);
    switch (opMenuVisualizarLembretes){
    case 1:
        VisualizarLembretesSemana();
        break;
    case 2:
        VisualizarLembretesMes();
        break;
    case 3:
        VisualizarLembretesAno();
        break;
    default:
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
    printf("A função Visualizar lembretes por semana está em criação \n");
}
void VisualizarLembretesMes(){
    printf("A função Visualizar lembretes por semana está em criação \n");
}
void VisualizarLembretesAno(){
    printf("A função Visualizar lembretes por ano está em criação \n");
}