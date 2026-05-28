class Solution {
public:
      std::string longestCommonPrefix(std::vector<std::string> &strs) {

    std::string res{};
    int minLength{getMinLength(strs)};
    for (int j{}; j < minLength; ++j) {
      for (int i = 0; i < strs.size() - 1; ++i) {
        if (strs[i][j] != strs[i + 1][j]) {
          return res;
        }
      }
      res += strs[0][j];
    }
    return res;
  }
  int getMinLength(std::vector<std::string> &strs) {
    int minLength{int(strs[0].size())};

    for (auto i : strs) {
      if (i.size() < minLength)
        minLength = i.size();
    }
    return minLength;
  }

};