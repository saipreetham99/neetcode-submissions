class Solution {
public:
     std::vector<int> sortArray(std::vector<int> &nums) {
    if (nums.size() <= 1) {
      return nums;
    }
    int mid{(int(nums.size()) / 2) - 1};
    int right{int(nums.size()) - 1};
    std::vector<int> left_v(nums.begin(), nums.begin() + mid + 1);
    std::vector<int> right_v(nums.begin() + mid + 1, nums.end());
    return merge(sortArray(left_v), sortArray(right_v));
  }
  std::vector<int> merge(std::vector<int> left_v, std::vector<int> right_v) {
    std::vector<int> result;
    int left{};
    int right{};
    while (left < left_v.size() && right < right_v.size()) {
      if (left_v[left] <= right_v[right]) {
        result.push_back(left_v[left]);
        ++left;
      } else {
        result.push_back(right_v[right]);
        ++right;
      }
    }
    if (left >= left_v.size()) {
      while (right < right_v.size()) {
        result.push_back(right_v[right]);
        ++right;
      }
    }
    if (right >= right_v.size()) {
      while (left < left_v.size()) {
        result.push_back(left_v[left]);
        ++left;
      }
    }
    return result;
  }

};