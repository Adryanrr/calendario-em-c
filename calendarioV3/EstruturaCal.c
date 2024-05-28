#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct {
    int hour; //entrada de hora do usuário para o evento
    int min; //entrada de minuto do usuário
    char name[100]; //nome do evento
}event;
//onde imprimir o menu
bool check (const event *e){
    return e==NULL;
} //verificar se o evento é NULL
event *UIEvent(){
    event *e = (event*) malloc(sizeof(event));
    e->hour=0;
    e->min=0;
    strcpy(e->name,"");
    return e;
} //definindo evento
//adicionar seleção (intervalo)
int range1(const int minimum, const int maximum){
    int input=0;
    int test=0;
    char temp[15];
labelh:scanf("%2d",&input);
       if(input>=minimum||input<=maximum){
       }else{
           printf("Entrada incorreta, por favor tente novamente: ");
           goto labelh;
       }
       return input;
}
int range2(const int minimum, const int maximum){
    int input=0;
    int test=0;
    char temp[15];
labelm:scanf("%2d",&input);
       if(input>=minimum||input<=maximum){
       }else{
           printf("Entrada incorreta, por favor tente novamente: ");
           goto labelm;
       }
       return input;
} //definindo intervalo para minutos
event *NewEvent(event *e){
    if(check(e)){
        e=UIEvent();
    }
    system("setterm -bold on");
    printf("\n \n  Novo  Evento  Selecionado  \n \n");
    system("setterm -bold off");
    printf("Digite a hora (0-23): ");
    e->hour=range1(0,23);
    printf("Digite o minuto (0-59): ");
    e->min=range2(0,59);
    puts("\n     NOME DO EVENTO     \n");
    printf("Por favor, inclua o nome ou descrição do evento: ");
    fgets(e->name,100,stdin);
    fgets(e->name,100,stdin);
    puts(" ----------------------------------");
    system("setterm -bold on");
    puts(" \nEvento Adicionado.");
    system("setterm -bold off");
    return e;
} //inicializando evento
void AddEvent(event list[],const event e, const int x){
	if(check(&e)){
return;
    }
    list[x].hour=e.hour;
    list[x].min=e.min;
    strcpy(list[x].name,e.name);
}//adicionando eventos a uma lista
//ordenando a ordem de tempo dos eventos em um dia
void sort (event list[],const int size){
    int x,y,storeh2,storem2;//store h para hora, m para min, 1 e 2, dependem de arr
    char name2[100];
    for (x=1;x<size;x++){
        for(y=x;y>0&&(list[y-1].hour>list[y].hour)||
                (list[y-1].hour==list[y].hour)&&(list[y-1].min>list[y].min);y--){
            storeh2=list[y-1].hour;
            storem2=list[y-1].min;
            strcpy(name2,list[y-1].name);
            //evento 2 ^
            list[y-1].hour=list[y].hour;
            list[y-1].min=list[y].min;
            strcpy(list[y-1].name,list[y].name);
            //trocar os dois usando o armazenamento temporário
            list[y].hour=storeh2;
            list[y].min=storem2;
            strcpy(list[y].name,name2);
        }
    }
}
void CorrectSort (event list[], int *size, event e){
    AddEvent(list,e,*size);
    (*size)++;
    sort(list,*size);
}
void printEvent(const event e){ //<---printevent sourced by: stackexchange.com
  char hour1 = {(e.hour/10)+ '0'};//primeiro dígito
	char hour2 = {(e.hour-(e.hour/10)*10)+'0'};
	char min1 = {(e.min/10)+'0'};
	char min2 = {(e.min-(e.min/10)*10)+'0'};
	printf("%c%c:%c%c  ~%s\n",hour1,hour2,min1,min2,e.name);
}
void printList(const event list[],const int size){
    if(size==0){
      puts("\n Você não tem eventos agendados. \n");
  }
  system("setterm -bold on");
  printf("\n Agenda: \n");
  system("setterm -bold off");
  for(int x=0;x<size;x++){
      printf(" [%d]  ",x);
      printEvent(list[x]);
  }
} //imprimir a lista de eventos
void deleteEvent(event list[],int *size){
  int x;
  if(*size==0){
      puts("\n Você não tem eventos para deletar. \n");
      return;
  }
  char temp[100];
  int locate;
  system("setterm -bold on");
  printf("\n    DELETAR EVENTO   \n");
  system("setterm -bold off");
  printf("\n Digite o número do evento que você deseja deletar: ");
  fgets(temp,100,stdin);
  fgets(temp,100,stdin);
  strtok(temp,"\n");
  locate = atoi(temp);
  //locate=locate-y;
  if(locate>*size-1){
      printf(" \n Nenhum evento encontrado \n");
      return;
  }
  list[locate].hour=70; //marcar o evento para exclusão
  list[locate].min=70;
  strcpy(list[locate].name,"");
  sort(list,*size);
  (*size)--;
}

