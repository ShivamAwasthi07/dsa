#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix[0][0]> target || matrix[matrix[0].size()-1][matrix[0].size()-1] < target){
            return false;
        }
        int vi=0;
        int vj=matrix.size()-1;
        int mid = vj - (vj-vi)/2;
        int locked=-1;
        if(target >= matrix[matrix.size()-1][0] && matrix[matrix[0].size()-1][matrix[0].size()-1] >= target){
            vi=0,vj=matrix[0].size()-1;
        mid = vj - (vj-vi)/2;
        while(vi<=vj){
            mid = vj - (vj-vi)/2;

            if(matrix[locked][mid] == target){
                return true;
            }
            else if(matrix[locked][mid] < target){
                vi = mid+1;
            }
            else if(matrix[locked][mid] > target){
                vj = mid-1;
            }
        }
        }
        if(locked == -1){
            while(vi<=vj){
             mid = vj - (vj-vi)/2;
            if(matrix[mid][0] == target){
                return true;
            }
            if(matrix[mid][0] < target && target<matrix[mid+1][0]){
                locked = mid;
                break;
            }
            else if(matrix[mid][0] > target){
                vj = mid-1;
            }
            else if(matrix[mid][0] < target){
                vi = mid+1;
            }
        }
        }
        cout<<"locked -- "<<locked;
        vi=0,vj=matrix[locked].size()-1;
        mid = vj - (vj-vi)/2;
        while(vi<=vj){
            mid = vj - (vj-vi)/2;

            if(matrix[locked][mid] == target){
                return true;
            }
            else if(matrix[locked][mid] < target){
                vi = mid+1;
            }
            else if(matrix[locked][mid] > target){
                vj = mid-1;
            }
        }
        return false;
    }
};

int main(){
    vector<vector<int>> v = {{1,3,5,7},{10,11,16,20},{23,30,34,60}, {65, 75, 78, 85}};
    int target = 85;
    Solution sol;
    bool x = sol.searchMatrix(v, target);
    cout<<bool(x)<<"--x"<<endl;
    return 0;
}