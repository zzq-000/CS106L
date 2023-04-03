#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
const int NUM_INTS = 10;
using namespace std;
int main()
{

    // vector<int> myVector(NUM_INTS);
    // generate(myVector.begin(), myVector.end(), rand);
    // sort(myVector.begin(), myVector.end());
    // copy(myVector.begin(), myVector.end(), ostream_iterator<int>(cout, "\n"));

    ifstream input("./test.txt");
    copy(istreambuf_iterator<char>(input), istreambuf_iterator<char>(),
              ostreambuf_iterator<char>(cout));
    vector<int> v(15, 999);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));
    v.resize(20, 80);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));
    return 0;
}