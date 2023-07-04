#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
     public:
};

int sumVal(int term){
    if(term == 0){
        return 0;
    }
    int a = term+sumVal(term-1); 
    cout<<"Summation "<<a;
    return a;
}

int main(){
    // Solution sol;
    cout<<sumVal(5);
    return 0;
}