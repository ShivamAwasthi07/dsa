#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int maxHeightIndex = -1;
        int maxH=0;
        vector<int> aux;
        for(int i=0;i<height.size();i++){
            if(height[i] > maxH){
                maxH = height[i];
                maxHeightIndex=i;
            }
            aux.push_back(maxH);
        }
        maxH=0;
        for(int i=height.size()-1;i>maxHeightIndex;i--){
            if(height[i] > maxH){
                maxH = height[i];
            }
            aux[i] = maxH;
        }
        int ans=0;
        for(int i=0;i<height.size();i++){
            ans+= abs(aux[i]-height[i]);
        }
        return ans;
    }
};

int main(){
    vector<int> v = {4,2,0,3,2,5};
    Solution sol;
    cout<<sol.trap(v);
    return 0;
}