#include<iostream>
#include<windows.h>
using namespace std;
/*
0=Black
1=Blue
2=Green
3=Aqua
4=Red
5=Purple
6=Yellow
7=White
8=Grey
9=Light Blue
A=Light Green
B=Light Aqua
C=Light Red
D=Light Purple
E=Light Yellow
*/
int main()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 44);
    cout<<"Enter HERE   !!!!"<<endl;
    SetConsoleTextAttribute(hConsole, 10);
    cout<<"Enter HERE   !!!!"<<endl;
    SetConsoleTextAttribute(hConsole, 11);
    cout<<"Enter HERE   !!!!"<<endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Enter HERE   !!!!"<<endl;
    SetConsoleTextAttribute(hConsole, 13);
    cout<<"Enter HERE   !!!!"<<endl;
    SetConsoleTextAttribute(hConsole, 0x74);
    cout<<"Enter HERE   !!!!"<<endl;

    int arr[4]={12,44,56,77};
    cout<<arr[0]<<endl;
    cout<<arr[1]<<endl;
    cout<<arr[2]<<endl;
    cout<<arr[3]<<endl;
    cout << "This is normal ";
SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 0x4A);
cout << "and this is green";
}
