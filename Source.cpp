#include <iostream>
#include <fstream>
#include <iomanip>
#include <string> // Only for to_string comparison
#include "String.h"
#include <sstream>

void logToFile(const char* filename, const std::string& methodName, const std::string& originalValue, const std::string& parameters, const std::string& modifiedValue, const std::string& message) {
    std::ofstream outFile(filename, std::ios::app);
    if (!outFile) {
        std::cerr << "Error opening file for output." << std::endl;
        return;
    }

    // Prepare log entry
    std::stringstream logEntry;
    logEntry << std::left
             << std::setw(20) << "Method" << std::setw(20) << "Original Value" << std::setw(30) << "Parameters"
             << std::setw(20) << "Modified Value" << std::setw(20) << "Comments" << std::endl;
    logEntry << std::setw(20) << methodName << std::setw(20) << originalValue << std::setw(30) << parameters
             << std::setw(20) << modifiedValue << std::setw(20) << message << std::endl
             << std::endl;

    // Write to file
    outFile << logEntry.str();
    outFile.close();
}

void actionOutput(const char* summaryFilename, const std::string& methodName, const std::string& message, const std::string& result) {
    std::ofstream summaryFile(summaryFilename, std::ios::app);
    if (!summaryFile) {
        std::cerr << "Error opening action log file for output." << std::endl;
        return;
    }

    // Prepare action output entry
    std::stringstream logEntry;
    logEntry << std::left 
             << std::setw(20) << "Action" 
             << std::setw(20) << "Outcome" 
             << std::setw(30) << "Result" << std::endl; // Adding a column for results
    logEntry << std::setw(20) << methodName 
             << std::setw(20) << message 
             << std::setw(30) << result << std::endl << std::endl; // Including the result in the log


    // Write to action output file
    summaryFile << logEntry.str();
    summaryFile.close();

    // write to console
    std::cout << logEntry.str();
}



