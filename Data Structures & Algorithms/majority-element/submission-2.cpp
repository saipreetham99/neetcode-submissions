class Solution {
public:
     int majorityElement(std::vector<int> &nums) {
    int count{};
    int res{};
    for (auto i : nums) {
      if (count == 0) {
        res = i;
      }
      count += (res == i) ? 1 : -1;
    }
    return res;
  }


};
 