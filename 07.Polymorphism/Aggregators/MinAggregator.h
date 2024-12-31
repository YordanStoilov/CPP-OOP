#ifndef MIN_AGGREGATOR_H

#define MIN_AGGREGATOR_H
class MinAggregator : public StreamAggregator {
public:
    MinAggregator(std::istringstream& stream) : StreamAggregator(stream) 
    {}

    virtual void aggregate(int next) override {
        StreamAggregator::aggregate(next);

        if (getNumAggregated() == 1) {
            aggregationResult = next;
            return;
        }
        if (next < aggregationResult) {
            aggregationResult = next;
        }
    }
    virtual ~MinAggregator() override {} 
};

#endif