/*
desxription:
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
*/

//we use a priority queue to keep track of the curdent window and the max element, and remove only whem we find the element on top not in the range, which got a complexity of O(n.k.log(n))

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> MaxWindow;
        priority_queue<pair<int,int>> Max;
        MaxWindow.reserve(nums.size() - k + 1);

        for (int i = 0; i < k; ++i)
            Max.push({nums[i], i});

        MaxWindow.push_back(Max.top().first);

        for (int i = 1; i <= (int)nums.size() - k; ++i) {
            while (!Max.empty() && Max.top().second < i)
                Max.pop();

            Max.push({nums[i + k - 1], i + k - 1});
            MaxWindow.push_back(Max.top().first);
        }
        return MaxWindow;
    }
};


//faster O(n) dequeue solution, where push any new element found to the front , and if its :larger than +previous elements we just remove them off the queue, also if we found elements in back got indice out of our range we remove them as well:

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;              // indices, values decreasing front→back
    vector<int> ans;
    ans.reserve(nums.size() - k + 1);
    for (int i = 0; i < (int)nums.size(); ++i) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}
