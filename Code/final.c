#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

struct usersdata
{
    char name[100];
    char password[100];
};
typedef struct usersdata list;
list cu[300];
list ad[100];
int global_count = 0;
int gb=0;
int test=0;

void welcome();
void loadfromcustomerfile();
void loadfromadmin();
void searchcustomer(list [],char []);
void searchadmin(list [],char []);
void new_acc();
void edit();
void erase();
void transact();
void bill_payment();
void balance();
void loan_application();
void EMI_calculator();
void FD_calculator();
void insurance_appl();
void insurance_calc();
void Cheque_book();
void C_appl();
void D_appl();
void C_deact();
void D_deact();
void pay_taxes();
void balance_enquiry();
void query();
void request();
void contact();
void report();
void feedback_rating();
void book();
void ATM_banking();
void currency_conv();
void near_bank();


int main()
{
    char customername[50],adminname[50];
    welcome();
    loadfromcustomerfile();
    loadfromadmin();
    int c;
    printf("Enter appropriate choice\n");
    printf("Enter 1 if you are an CUSTOMER\n");
    printf("Enter 2 if you are an ADMINISTRATOR\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1 :printf("enter your name = ");
                scanf("%s",customername);
                searchcustomer(cu,customername);
                break;
        case 2 :printf("enter your = ");
                scanf("%s",adminname);
                searchadmin(ad,adminname);
                break;
        default:printf("invalid choice!Please start from first");
                exit(0);
                break;
    }
    return 0;
}

void welcome()
{
    int i;
    for(i=0;i<20;i++)
    {
        printf("*");
    }
    printf("\nWELCOME TO XYZ INTERNET BANKING\n");
    printf("\nHOME PAGE\n");

    for(i=0;i<20;i++)
    {
        printf("*");
    }
    printf("\n");
}

void loadfromcustomerfile()
{
    FILE *fp;
    fp = fopen("customerlogin.txt", "r");
    if(fp==NULL)
    {
        printf("FILE NOT FOUND\n");
        return;
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s\t%s",cu[global_count].name,cu[global_count].password);
        //printf("%s\t%s\n",cu[global_count].name,cu[global_count].password);
        global_count++;
    }
    fclose(fp);
}

void loadfromadmin()
{
    FILE *fp;
    fp = fopen("adminlogin.txt", "r");
    if(fp==NULL)
    {
        printf("FILE NOT FOUND\n");
        return;
    }
    //printf("\nprinting admin file\n");
    while(!feof(fp))
    {
        fscanf(fp,"%s\t%s",ad[gb].name,ad[gb].password);
        //printf("%s\t%s\n",ad[gb].name,ad[gb].password);
        gb++;
    }
    fclose(fp);
}

void searchcustomer(list m[300],char customername[100])
{
    char passvb[50];
    int count=1,k=0;
    int checkmade=0;
    printf("enter your password = ");
    scanf("%s",passvb);

    if(customername[0]== '\0' || passvb[0]=='\0')
    {
        count=0;
        printf("input your name and password");
        exit(0);
    }
   else
   {
        while(k<global_count)
        {
            char *pch = strstr(m[k].name,customername);
            char *checkpass=strstr(m[k].password,passvb);
            if(pch && checkpass)
          {
               checkmade=1;
               break;
          }
           else
          {
              k++;
          }
        }
   }
   if(checkmade==1)
   {
        test=1;
        printf("VALID CUSTOMER\n");
   }
   else
   {
       printf("OOPS!We couldn't find your name in the directory");
   }

   if(test==1)
   {
       int choice;
       printf("Please enter your choice\n");
       printf("1.Create new account\n2.Edit your details\n3.Delete your account\n4.Transactions\n");
       printf("5.Balance enquiry\n6.Bill payment\n7.Loan application\n8.EMI calculator\n");
       printf("9.FD calculator\n10.Insurance application\n11.Insurance calculator\n12.Cheque book issue application\n");
       printf("13.Credit card application and activation\n14.Debit card application and activation\n15.Credit card deactivation\n");
       printf("16.Debit card deactivation\n17.Pay taxes\n18.Query\n19.Request\n20.Contact us\n21.Report a fraud\n22.Feedback and rating\n");
       printf("23.Book an appointment\n24.Currency conversion calculator\n25.ATM banking\n26.Search nearby ATM's\n27.exit\n");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:new_acc();
                  break;
           case 2:edit();
                  break;
           case 3:erase();
                  break;
           case 4:transact();
                  break;
           case 5:balance_enquiry();
                  break;
           case 6:bill_payment();
                  break;
           case 7:loan_application();
                  break;
           case 8:EMI_calculator();
                  break;
           case 9:FD_calculator();
                  break;
           case 10:insurance_appl();
                   break;
           case 11:insurance_calc();
                   break;
           case 12:Cheque_book();
                   break;
           case 13:C_appl();
                   break;
           case 14:D_appl();
                   break;
           case 15:C_deact();
                   break;
           case 16:D_appl();
                   break;
           case 17:pay_taxes();
                   break;
           case 18:query();
                   break;
           case 19:request();
                   break;
           case 20:contact();
                   break;
           case 21:report();
                   break;
           case 22:feedback_rating();
                   break;
           case 23:book();
                   break;
           case 24:currency_conv();
                   break;
           case 25:ATM_banking();
                   break;
           case 26:near_bank();
                   break;
           case 27:exit(0);
       }
   }

}

struct atm
{
    int a_no;
    int pass;
    float am;
};

struct atm d[100];
struct atm ba[100];
struct atm t[100];
struct atm de[100];

struct add
{
    int acc_no;
    char name[100];
    int birthday,birthmonth,birthyear;
    int age;
    double phone_no;
    char address[100];
    char acc_type[100];
    float amt;
};

struct add a[100];
struct add upd[100];
struct add rem[100];
struct add tran[100];
struct add bal[100];
struct add bill[100];
struct add loan[100];
struct add ins[100];
int g_count=0;

void load_from_file()
{
    FILE *fp;
    fp=fopen("userdata.txt","r");
    if(fp==NULL)
    {
        printf("FILE NOT FOUND\n");
        return;
    }
    while(!feof(fp))
    {
        fscanf(fp,"%d\t%s\t%d\t%d\t%d\t%d\t%lf\t%s\t%s\t%f\n",&a[g_count].acc_no,a[g_count].name,&a[g_count].birthday,&a[g_count].birthmonth,&a[g_count].birthyear,&a[g_count].age,&a[g_count].phone_no,a[g_count].address,a[g_count].acc_type,&a[g_count].amt);
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%lf\t%s\t%s\t%f\n",a[g_count].acc_no,a[g_count].name,a[g_count].birthday,a[g_count].birthmonth,a[g_count].birthyear,a[g_count].age,a[g_count].phone_no,a[g_count].address,a[g_count].acc_type,a[g_count].amt);
        g_count++;
    }
    fclose(fp);
}

