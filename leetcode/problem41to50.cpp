//
// Created by fyabc on 2019/12/21.
//

#include "support/IO.h"

#include <algorithm>
#include <vector>

using namespace std;

class Solution41 {
public:
    static int firstMissingPositive(vector<int>& nums) {
        int result = 1;

        auto maxNumIt = max_element(nums.begin(), nums.end());
        return result;
    }
};
