#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

int findMin(vector<int> &nums) {

    size_t n = nums.size();  
    int l = 0;
    int answer = nums[0];
    int r = n - 1;

    while (l <= r) {

        if (nums[l] <  nums[r]) {
            answer = min(answer, nums[l]);
            break;
        }

        int midpoint = (l + r) / 2;
        answer = min(answer, nums[midpoint]);
        if (nums[midpoint] >= nums[l]) {
            l = midpoint + 1;
        } else {
            r = midpoint - 1;
        }
    }
    return answer;
}

int main() {
    vector<int> list = {3, 4, 5, 6, 1, 2, 3};
    cout << findMin(list);
}
