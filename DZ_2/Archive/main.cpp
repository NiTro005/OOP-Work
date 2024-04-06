
#include "archive.h"
#include "utilities.h"

enum Actions { EXIT, INSERT, FIND, REMOVE, CLEAN };

int main() {
    TArchive<char> archive;
    archive.data();
    size_t n, pos;
    size_t count = 0;
    char* values = nullptr;
    int user;
    size_t* result = new size_t[archive.capacity()];
    size_t* new_result = new size_t[archive.capacity()];
    std::exception err;
    bool exit = false;
    bool success;
    InputSystem::InsertMode mode;
    InputSystem::RemoveMode mode1;
    InputSystem::FindMode mode2;

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
            if (values != nullptr) { delete[] values; values = nullptr; }
            values = InputSystem::find<char>(mode2);
            success = false;
            try {
                if (mode2 == InputSystem::FindMode::FFirst) {
                    result[0] = archive.find_first(values[0]);
                    count = 1;
                }
                else if (mode2 == InputSystem::FindMode::FLast) {
                    result[0] = archive.find_last(values[0]);
                    count = 1;
                }
                else {
                    for (size_t i = 0; i < 5; i++) {
                        if (values[i] == '.') { break; }
                        size_t* temp_result = archive.find_all(values[i], n);
                        for (size_t j = 0; j < n; j++) {
                            new_result[count++] = temp_result[j];
                        }
                        delete[] temp_result;
                    }
                    result = new size_t[count];
                    std::copy(new_result, new_result + count, result);
                    delete[] new_result;
                }
                success = true;
            }
            catch (std::exception& err) {
                std::cerr << err.what() << std::endl;
            }
            if (success) {
                OutputSystem::find(result, mode2, archive, count);
                count = 0;
            }
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
                else if (mode1 == InputSystem::RemoveMode::SeveralValues1) {
                    archive.erase(pos, n);
                }
                else if (mode1 == InputSystem::RemoveMode::All) {
                    archive.remove_all(values[0]);
                }
                else if (mode1 == InputSystem::RemoveMode::First) {
                    archive.remove_first(values[0]);
                }
                else{ archive.remove_last(values[0]); }
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
