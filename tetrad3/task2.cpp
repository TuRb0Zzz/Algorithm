#include <iostream>
#include <vector>
#include <algorithm>
// #define TEST
// #define COUTBUFFER
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

void multiply(string a, string b){
    Addnol(a,b);
    //int multi=1;
    vector<int> first, second;
    if (AbiggerB(a,b)){
        for(int i=0;i<a.size();i++){
            first.push_back((a[i])- '0');
            second.push_back((b[i])- '0');
        }
    }
    else{
        for(int i=0;i<a.size();i++){
            first.push_back((b[i])- '0');
            second.push_back((a[i])- '0');
        }
    }
    int number_first,number_second;
    int buffer[second.size()][first.size()+second.size()+1];
    for(int i=0;i<second.size();i++){
        for(int j=0; j<(first.size()+second.size()+1);j++){
            buffer[i][j]=0;
        }
    }
    int buff=0;
    int pozition=0;
    for(int i=1;i<=second.size();i++){
        number_second=second[second.size()-i];
        for(int j=1;j<=first.size();j++){
            number_first=first[first.size()-j];
            if((((number_first*number_second)+buff)>=10) and j!=first.size()){
                buffer[i-1][(first.size()+second.size()+1)-j-pozition]=((number_first*number_second)+buff)%10;
                buff=(((number_first*number_second)+buff)-((((number_first*number_second)+buff)%10)))/10;
            }
            else{
                if(j==first.size()){
                    if(((number_first*number_second)+buff)>=10){
                        buffer[i-1][(first.size()+second.size()+1)-j-pozition]=((number_first*number_second)+buff)%10;
                        buffer[i-1][(first.size()+second.size()+1)-j-pozition-1]=(((number_first*number_second)+buff)-((((number_first*number_second)+buff)%10)))/10;
                    }
                    else{
                        buffer[i-1][(first.size()+second.size()+1)-j-pozition]=((number_first*number_second)+buff);
                    }
                }
                else{
                    buffer[i-1][(first.size()+second.size()+1)-j-pozition]=((number_first*number_second)+buff);
                }
                buff=0;
            }    
        }
        pozition+=1; 
    }
#ifdef COUTBUFFER
    for(int i=0;i<second.size();i++){
        for(int j=0; j<(first.size()+second.size()+1);j++){
            cout<<buffer[i][j]<<" ";
        }
        cout<<endl;
    }
#endif
    buff=0;
    int counter=0;
    vector<int> otvet;
    int size=first.size()+second.size();
    for(int j=size;j>=0;j--){
        for(int i=0;i<second.size();i++){
            counter+=buffer[i][j];
        }
        if((counter+buff)>=10 and j!=0){
            otvet.push_back((counter+buff)%10);
            buff=((counter+buff)-((counter+buff)%10))/10;
        }
        else{
            if((counter+buff)>=10){
                otvet.push_back((counter+buff)%10);
                otvet.push_back(((counter+buff)-((counter+buff)%10))/10);
            }
            else{
                otvet.push_back(counter+buff);
            }
            buff=0;
        }
        counter=0;
    }
    reverse(otvet.begin(),otvet.end());
    bool vedNol=false;
    for(int i=0; i< otvet.size();i++){
        if(otvet[i]!=0){
            vedNol=true;
        }
        if(vedNol){
            cout<<otvet[i];
        }
    }
    cout<<endl;

}

int main(){
    string a,b;
    cin >> a >> b;
    multiply(a,b);
    return 0;
}