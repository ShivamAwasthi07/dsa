#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string s, int low){
    if(s[low] != s[s.length()-1-low]){
        return 0;
    }
    if(low >= s.length()/2){
        return 1;
    }
    return isPalindrome(s, low+1);

}

int main(){
    string s = "oppo";
    cout<<isPalindrome(s, 0);
    return 0;
}