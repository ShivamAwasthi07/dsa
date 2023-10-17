#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;

// vector<string> solve(vector<string> strings, string order){
void solve(vector<string> strings, string order){
    unordered_map<char, int> p_map;
    int n = order.length();
    for (auto &&i : order){
        p_map[i] = n--;
    }
    // priority_queue<pair<int, string> > pq;
    map<int, string> m;
    for(int i=0; i<strings.size() ;i++){
        int val = 0;
        for(int j=0; j<strings[i].length() ;j++){
            val*=10;
            val+=p_map[strings[i][j]];
        }
        m[val] = strings[i];
        // pq.push();
    }
    for(auto i = m.begin(); i != m.end() ; ++i){
        cout<< i->second<<" ";
    }
    
}


int main(){
    vector<string> v;
    v.push_back("baa");
    v.push_back("bac");
    v.push_back("acba");
    v.push_back("acbd");
    string str = "dbac";
    solve(v, str);
    return 0;
}