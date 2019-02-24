/***********************************************************************************
*             Program for student Registration                                     *
*             using C and filestream                                               *
*             Developed by Shreya,Sanket,Anurag and Devansh                        *
***********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stud
{
	char first[15];
	char last[15];
	char ids[10];
	int  rollno;
	int  sta;
	char bookid[10];
	
}child;

int main()
{
	FILE *cptr,*nptr;
	int enter;
	 	nptr=fopen("D:\\Library\\chnum.txt","r");
	 	fscanf(nptr,"%d",&enter);
	 	fclose(nptr);
	 	fopen("D:\\Library\\chnum.txt","w");
	 	fprintf(nptr,"%d",enter+1);
	 	fclose(nptr);
	 	
	 	
		cptr=fopen("D:\\library\\stud.bin","ab");
		//Entering the details of a student
		printf("\nEnter your first name:  ");
		scanf("%s",&child.first[0]);
		
		printf("\n\nEnter your last name:  ");
		scanf("%s",&child.last[0]);
		
		
		printf("\n\nEnter Roll no:  ");
		scanf("%d",&child.rollno);
		
		//creating ID
			child.ids[0]='@';
			child.ids[1]=child.last[0];
			child.ids[2]=child.last[1];
			child.ids[3]=child.first[0];
			child.ids[4]=child.first[1];
			if(child.rollno<100)
			child.ids[5]='0';
			if(child.rollno>=100 && child.rollno<200)
			child.ids[5]='1';
			if(child.rollno>=200)
			child.ids[5]='2';
		
		printf("\n\nYour Id :  ");
		printf("%s",child.ids);
		printf("\tPLEASE REMEBER THIS ID");
		
		child.sta=0;
		printf("\n\nIssue status:\t");
		printf("No issues yet");		
		fwrite(&child,sizeof(struct stud),1,cptr);	
		fclose(cptr);
	
	getch();		
		
return 0;	
}
