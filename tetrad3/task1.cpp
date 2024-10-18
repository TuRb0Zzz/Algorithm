#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
using namespace std;

bool AbiggerB(string a, string b){
    
    for(int i=0;i<a.length();i++){
        if (((a[i])- '0')>((b[i])- '0')){
            return true;
        }
        else if(((a[i])- '0')<((b[i])- '0')){
            return false;
        }
    }
    return true;
}


int Addnol(string &first, string &second) {
    int raz;
    if (first.length() > second.length()) {
        raz = (first.length() - second.length());
    } 
    if (first.length() < second.length()){
        raz = (second.length() - first.length());
    }
    string nol = string(raz, '0');
    if (raz == 0) {
        return raz;
    }
    if (first.length() > second.length()) {
        second = nol + second;
        return raz;
    } 
    if (first.length() < second.length()){
        first = nol + first;
        return raz;
    }
    return raz;
}

void stolbikPlus(string a,string b){

    int raz = Addnol(a,b);
    vector<int> first;
    vector<int> second;
    for(int i=0;i<a.length();i++){
        first.push_back((a[i])- '0');
        second.push_back((b[i])- '0');
    }
    vector<int> otvet;
    int number1,number2;
    int buff=0;
    int minLen=first.size();
    for(int i=1;i<=minLen;i++){
        number1=first[first.size()-i];
        number2=second[second.size()-i];
        if((((number1+number2)+buff)>=10) and i!=minLen){
            otvet.push_back((number1+number2+buff)%10);
            buff=(((number1+number2)+buff)-((((number1+number2))+buff)%10))/10;
        }
        else{
            otvet.push_back(number1+number2+buff);
            buff=0;
        }
    }
    reverse(otvet.begin(),otvet.end());
    system("cls");
    if(AbiggerB(a,b)){
        cout<<a<<"  "<<"+"<<endl<<b<<endl<<string(a.length(),'-')<<endl;
    }
    else{
        cout<<b<<"  "<<"+"<<endl<<a<<endl<<string(a.length(),'-')<<endl;
    }
    for(int i=0;i<otvet.size();i++){
        cout<<otvet[i];
    }
}

void stolbikMinus(string a, string b){
    int raz = Addnol(a,b);
    vector<int> first;
    vector<int> second;
    vector<int> otvet;
    int number1,number2;
    if (AbiggerB(a,b)){
        for(int i=0;i<a.length();i++){
            first.push_back((a[i])- '0');
            second.push_back((b[i])- '0');
        }
    }
    else{
        for(int i=0;i<a.length();i++){
            first.push_back((b[i])- '0');
            second.push_back((a[i])- '0');
        }
    }
    for(int i=1;i<=first.size();i++){
        number1=first[first.size()-i];
        number2=second[second.size()-i];
        if(number1>=number2){
            otvet.push_back(number1-number2);
        }
        else{
            first[first.size()-i-1]--;
            otvet.push_back(10+number1-number2);
        }
    }
    reverse(otvet.begin(),otvet.end());
    system("cls");
    if(AbiggerB(a,b)){
        cout<<a<<"  "<<"-"<<endl<<b<<endl<<string(a.length(),'-')<<endl;
    }
    else{
        cout<<b<<"  "<<"-"<<endl<<a<<endl<<string(a.length(),'-')<<endl;
    }
    for(int i=0;i<otvet.size();i++){
        cout<<otvet[i];
    }
}


int main(){
    string a,b;
    char znak;
    cin>>a>>znak>>b;
    if(znak=='+'){
        stolbikPlus(a,b);
    }
    if (znak=='-'){
        stolbikMinus(a,b);
    }
    return 0;
}