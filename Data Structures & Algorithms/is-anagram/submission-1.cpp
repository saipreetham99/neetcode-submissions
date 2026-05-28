class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
    if (s.size() != t.size()) {
      return false;
    }
    std::unordered_map<char, int> s_freq{};
    std::unordered_map<char, int> t_freq{};
    for (auto i : s) {
      if (s_freq.count(i)) {
        s_freq[i] += 1;
      } else {
        s_freq.emplace(i, 1);
      }
    }
    for (auto i : t) {
      if (t_freq.count(i)) {
        t_freq[i] += 1;
      } else {
        t_freq.emplace(i, 1);
      }
    }
    for (auto i : s) {
      if (s_freq[i] != t_freq[i]) {
        return false;
      }
    }
    return true;
  }
};
