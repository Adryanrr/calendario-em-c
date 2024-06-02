#include <stdio.h>

#define BLUE "\x1B[34m"
#define RED "\x1B[31m"
#define RESET "\x1B[0m"

int main() {
    printf(BLUE "                      _____________      ____                   _______________________\n");
    printf("              ________)            \\    /   /                      /                      \\\n");
    printf("     ________/  \\      " RED "RED BULL" RESET BLUE "   /  \\_/   |------/  Obrigado pela visita,\n");
    printf("____/_______| () |_______________| () |____|                       \\      Volte Sempre!  /\n");
    printf("|__ |        \\__/                 \\__/                            \\____________________/\n" RESET);

    return 0;
}
