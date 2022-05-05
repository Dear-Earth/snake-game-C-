#include<iostream>
#include<Windows.h>
using namespace std;

int main(){
    int h,m,s;
    int d=1000;//we add delay of 1000 milliseconds and we will use it in the function sleep;
    cout<<"Set time:\n";
    cin>>h>>m>>s;
    if (h>12||m>60||s>60)
    {
        cout<<"ERROR!\n";
        exit(0);
    }
    while(true)//this is an infinite loop and anything inside will repeat itself to infinity;
    {
        s++;
        if (s>59)
        {
            m++;
            s=0;
        }
        if(m>59){
            h++;
            m=0;
        }
        if (h>12)
        {
            h=1;
        }
        cout<<"\n Clock:";
        cout<<"\n "<<h<<":"<<m<<":"<<s;
        // this writes the time in this format 00:00:00;
        Sleep(d);// the function sleep slows down the while loop and make it more like a real clock;
        system("cls");// this clears the screen;
        
        
    }
    
    return 0;
}