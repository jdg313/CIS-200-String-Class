#include <iostream>
#include <cstdlib>
#include <cstring>

class myString {
    private:
        char* str;
        int status;
    public:
        myString(); // Default Constructor
        myString(char* inpStr); // C style Constructor
        myString(const std::string cppStyle); // String Constructor
        myString(const myString& orig); // Copy Constructor
        ~myString() { delete[] str; str = nullptr; } // Destructor
        myString& operator=(const myString& orig); // Overload = operator
        int Size() const { return strlen(str); } // Returns amount of chars in string
        void addStart(const myString& orig); // Adds orig string to front of current string
        void addEnd(const myString& orig); // Adds orig string to end of current string
        myString partString(const int startPos, const int length); // Returns as myString the protion from startPos for length given
        std::string replPartString(const myString& orig, const int startPos, const int length); // Replaces length chars starting at startPos and returns new myString
        std::string replWholeString(const myString& orig); // Replaces curr str value with param, returns new string
        int compareString(const myString& orig); // Compares this->str to paramater str
        void initString() { delete[] str; str = new char[1]; *str = '\0'; } // Initialize string
        std::string setString(const std::string usrStr); // Sets c style string
        std::string getString() const { return str; } // Return the C style string
        void printStringScreen() const { std::cout << str << std::endl; } // print str to screen
        bool numericString() const; // check if str is an int or real #
        bool alphabeticString() const; // check if str is purely alpha

};