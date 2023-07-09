#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fibbo(int n){
    vector <int> vec;
    vec.push_back(0);
    vec.push_back(1);
    for(int i=2;i<=n;i++){
        vec.push_back(vec[vec.size()-1]+vec[vec.size()-2]);
    }
    return vec[vec.size()-1];
}

int main(){
    cout<<fibbo(5);
    return 0;
}