#include "IString.h"
using namespace std;

String::String(){

} 

string String::PadStart(string value, int length, char padChar) {
    if (value.length() >= length) {
        return value;
    }

    string paddedString(length - value.length(), padChar);
    paddedString += value;

    return paddedString;
}


string String::PadStart(int valueInt, int length, char padChar) {
    string value = to_string(valueInt);

    if (value.length() >= length) {
        return value;
    }

    string paddedString(length - value.length(), padChar);
    paddedString += value;

    return paddedString;
}

