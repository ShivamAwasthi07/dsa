#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int> s)
{
    // cout<<i<<endl;
    while (!s.empty())
    {
        cout << "| " << s.top() << " |" << endl;
        s.pop();
    }
}

class Solution
{
public:
    void deleteFunc(stack<int> &s, int i, int elem)
    {
        if (i == elem / 2)
        {
            s.pop();
            return;
        }
        int top = s.top();
        s.pop();
        deleteFunc(s, i + 1, elem);
        s.push(top);
    }

    stack<int> deleteMid(stack<int> &s)
    {
        int elem = s.size();
        int i = 0;
        deleteFunc(s, i, elem);
        return s;
    }
    void insertAtBottom(stack<int> &s, int num)
    {
        if (s.empty())
        {
            s.push(num);
            return;
        }
        int top = s.top();
        s.pop();
        insertAtBottom(s, num);
        s.push(top);
    }

    void reverse(stack<int> &s)
    {
        if (s.empty())
        {
            return;
        }
        int x = s.top();
        s.pop();
        reverse(s);
        insertAtBottom(s, x);
    }
};

int main()
{
    int i = 0;
    string st = "())";
    stack<char> s;

    while (i < st.length())
    {
        char x = st[i];
        if (x == '(')
        {
            s.push('(');
        }
        else if (x == ')')
        {
            if (!s.empty() && s.top() == '(')
            {
                s.pop();
            }
            else if (s.empty() || s.top() == ')')
            {
                s.push(')');
            }
        }
        i++;
    }

    cout<<s.size();
    return 0;
}

// class Solution {
// public:
//     vector<string> summaryRanges(vector<int>& nums) {
//         nums.push_back(nums[nums.size()-1]+2);
//         vector<string> v;
//         int count=0;
//         int min=0;
//         for(int i=0;i<nums.size()-1;i++){
//             if(nums[i]+1 == nums[i+1]){
//                 count++;
//             }
//             else{
//                 if(count>=1){
//                     v.push_back(to_string(nums[min])+"->"+to_string(nums[i]));
//                 }
//                 else{
//                     v.push_back(to_string(nums[i]));
//                 }
//                 count=0;
//                 min=i+1;
//             }
//         }
//         return v;
//     }
// };