#include "Gameplay.h"
#define Xcoord 24
#define Ycoord 7

const char* main_menu[MAIN_MENU_SIZE] = { "Играть", "Выход" };
int choose_pos;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursorPos;
int player1life = 3;
int player2life = 3;
int Hp1 = 0;
int Hp2 = 0;
int armor1 = 0;
int armor2 = 0;
int power1 = 0;
int power2 = 0;

void Gameplay::launch(){
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(console, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(console, &structCursorInfo);
    bool exit = false;
    do {
        ShowMainMenu();
        if (choose_pos == 0) {
            ShowCreateCharacter();
            start();
            exit = true;
        }
        else {
            return;
        }
    } while (!exit);
}

void Gameplay::start() {
    field = new Playing_field(player1, player2);
    ShowGameMenu();
    while (1) {
        PlayerMove();
        if (player1life == 0 || player2life == 0) {
            break;
        }
    }
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
    bool color = true;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console, &csbi);
    COORD saved_cursor_pos = csbi.dwCursorPosition;
    WORD saved_attributes = csbi.wAttributes;
    Hp1 = player1->get_hp();
    Hp2 = player2->get_hp();
    armor1 = player1->get_armor();
    armor2 = player2->get_armor();
    power1 = player1->get_power();
    power2 = player2->get_power();
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
            cursorPos = { 23, static_cast<SHORT>(y + Ycoord + 1) };
            SetConsoleCursorPosition(console, cursorPos);
            std::cout << "+";
        }
        cursorPos = { 23, static_cast<SHORT>(y + Ycoord)};
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << "|";

        for (int x = 0; x < 70; x++) {
            Game_element* obj = field->get_object_at(x, y);
            if (obj == nullptr) {
                std::cout << ' ';
            }
            else if (dynamic_cast<Character*>(obj)) {
                if (obj == player1) {
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
    std::cout << "Управление:";
    cursorPos.X = 97;
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "Управление:";
    cursorPos = { 6, 26 };
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "WASD";
    cursorPos.X = 99;
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "IJKL";

    descriptCharacter();

    // Возвращаем курсор в прежнее положение и восстанавливаем прежние настройки консоли
    SetConsoleCursorPosition(console, saved_cursor_pos);
    SetConsoleTextAttribute(console, saved_attributes);
    updateStatus("<-Игровое поле создано->");
    updateStatus("<-Персонажи сгенерированы->");
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

    cursorPos.X = 97;
    for (int i = 0; i < 9; i++) {
        cursorPos.Y = i + 15;
        SetConsoleCursorPosition(console, cursorPos);
        for (int j = 0; j < 15; j++) {
            std::cout << " ";
        }
    }
    cursorPos.X = 4;
    for (int i = 0; i < 9; i++) {
        cursorPos.Y = i + 15;
        SetConsoleCursorPosition(console, cursorPos);
        for (int j = 0; j < 15; j++) {
            std::cout << " ";
        }
    }
    cursorPos = { 7, 16 };
    SetConsoleCursorPosition(console, cursorPos);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE);
    std::cout << player1->get_class();
    SetConsoleTextAttribute(console, saved_attributes);
    cursorPos = { 4, 18 };
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "Имя: " << player1->get_name();
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
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    std::cout << player2->get_class();
    SetConsoleTextAttribute(console, saved_attributes);
    cursorPos = { 97, 18 };
    SetConsoleCursorPosition(console, cursorPos);
    std::cout << "Имя: " << player2->get_name();
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

void Gameplay::PlayerMove()
{
    Sleep(100);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console, &csbi);
    WORD saved_attributes = csbi.wAttributes;
    int X1 = player1->get_x();
    int Y1 = player1->get_y();
    int X2 = player2->get_x();
    int Y2 = player2->get_y();
    CString str = player1->get_name();
    CString str2 = player2->get_name();
    TArchive<Game_element*> neighbors_player1 = field->get_neighbors(player1->get_x(), player1->get_y());
    TArchive<Game_element*> neighbors_player2 = field->get_neighbors(player2->get_x(), player2->get_y());
    if (_kbhit()) {
        char iKey = _getch();
        switch (iKey)
        {
        case 'W': case 'w':
            if (Y1 - 1 + Ycoord < Ycoord) { return; }
            if (neighbors_player1[1] == player2) { 
                player2->defence(*player1, player1->attack(*player2)); descriptCharacter();
                str.append(" атаковал ").append(str2);
                updateStatus(str);
            }
            else {
                field->set_element(X1, Y1, nullptr);
                field->set_element(X1, Y1 - 1, player1);
                cursorPos = { static_cast<SHORT>(X1 + Xcoord),static_cast<SHORT>(Y1 + Ycoord - 1) };
                SetConsoleCursorPosition(console, cursorPos);
                SetConsoleTextAttribute(console, FOREGROUND_BLUE);
                std::cout << "C";
                SetConsoleTextAttribute(console, saved_attributes);
                cursorPos = { static_cast<SHORT>(X1 + Xcoord),static_cast<SHORT>(Y1 + Ycoord) };
                SetConsoleCursorPosition(console, cursorPos);
                std::cout << " ";
                player1->change_position(Y1 - 1, X1);
            }
            break;

        case 'A': case 'a':
            if (X1 + Xcoord < Xcoord + 1) { return; }
            if (neighbors_player1[3] == player2) { player2->defence(*player1, player1->attack(*player2)); descriptCharacter(); 
            str.append(" атаковал ").append(str2);
            updateStatus(str);
            }
            else {
                field->set_element(X1, Y1, nullptr);
                field->set_element(X1 - 1, Y1, player1);
                cursorPos = { static_cast<SHORT>(X1 + Xcoord - 1),static_cast<SHORT>(Y1 + Ycoord) };
                SetConsoleCursorPosition(console, cursorPos);
                SetConsoleTextAttribute(console, FOREGROUND_BLUE);
                std::cout << "C";
                SetConsoleTextAttribute(console, saved_attributes);
                cursorPos = { static_cast<SHORT>(X1 + Xcoord),static_cast<SHORT>(Y1 + Ycoord) };
                SetConsoleCursorPosition(console, cursorPos);
                std::cout << " ";
                player1->change_position(Y1, X1 - 1);
            }
            break;

        case 'S': case 's':
            if (Y1 + Ycoord > 25) { return; }
            if (neighbors_player1[6] == player2) { player2->defence(*player1, player1->attack(*player2)); descriptCharacter(); 
            str.append(" атаковал ").append(str2);
            updateStatus(str);
            }
            else {
                field->set_element(X1, Y1, nullptr);
                field->set_element(X1, Y1 + 1, player1);
                cursorPos = { static_cast<SHORT>(X1 + Xcoord),static_cast<SHORT>(Y1 + Ycoord + 1) };
                SetConsoleCursorPosition(console, cursorPos);
                SetConsoleTextAttribute(console, FOREGROUND_BLUE);
                std::cout << "C";
                SetConsoleTextAttribute(console, saved_attributes);
                cursorPos = { static_cast<SHORT>(X1 + Xcoord),static_cast<SHORT>(Y1 + Ycoord) };
                SetConsoleCursorPosition(console, cursorPos);
                std::cout << " ";
                player1->change_position(Y1 + 1, X1);
            }
            break;

        case 'D': case 'd':
            if (X1 + Xcoord > 92) { return; }
            if (neighbors_player1[4] == player2) { player2->defence(*player1, player1->attack(*player2)); descriptCharacter(); 
            str.append(" атаковал ").append(str2);
            updateStatus(str);
            }
            else {
                field->set_element(X1, Y1, nullptr);
                field->set_element(X1 + 1, Y1, player1);
                cursorPos = { static_cast<SHORT>(X1 + Xcoord + 1),static_cast<SHORT>(Y1 + Ycoord) };
                SetConsoleCursorPosition(console, cursorPos);
                SetConsoleTextAttribute(console, FOREGROUND_BLUE);
                std::cout << "C";
                SetConsoleTextAttribute(console, saved_attributes);
                cursorPos = { static_cast<SHORT>(X1 + Xcoord),static_cast<SHORT>(Y1 + Ycoord) };
                SetConsoleCursorPosition(console, cursorPos);
                std::cout << " ";
                player1->change_position(Y1, X1 + 1);
            }
            break;
        case 'I': case 'i':
            if (Y2 - 1 + Ycoord < Ycoord) { return; }
            if (neighbors_player2[1] == player1) {
                player1->defence(*player2, player2->attack(*player1)); descriptCharacter();
                (str2.append(" атаковал ")).append(str);
                updateStatus(str2);
            }
            else {
                field->set_element(X2, Y2, nullptr);
                field->set_element(X2, Y2 - 1, player2);
                cursorPos = { static_cast<SHORT>(X2 + Xcoord),static_cast<SHORT>(Y2 + Ycoord - 1) };
                SetConsoleCursorPosition(console, cursorPos);
                SetConsoleTextAttribute(console, FOREGROUND_RED);
                std::cout << "C";
                SetConsoleTextAttribute(console, saved_attributes);
                cursorPos = { static_cast<SHORT>(X2 + Xcoord),static_cast<SHORT>(Y2 + Ycoord) };
                SetConsoleCursorPosition(console, cursorPos);
                std::cout << " ";
                player2->change_position(Y2 - 1, X2);
            }
            break;
        case 'J': case 'j':
            if (X2 + Xcoord < Xcoord + 1) { return; }
            if (neighbors_player2[3] == player1) {
                player1->defence(*player2, player2->attack(*player1)); descriptCharacter();
                (str2.append(" атаковал ")).append(str);
                updateStatus(str2);
            }
            else {
                field->set_element(X2, Y2, nullptr);
                field->set_element(X2 - 1, Y2, player2);
                cursorPos = { static_cast<SHORT>(X2 + Xcoord - 1),static_cast<SHORT>(Y2 + Ycoord) };
                SetConsoleCursorPosition(console, cursorPos);
                SetConsoleTextAttribute(console, FOREGROUND_RED);
                std::cout << "C";
                SetConsoleTextAttribute(console, saved_attributes);
                cursorPos = { static_cast<SHORT>(X2 + Xcoord),static_cast<SHORT>(Y2 + Ycoord) };
                SetConsoleCursorPosition(console, cursorPos);
                std::cout << " ";
                player2->change_position(Y2, X2 - 1);
            }
            break;
        case 'K': case 'k':
            if (Y2 + Ycoord > 25) { return; }
            if (neighbors_player2[6] == player1) {
                player1->defence(*player2, player2->attack(*player1)); descriptCharacter();
                (str2.append(" атаковал ")).append(str);
                updateStatus(str2);
            }
            else {
                field->set_element(X2, Y2, nullptr);
                field->set_element(X2, Y2 + 1, player2);
                cursorPos = { static_cast<SHORT>(X2 + Xcoord),static_cast<SHORT>(Y2 + Ycoord + 1) };
                SetConsoleCursorPosition(console, cursorPos);
                SetConsoleTextAttribute(console, FOREGROUND_RED);
                std::cout << "C";
                SetConsoleTextAttribute(console, saved_attributes);
                cursorPos = { static_cast<SHORT>(X2 + Xcoord),static_cast<SHORT>(Y2 + Ycoord) };
                SetConsoleCursorPosition(console, cursorPos);
                std::cout << " ";
                player2->change_position(Y2 + 1, X2);
            }
            break;
        case 'L': case 'l':
            if (X2 + Xcoord > 92) { return; }
            if (neighbors_player2[4] == player1) {
                player1->defence(*player2, player2->attack(*player1)); descriptCharacter();
                (str2.append(" атаковал ")).append(str);
                updateStatus(str2);
            }
            else {
                field->set_element(X2, Y2, nullptr);
                field->set_element(X2 + 1, Y2, player2);
                cursorPos = { static_cast<SHORT>(X2 + Xcoord + 1),static_cast<SHORT>(Y2 + Ycoord) };
                SetConsoleCursorPosition(console, cursorPos);
                SetConsoleTextAttribute(console, FOREGROUND_RED);
                std::cout << "C";
                SetConsoleTextAttribute(console, saved_attributes);
                cursorPos = { static_cast<SHORT>(X2 + Xcoord),static_cast<SHORT>(Y2 + Ycoord) };
                SetConsoleCursorPosition(console, cursorPos);
                std::cout << " ";
                player2->change_position(Y2, X2 + 1);
            }
            break;
        }
    }
    if (player1->get_hp() < 0) { 
        updateStatus("<-Player1 погиб: - 1 жизнь->         ");
        player1life--;
        cursorPos = { static_cast<SHORT>(X1 + Xcoord),static_cast<SHORT>(Y1 + Ycoord) };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << " ";
        field->restore_character(player1); player1->set_hp(Hp1); player1->set_armor(armor1); player1->set_power(power1);
        cursorPos = { static_cast<SHORT>(player1->get_x() + Xcoord),static_cast<SHORT>(player1->get_y() + Ycoord) };
        SetConsoleCursorPosition(console, cursorPos);
        SetConsoleTextAttribute(console, FOREGROUND_BLUE);
        std::cout << "C";
        SetConsoleTextAttribute(console, saved_attributes);
        field->set_element(X1, Y1, nullptr);
        descriptCharacter();
        updateStatus("<-Player1 возрожден->            ");
    }
    if (player2->get_hp() < 0) { 
        updateStatus("<-Player2 погиб: - 1 жизнь->         ");
        player2life--;
        cursorPos = { static_cast<SHORT>(X2 + Xcoord),static_cast<SHORT>(Y2 + Ycoord) };
        SetConsoleCursorPosition(console, cursorPos);
        std::cout << " ";
        field->restore_character(player2); player2->set_hp(Hp2); player2->set_armor(armor2); player2->set_power(power2);
        cursorPos = { static_cast<SHORT>(player2->get_x() + Xcoord),static_cast<SHORT>(player2->get_y() + Ycoord) };
        SetConsoleCursorPosition(console, cursorPos);
        SetConsoleTextAttribute(console, FOREGROUND_RED);
        std::cout << "C";
        SetConsoleTextAttribute(console, saved_attributes);
        field->set_element(X2, Y2, nullptr);
        descriptCharacter();
        updateStatus("<-Player2 возрожден->          ");
    }
}


void Gameplay::ShowMainMenu() {
    system("cls");
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