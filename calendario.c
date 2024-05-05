//calendario
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
int opMenuPrincipal,opMenuCriar,opMenuVisualizar,opMenuAnalisar;

<<<<<<< HEAD
int opMenuPrincipal, opMenuCriar, opMenuVisualizar, opMenuAnalisar;

void MenuPrincipal(){
    do{
    printf("+==================================================+\n");
    printf("| 1 - Criar Lembretes    | 2 - Visualizar Lembretes |\n");
    printf("+==================================================+\n");
    printf("| 3 - Analisar Lembretes |        4 - Sair         |\n");
    printf("+==================================================+\n");
    printf("Digite Qual opção voce deseja acessar \n");
    scanf("%d", &opMenuPrincipal);
    switch (opMenuPrincipal){
    case 1:
        system("cls");
        MenuCriarLembrete();
        break;
    case 2:
        system("cls");
        MenuVisualizarLembretes();
    case 3: 
        system ("cls");
        MenuAnalisarLembretes();
    case 4: 
        system ("cls");
        printf ("Deseja sair do calendario? \n");
    }    
 } while (MenuPrincipal != 4);
}
void MenuCriarLembrete (){
    printf("+====================================================+\n");
    printf("|    1 - Inserir Data    |     2 - Inserir Hora      |\n");
    printf("+====================================================+\n");
    printf("| 3 - Inserir Descrição  |    4 - Menu Principal     |\n");
    printf("+====================================================+\n");
}
void MenuVisualizarLembretes(){
    printf("+========================================================+\n");
    printf("|          1 - Semana          |         2 - Mês         |\n");
    printf("+========================================================+\n");
    printf("|           3 - Ano            |    4 - Menu Principal   |\n");
    printf("+========================================================+\n");
=======
void MenuPrincipal(){
    printf("+=================================================+\n");
    printf("| 1- Criar Lembretes    | 2- Visualizar Lembretes |\n");
    printf("+=================================================+\n");
    printf("| 3- Analisar Lembretes | 4- Sair                 |\n");
    printf("+=================================================+\n");
    scanf("%d",&opMenuPrincipal);
}
void MenuCriar (){
    printf("+=================================================+\n");
    printf("| 1- Inserir Data       | 2- Inserir Hora         |\n");
    printf("+=================================================+\n");
    printf("| 3- Inserir Descrição  | 4- Menu Principal       |\n");
    printf("+=================================================+\n");
    scanf("%d",&opMenuCriar);
}
void MenuVisualizar(){
    printf("+=================================================+\n");
    printf("| 1- Semana              | 2- Mês                 |\n");
    printf("+=================================================+\n");
    printf("| 3- Ano                 | 4- Menu Principal      |\n");
    printf("+=================================================+\n");
    scanf("%d",&opMenuVisualizar);
>>>>>>> 2285c9574772d04f7211c73c9c8f27fdc3d14fca
}
void MenuAnalisarLembretes(){
    printf("+=================================================+\n");
    printf("|    1- Modificar Data   |   2- Modificar Hora    |\n");
    printf("+=================================================+\n");
    printf("| 3- Modificar Descrição |    4- Menu Principal   |\n");
    printf("+=================================================+\n");
    scanf("%d",&opMenuAnalisar);
}