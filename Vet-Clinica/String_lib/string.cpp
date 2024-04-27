#include "string.h"

/// <summary>
/// Конструктор по умолчанию.
/// </summary>
CString::CString() {
    _size = 0;
    _capacity = STEP_CAPACITY;
    _data = new char[_capacity];
    _data[0] = '\0';
}


/// <summary>
/// Конструктор копирования.
/// </summary>
/// <param name="str"> - копируемая строка</param>
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
/// Конструктор инициализации.
/// </summary>
/// <param name="c_str"> - массив элементов, которые мы присваиваем строке _data </param>
/// <param name="n"> - размер строки </param>
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
/// Конструктор изменения типа
/// </summary>
/// <param name="c_str"> - строка элементов  </param> 
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
/// Конструктор инициализирует строку содержащую n символов с.
/// </summary>
/// <param name="n"> - колличество символов строки</param>
/// <param name="c"> - элемент строки </param>
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
/// Конструктор вычленения подстроки
/// </summary>
/// <param name="str"> - строка </param>
/// <param name="pos"> - позиция первого элемента строки </param>
/// <param name="len"> - количество символов</param>
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
/// Деструктор.
/// </summary>
CString::~CString() {
    delete[] _data;
    _data = nullptr;
}



/// <summary>
/// Проверка строки на пустоту.
/// </summary>
/// <returns>
/// true - если строка пуста,
/// false - иначе.
/// </returns>
bool CString::empty() const noexcept {
    return _size == 0;
}

/// <summary>
/// Проверка заполнения строки до максимальной длины
/// </summary>
/// <returns>
/// true - если строка пуста,
/// false - иначе.
/// </returns>
bool CString::full() const noexcept {
    return _size == _capacity;
}

/// <summary>
/// Геттер для размера строки.
/// </summary>
/// <returns>размер (длина) строки</returns>
size_t CString::size() const noexcept {
    return _size;
}

/// <summary>
/// Геттер для размера массива
/// </summary>
/// <returns> - размер массива</returns>
size_t CString::capacity() const noexcept {
    return _capacity;
}

/// <summary>
/// Геттер строки
/// </summary>
/// <returns> - возвращает строку </returns>
const char* CString::data() const{
    return _data;
}

/// <summary>
/// Метод перестановки
/// </summary>
/// <param name="str"> -  строка</param>
void CString::swap(CString& str) {
    char* temp = this->_data;
    this->_data = str._data;
    str._data = temp;
}

/// <summary>
/// Копирование строки
/// </summary>
/// <param name="buf"> - буфер для хранения символов</param>
/// <param name="len"> - длина копируемой строки</param>
/// <param name="pos"> - начальная позиция копируемой строки </param>
/// <returns>  количество скопируемых символов</returns>
size_t CString::copy(char* buf, size_t len, size_t pos) const {
    if (pos >= _size) {
        return 0;
    }

    size_t chars_to_copy = algorithms::min(len, _size - pos);
    std::memcpy(buf, _data + pos, chars_to_copy);
    return chars_to_copy;
}

/// <summary>
/// Вычленение подстроки
/// </summary>
/// <param name="pos"> - позиция первого элемента подстроки</param>
/// <param name="len"> - количеесво символов</param>
/// <returns> - возвращает подстроку, не изменяя исходник</returns>
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
/// Присваивает значения одной строки другой
/// </summary>
/// <param name="str"> - строка</param>
/// <returns> возвращает измененную строку</returns>
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
/// Функция сравнения (лексикографического).
/// </summary>
/// <param name="str"> - строка для сравнения</param>
/// <returns>
/// 1 - если исходная строка больше,
/// -1 - если исходная строка меньше,
/// 0 - если строки совпадают.
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
/// Очистка строки
/// </summary>
void CString:: clear() noexcept {
    delete[] _data;
    _size = 0;
    _capacity = 0;
    _data[_size] = '\0';
}

/// <summary>
/// Изменение длины строки
/// </summary>
/// <param name="n"> - новая длина</param>
/// <param name="c"> - заполнение пустых элементов</param>
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

/// <summary>
/// Расширение хранилище
/// </summary>
/// <param name="n"> - длина </param>
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


