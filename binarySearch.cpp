#include <vector>
#include <iostream>

int search(std::vector<int>& nums, int target) {
    size_t n = nums.size();
    int low = 0;
    int high = n - 1;

    while(low <= high) {
        int midpoint = (low + high) / 2;
        if (nums[midpoint] == target) {
            return midpoint;
        } else if (nums[midpoint] > target) { 
            high = midpoint - 1;
        } else {
            low = midpoint + 1;
        }
    }
    return -1;
}

int main() {
    std::vector<int> nums = {1, 1, 1, 1, 1};
    std::cout << search(nums, 0);
}
