#pragma once

#include <string>

struct FIO {
    std::string surname;
    std::string name;
    std::string patronymic;
};

struct Book {
    std::string bookname;
    FIO fio;
    int year;
    std::string genre;
    int index;
    bool operator==(const Book& other) const {
        return bookname == other.bookname && fio.surname == other.fio.surname &&
            fio.name == other.fio.name && fio.patronymic == other.fio.patronymic &&
            year == other.year && genre == other.genre;
    }
};



