//
// Created by emir on 12.07.22.
//

#ifndef AND_MYVECTOR_H
#define AND_MYVECTOR_H

#include <algorithm>

template<typename T>
class MyVector {
public:
    explicit MyVector(int sz = 0);

    MyVector(const MyVector &mv);

    MyVector(MyVector &&mv) noexcept;

    ~MyVector();

    MyVector &operator=(const MyVector &mv);

    MyVector &operator=(MyVector &&mv) noexcept;

    void reserve(int newCapacity);

    void resize(int newSize);

    T &operator[](int idx);

    const T &operator[](int idx) const;

    bool empty() const;

    int size() const;

    int capacity() const;

    void push_back(const T &t);

    void push_back(T &&t);

    void pop_back();

    const T &back() const;

    typedef T *iterator;
    typedef const T *const_iterator;

    iterator begin();

    iterator end();

    const_iterator cbegin() const;

    const_iterator cend() const;

    static const int ADDITIONAL_CAPACITY = 16;

private:
    int m_size;
    int m_capacity;
    T *m_buffer;
};

template<typename T>
MyVector<T>::MyVector(int sz) : m_size(sz), m_capacity(sz + ADDITIONAL_CAPACITY) {
    m_buffer = new T[m_capacity];
}

template<typename T>
MyVector<T>::MyVector(const MyVector &mv) : m_size(mv.m_size), m_capacity(mv.m_capacity) {
    m_buffer = new T[m_capacity];
    for (int i = 0; i < m_size; i++) {
        m_buffer[i] = mv.m_buffer[i];
    }
}

template<typename T>
MyVector<T>::MyVector(MyVector &&mv) noexcept : m_size(mv.m_size), m_capacity(mv.m_capacity), m_buffer(mv.m_buffer) {
    mv.m_buffer = nullptr;
    mv.m_size = 0;
    mv.m_capacity = 0;
}

template<typename T>
MyVector<T>::~MyVector() {
    delete[] m_buffer;
}

template<typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector &mv) {
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

template<typename T>
MyVector<T> &MyVector<T>::operator=(MyVector &&mv) noexcept {
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

template<typename T>
void MyVector<T>::reserve(int newCapacity) {
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

template<typename T>
void MyVector<T>::resize(int newSize) {
    if (newSize > m_capacity) {
        reserve(newSize * 2);
    }
    m_size = newSize;
}

template<typename T>
T &MyVector<T>::operator[](int idx) {
    return m_buffer[idx];
}

template<typename T>
const T &MyVector<T>::operator[](int idx) const {
    return m_buffer[idx];
}

template<typename T>
bool MyVector<T>::empty() const {
    return m_size == 0;
}

template<typename T>
int MyVector<T>::size() const {
    return m_size;
}

template<typename T>
int MyVector<T>::capacity() const {
    return m_capacity;
}

template<typename T>
void MyVector<T>::push_back(const T &t) {
    if (m_size == m_capacity) {
        reserve(2 * m_capacity);
    }
    m_buffer[m_size++] = t;
}

template<typename T>
void MyVector<T>::push_back(T &&t) {
    if (m_size == m_capacity) {
        reserve(2 * m_capacity);
    }
    m_buffer[m_size++] = std::move(t);
}

template<typename T>
void MyVector<T>::pop_back() {
    --m_size;
}

template<typename T>
const T &MyVector<T>::back() const {
    return m_buffer[m_size - 1];
}

template<typename T>
T *MyVector<T>::begin() {
    return &m_buffer[0];
}

template<typename T>
T *MyVector<T>::end() {
    return &m_buffer[m_size];
}

template<typename T>
const T *MyVector<T>::cbegin() const {
    return &m_buffer[0];
}

template<typename T>
const T *MyVector<T>::cend() const {
    return &m_buffer[m_size];
}


#endif //AND_MYVECTOR_H
