#include<stdio.h>
int i,j;
int main_exit;
void menu();
struct date{
    int month,day,year;
    };
struct detail{
    char name[60];
    int acno,age;
    char address[60];
    char citizenship[15];
    double phone;
    char actype[10];
    float amt, loan;
    struct date dob;
    struct date deposit;
    struct date withdraw;
    }add,upd,check,removes,transaction;
float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100;
    return SI;
}
void new_acc()
{
    int choice;
    FILE *ptr;
    ptr=fopen("data.txt","a+");
    system("cls");
    account_no:
    printf("\nEnter the account number:");
    scanf("%d",&check.acno);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %f %d/%d/%d\n",&add.acno,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.actype,&add.amt,&add.loan,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acno==add.acno)
            {printf("Account no %d is not available right now.\nPlease try another one",check.acno);
                goto account_no;
            }
    }
    add.acno=check.acno;
    printf("\nName:");
    scanf("%s",add.name);
    printf("\nDate of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nAge:");
    scanf("%d",&add.age);
    printf("\nAddress:");
    scanf("%s",add.address);
    printf("\nCitizenship number:");
    scanf("%s",add.citizenship);
    printf("\nPhone number: ");
    scanf("%lf",&add.phone);
    printf("\nThe amount to deposit:Rs. ");
    scanf("%f",&add.amt);
    printf("\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nType of account:\n\tsaving\n\tcurrent\n\tfixed\n\n\tEnter your choice:");
    scanf("%s",add.actype);
        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %f %d/%d/%d\n",add.acno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.actype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    fclose(ptr);
    printf("\nCongratulation, Account created successfully!!!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
     
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
void view_list()
{
    FILE *view;
    view=fopen("data.txt","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");
    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %f %d/%d/%d",&add.acno,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.actype,&add.amt,&add.loan,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
		   printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acno,add.name,add.address,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {    
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
         
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("data.txt","r");
    newrec=fopen("temp.txt","w");
	system("cls");
    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acno);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %f %d/%d/%d",&add.acno,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.actype,&add.amt,&add.loan,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acno==upd.acno)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
             
            if(choice==1)
                {printf("Enter the new address:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %f %d/%d/%d\n",add.acno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.actype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                 
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                printf("Enter the new phone number:");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %f%d/%d/%d\n",add.acno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.actype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                printf("Changes saved!");
                }
        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %f %d/%d/%d\n",add.acno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.actype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("data.txt");
    rename("temp.txt","data.txt");
if(test!=1)
        {    
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);               
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);        
        if (main_exit==1)
            menu();
        else
            close();
        }
}
void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("data.txt","r");
    newrec=fopen("temp.txt","w");
    system("cls");
    printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acno);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %f %d/%d/%d",&add.acno,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.actype,&add.amt,&add.loan,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
            if(add.acno==transaction.acno)
            {   test=1;
                if(strcmp(add.actype,"fixed")==0)
                {
                    printf("\a\nYou can not withdraw and deposit in fixed account!!!!!");                    
                    menu();
                }
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:Rs. ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %f %d/%d/%d\n",add.acno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.actype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited successfully!!\nYour new balance is Rs. %.2f.",add.amt);
                }
                else if (choice==2)
                {
                    printf("Enter the amount you want to withdraw:Rs. ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %f %d/%d/%d\n",add.acno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.actype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWithdrawn successfully!! \nYour new balance is Rs. %.2f.",add.amt);
                }
            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %f %d/%d/%d\n",add.acno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.actype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("data.txt");
   rename("temp.txt","data.txt");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);      
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }
   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
         
        if (main_exit==1)
            menu();
        else
            close();
   }
}
void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("data.txt","r");
    newrec=fopen("temp.txt","w");
    system("cls");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&removes.acno);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %f %d/%d/%d",&add.acno,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.actype,&add.amt,&add.loan,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acno!=removes.acno)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %f %d/%d/%d\n",add.acno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.actype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("data.txt");
   rename("temp.txt","data.txt");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);       
        if (main_exit==1)
            main();
        else
            close();
        }
}
void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("data.txt","r");
    system("cls");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.acno);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %f %d/%d/%d",&add.acno,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.actype,&add.amt,&add.loan,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acno==check.acno)
            {    
                test=1;
                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:Rs. %.2f \nDate Of Deposit:%d/%d/%d\nLoan : %.2f\n\n",add.acno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.actype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year,add.loan);
                if(strcmpi(add.actype,"fixed")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs. %.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.actype,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs. %.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);
                    }
                else if(strcmpi(add.actype,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs. %.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);
                    }
                 else if(strcmpi(add.actype,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs. %.2f as interest on %d of every month",intrst,add.deposit.day);
                     }
                 else if(strcmpi(add.actype,"current")==0)
                    {
                        printf("\n\nYou will get no interest\a\a");
                     }
            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %f %d/%d/%d",&add.acno,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.actype,&add.amt,&add.loan,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {    
                test=1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:Rs. %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.actype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.actype,"fixed")==0)
                    {
                        time=1.0;
                        rate=15;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs. %.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                 else if(strcmpi(add.actype,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs. %.2f as interest on %d %d of every year",intrst,add.deposit.day,add.deposit.month);
                     }
                 else if(strcmpi(add.actype,"current")==0)
                    {
                        printf("\n\nYou will get no interest\a\a");
                     }
            }
        }
    }
    fclose(ptr);
     if(test!=1)
        {    
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
               
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {
                         
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {    
            menu();
        }
        else
           { 
            close();
            }
}
void loans(void)
{   int loan12, test=0;
    FILE *old,*newrec;
    old=fopen("data.txt","r");
    newrec=fopen("temp.txt","w");
    system("cls");
	printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acno);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %f %d/%d/%d",&add.acno,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.actype,&add.amt,&add.loan,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
    if(add.acno==transaction.acno)
    {   test=1;
		printf("1. take loan\n2. pay loan\n 3.check loan amount");
        scanf("%d",&loan12);
        if (loan12==1)
        {
        	printf("Enter amount of loan you want: Rs.");
        	scanf("%f",&transaction.loan);
        	add.loan+=transaction.loan;
        	fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %f %d/%d/%d\n",add.acno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.actype,add.amt,add.loan,add.deposit.month,add.deposit.day,add.deposit.year);
            printf("You have loan of amount Rs. %.2f",add.loan);
            break;
		}
		else if (loan12==2)
        {
        	printf("Enter amount of loan you wanna pay: Rs.");
        	scanf("%f",&transaction.loan);
        	add.loan-=transaction.loan;
        	fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %f %d/%d/%d\n",add.acno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.actype,add.amt,add.loan,add.deposit.month,add.deposit.day,add.deposit.year);
            printf("You have loan of amount %.2f",add.loan);
            break;
		}
		else if (loan12==3)
		{
			fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %f %d/%d/%d\n",add.acno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.actype,add.amt,add.loan,add.deposit.month,add.deposit.day,add.deposit.year);
            printf("You have loan of amount Rs. %.2f",add.loan);
            break;
        }
		else
		{
			fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %f %d/%d/%d\n",add.acno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.actype,add.amt,add.loan,add.deposit.month,add.deposit.day,add.deposit.year);
            printf("Invallid Option Given.");
            break;
        }
        
	}
	else
		fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %f %d/%d/%d\n",add.acno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.actype,add.amt,add.loan,add.deposit.month,add.deposit.day,add.deposit.year);
   }
   if(test==0)
			printf("The account number does not exist.");
   fclose(old);
   fclose(newrec);
   remove("data.txt");
   rename("temp.txt","data.txt");
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
         
        if (main_exit==1)
            menu();
        else
            close();
}
void menu(void)
{   int choice;
	system("cls");
    printf("\n\n*******************WELCOME TO BANK MANAGEMENT SYSTEM*******************");
    printf("\n**************************WELCOME TO THE MAIN MENU**************************");
    printf("\n\n\t\t\n\t\t1.See AC informations\n\t\t2.Withdraw/Deposit\n\t\t3.Edit AC Informations\n\t\t4.Delete account\n\t\t5.View customer's list\n\t\t6.Loan\n\t\t7.Create another account\n\t\t8.Exit\n\n\n\n\n\t\t Enter your choice: (1 or 2 or .... or 8))");
    scanf("%d",&choice);     
    switch(choice)
    {
        case 1:see();
        break;
        case 2:transact();
        break;
        case 3:edit();
        break;
        case 4:erase();
        break;
        case 5:view_list();
        break;
        case 6:loans();
        break;
		case 7: new_acc();
        break;
        case 8: close();
        break;
        default:{
     	printf("Invallid option given. \nTry again with vallid option.");
    	menu();
		break;  }
    }
}
int main()
{
    char yesno;
	printf("\nDo you have any account in this bank? \nPress y to go to main menu OR n to create a new one\n(y/n)\n");
    yesno=getche();
    if(yesno=='y'){
	menu();
	goto exit;	}	
    else if(yesno=='n');{
    printf("\nYou have not any account in the bank.\n Lets create a new one:");
	new_acc();
	goto exit;  }
	exit:
		system("cls");
		printf("\n\t\t***|||***THANKS FOR VISITING.***|||***\n\t\t***************See you again*******************");
	return 0;
}
