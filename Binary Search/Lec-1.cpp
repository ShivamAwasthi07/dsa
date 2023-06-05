#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
     public:
     int binsearch(int lo, int hi, vector<int> arr, int target){
        int mid;
        int lowest=-1;
        while(lo <= hi){
            mid = lo+(hi-lo)/2;
            if(arr[mid] == target){
                lowest = mid;
                lo=mid+1;   
            }
            else if(arr[mid] > target){
                hi = mid-1;
            }
            else if(arr[mid] < target){
                lo = lo+1;
            }
        }
        return lowest;
     }

     int mountainFunc(int lo, int hi, vector<int> arr){
        int mid = lo+(hi-lo)/2;
        if(arr.size() == 1){
            return lo;
        }
        if(arr.size() == 2){
            return arr[0] >= arr[1] ? 0 : 1;
        }
        while(lo<=hi){
            if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
                return mid;
            }
            else if(arr[mid] < arr[mid+1]){
                lo = mid+1;
            }
            else if(arr[mid] > arr[mid+1]){
                hi = mid-1;
            }
            mid = lo+(hi-lo)/2;
        }
        return -1;
     }

     int pivotFunction(vector <int> arr){
        int lo=0;
        int hi=arr.size()-1;
        if(arr[lo] < arr[hi]){
            return 0;
        }

        if(arr.size() == 1){
            return lo;
        }
        int mid = lo+(hi-lo)/2;
        while(lo<=hi){
            if(arr[mid] < arr[mid+1] && arr[mid] < arr[mid-1]){
                return mid;
            }
            else if(arr[mid] >= arr[0]){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
            mid = lo+(hi-lo)/2;
        }
        return -1;
     }
};

int main(){
    Solution sol;
    vector <int> v = {5, 1, 2, 3, 4};
    // cout<< sol.binsearch(0, v.size()-1,v ,5);
    // cout<< sol.mountainFunc(0, v.size()-1,v);
    cout<< sol.pivotFunction(v);
    return 0; 
}