#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>


int main(){
    setlocale(LC_ALL,"Portuguese_Brazil");
    int i;
    printf("Carregando...\n");
    for(i = 0; i < 100; i++){
        printf("%d%%\r", i);
        fflush(stdout);
        system("sleep 0.1");
    }
    printf("Carregado com sucesso!\n");
    return 0;
}