void new_acc()
{
    int i,j=0;
    FILE *ptr;
    ptr=fopen("userdata.txt","a+");
    //account_number:
    int account_no;
    printf("enter account number you wish to keep for your account\n");
    scanf("%d",&account_no);
    //printf("%d\n",account_no);
    for(i=0;i<global_count;i++)
    {
        //printf("%d\n",search_list[i].acc_no);
        if(account_no==a[i].acc_no)
        {
            printf("account number already in use\n");
            return;
            //goto account_number;
        }
    }

    printf("please re-enter your account number\n");
    scanf("%d",&a[j].acc_no);
    fflush(stdin);
    printf("enter your name\n");
    gets(a[j].name);
    printf("enter your birthday\n");
    scanf("%d",&a[j].birthday);
    printf("enter your birthmonth\n");
    scanf("%d",&a[j].birthmonth);
    printf("enter yout birthyear\n ");
    scanf("%d",&a[j].birthyear);
    printf("enter your age\n");
    scanf("%d",&a[j].age);
    printf("enter your phone number\n");
    scanf("%lf",&a[j].phone_no);
    fflush(stdin);
    //please enter the address in one word or please use underscore in case of multiple words,else the whole program will get disrupted
    printf("Enter your address\n");
    printf("Please enter the address in one word or please use underscore in case of multiple words in address\n");
    gets(a[j].address);
    printf("enter type of account:current or savings or FD(1year/2year/other)\n");
    scanf("%s",a[j].acc_type);
    printf("enter amount you want to deposit\n");
    printf("Your account should always have minimun 500 rupees\n");
    scanf("%f",&a[j].amt);

    fprintf(ptr,"%d\t%s\t%d\t%d\t%d\t%d\t%lf\t%s\t%s\t%f\n",a[j].acc_no,a[j].name,a[j].birthday,a[j].birthmonth,a[j].birthyear,a[j].age,a[j].phone_no,a[j].address,a[j].acc_type,a[j].amt);

    fclose(ptr);

    printf("account added successfully\n");
}

void view_list()
{
    FILE *view;
    //int i;
    view=fopen("userdata.txt","r");
    int test=0;
    printf("\nACC.NO\tNAME\tADDRESS\tPHONE_NO\n");

    while(fscanf(view,"%d\t%s\t%d\t%d\t%d\t%d\t%lf\t%s\t%s\t%f\n",&a[global_count].acc_no,a[global_count].name,&a[global_count].birthday,&a[global_count].birthmonth,&a[global_count].birthyear,&a[global_count].age,&a[global_count].phone_no,a[global_count].address,a[global_count].acc_type,&a[global_count].amt)!=EOF)
    //for(i=0;i<global_count;i++)
    {
         test++;
         printf("\n%d\t%s\t%s\t%lf\n",a[global_count].acc_no,a[global_count].name,a[global_count].address,a[global_count].phone_no);

    }
    fclose(view);
    if (test==0)
        {
            printf("\nNO RECORDS!!\n");
        }

}

void edit()
{
    int j=0;
    int choice,test=0;
    FILE *newdata;
    FILE *oldrec,*newrec;
    oldrec=fopen("userdata.txt","r");
    newrec=fopen("newdata.txt","a+");

    printf("enter account of customer whose information information you want to change\n");
    scanf("%d",&upd[j].acc_no);

    while(fscanf(oldrec,"%d\t%s\t%d\t%d\t%d\t%d\t%lf\t%s\t%s\t%f\n",&a[j].acc_no,a[j].name,&a[j].birthday,&a[j].birthmonth,&a[j].birthyear,&a[j].age,&a[j].phone_no,a[j].address,a[j].acc_type,&a[j].amt)!=EOF)
    {
        if(a[j].acc_no==upd[j].acc_no)
        {
            test=1;
            printf("which information do you want to change??\n");
            printf("1.ADDRESS\n 2.PHONE NUMBER\n");
            printf("enter your choice\n");
            scanf("%d",&choice);
            fflush(stdin);
            if(choice==1)
            {
                printf("enter new address\n");
                gets(upd[j].address);
                fprintf(newrec,"%d\t%s\t%d\t%d\t%d\t%d\t%lf\t%s\t%s\t%f\n",a[j].acc_no,a[j].name,a[j].birthday,a[j].birthmonth,a[j].birthyear,a[j].age,a[j].phone_no,upd[j].address,a[j].acc_type,a[j].amt);
                printf("changes saved\n");
            }
            else if(choice==2)
            {
                printf("enter new phone number\n");
                scanf("%lf",&upd[j].phone_no);
                fprintf(newrec,"%d\t%s\t%d\t%d\t%d\t%d\t%lf\t%s\t%s\t%f\n",a[j].acc_no,a[j].name,a[j].birthday,a[j].birthmonth,a[j].birthyear,a[j].age,upd[j].phone_no,a[j].address,a[j].acc_type,a[j].amt);
                printf("changes saved\n");
            }
            else
            {
                fprintf(oldrec,"%d\t%s\t%d\t%d\t%d\t%d\t%lf\t%s\t%s\t%f\n",a[j].acc_no,a[j].name,a[j].birthday,a[j].birthmonth,a[j].birthyear,a[j].age,a[j].phone_no,a[j].address,a[j].acc_type,a[j].amt);
                printf("no changes\n");
            }
        }
    }
    fclose(oldrec);
    fclose(newrec);
    remove("userdata.txt");
    rename("newdata.txt","userdata.txt");

    if(test==0)
    {
        printf("record not found\n");

    }
}

void erase()
{
    int j=0;
    FILE *oldrec,*newrec;
    int test=0;
    oldrec=fopen("userdata.txt","r");
    newrec=fopen("newdata.txt","a+");
    printf("enter the account number of the customer you want to delete\n");
    scanf("%d",&rem[j].acc_no);
    while(fscanf(oldrec,"%d\t%s\t%d\t%d\t%d\t%d\t%lf\t%s\t%s\t%f\n",&a[j].acc_no,a[j].name,&a[j].birthday,&a[j].birthmonth,&a[j].birthyear,&a[j].age,&a[j].phone_no,a[j].address,a[j].acc_type,&a[j].amt)!=EOF)
    {
        if(a[j].acc_no!=rem[j].acc_no)
        {
            fprintf(newrec,"%d\t%s\t%d\t%d\t%d\t%d\t%lf\t%s\t%s\t%f\n",a[j].acc_no,a[j].name,a[j].birthday,a[j].birthmonth,a[j].birthyear,a[j].age,a[j].phone_no,a[j].address,a[j].acc_type,a[j].amt);
        }
        else
        {
            test++;
            printf("record deleted succesfully\n");
        }
    }
    fclose(oldrec);
    fclose(newrec);
    remove("userdata.txt");
    rename("newdata.txt","user.txt");

    if(test==0)
    {
        printf("record not found\n");
    }

}

