class Solution {
public:
    int majorityElement(vector<int>& nums) {
    // The naive solution would be sorting and then going for the middle element
    // and checking left and right of it.
    // Try O(n) solution
    std::unordered_map<int, int> freq{};
    for (auto i : nums) {
      ++freq[i];
      if (freq[i] > (nums.size() / 2))
        return i;
    }
    return 0;
  }
};
 