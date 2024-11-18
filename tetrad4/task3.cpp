#include <iostream>
#include <cmath>
using namespace std;

double func(double x){
    return 0.25*pow(x,3)+x-2;
}

double solve(double A, double B, double fA, double fB){
    double xc= (A+B)/2;
    double fc= func(xc);
    if(0.000001>fabs((B-A)/xc)){
        return xc; 
    }
    if (fc*fA>0){
        return solve(xc,B,fc,fB);
    }
    else{
        return solve(A,xc,fA,fc);
    }
}


int main(){
    double a1,b1;
    cin>>a1>>b1;
    cout<<solve(a1,b1,func(a1),func(b1));
    return 0;
}
