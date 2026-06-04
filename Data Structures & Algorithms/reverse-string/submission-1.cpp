class Solution {
public:
  void reverseString(std::vector<char> &s) {
    int front{};
    int back{int(s.size()) - 1};
    while (back > front) {
      std::swap(s[front++], s[back--]);
    }
  }

};