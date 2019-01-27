#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>

using namespace std;
void checka();      //to confirm admin's ID & password
void admin();       //function of admin's powers
void checkv();      //to check and confirm voter's ID & password
void start();           //default start screen of EVM++
void status();          //to show percentage of voting
class voter
{
    char name[50];
    int id;
    char password[50];
public:
    void getdata()  //get voter's data
    {
        cout<<"Enter Voter Name:";
        cin>>name;
        cout<<"Enter Voter ID:";
        cin>>id;
        cout<<"Enter Voter's Password: ";
        cin>>password;
    }
    void display()  //display any voter's data
    {
        cout<<"Voter Name: "<<name<<endl;
        cout<<"Voter ID: "<<id<<endl;
        cout<<"Voter Password: "<<password<<endl;
    }
    int find_id(int a)  //to confirm a searched ID from file
    {
        if(a==id)
        {
            return 1;
        }
        else
        {   return 0;   }
    }
    int conf_pass()     //confirm password to the respective ID of voter
    {
        int a;
        char pass[30];
        cout<<"Enter your Password : ";
        cin>>pass;
        (strcmp(pass,password)==0)?(a=1):(a=2);
        return a;
    }
    int id1()   //to return ID of voter
    {
        return id;
    }
}v1;    //one oblect of class voter

class votes
{
    char name[50];
    int BJP;
    int Congress;
    int AAP;
    int Shivsena;
    int RJD;
    int JDU;
    int Trinamool;
public:
    void take() //take vote of voter
    {
        int ch;
        cout<<"1.BJP\t\t2.Congress\t\t3.AAP\n4.Shivsena\t\t5.RJD\n6.JDU\t\t7.Trinamool Congress"<<endl;
        cout<<"Vote to : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            BJP++;
            break;
        case 2:
            Congress++;
            break;
        case 3:
            AAP++;
            break;
        case 4:
            Shivsena++;
            break;
        case 5:
            RJD++;
            break;
        case 6:
            JDU++;
            break;
        case 7:
            Trinamool++;
            break;

        default:
            cout<<"Choose proper party !"<<endl;
        }
    }

    void evm_result()   //to display the result of election
    {
        cout<<"ELECTION RESULT "<<name;
        cout<<"Number of votes of each party are :"<<endl;
        cout<<"BJP : "<<BJP<<endl;
        cout<<"Congress : "<<Congress<<endl;
        cout<<"AAP : "<<AAP<<endl;
        cout<<"Shivsena : "<<Shivsena<<endl;
        cout<<"RJD : "<<RJD<<endl;
        cout<<"JDU : "<<JDU<<endl;
        cout<<"Trinamool Congress : "<<Trinamool<<endl;
    }

    void tkname()   //take name (year) of election
    {
        cout<<"Enter Year of Election : ";
        cin>>name;
    }
}vote;

int voted[100]={0};     //array to store the IDs of voted voters so they cannot vote twice
int i=0;    //general purpose variable

int main()
{
    fstream file;   //object of class fstream
    file.open("Voters++.txt", ios::in | ios::out | ios::binary );   //open Voters++.txt file (Voter's database)
    fstream file2;
    file2.open("Votes++.txt", ios::app | ios::in | ios::out | ios::binary );    //open Votes++.txt file (for storing and reading votes)

    cout<<"-------------------------------Welcome to EVM ++--------------------------------"<<endl;
    checka();
    start();
}

void start()
{
    int ch;
    fstream file2;
    file2.open("Votes++.txt", ios::in | ios::out | ios::binary );
    cout<<"1. Press the ballot button\n2. Show the Voting Percentage\n3. Stop the EVM++"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
        checkv();
        break;

    case 2:
        status();
        break;

    case 3:
        vote.evm_result();
        //write the election result i.e. votes of each party to Votes++.txt file
        file2.seekp(0,ios::end);
        file2.write((char*) &vote,sizeof(vote));
        exit(0);
        break;

    default:
        cout<<"Make proper choice .";
        start();
    }
}

void checkv()
{
    int j;
    fstream file;
    file.open("Voters++.txt", ios::in | ios::out | ios::binary );
    int n,flag=4,flag2; //flag to confirm matching of searched ID and flag2 to confirm matching of Voter's password
    cout<<"Enter your Voter ID : ";
    cin>>n;
    file.seekg(0);  //place get cursor at start of file
    while(!file.eof())  //search till end of file(EOF)
    {
        file.read((char*)&v1,sizeof(v1));
        flag=v1.find_id(n);
        if(flag==1)
        {
            j=0;
            while(j<=100)   //100 is just arbitary constant to search whole array
            {
                if(voted[j]==n) //to check in voted array if voter has already voted
                {
                    cout<<"Get Out !!!!! You cannot vote TWICE !!!! "<<endl;
                    start();
                }
                j++;
            }
            flag2=v1.conf_pass();   //confirming voter's password
            if(flag2==1)
            {
               vote.take(); //take the vote of voter
               voted[i]=v1.id1();   //storing ID of voter who has voted
               i++;
               start(); //again going back to start screen of EVM++
               break;
            }
            else
            {
                cout<<"Incorrect Password !"<<endl<<endl;
                checkv();   //if password is incorrect then again it asks for login of voter
            }
        }
    }
    if(flag==0)
    {
         cout<<"\nVoter ID invalid."<<endl<<endl;
         checkv();  //if Voter ID is wrong again asks for login of voter
     }
}

void checka()
{
    int adminid=9597,n;         //fixing administrator's ID & password
    char adminpass[]="Admin4444",pass[20];
    cout<<"Enter Administrator's ID ; ";
    cin>>n;
    cout<<"Enter Administator's Password : ";
    cin>>pass;
    if( n==adminid && strcmp(adminpass,pass)==0 )   //matching administrator's ID & password
    {
        admin();
    }
    else
    {
        cout<<"Incorrect ID or Password ."<<endl;
        checka();   //again ask for admin's login if any one is incorrect
    }
}

void admin()
{
    int ch;
    //opening both files
    fstream file;
    file.open("Voters++.txt", ios::in | ios::out | ios::binary );
    fstream file2;  //for viewing already stored result of EVM++
    file2.open("Votes++.txt", ios::in | ios::out | ios::binary );
    vote.tkname();  //taking year as name of election
    system("PAUSE");
    cout<<"Make a choice ADMIN : "<<endl;
    cout<<"1. Start the EVM++\n2. See all Voter's list\n3. View result of previous election\n4. Exit"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
        break;

    case 2: //display all voters
        file.seekg(0);
        while (!file.eof()) //search till end of file
        {
            file.read((char*) &v1,sizeof(v1));  //store the 1st object of class voter in v1 object
            v1.display();   //display voter
            cout<<endl;
        }
        file.clear();   //close file
        break;

    case 3:
        file2.seekg(0); //put the get cursor at start of file
        while(!file2.eof())
        {
            file2.read((char*)&vote,sizeof(vote));
            vote.evm_result();
        }
        cout<<endl;
        break;

    case 4:
        exit(0);

    default:
        cout<<"Make appropriate choice : "<<endl;
        admin();
    }
}

void status()
{
    fstream file;
    file.open("Voters++.txt", ios::in | ios::out | ios::binary );
    file.seekg(0,ios::end); //put get cursor at start of file
    float z=file.tellg();   //get the end position of file
    //below logic is given in Lafore book to count total number of voters
    float total=z/sizeof(v1);
    int percentage=(i/total)*100;
    cout<<"Total Voters : "<<total<<" No. of voters voted : "<<i<<endl;
    cout<<percentage<<"% voting has been done till now. "<<endl;
}
