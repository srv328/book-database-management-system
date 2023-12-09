# the-management-of-book-related-data
the code handles the management of book-related data in a Windows Forms application, offering functionalities like importing/exporting data, searching through the book database, adding/removing books, and managing the user interface based on these operations.

Book Database Management System
===============================

This project is a Windows Forms application designed to manage a book database. It allows users to perform various operations like adding, deleting, and searching for books based on different criteria.

Overview
--------

The application consists of several functionalities:

### File Operations

*   **Export Data:** Exports the current book database to a text file named `books.txt`.
*   **Import Data:** Imports book data from an external source, populating the database.

### Database Manipulation

*   **Adding and Deleting Records:** Users can add new book records or delete existing ones from the database.
*   **Searching:** Supports multiple search criteria such as book title, author, genre, and publication year.

### User Interface Features

*   **Placeholders:** Text boxes are equipped with placeholders to guide user input.
*   **Color Indicators:** Text box colors change to indicate user input, placeholders, or errors.
*   **Combo Search:** Allows combined searches using book title and author.

Components
----------

The project is structured into multiple files:
1. [algo.h](#algoh) Contains algorithmic functions for data manipulation.
2. [book.h](#bookh) Defines the structure and properties of a Book.
3. [database.h](#databaseh) Manages the database operations.
4. [hashtable.h](#hashtableh) Implements a hash table for efficient data retrieval
5. [list.h](#listh) Provides functionalities for linked lists.
6. [rbtree.h](#rbtreeh) Implements a Red-Black Tree for sorted data storage.

## algo.h

*   **`gcd(int a, int b)`**: Computes the greatest common divisor of two integers using the Euclidean algorithm.
    
*   **`findCoprime(int n)`**: Finds a coprime number to a given integer `n`.
    
*   **`isNumeric(const std::string& str)`**: Checks if a string contains only numeric characters.
    
*   **`IsValidFIO(System::String^ text)`**: Validates whether the input string matches the format of a name (first name, middle name, last name) where each word starts with an uppercase letter and words are separated by spaces.
    
*   **`IsValidYear(System::String^ text)`**: Validates if the input string represents a valid year between 0 and 2023.
    
*   **`IsValidBookTitle(System::String^ text)`**: Checks if the input string represents a valid book title. The title should start with an uppercase letter or a digit and can contain alphanumeric characters and spaces.
    
*   **`IsValidGenre(System::String^ text)`**: Validates if the input string represents a valid genre. The genre should start with an uppercase letter and continue with lowercase letters separated by a single space.

## book.h

This code snippet defines two C++ structures: `FIO` and `Book`.

1.  **`FIO` Struct**:
    
    *   It contains three `std::string` members: `surname`, `name`, and `patronymic`, representing the components of a full name (last name, first name, and middle name).
2.  **`Book` Struct**:
    
    *   It consists of five members:
        *   `bookname`: A `std::string` representing the title of the book.
        *   `fio`: An instance of the `FIO` struct, representing the author's name components (surname, name, and patronymic).
        *   `year`: An `int` indicating the publication year of the book.
        *   `genre`: A `std::string` specifying the genre of the book.
        *   `index`: An `int` used for indexing or identifying the book.

Additionally, the `Book` struct defines an `operator==` function to check for equality between two `Book` objects. The equality check is based on comparing the individual components (book name, author's name, year, and genre) of two `Book` objects.

## database.h

### Includes:

*   It includes headers for various classes and libraries (`Algo.h`, `Book.h`, `HashTable.h`, `<vector>`, `<fstream>`, `<sstream>`, `<msclr/marshal_cppstd.h>`).

### Class Structure:

*   **`Database` Class**:
    *   **Constructor**: There's a default constructor present in the `Database` class.
    *   **Member Functions**:
        *   `countLines`: Counts the number of lines in a file given the filename provided as an argument.
        *   `loadFromDatabaseFile`: Reads data from a database file (presumably containing book information). It parses each line, validates its format using different functions (`IsValidBookTitle`, `IsValidFIO`, `IsValidYear`, `IsValidGenre`), and adds valid entries to the internal `HashTable` and `books` vector.
        *   `getAllBooks`: Retrieves all books stored in the `books` vector.

### Attributes:

*   **Private Attribute**:
    *   `std::vector<Book> books`: Stores a collection of `Book` objects representing the books present in the database.

### Functionality:

*   The `loadFromDatabaseFile` function reads data from a file, validating each line's format (assuming each line represents a book entry) and storing valid entries both in the internal `HashTable` and the `books` vector.
*   The `getAllBooks` function provides access to all books stored in the `books` vector.

### Considerations:

*   This code interacts with a database file assumed to contain book information and performs parsing, validation, and storage of book data into an internal structure (`HashTable` and `books` vector).
*   The `IsValidBookTitle`, `IsValidFIO`, `IsValidYear`, and `IsValidGenre` functions appear to validate specific aspects of book information like titles, author names, publication years, and genres.

## hashtable.h

### Includes:

*   Headers for `Algo.h` and `Book.h` are included.

### `HashTable` Class:

*   **Private Members**:
    
    *   `struct HashEntry`: Holds information about each entry in the hash table.
    *   `int initialSize, size, count, k`: Variables to manage the hash table size, current count, and hashing parameters.
    *   `std::vector<HashEntry> table`: The actual hash table, using a vector of `HashEntry` structures.
*   **Private Methods**:
    
    *   `hash`: Hashes a given string key to an index in the hash table.
    *   `linearProbe`: Handles linear probing to resolve collisions.
    *   `resolveCollision`: Resolves collisions using linear probing.
    *   `resizeTable`: Resizes the hash table when it reaches a certain load factor.
    *   `getKey`: Constructs a unique key for a `Book` entry.
    *   `addAfterRemoval`: Handles reorganization of the table after removal of an entry.
*   **Public Methods**:
    
    *   `HashTable(int initialSize)`: Constructor that initializes the hash table with the given size.
    *   `~HashTable()`, `clear()`: Destructor and method to clear the hash table.
    *   `add`, `remove`, `search`: Functions to add, remove, and search for entries in the hash table.
    *   `returnTable`: Returns a vector representation of the hash table.
    *   `updateIndex`, `hashF`, `returnK`, `returnSize`: Utility functions for index updates, hashing, and obtaining table parameters.

### Functionality:

*   **Addition and Removal**:
    *   `add`: Adds a `Book` entry to the hash table.
    *   `remove`: Removes a `Book` entry from the hash table.
*   **Search**:
    *   `search`: Searches for a `Book` entry in the hash table based on provided attributes.
*   **Internal Operations**:
    *   Handles collision resolution using linear probing.
    *   Resizes the hash table dynamically based on its load factor.
    *   Manages table organization after removal.

### Considerations:

*   This hash table implementation employs linear probing for collision resolution.
*   It uses a vector as the underlying data structure for the hash table.
*   `Book` entries are stored within `HashEntry` structures in the hash table.

## list.h

### Structures:

*   **`list_elem`**: Represents an element in the doubly linked list with an integer `key`, and pointers to the `next` and `prev` elements.

### Functions:

*   **`list_init`**: Initializes an empty list and returns a pointer to the root.
*   **`list_insert`**: Inserts a new node with a given `value` into the list.
*   **`remove`**: Removes a node with a specific `key` from the list.
*   **`list_erase`**: Erases the entire list, deallocating memory.
*   **`print_list`**: Generates a string representation of the list, indicating each node's key and its connections.

### Operations:

*   **Insertion**:
    *   Inserts a new node with a specified value into the list.
*   **Removal**:
    *   Removes a node based on a given key from the list.
*   **Deletion**:
    *   Clears the entire list, freeing the allocated memory.
*   **Printing**:
    *   Generates a string representation of the list, displaying the keys of each node in sequence.

## rbtree.h

This code is a generic implementation of a Red-Black Tree. The structure `tree_elem_generic` represents a node in the tree and holds data (`T`), a color (`bool`), pointers to left and right children, a parent, and a linked list (`list_elem`).

The provided functions serve various purposes within the Red-Black Tree:

*   **Rotations** (`leftRotate` and `rightRotate`): Perform left and right rotations, respectively, on a node.
*   **Insertion** (`insert` and `insert_balance`): Handles the insertion of nodes into the Red-Black Tree and balances it to maintain the Red-Black properties.
*   **Deletion** (`erase` and `erase_balance`): Removes nodes from the tree while maintaining Red-Black properties.
*   **Search** (`search`): Looks for a specific data value within the tree.
*   **Traversal** (`print`): Generates a string representation of the Red-Black Tree.

Some additional functions include operations on the linked list within each tree node, such as insertion, removal, and printing.

The code is generic and operates on templated data types (`T`). It provides operations to maintain a balanced binary search tree and is designed to ensure that the Red-Black Tree properties (such as maintaining balance and adhering to coloring rules) are preserved throughout insertions and deletions.


Usage
-----

### Prerequisites

*   Visual Studio with C++/CLI support.

### Getting Started

1.  Open the solution file in Visual Studio.
2.  Build and run the project.
3.  Use the interface to perform operations on the book database.

### Features and Functionalities

*   **Adding a Book:** Fill in the details in the respective fields and click the "Add" button.
*   **Deleting a Book:** Select a book and click the "Delete" button.
*   **Searching for Books:** Use the provided search fields or combo search to find specific books.

Code Structure
--------------

The codebase is organized into several sections:

*   **Error Handling:** Functions to display error messages and handle exceptions.
*   **Data Conversion:** Conversion functions between C++ and .NET types.
*   **Event Handlers:** Functions triggered by UI actions (e.g., button clicks).
*   **Text Box Handling:** Methods for managing text box behaviors and placeholders.
