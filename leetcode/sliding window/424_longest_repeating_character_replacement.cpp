/*
description:
*/

class Solution {
public:
    int MaxEl(vector<int> &a)
    {
        return *max_element(a.begin(), a.end()) ;
    }
    int characterReplacement(string s, int k) {
        vector<int> chars(128,0);
        int start = 0;
        int length = 0;
        for(int i = 0;i <k ;++i)
        {
            ++chars[s[i]];
            ++length;
        }

        for(int i = k ; i< s.size();++i){
            ++chars[s[i]];
            while(MaxEl(chars)+k <i-start+1)
            {
                --chars[s[start]];
                ++start;
            }
            if(i-start+1 > length)length = i-start +1;
        }
        return length;
        
    }
};


// faster version( uses only 26 upper case letters and only computes the max element when we are searching for an element for a faster O(1) update on max because we know the only way we find another bigger element is when we increase sliding window size)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {};
        int left = 0, maxFreq = 0, maxLen = 0;
        for (int right = 0; right < (int)s.size(); ++right) {
            maxFreq = max(maxFreq, ++count[s[right] - 'A']);
            while (right - left + 1 - maxFreq > k)
                --count[s[left++] - 'A'];
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
