class Solution {
public:
    std::vector<int> sortArray(std::vector<int> &nums) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap{};
    std::vector<int> sortedNums{};
    for (auto i : nums) {
      minHeap.push(i);
    }
    while (!minHeap.empty()) {
      sortedNums.push_back(minHeap.top());
      minHeap.pop();
    }
    return sortedNums;
  }
};