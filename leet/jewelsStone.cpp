class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char, bool> m;
        int count =0;
        for(char ch : jewels){
            m[ch] = true;
        }
        for(char ch : stones){
            if(m[ch] == true){
                count++;
            }
        }
        return count;
    }
};