
/*
description:
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
*/

//approach: make two arrays to store the frequnecy of occurence of the letters on each string, then compare them to see if they equal each others.
class Solution {
public:
    bool isAnagram(string s, string t) {
        //sort( s.begin(),s.end());
       // sort(t.begin(), t.end());
        vector<int> a(26,0);
        vector<int> b(26,0);
        if(s.size() != t.size())return false;
        for(int i = 0; i <s.size();++i)
        {
            ++a[s[i] -'a'];
            ++b[t[i] -'a'];
        }
        return a == b;
    }
};
