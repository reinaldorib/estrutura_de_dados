#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"avld.h"




/*------- Funcoes-----------------------------*/



void inicializar(arvore **T)
{
	*T = NULL;
}


int caso1(arvore ** p, int *h)
{
	arvore *u,*v;
	u = (*p)->esq;
	if(u->fatorBalanco == -1)
	{
		(*p)->esq = u->dir;
		u->dir = (*p);
		(*p)->fatorBalanco = 0;
		*p = u; 
	}
	else
	{
		v = u->dir;
		u->dir = v->esq;
		v->esq = u;
		(*p)->esq = v->dir;
		v->dir = *p;

		if(v->fatorBalanco == -1)
			(*p)->fatorBalanco = 1;
		else
			(*p)->fatorBalanco = 0;

		if(v->fatorBalanco == 1)
			u->fatorBalanco = -1;
		else
			u->fatorBalanco = 0;

		*p = v;
		
		
		
	}
	(*p)->fatorBalanco = 0;
	*h = 0;
	

}

int caso2(arvore ** p, int *h)
{
	arvore *u,*v;
	u = (*p)->dir;
	if(u->fatorBalanco == 1)
	{
		(*p)->dir = u->esq;
		u->esq = *p;
		(*p)->fatorBalanco = 0;
		*p = u;
	}
	else
	{
		v = u->esq;
		u->esq = v->dir;
		v->dir = u;
		(*p)->dir = v->esq;
		v->esq = *p;
		if(v->fatorBalanco == 1)
			(*p)->fatorBalanco = -1;
		else
			(*p)->fatorBalanco = 0;

		if(v->fatorBalanco == -1)
			u->fatorBalanco = 1;
		else
			u->fatorBalanco = 0;

		*p = v;
		
		
		
	}
	(*p)->fatorBalanco = 0;
	*h = 0;
	
}

void insereAVL(arvore **p, int x, int *h)
{
	if(*p == NULL)
	{
		arvore * novo;
		novo = (arvore*) malloc(sizeof(arvore));
		novo->info = x;
		novo->fatorBalanco = 0;
		novo->pai = NULL;
		novo->dir = novo->esq = NULL;
		*p = novo;
		*h = 1;
	}
	else
	{
		if(x<(*p)->info)
		{
			insereAVL(&((*p)->esq),x,h);
			if(*h)
			{
				switch((*p)->fatorBalanco)
				{
					case 1: (*p)->fatorBalanco = 0 ; h = 0;
					break;
					case 0: (*p)->fatorBalanco = -1 ;
					break;
					case -1: caso1(p,h);
					break;

				}
			}
		}
		else
		{
			insereAVL(&((*p)->dir),x,h);
			if(*h)
			{
				switch((*p)->fatorBalanco)
				{
					case -1: (*p)->fatorBalanco = 0; h = 0;
					break;
					case 0:(*p)->fatorBalanco = 1;
					break;
					case 1: caso2(p,h);
					break;
				}
			}
		}
	}
}


void emOrdem(arvore *P,int nivel,int fatorBalanco)
{
	if(P != NULL)
	{
		emOrdem(P->esq,nivel+1,fatorBalanco);
		printf("%d, nivel:%i fator de balanceamento:%i\n",P->info, nivel,P->fatorBalanco);
		emOrdem(P->dir,nivel+1,fatorBalanco);
	}
}


arvore *maiorDireita(arvore **T)
{
  if((*T)->dir != NULL)
    return maiorDireita(&((*T)->dir));
  else
  {
    arvore *aux;
    aux = *T;
    if((*T)->esq != NULL)
      *T = (*T)->esq;
    else
      *T = NULL;
    return aux;
  }

}

void remocao(arvore **P, int x, int *h)
{
	if((*P)->info == x)
	{
		arvore *aux;
		aux = *P;
		//------- exlcusao para nós folha, sem filhos.
		if((*P)->esq == NULL && (*P)->dir)
		{
			free(aux);
			(*P) = NULL;
		}
		//------- exlcusao para nós com apenas o filho da direita
		else if((*P)->esq == NULL)
		{
			(*P) = (*P)->dir;
			aux->dir = NULL;
			free(aux);
		}
		 //-------exclusao para nós apenas com o filho da esquerda
		else if((*P)-> dir == NULL)
		{
			(*P) = (*P)->esq;
			aux->esq = NULL;
			free(aux);
		}
		//-----------exclusao de nos com dois filhos
		else
		{
			aux = maiorDireita(&(*P)->esq);
			aux->esq = (*P)->esq;
			aux->dir = (*P)->dir;
			(*P)->esq = (*P)->dir = NULL;
			free((*P));
			*P = aux;
		}
	}
	else
	{

		if(x < (*P)->info)
		{
			remocao(&((*P)->esq),x,h);
			if(*h)
			{
				switch((*P)->fatorBalanco)
				{
					case -1: (*P)->fatorBalanco = 0; *h = 0;
					break;
					case 0:(*P)->fatorBalanco = 1;
					break;
					case 1: caso2(P,h);
					break;
				}
			}

		}
		else
		{
			remocao(&((*P)->dir),x,h);
			if(*h)
			{
				switch((*P)->fatorBalanco)
				{
					case 1: (*P)->fatorBalanco = 0 ; *h = 0;
					break;
					case 0: (*P)->fatorBalanco = -1 ;
					break;
					case -1: caso1(P,h);
					break;

				}
			}
		}
	}

}
