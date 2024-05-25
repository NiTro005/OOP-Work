#include "Gameplay.h"
#define Xcoord 23
#define Ycoord 8

const char* main_menu[MAIN_MENU_SIZE] = { "������", "�����" };
int choose_pos;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursorPos;
int player1life = 3;
int player2life = 3;

void Gameplay::launch(){
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(console, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(console, &structCursorInfo);
    bool exit = true;
    do {
        ShowMainMenu();
        if (choose_pos == 0) {
            ShowCreateCharacter();
            start();
            exit = false;
        }
    } while (!exit);
}

void Gameplay::start() {
    field = new Playing_field(player1, player2);
    ShowGameMenu();
    while (1) {}
}

void Gameplay::ShowCreateCharacter() {

    int player1Choice = -1;
    int player2Choice = -1;

    while (player1Choice == -1 || player2Choice == -1) {
        system("cls");
        for (int i = 0; i < 30; i++) {
            cursorPos = { 60, static_cast<SHORT>(i) };
            SetConsoleCursorPosition(console, cursorPos);
            std::cout << "|";
        }

        cursorPos = { 5, 5 };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "����� 1, �������� ���������:";
        cursorPos = { 5, 7 };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "1. ����";
        cursorPos = { 5, 8 };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "2. ������";
        cursorPos = { 5, 9 };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "3. ���";

        cursorPos = { 70, 5 };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "����� 2, �������� ���������:";
        cursorPos = { 70, 7 };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "1. ����";
        cursorPos = { 70, 8 };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "2. ������";
        cursorPos = { 70, 9 };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "3. ���";

        cursorPos = { 5, 11 };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "����� 1, ��� �����: ";
        std::cin >> player1Choice;

        cursorPos = { 70, 11 };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "����� 2, ��� �����: ";
        std::cin >> player2Choice;
        std::cin.ignore();

        if (player1Choice == -1 || player1Choice > 3) {
            cursorPos = { 5, 13 };
            SetConsoleCursorPosition(console, cursorPos);
            std::cout << "����� 1, �������� �����, ���������� �����";
            system("pause");
        }
        if (player2Choice == -1 || player2Choice > 3) {
            cursorPos = { 40, 13 };
            SetConsoleCursorPosition(console, cursorPos);
            std::cout << "����� 2, �������� �����, ���������� �����";
            system("pause");
        }
    }


    CString player1Name, player2Name;
    cursorPos = { 5, 15 };
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "����� 1, ������� ��� ���������: ";
    std::cin >> player1Name;
    cursorPos = { 70, 15 };
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "����� 2, ������� ��� ���������: ";
    std::cin >> player2Name;
    switch (player1Choice) {
    case 1:
        player1 = new Warrior(player1Name);
        break;
    case 2:
        player1 = new Archer(player1Name);
        break;
    case 3:
        player1 = new Vizzard(player1Name);
        break;
    }

    switch (player2Choice) {
    case 1:
        player2 = new Warrior(player2Name);
        break;
    case 2:
        player2 = new Archer(player2Name);
        break;
    case 3:
        player2 = new Vizzard(player2Name);
        break;
    }
}

void Gameplay::ShowGameMenu(){
    system("cls");
    bool color = true;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console, &csbi);
    COORD saved_cursor_pos = csbi.dwCursorPosition;
    WORD saved_attributes = csbi.wAttributes;
    cursorPos = { 2, 1 };
    SetConsoleCursorPosition(console, cursorPos);
    for (int i = 0; i < 116; i++) {
        std::cout << "-";
        if (i == 0) {
            for (int j = 0; j < 26; j++) {
                cursorPos.Y = j + 2;
                SetConsoleCursorPosition(console, cursorPos);
                std::cout << "|";
            }
            cursorPos.Y = 1;
            SetConsoleCursorPosition(console, cursorPos);
        }
            
        
    }
    cursorPos.X = 116;
    for (int j = 0; j < 26; j++) {
        cursorPos.Y = j + 2;
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "|";
    }
    for(int k = 0; k < 5; k++) {
        cursorPos.Y = k + 2;
        cursorPos.X = 23;
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "|";
        cursorPos.X = 94;
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "|";
    }
    cursorPos = { 23, 6 };
    SetConsoleCursorPosition(console, cursorPos);
    for (int i = 0; i < 70 + 2; i++) {
        if (i == 0 || i == 71) { std::cout << "+"; }
        else { std::cout << "-"; }
    }
    cursorPos = { 2, 27 };
    SetConsoleCursorPosition(console, cursorPos);
    for (int i = 0; i < 115; i++) {
        std::cout << "-";
    }
    for (int y = 0; y < 20; y++) {
        if (y == 19) {
            cursorPos = { 23, static_cast<SHORT>(y + 7) };
            SetConsoleCursorPosition(console, cursorPos);
            std::cout << "+";
        }
        cursorPos = { 23, static_cast<SHORT>(y + 7)};
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "|";

        for (int x = 0; x < 70; x++) {
            Game_element* obj = field->get_object_at(x, y);
            if (obj == nullptr) {
                std::cout << ' ';
            }
            else if (dynamic_cast<Character*>(obj)) {
                if (color) {
                    SetConsoleTextAttribute(console, FOREGROUND_BLUE);
                    std::cout << 'C';
                    SetConsoleTextAttribute(console, saved_attributes);
                    color = false;
                }
                else {
                    SetConsoleTextAttribute(console, FOREGROUND_RED);
                    std::cout << 'C';
                    SetConsoleTextAttribute(console, saved_attributes);
                }
            }
            else {
                std::cout << 'O';
            }
        }
        std::cout << "|"; 
        if (y == 19) {
            cursorPos = { 94, static_cast<SHORT>(y + 8) };
            SetConsoleCursorPosition(console, cursorPos);
            std::cout << "+";
        }
    }
    cursorPos = { 3, 14 };
    SetConsoleCursorPosition(console, cursorPos);
    for (int i = 0; i < 20; i++) {
        cursorPos.X = i + 3;
        cursorPos.Y = 14;
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "-";
        cursorPos.Y = 24;
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "-";

    }
    cursorPos = { 95, 14 };
    SetConsoleCursorPosition(console, cursorPos);
    for (int i = 0; i < 21; i++) {
        cursorPos.X = i + 95;
        cursorPos.Y = 14;
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "-";
        cursorPos.Y = 24;
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "-";
    }
    cursorPos = { 4, 25 };
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "����������:";
    cursorPos.X = 97;
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "����������:";
    cursorPos = { 6, 26 };
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "WASD";
    cursorPos.X = 99;
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "IJKL";

    descriptCharacter();

    // ���������� ������ � ������� ��������� � ��������������� ������� ��������� �������
    SetConsoleCursorPosition(console, saved_cursor_pos);
    SetConsoleTextAttribute(console, saved_attributes);
    updateStatus("* ������� ���� �������");
    updateStatus("* ��������� �������������");
}

