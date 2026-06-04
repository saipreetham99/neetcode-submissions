class Solution {
public:
    void reverseString(std::vector<char> &s) {
    int front{};
    int back{int(s.size()) - 1};

    while (back > front) {
      auto tmp{s[front]};
      s[front] = s[back];
      s[back] = tmp;
      ++front;
      --back;
    }
  }
};