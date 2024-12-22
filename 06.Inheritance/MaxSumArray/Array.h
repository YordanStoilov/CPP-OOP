template <class T>
class Array {
    class Iterator {
    public:
        Iterator(const Array& container, size_t index) : container(container), index(index)
        { }
        T operator*() const {
            return container.data[index];
        }
        Iterator& operator++() {
            index++;
            return *this;
        }
        bool operator==(const Iterator& other) const {
            return index == other.index;
        }
        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    private:
        const Array& container;
        size_t index;
};

public:
    Array(size_t size) : data(new T[size]), size(size)
    {}

    Array& operator=(const Array& other) {
        T* newArr = new T[other.size];

        for (size_t i = 0; i < other.size; ++i) {
            newArr[i] = other.data[i];
        }
        delete[] data;
        data = newArr;
        size = other.size;
        return *this;
    }
    Array(const Array& other) : data(nullptr), size(0) {
        *this = other;
    }
    ~Array() {
        delete[] data;
    }
    T& operator[](size_t idx) {
        return data[idx];
    }
    size_t getSize() { return size; }

    typename Array<T>::Iterator begin() {
        return Iterator(*this, 0);
    }

    typename Array<T>::Iterator end() {
        return Iterator(*this, size);
    }

private:
    T* data;
    size_t size;
};