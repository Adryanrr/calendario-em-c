#include<string.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<locale.h>
#include <stdbool.h>
#include <Windows.h>
#include <unistd.h>

typedef struct {
    int hora;
    int min;
    char nome[100];
}evento;

// Funções de interface do usuário
void limparTerminal();
void menuPrincipal();
void menuCalendario();
void logoCalendario();
char obterEscolha();

// Funções de manipulação de eventos
bool check(const evento *e);
evento* UIEvento();
void novoEvento(evento *e);
void adicionarEvento(evento lista[], const evento e, const int x);
void organizar(evento lista[], const int contador);
void organizarCorreto(evento lista[], int *contador, evento e);
void deletarEvento(evento lista[], int *contador);
void visualizarEvento(const evento e);
void mostrarEventos(const evento lista[], const int contador);
void exibirEventos(evento lista[], int contador);

// Funções de manipulação de datas
int eAnoBissexto(int ano);
int calcularPrimeiroDiaSemana(int ano, int mes);
void imprimirCalendario(int ano, int mes, int dia, int mesArray[]);
int intervalo1(const int minimo, const int maximo);
int intervalo2(const int minimo, const int maximo);
void obterDigitos(int num, char* primeiroDigito, char* segundoDigito);

// Funções específicas do calendário
void visualizarLembretes();
void calendarioIcev();
void calendario();

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

printf(" ██████╗ █████╗ ██╗     ███████╗███╗   ██╗██████╗  █████╗ ██████╗ ██╗ ██████╗  \n");
printf("██╔════╝██╔══██╗██║     ██╔════╝████╗  ██║██╔══██╗██╔══██╗██╔══██╗██║██╔═══██╗ \n");
printf("██║     ███████║██║     █████╗  ██╔██╗ ██║██║  ██║███████║██████╔╝██║██║   ██║ \n");
printf("██║     ██╔══██║██║     ██╔══╝  ██║╚██╗██║██║  ██║██╔══██║██╔══██╗██║██║   ██║ \n");
printf("╚██████╗██║  ██║███████╗███████╗██║ ╚████║██████╔╝██║  ██║██║  ██║██║╚██████╔╝ \n");
printf(" ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝ ╚═════╝  \n");
                                                                              
}

void menuPrincipal(){
    setlocale(LC_ALL,"Portuguese_Brazil");
    int opMenuPrincipal;

    printf("+===================================================================+\n");
    printf("|         1 - Calendario                 2 - Criar Lembrete         |\n");
    printf("|                                                                   |\n");
    printf("|     3 - Visualizar Evento           4 - Calendario Academico      |\n");
    printf("|                                                                   |\n");
    printf("|                           0 - Exit                                |\n");
    printf("+===================================================================+\n");
    printf("Digite Qual opção você deseja acessar: \n");
    scanf("%d", &opMenuPrincipal);

    switch (opMenuPrincipal){
    case 1:
        limparTerminal();
        printf("Calendario \n");
        break;
    case 2:
        limparTerminal();
        printf("Criar Lembrete \n");
        break;
    case 3:
        limparTerminal();
        printf("Visualizar Evento \n");
        break;
    case 4: 
          limparTerminal();
        printf("Calendario Academico \n");
    case 0:
        limparTerminal();
        printf("Obrigado, volte sempre! \n");
      default:
        printf("Opção inválida, tente novamente! \n");
        sleep(300);
        limparTerminal();
        menuPrincipal();
      }
}
