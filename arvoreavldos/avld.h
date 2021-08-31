#ifndef H_AVLD_H
#define H_AVLD_H

#include <stdio.h>
#include <stdlib.h>
#include "avld.h"

struct no
{
	int info;
	struct no *pai;
	struct no *esq;
	struct no *dir;
	int fatorBalanco;
};

typedef struct no arvore;

/*--------Prototipos de função----------------*/


void inicializar(arvore **T);

void insereAVL(arvore **p, int info, int *h);

void emOrdem(arvore *P, int nivel,int fatorBalanco);

int caso1(arvore ** p, int *h);

int caso2(arvore ** p, int *h);

void remocao(arvore **P, int x, int *h);

arvore *maiorDireita(arvore **T);


#endif