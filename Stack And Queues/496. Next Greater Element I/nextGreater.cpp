class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.empty() || nums1.empty())
            return {};

        unordered_map<int, int> numberNGE;
        stack<int> numStack;

        numStack.push(nums2.back());
        numberNGE[nums2.back()] = -1;

        for (int i = nums2.size() - 2; i >= 0; --i) {
            while (!numStack.empty() && nums2[i] > numStack.top())
                numStack.pop();

            if (numStack.empty()) {
                numStack.push(nums2[i]);
                numberNGE[nums2[i]] = -1;
            } else {
                numberNGE[nums2[i]] = numStack.top();
                numStack.push(nums2[i]);
            }
        }

        for (int i = 0; i < nums1.size(); ++i)
            nums1[i] = numberNGE[nums1[i]];

        return nums1;
    }
};