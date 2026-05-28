class Solution {
public:
      std::string longestCommonPrefix(std::vector<std::string> &strs) {

    std::string res{};
    if (strs.size() == 0) {
      return "";
    }
    for (std::size_t i{}; i < strs[0].size(); ++i) {
      for (std::size_t j{}; j < strs.size() - 1; ++j) {
        if (!strs[j][i]) {
          return res;
        }
        if (strs[j][i] != strs[j + 1][i])
          return res;
      }
      res += strs[0][i];
    }
    return res;
  }

};