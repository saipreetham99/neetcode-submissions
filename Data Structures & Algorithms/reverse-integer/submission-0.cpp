class Solution {
public:
    int reverse(int x) {
    int MAX{std::numeric_limits<int>::max()};
    int MIN{std::numeric_limits<int>::lowest()};
    int result{};
    bool negative{false};
    if (x < 0) {
      x = std::abs(x);
      negative = true;
    }
    while (x > 0) {
      if (result > MAX / 10) {
        return 0;
      }
      result = (10 * result) + x % 10;
      x = x / 10;
    }
    return negative ? -1 * result : result;
  }
};
