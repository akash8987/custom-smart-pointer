#include <iostream>

using namespace std;

template <typename T>
class SmartPointer {
private:
    T* ptr;

public:
    explicit SmartPointer(T* p = nullptr) : ptr(p) {}

    ~SmartPointer() {
        delete ptr;
    }

    // Disable copy
    SmartPointer(const SmartPointer&) = delete;
    SmartPointer& operator=(const SmartPointer&) = delete;

    // Enable move
    SmartPointer(SmartPointer&& other) noexcept {
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    SmartPointer& operator=(SmartPointer&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    bool isValid() const {
        return ptr != nullptr;
    }
};

int main() {
    SmartPointer<int> sp(new int(42));

    if (sp.isValid()) {
        cout << "Value: " << *sp << endl;
    }

    return 0;
}
