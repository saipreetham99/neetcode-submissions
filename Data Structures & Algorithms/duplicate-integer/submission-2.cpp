class Solution {
public:
    bool hasDuplicate(std::vector<int> &nums) {
    std::unordered_set<int> set{};
    for (auto i : nums) {
      if (set.count(i)) {
        return true;
      }
      set.emplace(i);
    }
    return false;
  }
};