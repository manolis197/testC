#include<stdio.h>
#include<iostream>
#include<string.h>
#define BOO 100 

struct car
{
	int year;
	float prise;
	char model[50];
};

int main(void)
{
	int i, temp, ko, cnt = 0;
	char check[50];
	char chock[50];
	struct car a[BOO];
	
	for(i = 0 ; i < BOO ; i++)
	{	
		printf("\ndose xronia: ");
		scanf("%d",&a[i].year);
		
		if(a[i].year == -1)
		{
			break;
		}
			
		printf("dose timi: ");
		scanf("%f", &a[i].prise);
		
		getchar();
		
		printf("dose modelo: ");
		gets(a[i].model);		

		cnt++;		
	}
	
	system("cls");
	getchar();
		

	while(1)
	{	
	
		jump:
		{
			printf("\n\n-----------------------------------------------------------------------");
			printf("\n end            :gia termathsmo");
			printf("\n kostos         :gia na sar emfanizei autokiniko megalhterh timh");
			printf("\n *              :gia gia na sat ta emfanhzh ola");
			printf("\n models         :gia na sas diksi to montelo poy 8elete");
			
			printf("\nti 8elis: ");
			gets(chock);
			system("cls");
		
			// termatismos
			if(strcmp(chock, "end") == 0)
			{
				return 0;
			}
		
			//kostos
			if(strcmp(chock, "kostos") == 0)
			{
				printf("\ndose kosto: ");
				scanf("%d", &ko);
				for(i = 0 ; i < cnt ; i++)
				{
					if(a[i].prise > ko)
					{
						printf("\nmodel:%s prise:%0.2f year:%d \n", a[i].model, a[i].prise, a[i].year);
					}
				}
				getchar();
				goto jump;
			}
	
				
			//ola
			if(strcmp(chock, "*") == 0)
			{
				for(i = 0 ; i < cnt ; i++)
				{
					printf("\nmodel:%s prise:%0.2f year:%d \n", a[i].model, a[i].prise, a[i].year);
				}
				goto jump;	
			}
	
	
			//montela
			if(strcmp(chock, "models") == 0)
			{
				printf("\ndose onoma mondelou pros anazhthsh: ");			
				gets(check);
		
				for(i = 0 ; i < cnt ; i++)
				{
					temp = strcmp(check, a[i].model);
					if(temp == 0)
					{
						printf("\nmodel:%s prise:%0.2f year:%d \n", a[i].model, a[i].prise, a[i].year);	
						break;
					}
					else
					{
						printf("den iparxei ayto to modelo");
						break;
					}	
				}
				goto jump;	
			}
			
			else
			{
				printf("\nedoses la8os leksi ksana prospa8ise: ");
			}
		}
	}
	

	return 0;
}