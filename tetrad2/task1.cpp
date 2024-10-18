#include <iostream>
using namespace std;

int* ReturnMax(int *a,int *b, int *c, int *d){
    int num=max(max(*a,*b),max(*c,*d));
    if (*a==num){
        return a;
    }
    if (*b==num){
        return b;
    }
    if (*c==num){
        return c;
    }
    if (*d==num){
        return d;
    }
}

int ReturnMin(int a,int b, int c, int d){
    return min(min(a,b),min(c,d));
}

int main(){
    int a,b,c,d;
    cin>> a>>b>>c>>d;

    int *p;
    int minimum;
    while(not(a==b and a==c and a==d)){
        int *p = ReturnMax(&a,&b,&c,&d);
        minimum=ReturnMin(a,b,c,d);
        *p = *p-minimum;
    }
    cout<<a;
    return 0;
}