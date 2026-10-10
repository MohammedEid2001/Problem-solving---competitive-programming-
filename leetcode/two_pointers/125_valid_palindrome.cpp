/*
description:
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/

using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        bool is = true;
        string ss ;
        ss.reserve(s.size());
        for(int i = 0 ; i < s.size(); ++i)
        {
            char & a= s[i];
            if(isalnum(a))ss.push_back(
                tolower(a)
            );
        }
        //cout << ss<< endl;
        for(int i = 0 , j = ss.size()-1;is && i <j ; ++i ,--j)
        {
            if(ss[i] != ss[j])is = false;
        }
        return is;
    }
};


//two pointer solution:

class Solution {
public:
    bool isPalindrome(const string& s) { 
        int i = 0;
        int j = (int)s.size() - 1;

        while (i < j) {
            while (i < j && !isAlnum(s[i])) ++i;
            while (i < j && !isAlnum(s[j])) --j;

            if (toLower(s[i]) != toLower(s[j])) return false;

            ++i;
            --j;
        }
        return true;
    }

private:
    static bool isAlnum(char &c) {
        return (c >= '0' && c <= '9') ||
               (c >= 'a' && c <= 'z') ||
               (c >= 'A' && c <= 'Z');
    }

    static char toLower(char &c) {
        return (c >= 'A' && c <= 'Z') ? char(c + ('a' - 'A')) : c;
    }
};
