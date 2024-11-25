#include <iostream>
#include <unordered_map>
using namespace std;


int main(){
    string a;
    unordered_map<char,int> table;
    getline(cin,a);
    for(int i=0;i<a.length();i++){
        table[a[i]]++;
    }
    for(auto i:table){
        cout<<i.first<<"\t"<<i.second<<endl;
    }
    return 0;
}