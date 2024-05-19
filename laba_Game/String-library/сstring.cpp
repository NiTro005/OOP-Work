#include "сstring.h"

std::istream& operator>>(std::istream& is, CString& str)
{
    char buffer[1000]; // Предположим, что максимальная длина вводимой строки не превышает 1000 символов
    is.getline(buffer, 1000); // Считываем строку из потока ввода

    str = CString(buffer); // Используем конструктор преобразования из const char* для присвоения значения

    return is;

}
