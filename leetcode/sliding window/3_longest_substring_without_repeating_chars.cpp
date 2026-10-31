/*
description:
*/


// made a vector to store the cirrent frequencies of occurences of any ascii character, that was then used to find if a character was repeated or not.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> repeat(128, 0);
        int freq = 0;
        int start = 0;
        int length = 0;

        for (int i = 0; i < (int)s.size(); ++i) {
            int index = (unsigned char)s[i];
            if (repeat[index] == 1) ++freq;
            ++repeat[index];

            while (freq) {
                int StartIndex = (unsigned char)s[start];
                if (repeat[StartIndex] == 2) --freq;
                --repeat[StartIndex];
                ++start;
            }

            length = max(length, i - start + 1);
        }

        return length;
    }
};




//faster solution, instead of moving one step a time, we can store the last index a character was seen, and jump immediately to it when we find theres a repeated character 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[128];
        memset(last, -1, sizeof(last));   // -1 = never seen
        int start = 0, best = 0;

        for (int i = 0; i < (int)s.size(); ++i) {
            unsigned char c = s[i];
            if (last[c] >= start) start = last[c] + 1;  // jump, don't crawl
            last[c] = i;
            best = max(best, i - start + 1);
        }
        return best;
    }
};
