#include <vector>
#include <iostream>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    size_t n = matrix.size();
    size_t nn = matrix[0].size();


    //not O(log(n * m)) but who cares... at worse its O(n)
    //if the last element (the greatest) of the current subArray is less than the target, continune to the next array,
    //because it is not possible to be found
    for(int i = 0; i < n; i++) {
        if (matrix[i][nn - 1] < target) {
            continue;
        } else {
            //just do binary search
            int low = 0;
            int high = nn - 1;
            while (low <= high) {
                int midpoint = (low + high) / 2;

                if (matrix[i][midpoint] == target) {
                    return true;
                } else if (matrix[i][midpoint] > target) {
                    high = midpoint - 1;
                } else {
                    low = midpoint + 1;
                }
            }
            return false;
        }
    }
    return false;
}

int main() {
    std::vector<std::vector<int>> mat =  {{1, 1}};
    std::cout << searchMatrix(mat, 0);
}
