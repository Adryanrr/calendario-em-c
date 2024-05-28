#include <stdio.h>

#define LMonth 31
#define SMonth 30
#define VMonth 28

typedef enum {
    Dom,
    Seg,
    Ter,
    Qua,
    Qui,
    Sex,
    Sab
} SEMANA;

typedef enum {
    Janeiro = 1,
    Fevereiro,
    Marco,
    Abril,
    Maio,
    Junho,
    Julho,
    Agosto,
    Setembro,
    Outubro,
    Novembro,
    Dezembro
} MES;

struct Data {
  int dia;
  int mes;
  int ano;
};

void imprimirCabecalhoMes(void) {
   printf("    Dom    Seg    Ter    Qua    Qui    Sex    Sab\n");
}

void imprimirMes(SEMANA primeiroDia, int comprimento, int diaSelecionado) {
     SEMANA diaDaSemana = primeiroDia % 7;

     int i;

     imprimirCabecalhoMes();

     for (i=0; i<diaDaSemana; ++i) {
         printf("       ");
     }

    for(i=1; i<=comprimento; ++i) {
          diaDaSemana = (++diaDaSemana)%7;
          if (i == diaSelecionado) {
              printf("%7d*", i);  // Imprime um asterisco após o dia selecionado
          } else {
              printf("%7d ", i);
          }
          if(diaDaSemana==0) printf("\n");
    }

    printf("\n");
}

void SelecionarData(struct Data *data) {
  printf("Digite o dia: ");
  scanf("%d", &data->dia);
  printf("Digite o mes: ");
  scanf("%d", &data->mes);
  printf("Digite o ano: ");
  scanf("%d", &data->ano);
}

int diaDaSemana(struct Data *data) {
  int dia = data->dia;
  int mes = data->mes;
  int ano = data->ano;
  if (mes < 3) {
    mes += 12;
    ano -= 1;
  }
  return (dia + 2 * mes + 3 * (mes + 1) / 5 + ano + ano / 4 - ano / 100 + ano / 400) % 7;
}

int main(void) {
  struct Data data;
  SelecionarData(&data);
  imprimirMes(diaDaSemana(&data), (data.mes == 2 && data.ano % 4 == 0 && (data.ano % 100 != 0 || data.ano % 400 == 0)) ? 29 : (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11) ? 30 : 31, data.dia);
  return 0;
}