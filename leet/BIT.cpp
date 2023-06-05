#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int count=0;
        while(num>0){
            cout<<num<<endl;
            if(!(num&1)){
                num=num>>1;
            }
            else{
                num=num-1;
            }
            count++;
        }
        return count;
    }
};

int main(){
    Solution sol;
    int x = sol.numberOfSteps(14);
    cout<<x;
    return 0;
}