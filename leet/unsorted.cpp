#include <iostream>
#include <unordered_set>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void print(unordered_set<int> const &s)
{
    copy(s.begin(),
            s.end(),
            ostream_iterator<int>(cout, " "));
}

int main(){
    unordered_set <int> s;
    vector <int> v1 = {4,2,3,5,4,2,3};
    vector <int> v2 = {9,1,7,2,4,2,1,2};
    int i=0;
    while(i<v1.size()){
        if(s.find(v1[i]) == s.end()){
            s.insert(v1[i]);
        }
        i++;
    }
    i=0;
    while(i<v2.size()){
        if(s.find(v2[i]) == s.end()){
            s.insert(v2[i]);
        }
        i++;
    }
    for(auto const z: s){
        cout<<z<<" ";
    }
    return 0;
}