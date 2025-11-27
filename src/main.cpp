#include <iostream>
#include <vector>
#include "ArrayProblems.h"

int main() {
    std::cout << "--- Debugging Sandbox ---" << std::endl;

    // Quick manual test
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    // Call the function from your library
    std::vector<int> result = ArrayProblems::twoSum(nums, target);

    if (!result.empty()) {
        std::cout << "Indices: " << result[0] << ", " << result[1] << std::endl;
    } else {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}