/// < CSsummary>
/// Вставка символа в конец строки.
/// </summary>
/// <param name="c"> - символ для вставки</param>
void CString::push_back(char c) {
    if (this->full()) {
        this->reserve(_capacity);
    }

    _data[_size] = c;
    _data[++_size] = '\0';
}

/// <summary>
/// Удаление символа из конца строки.
/// <exception cref="std::logic_error">Исключение, если исходная строка пуста.</exception>
/// </summary>
void CString::pop_back() {
    if (this->empty()) {
        throw std::logic_error("Error in function \
                  \"void pop_back()\": source CString is empty");
    }
    _data[--_size] = '\0';
}

/// <summary>
/// Удаление участка строки
/// </summary>
/// <param name="pos"> - первый удаляемый элемент</param>
/// <param name="len"> - количество удаляемых символов</param>
/// <returns> - возвращает строку </returns>
CString& CString::erase(size_t pos, size_t len) {
    if (pos >= _size) {
        return *this;
    }
    len = std::min(len, _size - pos); 
    if (len > 0) {
        size_t new_len = _size - len;
        memmove(_data + pos, _data + pos + len, new_len - pos); // сдвигаем символы влево
        _size = new_len;
        _data[_size] = '\0';
    }

    return *this;
}

/// <summary>
/// Вставка строки(в конец)
/// </summary>
/// <param name="str"> - вставляемая строка</param>
/// <returns> - возвращает новую строку</returns>
CString& CString::append(const CString& str) {
    if ((_capacity - _size) <= str._size) {
        reserve(_size + str._size);
    }
    for (int i = 0; i < str._size; ++i) {
        _data[_size + i] = str._data[i];
    }
    _size += str._size;
    return *this;
}


/// <summary>
/// Вставка строки после заданной позиции в исходной.
/// </summary>
/// <param name="pos"> - позиция для вставки в исходной строке.</param>
/// <param name="str"> - строка для вставки</param>
/// <returns>изменённая исходная строка</returns>
CString& CString::insert(size_t pos, const CString& str) {
    CString begin(*this, 0, pos);
    CString end(*this, pos, _size - pos);
    begin.append(str);
    begin.append(end);
    this->swap(begin);
    return *this;
}

/// <summary>
/// Замена участка строки
/// </summary>
/// <param name="pos"> - начальная позиция</param>
/// <param name="len"> - длина </param>
/// <param name="str"> - строка</param>
/// <returns> - возвращает строку с замененным участком </returns>
CString& CString::replace(size_t pos, size_t len, const CString& str) {
    len = std::min(len, _size - pos);
    for (size_t i = pos; i < pos + len; i++) {
        if (str._data[i - pos] == '\0') {
            break;
        }
        _data[i] = str._data[i - pos];
    }
    return *this;
}

/// <summary>
/// Поиск подстроки
/// </summary>
/// <param name="str"> - подстрока</param>
/// <param name="pos"> - начальная позиция</param>
/// <returns> индекс найденной подстроки</returns>
size_t CString::find(const CString& str, size_t pos) const {
    if (pos >= _size) {
        throw std::logic_error("Error in function \ Position > size");
    }
    for (size_t i = pos; i <= _size - str._size; i++) {
        for (size_t j = 0; j < str._size; j++) {
            if (_data[i + j] == str._data[j]) {
                return i;
            }
        }
    }
    return -1;
}

