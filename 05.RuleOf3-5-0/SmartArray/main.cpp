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

    nums.print();

    // for (int num : nums){

    // }
}