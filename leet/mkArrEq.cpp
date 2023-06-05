class Solution {
public:
    int minOperations(int n) {
        int an = n-1;
        int a = abs(n%2-1);

        int sumOfOp=0;
        
        int terms = ((an-a)/2)+1;

        sumOfOp = ((terms)*(a+an))/2; 

        return sumOfOp;
    }
};