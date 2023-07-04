#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVector(vector <int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<endl;
}

void reverse(vector <int> &v, int high){
    if(v.size()/2 > high){
        return;
    }
    int temp = v[v.size()-1-high];
    v[v.size()-1-high] = v[high];
    v[high] = temp;
    reverse(v, high-1);
}

int main(){
    vector <int> vec = {1,2,3,4,5};
    printVector(vec);
    reverse(vec, vec.size()-1);
    printVector(vec);
    return 0;
}