void transact()
{
    int choice,test=0,j=0;
    FILE *oldrec,*newrec;
    FILE *newdata;
    oldrec=fopen("userdata.txt","r");
    newrec=fopen("newdata.txt","a+");

    printf("enter the account number of the customer\n");
    scanf("%d",&tran[j].acc_no);

    while(fscanf(oldrec,"%d\t%s\t%d\t%d\t%d\t%d\t%lf\t%s\t%s\t%f\n",&a[j].acc_no,a[j].name,&a[j].birthday,&a[j].birthmonth,&a[j].birthyear,&a[j].age,&a[j].phone_no,a[j].address,a[j].acc_type,&a[j].amt)!=EOF)
    {
        if(a[j].acc_no==tran[j].acc_no)
        {
            test++;
            printf("do you want to \n 1.deposit\t2.withdraw\n");
            printf("enter your choice\n");
            scanf("%d",&choice);

            if(choice==1)
            {
                printf("enter amount you want to deposit\n");
                scanf("%f",&tran[j].amt);
                a[j].amt+=tran[j].amt;

                fprintf(newrec,"%d\t%s\t%d\t%d\t%d\t%d\t%lf\t%s\t%s\t%f\n",a[j].acc_no,a[j].name,a[j].birthday,a[j].birthmonth,a[j].birthyear,a[j].age,a[j].phone_no,a[j].address,a[j].acc_type,a[j].amt);
                printf("\nmoney deposited successfully\n");
            }
            else if(choice==2)
            {
                printf("enter amount you want to withdraw\n");
                scanf("%f",&tran[j].amt);
                a[j].amt-=tran[j].amt;

                fprintf(newrec,"%d\t%s\t%d\t%d\t%d\t%d\t%lf\t%s\t%s\t%f\n",a[j].acc_no,a[j].name,a[j].birthday,a[j].birthmonth,a[j].birthyear,a[j].age,a[j].phone_no,a[j].address,a[j].acc_type,a[j].amt);
                printf("\nmoney withdrawn successfully\n");
            }
            else
            {
                fprintf(newrec,"%d\t%s\t%d\t%d\t%d\t%d\t%lf\t%s\t%s\t%f\n",a[j].acc_no,a[j].name,a[j].birthday,a[j].birthmonth,a[j].birthyear,a[j].age,a[j].phone_no,a[j].address,a[j].acc_type,a[j].amt);
            }
        }
    }

    fclose(oldrec);
    fclose(newrec);
    remove("userdata.txt");
    rename("newdata.txt","userdata.txt");

    if(test==0)
    {
        printf("Record not found\n");
    }

}

void balance_enquiry()
{
    int test=0,j=0;
    FILE *fp;
    fp=fopen("userdata.txt","r");
    printf("Enter your account number\n");
    scanf("%d",&bal[j].acc_no);
    while(fscanf(fp,"%d\t%s\t%d\t%d\t%d\t%d\t%lf\t%s\t%s\t%f\n",&a[j].acc_no,a[j].name,&a[j].birthday,&a[j].birthmonth,&a[j].birthyear,&a[j].age,&a[j].phone_no,a[j].address,a[j].acc_type,&a[j].amt)!=EOF)
    {
        if(a[j].acc_no==bal[j].acc_no)
            {
                test++;
                printf("%f\n",a[j].amt);
            }
    }
    if(test==0)
    {
        printf("Given account number not found in records\n");
        printf("Enter appropriate account number\n");
    }
}


void bill_payment()
{
    int test=0;
   int choice;
   int j=0;
   FILE *fp,*ptr;
   fp=fopen("userdata.txt","r");
   ptr=fopen("newdata.txt","a+");
   printf("enter your account number\n");
   scanf("%d",&bill[j].acc_no);
   while(fscanf(fp,"%d\t%s\t%d\t%d\t%d\t%d\t%lf\t%s\t%s\t%f\n",&a[j].acc_no,a[j].name,&a[j].birthday,&a[j].birthmonth,&a[j].birthyear,&a[j].age,&a[j].phone_no,a[j].address,a[j].acc_type,&a[j].amt)!=EOF)
   {
       if(a[j].acc_no==bill[j].acc_no)
       {
           test++;
           printf("select bill type\n");
           printf("1.Electricity_bill\n 2.Water_bill\n");
           scanf("%d",&choice);

           if(choice==1)
           {
               //char ch,y,n;
               float amount,unit;
               printf("rates_apply_per_unit\n");
               printf("1 to 50 units - 1.50 rupees per unit\n");
               printf("51 to 150 units - 2.00 rupees per unit\n");
               printf("151 to 250 units - 3.00 per rupees unit\n");
               printf("enter number of units\n");
               scanf("%f",&unit);

               if((unit>1) && (unit<=50))
               {
                   amount=unit*1.50;
               }
               else if((unit>50) && (unit<=150))
               {
                   amount=((50*1.5) + (unit-50)*2.00);
               }
               else if((unit>150) && (unit<=250))
               {
                   amount= ((50*1.5) + (100*2.00) + ((unit-150)*3.00));
               }
               else if(unit>250)
               {
                   amount=((50*1.5) + (100*2.00) + (100*3.00) + ((unit-250)*4.00));
               }
               else
               {
                   printf("No usage\n");
               }

              printf("Electricity bill =%f\n",amount);
              int c;
              printf("Do you want to pay the bill now?Confirm your choice\n");
              printf("1.To pay\n2.To pay later\n");
              scanf("%d",&c);
              if(c==1)
              {
                   a[j].amt=a[j].amt-amount;
                   fprintf(ptr,"%d\t%s\t%d\t%d\t%d\t%d\t%lf\t%s\t%s\t%f\n",a[j].acc_no,a[j].name,a[j].birthday,a[j].birthmonth,a[j].birthyear,a[j].age,a[j].phone_no,a[j].address,a[j].acc_type,a[j].amt);
                   printf("Electricity bill payed\n");
              }
              else if(c==2)
              {
                  return;
              }
              else
              {
                  printf("Enter appropriate choice\n");
              }

           }

           else if(choice==2)
           {
              float amount,total_amt,vol;
              int min_pay=5;
              printf("Enter volume of water used\n");
              scanf("%f",&vol);
              printf("rates apply per volume units\n");
              printf("1 to 15 vol - 0.42 rupees per vol\n");
              printf("16 to 40 vol - 0.65 rupees per vol\n");
              printf("above 40 vol - 1.05 rupees per vol\n");
              if((vol>=1) && (vol<=15))
              {
                  amount= vol*0.42;
              }
              else if(vol>15 && vol<=40)
              {
                  amount=((15*0.42) + ((vol-15)*0.65));
              }
              else if(vol>40)
              {
                  amount=((15*0.4) + (25*0.65) + ((vol-40)*1.05));
              }
              else
              {
                  printf("no usage\n");
              }
              total_amt=amount+min_pay;
              printf("Water bill = %f\n",total_amt);
              int y;
              printf("Do you want to pay the bill now?confirm once\n");
              scanf("%d",&y);
              if(y==1)
              {
                  a[j].amt=a[j].amt-total_amt;
                  fprintf(ptr,"%d\t%s\t%d\t%d\t%d\t%d\t%lf\t%s\t%s\t%f\n",a[j].acc_no,a[j].name,a[j].birthday,a[j].birthmonth,a[j].birthyear,a[j].age,a[j].phone_no,a[j].address,a[j].acc_type,a[j].amt);
              }
              else if(y==2)
              {
                  return;
              }
              else
              {
                  printf("Enter appropriate choice\n");
              }
           }
       }
   }

       fclose(fp);
       fclose(ptr);
       remove("userdata.txt");
       rename("newdata.txt","userdata.txt");

       if(test==0)
       {
           printf("Record not found\n");
           printf("Enter appropriate account number\n");
       }

}

