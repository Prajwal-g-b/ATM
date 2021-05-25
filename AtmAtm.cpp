#include<iostream>
using namespace std;
class ATM{
    private:
            string name;
            int i=0, j=0,n=0,pin;
            double accno=0;
            int a[10] ,t[10];

            int amount=0;
            int total=100;
    public:
            void setvalue()
            {
                cout<<"\n\t                  Enter name:";
                cin>>name;
                cout<<"\n\t                  Enter account no:";
                cin>>accno;
                
            }
            void showdata()
                {
                    cout<<"\tName:"<<name<<endl;
                    cout<<"\tAccount no:"<<accno<<endl;
                    cout<<"\tBalance:$"<<total<<endl;
                    
                }
            void deposit()
                {
                     if(accno!=0){
                     cout<<"\tEnter amount to be Deposited:$";
                     cin>>amount;
                     total+=amount;
                     cout<<"\tAvailable balance is $"<<total<<"\n"<<endl;
                     t[j]=1;
                     a[i]=amount;
                     i++;
                     j++;
                     n++;
                     } else{
                        cout<<"\tPlease enter your account details"<<endl;
                     }
                    
                }
            void showbal()
                {
                    cout<<"\tTotal Balance is: $"<<total<<"\n"<<endl;
                    
                }
            void withdrawl()
                {
                    if(accno!=0){
                        cout<<"\tEnter amount to be Withdrawn $";
                        cin>>amount;
                        if(total<amount||total==0){
                         cout<<"\tYou dont have enough money";
                         } else {
                         	cout<<"         Enter your PIN:";
        					cin>>pin;
        					if(pin==123456)
        					{
                         total=total-amount;
                         	cout<<"\t Collect your cash..........\n\n";
                         cout<<"\t Available balance is $"<<total<<"\n"<<endl;
                         t[j]=0;
                         a[i]=amount;
                         i++;
                         j++;
                         n++;
                        }}
                     } else{
                        cout<<"\tInvalid PIN"<<endl;
                     }
                    
                }
                void miniStatement()
                {
                  cout<<"\n\t********************Transactions*******************\n";
                  if(a[0]!=0)
                  {
                    cout<<"\tName: "<<name<<endl;
                    cout<<"\tAccount no: "<<accno<<endl;
                      for (j=0;j<n;++j){
                          i=j;
                              if(t[j]==1)
                              {
                                  cout<<"\tAmount Deposit at "<<i+1<<" is $"<<a[i]<<endl;
                              } else{
                                  cout<<"\tAmount Withdrawl at "<<i+1<<" is $"<<a[i]<<endl;
                              }
                         
                      }
                      i=j;
                      cout<<"\tAvailable balance is $"<<total<<"\n"<<endl;
                  }
                }
            };

int main()
{

	
	system("Color 3E");
    ATM b;
    int choice;
    int count=1,Pin=123456,pin;
    while(1)
    {
    	cout<<"\n\t****************** Welcome to ATM ******************\n";
        b.setvalue();
        cout<<"\n\t                  PIN:";
        cin>>pin;
        do{
        	if(pin ==Pin)
        	{
        cout<<"\n\t*********************** MENU ***********************\n";
        
        cout<<"\t*           1.Account Info                         *\n";
        cout<<"\t*           2.Deposit Amount                       *\n";
        cout<<"\t*           3.Withdraw Amount                      *\n";
        cout<<"\t*           4.Show Balance                         *\n";
        cout<<"\t*           5.Recent Transactions                  *\n";
        cout<<"\t*           6.EXIT                                 *\n";
        cout<<"\n\t*****************************************************\n";
        cout<<"\tEnter your choice";
        cin>>choice;
        
		
        switch(choice)
        {
            case 1:
                    b.showdata();
                    break;
            case 2:
                   b.deposit();
                   break;
            case 4:
                   b.showbal();
                   break;
            case 3:
                    b.withdrawl();
                    break;
            case 5:
                   b.miniStatement();
                   break;
            case 6:
                   cout<<"\n************Thank you for visiting************\n"<<endl;
                   exit(1);
                   break;
            default:
                    cout<<"\n Invalid choice\n";
                    
                    
        }
    }
    else
    {
    cout<<"Please enter a valid PIN"<<endl;
    cin>>pin;
    count++;
    }
    
        
    }while(count!=3);
    if(count==3)
    cout<<"Exceed  the limit,Please try later";
	cout<<"\n************Thank you for visiting************\n"<<endl;
                   exit(1);
    
}
    return 0;
}
