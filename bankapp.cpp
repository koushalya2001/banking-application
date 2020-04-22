



#include<iostream>
    #include<stdio.h>
    #include<conio.h>
    #include<bits/stdc++.h>
using namespace std;
    class date
{
int year;
int month;
int day;
public:


int operator -(date m)
{ int c;
	year=((year-m.year)-1)*12;
	month=(month)- (m.month-12);
	day=(day-m.day)/30;
         if(day<0)
		{
                  month= month-1;
                  day=(30+day)/30;

		}
     c=year+month+day;

}
friend ostream& operator <<(ostream& stream,date o);
friend istream& operator>>(istream& stream,date& o);
};


ostream& operator <<(ostream& stream,date o)
{

stream<<o.year<<"/"<<o.month<<"/"<<o.day<<endl;
return stream;
}

istream& operator >>(istream& stream,date& o)
{
    cout<<"enter the year:";
    stream>>o.year;
    cout<<"\n enter the month:";
    stream>>o.month;
    cout<<"\n enter the day:";
    stream>>o.day;
}

    class bank
    {
     private: char o;int interest;
      date ddate,mdate,cdate; float famt,iamt;
    int time;
    int account;
      queue<int>q,q1,q2,q3;

      float balance;
     char name[20];

     public:
           char type;
      bank()
        {interest=8.5;}
     void open(void);
     int deposite(int,char);
     void withdraw(int,char);
     void search(int);
     void display(void);
     void openfd()
       {
           fd_creation();
             q.push(account);
       }
       void view_fd(int j)
          {

                 if(account==j)
                   {

                cout<<"enter current date";
                cin>>cdate;
                   time=cdate-ddate;
                    for(int i=0;i<time;i++)
                     {famt= iamt+ iamt *8.5;}

          }
          }
     void fd_creation()
       {

           cout<<"ENTER YOUR NAME :  ";
         cin>>name;
          cout<<"ENTER YOUR ACCOUNT NUMBER :  ";
         cin>>account;
           cout<<"enter amount to be deposited for interest 8.5%"<<endl;
         cin>>iamt;
    //if(iamt>1000000)
         //{
          //cout<<"enter balance within 10,00,000,retry"<<endl;
        /* cin<<iamt;
          account=iamt;*/
          //}
          //else
          cout<<"enter current date"<<endl;
           cin>>ddate;
         cout<<"enter time period upto which you want to store money within 10 years"<<endl;
          cin>>time;
          for(int i=0;i<time*12;i++)
          {famt= iamt+ iamt*8.5;}

            cout<<"your deposit will mature with amount "<<famt<<endl;
             famt=iamt;
             balance=iamt;
            cout<<"thank you"<<endl;
       //}
            }
            void break_fd(int k)
              { int c;char r;
              if(account==k)
                  {cout<<"enter current date";
                cin>>cdate;
                   c=cdate-ddate;


                    for(int i=0;i<c;i++)
                     {famt= iamt+ iamt *8.5;}


                   if(c!=time)
                   {cout<<"YOU ARE PRECLOSING YOUR DEPOSIT!FINE WILL BE APPLIED,ARE YOU SURE?PRESS Y-YES,N-NO"<<endl;
                     cin>>r;
                       if(r=='y')
                      {famt=famt-famt*8.5;
                       cout<<"YOUR FINAL AMOUNT AFTER DEDUCTING FINE IS:"<<famt;
                      }
                      else
                        cout<<"YOUR DEPOSIT IS INTACT AND CURRENT DEPOSIT IS:"<<famt;
                   }
                   else
                   {
                   cout<<"YOUR FINAL DEPOSITED AMOUNT IS:"<<famt;
                    q.pop();
                   }
                  }
                  else
                  {
                      cout<<"ACCOUNT NOT FOUND"<<endl;
                  }
              }

            void deleteac(int j)
               {




                      cout<<"account deletion was successful\n\n";
                       q2.pop();



               }


    };




    void bank::open(void)

     {



           cout<<"ENTER YOUR NAME :  ";
         cin>>name;
          cout<<"ENTER YOUR ACCOUNT NUMBER :  ";
         cin>>account;
              q2.push(account);

        cout<<"ENTER THE AMOUNT OF MONEY :     ";
         cin>>balance;
     }

          int bank::deposite(int j,char c)

    {
          int bnc;

          if(account==j)

       { if(c=='s')
        {cout<<"ENTER THE AMOUNT OF MONEY :    ";
        cin>>bnc;
        balance=balance+bnc;
        cout<<"\n\n\tJOB HAS DONE WELL !!! \n";return -1;
        }
        else
            cout<<"IT IS FD"<<endl;
       }
       else
       {
           cout<<"ACCOUNT NUMBER NOT FOUND"<<endl;




       }



    }

    void bank::withdraw(int k,char t)
    {
           int blnc,p;
       if(account==k)
     {
         if(t=='s')


      {
        cout<<"YOUR CURRENT ACCOUNT BALANCE IS    "<<balance<<"\n"<<"THE AMOUNT OF MONEY YOU WANT TO WITHDRAW IS    ";
        cin>>blnc;
           p=balance-blnc;
           { if(p<0)
              cout<<"SORRY !!! THERE IS NOT ENOUGH MONEY IN YOUR ACCOUNT\n";
            else if(p>=0)
              {
                cout<<"\n\tYOUR REQUEST TO WITHDRAW MONEY HAS DONE\n\n";
                balance=p;
              }

           }
       }
       else
           cout<<"THE ACCOUNT WAS FD"<<endl;
     }
       else
       {

           cout<<"THE ACCOUNT NUMBER NOT FOUND"<<endl;
       }

    }


    void bank::display()
    { if(type=='f')
        { cout<<"FIXED DEPOSIT DETAILS";
        swap(q,q1);
        while(!q1.empty()){
		  cout<<"\n\nNAME : "<<name<<"\n\nACCOUNT NO. "<<account<<"\n\nBALANCE :    "<<balance<<"deposit date"<<ddate<<"\n\n";

         q1.pop();
		   }
        }
	  else
	    	  { cout<<"SAVINGS ACCOUNT DETAILS";
	    	    if(!q2.empty())
       {swap(q2,q3);
        while(!q3.empty()){
		  cout<<"\n\nNAME : "<<name<<"\n\nACCOUNT NO. "<<account<<"\n\nBALANCE :    "<<balance<<"\n\n";
         q3.pop();
		   }
		   }
		   else
		     cout<<"YOU HAVE NO SAVINGS ACCOUNT";
    }

    }


    void bank::search(int m)

    {

     if(account==m)
       {
         cout<<"\n\n******account Holder's INFO*******";
         cout<<"\n\nNAME : "<<name<<"\n\nACCOUNT NO. "<<account<<"\n\nBALANCE :    "<<balance<<"\n\n";
         cout<<"\n***************************************\n\n";
       }

    }

       int main()
       {char t;
      int i,j,k,m,l,y=0;
         bank b[20];
        int index;
        cout<<"HI.... DEAR CUSTOMER, WELCOME TO OUR BANK"<<endl;

          do
        {
    cout<<"\a\nPRESS 1 TO OPEN ACCOUNT\n\n"<<"PRESS 2 TO DEPOSITE AMOUNT\n\n"<<"PRESS 3 TO WITHDRAW MONEY \n\n"<<"PRESS 4 TO DISPLAY \n\n"<<"PRESS 5 TO SEARCH \n\n"<<"PRESS 6 TO view DEPOSIT"<<"PRESS 7 TO delete account \n\n PRESS 8 TO EXIT\t\n";
    cout<<"Your option.....";

    cin>>index;
               switch(index)
            {
               case 1:

                     cout<<"\nHOW MANY ACCOUNT YOU WANT TO OPEN?\n"; //opening account
                 cin>>y;
                  for(i=0;i<y;i++)
               {  cout<<"enter account type-s for savings and f for fixed deposit: ";
         cin>>b[i].type;
         if(b[i].type=='f')
         { b[i].openfd();

         }
            else
            {
                 b[i].open();
            }

               }

               break;
              case 2: int w;
                 cout<<"\nENTER YOUR ACCOUNT NO. ";
                 cin>>j;
                 for(i=0;i<y;i++)
                  {
                    w=b[i].deposite(j,b[i].type);
                    if(w==-1)
                        break;
                  }
              break;
              case 3:
                cout<<"\nENTER YOUR ACCOUNT NO. ";              //withdraw money
                cin>>k;
                for(i=0;i<y;i++)

                      {b[i].withdraw(k,b[i].type);}

                break;

              case 4:
                for(i=0;i<y;i++)
                  {                                             //display option
                  b[i].display();
                  }
                break;
              case 5:
                cout<<"\nENTER YOUR ACCOUNT NO. ";              //search option
                cin>>m;
                 for(i=0;i<y;i++)
                {
                b[i].search(m);
                }
                 break;
              case 6:
                      int o;
                      cout<<"ENTER 1 TO VIEW ";
                      cin>>o;
                      if(o==1)
                      {

                         cout<<"\nENTER YOUR ACCOUNT NO. ";              //withdraw money
                         cin>>j;
                         for(i=0;i<y;i++)
                   {
                   b[i].view_fd(j);
                   }
                      }
                      break;

             case 7: cout<<"\nENTER YOUR ACCOUNT NO. to be deleted ";
                cin>>k;
                for(i=0;i<y;i++)
                   { if(b[i].type=='s')
                      b[i].deleteac(k);
                      else
                        b[i].break_fd(k);
                      }


                break;

                default:cout<<"\nYOU HAVE PRESSED THE WRONG KEY. PLEASE TRY AGAIN. \n\n\n";

            }
           }     while(index!=8);
    }
