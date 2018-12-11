#include <string.h>
#include "dispo.h"
#include <stdio.h>
#include <stdlib.h>
int verif1(char j[], char m[], char y[])
{
if(((strcmp(m,"04")==0)||(strcmp(m,"06")==0)||(strcmp(m,"11")==0)||(strcmp(m,"09")==0))&&(strcmp(j,"31")==0))
	return 0;

else if((strcmp(m,"02")==0)&&(strcmp(y,"2020")==0)&&(strcmp(j,"30")==0))
	return 0;
else if((strcmp(m,"02")==0)&&(strcmp(y,"2020")==0)&&(strcmp(j,"31")==0))
	return 0;

else if((strcmp(m,"02")==0)&&((strcmp(y,"2018")==0)||(strcmp(y,"2019")==0))&&(strcmp(j,"29")==0))
	return 0;
else if((strcmp(m,"02")==0)&&((strcmp(y,"2018")==0)||(strcmp(y,"2019")==0))&&(strcmp(j,"30")==0))
	return 0;
else if((strcmp(m,"02")==0)&&((strcmp(y,"2018")==0)||(strcmp(y,"2019")==0))&&(strcmp(j,"31")==0))
	return 0;
else
	return 1;
}


int verif2(char j[], char m[], char y[])
{

FILE* f= fopen("src/disponibilite.txt","r");

char jour[3] ;
char mois[3] ;
char year[6] ;

int nbplaces;
int x=1;

if (f != NULL)
{

		while( (fscanf(f,"%s %s %s %d\n",jour,mois,year,&nbplaces)!=EOF ))
	{			if( (strcmp(jour,j)==0)&&(strcmp(mois,m)==0)&&(strcmp(year,y)==0) )
		{	
		x=0;
		}
	}
}

fclose(f);

return x;
}


void chaine (char ch[], char j[], char m[], char y[], char p[], int nbp)
{
		strcpy(ch,j);
		strcat(ch," ");
		strcat(ch,m);
		strcat(ch," ");
		strcat(ch,y);
		strcat(ch," ");
		sprintf(p,"%d",nbp);
		strcat(ch," ");
		strcat(ch,p);

return 0;
}

void remplacer (char j1[],char j[], char m1[], char m[], char y1[], char y[],int nb1, int nb)
{
			  if (strcmp(j,"")!=0)
			   {strcpy(j1,j);}

			  if (strcmp(m,"")!=0)
			   {strcpy(m1,m);}

			  if (strcmp(y,"")!=0)
			   {strcpy(y1,y);}

			  if (nb!=1)
			   {nb1=nb;}

return 0;
}


