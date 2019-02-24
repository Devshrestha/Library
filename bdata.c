
#include<stdlib.h>
#include<stdio.h>

struct book   //declaring a structure
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
  int item,i,j,num;
  char wish;
  FILE *fptr,*rtr;    //Pointers of type file

     rtr=fopen("D:\\library\\num.txt","r");
     fscanf(rtr,"%d",&num);
	 fclose(rtr);

	 fptr = fopen("D:\\library\\book.bin","ab+"); //opening the file in binary read and append mode
     if(fptr == 0 )
     {
	 printf("ERROR! in opening the file");
	 exit(1);   //exiting the program in case the file is not opening
     }
     for(j=1;j<=num;j++)
     {

     fread(&d,sizeof(struct book),1,fptr);
     printf("\nName of the book : %s",d.name);
     printf("\nName of the author : %s",d.author);
     printf("\nContainig pages : %d",d.page);
     printf("\nID : %s",d.idb);
     printf("\nCategory : %s\n",d.cat);
     if(d.stat==0)
     {
     	printf("Issue status:\t");
     	printf("Unissued");
	 }
	 if(d.stat==1)
	 {
	 	printf("Issue status:\t");
	 	printf("Issued");
	 }
     printf("\n\n\n\n\n");
     }
    fclose(fptr);

    getch();

  return 0;
}
