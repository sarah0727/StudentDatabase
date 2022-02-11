#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<conio.h>
#include<cstring>
#include<iomanip>

using namespace std;
int main()
{
	  FILE *fp,*ft;
	  char another,choice;
	  
	  struct student
	  {
	  	 char first_name[50],last_name[50];
	  	 char course[100];
	  	 int section;
		};
		
		struct student e;
		char xfirst_name[50],xlast_name[50];
		long int recsize;
		
		fp=fopen("users.txt","rb+");
		
		if(fp==NULL)
		{
			  fp=fopen("users.txt","wb+");
			  
			  if(fp == NULL )
			  {
			  	 puts("CANNOT OPEN FILE");
			  	 return 0;
				}
		}
		
		recsize= sizeof(e);
		
		while(1)
		{
			  system("cls");
			  
			  cout<<"\t\t******* 'STUDENT DATABASE MANAGEMENT SYSTEM' ******* ";
			  cout<<"\n\n                                            ";
			  cout<<"\n\n";
			  cout<<"\n \t\t\t 1. ADD    RECORDS";
			  cout<<"\n \t\t\t 2. LIST   RECORDS";
			  cout<<"\n \t\t\t 3. MODIFY RECORDS";
			  cout<<"\n \t\t\t 4. DELETE RECORDS";
			  cout<<"\n \t\t\t 5. EXIT   RECORDS";
			  cout<<"\n\n";
			  cout<<"\t\t\t SELECT YOUR CHOICE :-}";
			  fflush(stdin);
			  choice= getche();
			  switch(choice)
			  {
			  	 case '1':
			  	 	    fseek(fp,0,SEEK_END);
			  	 	    another ='Y';
			  	 	    while(another =='Y'|| another=='y')
			  	 	    {
			  	 	    	  system("cls");
			  	 	    	  cout<<"\n ENTER FIRST NAME   : ";
			  	 	    	  cin>>e.first_name;
			  	 	    	  cout<<"\nENTER THE LAST NAME : ";
			  	 	    	  cin>>e.last_name;
			  	 	    	  cout<<"\n ENTER THE COURSE   : ";
			  	 	    	  cin>>e.course;
			  	 	    	  cout<<"\n ENTER THE SECTION  :  ";
			  	 	    	  cin>>e.section;
			  	 	    	  fwrite(&e,recsize,1,fp);
			  	 	    	  cout<<"\n ADD ANOTHER RECORD  ";
			  	 	    	  fflush(stdin);
			  	 	    	  another =getchar();
			  	 	    }
			  	 	    break;
			  	 	
			  	 	case '2':
			  	 		  system("cls");
			  	 		  rewind(fp);
			  	 		  cout<<"---VIEW THE RECORDS IN THE DATABASE---";
			  	 		  cout<<endl;
			  	 		  while(fread(&e,recsize,1,fp)==1)
			  	 		  {
			  	 		  	 cout<<"\n";
			  	 		  	 cout<<"\n"<<e.first_name<<setw(10)<<e.last_name<<"\n";
			  	 		  	 cout<<"\n"<<e.course<<setw(8)<<e.section<<"\n";
								}
								cout<<"\n\n";
								system("pause");
								break;
						case '3':
							 system("cls");
							 another ='Y';
			  	 	  while(another =='Y'|| another=='y')
			  	 	  {
			  	 	  	 cout<<"\n ENTER THE LAST NAME OF STUDENT";
			  	 	  	 cin>>xlast_name;
			  	 	  	 
			  	 	  	rewind(fp);
			  	 	    while(fread(&e,recsize,1,fp)==1)
			  	 	    {
			  	 	    	 if(strcmp(e.last_name,xlast_name)==0)
			  	 	    	{
			  	 	    	 	cout<<"\n ENTER  NEW FIRST NAME   : ";
			  	 	    	  cin>>e.first_name;
			  	 	    	  cout<<"\nENTER THE NEW LAST NAME : ";
			  	 	    	  cin>>e.last_name;
			  	 	    	  cout<<"\n ENTER THE NEW COURSE   : ";
			  	 	    	  cin>>e.course;
			  	 	    	  cout<<"\n ENTER THE NEW SECTION  :  ";
			  	 	    	  cin>>e.section;
			  	 	    	  fseek(fp,- recsize, SEEK_CUR);
			  	 	    	  fwrite(&e,recsize,1,fp);
			  	 	    	  break;
									}
									else
									  cout<<"RECORD NOT FOUND";
								 }
								 cout<<"\n MODIFY ANOTHER RECORD(Y/N)";
								 fflush(stdin);
								 another=getchar();
							 }
							 break;
					  case '4':
					  	 system("cls");
					  	 another='Y';
					  	 while(another=='Y'||another=='y')
					  	 {
					  	 	 
					  	 	  cout<<"\n ENTER THE LAST NAME OF THE STUDENT TO DELETE: ";
					  	 	  cin>>xlast_name;
					  	 	  
					  	 	  
					  	 	  ft=fopen("temp.dat","wb");
					  	 	  
					  	 	  rewind(fp);
					  	 	  while(fread(&e,recsize,1,fp)==1)
					  	 	  
					  	 	       if(strcmp(e.last_name,xlast_name)!=0)
					  	 	       {
					  	 	       	 fwrite(&e,recsize,1,ft);
												}
									fclose(fp);
									fclose(ft);
									remove("users.txt");
									rename("temp.dat","users.txt");
									
									fp=fopen("users.txt","rb+");
									
									cout<<"\n DELETE ANOTHER RECORD :";
									fflush(stdin);
									another=getchar();
							 }
							 
							 break;
							 
							case '5':
								 fclose(fp);
								 cout<<"\n\n";
								 cout<<"\t\t    THANKYOU FOR USING THIS SOFTWARE  ";
								 cout<<"\n\n";
								 exit(0);
				}
		}
		
		
		system("pause");
		return 0;
}
