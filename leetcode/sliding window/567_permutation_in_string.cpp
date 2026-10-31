/*
description:

*/

public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> S1(26,0), S2(26,0);
        for (char &c : s1) ++S1[c-'a'];
        int len = s1.size();
        for (int i = 0; i < len; ++i) ++S2[s2[i]-'a'];
        if (S1 == S2) return true;
        for (int i = len; i < (int)s2.size(); ++i) {
            ++S2[s2[i]-'a'];
            --S2[s2[i-len]-'a'];
            if (S1 == S2) return true;
        }
        return false;
    }
};


//faster solution:

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        int diff[26] = {};
        for (char c : s1) ++diff[c - 'a'];

        int nonZero = 0;
        for (int i = 0; i < 26; ++i) nonZero += (diff[i] != 0);

        auto add = [&](int c) {          // add s2 char to window
            if (diff[c] == 0) ++nonZero;
            if (--diff[c] == 0) --nonZero;
        };
        auto remove = [&](int c) {       // remove s2 char from window
            if (diff[c] == 0) ++nonZero;
            if (++diff[c] == 0) --nonZero;
        };

        for (int i = 0; i < n; ++i) add(s2[i] - 'a');
        if (nonZero == 0) return true;

        for (int i = n; i < m; ++i) {
            remove(s2[i - n] - 'a');
            add(s2[i] - 'a');
            if (nonZero == 0) return true;
        }
        return false;
    }
};