#include <iostream>
using namespace std;

int SumNumbers(int number, int summa=0){
    if(number<10){
        summa+=number;
        return summa;
    }
    else{
        summa+=number%10;
        return SumNumbers(number/10,summa);
    }
}

int main(){
    int a;
    cin>>a;
    cout<<SumNumbers(a);
    return 0;
}