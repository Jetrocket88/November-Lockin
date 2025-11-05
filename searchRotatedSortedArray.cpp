#include <vector>
#include <iostream> 

using namespace std;

int search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    while(l <= r) {

        int m = (l + r) / 2;
        if (nums[m] == target) {
            return m;
        } else if (nums[r] == target) {
            return r;
        } else if (nums[l] == target) {
            return l;
        }
        


        if (nums[l] < nums[m])  {
            //the left is the sorted array 
            if (nums[l] <= target && nums[m] > target) {
                //it can conatain the target,
                //move to the left 
                r = m - 1;
            } else {
                //it cannot contain the target,
                //move to the right 
                l = m + 1;
            }
        } else {
            //the right is the sorted array
            if (nums[m] < target && nums[r] >= target) {
                //it can contain the target
                //move to the right
                l = m + 1;
            } else {
                //it cannot contain the target
                //move to the left
                r = m - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {3,1};
    std::cout << search(nums, 1);
}
