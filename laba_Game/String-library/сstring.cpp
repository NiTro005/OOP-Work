#include "�string.h"

std::istream& operator>>(std::istream& is, CString& str)
{
    char buffer[1000]; // �����������, ��� ������������ ����� �������� ������ �� ��������� 1000 ��������
    is.getline(buffer, 1000); // ��������� ������ �� ������ �����

    str = CString(buffer); // ���������� ����������� �������������� �� const char* ��� ���������� ��������

    return is;

}

std::ostream& operator<<(std::ostream& os, const CString& str) {
    // ������� �� ����� ���������� ������ _data �� ������� ����� ������
    os.write(str._data, str._size);

    // ���������� ������ �� ����� ������
    return os;
}

