#include "String.h"
#include <cstring>
#include <cstdlib>

myString::myString() { /* DONE */
    str = new char[1];
    *str = '\0';
}

myString::myString(char* inpStr) { /* DONE */
    if (inpStr) {
        str = new char[strlen(inpStr) + 1];
        strcpy(str, inpStr);
    }
    else {
        str = new char[1];
        *str = '\0';
    }
}

myString::myString(const std::string cppStyle) { /* DONE */
    str = new char[cppStyle.length() + 1];
    for (int i = 0; i < cppStyle.length(); i++) {
        str[i] = cppStyle[i];
    }
    str[cppStyle.length()] = '\0';
}

myString::myString(const myString& orig) { /* DONE */
    str = new char[strlen(orig.str) + 1]; 
    strcpy(str, orig.str);
    status = orig.status;
}

myString& myString::operator=(const myString& orig) { /* DONE */
    if (this != &orig) {
        delete[] str;
        str = new char[strlen(orig.str) + 1];
        strcpy(str, orig.str);
        status = orig.status;
    }
    return *this;
}

void myString::addStart(const myString& orig) { /* DONE */
    // null error check
    if (str == nullptr || orig.str == nullptr) {
        std::cout << "Error: one or more strings = nullptr, no value modified\n";
        return;
    }

    int origLen = strlen(orig.str);
    int currLen = strlen(str);

    char* temp = new char[currLen + 1];
    strcpy(temp, str);

    delete[] str;
    str = new char[origLen + currLen + 1];
    
    strcpy(str, orig.str);
    strcpy(str + origLen, temp);

    delete[] temp;
    temp = nullptr;
}

void myString::addEnd(const myString& orig) { /* DONE */
    // null error check
    if (str == nullptr || orig.str == nullptr) {
        std::cout << "Error: one or more strings = nullptr, no value modified\n";
        return;
    }

    int origLen = strlen(orig.str);
    int currLen = strlen(str);
    int fullLen = currLen + origLen;

    char* newStr = new char[fullLen + 1];
    
    strcpy(newStr, str);
    strcpy(newStr + currLen, orig.str);

    delete[] str;
    str = newStr;
}

myString myString::partString(const int startPos, const int length) { /* DONE */
    int currLen = strlen(str);

    if (startPos == currLen) {
        myString newStr;
        return newStr;
    }
    else if (startPos + length > currLen) { // Error 1 check
        status = 0;
        std::cout << "Error: Start Position + Length is greater than the original string length";
        std::cout << "\nReturning null string\n";
        myString newStr;
        return newStr;
    }
    else if (startPos > currLen) { // Error 2 check
        status = 0;
        std::cout << "Error: Start position is greater than the original string length";
        std::cout << "\nReturning null string\n";
        myString newStr;
        return newStr;
    }
    else if (startPos < 1) { // Error 3 check
        status = 0;
        std::cout << "Error: Start position is less than 1";
        std::cout << "\nReturning null string\n";
        myString newStr;
        return newStr;
    }
    else if (length <= 0) { // Error 4 check
        status = 0;
        std::cout << "Error: Length is less than 1";
        std::cout << "\nReturning null string\n";
        myString newStr;
        return newStr;
    }
    else {
        int idx = startPos - 1;
        int j = 0;
        char* newString = new char[length + 1];

        for (int i = idx; i < length + idx; ++i) {
            newString[j] = str[i];
            j++;
        }

        newString[j] = '\0';

        myString newStr(newString);

        delete[] newString;
        newString = nullptr;

        return newStr;
    }
}

std::string myString::setString(const std::string usrStr) { /* DONE */
    delete[] str;
    str = new char[usrStr.length() + 1];

    for (int i = 0; i < usrStr.length(); ++i) {
        str[i] = usrStr[i];
    }
    
    str[usrStr.length()] = '\0';

    return str;
}

