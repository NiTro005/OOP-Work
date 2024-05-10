#pragma once
#include <iostream>
#define STEP_CAPACITY 15
#define MAX_CAPACITY 100000

enum State { empty, busy, deleted };

namespace algorithm {
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
    TArchive(const TArchive& archive);
    TArchive(const T* arr, size_t n);
    TArchive(size_t n, T value);
    TArchive(const TArchive& archive, size_t pos, size_t n);

    ~TArchive();

    void print() const noexcept;

    inline bool empty() const noexcept;
    inline bool full() const noexcept;

    size_t size();
    size_t capacity();
    const T* data() const;

    void swap(TArchive& archive);

    TArchive& assign(const TArchive& archive);

    void clear();
    void resize(size_t n, T* value = nullptr);
    void reserve(size_t n = 15);

    void push_back(T value);             // вставка элемента (в конец)
    void pop_back();                     // удаление элемента (из конца)
    void push_front(T value);            // вставка элемента (в начало)
    void pop_front();                    // удаление элемента (из начала)

    TArchive& insert(const T* arr, size_t n, size_t pos);
    TArchive& insert(T value, size_t pos);

    TArchive& replace(size_t pos, T new_value);

    TArchive& erase(size_t pos, size_t n);
    TArchive& remove_all(T value);
    TArchive& remove_first(T value);
    TArchive& remove_last(T value);
    TArchive& remove_by_index(size_t pos);

    size_t* find_all(T value) const noexcept;
    size_t find_first(T value) const;
    size_t find_last(T value) const;

    T& operator[](size_t index);

