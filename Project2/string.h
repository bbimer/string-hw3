#pragma once
class String
{
private:
	int size = 0;
	char wrd[80]{};
	char* newArr = nullptr;

	void copy_from(const String& other);

public:
	String(const char* word);

	String(const String& other);

	String& operator=(const String& other);
	String operator+(const String& other) const;
	String& operator+=(const String& other);
	const char& operator[](int index) const;
	friend std::ostream& operator<<(std::ostream& os, const String& str);
	bool operator==(const String& other) const;
	bool operator!=(const String& other) const;
	bool operator>(const String& other) const;
	bool operator<(const String& other) const;
	String& operator=(String&& other) noexcept;

	String(String&& other) noexcept;

	~String();
	
	void print() const;
};