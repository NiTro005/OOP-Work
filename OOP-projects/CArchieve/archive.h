#pragma once
#include <iostream>
#define STEP_CAPACITY 15

enum State { empty, busy, deleted };

namespace algorithms {
    template<typename T>
    inline void swap(T& val_1, T& val_2) noexcept {
        T tmp = val_1;
        val_1 = val_2;
        val_2 = tmp;
    }
}

template <typename T>
class TArchive {
    T* _data;                  // динамический массив данных
    State* _states;            // состо€ни€ €чеек
    size_t _capacity;          // реальный размер массива
    size_t _size;              // количество хранимых данных
    size_t _deleted;           // количество "удалЄнных" позиций
public:
    TArchive();
    //TArchive(const TArchive& archive);
    //TArchive(const T* arr, size_t n);
    //TArchive(size_t n, T value);
    //TArchive(const TArchive& archive, size_t pos, size_t n);

    ~TArchive();

    void print() const noexcept;

    inline bool empty() const noexcept;
    inline bool full() const noexcept;

    size_t size();
    size_t capacity();
    const T* data();

    void swap(TArchive& archive);

    TArchive& assign(const TArchive& archive);

    void clear();
    void resize(size_t n, T value);
    void reserve(size_t n = 15);

    //void push_back(T value);             // вставка элемента (в конец)
    //void pop_back();                     // удаление элемента (из конца)
    //void push_front(T value);            // вставка элемента (в начало)
    //void pop_front();                    // удаление элемента (из начала)

    TArchive& insert(const T* arr, size_t n, size_t pos);
    TArchive& insert(T value, size_t pos);

    //TArchive& replace(size_t pos, T new_value);

    //TArchive& erase(size_t pos, size_t n);
    //TArchive& remove_all(T value);
    //TArchive& remove_first(T value);
    //TArchive& remove_last(T value);
    //TArchive& remove_by_index(size_t pos);

    //size_t* find_all(T value) const noexcept;
    //size_t find_first(T value);
    //size_t find_last(T value);
private:
    //size_t count_value(T value);
};

template <typename T>
TArchive<T>::TArchive() {
    _size = 0;
    _capacity = STEP_CAPACITY;
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < STEP_CAPACITY; i++) {
        _states[i] = State::empty;
    }
}
template <typename T>
size_t TArchive<T>::size() {
    return _size;
}
template <typename T>
size_t TArchive<T>::capacity() {
    return _capacity;
}

template <typename T>
const T* TArchive<T> ::data() {
    return _data;
}

template <typename T>
void TArchive <T>::swap(TArchive& archive) {
    algorithms::swap(_size, archive._size);
    algorithms::swap(_capacity, archive._capacity);
    algorithms::swap(_data, archive._data);
    algorithms::swap(_states, archive._states);
}

template <typename T>
TArchive<T>& TArchive <T>::assign(const TArchive& archive) {
    _size = archive._size;
    _capacity = archive._capacity;
    _data = new T[_capacity];
    _states = new T[_capacity];
    for (int i = 0; i < _size; i++) {
        _data[i] = archive._data[i];
        _states[i] = archive.data[i];
    }
    return *this;
}

template <typename T>
void TArchive<T>::clear() {
    delete[] _data;
    delete[] _states;
    _size = 0;
    _capacity = 0;
}

template <typename T>
void TArchive <T>::resize(size_t n, T value) {
    if (n <= _size) {
        for (size_t i = _size; i >= n; i--) {
            _states[i] = State::empty;
        }
        _size = n;
    }
    else {
        reserve(n);
        for (size_t i = _size; i < n; ++i) {
            _data[i] = value;
            _states[i] = State::busy;
        }
        _size = n;
    }
}

template <typename T>
void TArchive <T>::reserve(size_t n) {
    if (n < _capacity) {
        return;
    }
    _capacity = (n / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    if (_capacity >= 45) {
        throw std::logic_error("Error in function \
\"void TArchive <T>::reserve(size_t n)\": complete max size of capacity.");
    }
    char* newData = new char[_capacity];
    std::memcpy(newData, _data, _size);
    delete[] _data;
    _data = newData;
}

template <typename T>
TArchive<T>::~TArchive() {
    delete[] _data;
    _data = nullptr;
}

template <typename T>
inline bool TArchive<T>::empty() const noexcept {
    return _size == 0;
}

template <typename T>
inline bool TArchive<T>::full() const noexcept {
    return _size == _capacity;
}

template <typename T>
TArchive<T>& TArchive<T>::insert(T value, size_t pos) {
    if (_size < pos) {
        throw std::logic_error("Error in function \
\"TArchive<T>& insert(T value, size_t pos)\": wrong position value.");
    }
    
    if (this->full()) {
        this->reserve();
    }
    for (size_t i = _size; i > pos; i--) {
        _data[i] = _data[i - 1];
    }
    _data[pos] = value;
    _states[pos] = State::busy;
    _size++;
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::insert(const T* arr, size_t n, size_t pos) {
    if (_size < pos) {
        throw std::logic_error("Error in function \
\"TArchive<T>& insert(const T* arr, size_t n, size_t pos)\": wrong position value.");
    }

    if((_capacity - _size) <= n) {
        reserve(_size + n);
    }
    for (size_t i = _size; i > pos; i--) {
        _data[i + n - 1] = _data[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        _data[pos + i] = arr[i];
        _states[pos + i] = State::busy;
    }
    _size += n;
    return *this;
}

template <typename T>
void TArchive<T>::print() const noexcept {
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] != State::deleted) {
            std::cout << _data[i] << ", ";
        }
    }
}

/*
// пример реализации с возвратом массива найденных позиций
template <typename T>
size_t* TArchive<T>::find_all (T value) const noexcept {
    size_t count = this->count_value(value);
    if (count == 0) { return nullptr; }
    int* found_positions = new int[count + 1];
    found_positions[0] = count;

    // TBD

    return found_positions;
}
*/
