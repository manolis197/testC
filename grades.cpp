#include<stdio.h>
#include<stdlib.h>
#define pio 10

struct stud
{
	char name[20];
	float gradea;
	float gradeb;
	float gradec;
	float summ;	
};

int main(void)
{
	struct stud *s;
	int i, j;
	float max = 0;
	
	s = (struct stud*) malloc(pio * sizeof(stud));
	
	FILE *fp;
	fp = fopen("students.txt", "r");
	
	if (fp == NULL)
	{
		printf("error\n");
		return 0;
	}
	
	while(!feof(fp))
	{
		for(i = 0 ; i < pio ; i++ )
		{
			fscanf(fp, "%s %f %f %f", s[i].name, &s[i].gradea, &s[i].gradeb, &s[i].gradec );
			s[i].summ = (s[i].gradea + s[i].gradeb + s[i].gradec)/3;
			
			printf( "%s             %0.1f      %0.1f      %0.1f     %0.1f\n", s[i].name, s[i].gradea, s[i].gradeb, s[i].gradec, s[i].summ);

			
			if(s[i].summ > max)
			{
				max = s[i].summ; 
			}
		}
		
		printf("\ndest students\n");
		
		
		for(j = 0 ; j < pio ; j++ )
		{
			fscanf(fp, "%s %f %f %f", s[j].name, &s[j].gradea, &s[j].gradeb, &s[j].gradec );
			s[j].summ = (s[j].gradea + s[j].gradeb + s[j].gradec)/3;
			
			
			if(max == s[j].summ)
			{
				printf("\n%s    %0.1f\n",s[j].name, s[j].summ );	
			}
		}				
	}
	
	free(s);
	fclose(fp);
	
	return 0;
}