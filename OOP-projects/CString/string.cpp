#include "string.h"

/// <summary>
/// ����������� �� ���������.
/// </summary>
CString::CString() {
    _size = 0;
    _capacity = STEP_CAPACITY;
    _data = new char[_capacity];
    _data[0] = '\0';
}

/// <summary>
/// ����������� �����������.
/// </summary>
/// <param name="str"> - ���������� ������</param>
CString::CString(const CString& str) {
    _size = str._size;
    _capacity = str._capacity;
    _data = new char[_capacity];
    for (size_t i = 0; i < _size; i++) {
        _data[i] = str._data[i];
    }
    _data[_size] = '\0';
}

/// <summary>
/// ����������� �������������.
/// </summary>
/// <param name="c_str"> - ������ ���������, ������� �� ����������� ������ _data </param>
/// <param name="n"> - ������ ������ </param>
CString::CString(const char* c_str, size_t n) {
    _size = n;
    _capacity = (n / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    _data = new char[_capacity];
    for (int i = 0; i < _size; i++) {
        _data[i] = c_str[i];
    }
    _data[_size] = '\0';
}

/// <summary>
/// ����������� ��������� ����
/// </summary>
/// <param name="c_str"> - ������ ���������  </param> 
CString::CString(const char* c_str) {
    _size = 0;
    while (c_str[_size] != '\0') {
        _size++;
    }
    _capacity = (_size / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    _data = new char[_capacity];
    for (int i = 0; i < _size; i++) {
        _data[i] = c_str[i];
    }
    _data[_size] = '\0';
}

/// <summary>
/// ����������� �������������� ������ ���������� n �������� �.
/// </summary>
/// <param name="n"> - ����������� �������� ������</param>
/// <param name="c"> - ������� ������ </param>
CString:: CString(size_t n, char c) {
    _size = n;
    _capacity = (n / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    _data = new char[_capacity];
    for (int i = 0; i < _size; i++) {
        _data[i] = c;
    }
    _data[_size] = '\0';
}

/// <summary>
/// ����������� ���������� ���������
/// </summary>
/// <param name="str"> - ������ </param>
/// <param name="pos"> - ������� ������� �������� ������ </param>
/// <param name="len"> - ���������� ��������</param>
CString::CString(const CString& str, size_t pos, size_t len) {
    _size = len;
    _capacity = (_size / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    _data = new char[_capacity];
    for (int i = pos; i < pos + len; i++) {
        _data[i - pos] = str._data[i];
    }
    _data[_size] = '\0';
}

/// <summary>
/// ����������.
/// </summary>
CString::~CString() {
    delete[] _data;
    _data = nullptr;
}



/// <summary>
/// �������� ������ �� �������.
/// </summary>
/// <returns>
/// true - ���� ������ �����,
/// false - �����.
/// </returns>
bool CString::empty() const noexcept {
    return _size == 0;
}

/// <summary>
/// �������� ���������� ������ �� ������������ �����
/// </summary>
/// <returns>
/// true - ���� ������ �����,
/// false - �����.
/// </returns>
bool CString::full() const noexcept {
    return _size == _capacity;
}

/// <summary>
/// ������ ��� ������� ������.
/// </summary>
/// <returns>������ (�����) ������</returns>
size_t CString::size() const noexcept {
    return _size;
}

/// <summary>
/// ������ ��� ������� �������
/// </summary>
/// <returns> - ������ �������</returns>
size_t CString::capacity() const noexcept {
    return _capacity;
}

/// <summary>
/// ������ ������
/// </summary>
/// <returns> - ���������� ������ </returns>
const char* CString::data() const{
    return _data;
}

/// <summary>
/// ����� ������������
/// </summary>
/// <param name="str"> -  ������</param>
void CString::swap(CString& str) {
    char* temp = this->_data;
    this->_data = str._data;
    str._data = temp;
}

/// <summary>
/// ����������� ������
/// </summary>
/// <param name="buf"> - ����� ��� �������� ��������</param>
/// <param name="len"> - ����� ���������� ������</param>
/// <param name="pos"> - ��������� ������� ���������� ������ </param>
/// <returns>  ���������� ����������� ��������</returns>
size_t CString::copy(char* buf, size_t len, size_t pos) const {
    if (pos >= _size) {
        return 0;
    }

    size_t chars_to_copy = algorithms::min(len, _size - pos);
    std::memcpy(buf, _data + pos, chars_to_copy);
    return chars_to_copy;
}

/// <summary>
/// ���������� ���������
/// </summary>
/// <param name="pos"> - ������� ������� �������� ���������</param>
/// <param name="len"> - ���������� ��������</param>
/// <returns> - ���������� ���������, �� ������� ��������</returns>
CString CString:: substr(size_t pos, size_t len) const {
    if (pos >= _size) {
        return CString("");
    }

    len = std::min(len, _size - pos); 

    char* substr_data = new char[len + 1];
    memcpy(substr_data, _data + pos, len);
    substr_data[len] = '\0';

    return CString(substr_data);
}

/// <summary>
/// ����������� �������� ����� ������ ������
/// </summary>
/// <param name="str"> - ������</param>
/// <returns> ���������� ���������� ������</returns>
CString& CString:: assign(const CString& str) {
    _size = str._size;
    _capacity = str._capacity;
    _data = new char[_capacity];
    for (int i = 0; i < _size; i++) {
        _data[i] = str._data[i];
    }
    _data[_size] = '\0';
    return *this;
}

/// <summary>
/// ������� ��������� (�������������������).
/// </summary>
/// <param name="str"> - ������ ��� ���������</param>
/// <returns>
/// 1 - ���� �������� ������ ������,
/// -1 - ���� �������� ������ ������,
/// 0 - ���� ������ ���������.
/// </returns>
int CString::compare(const CString& str) const noexcept {
    for (size_t i = 0; i < algorithms::min(_size, str._size); i++) {
        if (this->_data[i] < str._data[i]) {
            return 1;
        }
        else if (this->_data[i] > str._data[i]) {
            return -1;
        }
    }
    if (this->_size > str._size) return 1;
    else if (this->_size < str._size) return -1;
    else return 0;
}

/// <summary>
/// ������� ������
/// </summary>
void CString:: clear() noexcept {
    delete[] _data;
    _size = 0;
    _capacity = 0;
    _data[_size] = '\0';
}

/// <summary>
/// ��������� ����� ������
/// </summary>
/// <param name="n"> - ����� �����</param>
/// <param name="c"> - ���������� ������ ���������</param>
void CString::resize(size_t n, char c) {
    if (n <= _size) {
        _data[n] = '\0';
        _size = n;
    }
    else {
        reserve(n);
        for (size_t i = _size; i < n; ++i) {
            _data[i] = c;
        }
        _data[n] = '\0';
        _size = n;
    }
}


void CString::reserve(size_t n) {
    if (n < _capacity) {
        return;
    }
    _capacity = (n / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    char* newData = new char[_capacity];
    std::memcpy(newData, _data, _size);
    delete[] _data;
    _data = newData;

}


/*
/// < CSsummary>
/// ������� ������� � ����� ������.
/// </summary>
/// <param name="c"> - ������ ��� �������</param>
void CString::push_back(char c) {
    if (this->full()) {
        this->reserve(_capacity);
    }

    _data[_size] = c;
    _data[++_size] = '\0';
}*/

/// <summary>
/// �������� ������� �� ����� ������.
/// <exception cref="std::logic_error">����������, ���� �������� ������ �����.</exception>
/// </summary>
void CString::pop_back() {
    if (this->empty()) {
        throw std::logic_error("Error in function \
                  \"void pop_back()\": source CString is empty");
    }
    _data[--_size] = '\0';
}

/*
// ���� ������ ����������
/// <summary>
/// ������� ������ ����� �������� ������� � ��������.
/// </summary>
/// <param name="pos"> - ������� ��� ������� � �������� ������.</param>
/// <param name="str"> - ������ ��� �������</param>
/// <returns>��������� �������� ������</returns>
CString& CString::insert(size_t pos, const CString& str) {
    CString begin(*this, 0, pos);
    CString end(*this, pos, _size - pos);
    begin.append(str);
    begin.append(end);
    this->swap(begin);
    return *this;
}*/

/// <summary>
/// ����� ������� ���������� � �������� ������ � ����� �� �������� �������� ������.
/// </summary>
/// <param name="str"> - ����� �������� ��� ������</param>
/// <param name="pos"> - �������, � ������� ������� �������� �����</param>
/// <returns></returns>
size_t CString::find_first_of(const CString& str, size_t pos) const {
    for (size_t i = pos; i < _size; i++) {
        for (size_t j = 0; j < str._size; j++) {
            if (_data[i] == str._data[j]) {
                return i;
            }
        }
    }
    return -1;
}

/// <summary>
/// ����� ������ � �������
/// </summary>
void CString::print() const noexcept {
    for (int i = 0; i < _size; i++) {
        std::cout << _data[i];
    }
}