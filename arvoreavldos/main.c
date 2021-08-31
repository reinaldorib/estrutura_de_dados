#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"avld.h"


int main(int argc, char *argv[])
{
	arvore *P = NULL;
	
	int valor,h = 1;
	

	//for (int i = 0; i < 9; ++i)
	//{
			
		do
		{
			if(valor != 0)
			{
				printf("\nvalor a ser inserido:");
				scanf("%d",&valor);
				insereAVL(&P,valor,&h);
				//insereAVL(&P,10,h);
				//insereAVL(&P,5,h);
				//insereAVL(&P,8,h);
				//insereAVL(&P,7,h);
				//insereAVL(&P,6,h);
				//insereAVL(&P,7,h);
				emOrdem(P,0,0);
			}

		}while(valor > 0);
	//}





	/*
	insereAVL(&P,30,&h);
	insereAVL(&P,50,&h);
	insereAVL(&P,80,&h);
	insereAVL(&P,15,&h);
	insereAVL(&P,40,&h);
	insereAVL(&P,60,&h);
	insereAVL(&P,100,&h);

	remocao(&P,60,&h);
	remocao(&P,100,&h);

	emOrdem(P,0,0);
	

	*/	
		
	
	return 1;
}