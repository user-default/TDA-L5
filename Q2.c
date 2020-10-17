#include <stdio.h>
#include <string.h>

struct horario
{
	int h_hora;
	int h_minutos;
	int h_segundos;
};
struct data
{
	int d_dia;
	char d_mes[10];
	int d_ano;
};

struct compromisso
{
	struct data c_data;
	struct horario c_horario;
	char c_texto[50];
	
};
typedef struct compromisso Compromisso;

void main(void) 
{
	Compromisso agenda[100];
	
	agenda[0].c_data.d_dia = 1;
	strcpy(agenda[0].c_data.d_mes, "Outubro");
	agenda[0].c_data.d_ano = 2020;
	agenda[0].c_horario.h_hora = 13;
	agenda[0].c_horario.h_minutos = 30;
	agenda[0].c_horario.h_segundos = 2;
	strcpy(agenda[0].c_texto, "Brainstorm da tarde");
	
	printf("Reserva confirmada para:\n%d, de %s, de %d\nHorario: %d:%d:%d\nAssunto: %s\n", 
	 agenda[0].c_data.d_dia, agenda[0].c_data.d_mes, agenda[0].c_data.d_ano,
	 agenda[0].c_horario.h_hora, agenda[0].c_horario.h_minutos, agenda[0].c_horario.h_segundos,
	 agenda[0].c_texto);
}
