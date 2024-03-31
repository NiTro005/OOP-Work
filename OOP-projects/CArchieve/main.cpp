
#include "archive.h"
#include "utilities.h"

enum Actions { EXIT, INSERT, FIND, REMOVE, CLEAN };

int main() {
    TArchive<char> archive;
    archive.data();
    size_t n, pos;
    char* values = nullptr;
    int user;

    std::exception err;
    bool exit = false;
    bool success;
    InputSystem::InsertMode mode;
    InputSystem::RemoveMode mode1;

    while (!exit) {
        system("cls");
        OutputSystem::show(archive);
        std::cout << "Menu:\n 1. insert,\n 2. find,\n 3. delete,\n 4. clean,\n 0. exit.\nYour choose: ";
        std::cin >> user;
        switch (user) {
        case Actions::EXIT:
            exit = true;
            break;
        case Actions::INSERT:
            if (values != nullptr) { delete[] values; values = nullptr; }
            values = InputSystem::insert<char>(n, pos, mode);
            success = false;
            try {
                if (mode == InputSystem::InsertMode::OneValue) {
                    archive.insert(values[0], pos);
                }
                else if (mode == InputSystem::InsertMode::SeveralValues) {
                    archive.insert(values, n, pos);
                }
                else if (mode == InputSystem::InsertMode::Back) {
                    archive.push_back(values[0]);
                }
                else {
                    archive.push_front(values[0]);
                }
                success = true;
            }
            catch (std::exception& err) {
                std::cerr << err.what() << std::endl;
            }
            if (success) {
                OutputSystem::insert();
            }
            system("pause>nul");
            break;
        case Actions::FIND:
            std::cout << "TBD" << std::endl;
            system("pause");
            break;
        case Actions::REMOVE:
            if (values != nullptr) { delete[] values; values = nullptr; }
            values = InputSystem::remove<char>(n, pos, mode1);
            success = false;
            try {
                if (mode1 == InputSystem::RemoveMode::Back1) {
                    archive.pop_back();
                }
                else if (mode1 == InputSystem::RemoveMode::Front1) {
                    archive.pop_front();
                }
                else if (mode1 == InputSystem::RemoveMode::OneValue1) {
                    archive.remove_by_index(pos);
                }
                success = true;
            }
            catch (std::exception& err) {
                std::cerr << err.what() << std::endl;
            }
            if (success) {
                OutputSystem::remove();
            }
            system("pause>nul");
            break;
        case Actions::CLEAN:
            archive.clear();
            break;
        }
    }

    return 0;
}
