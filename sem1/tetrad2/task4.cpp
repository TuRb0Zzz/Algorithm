#include <iostream>
#include <cmath>
using namespace std;



int main(){
    int p;
    cin>>p;
    int S=4;
    int k=1;
    int Mersen=pow(2,p)-1;
    while(k!=p-1){
        S=((S*S)-2)%Mersen;
        k++;
    } 
    if(S==0){
        cout<<"prime"<<endl;
    }
    else{
        cout<<"composite"<<endl;
    }
    return 0;
}