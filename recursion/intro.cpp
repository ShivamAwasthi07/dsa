#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int B=0;

void p(){
    if(B == 5){
        return;
    }
    cout<<B++<<" ";

    p();

}

int main(){
    // Solution sol;
    p();
    return 0;
}