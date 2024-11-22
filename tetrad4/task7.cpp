#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int,int> table;
    int a[7]={86,90,27,29,38,30,40};
    for(int i:a){
        if(table.find(i%7)==table.end()){
            table[i%7]=i;
        }
        else{
            for(int j=1;;j++){
                if(table.find(i%7+j)==table.end()){
                    table[i%7+j]=i;
                    break;
                }
            }
        }
    }
    for(auto a:table){
        cout<<a.first<<"\t"<<a.second<<endl;
    }
    return 0;
}