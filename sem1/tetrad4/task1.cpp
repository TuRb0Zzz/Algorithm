#include <iostream>
using namespace std;

int NOD(int a,int b){
    int oct;
    if(a%b==0){
        return b;
    }
    if(a>b){
        oct=a%b;
        return NOD(b,oct);
    }
    else if(b>a){
        oct=b%a;
        return NOD(a,oct);
    }
    return 0;
}


int main(){
    int a,b;
    cin>>a>>b;
    cout<<NOD(a,b);
    return 0;
}