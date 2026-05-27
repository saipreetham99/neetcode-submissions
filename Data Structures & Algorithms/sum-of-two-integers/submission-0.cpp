class Solution {
public:
      int getSum(int a, int b) {
    return getDecimal(addBinary(getBinary(a), getBinary(b)));
  }

  int getDecimal(const std::vector<int> &a) {
    int result = -a[0] * (1 << 31); // sign bit -- negative contribution
    for (int index{1}; index < (int)a.size(); ++index) {
      result += (1 << (31 - index)) * a[index];
    }
    return result;
  }

  std::vector<int> addBinary(const std::vector<int> &a,
                             const std::vector<int> &b) {
    int carry{};
    std::vector<int> result{};
    for (auto index{(int)a.size() - 1}; index >= 0; --index) {
      if (a[index] == 1 && b[index] == 1) {
        if (carry == 1) {
          result.push_back(1);
        } else {
          result.push_back(0);
        }
        carry = 1;
      } else if ((a[index] ^ b[index]) == 1) {
        if (carry == 1) {
          result.push_back(0);
        } else {
          result.push_back(1);
        }
      } else {
        result.push_back(carry);
        carry = 0;
      }
    }
    std::reverse(result.begin(), result.end());
    return result;
  }

  std::vector<int> getBinary(int a) {
    bool negative = false;
    std::vector<int> binary{};
    if (a < 0) {
      negative = true;
      a = std::abs(a);
    }
    while (a > 0) {
      binary.push_back(a % 2);
      a = a / 2;
    }
    padZeros(binary);
    if (!negative) {
      std::reverse(binary.begin(), binary.end());
      return binary;
    } else {
      for (std::size_t index{}; index < binary.size(); ++index) {
        if (binary[index] == 1) {
          binary[index] = 0;
        } else {
          binary[index] = 1;
        }
      }
      std::reverse(binary.begin(), binary.end());
      std::vector<int> one(32, 0);
      one[31] = 1;
      return addBinary(binary, one);
    }
  }

  void padZeros(std::vector<int> &vec) {
    for (std::size_t zero{32 - vec.size()}; zero > 0; --zero) {
      vec.push_back(0);
    }
  }

};
