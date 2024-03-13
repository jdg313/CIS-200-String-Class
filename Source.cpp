#include <iostream>
#include "String.h"

int main() {
    myString test("Hello");
    myString copy("Copy");

    myString test2(test);

    std::cout << test2.Size() << std::endl;
    test2 = copy;
    std::cout << test2.Size() << std::endl;

    std::cout << copy.getString() << " :After addStart: ";
    copy.addStart(test);
    std::cout << copy.getString() << std::endl;
    std::cout << copy.Size() << std::endl;

    copy.addEnd(test);
    std::cout << copy.getString() << std::endl;
    std::cout << copy.Size() << std::endl << std::endl;

    myString str1("Officer");
    myString str2(str1.partString(1, 3));

    std::cout << str2.getString() << std::endl;

    myString str3(str1.partString(1, 0));
    myString str4(str1.partString(1, 8));
    myString str5(str1.partString(0, 5));

    myString str6("There");
    std::cout << str6.replPartString(str1, 4, 1) << std::endl;

    std::cout << str6.getString() << std::endl;
    std::cout << str6.Size() << std::endl;

    std::cout << "Before replace: " << str6.getString() << std::endl;
    std::cout << "After replace: " << str6.replWholeString(test) << std::endl;

    std::cout << "Comparing " << str6.getString() << " to " << str1.getString() << std::endl;
    std::cout << str6.compareString(str1) << std::endl;

    str6.printStringScreen();

    myString str7("123");
    myString str8("1.23");
    myString str9("%1.2.3");
    myString str10("Hello");
    myString str11("Hello1");

    std::cout << str7.numericString() << str8.numericString() << str9.numericString()
    << str10.numericString() << str11.numericString() << std::endl;

    std::cout << str7.alphabeticString() << str8.alphabeticString() << str9.alphabeticString()
    << str10.alphabeticString() << str11.alphabeticString() << std::endl;

    return 0;
}

