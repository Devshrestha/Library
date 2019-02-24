  /*#######################################################
  #   A Program to input the data of library              #
  #                                                       #
  #  Developed by Sanket,Anurag,Shreya and Devansh        #
  #######################################################*/


#include<stdlib.h>
#include<stdio.h>
#include<string.h>


struct book   //declaring a structure
	{
	 char name[30];
	 int  page;
	 char author[30];
	 char cate[20];
	 char idb[30];
	 int  stat;
	}b;



int main()
{
  int i,j,num,pre,n,val,choice;
  char iid[6];
  char cat[6][20]={"Fiction","Philosphy","Literature","Science","Arts","Biography"};
  FILE *fptr,*item,*rtr;    //Pointer of type file
     fptr = fopen("D:\\Library\\book.bin","ab"); //opening the file in binary append write mode
     if(fptr == 0 )
     {
	 printf("ERROR! in opening the file");
	 exit(1);   //exiting the program in case the file is not opening
     }

	 printf("Enter the number of desired entiries \n");
	 scanf("%d",&num);
     printf("Enter the DATA\n");
                       //Begining of the loop for data input
    for(i=1;i<=num;i++)
     {
       printf("\nEnter the name of book\n");
       scanf("%s",&b.name[0]);

       printf("\nEnter the name of the author\n");
       scanf("%s",&b.author[0]);

       printf("\nEnter the number of pages\n");
       scanf("%d",&b.page);
		
		//generating ID
			iid[0]='#';
			iid[1]=b.author[0];
			iid[2]=b.author[1];
			iid[3]=b.author[2];
			iid[4]=b.name[0];
			iid[5]=b.name[1];
			iid[6]='2';
			if(b.page<300)
			iid[6]='1';
			if(b.page>700)
			iid[6]='3';
			
	   strcpy(b.idb,iid);	
       printf("\nThe ID associated\n");
       printf("%s",b.idb);

       printf("\n\nEnter the catogary\n");
       for(j=0;j<6;j++)
       {
       		printf("%d for %s\n",j+1,cat[j]);
	   }
	   scanf("%d",&choice);
	   strcpy(b.cate,cat[choice-1]);

       fwrite(&b,sizeof(struct book),1,fptr);
       
       b.stat=0;

     }

	fclose(fptr);

	rtr=fopen("D:\\library\\num.txt","r");
	fscanf(rtr,"%d",&pre);
	fclose(rtr);
	fopen("D:\\library\\num.txt","w");
	num=num+pre;
	fprintf(rtr,"%d",num);
	fclose(rtr);


  return 0;
}
