class Solution {
public:
    int sumBase(int n, int k) {
        int base10 = n;
        int baseK=0;
        int i=1;
        while(base10>0){
            baseK+=i*(base10%k);
            base10 = base10/k;
            i*=10;
        }
        int ans=0;
        string str = to_string(baseK);
        for(char c: str){
            ans+= c-'0';
        }
        return ans;
    }
};