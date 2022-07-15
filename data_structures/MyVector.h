#ifndef AND_MYVECTOR_H
#define AND_MYVECTOR_H

#include <algorithm>


template<typename T>
class MyVector {
public:
    explicit MyVector(int sz = 0) : m_size(sz), m_capacity(sz + ADDITIONAL_CAPACITY) {
        m_buffer = new T[m_capacity];
    }

    MyVector(const MyVector &mv) : m_size(mv.m_size), m_capacity(mv.m_capacity) {
        m_buffer = new T[m_capacity];
        for (int i = 0; i < m_size; i++) {
            m_buffer[i] = mv.m_buffer[i];
        }
    }

    MyVector(MyVector &&mv) noexcept: m_size(mv.m_size), m_capacity(mv.m_capacity), m_buffer(mv.m_buffer) {
        mv.m_buffer = nullptr;
        mv.m_size = 0;
        mv.m_capacity = 0;
    }

    ~MyVector() {
        delete[] m_buffer;
    }

    MyVector &operator=(const MyVector &mv) {
        if (this == &mv) {
            return *this;
        }

        m_size = mv.m_size;
        m_capacity = mv.m_capacity;
        delete[] m_buffer;
        m_buffer = new T[m_size];
        for (int i = 0; i < m_size; i++) {
            m_buffer[i] = mv.m_buffer[i];
        }

        // MyVector t = mv;
        // std::swap(*this, copy);
        return *this;
    }

    MyVector &operator=(MyVector &&mv) noexcept {
        m_size = mv.m_size;
        m_capacity = mv.m_capacity;
        m_buffer = mv.m_buffer;

        mv.m_buffer = nullptr;
        mv.m_size = 0;
        mv.m_capacity = 0;
        // std::swap(m_size, mv.m_size);
        // std::swap(m_capacity, mv.m_capacity);
        // std::swap(m_buffer, mv.m_buffer);
        return *this;
    }

    void reserve(int newCapacity) {
        if (newCapacity < m_size) {
            return;
        }

        T *tmp = new T[newCapacity];
        for (int i = 0; i < m_size; ++i) {
            tmp[i] = std::move(m_buffer[i]);
        }

        m_capacity = newCapacity;
//        std::swap(m_buffer, tmp);

        delete[] m_buffer;
        m_buffer = tmp;
//        delete[] tmp;
    }

    void resize(int newSize) {
        if (newSize > m_capacity) {
            reserve(newSize * 2);
        }
        m_size = newSize;
    }

    T &operator[](int idx) {
        return m_buffer[idx];
    }

    const T &operator[](int idx) const {
        return m_buffer[idx];
    }

    bool empty() const {
        return m_size == 0;
    }

    int size() const {
        return m_size;
    }

    int capacity() const {
        return m_capacity;
    }

    void push_back(const T &t) {
        if (m_size == m_capacity) {
            reserve(2 * m_capacity);
        }
        m_buffer[m_size++] = t;
    }

    void push_back(T &&t) {
        if (m_size == m_capacity) {
            reserve(2 * m_capacity);
        }
        m_buffer[m_size++] = std::move(t);
    }

    void pop_back() {
        --m_size;
    }

    const T &back() const {
        return m_buffer[m_size - 1];
    }

    typedef T *iterator;
    typedef const T *const_iterator;

    iterator begin() {
        return &m_buffer[0];
    }

    iterator end() {
        return &m_buffer[m_size];
    }

    const_iterator cbegin() const {
        return &m_buffer[0];
    }

    const_iterator cend() const {
        return &m_buffer[m_size];
    }

    static const int ADDITIONAL_CAPACITY = 16;

private:
    int m_size;
    int m_capacity;
    T *m_buffer;
};


#endif //AND_MYVECTOR_H
