class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    //
    int total_gas{};
    int total_cost{};
    for (int i = 0; i < gas.size(); ++i) {
      total_gas += gas[i];
      total_cost += cost[i];
    }
    if (total_cost > total_gas)
      return -1;
    int current_gas{};
    int resultIndex{};
    for (int i = 0; i < gas.size(); ++i) {
      current_gas = current_gas + gas[i] - cost[i];
      if (current_gas <= 0) {
        current_gas = 0;
        if (i + 1 >= gas.size())
          resultIndex = 0;
        else
          resultIndex = i + 1;
      }
    }
    return resultIndex;
  }
};
