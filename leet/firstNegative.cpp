#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

vector<int> f(vector<int> v, int k){
    queue<int> q;
    vector<int> ans;
    int i=0,j=0;
    while(j < v.size()){
        cout<<i<<" "<<j<<endl;
        if(j-i+1 < k) {
            if(v[j] < 0) q.push(v[j]);
        }
        
        else if(j-i+1 == k){
            if(v[j] < 0) q.push(v[j]);
            if(q.empty()){
                ans.push_back(0);
                i++;
            } else {
                ans.push_back(q.front());
                if(v[i] == q.front()){
                    q.pop();
                }
                i++;
            }
        }
        j++;
    }
    for(i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return ans;
    
}


int main(){
    vector<int> v;
    v.push_back(-1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(3);
    v.push_back(-2);
    v.push_back(6);
    v.push_back(-9);
    vector<int> a = f(v, 3);

    

    return 0;
}