#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<endl;
}

int indexOfDanger(vector<int> time, string s){
    if(time.size() == 0) return -1;
    for(int i = 0; i < time.size(); i++){
        if(s[time[i]-1] == '1'){
            return i;
        }
    }
    return -1;
}

int countMinimumDeletion(int n, int m, string s, vector<int> &time) {
    cout<<"Started"<<endl;
    int index = indexOfDanger(time, s);
    cout<<"index: "<<index<<endl;
    while(time.size() > 0 && index >= 0){
        for(int i = index;i<time.size();i++){
            time[i]=time[i]-1;
        }
        time.erase(time.begin()+index);

        printVector(time);

        index = indexOfDanger(time, s);
    }
    
    return n-time.size();
}


int main(){
    vector<int> time;
    time.push_back(3);
    time.push_back(5);
    time.push_back(7);
    time.push_back(8);
    time.push_back(9);
    time.push_back(10);
    string s = "1010101010";

    cout<<countMinimumDeletion(time.size(), s.length(), s, time);
    return 0;
}