void loan_application()
{
    int test=0;
    int choice,j=0;
    FILE *ptr;
    ptr=fopen("userdata.txt","r");
    printf("enter your account number\n");
    scanf("%d",&loan[j].acc_no);
    while(fscanf(ptr,"%d\t%s\t%d\t%d\t%d\t%d\t%lf\t%s\t%s\t%f\n",&a[j].acc_no,a[j].name,&a[j].birthday,&a[j].birthmonth,&a[j].birthyear,&a[j].age,&a[j].phone_no,a[j].address,a[j].acc_type,&a[j].amt)!=EOF)
    {
        if(a[j].acc_no==loan[j].acc_no)
        {
            test++;
            printf("enter your choice\n");
            printf("1.Home_loan\n 2.Education_loan\n 3.Car_loan\n4.Gold loan\n");
            scanf("%d",&choice);
            if(choice==1)
            {
                printf("\n\t\t\tWELCOME TO HOME LOAN APPLICATION\t\t\n");
                printf("\tGet the lowest home loan interest rate starting at 6.83% per annum with minimum applicable processing starting from 0.25% of the loan amount\n");
                printf("Home loan interest rate is 6.75%* per annum\n");
                printf("Documents required for home loan are\n");
                printf("1.PERSONAL IDENTIFICATION\n *Primary identification:current passport,driver's license,voter id\n *Secondary identification:birth certificate,citizenship certificate\n");
                printf("2.INCOME DETAILS\n *If you an employee,you will need\ta.A copy of your 2 most recent pay slips\nb.your most recent payment summary from your employee\n");
                printf("*If you are self-employeed,you will need\t a.personal and business tax returns\nb.tax assessments for last 2 years\n");
                printf("*If you have a rental income,you will need\n a.A formed signed lease(either current or new)\n b.Your most recent rental statement\n c.Tax return no older than 18 months\n");
                printf("3.HOME LOAN SITUATION\n *If you're a first home buyer\n a.statements showing your savings and investment history\n b.your most recent statements of your bank account and credit card\n");
                printf("c.A copy of sale for property you are buying\n d.Supporting evidence if other funds are contributing towards the deposit on the purchase as well\n");
                printf("*If you're an owner occupied home buyer\n a.Your most recent statement of your credit account\n b.Account statements for all home loans and personal loans for last 6 months\n");
                printf("c.A copy of sale for property you are buying\n d.Supporting evidence if other funds are contributing towards the deposit on the purchase as well\n");
                printf("4.ASSETS AND LIABILITIES\n *Assets-Bank account details with proof of your savings\nCurrent term deposit account\nShare investment statement\nSuperannuation statements\nProperty or vehicle assets\n");
                printf("*Liabilities-Details of any existing loans and credit card statements\n");
                printf("Terms and conditions apply*\n");
                printf("You can download the loan application form from www.xyz.com and visit the nearest branch of our branch\n");
                printf("\t\tTHANK YOU FOR BANKING WITH US\t\t\n");
            }
            else if(choice==2)
            {
                printf("\n\t\t\tWELCOME TO CAR LOAN APPLICATION\t\t\n");
                printf("Apply for New Car Loans get up to 100% financing for your car at attractive Interest Rates & flexible repayment tenures. Apply now!");
                printf("Car loan interest rate is 7.30%* per annum\n");
                printf("Documents required for car loan are\n");
                printf("1.OFFICE/BUSINESS PROOF\n2.INCOME PROOF\n3.LAST 3 MONTHS BANK STATEMENT\n4.AGE PROOF(PAN card/passport/driver's license)\n");
                printf("5.SIGN VERIFICATION PROOF(PAN/passport)\n6.EMPLOYEMENT/BUSINESS CONTINUITY PROOF\n");
                printf("Terms and conditions apply*\n");
                printf("You can download the loan application form from www.xyz.com and visit the nearest branch of our branch\n");
                printf("\t\tTHANK YOU FOR BANKING WITH US\t\t\n");
            }
            else if(choice==3)
            {
                 printf("\n\t\t\tWELCOME TO EDUCATION LOAN APPLICATION\t\t\n");
                 printf("Pursue your dream career, Get Instant Education Loan without mortgage.\n100% Finance to study in India or Abroad.\nCover Course Fee, Travel, Living & other Costs. Low Interest Rate. Simple & Easy Process.");
                 printf("Personal loan interest rate is 10.75%* per annum\n");
                 printf("FEATURES\n *Repayment period of upto 15 years after Course Period + 12 months of repayment holiday\n *Processing Charges\tLoans upto Rs. 20 lacs : NIL\tLoans above Rs. 20 lacs: Rs. 10,000 (plus taxes)\n");
                 printf("*Repayment will commence one year after completion of course.\t*Loan to be repaid in 15 years after the commencement of repayment");
                 printf("Terms and conditions apply*\n");
                 printf("You can download the loan application form from www.xyz.com and visit the nearest branch of our branch\n");
                 printf("\t\tTHANK YOU FOR BANKING WITH US\t\t\n");
            }
            else if(choice==4)
            {
                printf("\n\t\t\tWELCOME TO GOLD LOAN APPLICATION\t\t\n");
                printf("Avail Gold Loan and Fulfill your Needs.Pay the Loan & Interest at the End of the Tenure.\n");
                printf("Gold loan interest rate is 9.85%* per annum\n");
                printf("Documents required for gold loan are\n");
                printf("1.Two passport size photograph\n2.ID Proof such as Driving License/PAN Card/Form(60/61)/Passport Copy/Voter ID Card/Aadhaar Card\n");
                printf("3.Address Proof such as Driving License/Voter ID Card/Ration Card/Aadhaar Card\n4.Proof of land holding in case of agriculture loan of more than Rs. 1 lakh\n");
            }
            else
            {
                printf("enter appropriate choice\n");
            }
        }
    }
    fclose(ptr);
}

