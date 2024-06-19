#include "lambda.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>

// by_value_t by_value;
// by_ref_t by_ref;
// cmp_lambda_t cmp_lambda;
// int g_counter = 0;

void init_globals() {
        by_value = [](std::vector<int> nums) -> std::vector<int> {
                std::vector<int> ret = std::vector<int>();
                for (auto num : nums) {
                        if (num % 2 == 0) {
                                ret.push_back(num);
                        }
                }
                return ret;
        };

        by_ref = [](std::vector<int>& nums) -> std::vector<int> {
                std::vector<int> ret = std::vector<int>();
                for (auto num : nums) {
                        if (num % 2 == 0) {
                                ret.push_back(num);
                        }
                }
                return ret;
        };

        cmp_lambda = [](int& a, int& b) -> bool {
                g_counter++;
                return std::abs(a) < std::abs(b);
        };
}

std::vector<int> ascending_sort(std::vector<int>& vec) {
        std::sort(vec.begin(), vec.end(), cmp_lambda);
        std::cout << g_counter << std::endl;
        return vec;
}

// int main (){
//         init_globals();
//         std::vector<int> vec = {1, 2, 4, 7, 6};
//         std::vector<int> even = by_ref(vec);
//         for (int num : even) {
//                 std::cout << num << " ";
//         }
        
//         std::vector<int> sort = ascending_sort(vec);
//         for (int num : sort) {
//                 std::cout << num << " ";
//         }
// }