#include <iostream>
#include <cmath>
using namespace std;

double func(double x){
    return 0.25*pow(x,3)+x-2;
}

int main(){
    double A;
    double B;
    cout<<"input A B,"<<" Example: 10 15"<<endl;
    cin>> A>> B;
    double fA= func(A);
    double fB= func(B);

    start:
    double xc= (A+B)/2;
    double fc= func(xc);
    if (fc*fA>0){
        A=xc;
        fA=fc;
    }
    else{
        B=xc;
        fB=fc;
    }
    
    if(0.000001>fabs((B-A)/xc)){
        cout<<"xc: "<<xc<<" "<<"fc: "<<fc<<endl; 
    }
    else{
        goto start;
    }
    return 0;
}