void query()
{
    fflush(stdin);
    FILE *fp;
    fp=fopen("query.txt","a+");
    char q[1000];
    printf("please enter your query\n");
    gets(q);
    fprintf(fp,"%s\n",q);
    printf("Dear customer,your query has been noted,we will reply to you within 24 hours\n");
    fclose(fp);

}

void request()
{
    fflush(stdin);
    FILE *fp;
    fp=fopen("request.txt","a+");
    char r[1000];
    printf("please enter your request\n");
    gets(r);
    fprintf(fp,"%s\n",r);
    printf("Dear customer,your request has been noted,we will reply to you within 24 hours\n");
    fclose(fp);
}

void contact()
{
    printf("CALL:1800-222-333 to get your account balance\n");
    printf("CALL:122-123-222 to get your mini statement\n");
    printf("email us at customerservice@xyz.com\n");

}

void report()
{
    printf("First block the card\n");
    printf("After blocking the card report the transaction to the Bank.You can report this transaction through the below channels:\n");
    printf("a.Email: Send us an email by clicking on the Email tab\nb.Phone:Call us on our Phone Banking numbers\nc. Branch: Visit your nearest Axis Bank Branch\n");
    printf("Thank you for reporting\n");
}

void feedback_rating()
{
    fflush(stdin);
    char f[1000];
    int rate;
    FILE *fp;
    fp=fopen("fr.txt","a+");
    printf("your feedback is valuable to us,please tell us about your experience/suggestions\n");
    gets(f);
    printf("Rate our service on the scale of 1 to 5\n");
    scanf("%d",&rate);
    fprintf(fp,"%s\t%d\n",f,rate);
    printf("Thank you for banking with us\n");
    fclose(fp);
}

void EMI_calculator()
{
    int choice;
    printf("Enter your choice\n");
    printf("1.Home loan EMI calculator\n2.Personal loan EMI calculator\n3.Education loan EMI calculator\n4.Car loan EMI calculator\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        float rate=6.75;
        float principal,time,emi;
        printf("Enter total home cost= ");
        scanf("%f",&principal);
        printf("Enter time in year= ");
        scanf("%f",&time);
        rate=rate/(12*100);
        time=time*12;
        emi= (principal*rate*pow(1+rate,time))/(pow(1+rate,time)-1);
        printf("Monthly EMI for your home loan is= %f\n",emi);
    }
    else if(choice==2)
    {
        float rate=10.75;
        float principal,time,emi;
        printf("Enter total personal loan cost= ");
        scanf("%f",&principal);
        printf("Enter time in year= ");
        scanf("%f",&time);
        rate=rate/(12*100);
        time=time*12;
        emi= (principal*rate*pow(1+rate,time))/(pow(1+rate,time)-1);
        printf("Monthly EMI for your personal loan is= %f\n",emi);
    }
    else if(choice==3)
    {
        float rate=8.75;
        float principal,time,emi;
        printf("Enter total education loan cost= ");
        scanf("%f",&principal);
        printf("Enter time in year= ");
        scanf("%f",&time);
        rate=rate/(12*100);
        time=time*12;
        emi= (principal*rate*pow(1+rate,time))/(pow(1+rate,time)-1);
        printf("Monthly EMI for your education loan is= %f\n",emi);
    }
    else if(choice==4)
    {
        float rate=7.30;
        float principal,time,emi;
        printf("Enter total car loan cost= ");
        scanf("%f",&principal);
        printf("Enter time in year= ");
        scanf("%f",&time);
        rate=rate/(12*100);
        time=time*12;
        emi= (principal*rate*pow(1+rate,time))/(pow(1+rate,time)-1);
        printf("Monthly EMI for your car loan is= %f\n",emi);
    }
    else
    {
        printf("Enter appropriate choice\n");
    }
}

void pay_taxes()
{
    int choice;
    float income;
    printf("Enter your choice\n");
    printf("1.salaried job\n 2.business\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        float tax;
        printf("Enter your annual income\n");
        scanf("%f",&income);
        if(income<=200000)
        {
            tax=0;
        }
        else if(tax>200000 && income<=500000)
        {
            tax=(income-200000)/10;
        }
        else if(income>500000 && income<=1000000)
        {
            tax=(((income-500000)/10)*2)+30000;
        }
        else if(income>1000000)
        {
            tax=(((income-1000000)/10)*3)+130000;
        }
        else
        {
            printf("invalid input\n");
        }
        printf("The tax payable is %f\n",tax);
    }
    else if(choice==2)
    {
        float tax;
       printf("Enter your annual income\n");
       scanf("%f",&income);
       if(income<250000)
       {
           tax=0;
       }
       else if(income>250500 && income<=500000)
       {
           tax=(income-250000)/10;
       }
       else if(income>500000 && income<=1000000)
       {
           tax=(((income-500000)/10)*2)+30000;
       }
       else if(income>1000000)
       {
           tax=(((income-1000000)/10)*3)+130000;
       }
       else
       {
           printf("Invalid input\n");
       }
       printf("The tax payable is %f",tax);
    }
}

void FD_calculator()
{
    int t;
    float A,P,I,temp;
    float r=0.05;//r:annual rate of interest
    float n=4;//n:Interest rate compounded every single year
    printf("Enter initial deposit\n");
    scanf("%f",&P);
    printf("Enter time period in years\n");
    scanf("%d",&t);
    temp=(1+r/n);
    A=P*pow(temp,(n*t));
    printf("FIXED DEPOSIT=%f\n",A);
    I=A-P;
    printf("INTEREST EARNED=%f\n",I);
}


