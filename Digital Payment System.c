#include<stdio.h>
#include<string.h>
FILE *ngdpoint,*trid;
float amount,total_amount;
 char PIN[10],tranid[]="1920347HFGT89";


void Cash_Out()
 {  ngdpoint=fopen("PinBalance.txt","w");
    trid=fopen("trids.txt","a");
     char num[100],pin[20];
      float vatt;


  printf("Enter Uddokta A/C Number:\n");
     scanf("%s",&num);
      system("cls");

   printf("Enter amount:\n");
   scanf("%f",&amount);
     system("cls");
   printf("Cash Out\nTo:%s\nAmount:Tk %.2f\n",num,amount);
   printf("Enter PIN:\n");
   scanf("%s",&pin);
    vatt=amount*0.0149;
     system("cls");
   if(strcmp(PIN,pin)==0)
   {
       total_amount-=(amount+vatt);
       if(total_amount>=0)
       {
         printf("Cash Out successful\nUddokta:%s\nAmount:Tk %.2f\nTxnID: %s\nTotal Fee:%.2f\nBal:%.2f",num,amount,tranid,vatt,total_amount);
        fprintf(trid,"Cash Out successful\nUddokta:%s\nAmount:Tk %.2f\nTxnID: %s\nTotal Fee:%.2f\nBal:%.2f\n\n",num,amount,tranid,vatt,total_amount);
        fclose(trid);

       }
           else
       {
           total_amount+=(amount+vatt);
            printf("\nInsufficient balance.Please check and try again later.\n");
       }

   }
   else if(strcmp(PIN,pin)!=0)
    printf("\nWrong PIN.Please check and try again\n");
    fprintf(ngdpoint,"%s %f",PIN,total_amount);
         fclose(ngdpoint);



 }
  int  Send_Money()
 {
     trid=fopen("trids.txt","a");
     ngdpoint=fopen("PinBalance.txt","w");
     char num[20],ref[20],pin[10];
     float fvat = 5.58;
     printf("Enter Receiver Account Number:");
     scanf("%s",&num);
     system("cls");


     printf("Enter Amount:");
     scanf("%f",&amount);
     system("cls");
     printf("Enter Reference:");
     scanf("%s",ref);
     system("cls");
     printf("Send Money\nTo: %s\nAmount:Tk %.2f\nReference: %s\nEnter PIN:",num,amount,ref);
     scanf("%s",&pin);
     system("cls");
      if(strcmp(PIN,pin)==0)
   {
       total_amount-=(amount+fvat);
     if(total_amount>=0 && amount>=10)
      {
        printf("Send Money Tk %.2f to %s successfull\nFee & VAT:%.2f\nBalance: Tk %.2f ",amount,num,fvat,total_amount);
        fprintf(trid,"Send Money Tk %.2f to %s successfull\nFee & VAT:%.2f\nBalance: Tk %.2f\n\n",amount,num,fvat,total_amount);
        fclose(trid);

      }
      else if(amount>total_amount)
      {
        printf("Insufficient balance.Please check and try again later.");
         total_amount+=(amount+fvat);
      }
      else if(amount<10)
      {
          total_amount+=(amount+fvat);
          printf("Transaction is not within the limit.Please Check and try again.Please call 16167 for details.");
      }

   }
   else
    printf("\nWrong PIN.Please check and try again\n");
      fprintf(ngdpoint,"%s %f",PIN,total_amount);
         fclose(ngdpoint);
 }
 int Mobile_Recharge()
 {
     int number;
  printf("Select Operator\n");
  printf("1.Teletalk\n");
   printf("2.GP\n");
    printf("3.Airtel\n");
     printf("4.Robi\n");
      printf("5.Banglalink\n");
       printf("0.Main Menu\n");
       scanf("%d",&number);
       system("cls");
       if(number==1)
        recharge();
       else if(number==2)
       recharge();
        else if(number==3)
       recharge();
        else if(number==4)
       recharge();
        else if(number==5)
         recharge();
        else if(number==0)
        main();


 }
