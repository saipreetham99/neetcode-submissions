class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> map{};
    int size{int(nums.size())};
    for (int index{}; index < size; ++index) {
      if (map.count(nums[index])) {
        return {map[nums[index]], index};
      }
      map.emplace(target - nums[index], index);
    }
    return {};
  }
};
