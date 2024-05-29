#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

// Struct
typedef struct {
    int hora;
    int min;
    char nome[100];
} evento;

// Function prototypes
void limparTerminal();
void MenuPrincipal();
void menuCalendario();
void logoCalendario();
void visualizarLembretes();
void calendarioIcev();
void Calendario();
bool check(const evento *e);
evento* UIEvento();
int intervalo1(const int minimo, const int maximo);
int intervalo2(const int minimo, const int maximo);
void novoEvento(evento *e);
void adicionarEvento(evento lista[], const evento e, const int x);
void organizar(evento lista[], const int size);
void organizarCorreto(evento lista[], int *size, evento e);
void obterDigitos(int num, char* primeiroDigito, char* segundoDigito);
void visualizarEvento(const evento e);
void mostrarEventos(const evento lista[], const int size);
void deletarEvento(evento lista[], int *size);
int eAnoBissexto(int ano);
int calcularPrimeiroDiaSemana(int ano, int mes);
void imprimirCalendario(int ano, int mes, int dia, int mesArray[]);
void exibirEventos(evento lista[], int contador);
char obterEscolha();

// Main function
int main() {
    limparTerminal();
    logoCalendario();
    MenuPrincipal();
    return 0;
}

// Clear terminal
void limparTerminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Display calendar logo
void logoCalendario() {
    printf(" ██████╗ █████╗ ██╗     ███████╗███╗   ██╗██████╗  █████╗ ██████╗ ██╗ ██████╗  \n");
    printf("██╔════╝██╔══██╗██║     ██╔════╝████╗  ██║██╔══██╗██╔══██╗██╔══██╗██║██╔═══██╗ \n");
    printf("██║     ███████║██║     █████╗  ██╔██╗ ██║██║  ██║███████║██████╔╝██║██║   ██║ \n");
    printf("██║     ██╔══██║██║     ██╔══╝  ██║╚██╗██║██║  ██║██╔══██║██╔══██╗██║██║   ██║ \n");
    printf("╚██████╗██║  ██║███████╗███████╗██║ ╚████║██████╔╝██║  ██║██║  ██║██║╚██████╔╝ \n");
    printf(" ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝╚═╝ ╚═════╝  \n");
}

// Main menu
void MenuPrincipal() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    int opMenuPrincipal;

    printf("+===================================================================+\n");
    printf("|         1 - Calendário               3 - Calendário Acadêmico      |\n");
    printf("|                                                                   |\n");
    printf("|     2 - Visualizar Evento                   4 - Exit              |\n");
    printf("+===================================================================+\n");
    printf("Digite qual opção você deseja acessar: \n");
    scanf("%d", &opMenuPrincipal);

    switch (opMenuPrincipal) {
    case 1:
        limparTerminal();
        Calendario();
        break;
    case 2:
        limparTerminal();
        novoEvento(NULL);
        break;
    case 3:
        limparTerminal();
        calendarioIcev();
        break;
    default:
        limparTerminal();
        printf("Obrigado, volte sempre! \n");
        break;
    }
}

void calendarioIcev() {
    printf("Calendário Acadêmico\n");
}

// Check if event is NULL
bool check(const evento *e) {
    return e == NULL;
}

evento* UIEvento() {
    evento *e = (evento*) malloc(sizeof(evento));
    e->hora = 0;
    e->min = 0;
    strcpy(e->nome, "");
    return e;
}

int intervalo1(const int minimo, const int maximo) {
    int input = 0;
    do {
        scanf("%2d", &input);
        if (input < minimo || input > maximo) {
            printf("Entrada incorreta, por favor tente novamente: ");
        }
    } while (input < minimo || input > maximo);
    return input;
}

int intervalo2(const int minimo, const int maximo) {
    int input = 0;
    do {
        scanf("%2d", &input);
        if (input < minimo || input > maximo) {
            printf("Entrada incorreta, por favor tente novamente: ");
        }
    } while (input < minimo || input > maximo);
    return input;
}

void novoEvento(evento *e) {
    if (check(e)) {
        e = UIEvento();
    }
    printf("\n \n  Novo  Evento  Selecionado  \n \n");
    printf("Digite a hora (0-23): ");
    e->hora = intervalo1(0, 23);
    printf("Digite o minuto (0-59): ");
    e->min = intervalo2(0, 59);
    printf("Por favor, inclua o nome ou descrição do evento: ");
    fgets(e->nome, 100, stdin);  // Remove any leftover newline character
    fgets(e->nome, 100, stdin);
    printf("Evento Adicionado: %02d:%02d %s\n", e->hora, e->min, e->nome);
}

void adicionarEvento(evento lista[], const evento e, const int x) {
    if (check(&e)) {
        return;
    }
    lista[x] = e;
}

