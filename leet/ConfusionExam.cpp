#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveAnswers(string arr, int k) {
        int i=0, j=0;
        int selected = 0, other = 0;
        char ch = 'F';
        int n = arr.size();
        if(n == 1) return 1;

        int trues = 0;
        for(char i : arr){
            if(i == 'T') trues++;
        }
        if(trues <= n/2) ch = 'T';
        int ans = 0;

        while(j < n){
            if(selected <= k){
                if(arr[j] == ch) selected++;
                else other++;

                j++;
            }
            else if(selected > k){
                while(selected > k){
                    if(arr[i] == ch){
                        selected--;
                    } else {
                        other--;
                    }
                    i++;
                }
            }
            ans = max(ans, other+k);
        }
        return ans;
    }

int main(){
    string s = "TF";
    int k = 2;

    cout<<maxConsecutiveAnswers(s, k);
    return 0;
}