void Gameplay::updateStatus(const CString& str)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console, &csbi);
    WORD saved_attributes = csbi.wAttributes;
    if (states.size() == 4) {
        states.pop_front();
    }
    states.push_back(str);
    cursorPos = { 40, 1 };
    SetConsoleCursorPosition(console, cursorPos);
    for (int i = 0; i < states.size(); i++) {
        cursorPos.Y++;
        SetConsoleCursorPosition(console, cursorPos);
        SetConsoleTextAttribute(console, FOREGROUND_INTENSITY);
        std::cout << states[i];
    }
    SetConsoleTextAttribute(console, saved_attributes);
}

void Gameplay::descriptCharacter()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console, &csbi);
    WORD saved_attributes = csbi.wAttributes;

    cursorPos = { 7, 16 };
    SetConsoleCursorPosition(console, cursorPos);
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN);
    std::cout << player1->get_class();
    SetConsoleTextAttribute(console, saved_attributes);
    cursorPos = { 4, 18 };
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "���: " << player1->get_name();
    cursorPos = { 4, 19 };
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "Hp: " << player1->get_hp();
    cursorPos = { 4, 20 };
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "Power: " << player1->get_power();
    cursorPos = { 4, 21 };
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "Armor: " << player1->get_armor();
    cursorPos = { 4, 23 };
    SetConsoleCursorPosition(console, cursorPos);
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    for (int i = 0; i < player1life; i++) {
        std::cout << "||| ";
    }
    SetConsoleTextAttribute(console, saved_attributes);

    cursorPos = { 100, 16 };
    SetConsoleCursorPosition(console, cursorPos);
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN);
    std::cout << player2->get_class();
    SetConsoleTextAttribute(console, saved_attributes);
    cursorPos = { 97, 18 };
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "���: " << player2->get_name();
    cursorPos = { 97, 19 };
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "Hp: " << player2->get_hp();
    cursorPos = { 97, 20 };
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "Power: " << player2->get_power();
    cursorPos = { 97, 21 };
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "Armor: " << player2->get_armor();
    cursorPos = { 97, 23 };
    SetConsoleCursorPosition(console, cursorPos);
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    for (int i = 0; i < player2life; i++) {
        std::cout << "||| ";
    }
    SetConsoleTextAttribute(console, saved_attributes);
}


void Gameplay::ShowMainMenu() {
    char iKey = 0;
    while (iKey != KEY_ENTER) {
        switch (iKey) {
        case KEY_ARROW_UP:
            choose_pos--;
            break;
        case KEY_ARROW_DOWN:
            choose_pos++;
            break;
        default:
            break;
        }
        if (choose_pos < 0) { choose_pos = MAIN_MENU_SIZE - 1; }
        if (choose_pos > MAIN_MENU_SIZE - 1) { choose_pos = 0; }
        for (int i = 0; i < MAIN_MENU_SIZE; i++) {
            cursorPos.Y = static_cast<SHORT>(i + 13);
            cursorPos.X = 55;
            SetConsoleCursorPosition(console, cursorPos);
            std::cout << main_menu[i];
        }
        cursorPos.X = 52;
        cursorPos.Y = choose_pos + 13;
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "<<";

        cursorPos.X = 50 + strlen(main_menu[choose_pos]) * 2;
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << ">>";
        iKey = _getch();
        system("cls");
        
    }
}