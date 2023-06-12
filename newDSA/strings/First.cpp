#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int compress(vector<char>& chars) {
//         if(chars.size() == 1){
//             return 1;
//         }
//         string s = "";
//         int count=1;
//         for(int i=0;i<chars.size();i++){
//             if(chars[i] == chars[i+1]){
//                 count++;
//             }
//             else{
//                 s.push_back(chars[i]);
//                 if(count > 1){
//                     string x = to_string(count);
//                     for(char a : x){
//                         s.push_back(a);
//                     }
//                 }
//                 count=1;
//             }
//         }
//         for(int i=0;i<s.length();i++){
//             chars[i] = s[i];
//         }
//         return s.length();
//     }
// };

// class Solution {
// public:
//     int numRescueBoats(vector<int>& people, int limit) {
//         int lim = limit;
//         int boatNum=0;
//         int maxi=2;
        
//         for(int i=0;i<people.size()-1;i++){
//             lim-=people[i];
//             maxi--;
//             if(maxi == 0 || lim < people[i+1]){
//                 maxi=2;
//                 boatNum++;
//                 lim = limit;
//             }
//         }
//         cout<<lim<<" "<<maxi<<endl;
//         cout<<people[people.size()-1];
//         if(lim < people[people.size()-1] || maxi == 0){
//             boatNum++;
//         }

//         return boatNum;
//     }
// };

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        set <int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int j=0;
        for (auto it = s.begin(); it!=s.end(); it++){
            nums[j] = *it;
            j++;
        }
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        return nums[nums.size()-k];
    }
};

int main(){
    Solution sol;
    vector <int> v = {3,2,3,1,2,4,5,5,6};
    int lim=4;
    cout<<sol.findKthLargest(v, lim);
    return 0;
}