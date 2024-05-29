#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<locale.h>

// Function prototypes
void limparTerminal();
void MenuPrincipal();
void menuCalendario();
// ------------------------------
void logoCalendario();
void menuCalendario();
void visualizarLembretes();
// ------------------------------
void calendarioIcev();
// ------------------------------

int main(){
    limparTerminal();
    logoCalendario();
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

void logoCalendario(){

printf(" ██████╗ █████╗ ██╗     ███████╗███╗   ██╗██████╗  █████╗ ██████╗ ██╗ ██████╗  \n");
printf("██╔════╝██╔══██╗██║     ██╔════╝████╗  ██║██╔══██╗██╔══██╗██╔══██╗██║██╔═══██╗ \n");
printf("██║     ███████║██║     █████╗  ██╔██╗ ██║██║  ██║███████║██████╔╝██║██║   ██║ \n");
printf("██║     ██╔══██║██║     ██╔══╝  ██║╚██╗██║██║  ██║██╔══██║██╔══██╗██║██║   ██║ \n");
printf("╚██████╗██║  ██║███████╗███████╗██║ ╚████║██████╔╝██║  ██║██║  ██║██║╚██████╔╝ \n");
printf(" ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝ ╚═════╝  \n");
                                                                              
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
        menuCalendario();
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

void visualizarLembretes(){
    printf("Em construção!! \n");
}

void calendarioIcev(){
    printf("Em construção!! \n");
}