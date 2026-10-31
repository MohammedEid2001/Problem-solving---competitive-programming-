/*
description:
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.
*/

//we use a moving sliding window, that keeps increasing in size to the right when we dont find the total number of permutations, and starts decreasing from the left after we do 

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.size() < t.size()) return "";

        vector<int> need(128, 0), window(128, 0);
        for (char c : t) ++need[c];

        int required = t.size();
        int formed = 0;

        int left = 0;
        int minLen = s.size()+1;
        int bestLeft = 0;

        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            ++window[c];

            if (need[c] > 0 && window[c] <= need[c]) {
                ++formed;
            }

            while (formed == required) {
                int len = right - left + 1;
                if (len < minLen) {
                    minLen = len;
                    bestLeft = left;
                }

                char lc = s[left];
                if (need[lc] > 0 && window[lc] <= need[lc]) {
                    --formed;
                }
                --window[lc];
                ++left;
            }
        }

        return minLen == s.size()+1 ? "" : s.substr(bestLeft, minLen);
    }
};
