#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

string GetLine() {
    string result;
    getline(cin, result);
    return result;
}

int GetInteger() {
        while(true) { // Read input until user enters valid data
            stringstream converter;
            converter << GetLine();
            /* Try reading an int, continue if we succeeded. */
            int result;
            if(converter >> result) {
                char remaining;
                if(converter >> remaining) // Something's left, input is invalid
                    cout << "Unexpected character: " << remaining << endl;
                else
                    return result;
            } else
                cout << "Please enter an integer." << endl;
            cout << "Retry: ";
        }
}



/*error*/
bool HasHexLetters(int v) {
    stringstream s;
    s << hex << v;
    cout << s.str() << endl;
    int data;
    s >> dec >> data;
    cout << data << endl;
    /*这个只能判断开头的字符是否是十六进制
    读完这个还需要接着尝试往stringstream后面读
    如果读不到，说明整个十六进制里面都没有字母，否则在中间或者末尾有可能有字母*/
    if (s.fail()) return true;
    char ch;
    s >> ch;
    return !s.fail();
}

void DrawTriangle(int height, char ch) {
    for (int i = 0; i < height; ++i) {
        string data(2 * i + 1, ch);
        cout << setw(i + height) << data << endl;
    }
}
int main(int argc, char* argv[]) {
    cout << "[" << left << setw(20) << "hello, world!" << "]" << endl;
    cout << "[" << right << setw(20) << "hello, world!" << "]" << endl;
    
    int intValue = GetInteger();
    // cout << hex << intValue << endl;
    cout << boolalpha << HasHexLetters(intValue) << endl;
    // stringstream s;
    // s << hex << intValue;
    DrawTriangle(5, '%');
    // cout << s.str() << endl;
    return 0;
}