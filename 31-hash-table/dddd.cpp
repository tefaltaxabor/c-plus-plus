#include <iostream>
#include <array>

using namespace std;

string s = "Hello World";
array<int, 255> contador{};

int main() {
    for (auto c : s) {
        contador[c]++;
    }

    for (char c = 'a'; c <= 'z'; c++) {
        cout << c << " " << contador[c] << endl;
    }

    cout << "===================" << endl;

    for (char c = 'A'; c <= 'Z'; c++) {
        cout << c << " " << contador[c] << endl;
    }

    return 0;
}


//-std=c++11 -stdlib=libc++