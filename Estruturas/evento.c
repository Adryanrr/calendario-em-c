#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct {
  int hora; //hora do evento
  int min; //minuto do evento
  char nome[100]; //nome do evento
}evento;

bool check (const evento *e){
  return e==NULL;
}

evento *criarEvento(){
  evento *e = (evento*) malloc(sizeof(evento));
  e->hora=0;
  e->min=0;
  strcpy(e->nome,"");
  return e;
}
int teste1(const int minimo, const int maximo){
  int input=0;
  int teste=0;
  char temp[15];
labelh:scanf("%2d",&input);
       if(input>=minimo||input<=maximo){
       }else{
         printf("Entrada incorreta, tente novamente: ");
         goto labelh;
       }
       return input;
}
int teste2(const int minimo, const int maximo){
  int input=0;
  int teste=0;
  char temp[15];
labelm:scanf("%2d",&input);
       if(input>=minimo||input<=maximo){
       }else{
         printf("Entrada incorreta, tente novamente: ");
         goto labelm;
       }
       return input;
}
evento *NovoEvento(evento *e){
  if(check(e)){
    e=criarEvento();
  }
  system("setterm -bold on");
  printf("\n \n  Novo Evento Selecionado  \n \n");
  system("setterm -bold off");
  printf("Digite a hora (0-23): ");
  e->hora=teste1(0,23);
  printf("Digite o minuto (0-59): ");
  e->min=teste2(0,59);
  puts("\n     NOME DO EVENTO     \n");
  printf("Por favor, inclua o nome ou descrição do evento: ");
  fgets(e->nome,100,stdin);
  fgets(e->nome,100,stdin);
  puts(" ----------------------------------");
  system("setterm -bold on"); // deixa em negrito!
  puts(" \n Evento adicionado");
	system("setterm -bold off"); // remove o negrito!
  return e;
} 
void AdicionarEvento(evento lista[],const evento e, const int x){
  if(check(&e)){
    return;
  }
  lista[x]=hora=e.hora;
  lista[x]=min=e.min;
  strcpy(lista[x].nome,e.nome);
}