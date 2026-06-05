class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        std::vector<int> temp(nums.size());   // single buffer, allocated once
        mergeSort(nums, temp, 0, (int)nums.size() - 1);
        return nums;
    }

private:
    void mergeSort(std::vector<int>& nums, std::vector<int>& temp, int lo, int hi) {
        if (lo >= hi) return;
        int mid = lo + (hi - lo) / 2;   // avoids overflow vs (lo+hi)/2
        mergeSort(nums, temp, lo, mid);
        mergeSort(nums, temp, mid + 1, hi);
        merge(nums, temp, lo, mid, hi);
    }

    void merge(std::vector<int>& nums, std::vector<int>& temp, int lo, int mid, int hi) {
        for (int i = lo; i <= hi; i++)
            temp[i] = nums[i];

        int left = lo, right = mid + 1, k = lo;
        while (left <= mid && right <= hi)
            nums[k++] = (temp[left] <= temp[right]) ? temp[left++] : temp[right++];

        while (left <= mid)  nums[k++] = temp[left++];
        while (right <= hi)  nums[k++] = temp[right++];
    }
};