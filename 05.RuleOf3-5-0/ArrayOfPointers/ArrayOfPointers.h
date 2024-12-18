class ArrayOfPointers{
public:
    void add(Company* c){
        data.push_back(c);
    }
    size_t getSize() const {
        return data.size();
    }
    Company* get(size_t idx) {
        return data[idx];
    }
private:
    std::vector<Company*> data;
};