int Payment()
{
    ngdpoint=fopen("PinBalance.txt","w");
 trid=fopen("trids.txt","a");
  float vatt;
  int opt;
     char accountnumb[20],counterNum[20],ref[100],pin[5];
  printf("Merchant A/C Number:");
   scanf("%s",&accountnumb);
   system("cls");
   printf("Enter Amount:");
   scanf("%f",&amount);
   system("cls");
    vatt=amount*0.0149;
   printf("Enter counter number:");
    scanf("%s",&counterNum);
    system("cls");
    printf("Enter Reference:");
     scanf("%s",&ref);
    system("cls");
    printf("Payment\nTo: %s\nCounter: %s\nReference: %s\nEnter PIN:\n",accountnumb,counterNum,ref);
    scanf("%s",&pin);
    system("cls");
      if(strcmp(PIN,pin)==0)
       {
            total_amount-=(amount+vatt);
           if(total_amount>=0)
           {
                fprintf(ngdpoint,"%s %f",PIN,total_amount);
                fclose(ngdpoint);
              printf("Payment of %.2f Tk to %s successful.\nTrxID: %s\nFee & VAT:Tk %.2f\nBalance:Tk %.2f\n0.Main Menu",amount,accountnumb,tranid,vatt,total_amount);
                fprintf(trid,"Payment of %.2f Tk to %s successful.\nTrxID: %s\nFee & VAT:Tk %.2f\nBalance:Tk %.2f\n\n",amount,accountnumb,tranid,vatt,total_amount);
                fclose(trid);

          scanf("%d",&opt);
          if(opt==0)
            main();
           }
           else
           {
               total_amount+=(amount+vatt);
                  printf("Insufficient balance.Please check and try again later.");
                   fprintf(ngdpoint,"%s %f",PIN,total_amount);
               fclose(ngdpoint);
           }
       }
    else
         printf("\nWrong PIN.Please check and try again\n");
          fprintf(ngdpoint,"%s %f",PIN,total_amount);
         fclose(ngdpoint);

 }
 int  Bill_Pay()
 {
   int number;
    printf("Select Bill Category:\n");
    printf("1. Electricity\n");
    printf("2. Internet\n");
    printf("3. Water\n");
    printf("4. TV & Telephone\n");
    printf("5. Education\n");
    printf("6. Bank & Finance\n");
    printf("7. Insurance\n");
    printf("8. COVID19 Sample Collection Fee\n");
    printf("9. ekpay\n");
    printf("10. Ministry of Land\n");
    printf("11. Other\n");
    printf("0. Main Menu\n");

    scanf("%d", &number);

    if(number==1)
    Payment();
    else if(number==2)
   Payment();
    else if(number==3)
   Payment();
    else if(number==4)
    Payment();
    else if(number==5)
    Payment();
    else if(number==6)
    Payment();
    else if(number==7)
   Payment();
    else if(number==8)
    Payment();
    else if(number==9)
    Payment();
    else if(number==10)
  Payment();
    else if(number==11)
   Payment();
    else if(number==0)
    main();
    else
    printf(" ");
 }