/// <summary>
/// Поиск первого совпадения в исходной строке с одним из символов заданной строки.
/// </summary>
/// <param name="str"> - набор символов для поиска</param>
/// <param name="pos"> - позиция, с которой следует начинать поиск</param>
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
/// поиск одного НЕ из перечисленных символов в строке начиная с некоторой позиции
/// </summary>
/// <param name="str"> - строка</param>
/// <param name="pos"> - начальная позиция</param>
/// <returns> индекс подходящего элемента</returns>
size_t CString::find_first_not_of(const CString& str, size_t pos) const {
    for (size_t i = pos; i < _size; i++) {
        bool found = false;
        for (size_t j = 0; j < str._size; j++) {
            if (_data[i] == str._data[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return i;
        }
    }
    return -1;
}

/// <summary>
/// Вывод строки в консоль
/// </summary>
void CString::print(size_t pos, size_t len) const noexcept {
    for (int i = pos; i < _size - pos + len; i++) {
        std::cout << _data[i];
    }
}


/// <summary>
/// Метод добавления подстроки str, начиная с позиции subpos и длиной sublen
/// </summary>
/// <param name="str"> - строка</param>
/// <param name="subpos"> - начальная позиция</param>
/// <param name="sublen"> - длина</param>
/// <returns> строку</returns>
CString& CString::append(const CString& str, size_t subpos, size_t sublen) {
    if (subpos >= str._size) return *this;

    size_t new_size = _size + sublen;
    reserve(new_size);

    for (size_t i = 0; i < sublen; ++i) {
        _data[_size++] = str._data[subpos + i];
    }

    _data[_size] = '\0';
    return *this;
}

/// <summary>
/// Метод добавления строки s
/// </summary>
/// <param name="s"> - строка</param>
/// <returns> измененная строка</returns>
CString& CString::append(const char* s) {
    if (s == nullptr) return *this;

    size_t len = strlen(s);
    size_t new_size = _size + len;
    reserve(new_size);

    for (size_t i = 0; i < len; ++i) {
        _data[_size++] = s[i];
    }

    _data[_size] = '\0';
    return *this;
}

/// <summary>
///  Метод добавления первых n символов из строки s
/// </summary>
/// <param name="s"> - строка</param>
/// <param name="n"> - первые символы из этой строки</param>
/// <returns> измененная строка</returns>
CString& CString::append(const char* s, size_t n) {
    if (s == nullptr) return *this;

    size_t len = strlen(s);
    size_t actual_len = std::min(len, n);
    size_t new_size = _size + actual_len;
    reserve(new_size);

    for (size_t i = 0; i < actual_len; ++i) {
        _data[_size++] = s[i];
    }

    _data[_size] = '\0';
    return *this;
}

/// <summary>
/// Метод добавления символа c n раз
/// </summary>
/// <param name="n"> - число повторений</param>
/// <param name="c"> - символ</param>
/// <returns> измененная строка</returns>
CString& CString::append(size_t n, char c) {
    size_t new_size = _size + n;
    reserve(new_size);

    for (size_t i = 0; i < n; ++i) {
        _data[_size++] = c;
    }

    _data[_size] = '\0';
    return *this;
}


/// <summary>
///  Метод вставки подстроки str, начиная с позиции subpos и длиной sublen, в позицию pos
/// </summary>
/// <param name="pos"></param>
/// <param name="str"></param>
/// <param name="subpos"></param>
/// <param name="sublen"></param>
/// <returns></returns>
CString& CString::insert(size_t pos, const CString& str, size_t subpos, size_t sublen) {
    if (pos > _size || subpos >= str._size) return *this;

    size_t new_size = _size + sublen;
    reserve(new_size);

    // Сдвигаем часть строки после позиции вставки
    for (size_t i = _size; i > pos; --i) {
        _data[i + sublen - 1] = _data[i - 1];
    }

    // Вставляем подстроку
    for (size_t i = 0; i < sublen; ++i) {
        _data[pos + i] = str._data[subpos + i];
    }

    _size = new_size;
    _data[_size] = '\0';
    return *this;
}

/// <summary>
/// Метод вставки строки s в позицию pos
/// </summary>
/// <param name="pos"></param>
/// <param name="s"></param>
/// <returns></returns>
CString& CString::insert(size_t pos, const char* s) {
    if (pos > _size || s == nullptr) return *this;

    size_t len = strlen(s);
    size_t new_size = _size + len;
    reserve(new_size);

    // Сдвигаем часть строки после позиции вставки
    for (size_t i = _size; i > pos; --i) {
        _data[i + len - 1] = _data[i - 1];
    }

    // Вставляем строку s
    for (size_t i = 0; i < len; ++i) {
        _data[pos + i] = s[i];
    }

    _size = new_size;
    _data[_size] = '\0';
    return *this;
}

/// <summary>
/// Метод вставки первых n символов из строки s в позицию pos
/// </summary>
/// <param name="pos"></param>
/// <param name="s"></param>
/// <param name="n"></param>
/// <returns></returns>
CString& CString::insert(size_t pos, const char* s, size_t n) {
    if (pos > _size || s == nullptr) return *this;

    size_t len = strlen(s);
    size_t actual_len = std::min(len, n);
    size_t new_size = _size + actual_len;
    reserve(new_size);

    // Сдвигаем часть строки после позиции вставки
    for (size_t i = _size; i > pos; --i) {
        _data[i + actual_len - 1] = _data[i - 1];
    }

    // Вставляем первые n символов из строки s
    for (size_t i = 0; i < actual_len; ++i) {
        _data[pos + i] = s[i];
    }

    _size = new_size;
    _data[_size] = '\0';
    return *this;
}

/// <summary>
///Метод вставки символа c n раз в позицию pos
/// </summary>
/// <param name="pos"></param>
/// <param name="n"></param>
/// <param name="c"></param>
/// <returns></returns>
CString& CString::insert(size_t pos, size_t n, char c) {
    if (pos > _size) return *this;

    size_t new_size = _size + n;
    reserve(new_size);

    // Сдвигаем часть строки после позиции вставки
    for (size_t i = _size; i > pos; --i) {
        _data[i + n - 1] = _data[i - 1];
    }

    // Вставляем символ c n раз
    for (size_t i = 0; i < n; ++i) {
        _data[pos + i] = c;
    }

    _size = new_size;
    _data[_size] = '\0';
    return *this;
}

/// <summary>
/// Метод замены len символов, начиная с позиции pos, на подстроку str, начиная с позиции subpos и длиной sublen
/// </summary>
/// <param name="pos"></param>
/// <param name="len"></param>
/// <param name="str"></param>
/// <param name="subpos"></param>
/// <param name="sublen"></param>
/// <returns></returns>
CString& CString::replace(size_t pos, size_t len, const CString& str, size_t subpos, size_t sublen) {
    if (pos >= _size) return *this;

    size_t new_size = _size - len + sublen;
    reserve(new_size);

    // Сдвигаем часть строки после позиции замены
    for (size_t i = pos + len; i < _size; ++i) {
        _data[i + sublen - len] = _data[i];
    }

    // Вставляем подстроку str
    for (size_t i = 0; i < sublen; ++i) {
        _data[pos + i] = str._data[subpos + i];
    }

    _size = new_size;
    _data[_size] = '\0';
    return *this;
}

/// <summary>
/// Метод замены len символов, начиная с позиции pos, на строку s длиной n
/// </summary>
/// <param name="pos"></param>
/// <param name="len"></param>
/// <param name="s"></param>
/// <param name="n"></param>
/// <returns></returns>
CString& CString::replace(size_t pos, size_t len, const char* s, size_t n) {
    if (pos >= _size) return *this;

    size_t new_size = _size - len + n;
    reserve(new_size);

    // Сдвигаем часть строки после позиции замены
    for (size_t i = pos + len; i < _size; ++i) {
        _data[i + n - len] = _data[i];
    }

    // Вставляем строку s
    for (size_t i = 0; i < n; ++i) {
        _data[pos + i] = s[i];
    }

    _size = new_size;
    _data[_size] = '\0';
    return *this;
}

/// <summary>
/// Метод замены len символов, начиная с позиции pos, на символ c повторенный n раз
/// </summary>
/// <param name="pos"></param>
/// <param name="len"></param>
/// <param name="n"></param>
/// <param name="c"></param>
/// <returns></returns>
CString& CString::replace(size_t pos, size_t len, size_t n, char c) {
    if (pos >= _size) return *this;

    size_t new_size = _size - len + n;
    reserve(new_size);

    // Сдвигаем часть строки после позиции замены
    for (size_t i = pos + len; i < _size; ++i) {
        _data[i + n - len] = _data[i];
    }

    // Вставляем символ c повторенный n раз
    for (size_t i = 0; i < n; ++i) {
        _data[pos + i] = c;
    }

    _size = new_size;
    _data[_size] = '\0';
    return *this;
}

/// <summary>
/// Метод поиска подстроки s, начиная с позиции pos
/// </summary>
/// <param name="s"></param>
/// <param name="pos"></param>
/// <returns></returns>
size_t CString::find(const char* s, size_t pos) const {
    if (s == nullptr || pos >= _size) return std::string::npos;

    char* found = strstr(_data + pos, s);
    if (found == nullptr) return std::string::npos;

    return found - _data;
}

/// <summary>
/// Метод поиска подстроки s длиной n, начиная с позиции pos
/// </summary>
/// <param name="s"></param>
/// <param name="pos"></param>
/// <param name="n"></param>
/// <returns></returns>
size_t CString::find(const char* s, size_t pos, size_t n) const {
    if (s == nullptr || pos >= _size) return std::string::npos;

    char* found = nullptr;
    for (size_t i = pos; i <= _size - n; ++i) {
        if (strncmp(_data + i, s, n) == 0) {
            found = _data + i;
            break;
        }
    }

    if (found == nullptr) return std::string::npos;
    return found - _data;
}

/// <summary>
/// Метод поиска символа c, начиная с позиции pos
/// </summary>
/// <param name="c"></param>
/// <param name="pos"></param>
/// <returns></returns>
size_t CString::find(char c, size_t pos) const {
    if (pos >= _size) return std::string::npos;

    char* found = strchr(_data + pos, c);
    if (found == nullptr) return std::string::npos;

    return found - _data;
}


/// <summary>
/// Метод поиска первого вхождения любого символа из строки s, начиная с позиции pos
/// </summary>
/// <param name="s"></param>
/// <param name="pos"></param>
/// <returns></returns>
size_t CString::find_first_of(const char* s, size_t pos) const {
    if (s == nullptr || pos >= _size) return std::string::npos;

    char* found = strpbrk(_data + pos, s);
    if (found == nullptr) return std::string::npos;

    return found - _data;
}

/// <summary>
/// Метод поиска первого вхождения любого символа из строки s длиной n, начиная с позиции pos
/// </summary>
/// <param name="s"></param>
/// <param name="pos"></param>
/// <param name="n"></param>
/// <returns></returns>
size_t CString::find_first_of(const char* s, size_t pos, size_t n) const {
    if (s == nullptr || pos >= _size) return std::string::npos;

    for (size_t i = pos; i < _size; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (_data[i] == s[j]) {
                return i;
            }
        }
    }

    return std::string::npos;
}

/// <summary>
/// Метод поиска первого вхождения символа c, начиная с позиции pos
/// </summary>
/// <param name="c"></param>
/// <param name="pos"></param>
/// <returns></returns>
size_t CString::find_first_of(char c, size_t pos) const {
    if (pos >= _size) return std::string::npos;

    char* found = strchr(_data + pos, c);
    if (found == nullptr) return std::string::npos;

    return found - _data;
}

/// <summary>
/// Метод поиска первого вхождения символов не из строки s, начиная с позиции pos
/// </summary>
/// <param name="s"></param>
/// <param name="pos"></param>
/// <returns></returns>
size_t CString::find_first_not_of(const char* s, size_t pos) const {
    if (s == nullptr || pos >= _size) return std::string::npos;

    for (size_t i = pos; i < _size; ++i) {
        if (strchr(s, _data[i]) == nullptr) {
            return i;
        }
    }

    return std::string::npos;
}

/// <summary>
/// Метод поиска первого вхождения символов не из строки s длиной n, начиная с позиции pos
/// </summary>
/// <param name="s"></param>
/// <param name="pos"></param>
/// <param name="n"></param>
/// <returns></returns>
size_t CString::find_first_not_of(const char* s, size_t pos, size_t n) const {
    if (s == nullptr || pos >= _size) return std::string::npos;

    for (size_t i = pos; i < _size; ++i) {
        bool found = false;
        for (size_t j = 0; j < n; ++j) {
            if (_data[i] == s[j]) {
                found = true;
                break;
            }
        }
        if (!found) return i;
    }

    return std::string::npos;
}

/// <summary>
/// Метод поиска первого вхождения символа не равного c, начиная с позиции pos
/// </summary>
/// <param name="c"></param>
/// <param name="pos"></param>
/// <returns></returns>
size_t CString::find_first_not_of(char c, size_t pos) const {
    if (pos >= _size) return std::string::npos;

    for (size_t i = pos; i < _size; ++i) {
        if (_data[i] != c) {
            return i;
        }
    }

    return std::string::npos;
}