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
	FILE *fp, *fl;
	
	s = (struct stud*) malloc(pio * sizeof(stud));
	
	if (s == NULL)
	{
		printf("error in array");
		return 0;
	}
	
	
	fp = fopen("students.txt", "r");
	
	if (fp == NULL)
	{
		printf("error in file 1\n");
		return 0;
	}
	
	
	fl = fopen("best.txt","w");
	
	if (fl == NULL)
	{
		printf("error in file 2");
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
	}
	
	printf("\nbest students\n");
	
	fputs("            best students\n\n", fl);

	for(j = 0 ; j < pio ; j++ )
	{	
		if(max == s[j].summ)
		{
			printf("\n%s    %0.1f\n",s[j].name, s[j].summ );
			fprintf(fl, "%s     %0.1f\n",s[j].name, s[j].summ );	
		}
	}


	free(s);
	fclose(fp);
	fclose(fl);
	
	system("best.txt");
	
	return 0;
}
