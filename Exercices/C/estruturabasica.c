#include <stdio.h>
#include <stdlib.h>

struct horario{
	int hora;
	int minutos;
	int segundos;
};

struct horario funcao_teste(struct horario x);

int main(){
	typedef int numero;
	typedef int *ponteiroint;


	struct horario agora;

	agora.hora = 15; 
	agora.minutos = 26;
	agora.segundos = 43;

	printf("Horário agora:  %dh%dmin%ds\n", agora.hora, agora.minutos, agora.segundos);

	struct horario depois;

	depois.hora = agora.hora + 3;
	depois.minutos = agora.minutos;
	depois.segundos = agora.segundos - 13;

	printf("Horário depois: %dh%dmin%ds\n", depois.hora, depois.minutos, depois.segundos);

	struct horario amanha = funcao_teste(agora);
	printf("Horário agora:  %dh%dmin%ds\n", agora.hora, agora.minutos, agora.segundos);
	printf("Horário amanha:  %dh%dmin%ds\n", amanha.hora, amanha.minutos, amanha.segundos);

	struct horario ontem = {22, 11, 56};
	printf("Horário ontem:  %dh%dmin%ds\n", ontem.hora, ontem.minutos, ontem.segundos);

	struct horario jaja = {2};
	printf("Horário jaja:  %dh%dmin%ds\n", jaja.hora, jaja.minutos, jaja.segundos);

	struct horario logologo = {.segundos = 59, .minutos = 01};
	printf("Horário logologo:  %dh%dmin%ds\n", logologo.hora, logologo.minutos, logologo.segundos);

	struct horario momentos[5] = {{3, 10, 15}, {6, 20, 30}, {9, 30, 45}, {12, 40, 59}, {15, 50, 9}};
	for (int i = 0; i < 5; ++i)
	{
		printf("Horário momentos:  %dh%dmin%ds\n", momentos[i].hora, momentos[i].minutos, momentos[i].segundos);
	};

	struct horario *mudaagora;
	mudaagora = &agora;
	(*mudaagora).hora += 3;
	(*mudaagora).minutos = 33;
	(*mudaagora).segundos = 14;

	printf("Horário agora:  %dh%dmin%ds\n", agora.hora, agora.minutos, agora.segundos);

	mudaagora->hora = 17;
	mudaagora->minutos += 10;
	mudaagora->segundos *= 3;

	printf("Horário agora:  %dh%dmin%ds\n", agora.hora, agora.minutos, agora.segundos);

	struct horario antes;
	antes.hora = 5 + (*mudaagora).hora;
	antes.minutos = 7 + mudaagora->minutos;
	antes.segundos = mudaagora->segundos/3;

	printf("Horário antes:  %dh%dmin%ds\n", antes.hora, antes.minutos, antes.segundos);

	struct phorario{
		int *phora;
		int *pminutos;
		int *psegundos;
	};

	struct phorario hoje;

	int h = 12, min = 21, s = 11;

	hoje.phora = &h;
	hoje.pminutos = &min;
	hoje.psegundos = &s;

	printf("Horário hoje:  %ih%imin%is\n", *hoje.phora, *hoje.pminutos, *hoje.psegundos);

	numero H = 11, M = 26, S = 57;
	struct horario *mudaantes = &antes;
	antes.hora = H;
	(*mudaantes).minutos = M;
	mudaantes->segundos = S;

	printf("Horário antes:  %dh%dmin%ds\n", antes.hora, antes.minutos, antes.segundos);

	typedef struct horario momento;
	momento quando;
	struct horario *mudaquando = &quando;
	quando.hora = H;
	(*mudaquando).minutos = M;
	mudaquando->segundos = S;

	printf("Horário quando:  %dh%dmin%ds\n", quando.hora, quando.minutos, quando.segundos);

	int *p = malloc(sizeof(int));
	printf("p(%p) = %d\n", p, *p);
	*p = 1000;
	printf("p(%p) = %d\n", p, *p);
	free(p);
	int *m = calloc(10, sizeof(int));
	*m = 10;
	*(m+1) = 20;
	printf("m(%p) = %d\n", m, *m);	printf("m+1(%p) = %d\n", m, m[1]);

	



	return 0;
}

struct horario funcao_teste(struct horario x){

	x.hora += 2; 
	x.minutos -= 10;
	x.segundos += 2;

	return x;
}