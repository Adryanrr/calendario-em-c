//calendario
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
int opMenuPrincipal,opMenuCriar,opMenuVisualizar,opMenuAnalisar;

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
}
void MenuAnalisar(){
    printf("+=================================================+\n");
    printf("| 1- Modificar Data      | 2- Modificar Hora      |\n");
    printf("+=================================================+\n");
    printf("| 3- Modificar Descrição | 4- Menu Principal      |\n");
    printf("+=================================================+\n");
    scanf("%d",&opMenuAnalisar);
}