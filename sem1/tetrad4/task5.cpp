#include <iostream>
using namespace std;

int func(int n){
    if(n==1){
        return 1;
    }
    else{
        if(n%2==0){
            return func(n/2);
        }
        else{
            return func((n-1)/2) + func((n-1)/2+1);
        }
    }
}


int main(){
    int n;
    cin>>n;
    cout<<func(n);
    return 0;
}