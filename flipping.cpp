#include <iostream>
#include <bits/stdc++.h>
// #include <./commonFunction.h>
using namespace std;

void printVector(vector <vector <int>> v){
    for(vector<int> vec : v){
        for(auto i: vec){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}


class Solution {
public:
    vector <vector<int>> flipAndInvertImage(vector <vector<int>> image) {
        int n = image.size();
        int k=0;
        while(k<n){
        int i=0;
            while(i<= n-i-1){
                if(image[k][i] == image[k][n-i-1]){
                    image[k][i] = !image[k][i];
                    image[k][n-i-1] = image[k][i];
                }
                i++;
            }
            k++;
        }
        return image;
    }
};

int main(){
    vector <vector <int>> v = {{1,1,0}, {1,0,1}, {0,0,0}};
    Solution sol;
    vector <vector <int>> x = sol.flipAndInvertImage(v);
    // print
    printVector(x);
    return 0;
}