class Solution {
public:
  bool isPalindrome(std::string s) {
    int first{};
    int last{static_cast<int>(s.size() - 1)};
    int length{static_cast<int>(s.size() - 1)};
    while (first < last) {
      while (!std::isalnum(s[first])) {
        if (first == length)
          return true;
        ++first;
      }
      while (!std::isalnum(s[last])) {
        if (last == 0) {
          return true;
        }
        --last;
      }
      if (std::tolower(s[first]) != std::tolower(s[last]))
        return false;
      ++first;
      --last;
    }
    return true;
  }
};
