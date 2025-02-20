#include <iostream>
#include <cmath>
using namespace std;

float func(float x){
    return 0.25*pow(x,3)+x-2;
}

int main(){
    float A;
    float B;
    cout<<"input A B,"<<" Example: 10 15"<<endl;
    cin>> A>> B;
    float fa=func(A);
    float fb=func(B);
    start:
    float xc= A-(fa*(B-A)/(fb-fa));
    float fc=func(xc);
    if (fc*fa>0){
        A=xc;
        fa=fc;
    }
    else{
        B=xc;
        fb=fc;
    }
    if(0.00001>fabs(((B-A)/xc))){
        cout<<"xc: "<<xc<<" "<<"fc: "<<fc<<endl; 
    }
    else{
        goto start;
    }

    return 0;
}