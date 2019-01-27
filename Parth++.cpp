#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

class voter
{
    char name[50];
    int id;
    char password[50];
    int co;
public:
    void getdata()
    {
        cout<<"Enter Voter Name:";
        cin>>name;
        cout<<"Enter Voter's Password: ";
        cin>>password;
        cout<<"Enter Voter ID:";
        cin>>id;
        co=1;
    }
    void display()
    {
        cout<<"Voter Name: "<<name<<endl;
        cout<<"Voter ID: "<<id<<endl;
        cout<<"Voter Password: "<<password<<endl;
        cout<<"Chances of voting : "<<co<<endl;
    }
    int find_id(int a)
    {
        if(a==id)
        {
            return 1;
        }
        else
        {   return 0;   }
    }
    int id1()
    {
        return id;
    }
}v1;

int main()
{
    int ch,flag=0,n;
    char c;
    fstream file;
    file.open("Voters++.txt", ios::app | ios::out | ios::in | ios::binary);
    do
    {
        cout<<"Make a choice Administrator : "<<endl;
        cout<<"1. Add a voter\n2. Search a voter\n3. Display all voter\n4. Exit"<<endl;
        cin>>ch;
        cout<<"SIze of obj : "<<sizeof(v1);
        switch(ch)
        {
    case 1:
        v1.getdata();
        file.seekp(0,ios::end);
        file.write((char*) &v1,sizeof(v1));
        cout<<"Voter added successfully !!!!"<<endl;
        break;

    case 2:
        cout<<"Enter Voter ID : ";
        cin>>n;
        file.seekg(0);
        while(!file.eof())
        {
            file.read((char*)&v1,sizeof(v1));
            flag=v1.find_id(n);
            if(flag==1)
            {
                v1.display();
                break;
            }
        }
        if(flag==0)
        {
             cout<<"\nVoter does not exist."<<endl;
             file.clear();
             break;
        }
        break;

    case 3:
        file.seekg(0);
        while (!file.eof())
        {
            file.read((char*) &v1,sizeof(v1));
            cout<<"test1";
            v1.display();
            cout<<endl<<"test2"<<endl;
        }
        file.clear();
        break;

    case 4:
        cout<<"See you again !"<<endl;
        break;

        //file.seekg(0);
        //file.seekp(0);
 /*               if(i==v1.id1())
                {
                    z=file.tellg();
                    v1.getdata();
                    file.seekp(z);
                    file.write((char*) &v1,sizeof(v1));
                    break;
                }   */

    default:
        cout<<"Wrong Choice . Enter again!";
        break;
    }
    cout<<endl<<"do another ? (y/n) : ";
    cin>>c;
    }while(c!='n');
cout<<"Over and Out....";
}
