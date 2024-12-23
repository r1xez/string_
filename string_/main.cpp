#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

template <typename T>
class StringManipulator {
private:
    T str;

public:
    StringManipulator(const T& input) : str(input) {}

    void toUpperCase() {
        transform(str.begin(), str.end(), str.begin(), ::toupper);
    }

    void toLowerCase() {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
    }

    void reverse() {
        std::reverse(str.begin(), str.end());
    }

    void concatenate(const T& other) {
        str += other;
    }

    T get() const {
        return str;
    }
};

template <>
class StringManipulator<int> {
private:
    string str;

public:
    StringManipulator(int input) {
        ostringstream oss;
        oss << input;
        str = oss.str();
    }

    void toUpperCase() {
        transform(str.begin(), str.end(), str.begin(), ::toupper);
    }

    void toLowerCase() {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
    }

    void reverse() {
        std::reverse(str.begin(), str.end());
    }

    void concatenate(const string& other) {
        str += other;
    }

    string get() const {
        return str;
    }
};

int main() {
    StringManipulator<string> stringManipulator("Hello, World!");

    cout << "Original: " << stringManipulator.get() << endl;

    stringManipulator.toUpperCase();
    cout << "Uppercase: " << stringManipulator.get() << endl;

    stringManipulator.toLowerCase();
    cout << "Lowercase: " << stringManipulator.get() << endl;

    stringManipulator.reverse();
    cout << "Reversed: " << stringManipulator.get() << endl;

    stringManipulator.concatenate(" How are you?");
    cout << "Concatenated: " << stringManipulator.get() << endl;

    StringManipulator<int> intManipulator(12345);
    cout << "Original integer string: " << intManipulator.get() << endl;

    intManipulator.reverse();
    cout << "Reversed integer string: " << intManipulator.get() << endl;

    intManipulator.concatenate("67890");
    cout << "Concatenated integer string: " << intManipulator.get() << endl;

    return 0;
}
