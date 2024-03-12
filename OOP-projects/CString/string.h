#pragma once
#include <iostream>
#include <limits>
#include <stdexcept>

#define STEP_CAPACITY 15

namespace algorithms {
    template<typename T>
    void swap(T& val_1, T& val_2) {
        T tmp = val_1;
        val_1 = val_2;
        val_2 = tmp;
    }

    template<typename T>
    T max(T val_1, T val_2) {
        if (val_1 > val_2) return val_1;
        else return val_2;
    }

    template<typename T>
    T min(T val_1, T val_2) {
        if (val_1 < val_2) return val_1;
        else return val_2;
    }
}

class CString {
    char* _data;                  // хранилище данных
    size_t _size;                 // длина текста
    size_t _capacity;             // размер хранилища
    size_t _max_capacity = -1;    // максимально возможный размер хранилища

public:
    CString();
    CString(const CString& str);
    CString(const char* c_str);
    //CString(const char* c_str, size_t n);
    //CString(size_t n, char c);
    //CString(const CString& str, size_t pos, size_t len);

    ~CString();

    void print() const noexcept; 

    bool empty() const noexcept;
    //bool full() const noexcept;

    size_t size() const noexcept;
    //size_t capacity() const noexcept;
    //const char* data() const;

    //void swap(CString& str);
    //size_t copy(char* buf, size_t len, size_t pos = 0) const;
    //CString substr(size_t pos, size_t len) const;

    //CString& assign(const CString& str);
    //CString& assign(const CString& str, size_t pos, size_t len);
    //CString& assign(const char* s);
    //CString& assign(const char* s, size_t n);
    //CString& assign(size_t n, char c);

    int compare(const CString& str) const noexcept;
    //int compare(size_t pos, size_t len, const CString& str) const;
    //int compare(size_t pos, size_t len, const CString& str, size_t subpos, size_t sublen) const;
    //int compare(const char* s) const;
    //int compare(size_t pos, size_t len, const char* s) const;
    //int compare(size_t pos, size_t len, const char* s, size_t n) const;

    //void clear() noexcept;                    // очистка строки
    //void resize(size_t n, char c = '\0');     // изменение длины строки
    //void reserve(size_t n = 0);               // увеличение хранилища

    //void push_back(char c);                   // вставка символа (в конец)
    void pop_back();                          // удаление символа (из конца)

    //CString& erase(size_t pos, size_t len);    // удаление участка

    // вставка строки (в конец)
    //CString& append(const CString& str);
    //CString& append(const CString& str, size_t subpos, size_t sublen);
    //CString& append(const char* s);
    //CString& append(const char* s, size_t n);
    //CString& append(size_t n, char c);

    // вставка строки (после указанной позиции)
    //CString& insert(size_t pos, const CString& str);
    //CString& insert(size_t pos, const CString& str, size_t subpos, size_t sublen);
    //CString& insert(size_t pos, const char* s);
    //CString& insert(size_t pos, const char* s, size_t n);
    //CString& insert(size_t pos, size_t n, char c);

    // замена участка заданной строкой
    //CString& replace(size_t pos, size_t len, const CString& str);
    //CString& replace(size_t pos, size_t len, const CString& str, size_t subpos, size_t sublen);
    //CString& replace(size_t pos, size_t len, const char* s, size_t n);
    //CString& replace(size_t pos, size_t len, size_t n, char c);

    // поиск подстроки в строке начиная с некоторой позиции
    //size_t find(const CString& str, size_t pos = 0) const;
    //size_t find(const char* s, size_t pos = 0) const;
    //size_t find(const char* s, size_t pos, size_t n) const;
    //size_t find(char c, size_t pos = 0) const;

    // поиск одного из перечисленных символов в строке начиная с некоторой позиции
    size_t find_first_of(const CString& str, size_t pos = 0) const;
    //size_t find_first_of(const char* s, size_t pos = 0) const;
    //size_t find_first_of(const char* s, size_t pos, size_t n) const;
    //size_t find_first_of(char c, size_t pos = 0) const;

    // поиск одного НЕ из перечисленных символов в строке начиная с некоторой позиции
    //size_t find_first_not_of(const CString& str, size_t pos = 0) const;
    //size_t find_first_not_of(const char* s, size_t pos = 0) const;
    //size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
    //size_t find_first_not_of(char c, size_t pos = 0) const;
};
