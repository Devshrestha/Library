/***********************************************************************************
*             Program for searching books in the data-base of library              *
*             using C and filestream                                               *
*             Developed by Shreya,Sanket,Anurag and Devansh                        *
***********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct book   //declaring a structure for book
	{
	 char name[30];
	 int  page;
	 char author[30];
	 char cat[20];
	 char idb[30];
	 int  stat;
	}d;

int main()
	{
		FILE *sptr,*rtr; //Pointer of type FILE
		char opt,fd,n[30],chId[10],bkId[10];
		char cat[6][20]={"Fiction","Philosphy","Literature","Science","Arts","Biography"};
		int  i,gen,j,num,sta,enter,flag=0;
		//opening the file contain the number of files in the database
		rtr=fopen("D:\\library\\num.txt","r");
        fscanf(rtr,"%d",&num);
	    fclose(rtr);
	    
				sptr=fopen("D:\\library\\book.bin","ab+");
			    //strating the search functions
			    printf("Enter the way of searching\n");
			    printf("a for Search by author\n");
			    printf("b for Search by book\n");
			    printf("g for Search by genre\n");
		
			    scanf("%c",&opt);
				switch(opt)
					{
						case 'a' :	printf("Enter the name of author\n");//Searching by the Author's name
						 			scanf("%s",&n[0]);
		
					              	for(i=0;i<num;i++)
					              	{
					              		fread(&d,sizeof(struct book),1,sptr);
		
					              		if(strcmp(n,d.author)==0)
					              		{
					              			printf("\nName of the book : %s",d.name);
			     							printf("\nName of the author : %s",d.author);
			     							printf("\nContainig pages : %d",d.page);
			     							printf("\nID : %s",d.idb);
			     							printf("\nCategory : %s",d.cat);
			     							printf("\n\n\n\n\n");
			     							flag=1;
										}
		
									}
									if(flag == 0)
										printf("Sorry no such Author");//when there is no author by that name
		
									break;
		
						case 'b':   printf("Enter the name of the book\n");//Searching by Book's name
						 			scanf("%s",&n[0]);
		
					              	for(i=0;i<num;i++)
					              	{
					              		fread(&d,sizeof(struct book),1,sptr);
		
					              		if(strcmp(n,d.name)==0)
					              		{
					              			printf("\nName of the book : %s",d.name);
			     							printf("\nName of the author : %s",d.author);
			     							printf("\nContainig pages : %d",d.page);
			     							printf("\nID : %s",d.idb);
			     							printf("\nCategory : %s",d.cat);
			     							printf("\n\n\n\n\n");
			     							flag=1;
										}
		
									 }
									if(flag == 0)
										printf("Sorry no such Book");//when there is no book by that name
		
									break;
		
						case 'g':   printf("Choose from the following\n");//Searching by genre
		
						 			for(i=0;i<6;i++)
						 			{
						 				printf("%d for %s\n",i+1,cat[i]);
									}
									scanf("%d",&gen);
									strcpy(n,cat[gen-1]);
					              	for(i=0;i<num;i++)
					              	{
					              		fread(&d,sizeof(struct book),1,sptr);
		
					              		if(strcmp(n,d.cat)==0)
					              		{
					              			printf("\nName of the book : %s",d.name);
			     							printf("\nName of the author : %s",d.author);
			     							printf("\nContainig pages : %d",d.page);
			     							printf("\nID : %s",d.idb);
			     							printf("\nCategory : %s",d.cat);
			     							printf("\n\n\n\n\n");
			     							flag=1;
										}
		
									}
									if(flag == 0)
										printf("Sorry no books under this genre");//When there is no book under the genre
		
									break;
						default :   printf("Not a valid choice");
									break;
			};
			
	fclose(sptr);
	getch();
	return 0;
	}