void EMI_Payment()
{
     trid=fopen("trids.txt","a");
    ngdpoint=fopen("PinBalance.txt","w");
    char ch,accountnumb[20],membercode[10],pin[5];
  float vatt;
  int d;
    printf("Carrier Info\n\n");
     printf("Select Company:\n1.Aspada Paribesh Unnayan Foundation");
  printf("2.Padakhep Manabik Unnayan Kendra\n3.Palli Mongal Karmosuchi(PMK)\n4.BURO Bangladesh\n5.Ambala\nn next\n");
  ch=getch();
  system("cls");
   if(ch=='n')
  {
     printf("Carrier info\n");
     printf("Foundataion\n6.Dwip Unnayan Songstha\n7.VPKA Foundation\n");
     printf("8.Pally Bikash Kendra(PBK)\n9.Sagarika Samaj Unnayan Songstha(SSUS)\n0.Main Menu\n");
      ch=getch();
       system("cls");
  }
   printf("Enter Receiver Account Number:\n");
  scanf("%s",accountnumb);
   system("cls");
  printf("Enter Member Code:");
  scanf("%s",membercode);
   system("cls");
  printf("Enter Amount:\n");
  scanf("%f",&amount);
   system("cls");
  vatt=amount*0.015;
  printf("EMI Payment\nMember Code: %s\nMobile No: %s\nEnter PIN\n",membercode,accountnumb);
  scanf("%s",pin);
   system("cls");
   if(strcmp(PIN,pin)==0)
       {
           total_amount-=(amount+vatt);
           if(total_amount>=0)
           {
              printf("EMI Payment of %.2f Tk to %s successful.\nTrxID: %s\nFee & VAT:Tk %.2f\nBalance:Tk %.2f\n0.Main Menu",amount,accountnumb,tranid,vatt,total_amount);
                fprintf(trid,"EMI Payment of %.2f Tk to %s successful.\nTrxID: %s\nFee & VAT:Tk %.2f\nBalance:Tk %.2f\n\n",amount,accountnumb,tranid,vatt,total_amount);
                fclose(trid);
                 fprintf(ngdpoint,"%s %f",PIN,total_amount);
                fclose(ngdpoint);
          scanf("%d",&d);
          if(d==0)
            main();
           else
            return ;
           }
           else
           {
                  total_amount+=(amount+vatt);
                  printf("Insufficient balance.Please check and try again later.");

           }
       }
       else
         printf("\nWrong PIN.Please check and try again\n");

 }


 int My_Nagad()
 {
     struct test
     {
         int x;
     }la[10];
     int num;
  printf("My Nagad\n\n\n1.Balance  Enquiry\n2.Mini Statement\n3.Updated Operator\n4.Update Profit Status\n5.Helpline\n6.Allow New Device\n7.Change Account Type\n0.Main Menu\n");
  printf("");
  scanf("%d",&num);
  system("cls");
  if(num==1)
  {
      ngdpoint=fopen("PinBalance.txt","r");
     char pin[10];
   printf("Enter PIN:\n");
   scanf("%s",pin);
    system("cls");
     fscanf(ngdpoint,"%s %f",&PIN,&total_amount);
   if(strcmp(PIN,pin)==0)
   {
       printf("Balance: Tk %.2f\n0.Main Menu\n",total_amount);
       scanf("%d",&la[1].x);
       if(la[1].x==0)
        main();
       else
        return ;

   }
   else
    printf("\nWrong PIN.Please check and try again\n");


  }
  else if(num==2)
  {
    char pin[10];
   printf("Enter PIN:\n");
   scanf("%s",pin);
    system("cls");
 if(strcmp(PIN,pin)==0)
   {
       printf("Statement List:\n");
     char str[100];
     trid=fopen("trids.txt","r");
     while(!feof(trid))
     {
      fgets(str,39,trid);
      printf("%s",str);

     }
     printf("0.Main Menu\n");
       scanf("%d",&la[2].x);
       if(la[2].x==0)
        main();
       else
        return ;

   }
   else
    printf("\nWrong PIN.Please check and try again\n");

  }
  else if(num==3)
  {
      char pin[10];
   printf("Enter PIN:\n");
   scanf("%s",pin);
    system("cls");
    if(strcmp(PIN,pin)==0)
    {
        printf("MNO update successful\n0.Main Menu\n");
        scanf("%d",&la[3].x);
        if(la[3].x==0)
            main();
        else
            return ;
    }
    else
        printf("\nWrong PIN.Please check and try again\n");
  }
  else if(num==4)
  {
      printf("Your profit status is currently disabled.\nDo you want to enable it?\n1.Yes\n2.No\n0.Main Menu\n");
      scanf("%d",&la[4].x);
      if(la[4].x==1)
      {
          char pin[10];
          printf("Enter PIN:");
          scanf("%s",&pin);
          system("cls");
         if(strcmp(PIN,pin)==0)
           {
          printf("Your Profit status is enable successfully.\n");
           }
           else
           {
              printf("Wrong PIN.Please check and try again\n");
              return ;
           }

      }
        else if(la[4].x==2)
          {
              printf("Your Profit status is disabled.\n");
          }
      else if(la[4].x==0)
        main();

  }
  else if(num==5)
  {
     printf("Call 16167 or visit www.nagad.com.bd for more info.\n0.Main Menu\n");
      scanf("%d",&la[5].x);
      if(la[5].x==0)
        main();
      else
        return ;
  }
  else if(num==6)
  {
      char pin[10];
      printf("Allow New Device\n1.iPhone\n0.Main Menu\n");
      scanf("%d",&la[6].x);
      if(la[6].x==1)
      {
          printf("Enter PIN:\n");
          scanf("%s",&pin);
        if(strcmp(PIN,pin)==0)
           {
          printf("You allow iPhone successfully.\n");
           }
           else
           {
              printf("Wrong PIN.Please check and try again\n");
              return ;
           }
      }
      else if(la[6].x==0)
        main();

  }
   else if(num==7)
  {
      char pin[10];
      printf("Change Account Type\nDo you want to change your account to Islamic Account?\nPlease confirm your action using PIN.\n\nEnter PIN.\n");
      scanf("%s",&pin);
        if(strcmp(PIN,pin)==0)
           {
           printf("Your Account Type change to Islamic Account.\n0.Main Menu\n");
           scanf("%d",&la[7].x);
           system("cls");
           if(la[7].x==0)
            main();

           }
           else
           {
              printf("Wrong PIN.Please check and try again\n");
              return ;
           }
      }
    else if(num==0)
        main();

 }



 int PIN_Reset()
 {
  int number;
  printf("1.Forgot PIN\n");
  printf("2.Change PIN\n");
  printf("0.Main Menu\n");
  scanf("%d",&number);
   ngdpoint=fopen("PinBalance.txt","w");
  if(number==1)
  {
      char nid[]="20048340853",yr[]="2004", a[25],year[6];;
      int d;
      printf("Enter your Nagad registered NID/Photo\NID number here:");
      scanf("%s",&a);
       system("cls");
      printf("Enter 4 digits of your Birth Year(YYYY):");
      scanf("%s",&year);
          if((strcmp(a,nid)==0)&&(strcmp(year,yr)==0))
          {
                 char code[10];
              printf("Your PIN has been RESET successfully.Please dial *167# to SET a new 4 Digit PIN.");
              scanf("%s",code);
              if(strcmp(code,"*167#")==0)
              {
                 char pin1[10],pin2[10];
                 printf("PIN setup\nEnter new PIN:\n");
                 scanf("%s",pin1);
                  system("cls");
                    printf("PIN setup\nConfirm new PIN:\n");
                 scanf("%s",pin2);
            if(strcmp(pin1,pin2)==0)
             {
                 if(strcmp(pin1,PIN)==0)
                 {
                     printf("New PIN must be different form Current PIN.Please check and try again.");
                     return ;
                 }
                 else
                 {
                    strcpy(PIN,pin1);
                      fprintf(ngdpoint,"%s %f",PIN,total_amount);
                     printf("PIN Saved.\nPlease remember it.\n");
                     fclose(ngdpoint);
                    main();

                 }

             }
             else
                printf("PIN Mismatch\n");

              }
               else
                system("cls");
    {
        printf("\nConnection problem of invalid MMI code\n");
        main();
    }

          }
          else
          {
              printf("Sorry! Your provided data does not match.\nPIN reset request has failed.\nPlease try again with correct  information or Call 16167 for help.\n");
              return 0;
          }

  }
  else if(number==2)
  {
      char cur_pin[5],new_pin1[5],new_pin2[5];
      printf("Enter Current PIN:");
      scanf("%s",&cur_pin);
        system("cls");
      if(strcmp(cur_pin,PIN)==0)
      {
          printf("Enter New PIN:");
          scanf("%s",&new_pin1);
            system("cls");
           printf("Confirm New PIN:");
             scanf("%s",&new_pin2);
             system("cls");
             if(strcmp(new_pin1,new_pin2)==0)
             {
                 if(strcmp(new_pin1,PIN)==0)
                 {
                     printf("New PIN must be different form Current PIN.Please check and try again.");
                     return ;
                 }
                 else{

                    int d;
                    strcpy(PIN,new_pin1);
                    fprintf(ngdpoint,"%s %f",PIN,total_amount);
                 printf("PIN Changed\n 0.Main Menu");
                 scanf("%d",&d);
                  if(d==0)
                    main();
                   else
                    return ;
                 }
             }
             else
                printf("PIN Mismatch\n");
      }
      else
printf("Wrong PIN.Please check and try again\n");
  }
  else if(number==0)
    main();
 }
  int  recharge()
    {
         trid=fopen("trids.txt","a");
          ngdpoint=fopen("PinBalance.txt","w");
        int paid;
        char a[100],pin[20];
       printf("1.Prepaid\n2.Postpaid\n0.Main Menu\n");
       scanf("%d",&paid);
       system("cls");
       printf("Enter Mobile Number:");
       scanf("%s",&a);
        system("cls");
        printf("Enter amount:");
        scanf("%f",&amount);
         system("cls");
        printf("Mobile Recharge\nTo:%s\nAmount: Tk %.2f\n",a,amount);
        printf("Enter PIN:");
        scanf("%s",&pin);
         system("cls");
        if(strcmp(pin,PIN)==0)
        {
            total_amount-=amount;
            if(total_amount>=0)
            {
                system("cls");
                 printf("Recharge of Tk %.2f To %s successfully.",amount,a);
                fprintf(trid,"Recharge of Tk %.2f To %s successfully.\n\n",amount,a);
                fclose(trid);
            }


         else
         {
               system("cls");
                total_amount+=amount;
            printf("\nInsufficient balance.Please check and try again later.\n");
         }

        }
        else
       printf("\nWrong PIN.Please check and try again\n");
        fprintf(ngdpoint,"%s %f",PIN,total_amount);
         fclose(ngdpoint);

    }

int main()
{

      ngdpoint=fopen("PinBalance.txt","r");
      trid=fopen("trids.txt","a");
      fscanf(ngdpoint,"%s %f",&PIN,&total_amount);
    char code[10];
    int number;
    printf("Enter Nagad Dial Code:");
    scanf("%s",&code);

    system("cls");
    if(strcmp(code,"*167#")==0)
    {
        printf("Nagad\n\n");
        printf("1.Cash Out\n");
        printf("2.Send Money\n");
        printf("3.Mobile Recharge\n");
        printf("4.Payment\n");
        printf("5.Bill Pay\n");
        printf("6.EMI Payment\n");
        printf("7.My Nagad\n");
        printf("8.PIN Reset\n");
        scanf("%d",&number);
        system("cls");
        if(number==1)
        Cash_Out();
        else if(number==2)
            Send_Money();
         else if(number==3)
            Mobile_Recharge();
             else if(number==4)
            Payment();
             else if(number==5)
                Bill_Pay();
             else if(number==6)
              EMI_Payment();
             else if(number==7)
           My_Nagad();
             else if(number==8)
            PIN_Reset();

    }
    else
    {
        printf("\nConnection problem or invalid MMI code\n");
        main();
    }
return 0;
}
