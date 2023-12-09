#pragma once

#include "Algo.h" 
#include "Book.h"
#include "HashTable.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <msclr/marshal_cppstd.h>

class Database {
public:
    Database() {

    }
    int countLines(const std::string& filename){
        std::ifstream file(filename);
        std::string line;
        int res = 0;
        while (std::getline(file, line)) {
            res++;
        }
        return res;
    }

    int loadFromDatabaseFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            return false;
        }
        HashTable ht(countLines(filename));

        std::string line;
        while (std::getline(file, line)) {
            std::vector<std::string> parts;
            std::stringstream ss(line);
            std::string part;
            while (std::getline(ss, part, ':')) {
                parts.push_back(part);
            }
            if (parts.size() != 4) {
                continue;
            }
            if (!IsValidBookTitle(msclr::interop::marshal_as<System::String^>(parts[0]))) {
                continue;
            }
            if (!IsValidFIO(msclr::interop::marshal_as<System::String^>(parts[1]))) {
                continue;
            }
            if (!IsValidYear(msclr::interop::marshal_as<System::String^>(parts[2]))) {
                continue;
            }
            if (!IsValidGenre(msclr::interop::marshal_as<System::String^>(parts[3]))) {
                continue;
            }

            std::istringstream iss(parts[1]);
            std::vector<std::string> tokens;

            do {
                std::string subs;
                iss >> subs;
                tokens.push_back(subs);
            } while (iss);
            Book existingBook = ht.search(tokens[0], tokens[1], tokens[2], parts[0]);
            if (existingBook.bookname == "") {
                ht.add(parts[0], tokens[0], tokens[1], tokens[2], std::stoi(parts[2]), parts[3], 0);
                books.push_back({ parts[0], {tokens[0], tokens[1], tokens[2]}, std::stoi(parts[2]), parts[3] });
            }
        }
        return static_cast<int>(books.size());
    }

    std::vector<Book> getAllBooks() const {
        return books;
    }

private:
    std::vector<Book> books;
};