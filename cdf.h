#include "functor.h"

class Accumulator : IAccumulator {
        float sum = 0;
        public:
        float operator() (const float& p){
                sum += p;
                return sum;
        }
};

template<typename F>
std::vector<float> cdf(const std::vector<float>& pdfv, F& acc) {
        std::vector<float> ret;
        for (auto& val : pdfv) {
                ret.push_back(acc(val));
        }
        return ret;
}

