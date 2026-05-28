class Solution {
public:
    bool hasDuplicate(std::vector<int> &nums) {
    std::unordered_set<int> set{};
    for (std::size_t index{}; index < nums.size(); ++index) {
      if (set.count(nums[index])) {
        return true;
      } else {
        set.emplace(nums[index]);
      }
    }
    return false;
  }
};