#include <iostream>
#include <cstring>
#include "string.h"
using namespace std;

String::String(const char* word) {
	this->size = strlen(word);
	newArr = nullptr;  
	if (this->size < sizeof(wrd)) {
		size_t i = 0;
		while (i < this->size && i < sizeof(wrd) - 1) {
			wrd[i] = word[i];
			++i;
		}
		wrd[i] = '\0';
	}
	else {
		size_t BigSize = strlen(word) + 1;
		newArr = new char[BigSize];
		for (size_t i = 0; i < BigSize; ++i) {
			newArr[i] = word[i];
		}
	}
}



String::String(const String& other) {
	copy_from(other);
}

String String::operator=(const String& other) {
	if (this != &other)
	{
		delete[] newArr;
		newArr = nullptr;
		copy_from(other);
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

	for (int j = 0; j < size; ++j, ++i) {
		str[i] = newArr ? newArr[j] : wrd[j];
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
	if (str.newArr != nullptr) {
		os << str.newArr;
	}
	else {
		os << str.wrd;
	}
	return os;  
}

bool String::operator==(const String& other) const {
	if (size != other.size) {
		return false;
	}
	for (size_t i = 0; i < size; ++i) {
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
	size_t min_size = std::min(size, other.size);
	for (size_t i = 0; i < min_size; ++i) {
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
	size_t min_size = std::min(size, other.size);
	for (size_t i = 0; i < min_size; ++i) {
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





String::~String() {
	delete[] newArr;
	newArr = nullptr;
}

void String::copy_from(const String& other) {
	size = other.size;
	if (other.newArr != nullptr) {
		newArr = new char[size + 1];
		for (size_t i = 0; i < size; ++i) {
			newArr[i] = other.newArr[i];
		}
		newArr[size] = '\0';
	}
	else {
		for (size_t i = 0; i < sizeof(wrd); ++i) {
			wrd[i] = other.wrd[i];
		}
		wrd[size] = '\0';
	}
}

void String::print() const {
	if (newArr != nullptr) {
		cout << newArr << endl;
	}
	else {
		cout << wrd << endl;
	}
}