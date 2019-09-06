#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


class Solution {
public:
    
    
bool IsPalindrome(string s)
{
    if(s.size() == 0)
    {
        return false;
    }
    if(s.size() == 1)
        return true;

    stack<char> str;
    for(int i=0; i<s.size(); i++)
        str.push(s[i]);

    for(int i=0; i<s.size(); i++)
    {
        char ch = str.top(); 
        str.pop(); 
        if(ch != s[i])
        {
            return false;
        }
    }
    return true;
}
    

    
    string longestPalindrome(string s) {
    if(s.size() == 0)
    {
        return "";
    }
    if(s.size() ==1)
        return s;

    //length start 
    vector<pair<int, int> > array;


    for(int i=0; i<s.size(); i++)
    {
        for(int j=i; j<s.size(); j++)
        {
            string curr = s.substr(i, j+1-i);
            if(IsPalindrome(curr))
                array.push_back(make_pair(j+1-i, i));
        }
    }


    
    sort(array.begin(), array.end(),[](pair<int, int>a, pair<int, int>b)->bool{
                                     return a.first > b.first;
                                 });   
    pair<int, int> result = array.front(); 
    
    return s.substr(result.second, result.first);
    }
};



int main(void)
{
    Solution solution;
    
    string test1 = "ac";
    string result1 = "a";



    string re1 = solution.longestPalindrome(test1); 


    if(re1 ==  "a")
        cout << "test1 passed" << endl;
    else
        cout << "test1 failed" << endl;



    return 0;
}