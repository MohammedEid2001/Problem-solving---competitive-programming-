/*

description

*/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleets = speed.size();
        vector<pair<int,int>> positions;
        positions.reserve(speed.size());

        for (int i = 0; i < speed.size(); ++i)
            positions.push_back({position[i], speed[i]});

        sort(positions.begin(), positions.end());

        for (int i = 0; i < positions.size(); ++i)
        {
            bool stopped = false;
            for (int j = i + 1; j < positions.size() && !stopped; ++j)
            { 
                if (positions[i].second <= positions[j].second) continue;

                long long lhs = (long long)(positions[j].first - positions[i].first)
                              * positions[j].second;
                long long rhs = (long long)(target - positions[j].first)
                              * (positions[i].second - positions[j].second);

                if (lhs <= rhs) { --fleets; stopped = true; }
            }
        }
        return fleets;
    }
};

// a better O(n.logn solution wiith atomic stack)
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars(n);
        for (int i = 0; i < n; ++i)
            cars[i] = {position[i], speed[i]};

        // Sort by position descending (closest to target first)
        sort(cars.begin(), cars.end(),
             [](const pair<int,int>& a, const pair<int,int>& b) {
                 return a.first > b.first;
             });

        vector<double> st;  // arrival times of fleets
        st.reserve(n);

        for (auto& [pos, sp] : cars) {
            double arrival = (double)(target - pos) / sp;
            if (st.empty() || arrival > st.back()) {
                st.push_back(arrival);
            }
            // else: arrival <= st.back() → this car catches the fleet ahead → merge
        }
        return st.size();
    }
};