std::string myString::replPartString(const myString& orig, const int startPos, const int length) { /* DONE */
    // Error Checks
    if (str == nullptr || orig.str == nullptr) {
        std::cout << "Error: one or more strings = nullptr, no value modified, returning \"Null\"\n";
        return "Null";
    }
    if (startPos < 1 || startPos > strlen(str)) {
        std::cout << "Invalid startPos, out of range, no value modified, returning \"Null\"\n";
        return "Null";
    }
    if (length < 0 || (startPos - 1) + length > strlen(str)) {
        std::cout << "Invalid length, no value modified, returning \"Null\"\n";
        return "Null";
    }

    char* newStr;
    int appendStatus = 0;
    int idx = startPos - 1;

    int newLen = ((strlen(str) - length) + strlen(orig.str)) + 1;
    newStr = new char[newLen];

    for (int i = 0; i < newLen; ++i) {
        if (i == idx) {
            newStr[i] = '\0'; // for use with strcat() func
            strcat(newStr, orig.str);
            i += strlen(orig.str);
            appendStatus = 1;
        }
        if (appendStatus == 1) {
            newStr[i] = str[(i - strlen(orig.str)) + length];
        }
        else {
            newStr[i] = str[i];
        }
    }
    newStr[newLen - 1] = '\0';
    
    delete[] str;
    str = nullptr;

    str = new char[newLen];
    strcpy(str, newStr);

    delete[] newStr;
    newStr = nullptr;

    return str;
}

std::string myString::replWholeString(const myString& orig) { /* DONE */
    // null error check
    if (orig.str == nullptr) {
        std::cout << "Error: paramter string is nullptr, no value modified, returning \"Null\"\n";
        return "Null";
    }

    delete[] str;
    str = nullptr;

    str = new char[strlen(orig.str) + 1];
    strcpy(str, orig.str);

    str[strlen(orig.str)] = '\0';

    return str;
}

int myString::compareString(const myString& orig) { /* DONE */
    // Null error check
    if (str == nullptr || orig.str == nullptr) {
        std::cout << "Error: a string in comparison is = to a nullptr, returning 1000\n";
        return 1000;
    }

    int len = strlen(str);
    int origLen = strlen(orig.str);
    int minLen = std::min(len, origLen);
    
    for (int i = 0; i < minLen; ++i) {
        // Case insensitive compare
        char char1 = std::tolower(str[i]);
        char char2 = std::tolower(orig.str[i]);

        if (char1 != char2) {
            if (char1 < char2) {
                return i + 1;
            }
            else {
                return -(i + 1);
            }
        }
    }

    if (len == origLen) {
        return 0;
    }

    return (len < origLen) ? -(minLen + 1) : minLen + 1; // If strLen !=, return pos of longer str (as it comes first alpha)
}

bool myString::numericString() const { /* DONE */
    // null check
    if (str == nullptr) {
        std::cout << "String is nullptr, returning false\n";
        return false;
    }

    bool numeric = false;
    int decStatus = 0; // limit to one decimal
    int len = strlen(str);

    for (int i = 0; i < len; ++i) {
        if (isalpha(str[i])) {
            return numeric;
        }
        if (isspace(str[i])) {
            return numeric;
        }
        if (ispunct(str[i])) {
            if (str[i] == '.' || str[i] == '-') { // Unsure if + is necc, clarify more about this func
                if (decStatus == 0 && str[i] == '.') {
                    decStatus = 1;
                    continue;
                }
                if (decStatus == 1 && str[i] == '.') {
                    return numeric;
                }
                if ((str[i] == '-') && (i == 0)) { // ensure negation is at beginning
                    continue;
                }
                if ((str[i] == '-') && (i != 0)) {
                    return numeric;
                }
            }
            else {
                return numeric;
            } 
        }
    }
    numeric = true;
    return numeric;
}

bool myString::alphabeticString() const { /* DONE */
    // null check
    if (str == nullptr) {
        std::cout << "String is nullptr, returning false\n";
        return false;
    }

    bool alpha = false;
    int len = strlen(str);

    // unsure about spaces and punc, again, ask and clarify more about this func
    for (int i = 0; i < len; ++i) {
        if ((!isalpha(str[i])) && (!isspace(str[i])) && (!ispunct(str[i]))) {
            return alpha;
        }
    }

    alpha = true;
    return alpha;
}