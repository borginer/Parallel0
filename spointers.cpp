#include <memory>
#include <vector>
#include <iostream>
#include <ctime>

using std::unique_ptr;
using std::vector;

int main() { 
        std::clock_t start = std::clock();

        vector<unique_ptr<int>> nums;
        for (int i = 0; i < 10000; i++) {
                nums.push_back(unique_ptr<int>(new int(i * 10)));
        }

        int sum = 0;
        for (const auto &num : nums) {
                sum += *num;
        }
        std::cout << "Sum: " << sum << std::endl;

        std::clock_t end = std::clock();
        double duration = double(end - start) / CLOCKS_PER_SEC;

        std::cout << "Time Taken: " << duration << std::endl;
        return 0;
}
