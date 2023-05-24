#include <iostream>
#include <vector>
using namespace std;

void returnVec(vector <int> v, int target, int index, int sum, vector<vector<int>> &finalV, vector<int> &t){
    sum+= v[index];
    t.push_back(v[index]);

    if(sum>=target){
        for(int i=0;i<t.size();i++){
        cout<<" "<<t[i];
    };
    cout<<endl;   
    cout<<endl;   
    t = {};
        if(sum == target){
            finalV.push_back(t);
        }
        return;
    }
    else if(index >= v.size()){
        t = {};
        return;
    }
    returnVec(v, target, index, sum, finalV, t);
    returnVec(v, target, index+1, sum, finalV, t);
}

int main(){
    vector <int> v = {2,3,5};
    int target = 8;
    int index = 0;
    int sum=0;
    vector <int> dummy;

    vector <vector<int>> vec;

    returnVec(v, target, index, sum, vec, dummy);
    return 0;
}