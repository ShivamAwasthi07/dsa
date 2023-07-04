#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
     public:
};

void func(int val, int n){
    if(val > n){
        return;
    }
    func(val+1, n);
    cout<<val<<" ";
}

int main(){
    // Solution sol;
    func(1, 10);
    return 0;
}