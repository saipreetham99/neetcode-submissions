class Solution {
public:
    bool hasDuplicate(std::vector<int> &nums) {
    std::unordered_map<int, bool> map{};
    for (int i = 0; i < nums.size(); ++i) {
      if (map.count(nums[i])) {
        return true;
      } else {
        map.emplace(nums[i], false);
      }
    }
    return false;
  }
};