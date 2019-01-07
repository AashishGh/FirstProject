#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;
void display()
{cout<<"Options:"<<endl<<"1.Create Acoount"<<endl<<"2.User LogIn"<<endl<<"3.Exit";
cout<<"\n"<<setw(20)<<"Enter your Choice";}

class Account{
    string usrname,password;
    public:
void CreateAccount(){
    cout<<"Enter Username:";
    cin>>usrname;
    cout<<"\n Enter password";
    cin>>password;
}
string Username(){return usrname;}
string Password(){return password;}
};

int main()
{char ch[20];
int choice,recordstatus=0;
string usrname,pasword;
Account ac;
fstream file("ListOfAccounts.txt",ios::ate|ios::in|ios::out|ios::binary);
do { system("cls");
display();
cin>>choice;
//choices_Starts_here
//Choice1_SignUp:
if (choice==1)
{system("cls");
cout<<"\nCreating new Account\n";
ac.CreateAccount();
file.seekp(0,ios::end);
file.write((char*)&ac,sizeof(ac));
}
//LogIn:
else if(choice==2)
{system("cls");
cout<<"\nEnter Username:";
cin>>usrname;
cout<<"\nEnter Password:";
cin>>pasword;
file.seekg(0,ios::beg);
file.read((char*)&ac,sizeof(ac));
while(file.eof()==0){
if (usrname==ac.Username() && pasword==ac.Password()){
    cout<<"You are logged in successfully !!";
    recordstatus=1;
    break;
}
file.read((char*)&ac,sizeof(ac));}
 if (recordstatus==0){cout<<"\nInvalid Username or Password;}
}
else if(choice==3){cout<<"\n"<<setw(32)<<"WE ARE EXITING";}
else{cout<<"\n"<<setw(32)<<"Invalid Option!! TryAgain!!";}
} while(choice!=1 && choice!=2 && choice!=3);

getch();
return 0;
}
