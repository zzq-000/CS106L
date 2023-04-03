#include <iostream>
#include <string>
#include <sstream>


using namespace std;
string GetAboutInformation() {
        stringstream result;
        result << "This program was compiled on " << __DATE__;
        result << " at time " << __TIME__;
        return result.str();
}

int main() {
    cout << GetAboutInformation() << endl;
    return 0;
}