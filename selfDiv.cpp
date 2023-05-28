class Solution {
public:
    bool isDiv(int n){
        string str = to_string(n);
        for(char i : str){
            if((i-'0') == 0){
                return false;
            }
            if(n % (i-'0') != 0){
                return false;
            }
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for(int i=left;i<=right;i++){
            if(i%10!=0 && isDiv(i)){
                v.push_back(i);
            }
        }
        return v;
    }
};