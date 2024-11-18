#include <iostream>

using namespace std;

int delit(int delitel, int divisor, int &remainder){
    int left=0;
    int right = delitel;
    int quotient=0;
    int mid;
    while(left<=right){
        mid = (left+right)/2;
        if(mid* divisor <= delitel){
            quotient = mid;
            left=mid+1;
        }
        else{
            right = mid - 1;
        }
    }
    remainder = delitel - (quotient * divisor);
    return quotient;
}

int main(){
    int a,b,remainder;
    int c;
    cin>>a>>b;
    if(b==0){
        cout<<"b is incorrect"<<endl;
    }
    else{
        c= delit(abs(a),abs(b),remainder);
        cout<<"quotient: "<<c<<endl;
        cout<<"remainder: "<<remainder<<endl;
    }
    return 0;
}
