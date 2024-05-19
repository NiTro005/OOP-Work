#include "Gameplay.h"


const char* main_menu[MAIN_MENU_SIZE] = { "������", "�����" };
int choose_pos;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursorPos;


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

    while (1) {}
}

void Gameplay::ShowCreateCharacter() {
    enum CharacterTipe { Warrior, Archer, Vizzard };
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
        player1Choice--;

        cursorPos = { 70, 11 };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "����� 2, ��� �����: ";
        std::cin >> player2Choice;
        player2Choice--;

        if (player1Choice == -1) {
            cursorPos = { 5, 13 };
            SetConsoleCursorPosition(console, cursorPos);
            std::cout << "����� 1, �������� �����, ���������� �����";
            system("pause");
        }
        if (player2Choice == -1) {
            cursorPos = { 40, 13 };
            SetConsoleCursorPosition(console, cursorPos);
            std::cout << "����� 2, �������� �����, ���������� �����";
            system("pause");
        }
        if (player1Choice != -1 && player1Choice == player2Choice) {
            cursorPos = { 5, 13 };
            SetConsoleCursorPosition(console, cursorPos);
            std::cout << "����� 1, ��������� �������� ��� �����, ���������� �����";
            player1Choice = -1;
            system("pause");
        }
        if (player2Choice != -1 && player1Choice == player2Choice) {
            cursorPos = { 40, 13 };
            SetConsoleCursorPosition(console, cursorPos);
            std::cout << "����� 2, ��������� �������� ��� �����, ���������� �����";
            player2Choice = -1;
            system("pause");
        }
    }

    CharacterTipe player1;
    CharacterTipe player2;
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