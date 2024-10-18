#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int number;
    cin>>number;
    vector<int> a(number-1);
    vector<int> b;
    for(int i=2;i<=number;i++){
        a[i-2]=i;
    }
    for(int i=0;i<number-1;i++){
        if(a[i]==0){continue;}
        for(int j=i+1;j<number-2;j++){
            if(a[j]%a[i]==0){
                a[j]=0;
            }
        }
    }
    for(int i=0;i<number-1;i++){
        if (a[i]!=0){
            b.push_back(a[i]);
        }
    }
    int count=0;
    while(number>1){
        for(int i=0;i<b.size();i++){
            if(number%b[i]==0){
                count=0;
                while(number%b[i]==0){
                    count++;
                    number=number/b[i];
                }
                if (count>1){
                    cout<<b[i]<<"^"<<count;
                }
                else{
                    cout<<"*"<<b[i];
                }
            }
        }
    }
    return 0;
}