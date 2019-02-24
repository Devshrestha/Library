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
struct stud  //declaring a stucture for student
	{
	char first[15];
	char last[15];
	char ids[10];
	int  rollno;
	int  sta;
	char bookid;	
	}c;
int main()
	{
		FILE *sptr,*rtr,*cptr,*eptr; //Pointer of type FILE
		char opt,fd,n[30],chId[10],bkId[10];
		char cat[6][20]={"Fiction","Philosphy","Literature","Science","Arts","Biography"};
		int  i,gen,j,num,sta,enter,flag=0,flag2=0,flag3=0;
		//opening the file contain the number of files in the database
		rtr=fopen("D:\\library\\num.txt","r");
        fscanf(rtr,"%d",&num);
	    fclose(rtr);
	    
	    
	    //getiing the data of number of student registered
		eptr=fopen("D:\\library\\chnum.txt","r");
		fscanf(eptr,"%d",&enter);
		fclose(eptr);
		
		//Gettin the id of student
		cptr=fopen("D:\\library\\stud.bin","ab+");
		
		printf("Enter your ID");
		scanf("%s",&chId[0]);
		
		for(j=0;j<enter;j++)
		{
		fread(&c,sizeof(struct stud),1,cptr);
		
		if(strcmp(chId,c.ids)==0)
		{
		  flag2=1;
		  if(c.sta==0)
			{
			
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
			printf("\nDo you want to issue a book (y/n)  ");
			scanf("%c",&fd);
			if(fd=='y' || fd=='Y')
			{	//Issueing the book
				printf("\nEnter the id of book u want to issue");
				scanf("%s",&bkId[0]);
				for(i=0;i<num;i++)
					{
					    fread(&d,sizeof(struct book),1,sptr);
		
					    if(strcmp(bkId,d.idb)==0)
					        {
					              			
							}
		
					}
				
			}
			fclose(sptr);
			fclose(cptr);
			}
			else printf("Already have a issued book");
		}
		}	
		if(flag2 == 0) printf("\nNO such exist");
		
	getch();
	return 0;
	}
