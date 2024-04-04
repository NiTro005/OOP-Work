#pragma once
#include <iostream>
#include <Windows.h>
#include "archive.h"

/*                     —À”∆≈¡Õ€≈/¬—œŒÃŒ√¿“≈À‹Õ€≈ ‘”Õ ÷»»                     */

namespace InputSystem {
    enum InsertMode {Back, Front, OneValue, SeveralValues};
    enum RemoveMode{Back1, Front1, All, First, Last, OneValue1, SeveralValues1};
    enum FindMode{FAll, FFirst, FLast};

    template <typename T>
    T* remove(size_t& n, size_t& pos, InputSystem::RemoveMode& mode) noexcept {
        T* value = nullptr;
        mode = Back1;
        int user;
        std::cout << "Choose remove mode:\n";
        std::cout << "1 - back,\n";
        std::cout << "2 - front,\n";
        std::cout << "3 - by value,\n";
        std::cout << "4 - at given position.\n";
        std::cout << "Your choose: ";
        std::cin >> user;
        if (user == 1) { mode = Back1; }
        if (user == 2) { mode = Front1; }
        if (user == 3) {
            std::cout << "Remove by value:\n";
            std::cout << "1 - first coincidence,\n";
            std::cout << "2 - last coincidence,\n";
            std::cout << "3 - all coincidence.\n";
            std::cout << "Your choose: ";
            std::cin >> user;
            if (user == 1) { mode = First; }
            if (user == 2) { mode = Last; }
            if (user == 3) { mode = All; }
        }
        if (user == 4) {
            std::cout << "How many values need to be removed:\n";
            std::cout << "1 - one value,\n";
            std::cout << "2 - several values.\n";
            std::cout << "Your choose: ";
            std::cin >> user;
            if (user == 1) { mode = OneValue1; }
            if (user == 2) { mode = SeveralValues1; }
        }
        if (mode == First || mode == Last || mode == All) {
            n = 1;
            value = new T[n];
            std::cout << "Input value for remove: ";
            std::cin >> value[0];
        }
        if (mode == SeveralValues1) {
            std::cout << "Input number of values for remove: ";
            std::cin >> n;
        }
        if (mode == OneValue1 || mode == SeveralValues1) {
            std::cout << "Input position for remove: ";
            std::cin >> pos;
        }
        return value;
    }

    template <typename T>
    T* insert(size_t& n, size_t& pos, InputSystem::InsertMode& mode) noexcept {
        T* value = nullptr;
        mode = Back;
        int user;
        std::cout << "Choose insert mode:\n";
        std::cout << "1 - to the back,\n";
        std::cout << "2 - to the front,\n";
        std::cout << "3 - at given position.\n";
        std::cout << "Your choose: ";
        std::cin >> user;
        if (user == 1) { mode = Back; }
        if (user == 2) { mode = Front; }
        if (user == 3) {
            std::cout << "How many values need to insert:\n";
            std::cout << "1 - one value,\n";
            std::cout << "2 - several values.\n";
            std::cout << "Your choose: ";
            std::cin >> user;
            if (user == 1) { mode = OneValue; }
            if (user == 2) { mode = SeveralValues; }
        }
        if (mode == Back || mode == Front || mode == OneValue) {
            n = 1;
            value = new T[n];
            std::cout << "Input value for insert: ";
            std::cin >> value[0];
        }
        if (mode == SeveralValues) {
            std::cout << "Input number of values for insert: ";
            std::cin >> n;
            value = new T[n];
            std::cout << "Input values for insert (between space): ";
            for (size_t i = 0; i < n; i++) {
                std::cin >> value[i];
            }
        }
        if (mode == OneValue || mode == SeveralValues) {
            std::cout << "Input position for insert: ";
            std::cin >> pos;
        }
        return value;
    }

    template <typename T>
    T* find(InputSystem::FindMode& mode) noexcept {
        T* value = nullptr;
        mode = FFirst;
        int user;
        std::cout << "Choose find mode:\n";
        std::cout << "1 - find all,\n";
        std::cout << "2 - find first,\n";
        std::cout << "3 - find last.\n";
        std::cout << "Your choose: ";
        std::cin >> user;
        if (user == 1) { mode = FAll; }
        if (user == 2) { mode = FFirst; }
        if (user == 3) { mode = FLast; }
        if (mode == FFirst || mode == FLast) {
            value = new T;
            std::cout << "Input value for find: ";
            std::cin >> value[0];
        }
        if (mode == FAll) {
            value = new T[5];
            std::cout << "Input values for find(max 5): ";
            for (size_t i = 0;i < 5; i++) {
                if (std::cin.peek() == '\n') {
                    std::cin.ignore();
                    break;
                }
                std::cin >> value[i];
            }
        }
        return value;
    }
}

namespace OutputSystem {
    static void setCursor(int column, int line) {
        COORD coord;
        coord.X = column;
        coord.Y = line;
        SetConsoleCursorPosition(
            GetStdHandle(STD_OUTPUT_HANDLE),
            coord
        );
    }

    static void getCursor(int& column, int& line) noexcept {
        CONSOLE_SCREEN_BUFFER_INFO csbi;

        if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
            column = csbi.dwCursorPosition.X;
            line = csbi.dwCursorPosition.Y;
        }
        else {
            column = 0;
            line = 0;
        }
    }

    static void insert() noexcept {
        std::cout << "Done." << std::endl;
    }
    static void remove() noexcept {
        std::cout << "Done." << std::endl;
    }

    template <typename T>
    void show(const TArchive<T>& archive) noexcept {
        std::cout << "Archive: { ";
        archive.print();
        if (!archive.empty()) {
            // ÒÚË‡ÂÏ ÔÓÒÎÂ‰Ì˛˛ Á‡ÔˇÚÛ˛
            int column, line;
            getCursor(column, line);
            column -= 2;
            setCursor(column, line);
        }
        std::cout << " }\n";
    }
}
