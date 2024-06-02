#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define LENGTH 50  // comprimento da barra de carregamento
#define PATTERN "_ _ _"  // padrão da estrada
#define PATTERN_LEN 5  // comprimento do padrão da estrada

void set_nonblocking_input() {
    struct termios ttystate;
    tcgetattr(STDIN_FILENO, &ttystate);

    ttystate.c_lflag &= ~ICANON;
    ttystate.c_lflag &= ~ECHO;
    ttystate.c_cc[VMIN] = 1;
    ttystate.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

int main() {
    char road[LENGTH + 1];  // +1 para o caractere nulo
    int i;
    int pattern_position = 0;
    char ch;

    // Configura entrada não-bloqueante
    set_nonblocking_input();
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);

    // Inicializa a barra de carregamento
    for (i = 0; i < LENGTH; i++) {
        road[i] = ' ';
    }
    road[LENGTH] = '\0';  // termina a string

    // Desenha o carro ASCII art na tela
    printf("         _______                |----------------------------------|   \n");
    printf("        //  ||\\ \\              |                                  |    \n");
    printf("  _____//___||_\\ \\___      ___|         obrigado, volte sempre!  |     \n");
    printf("  )  _          _    \\____|    |                                  |    \n");
    printf("  |_/ \\________/ \\___|          |----------------------------------|   \n");
    printf("    \\_/        \\_/                                                     \n");
    printf("\nPressione '0' para pular e sair.\n");

    while (1) {
        // Verifica se uma tecla foi pressionada
        if (read(STDIN_FILENO, &ch, 1) > 0) {
            if (ch == '0') {
                break;  // sai do loop se '0' for pressionado
            }
        }

        // Preenche a estrada com o padrão a partir da posição atual do padrão
        for (i = 0; i < LENGTH; i++) {
            road[i] = PATTERN[(pattern_position + i) % PATTERN_LEN];
        }

        // Imprime a estrada animada
        printf("\r%s", road);
        fflush(stdout);

        // Move a posição do padrão
        pattern_position = (pattern_position + 1) % PATTERN_LEN;

        // Aguarda um pouco antes da próxima atualização
        usleep(100000);  // 100 milissegundos
    }

    // Restaura o estado original do terminal
    struct termios ttystate;
    tcgetattr(STDIN_FILENO, &ttystate);
    ttystate.c_lflag |= ICANON;
    ttystate.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);

    printf("\nSaindo...\n");
    return 0;
}
