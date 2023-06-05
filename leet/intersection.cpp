#include <iostream>
#include <vector>
#include <commonFunction.h>
using namespace std;

int main(){
    vector <int> v1 = {2,2,2,3,3,4,7,8};
    vector <int> v2 = {1,2,4,4,6,6,7,8,10};
    vector <int> v;

    int i=0,j=0;

    while(i<v1.size() && j<v2.size()){
        if(v1[i] == v1[i+1]){
            i++;
        }
        else if(v2[j] == v2[j+1]){
            j++;
        }
        else{
            if(v1[i]>v2[j]){
                j++;
            }
            else if(v1[i]<v2[j]){
                i++;
            }
            else{
                v.push_back(v1[i]);
                i++;
                j++;
            }
        }
    }
    for(int x=0;x<v.size();x++){
        cout<<v[x]<<" ";
    }
    cout<< v.size();

    return 0;
}