void insurance_appl()
{
    int test=0;
    int choice,j=0;
    FILE *ptr;
    ptr=fopen("userdata.txt","r");
    printf("Enter your account number\n");
    scanf("%d",&ins[j].acc_no);
    while(fscanf(ptr,"%d\t%s\t%d\t%d\t%d\t%d\t%lf\t%s\t%s\t%f\n",&a[j].acc_no,a[j].name,&a[j].birthday,&a[j].birthmonth,&a[j].birthyear,&a[j].age,&a[j].phone_no,a[j].address,a[j].acc_type,&a[j].amt)!=EOF)
    {
        if(a[j].acc_no==ins[j].acc_no)
        {
            test++;
            printf("Enter your choice\n");
            printf("1.LIFE INSURANCE\n 2.CAR INSURANCE\n 3.BUILDING INSURANCE\n");
            scanf("%d",&choice);
            if(choice==1)
            {
                printf("\n\t\tWELCOME TO LIFE INSURANCE APPLICATION\t\t\n");
                printf("Life insurance is a contract between an insurance policy holder and an insurer or assurer, where the insurer promises to pay a designated beneficiary a sum of money in exchange for a premium, upon the death of an insured person.\n");
                printf("A Comprehensive Protection At An Affordable Price To Protect Yourself And Your Loved Ones. 2 Cr Life Cover @ 1300pm* Return of Premium.\n");
                printf("The documents required for applying for life insurance are:\n");
                printf("1.Health certificate\n2.Proof of any health problems,if any\n3.Age proof\n4.address proof\n5.annual income certificate\n");
                printf("Terms and conditions apply*\n");
                printf("You can download the life insurance application form from www.xyz.com and visit our nearest branch\n");
                printf("\n\t\tTHANK YOU FOR BANKING WITH US\n");
            }
            else if(choice==2)
            {
                printf("\n\t\tWELCOME TO CAR INSURANCE APPLICATION\t\t\n");
                printf("A comprehensive car insurance policy, also known as motor package insurance, saves you money when your car is damaged in an accident or natural calamity. It also covers your vehicle against theft and burglary.\n");
                printf("Immediate Settlement for Minor Damages*,Covers Electrical & Non Electrical Accessories,Easy Renewal Process,No Claim Bonus upto 50% Third Party Cover,Quick & Easy Claims.\n");
                printf("The documents required for applying for car insurance are:\n");
                printf("1.Age proof\n2.Car purchase papers\n3.Driver's license\n");
                printf("Terms and conditions apply*\n");
                printf("You can download the car insurance application form from www.xyz.com and visit our nearest branch\n");
                printf("\n\t\tTHANK YOU FOR BANKING WITH US\n");
            }
            else if(choice==3)
            {
                 printf("\n\t\tWELCOME TO BUILDING INSURANCE APPLICATION\t\t\n");
                 printf("Building insurance plans offer coverage of the liabilities that arise out of damages to the house and/or the contents due to man-made reasons like burglary, theft, etc.\n");
                 printf("Covers all Risk,Simplified Claim Procedure,No Documentation,Online Policy,Buy Now!Upto 45% Off,Coverage Upto 5 Yrs\n");
                 printf("The documents required for applying for building insurance are:\n");
                 printf("1.Building construction permission grant certificate\n2.Building completion certificate\n3.Ownership proof\n");
                 printf("Terms and conditions apply*\n");
                 printf("You can download the building insurance application form from www.xyz.com and visit our nearest branch\n");
                 printf("\n\t\tTHANK YOU FOR BANKING WITH US\n");
            }
            else
            {
                printf("INVALID CHOICE\n");
            }
        }
    }
    fclose(ptr);
}

void insurance_calc()
{
    int choice;
    printf("1.LIFE INSURANCE\n2.CAR INSURANCE\n3.BUILDING INSURANCE\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        float SA,Y,MP,QP,HP,YP;
        int years;
        printf("Enter your sum assured\n");
        scanf("%f",&SA);
        printf("Enter your life insurance policy terms,in years\n");
        scanf("%d",&years);
        MP=SA/(years*12);
        QP=SA/(years*4);
        HP=SA/(years*2);
        YP=SA/(years);
        printf("Your monthly premium is %f\n",MP);
        printf("Your Quarterly premium is %f\n",QP);
        printf("Your half yearly premium is %f\n",HP);
        printf("Your yearly premium is %f\n",YP);
        printf("Note: Actual premium may vary because of various charges imposed by company.\n");
    }
    else if(choice ==2)
    {
        fflush(stdin);
        int ch;
        char ct[50],ft[50],rn[50],mod[50],var[50];
        char ODC,TPC,PAC,death,disability;
        long int price,claim;
        printf("ENTER CAR DETAILS\n");
        printf("Enter car company:\n");
        gets(ct);
        printf("Enter model:\n");
        gets(mod);
        printf("Enter variant:\n");
        gets(var);
        printf("Enter fuel type:\n");
        gets(ft);
        printf("Enter registeration number:\n");
        gets(rn);
        printf("On-road price:\n");
        scanf("%ld",&price);
        printf("Own-Damage Cover(ODC) : This covers damages and losses caused to your car, by this we mean: Road Accidents , Theft, Natural Disasters and Man-Made Disasters\n");
        printf("\nThird-Party Cover(TPC): This covers damages and losses caused by your car to third party, this includes:Legal liability on death, injury of third party person\n");
        printf("\nPersonal Accident Cover(PAC) : This cover offers compensation in case of accidental death or disability.\n");
        printf("Enter your choice\n");
        printf("1.ODC\n2.TPC\n3.PAC(death)\n4.PAC(disability)\n5.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:claim=price-(price*0.15);
                   printf("Amount claimed by the account holder is = %d\n",claim);
                   break;
            case 2:claim=price-(price*0.45);
                   printf("Amount claimed by the account holder is = %d\n",claim);
                   break;
            case 3:claim=price;
                   printf("Amount claimed by the account holder is = %d\n",claim);
                   break;
            case 4:claim=price-(price*0.25);
                   printf("Amount claimed by the account holder is = %d\n",claim);
                   break;
            case 5:exit(0);
                   break;

        }
    }
    else if(choice==3)
    {
        int ch;
        long int pv,claim;
        printf("ENTER BUILDING DETAILS\n");
        printf("Enter property value:\n");
        scanf("%ld",&pv);
        printf("Enter building type:\n");
        printf("1.Residential Buildings\n2.Educational Buildings\n3.Institutional Buildings\n4.Industrial Buildings\n5.Assembly Buildings\n6.exit\n");
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:claim=pv-(pv*0.10);
                   printf("Amount claimed by the account holder is = %d\n",claim);
                   break;
            case 2:claim=pv-(pv*0.20);
                   printf("Amount claimed by the account holder is = %d\n",claim);
                   break;
            case 3:claim=pv-(pv*0.15);
                   printf("Amount claimed by the account holder is = %d\n",claim);
                   break;
            case 4:claim=pv-(pv*0.25);
                   printf("Amount claimed by the account holder is = %d\n",claim);
                   break;
            case 5:claim=pv-(pv*0.30);
                   printf("Amount claimed by the account holder is = %d\n",claim);
                   break;
            case 6:exit(0);
                   break;
        }
    }
    else
    {
        printf("Enter valid choice\n");
    }
}

void Cheque_book()
{
    printf("A cheque book can be issued for your account only after you have completed your KYC\n");
    printf("You can place a request using the below options:\n");
    printf("a.SMS: SMS <CHQBK> space <last 6 digits of your account no.> to 5676782 from your registered mobile number.(For e.g:CHQBK 123456)\n");
    printf("b.xyzbank.com/Support:Support Home Page>Get It Done Instantly>Click on Cheque Book Request>Enter Registered Mobile Number>Enter OTP>Select Account>Click on Submit>Cheque Book will be issued and delivered.\n");
    printf("c.Axis Mobile App:Select Banking>Click on Services>Click on Savings/Current Account>Click on New Cheque Book\n");
    printf("d.ATM: Visit your nearest Axis Bank ATM\n");
    printf("Please note:Charges will be applicable for a cheque book, if you request for another/additional cheque book in the same quarter. Click here to know the charges.\n");

}

