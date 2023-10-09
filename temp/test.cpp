MH Utsho
#include<bits/stdc++.h>
using namespace std;
#define ll long long



void prime(int a);

bool check_palindromic(int a);

int main()
{
    int start,end;

    cin>>start>>end;

    for (int i = start; i <=end; i++)
    {
        
        prime(i); 
    }
    

    return 0;
}

void prime(int a){

    bool TorF=true;
    for (int i = 2; i <=sqrt(a); i++)
    {
        if(a%i==0 && a!=1){
            TorF=false;
            break;
        }
    }

    if(TorF && a!=1){

        if(check_palindromic(a)){
            cout<<a<<endl;
        }
        

    }
    else return;
    
}

bool check_palindromic(int a){

    if(a>=10 && a<100){

        int second=a%10;
        int first=a/10;

        if(first==second) return true;

        else return false;
        

    }

    if(a>=100 && a<1000){

        int third=a%10;
        a=a/10;
        int first =a/10;

        if(first==third) return true;

        else return false;

    }

    if(a>=1000 && a<10000){

        int forth=a%10;
           a=a/10;
        int third=a%10;
           a=a/10; 
        int second=a%10;
        int first=a/10;

        if(first==forth && second==third ) return true;

        else return false;

    }

    if(a>=10000 && a<100000){
      
       int fifth=a%10;
        a=a/10;
       int forth=a%10;
           a=a/10;
       int third=a%10;
           a=a/10; 
       int second=a%10;
       int first=a/10; 

        if(first==fifth && second==forth ) return true;

        else return false;

    }
}