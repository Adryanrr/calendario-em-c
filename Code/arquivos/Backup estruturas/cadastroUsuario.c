#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <locale.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdbool.h>
#include <stdbool.h>


void limparTerminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void MenuPrincipal();

FILE *arquivo;
// void cadastrarUsuario(struct usuario usuarios[], int *contagem);  
// void listarUsuarios(int *contagem, struct usuario usuarios[]);
void criarArquivoUser(){
  arquivo = fopen("usuarios.txt", "a");
  if (arquivo == NULL){
    printf("Erro ao criar arquivo! \n");
    exit(1);
  }
  fclose(arquivo);
}

#define MAXIMO_USUARIO 10

struct usuario{
  char nomeUsuario[50];
  char senha[50];
};

struct usuario usuarios[MAXIMO_USUARIO];
int contagem = 0;

int compararUsuario(const char *nomeUsuario, int contagem){
  for (int i = 0; i < contagem; i++){
    if (strcmp(nomeUsuario, usuarios[i].nomeUsuario) == 0){
        printf("já existe um usuario com esse nome\n");
        printf(" \n");
        printf(" \n");
        return 1;
    }
  }
  return 0;
}

void cadastrarUsuario(struct usuario usuarios[], int *contagem){

  arquivo = fopen("usuarios.txt", "a");
  if (*contagem >= MAXIMO_USUARIO){
    printf("Numero maximo de usuarios atingidos! \n");
    return;
  }

  struct usuario novoUsuario;
  printf("Insira o nome de usuario: \n");
  scanf("%s", novoUsuario.nomeUsuario);
  if(compararUsuario(novoUsuario.nomeUsuario, *contagem) ==1){
    printf("Tente outro nome de usuario! \n");
    return;
  }

  printf("Insira a senha do usuario: \n");
  scanf("%s", novoUsuario.senha);

  fprintf(arquivo, "%s" , novoUsuario.nomeUsuario);
  fprintf(arquivo, "%s\n", novoUsuario.senha);
  
  usuarios[*contagem] = novoUsuario;
  (*contagem)++;

  printf("Usuario cadastrado com sucesso! \n");
  
  fclose(arquivo);

  sleep(0.5);
  limparTerminal();
}


void listarUsuarios(int contagem, struct usuario usuarios[]) {
    limparTerminal();
    printf("Usuarios cadastrados:\n");
    for (int i = 0; i < contagem; i++) {
        printf("%d. %s\n", i + 1, usuarios[i].nomeUsuario);
    }
}


int main(){
  criarArquivoUser();
  while  (1){
    
    MenuPrincipal();
  }
  return 0;
}

void MenuPrincipal(){
    int opMenuPrincipal;
    printf("+===================================================================+\n");
    printf("|         1 - Cadastrar              2 - Listar                     |\n");
    printf("+===================================================================+\n");
    printf("Digite Qual opção você deseja acessar: \n");
    scanf("%d", &opMenuPrincipal);

    switch (opMenuPrincipal){
    case 1:
        cadastrarUsuario(usuarios, &contagem);
        break;
    case 2:
        listarUsuarios(contagem, usuarios);
        break;
    default:
        printf("Obrigado, volte sempre! \n");
        break;
    }
}