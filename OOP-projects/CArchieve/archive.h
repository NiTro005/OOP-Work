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
    void repacking();

    void push_back(T value);             // вставка элемента (в конец)
    void pop_back();                     // удаление элемента (из конца)
    void push_front(T value);            // вставка элемента (в начало)
    void pop_front();                    // удаление элемента (из начала)

    TArchive& insert(const T* arr, size_t n, size_t pos);
    TArchive& insert(T value, size_t pos);

    TArchive& replace(size_t pos, T new_value);

    TArchive& erase(size_t pos, size_t n);
    //TArchive& remove_all(T value);
    //TArchive& remove_first(T value);
    //TArchive& remove_last(T value);
    TArchive& remove_by_index(size_t pos);

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
    repacking();
    if (n < _capacity || _size < _capacity) {
        return;
    }
    _capacity = (n / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    if (_capacity > 45) {
        throw std::logic_error("Error in function \
\"void TArchive <T>::reserve(size_t n)\": complete max size of capacity.");
    }
    T* newData = new T[_capacity];
    std::memcpy(newData, _data, _size);
    delete[] _data;
    _data = newData;
    State* newDat = new State[_capacity];
    std::memcpy(newDat, _states, _size);
    delete[] _states;
    _states = newDat;
}

template <typename T>
void TArchive<T>::repacking() {
    int count = _deleted;
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] == State::deleted) {
            for (size_t j = i; j < _size - _deleted; j++) {
                _data[j] = _data[j + 1];
                _states[j] = _states[j + 1];
            }
            _states[_size - _deleted] = State::deleted;
            _deleted--;
        }
    }
    _size -= count;
    T* new_data = new T[_capacity];
    for (size_t i = 0, j = 0; i < _size; i++) {
        if (_states[i] != State::deleted) {
            new_data[j++] = _data[i];
        }
    }
    delete[] _data;
    _data = new_data;
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
        if (_capacity < 45) {
            this->reserve();
        }
        else { 
            replace(pos, value); 
            return *this;
        }
    }
    for (size_t i = _size; i > pos; i--) {
        _data[i] = _data[i - 1];
        _states[i + 1] = State::busy;
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

    if((_capacity - _size) < n) {
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
void TArchive<T>::push_back(T value) {
    if (this->full()) {
        if (_capacity < 45) {
            this->reserve();
        }
        else {
            replace(_size, value);
            return;
        }
    }
    _data[_size] = value;
    _states[_size] = State::busy;
    _size++;
}

template <typename T>
void TArchive<T>::push_front(T value) {
    if (this->full()) {
        if (_capacity < 45) {
            this->reserve();
        }
        else {
            replace(0, value);
            return;
        }
    }
    for (size_t i = _size; i > 0; i--) {
        _data[i] = _data[i - 1];
        _states[i + 1] = State::busy;
    }
    _data[0] = value;
    _states[0] = State::busy;
    _size++;
}

template <typename T>
void TArchive<T>::pop_front() {
    if (_size <= 0) {
        throw std::logic_error("Error in function \
\"void TArchive<T>::pop_front()\": archive clear");
    }
    for (size_t i = 1; i < _size; i++) {
        _data[i - 1] = _data[i];
        _states[i - 1] = _states[i];
    }
    _states[_size - 1] = State::deleted;
    _deleted++;
    _size--;

}

template <typename T>
void TArchive<T>::pop_back() {
    if (_size <= 0) {
        throw std::logic_error("Error in function \
\"void TArchive<T>::pop_back()\": archive clear");
    }
    _states[_size - 1] = State::empty;
    --_size;
}

template <typename T>
TArchive<T>& TArchive<T> ::remove_by_index(size_t pos) {
    if (_size <= pos || pos < 0) {
        throw std::logic_error("Error in function \
\"TArchive<T>& TArchive<T> ::remove_by_index(size_t pos)\": wrong position value.");
    }
    _states[pos] = State::deleted;
    _deleted++;
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::erase(size_t pos, size_t n) {
    if (_size < pos) {
        throw std::logic_error("Error in function \
\"TArchive<T>& TArchive<T>::erase(size_t pos, size_t n)\": wrong position value.");
    }
    for (size_t i = pos; i < pos + n; i++) {
        _states[i] = State::deleted;
    }
    _deleted = n;
}

template <typename T>
TArchive<T>& TArchive<T>::replace(size_t pos, T new_value) {
    _data[pos] = new_value;
    _states[pos] = State::busy;
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