    const T& operator[](size_t index) const;

private:
    size_t count_value(T value)  const noexcept;
    void repacking();
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
TArchive<T>::TArchive(const TArchive& archive) {
    _capacity = archive._capacity;
    _size = archive._size;
    _deleted = archive._deleted;

    _data = new T[_capacity];
    _states = new State[_capacity];

    for (size_t i = 0; i < _size; i++) {
        _data[i] = archive._data[i];
        _states[i] = archive._states[i];
    }
}

//  онструктор инициализации массивом
template <typename T>
TArchive<T>::TArchive(const T* arr, size_t n) {
    _capacity = n;
    _size = n;
    _deleted = 0;

    _data = new T[_capacity];
    _states = new State[_capacity];

    for (size_t i = 0; i < _size; i++) {
        _data[i] = arr[i];
        _states[i] = State::occupied;
    }
}

//  онструктор инициализации значени€ми
template <typename T>
TArchive<T>::TArchive(size_t n, T value) {
    _capacity = n;
    _size = n;
    _deleted = 0;

    _data = new T[_capacity];
    _states = new State[_capacity];

    for (size_t i = 0; i < _size; i++) {
        _data[i] = value;
        _states[i] = State::busy;
    }
}

//  онструктор копировани€ с учетом позиции и количества элементов
template <typename T>
TArchive<T>::TArchive(const TArchive& archive, size_t pos, size_t n) {
    _capacity = n;
    _size = n;
    _deleted = 0;

    _data = new T[_capacity];
    _states = new State[_capacity];

    for (size_t i = 0; i < n; i++) {
        if (pos + i < archive._size) {
            _data[i] = archive._data[pos + i];
            _states[i] = archive._states[pos + i];
        }
        else {
            _data[i] = T();
            _states[i] = State::empty;
        }
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
const T* TArchive<T> ::data() const{
    return _data;
}

template <typename T>
void TArchive <T>::swap(TArchive& archive) {
    algorithm::swap(_size, archive._size);
    algorithm::swap(_capacity, archive._capacity);
    algorithm::swap(_data, archive._data);
    algorithm::swap(_states, archive._states);
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
void TArchive <T>::resize(size_t n, T* value) {
    if (n <= _size) {
        for (size_t i = _size; i >= n; i--) {
            _states[i] = State::empty;
        }
        _size = n;
    }
    else {
        reserve(n);
        for (size_t i = _size; i < n; ++i) {
            _data[i] = *value;
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
    if (_capacity > MAX_CAPACITY) {
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
    int step = 0; 
    int newSize = 0; 
    for (int i = 0; i < _size; i++) {
        if (_states[i] == State::deleted) {
            step++;
        }
        else {
            _data[i - step] = _data[i];
            _states[i - step] = _states[i];
        }
    }
    newSize = _size - step;
    for (int i = newSize; i < _size; i++) {
        _states[i] = State::empty;
    }
    _size = newSize;
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
        _states[i] = _states[i - 1];
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
        _states[i + n - 1] = _states[i - 1];
    }
    for (size_t i = 0; i < n; ++i) {
        _data[pos + i] = arr[i];
        _states[pos + i] = State::busy;
    }
    _size += n;
    return *this;
}

template <typename T>
void TArchive<T>::push_back(T value) {
    if (this->full()) {
        this->reserve();
    }
    _data[_size] = value;
    _states[_size] = State::busy;
    _size++;
}

template <typename T>
void TArchive<T>::push_front(T value) {
    if (this->full()) {
        this->reserve();

    }
    for (size_t i = _size; i > 0; i--) {
        _data[i] = _data[i - 1];
        _states[i] = _states[i - 1];
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
TArchive<T>& TArchive<T>::remove_all(T value) {
    if (_size <= 0) {
        throw std::logic_error("Error in function \
\"TArchive<T>& TArchive<T>::remove_all(T value)\": archive clear");
    }
    for (size_t i = 0; i < _size; i++) {
        if (_data[i] == value) {
            _states[i] = State::deleted;
            _deleted++;
        }
    }
}

template <typename T>
TArchive<T>& TArchive<T>::remove_first(T value) {
    if (_size <= 0) {
        throw std::logic_error("Error in function \
\"TArchive<T>& TArchive<T>::remove_first(T value)\": archive clear");
    }
    for (size_t i = 0; i < _size; i++) {
        if (_data[i] == value) {
            _states[i] = State::deleted;
            break;
        }
    }
    _deleted++;
}

template <typename T>
TArchive<T>& TArchive<T>::remove_last(T value) {
    if (_size <= 0) {
        throw std::logic_error("Error in function \
\"TArchive<T>& TArchive<T>::remove_last(T value)\": archive clear");
    }
    for (size_t i = _size; i > 0; i--) {
        if (_data[i] == value) {
            _states[i] = State::deleted;
            break;
        }
    }
    _deleted++;
}

template <typename T>
size_t TArchive<T>::find_first(T value) const{
    for (size_t i = 0; i < _size; i++) {
        if (_data[i] == value && _states[i] != State::deleted) {
            return i;
        }
    }
    throw std::logic_error("Error in function \
\"size_t TArchive<T>::find_first(T value)\":No mathes");
}


template <typename T>
size_t TArchive<T>::find_last(T value) const {
    for (size_t i = _size; i > 0; i--) {
        if (_data[i] == value && _states[i] != State::deleted ) {
            return i;
        }
    }
    throw std::logic_error("Error in function \
\"size_t TArchive<T>::find_first(T value)\":No mathes");
}

template <typename T>
size_t* TArchive<T>::find_all(T value) const noexcept {
    size_t count = this->count_value(value);
    if (count == 0) { return nullptr; }
    size_t* found_positions = new size_t[count + 1];
    found_positions[0] = count;
    size_t found_count = 0;

    for (size_t i = 0; i < _size; ++i) {
        if (_data[i] == value && _states[i] != State::deleted) {
            found_positions[++found_count] = i;
        }
    }

    return found_positions;
}

template <typename T>
TArchive<T>& TArchive<T>::replace(size_t pos, T new_value) {
    if (_data[pos] != State::busy) {
        throw std::logic_error("Error in function \
\"TArchive<T>& replace(size_t pos, T new_value)\":No mathes");
    }
    if(_data[pos] )
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

template <typename T>
size_t TArchive<T>::count_value(T value) const noexcept {
    size_t count = 0;
    for (size_t i = 0; i < _size; i++) {
        if (_data[i] == value) {
            count++;
        }
    }
    return count;
}

template <typename T>
T& TArchive<T>::operator[](size_t index) {
    return _data[index];
}

template <typename T>
const T& TArchive<T>::operator[](size_t index) const {
    return _data[index];
}