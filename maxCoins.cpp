class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int sum=0;
        for(int i=0;i<piles.size()/3;i++){
            sum += piles[piles.size()-2-(2*i)];
        }
        return sum;
    }
};