void menu(){
  printf("Pressione 1: para criar evento\n");
  printf("Pressione 2: para deletar evento\n");
  printf("Pressione 3: para sair\n\n");
  //função principal para o calendário
}
int main () {
  system("clear");
  event list[15];
  static const char* MonthDisplay[]={
      "Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho","Agosto","Setembro",
      "Outubro","Novembro","Dezembro"
  };
  int year, month, day,leap=0,x, day2;
  int count=0;
  char temp[100];
  signed char c; //entrada do usuário para mudança de calendário
  int MonthArray[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  system("setterm -bold on"); //cabeçalho em negrito
  printf("Calendário de Eventos \n");
  system("setterm -bold off");
label1:printf("Digite o ano: ");
      scanf("%d",&year); //entrada do usuário para o ano
      if (year<0){
          printf("Ano não adequado. \n");
          goto label1; //label 1 para entrada de ano incorreta
       }
label2:printf("Digite o mês: ");
      scanf("%d", &month); //entrada do usuário para o mês
      if(!(month<13) || !(month>0)){
          printf("Mês não adequado. \n");
          goto label2; //label 2 para entrada de mês incorreta
      }
label3:printf("Digite o dia: ");
      scanf("%d", &day); //entrada do usuário para o dia
      if (day<1||day>31){
          printf("Dia não adequado. \n");
          goto label3;
      }else if(month==4||month==6||month==9||month==11){ //entrada incorreta para 30 dias
          if (day>30){
              printf("Dia não adequado. \n");
              goto label3;
          }
      }else if (month==2){ //entrada incorreta para fevereiro
          if ((year%4)==0&&(year%100!=0)||(year%400==0)){ //possibilidade de ano bissexto
              MonthArray[1]=29;
              if(day>29){ //29 dias
                  printf("Dia não adequado. \n");
                  goto label3;
              }
          }else{
              if(day>28){ //28 dias
                  printf("Dia não adequado. \n");
                  goto label3;
              }
          }
      }
      //imprimindo calendário
      int DetermineDay;
label4:system("clear");
       x=1;
       DetermineDay=(x+=month<3?year:year-2,23*month/9+x+4+year/4-year/100+year/400)%7;
       if((year%4)==0&&(year%100!=0)||(year%400==0)){
	       MonthArray[1]=29;
	       if(month==1||month==2){
		       DetermineDay--;
		       if (DetermineDay<0){
			       DetermineDay=6;
		       }
	       }
       }else{
	       MonthArray[1]=28;
       }
      //Fonte da linha acima: cadaeit.net
      system("setterm -bold on"); //cabeçalho em negrito
      printf("\n         %s    %d \n", MonthDisplay[month-1],year); //cabeçalho
      printf("\nDOM  SEG  TER  QUA  QUI  SEX  SAB\n");
      system("setterm -bold off");
      for(day2=1;day2<=DetermineDay;day2++){ //day2 é o contador
          printf("     ");
      } //inicializa a posição do primeiro dia
      printf(" ");
      for (day2=1;day2<=MonthArray[month-1];day2 = day2 + 1){
          //preenche o calendário
          if(day==day2){ //torna a saída vermelha
              printf("\e[5;31;40m%2d\e[0m",day); //não pisca
          }else{
              printf("%2d",day2);
          }
          if(((day2+DetermineDay)%7) > 0) { //passa para a próxima linha após sábado
              printf("   ");
          }else{
              printf("\n ");
          }
      }
      //tentativa de negrito no dia de entrada do usuário
      printf("\n\n");
      //exibe o dia:
label5:printf("Você selecionou %s %d, %d \n",MonthDisplay[month-1],day,year);
      //exibe eventos
      //carrega do arquivo de saída :(
      printList(list,count);
      //instruções para entrada do usuário
      printf("   - Para alternar entre os dias, use (a) para o dia anterior e (d) para o próximo dia. \n");
      printf("   - Para alternar entre os meses, use w (anterior) e s (próximo).\n\n");
      menu();
      scanf("%c",&c);
       if(c=='\n'){
	       scanf("%c",&c);
       }
while(c!=3){
        if(c=='1'){
            CorrectSort(list,&count,*NewEvent(&list[count]));
            //salvar(list,count);
            goto label4;
        }else if(c=='2'){
            deleteEvent(list,&count);
            //salvar(list,count);
            goto label4;
        }else if(c=='3'){
            system("clear");
            system("setterm -bold on");
            printf("\n\n\n TENHA UM ÓTIMO DIA ENQUANTO EU PROGRAMO ISSO!!  :)) \n\n\n\n");
            system("setterm -bold off");
            break;
        }else if(c=='w'){ //mês anterior
            if(month==1){
                year--;
                month=12;
            }else{
                month--;
            }
            if(day>MonthArray[month-1]){
                day=MonthArray[month-1];
            }
            goto label4;
        }else if(c=='s'){ //próximo mês
            if(month==12){
                month=1;
                year++;
            }else{
                month++;
            }
            if(day>MonthArray[month-1]){
			       day=MonthArray[month-1];
		       }
		       goto label4;
        }else if(c=='a'){ //dia anterior
            if(day==1){
                month--;
                day=MonthArray[month-1];
            }else{
                day--;
            }goto label4;
        }else if(c=='d'){ //próximo dia
            if (day==MonthArray[month-1]){
                day=1;
                month++;
            }else{
                day++;
            }
            goto label4;
        }else{
            printf("Resposta inválida. Por favor, tente novamente. \n");
            goto label4;
        }
    }
    return 0;
}