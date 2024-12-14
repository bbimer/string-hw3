#include <iostream>
#include "string.h"
using namespace std;

int main() {
    String str1("Hello");
    String str2(" World");

    str1.print();
    str2.print();

    String result = str1 + str2;
    result.print();

    str1 += str2;
    str1.print();
    cout << str2[1] << endl;
    int str3 = str1 == str2;
    int str4 = str1 != str2;
    int str5 = (str1 > str2);
    int str6 = (str1 < str2);
    cout << str3 << endl;
    cout << str4 << endl;
    cout << str5 << endl;
    cout << str6 << endl;

    return 0;
}
