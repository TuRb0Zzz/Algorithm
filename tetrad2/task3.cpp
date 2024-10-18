#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

pair<int,int> ferma(int number){
    int koren=sqrt(number);
    int x=1;
    int q=0;
    int delit1=0,delit2=0;
    int koren_iz_q=0;
    while(true){
        q=(koren+x)*(koren+x)-number;
        koren_iz_q=sqrt(q);
        if (koren_iz_q*koren_iz_q==q){
            break;
        }
        else{
            x++;
        }
    }
    delit1=(koren+x)-koren_iz_q;
    delit2=(koren+x)+koren_iz_q;
    return std::make_pair(delit1,delit2);
}

bool IsSimple(int number){
    for(int i=2;i<sqrt(number);i++){
        if (number%i==0){
            return false;
        }
    }
    return true;
}


int main(){
    int number;
    cin>>number;
    std::pair<int,int> a=ferma(number);
    pair<int,int> bufferpair;
    vector<int> b;
    vector<int> c;
    b.push_back(a.first);
    b.push_back(a.second);
    int counter=0;
    while(true){
        counter=0;
        for(int i=0;i<b.size();i++){
            if (IsSimple(b[i])){
                counter++;
            }
        }
        if(counter==b.size()){
            break;
        }
        for(int i=0;i<b.size();i++){
            bufferpair=ferma(b[i]);
            c.push_back(bufferpair.first);
            c.push_back(bufferpair.second);
        }
        b=c;
        c.clear();
    }
    counter=0;
    for(int i=0;i<b.size();i++){
        if(b[i]!=1){
            cout<<b[i];
            if(i!=b.size()-1){
                cout<<" * ";
            }
        }
    }
    return 0;
}