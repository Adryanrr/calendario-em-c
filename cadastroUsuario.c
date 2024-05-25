#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void MenuPrincipal();
// void cadastrarUsuario(struct usuario usuarios[], int *contagem);  
// void listarUsuarios(int *contagem, struct usuario usuarios[]);

#define MAXIMO_USUARIO 3

// void limparTerminal() {
// #ifdef _WIN32
//     system("cls");
// #else
//     system("clear");
// #endif
//}
struct usuario{
  char nomeUsuario[50];
  char senha[50];
};
  struct usuario usuarios[MAXIMO_USUARIO];
  int contagem = 0;

void cadastrarUsuario(struct usuario usuarios[], int *contagem){
  if (*contagem >= MAXIMO_USUARIO){
    printf("Numero maximo de usuarios atingidos! \n");
    return;
  }
  struct usuario novoUsuario;
  printf("Insira o nome de usuario: \n");
  scanf("%s", novoUsuario.nomeUsuario);
  printf("Insira a senha do usuario: \n");
  scanf("%s", novoUsuario.senha);
  usuarios[*contagem] = novoUsuario;
  (*contagem)++;

  printf("Usuario cadastrado com sucesso!");

  MenuPrincipal();
}

void listarUsuarios(int *contagem, struct usuario usuarios[]){
  int i;
  for (i = 0; i < 2; i++){
    printf("Usuarios cadastrados: %s \n", usuarios[i].nomeUsuario);
  }

  MenuPrincipal();
  
}

int main(){
  MenuPrincipal();
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
        listarUsuarios(&contagem, usuarios);
        break;
    default:
        printf("Obrigado, volte sempre! \n");
        break;
    }
}