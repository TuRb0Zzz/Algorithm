#include <iostream>
#include <string>
using namespace std;



int main(){
    int number;
    string a;
    string numbuff;
    cin>>number;
    for(int i=0;i<10;i++){
        number=number*number;
        a=to_string(number);
        int start=(a.length()-5)/2;
        for(int j=start;j<start+5;j++){
            numbuff+=a[j];
        }
        number=stoi(numbuff);
        cout<<numbuff<<endl;
        numbuff="";
    }
    return 0;
}