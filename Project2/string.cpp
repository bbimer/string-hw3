#include <iostream>
#include "string.h"
using namespace std;

String::String(const char* word) {
    this->size = 0;
    while (word[this->size] != '\0' && this->size < 79) {
        this->size++;
    }

    if (this->size < 80) {
        for (int i = 0; i < this->size; ++i) {
            wrd[i] = word[i];
        }
        wrd[this->size] = '\0';
    }
    else {
        newArr = new char[size + 1];
        for (int i = 0; i < size; ++i) {
            newArr[i] = word[i];
        }
        newArr[size] = '\0';
    }
}

String::String(const String& other) {
    copy_from(other);
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] newArr;
        newArr = nullptr;
        copy_from(other);
    }
    return *this;
}

String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        delete[] newArr;
        newArr = other.newArr;
        size = other.size;

        other.newArr = nullptr;
        other.size = 0;
    }
    return *this;
}

String String::operator+(const String& other) const {
    int new_size = size + other.size;
    char* str = new char[new_size + 1];

    int i = 0;
    for (; i < size; ++i) {
        str[i] = newArr ? newArr[i] : wrd[i];
    }

    for (int j = 0; j < other.size; ++j, ++i) {
        str[i] = other.newArr ? other.newArr[j] : other.wrd[j];
    }
    str[i] = '\0';

    String result(str);
    delete[] str;
    return result;
}

String& String::operator+=(const String& other) {
    int new_size = size + other.size;
    char* str = new char[new_size + 1];

    int i = 0;
    for (; i < size; ++i) {
        str[i] = newArr ? newArr[i] : wrd[i];
    }

    for (int j = 0; j < other.size; ++j, ++i) {
        str[i] = other.newArr ? other.newArr[j] : other.wrd[j];
    }
    str[i] = '\0';

    delete[] newArr;
    newArr = str;
    size = new_size;

    return *this;
}

const char& String::operator[](int index) const {
    return newArr ? newArr[index] : wrd[index];
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    os << (str.newArr ? str.newArr : str.wrd);
    return os;
}

bool String::operator==(const String& other) const {
    if (size != other.size) {
        return false;
    }
    for (int i = 0; i < size; ++i) {
        char this_char = newArr ? newArr[i] : wrd[i];
        char other_char = other.newArr ? other.newArr[i] : other.wrd[i];
        if (this_char != other_char) {
            return false;
        }
    }
    return true;
}

bool String::operator!=(const String& other) const {
    return !(*this == other);
}

bool String::operator>(const String& other) const {
    int min_size = std::min(size, other.size);
    for (int i = 0; i < min_size; ++i) {
        char this_char = newArr ? newArr[i] : wrd[i];
        char other_char = other.newArr ? other.newArr[i] : other.wrd[i];
        if (this_char > other_char) {
            return true;
        }
        else if (this_char < other_char) {
            return false;
        }
    }
    return size > other.size;
}

bool String::operator<(const String& other) const {
    int min_size = std::min(size, other.size);
    for (int i = 0; i < min_size; ++i) {
        char this_char = newArr ? newArr[i] : wrd[i];
        char other_char = other.newArr ? other.newArr[i] : other.wrd[i];
        if (this_char < other_char) {
            return true;
        }
        else if (this_char > other_char) {
            return false;
        }
    }
    return size < other.size;
}

String::String(String&& other) noexcept
    : newArr(other.newArr), size(other.size) {
    other.newArr = nullptr;
    other.size = 0;
}

String::~String() {
    delete[] newArr;
}

void String::copy_from(const String& other) {
    size = other.size;
    if (other.newArr != nullptr) {
        newArr = new char[size + 1];
        for (int i = 0; i < size; ++i) {
            newArr[i] = other.newArr[i];
        }
        newArr[size] = '\0';
    }
    else {
        for (int i = 0; i < size; ++i) {
            wrd[i] = other.wrd[i];
        }
        wrd[size] = '\0';
    }
}

void String::print() const {
    std::cout << (newArr ? newArr : wrd) << std::endl;
}