int main() {
    const char* outputFilename = "myStringLogFile.txt";
    const char* output2Filename = "myStringOutput.txt";
    myString methodName;
    myString origValue;
    myString modValue;
    myString parameters;
    myString msg;

    myString s1("Hello");
    myString s2("World");
    myString s3;

    // Test default constructor and print (should be nothing)
    myString s4;
    methodName.setString("Default Constructor");
    origValue = s4;
    parameters.setString("None");
    modValue = s4;
    msg.setString("Should be Null/Nothing");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());

    // Test C-style string constructor (should be "Hello")
    methodName.setString("C-style constructor");
    origValue = s1;
    parameters.setString("s1(\"Hello\")");
    modValue = s1;
    msg.setString("Should be \"Hello\"");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());

    // Test string constructor (Should be "CPP String")
    std::string cppString = "CPP String";
    myString s5(cppString);
    methodName.setString("String constructor");
    origValue = s5;
    parameters.setString("s5(cppString) -> \"CPP String\"");
    modValue = s5;
    msg.setString("Should be \"CPP String\"");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());

    // Test copy constructor (Should be "World")
    myString s6(s2);
    methodName.setString("Copy constructor");
    origValue = s2;
    parameters.setString("s6(s2) -> \"World\"");
    modValue = s6;
    msg.setString("Should be \"World\"");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());

    // Test addStart (Should be "HelloWorld")
    origValue = s2;
    s2.addStart(s1);
    methodName.setString("addStart");
    parameters.setString("s2.addStart(s1)");
    modValue = s2;
    msg.setString("Should be \"HelloWorld\"");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());

    // Test addEnd (Should be "HelloWorldHello")
    origValue = s2;
    s2.addEnd(s1);
    methodName.setString("addEnd");
    parameters.setString("s2.addEnd(s1)");
    modValue = s2;
    msg.setString("Should be \"HelloWorldHello\"");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());

    // Test partString (Should be "loWo")
    origValue = s2;
    myString s7 = s2.partString(4, 4);
    methodName.setString("partString");
    parameters.setString("s7 = s2.partString(4, 4)");
    modValue = s7;
    msg.setString("Should be \"loWo\"");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());

    // Test replPartString (Should be "lHelloo")
    origValue = s2;
    s7.replPartString(s1, 2, 2);
    methodName.setString("replPartString");
    parameters.setString("s7.replPartString(s1, 2, 2)");
    modValue = s7;
    msg.setString("Should be \"lHelloo\"");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());

    // Test replWholeString (Should be "Replacement")
    origValue = s7;
    myString s8("Replacement");
    s7.replWholeString(s8);
    methodName.setString("replWholeString");
    parameters.setString("s7.replPartString(s8)");
    modValue = s7;
    msg.setString("Should be \"Replacement\"");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());

    // Test setString (Should be "Reset String")
    origValue = s7;
    std::string newStr = "Reset String";
    s7.setString(newStr);
    methodName.setString("setString");
    parameters.setString("s7.setString(newStr)");
    modValue = s7;
    msg.setString("Should be \"Reset String\"");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());

    myString na("N/A");
    origValue = na;
    methodName.setString("compareString");

    // Test compareString
    myString sCompare1("Hello");
    myString sCompare2("Hello");
    myString sCompare3("Hello There");
    myString sCompare4("hello");
    myString sCompare5("Goodbye");
    int cmpResult1 = sCompare1.compareString(sCompare2); // Should be 0
    parameters.setString("Comparing Hello to Hello");
    modValue.setString(std::to_string(cmpResult1));
    msg.setString("Should be 0 (mod value)");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());
    int cmpResult2 = sCompare2.compareString(sCompare3); // Should be -6
    parameters.setString("Comparing Hello to Hello There");
    modValue.setString(std::to_string(cmpResult2));
    msg.setString("Should be -6 (mod value)");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());
    int cmpResult3 = sCompare2.compareString(sCompare4); // Should be 0
    parameters.setString("Comparing Hello to hello");
    modValue.setString(std::to_string(cmpResult3));
    msg.setString("Should be 0 (mod value)");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());
    int cmpResult4 = sCompare1.compareString(sCompare5); // Should be -1
    parameters.setString("Comparing Hello to Goodbye");
    modValue.setString(std::to_string(cmpResult4));
    msg.setString("Should be -1 (mod value)");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());

    myString boolResult("null");
    methodName.setString("numericString");
    // Test numericString
    myString numericStr1("123.45");
    myString numericStr2("-45");
    myString numericStr3("One");
    myString numericStr4("12.12.4");
    bool isNumeric1 = numericStr1.numericString(); // Should be true
    (isNumeric1) ? boolResult.setString("True") : boolResult.setString("False");
    parameters.setString("Is 123.45 Numeric");
    modValue = boolResult;
    msg.setString("Should be true");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());
    bool isNumeric2 = numericStr2.numericString(); // Should be true
    (isNumeric2) ? boolResult.setString("True") : boolResult.setString("False");
    parameters.setString("Is -45 Numeric");
    modValue = boolResult;
    msg.setString("Should be true");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());
    bool isNumeric3 = numericStr3.numericString(); // Should be false
    (isNumeric3) ? boolResult.setString("True") : boolResult.setString("False");
    parameters.setString("Is One Numeric");
    modValue = boolResult;
    msg.setString("Should be false");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());
    bool isNumeric4 = numericStr4.numericString(); // Should be false
    (isNumeric4) ? boolResult.setString("True") : boolResult.setString("False");
    parameters.setString("Is 12.12.4 Numeric");
    modValue = boolResult;
    msg.setString("Should be false");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());

    methodName.setString("alphabeticString");
    // Test alphabeticString
    bool isAlpha1 = s1.alphabeticString(); // Should be true
    (isAlpha1) ? boolResult.setString("True") : boolResult.setString("False");
    parameters.setString("Is Hello Alphabetic");
    modValue = boolResult;
    msg.setString("Should be true");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());
    bool isAlpha2 = s7.alphabeticString(); // Should be false (due to space)
    (isAlpha2) ? boolResult.setString("True") : boolResult.setString("False");
    parameters.setString("Is Reset String Alphabetic");
    modValue = boolResult;
    msg.setString("Should be false due to space");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());
    bool isAlpha3 = numericStr1.alphabeticString(); // Should be false
    (isAlpha3) ? boolResult.setString("True") : boolResult.setString("False");
    parameters.setString("Is 123.45 Alphabetic");
    modValue = boolResult;
    msg.setString("Should be false");
    logToFile(outputFilename, methodName.getString(), origValue.getString(), parameters.getString(), modValue.getString(), msg.getString());
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());

    // Error tests below
    // partString errors
    methodName.setString("partString");

    myString a1("There");
    msg.setString("Should be invalid start pos error");
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());
    myString a2(a1.partString(0, 3));

    msg.setString("Should be invalid length error");
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());
    a2 = a1.partString(1, 6);

    msg.setString("Should be invalid start pos error");
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());
    a2 = a1.partString(6, 1);

    msg.setString("Should be invalid length error");
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());
    a2 = a1.partString(1, 0);
    
    // replPartString errors
    methodName.setString("replPartString");

    a2.setString("Hi");
    
    msg.setString("Should be invalid start pos error");
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());
    a1.replPartString(a2, 6, 1);

    msg.setString("Should be invalid length error");
    actionOutput(output2Filename, methodName.getString(), msg.getString(), "Result: " + modValue.getString());
    a1.replPartString(a2, 1, -1);

    return 0;
}