void book()
{
    char s[1000];
    float time;
    FILE *ptr;
    ptr=fopen("book.txt","a+");
    printf("Enter time(hours.min)\n");
    scanf("%f",&time);
    fflush(stdin);
    printf("Please mention whom do you want to meet and the reason for appointment\n");
    gets(s);
    fprintf(ptr,"%f\t%s\n",time,s);
    printf("Thank you for banking with us\n We will confirm your appointment within 30 minutes\n");
    fclose(ptr);

}

void currency_conv()
{
    float rup,dol,eur;
    int choice;
    printf("1.Rupee to Dollar\n");
    printf("2.Rupee to Euro\n");
    printf("Enter choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("Enter the currency in rupees=\n");
               scanf("%f",&rup);
               dol=rup/73;
               printf("The currency in dollar is %.2f\n",dol);
               break;
        case 2:printf("Enter the currency in rupees=\n");
               scanf("%f",&rup);
               eur=rup/84;
               printf("The currency in Euro is %.2f\n",eur);
    }

}

void C_appl()
{
    fflush(stdin);
    FILE *fp;
    fp=fopen("cappl.txt","a+");
    char n[1000];
    int accno;
    double pno;
    printf("Enter your name\n");
    gets(n);
    printf("Enter your account number\n");
    scanf("%d",&accno);
    printf("Enter your phone number\n");
    scanf("%lf",&pno);
    fprintf(fp,"%s\t%d\t%lf\n",n,accno,pno);
    printf("Thank you for banking with us\n We will confirm your application within 24 hours\n");
    printf("To activate your card\n");
    printf("1.Receive your credit card in the mail.\n2.Find a sticker on the card with activation instructions.\n");
    printf("3.Follow the instructions for activating online or over the phone,whichever you prefer.\n4.Wait for confirmation that your card has been activated.\n");
    fclose(fp);
}

void D_appl()
{
    fflush(stdin);
    FILE *ptr;
    ptr=fopen("dappl.txt","a+");
    char a[1000];
    int acno;
    double pn;
    printf("Enter your name\n");
    gets(a);
    printf("Enter your account number\n");
    scanf("%d",&acno);
    printf("Enter your phone number\n");
    scanf("%lf",&pn);
    fprintf(ptr,"%s\t%d\t%lf\n",a,acno,pn);
    printf("Thank you for banking with us\n We will confirm your application within 24 hours\n");
    printf("To activate your debit card\n");
    printf("1.Once you get your Debit Card,there is an ATM pin given in a sealed envelope.\n2.When you go to the ATM, enter your Debit Card and enter the ATM pin provided in the envelope\n.");
    printf("3.Change your ATM PIN and use the card henceforth for regular transactions.\n");
    fclose(ptr);

}

void C_deact()
{
    printf("To cancel/deactivate your credit card:\n");
    printf("1.Find the number of the customer service department you need to contact\n2.Redeem any remaining rewards\n3.Pay off any remaining balance\n4.Call your bank\n");
    printf("4.Send a letter requesting card account closure, just to be sure\n5.Check your credit report to confirm the cancellation\n6.Dispose of your card properly after confirming cancellation\n");
}

void D_deact()
{
    printf("To cancel/deactivate your debit card:\n");
    printf("1.Call Contact Centre at toll free number: 1800 34 2211 OR \n");
    printf("Through SMS: Send SMS “BLOCK<space>XXXX” to 561276 from registered mobile number (XXXX is the last 4-digits of your Debit Card)  OR \n");
    printf("Submit a request letter at nearest Branch for Blocking Debit Card.\n");
    printf("Once the Card is blocked, a confirmation SMS will be sent to the registered mobile number along with a ticket number which may be required for future reference.\n");

}

void balance()
{
    FILE *fp;
    fp=fopen("atm.txt","a+");
    int test=0,j=0;
    printf("Enter your account number\n");
    scanf("%d",&ba[j].a_no);
    while(fscanf(fp,"%d\t%d\t%f\n",&d[j].a_no,&d[j].pass,&d[j].am)!=EOF)
    {
        if(d[j].a_no==ba[j].a_no)
        {
            test++;
            printf("%f\n",d[j].am);
        }
    }
    if(test==0)
    {
        printf("Enter appropriate account number\n");
    }
}

void transaction()
{
    FILE *fp;
    fp=fopen("atm.txt","a+");
    int test=0,j=0;
    printf("Enter your account number\n");
    scanf("%d",&t[j].a_no);
    while(fscanf(fp,"%d\t%d\t%f\n",&d[j].a_no,&d[j].pass,&d[j].am)!=EOF)
    {
        if(d[j].a_no==t[j].a_no)
        {
            test++;
            printf("Enter amount you want to transact\n");
            scanf("%f",&t[j].am);
            d[j].am=d[j].am-t[j].am;
            fprintf(fp,"%d\t%d\t%f\n",d[j].a_no,d[j].pass,d[j].am);
            printf("Amount withdrawn successfully\nTHANK YOU FOR USING OUR ATM SERVICE\n");
        }
    }
    if(test==0)
    {
        printf("Enter appropriate account number\n");
    }
    fclose(fp);
}

void deposit()
{
    FILE *fp;
    fp=fopen("atm.txt","a+");
    int test=0,j=0;
    printf("Enter your account number\n");
    scanf("%d",&de[j].a_no);
    while(fscanf(fp,"%d\t%d\t%f\n",&d[j].a_no,&d[j].pass,&d[j].am)!=EOF)
    {
        if(d[j].a_no==de[j].a_no)
        {
            test++;
            printf("Enter amount you want to deposit\n");
            scanf("%f",&de[j].am);
            d[j].am=d[j].am+de[j].am;
            fprintf(fp,"%d\t%d\t%f\n",d[j].a_no,d[j].pass,d[j].am);
            printf("Amount withdrawn successfully\nTHANK YOU FOR USING OUR ATM SERVICE\n");
        }
    }
    if(test==0)
    {
        printf("Account number not found\nEnter appropriate account number\n");
    }
    fclose(fp);

}
void ATM_banking()
{
    int choice;
    int j=0,test=0;
    int a,b;
    int g[100];
    FILE *p;
    p=fopen("atm.txt","a+");
    printf("Enter your account number\n");
    scanf("%d",&a);
    printf("Enter your password\n");
    scanf("%d",&b);
    while(fscanf(p,"%d\t%d\%f",&d[j].a_no,&d[j].pass,&d[j].am)!=EOF)
    {
        if((a==d[j].a_no) && (b==d[j].pass))
        {
            test++;
            printf("Enter your choice\n");
            printf("1.Balance enquiry\n");
            printf("2.Amount transaction\n");
            printf("3.Amount deposit\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:balance();
                       break;
                case 2:transaction();
                       break;
                case 3:deposit();
                       break;
                case 4:exit(0);
            }
        }
    }
    if(test==0)
    {
         printf("Enter appropriate account number and password\n");
    }

}
struct engine_data
{
    char search_feed[150];
};

