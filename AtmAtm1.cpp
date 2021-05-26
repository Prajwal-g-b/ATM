#include<iostream>
using namespace std;
class ATM{
    private:
            string name;
            int i=0, j=0,n=0,pin,pin1,pin2,pin3;
            double accno=0;
			int camount=0;
			int t[20],a[20];
            int amount=0;
            int total=100,ctotal=50;
    public:
    	 int Pin=123456;
    	 int Otp = 1234,cur;
    	 
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
                    if(cur==1)
                    cout<<"\tCurrent account Balance:$"<<ctotal<<endl;
                    if(cur==2)
                    cout<<"\tSavings account Balance:$"<<total<<endl;
                    
                }
            void deposit()
                {
                	
                     
                     switch(cur)
					 {
                     	case 2:
                     		cout<<"\tEnter amount to be Deposited:$";
                     		cin>>amount;
                     		total+=amount;
                     		cout<<"\tAvailable balance is $"<<total<<"\n"<<endl;
                     		t[j]=1;
                     		a[i]=amount;
                     		i++;
                     		j++;
                     		n++;
                     		break;
                     case 1:
                     		cout<<"\tEnter amount to be Deposited:$";
                     		cin>>camount;
                     		ctotal+=camount;
                     		cout<<"\tAvailable balance is $"<<ctotal<<"\n"<<endl;
                     		t[j]=3;
                     		a[i]=camount;
                     		i++;
                     		j++;
                     		n++;
                     
                     		break;
                     
                 }
                    
                }
            void showbal()
                {
                	if(cur==2)
                    cout<<"\tTotal Savings Balance is: $"<<total<<"\n"<<endl;
                    else
                    cout<<"\tTotal Current Balance is: $"<<ctotal<<"\n"<<endl;
                    
                }
            void withdrawl()
                {
                	
                     switch(cur)
					 {
                     	case 2:
                    
                    		cout<<"\tEnter amount to be Withdrawn $";
                        	cin>>amount;
                        	if(total<amount||total==0)
							{
                         		cout<<"\tYou dont have enough money";
                         	}
							else
							{
                         		cout<<"         Enter your PIN:";
        						cin>>pin;
        						if (pin==Pin)
								{        					
                         			total=total-amount;
                         			cout<<"\t Collect your cash..........\n\n";
                         			cout<<"\t Available balance is $"<<total<<"\n"<<endl;
                         			t[j]=0;
                         			a[i]=amount;
                        			 i++;
                        			 j++;
                        			 n++;
                     			}
                        		else
								{
                        			cout<<"\tInvalid PIN"<<endl;
                        		}
                     		} 
                            break;
                     case 1:
                     		
                        	cout<<"\tEnter amount to be Withdrawn $";
                        	cin>>camount;
                           	cout<<"         Enter your PIN:";
        					cin>>pin;
        					if (pin==Pin)
							{
                         		ctotal=ctotal-camount;
                         		cout<<"\t Collect your cash..........\n\n";
                         		cout<<"\t Available balance is $"<<ctotal<<"\n"<<endl;
                         		t[j]=2;
                        		a[i]=camount;
                         		i++;
                         		j++;
                        		n++;
                     		}
                        	else
							{
                        		cout<<"\tInvalid PIN"<<endl;
                     		}
                     	 	break;
                     	
                     	
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
                                  cout<<"\t"<<i+1<<".Amount Deposit at Savings account is $"<<a[i]<<endl;
                              }
							  else if(t[j]==2)
                              {
                                  cout<<"\t"<<i+1<<".Amount Withdrawl at Current account is $"<<a[i]<<endl;
                              }
							  else if(t[j]==3)
                              {
                                  cout<<"\t"<<i+1<<".Amount deposit at Current account is $"<<a[i]<<endl;
                              }
							  else if(t[j]==5)
                              {
                                  cout<<"\t"<<i+1<<".PIN change"<<endl;
                              } 
							  else{
                                  cout<<"\t"<<i+1<<".Amount Withdrawl at Savings account is $"<<a[i]<<endl;
                              }
                         
                      }
                      i=j;
                      switch(cur)
                      {case 2:
                      cout<<"\tAvailable savings balance is $"<<total<<"\n"<<endl;
                      break;
                      case 1:
                      cout<<"\tAvailable current balance is $"<<ctotal<<"\n"<<endl;
                      break;
                  }
                }
            }
            void account()
            {
            cout<<"\t1.Current account:\n\t2.Savings account\n\tEnter your choice:";
            cin>>cur;
			}
                void PIN()
				{
                	cout<<"\n\tEnter your current pin:";
                   	cin>>pin1;
                   	if (pin1==Pin)
					{
                   		cout<<"\n\tEnter the new PIN:";
                   		cin>>pin2;
                   		cout<<"\n\tEnter the PIN again:";
                   		cin>>pin3;
                   		cout<<"\n\tSuccessfully changed your pin";
                   		
                   		if(pin3==pin2)
						{
                   			Pin=pin3;
							   t[j]=5;
							   a[i]=0;
							   j++;
							   i++;
							   n++;                   		
					   	}
                   	 }
				  	 else
				   	cout<<"\n\tInvalid PIN";
                	
				}
            };

int main()
{

	
	system("Color 3E");
    ATM b;
    int choice;
    int count=1,otp,pin,ch;
    while(1)
    {
    	cout<<"\n\t************** Welcome to OOC Bank ******************\n";
        b.setvalue();
        cout<<"\n\t           1.Card less Transactions:";
        cout<<"\n\t           1.Card Transactions:";
        
        cout<<"\n\t           Enter your choice:";
        cin>>ch;
        switch(ch)
		{
        	case 1:
        		cout<<"\n\t           Enter the OTP received on your mobile:";
        		cin>>otp;
        		break;
        	case 2:
        		cout<<"\n\t            Enter PIN:";
        		cin>>pin;
        		break;
        	default:cout<<"\n\t   Invalid Choice";
        
        		break;
    	}
    	b.account();
        do{
        	
        	if(pin == b.Pin||otp==b.Otp)
        	{
        	
            if (!(b.cur==1||b.cur==2))
            {
            	cout<<"\n\tInvalid choice";
            	return 0;
			}
        cout<<"\n\t*********************** MENU ***********************\n";
        
        cout<<"\t*           1.Account Info                         *\n";
        cout<<"\t*           2.Deposit Amount                       *\n";
        cout<<"\t*           3.Withdraw Amount                      *\n";
        cout<<"\t*           4.Show Balance                         *\n";
        cout<<"\t*           5.Recent Transactions                  *\n";
        cout<<"\t*           6.Pin Change                           *\n";
        cout<<"\t*           7.EXIT                                 *\n";
        cout<<"\n\t*****************************************************\n";
        cout<<"\t          Enter your choice:";
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
                   b.PIN();
                   
                   break;
            case 7:
                   cout<<"\n************Thank you for visiting************\n"<<endl;
                   exit(1);
                   break;
            default:
                    cout<<"\n Invalid choice\n";
                    
                    
        }
    }
    else
    {
    	if(ch==1){
		cout<<"\tPlease enter a valid OTP:";
    		cin>>otp;
    		
		}
		else
		{
    		cout<<"\tPlease enter a valid PIN:";
    		cin>>pin;
		}
    	count++;

    }
    

}while(count!=3);
    if(count==3)
    cout<<"\tExceed  the limit,Please try later";
	cout<<"\n************Thank you for visiting************\n"<<endl;
                   exit(1);
    
}
    return 0;
}
