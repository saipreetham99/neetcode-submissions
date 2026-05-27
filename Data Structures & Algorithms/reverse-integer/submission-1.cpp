class Solution {
public:
    int reverse(int x) {
    int MAX{std::numeric_limits<int>::max()};
    int MIN{std::numeric_limits<int>::lowest()};
    int result{};
    while (x != 0) {
      int digit{x % 10};
      if (result > MAX / 10 || result == MAX / 10 && digit > 7) {
        return 0;
      }
      if (result < MIN / 10 || result == MIN / 10 && digit < -8) {
        return 0;
      }
      result = (10 * result) + digit;
      x /= 10;
    }
    return result;
  }
};
