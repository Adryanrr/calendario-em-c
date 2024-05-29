#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <unistd.h>

  static const char* MonthDisplay[]={
      "Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho","Agosto","Setembro",
      "Outubro","Novembro","Dezembro"
  };
  int year, mes, dia,x, day2;
  signed char c; //entrada do usuário para mudança de calendário
  int mesArray[12]={31,28,31,30,31,30,31,31,30,31,30,31};

void menu(){
  printf("Pressione 1: para criar evento\n");
  printf("Pressione 2: para deletar evento\n");
  printf("Pressione 3: para sair\n\n");
  //função principal para o calendário
}
int DetermineDay;
void GerarCalendario(){
    //Fonte da linha acima: cadaeit.net
      system("setterm -bold on"); //cabeçalho em negrito
      printf("\n         %s    %d \n", MonthDisplay[mes-1],year); //cabeçalho
      printf("\nDOM  SEG  TER  QUA  QUI  SEX  SAB\n");
      system("setterm -bold off");
      for(day2=1;day2<=DetermineDay;day2++){ //day2 é o contador
          printf("     ");
      } //inicializa a posição do primeiro dia
      printf(" ");
      for (day2=1;day2<=mesArray[mes-1];day2 = day2 + 1){
          //preenche o calendário
          if(dia==day2){ //torna a saída vermelha
              printf("\e[5;31;40m%2d\e[0m",dia); //não pisca
          }else{
              printf("%2d",day2);
          }
          if(((day2+DetermineDay)%7) > 0) { //passa para a próxima linha após sábado
              printf("   ");
          }else{
              printf("\n ");
          }
      }
}

int main () {
  system("clear");
  system("setterm -bold on"); //cabeçalho em negrito
  printf("Calendário de Eventos \n");
  system("setterm -bold off");
  
printf("Digite o ano: ");
scanf("%d", &year); //entrada do usuário para o ano
while (year < 0) {
    printf("Ano não adequado. \n");
    printf("Digite o ano: ");
    scanf("%d", &year); //entrada do usuário para o ano
}

printf("Digite o mês: ");
scanf("%d", &mes); //entrada do usuário para o mês
while (!(mes < 13) || !(mes > 0)) {
    printf("Mês não adequado. \n");
    printf("Digite o mês: ");
    scanf("%d", &mes); //entrada do usuário para o mês
}

printf("Digite o dia: ");
scanf("%d", &dia); //entrada do usuário para o dia
while (dia < 1 || dia > 31) {
    printf("Dia não adequado. \n");
    printf("Digite o dia: ");
    scanf("%d", &dia); //entrada do usuário para o dia
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) { //entrada incorreta para 30 dias
        if (dia > 30) {
            printf("Dia não adequado. \n");
            continue;
        }
    } else if (mes == 2) { //entrada incorreta para fevereiro
        if (((year % 4) == 0 && (year % 100 != 0)) || (year % 400 == 0)) { //possibilidade de ano bissexto
            mesArray[1] = 29;
            if (dia > 29) { //29 dias
                printf("Dia não adequado. \n");
                continue;
            }
        } else {
            if (dia > 28) { //28 dias
                printf("Dia não adequado. \n");
                continue;
            }
        }
    }
}
      //imprimindo calendário
      int DetermineDay;
        system("clear");
        x=1;
        DetermineDay=(x+=mes<3?year:year-2,23*mes/9+x+4+year/4-year/100+year/400)%7;
    if((year%4)==0&&((year%100)!=0||(year%400)==0)){
	       mesArray[1]=29;
	       if(mes==1||mes==2){
		       DetermineDay--;
		       if (DetermineDay<0){
			       DetermineDay=6;
		       }
	       }
       }else{
	       mesArray[1]=28;
       }
      
      //tentativa de negrito no dia de entrada do usuário
      GerarCalendario();
      printf("\n\n");
      //exibe o dia:
        printf("Você selecionou %s %d, %d \n",MonthDisplay[mes-1],dia,year);
      //exibe eventos
      //carrega do arquivo de saída :(
      // printList(list,count);
      //instruções para entrada do usuário
      printf("   - Para alternar entre os dias, use (a) para o dia anterior e (d) para o próximo dia. \n");
      printf("   - Para alternar entre os meses, use w (anterior) e s (próximo).\n\n");
      menu();
      scanf("%c",&c);
       if(c=='\n'){
	       scanf("%c",&c);
       }

    void GerarCalendario(); // Add function declaration for 'GerarCalendario'

   while(c!=3){
        if(c=='1'){

            //salvar(list,count);
            GerarCalendario();
        }else if(c=='2'){

            //salvar(list,count);
            GerarCalendario();
        }else if(c=='3'){
            system("clear");
            system("setterm -bold on");
            printf("\n\n\n TENHA UM ÓTIMO DIA ENQUANTO EU PROGRAMO ISSO!!  :)) \n\n\n\n");
            system("setterm -bold off");
            break;
        }else if(c=='w'){ //mês anterior
            if(mes==1){
                year--;
                mes=12;
            }else{
                mes--;
            }
            if(dia>mesArray[mes-1]){
                dia=mesArray[mes-1];
            }
            GerarCalendario();
        }else if(c=='s'){ //próximo mês
            if(mes==12){
                mes=1;
                year++;
            }else{
                mes++;
            }
            if(dia>mesArray[mes-1]){
			       dia=mesArray[mes-1];
		       }
		       GerarCalendario();
        }else if(c=='a'){ //dia anterior
            if(dia==1){
                mes--;
                dia=mesArray[mes-1];
            }else{
                dia--;
            }GerarCalendario();
        }else if(c=='d'){ //próximo dia
            if (dia==mesArray[mes-1]){
                dia=1;
                mes++;
            }else{
                dia++;
            }
            GerarCalendario();
        }else{
            printf("Resposta inválida. Por favor, tente novamente. \n");
            GerarCalendario();
    }
 }
}