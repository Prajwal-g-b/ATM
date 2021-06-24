#include<iostream>
#include<windows.h> 		//to add background color
#include<dos.h>			//to add background color
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
                cout<<"\n\t                  Enter name:";		//input name
                cin>>name;
                cout<<"\n\t                  Enter account no:";		//input account no.
                cin>>accno;
                
            }
            
                void miniStatement()
                {
                  cout<<"\n\t********************Transactions*******************\n";
                  if(t[0]!=0)
                  {
                    cout<<"\tName: "<<name<<endl;
                    cout<<"\tAccount no: "<<accno<<endl;
                      for (j=0;j<n;++j){   								//print thetransactions
                          i=j;
                              if(t[j]==1) 								//print the Amount Deposit at Savings
                              {
                                  cout<<"\t"<<i+1<<".Amount Deposit at Savings account is $"<<a[i]<<endl;
                              }
							  else if(t[j]==2)							//print the Amount withdraw at current
                              {
                                  cout<<"\t"<<i+1<<".Amount Withdrawl at Current account is $"<<a[i]<<endl;
                              }
							  else if(t[j]==3) 								//print the Amount Deposit at current
                              {
                                  cout<<"\t"<<i+1<<".Amount deposit at Current account is $"<<a[i]<<endl;
                              }
							  else if(t[j]==5) 								//print the pin changed
                              {
                                  cout<<"\t"<<i+1<<".PIN change"<<endl;
                              } 
							  else if(t[j]==0){	 								//print the Amount withdraw at Savings
                                  cout<<"\t"<<i+1<<".Amount Withdrawl at Savings account is $"<<a[i]<<endl;
                              }
                         
                      }
                      i=j;
                      if(cur==2)															//savings account is activated
                      		cout<<"\tAvailable savings balance is $"<<total<<"\n"<<endl;
                      else																	//current account is activated
	                      	cout<<"\tAvailable current balance is $"<<ctotal<<"\n"<<endl;
                      
                  
                }
            }
            void showdata()
                {
                    cout<<"\tName:"<<name<<endl;			//input name
                    cout<<"\tAccount no:"<<accno<<endl;		//input account number
                    if(cur==1)											//current account is activated
                    cout<<"\tCurrent account Balance:$"<<ctotal<<endl;
                    if(cur==2)											//savings account is activated
                    cout<<"\tSavings account Balance:$"<<total<<endl;
                    
                }
            void deposit()
                {
                	
                     
                     
                     	if(cur==2)   //savings account is activated
						 {  
						 
                     		cout<<"\tEnter amount to be Deposited:$";
                     		cin>>amount;   //amount is inputted
                     		total+=amount;  //ammount is added to total ballance
                     		cout<<"\tAvailable balance is $"<<total<<"\n"<<endl;  //balance is outputputted
                     		t[j]=1;  //it stores tansactions type
                     		a[i]=amount;	//it stores tansactions amount
                     		i++;
                     		j++;
                     		n++;
                     		}
                     else{         //current is activated
                     		cout<<"\tEnter amount to be Deposited:$";
                     		cin>>camount;
                     		ctotal+=camount;	//ammount is added to total ballance
                     		cout<<"\tAvailable balance is $"<<ctotal<<"\n"<<endl;	//balance is outputputted
                     		t[j]=3;			//it stores tansactions type
                     		a[i]=camount;	//it stores tansactions amount
                     		i++;
                     		j++;
                     		n++;
                 }
                     		
                     
                 
                    
                }
            void showbal()
                {
                	if(cur==2)		//if savings account is selected
                    cout<<"\tTotal Savings Balance is: $"<<total<<"\n"<<endl;
                    
                    else			//if current account is selected
                    cout<<"\tTotal Current Balance is: $"<<ctotal<<"\n"<<endl;
                    
                }
            void withdrawl()
                {
                	
                     if(cur==2){		//if savings account is selected
                    		cout<<"\tEnter amount to be Withdrawn $";
                        	cin>>amount;
                        	if(total<amount||total==0) //checks if amount is less than the balance
							{
                         		cout<<"\tYou dont have enough money";
                         	}
							else
							{
                         		cout<<"         Enter your PIN:";
        						cin>>pin;
        						if (pin==Pin)		//checks for correct pin
								{        					
                         			total=total-amount;		//amount is reduced from total balance
                         			cout<<"\t Collect your cash..........\n\n";
                         			cout<<"\t Available balance is $"<<total<<"\n"<<endl;
                         			t[j]=0;			//it stores tansactions type
                         			a[i]=amount;		//it stores tansactions amount
                        			 i++;
                        			 j++;
                        			 n++;
                     			}
                        		else			//if pin is invalid
								{
                        			cout<<"\tInvalid PIN"<<endl;
                        		}
                     		} 
                            }
                     else{			//if current account is selected
                        	cout<<"\tEnter amount to be Withdrawn $";
                        	cin>>camount;
                           	cout<<"         Enter your PIN:";
        					cin>>pin;
        					if (pin==Pin)		//checks for correct pin
							{
                         		ctotal=ctotal-camount;		//amount is reduced from total balance
                         		cout<<"\t Collect your cash..........\n\n";
                         		cout<<"\t Available balance is $"<<ctotal<<"\n"<<endl;
                         		t[j]=2;		//it stores tansactions type
	                        		a[i]=camount;		//it stores tansactions amount
	                         		i++;
                         		j++;
                        		n++;
                     		}
                        	else		//if pin is invalid
							{
                        		cout<<"\tInvalid PIN"<<endl;
                     		}
                     	 	}
                     	
                     	
                	
                }
                
            		void account() //choose whether the account is savings or the current
            			{
            				cout<<"\n\t\t\t1.Current account\n\t\t\t2.Savings account\n\t\t\tEnter your choice:";
            				cin>>cur;
						}
						
						
                void PIN()			//pin change
				{
                	cout<<"\n\tEnter your current pin:";
                   	cin>>pin1;								//enter old pin
                   	if (pin1==Pin)
					{
                   		cout<<"\n\tEnter the new PIN:";		//enter the new pin
                   		cin>>pin2;
                   		cout<<"\n\tEnter the PIN again:";   //enter the new pin again
                   		cin>>pin3;
                   		
                   		
                   		if(pin3==pin2)						//check for the both pins match or not
						{
							cout<<"\n\tSuccessfully changed your pin";
                   			Pin=pin3;
							   t[j]=5;						//stores the transaction
							   a[i]=0;						//stores the value of transaction
							   j++;
							   i++;
							   n++;                   		
					   	}
					   	else									//if pin did not match
				   			cout<<"\n\t PIN did not match";
                   	 }
				  	 else											//if pin did not match
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
        b.setvalue(); 	//enter the account details
        b.account();	//enter whether its current or savings
        
        cout<<"\n\t               1.Card less Transactions:";
        cout<<"\n\t               2.Card Transactions:";
        
        
        cout<<"\n\t               Enter your choice:";	//inputs the type of transaction
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
    	
        do{
        	
        	if(pin == b.Pin||otp==b.Otp)//check the pin or otp is correct
        	{
        	
            if (!(b.cur==1||b.cur==2))	//if other than current and savings is selected it will exit
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
                    b.showdata();  //it will display data
                    break;
            case 2:
                   b.deposit();		//call the deposit function
                   break;
            case 4:
                   b.showbal();		//show the ballence
                   break;
            case 3:
                    b.withdrawl();  //withdrawl the amount
                    break;
            case 5:
                   b.miniStatement();  //transaction the amount
                   break;
            case 6:
                   b.PIN();				// change the pin
                   
                   break;
            case 7:
                   cout<<"\n************Thank you for visiting************\n"<<endl;
                   cout<<"\n*******************Visit again****************\n"<<endl;
                   exit(1);
                   break;
            default:
                    cout<<"\n Invalid choice\n";
                    
                    
        }
    }
    else
    {
    	if(ch==1){								//input the otp
		cout<<"\tPlease enter a valid OTP:";
    		cin>>otp;
    		
		}
		else								//input the pin
		{
    		cout<<"\tPlease enter a valid PIN:";
    		cin>>pin;
		}
    	count++;										//incriment the time of the pin enter

    }
    

}while(count!=4);  									//given 3 attempts for the wrong pin
    if(count==4)
    cout<<"\tExceed  the limit,Please try later";
	cout<<"\n************Thank you for visiting************\n"<<endl;
                   exit(1);
    
}
    return 0;
}