typedef struct engine_data ED;
ED search_list[300];
int gc = 0;

void near_bank()
{
    FILE *loc;
    loc = fopen("BANK.txt", "a+");
    if (loc == NULL)
    {
        printf("File Not found\n");
        return;
    }
    while(!feof(loc))
    {
        fscanf(loc,"%s",search_list[gc].search_feed);
        //printf("%s\n",search_list[gc].search_feed);
        gc++;
    }
    int eof=gc;
     fclose(loc);
    int i,j,k;
    char c[20];
    printf("keshwapur/nehru_nagar/vidyanagar/koppikar_road/deshpande_nagar/tarihal_industrial_estate/vishweshwar_nagar/munneshwar_nagar/navanagar\n");
    printf("Enter your location : ");
    scanf("%s",c);
    int x = strlen(c);
     for(k=0;k<eof-1;k++)
      {
          fscanf(loc,"%s",search_list[gc].search_feed);
         int y = strlen(search_list[k].search_feed);
         for(i=0 ; i<=y-x ; i++)
         {
           j = 0;
           while(j<x && c[j] == search_list[k].search_feed[i+j])
           {
               j = j+1;
           }
            if(j == x)
               {
                printf("\nOur banch nearest to you is : %s\n",search_list[k].search_feed);
               }

         }
     }
}

struct user
{
    int acc,amount;
    char name[25];
};
typedef struct user US;
US s_list[300];
int g_c = 0;

void sort_acc()
{
    US a[300];
    FILE *f;
    f = fopen("userdata.txt", "r");
    if (f == NULL)
    {
        printf("File Not found\n");
        exit(0);
    }
    printf("data of all account holders\n");
    printf("account.no\tamount\t\tname\n");
    while(!feof(f))
    {
        fscanf(f,"%d\t%d\t%[^\n]s", &s_list[g_c].acc,&s_list[g_c].amount, s_list[g_c].name);
        printf("%d\t\t%d\t\t%s\n", s_list[g_c].acc , s_list[g_c].amount , s_list[g_c].name);
        g_c++;
    }
    printf("\n\n");
    int eof=g_c;
    fclose(f);
    int i,j,n=eof;
    int v;
    for(i=1;i<=n-1;i++)
    {
        v=s_list[i].acc;
        j=i-1;
        while(j>=0 && s_list[j].acc>v)
        {
           s_list[j+1].acc=s_list[j].acc;
           j--;

        }
        s_list[j+1].acc=v;
    }
    printf("sorted data of all account holders wrt account number\n");
    printf("account.no\tamount\t\tname\n");
        for(i=0 ; i<=n-1 ; i++)
            {
                printf("%d\t\t%d\t\t%s\n", s_list[i].acc , s_list[i].amount , s_list[i].name);
            }
}

struct users
{
    int acc,amount;
    char name[25];
};
typedef struct users USS;
USS search_listt[300];
int g_cc = 0;
void sort_amt(int first,int last)
{
    int pivot,j,temp1,temp2,i;
    if(first<last)
    {
         pivot=first;
         i=first;
         j=last;
         while(i<j)
        {
             while(search_listt[i].amount<=search_listt[pivot].amount && i<last)
                 i++;
             while(search_listt[j].amount>search_listt[pivot].amount)
                 j--;
             if(i<j)
            {
                 temp1=search_listt[i].acc;
                  search_listt[i].acc=search_listt[j].acc;
                  search_listt[j].acc=temp1;
             }
             if(i<j)
            {
                 temp2=search_listt[i].amount;
                  search_listt[i].amount=search_listt[j].amount;
                  search_listt[j].amount=temp2;
             }
         }

         temp1=search_listt[pivot].acc;
         search_listt[pivot].acc=search_listt[j].acc;
         search_listt[j].acc=temp1;

         temp2=search_listt[pivot].amount;
         search_listt[pivot].amount=search_listt[j].amount;
         search_listt[j].amount=temp2;
         sort_amt(first,j-1);
         sort_amt(j+1,last);
    }
}



int sort_amt_m()
{
    USS a[300];
    FILE *f;
    f = fopen("sortdata.txt", "r");
    if (f == NULL)
    {
        printf("File Not found\n");
        exit(0);
    }
    printf("data of all account holders\n");
    printf("account.no\tamount\t\tname\n");
    while(!feof(f))
    {
        fscanf(f,"%d\t%d\t%[^\n]s", &search_listt[g_cc].acc,&search_listt[g_cc].amount, search_listt[g_cc].name);
        printf("%d\t\t%d\t\t%s\n", search_listt[g_cc].acc , search_listt[g_cc].amount , search_listt[g_cc].name);
        g_cc++;
    }
    printf("\n\n");
    int eof=g_cc;
    fclose(f);

    int size,i;
    size=eof;
    sort_amt(0,size-1);

  printf("sorted data of all account holders wrt amount\n");
   printf("account.no\tamount\n");
  for(i=0;i<size;i++)
  {
       printf("%d\t\t%d\n", search_listt[i].acc , search_listt[i].amount);
  }
  return 0;
}


void searchadmin(list ad[300],char adminname[50])
{

    char passadmin[50];
    int count=1,k=0;
    int checkmade=0;
    printf("enter your password = ");
    scanf("%s",passadmin);


     if(adminname[0]== '\0' || passadmin[0]=='\0')
    {
        count=0;
        printf("input your name and password");
        exit(0);
    }
     else
   {
        while(k<gb)
        {
            char *p = strstr(ad[k].name,adminname);
            char *chepass=strstr(ad[k].password,passadmin);
            if(p && chepass)
          {
               checkmade=1;
               break;
          }
          else
          {
              k++;
          }

        }
   }
   if(checkmade==1)
   {
        test=2;
        printf("YOU ARE A VALID ADMIN");
   }
   else
   {
       printf("OOPS! ,We couldn't find your name in your directory");
   }

   if(test==2)
   {
       int m;
       int first ,last;
       printf("\nPlease enter your choice\n");
       printf("1.Create an account\n");
       printf("2.View customer list\n");
       printf("2.Edit customer details\n");
       printf("4.Sort data with respect to account number\n");
       printf("5.Sort data with respect to amount\n");
       printf("6.exit\n");
       scanf("%d",&m);
       switch(m)
       {
           case 1:new_acc();
                  break;
           case 2:view_list();
                  break;
           case 3:edit();
                  break;
           case 4:sort_acc();
                  break;
           case 5:sort_amt_m();
                  sort_amt(first,last);
                  break;
           case 6:exit(0);
       }
   }
}

