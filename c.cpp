#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVector(vector <int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<endl;
}

// class Solution {
// public:
//     int maxWidthOfVerticalArea(vector<vector<int>>& points) {
//         vector <int> v;
//         for(vector<int> i : points){
//             v.push_back(i[0]);
//         }
//         sort(v.begin(), v.end());
//         int max = INT_MIN;
//         for(int i=0;i<v.size()-1;i++){
//             if(max < abs(v[i]-v[i+1])){
//                 max = abs(v[i]-v[i+1]);
//             }
//         }
//         return max;
//     }
// };

// class Solution {
// public:
//     map <char, char> m;
//     string decodeMessage(string key, string me) {
//         int i=0;
//         char j='a';
//         while(key[i] != '\0'){
//             char a = key[i];
//             if((a>=97 && a<=122) || (a>=65 && a<=90)){
//                 if(m.find(a) == m.end()){
//                     m[a] = j;
//                     j++;
//                 } 
//             }
//             i++;
//         }
        
//         for(int i=0;i<me.length();i++){
//             if(me[i] != ' '){
//                 me[i]=m[me[i]];
//             }
//         }
//         return me;
//     }
// };

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector <int> v(bank.size(), 0);
        int j=0;
        for(string s: bank){
            for(char i : s){
                if(i == '1'){
                    v[j]++;
                }
            }
            j++;
        }
        int p1=0,p2=1, cam=0;
        int i=0;
        if(v.size() <= 1){
            return 0;
        }
        else if(v.size() == 2){
            if(v[0] == 0 || v[1] == 0){
                return 0;
            }
            return v[1]*v[0]; 
        }
        while(p2 < v.size()){
            i++;
            if(v[p1] != 0 && v[p2] != 0){
                cam+=(v[p1]*v[p2]);
                p1++;
                p2++;
            }
            else if(v[p1] != 0 && v[p2] == 0){
                p2++;
            }
            else if(v[p1] == 0 && v[p2] != 0 && p1 == p2-1 && p2 != v.size()-1){
                p1++;
                p2++;
            }
            else if(v[p1] == 0 && v[p2] != 0){
                p1++;
            }
            else if(v[p1] == 0 && v[p2] == 0){
                p2++;
                p1++;
            }   
        }
        return cam;
    }
};

int main(){
    vector<string> v = {"0000111","1000000","0000000","0010000","0001101","1111111"};

    Solution sol;
    int a = sol.numberOfBeams(v);
    cout<<a;
    return 0;
}