void organizar(evento lista[], const int size) {
    int x, y;
    evento temp;
    for (x = 1; x < size; x++) {
        for (y = x; y > 0 && (lista[y - 1].hora > lista[y].hora || 
            (lista[y - 1].hora == lista[y].hora && lista[y - 1].min > lista[y].min)); y--) {
                temp = lista[y - 1];
                lista[y - 1] = lista[y];
                lista[y] = temp;
        }
    }
}

void organizarCorreto(evento lista[], int *size, evento e) {
    adicionarEvento(lista, e, *size);
    (*size)++;
    organizar(lista, *size);
}

void obterDigitos(int num, char* primeiroDigito, char* segundoDigito) {
    *primeiroDigito = (num / 10) + '0';
    *segundoDigito = (num % 10) + '0';
}

void visualizarEvento(const evento e) {
    char primeiroDigitoHora, segundoDigitoHora;
    char primeiroDigitoMinuto, segundoDigitoMinuto;

    obterDigitos(e.hora, &primeiroDigitoHora, &segundoDigitoHora);
    obterDigitos(e.min, &primeiroDigitoMinuto, &segundoDigitoMinuto);

    printf("%c%c:%c%c  ~ %s", primeiroDigitoHora, segundoDigitoHora, primeiroDigitoMinuto, segundoDigitoMinuto, e.nome);
}

void mostrarEventos(const evento lista[], const int size) {
    if (size == 0) {
        printf("Nenhum evento para mostrar\n");
        return;
    }
    printf("\nAgenda:\n");
    for (int x = 0; x < size; x++) {
        printf("[%d] ", x);
        visualizarEvento(lista[x]);
        printf("\n");
    }
}

void deletarEvento(evento lista[], int *size) {
    int x;
    if (*size == 0) {
        printf("Você não tem eventos para deletar.\n");
        return;
    }
    char temp[100];
    int locate;
    printf("DELETAR EVENTO\n");
    printf("Digite o número do evento que você deseja deletar: ");
    fgets(temp, 100, stdin);
    fgets(temp, 100, stdin);
    strtok(temp, "\n");
    locate = atoi(temp);
    if (locate >= *size) {
        printf("Nenhum evento encontrado\n");
        return;
    }
    for (x = locate; x < *size - 1; x++) {
        lista[x] = lista[x + 1];
    }
    (*size)--;
}

int eAnoBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int calcularPrimeiroDiaSemana(int ano, int mes) {
    int x = 1;
    int determinaDia = (x += mes < 3 ? ano : ano - 2, 23 * mes / 9 + x + 4 + ano / 4 - ano / 100 + ano / 400) % 7;
    if (mes == 1 || mes == 2) {
        determinaDia--;
        if (eAnoBissexto(ano) && mes == 1) determinaDia--;
    }
    return determinaDia;
}

void imprimirCalendario(int ano, int mes, int dia, int mesArray[]) {
    int determinaDia;
    determinaDia = calcularPrimeiroDiaSemana(ano, mes);
    printf("\n  S  T  Q  Q  S  S  D\n");
    for (int x = 0; x < determinaDia; x++) printf("   ");
    for (int x = 1; x <= mesArray[mes - 1]; x++) {
        if (x == dia) printf("[");
        else printf(" ");
        printf("%2d", x);
        if (x == dia) printf("]");
        else printf(" ");
        determinaDia++;
        if (determinaDia > 6) {
            determinaDia = 0;
            printf("\n");
        }
    }
    if (determinaDia != 0) printf("\n");
}

void exibirEventos(evento lista[], int contador) {
    printf("\n\nTodos Eventos \n");
    mostrarEventos(lista, contador);
    printf("\nSelecione (1) para criar um evento, (2) para deletar um evento, ou pressione (3) para voltar ao menu principal:\n");
    char escolha = obterEscolha();
    switch (escolha) {
    case '1':
        limparTerminal();
        novoEvento(&lista[contador]);
        organizarCorreto(lista, &contador, lista[contador]);
        exibirEventos(lista, contador);
        break;
    case '2':
        limparTerminal();
        deletarEvento(lista, &contador);
        exibirEventos(lista, contador);
        break;
    case '3':
        limparTerminal();
        MenuPrincipal();
        break;
    default:
        limparTerminal();
        printf("Por favor, digite uma opção válida.\n");
        exibirEventos(lista, contador);
        break;
    }
}

void Calendario() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    int ano, mes, dia;
    int mesArray[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    printf("Digite o ano: ");
    scanf("%d", &ano);
    printf("Digite o mês (1-12): ");
    scanf("%d", &mes);
    printf("Digite o dia: ");
    scanf("%d", &dia);
    if (eAnoBissexto(ano)) mesArray[1] = 29;
    imprimirCalendario(ano, mes, dia, mesArray);
    MenuPrincipal();
}

char obterEscolha() {
    char escolha;
    scanf(" %c", &escolha);
    return escolha;
}
