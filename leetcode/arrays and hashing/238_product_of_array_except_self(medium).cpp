
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector< pair<long,long>> mults(nums.size(), {0,0});
        int sum = 0;
        mults[0]= {nums[0],1};
        for(int i = 1; i <nums.size();++i)
        {
            mults[i]={mults[i-1].first*nums[i],mults[i-1].first};
        }
        int accumulated= 1;
        for(int i = nums.size()-1; i >=0; --i)
        {
            mults[i].second*= accumulated;
            accumulated*= nums[i];
        }

        vector<int> sol;
        for(pair<long,long> a: mults)sol.push_back(a.second);
        return sol;
    }
};

