#pragma once

#include "Algo.h"
#include "Book.h"
#include <vector>

class HashTable {
private:
    struct HashEntry {
        bool occupied;
        Book book;
        HashEntry() : occupied(false) {}
    };

    int initialSize;
    int size;
    int count;
    int k;
    std::vector<HashEntry> table;

    int HashTable::hash(const std::string& key) {
        int hash = 0;
        for (int i = 0; i < key.size(); i += 2) {
            std::string substring = key.substr(i, 2);
            for (char c : substring) {
                hash += static_cast<int>(c);
            }
        }
        return hash % size;
    }

    int HashTable::linearProbe(int index, int attempt, int step) {
        return (index + attempt * step) % size;
    }

    int HashTable::resolveCollision(int index, const std::string& key, const std::vector<HashEntry>& table) {
        int attempt = 1;
        int newIndex = linearProbe(index, attempt, k);

        while (table[newIndex].occupied && getKey(table[newIndex].book) != key) {
            attempt++;
            newIndex = linearProbe(index, attempt, k);
        }

        return newIndex;
    }

    void HashTable::resizeTable(int newSize) {
        this->size = newSize;
        this->k = findCoprime(newSize);
        std::vector<HashEntry> newTable(newSize);
        int newCount = 0;

        for (const auto& entry : table) {
            if (entry.occupied) {
                std::string key = getKey(entry.book);
                int index = hash(key);

                if (newTable[index].occupied) {
                    index = resolveCollision(index, key, newTable);
                }

                newTable[index].occupied = true;
                newTable[index].book = entry.book;
                newCount++;
            }
        }
        table = std::move(newTable);
        count = newCount;
    }

    std::string HashTable::getKey(Book book) {
        return book.bookname + book.fio.surname + book.fio.name + book.fio.patronymic;
    }

    void HashTable::addAfterRemoval(int index) {
        int step = k;
        int newIndex = (index + step) % size;
        while (table[(newIndex + k) % size].occupied && hash(getKey(table[(newIndex + k) % size].book)) == hash(getKey(table[index].book))) {
            step += k;
            newIndex = (index + step) % size;
        }
        if (table[newIndex].occupied) {
            table[index] = table[newIndex];
            table[newIndex].occupied = false;
        }
        for (int i = 0; i < size; i++) {
            if (table[i].occupied) {
                int bookHash = hash(getKey(table[i].book));
                if (!table[bookHash].occupied) {
                    table[bookHash] = table[i];
                    table[i].occupied = false;
                }
            }
        }
    }

public:
    HashTable::HashTable(int initialSize) : size(initialSize), count(0), k(0) {
        table.resize(size);
        this->k = findCoprime(initialSize);
        this->initialSize = size;
    }

    HashTable::~HashTable() {
        HashTable::clear();
    }

    void HashTable::clear() {
        for (int i = 0; i < size; i++) {
            table[i].occupied = false;
            table[i].book = Book();
        }
        count = 0;
        resizeTable(initialSize);
    }
    
    void HashTable::add(const std::string& bookname, const std::string& surname, const std::string& name, const std::string& patronymic, int year, const std::string& genre, int num) {
        Book book{ {bookname}, {surname,name,patronymic}, {year}, {genre}, {num} };
        if (book == search(book.fio.surname, book.fio.name, book.fio.patronymic, book.bookname)) {
            return;
        }
        std::string key = getKey(book);
        int index = hash(key);

        if (!table[index].occupied) {
            table[index].occupied = true;
            table[index].book = book;
            count++;
        }
        else {
            int newIndex = resolveCollision(index, key, table);
            if (getKey(table[newIndex].book) == key) {
                return;
            }
            table[newIndex].occupied = true;
            table[newIndex].book = book;
            count++;
        }
        if (count >= 0.75 * size) {
            resizeTable(2 * size);
        }
    }

    void HashTable::remove(const std::string& bookname, const std::string& surname, const std::string& name, const std::string& patronymic) {
        std::string key = bookname + surname + name + patronymic;
        int index = hash(key);
        bool flag = false;
        if (table[index].occupied && table[index].book.bookname == bookname && table[index].book.fio.name == name && table[index].book.fio.surname == surname && table[index].book.fio.patronymic == patronymic) {
            table[index].occupied = false;
            count--;
            flag = true;
            addAfterRemoval(index);
        }
        else {
            int newIndex = resolveCollision(index, key, table);
            if (table[newIndex].occupied && table[newIndex].book.bookname == bookname && table[newIndex].book.fio.name == name && table[newIndex].book.fio.surname == surname && table[newIndex].book.fio.patronymic == patronymic) {
                table[newIndex].occupied = false;
                count--;
                flag = true;
                addAfterRemoval(newIndex);
            }
        }

        if (!flag) {
            return;
        }

        if (count <= 0.25 * size && size / 2 >= initialSize) {
            resizeTable(size / 2);
        }
    }

    const Book HashTable::search(const std::string& surname, const std::string& name, const std::string& patronymic, const std::string& bookname) {
        std::string key = bookname + surname + name + patronymic;
        int index = hash(key);

        if (table[index].occupied) {
            if (getKey(table[index].book) == key) {
                return table[index].book;
            }
            int newIndex = resolveCollision(index, key, table);
            if (getKey(table[newIndex].book) == key) {
                return table[newIndex].book;
            }
        }
        Book book{ {""}, {"","",""}, {0}, {""}, 0 };
        return book;
    }
    
    std::vector<Book> HashTable::returnTable() {
        Book book;
        std::vector<Book> books(size);
        for (int i = 0; i < size; i++) {
            if (table[i].occupied) {
                books[i] = table[i].book;
            }
            else {
                books[i].bookname = "N/A";
            }
        }
        return books;
    }

    void HashTable::updateIndex(int newIndex) {
        int maxIndex = -1;
        int maxIndexPosition = -1;

        for (int i = 0; i < size; i++) {
            if (table[i].occupied && table[i].book.index > maxIndex) {
                maxIndex = table[i].book.index;
                maxIndexPosition = i;
            }
        }

        if (maxIndexPosition != -1) {
            table[maxIndexPosition].book.index = newIndex;
        }
    }

    int HashTable::hashF(const std::string& key) {
        return hash(key);
    }

    int HashTable::returnK() {
        return k;
    }

    int HashTable::returnSize() {
        return size;
    }
};