#include "SmartArray.h"

int main(){
    SmartArray<int> nums;

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);

    nums[nums.size() - 2] = 100;
    nums.pop_back();

    for (int num : nums){
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    SmartArray<int> nums2(nums);

    nums2[1] = 150;
    nums2[2] = 267;

    nums = std::move(nums2);

    std::cout << "Nums 1:\n";
    nums.print();

    std::cout << "Nums 2:\n";
    nums2.print();
}