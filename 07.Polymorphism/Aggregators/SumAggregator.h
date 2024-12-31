#ifndef SUM_AGGREGATOR_H

#define SUM_AGGREGATOR_H
#include "Aggregator.h"
class SumAggregator : public StreamAggregator {
public:
    SumAggregator(std::istringstream& stream) : StreamAggregator(stream)
    {}
    virtual void aggregate(int next) override {
        StreamAggregator::aggregate(next);
		aggregationResult += next;
	} 
    virtual ~SumAggregator() override {}
};

#endif