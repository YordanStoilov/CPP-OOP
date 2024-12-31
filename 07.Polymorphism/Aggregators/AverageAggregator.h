#ifndef AVERAGE_AGGREGATOR_H
#define AVERAGE_AGGREGATOR_H

#include <numeric>
#include <vector>
class AverageAggregator : public StreamAggregator {
public:
    AverageAggregator(std::istringstream& stream) : StreamAggregator(stream)
    {}
    virtual void aggregate(int next) override {
		StreamAggregator::aggregate(next);
        nums.push_back(next);

        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        aggregationResult = sum / getNumAggregated();
	}
    virtual ~AverageAggregator() override {}
private:
    std::vector<int> nums;
};
#endif