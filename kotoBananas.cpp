#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

int minEatingSpeed(std::vector<int>& piles, int h) {

    int maxEatingRate = *std::max_element(piles.begin(), piles.end());
    int minEatingRate = 1;
    int result = maxEatingRate;

    while(minEatingRate <= maxEatingRate) {

        int midpoint = (minEatingRate + maxEatingRate) / 2;
        int timeToEatAll = 0;
        
        for (int p : piles) {
            timeToEatAll += ceil(static_cast<double>(p) / midpoint);
        }

        if (timeToEatAll <= h) {
            //we have a possible solution, but we need to keep looking
            result = midpoint;
            maxEatingRate = midpoint - 1;

        } else {
            //we are too slow, so we speed up
            minEatingRate = midpoint + 1;
        } 
    }
   return result;
}

int main() {
    std::vector<int> piles = {25,10,23,4};
    std::cout << minEatingSpeed(piles, 4);
}
