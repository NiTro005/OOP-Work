#include "Gameplay.h"


const char* main_menu[MAIN_MENU_SIZE] = { "Играть", "Выход" };
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
        std::cout << "Игрок 1, выберите персонажа:";
        cursorPos = { 5, 7 };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "1. Воин";
        cursorPos = { 5, 8 };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "2. Лучник";
        cursorPos = { 5, 9 };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "3. Маг";

        cursorPos = { 70, 5 };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "Игрок 2, выберите персонажа:";
        cursorPos = { 70, 7 };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "1. Воин";
        cursorPos = { 70, 8 };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "2. Лучник";
        cursorPos = { 70, 9 };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "3. Маг";

        cursorPos = { 5, 11 };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "Игрок 1, ваш выбор: ";
        std::cin >> player1Choice;

        cursorPos = { 70, 11 };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "Игрок 2, ваш выбор: ";
        std::cin >> player2Choice;
        std::cin.ignore();

        if (player1Choice == -1 || player1Choice > 3) {
            cursorPos = { 5, 13 };
            SetConsoleCursorPosition(console, cursorPos);
            std::cout << "Игрок 1, неверный выбор, попробуйте снова";
            system("pause");
        }
        if (player2Choice == -1 || player2Choice > 3) {
            cursorPos = { 40, 13 };
            SetConsoleCursorPosition(console, cursorPos);
            std::cout << "Игрок 2, неверный выбор, попробуйте снова";
            system("pause");
        }
    }


    CString player1Name, player2Name;
    cursorPos = { 5, 15 };
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "Игрок 1, введите имя персонажа: ";
    std::cin >> player1Name;
    cursorPos = { 70, 15 };
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "Игрок 2, введите имя персонажа: ";
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
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console, &csbi);

    // Сохраняем текущие настройки консоли
    COORD saved_cursor_pos = csbi.dwCursorPosition;
    WORD saved_attributes = csbi.wAttributes;

    // Устанавливаем курсор в левый верхний угол поля
    COORD cursor_pos = { static_cast<SHORT>(2), static_cast<SHORT>(2) };
    SetConsoleCursorPosition(console, cursor_pos);

    // Выводим рамку поля
    for (int i = 0; i < 15 + 2; i++) {
        std::cout << (i == 0 || i == 15 + 1 ? '+' : '-');
    }
    std::cout << std::endl;

    for (int y = 0; y < 15; y++) {
        std::cout << '|';

        for (int x = 0; x < 15; x++) {
            Game_element* obj = field->get_object_at(y, x);
            if (obj == nullptr) {
                std::cout << ' ';
            }
            else if (dynamic_cast<Character*>(obj)) {
                // Устанавливаем цвет для персонажей
                SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                std::cout << 'C';
                // Возвращаем прежние настройки цвета
                SetConsoleTextAttribute(console, saved_attributes);
            }
            else {
                std::cout << 'O';
            }
        }

        std::cout << '|' << std::endl;
    }

    // Выводим нижнюю часть рамки поля
    for (int i = 0; i < 15 + 2; i++) {
        std::cout << (i == 0 || i == 15 + 1 ? '+' : '-');
    }
    std::cout << std::endl;

    // Возвращаем курсор в прежнее положение и восстанавливаем прежние настройки консоли
    SetConsoleCursorPosition(console, saved_cursor_pos);
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