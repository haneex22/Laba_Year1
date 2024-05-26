#include <iostream>
#include <fstream>

using namespace std;
int main() {
    ifstream in("a.txt");
    int check = 0;
    double x = 0, j = 0;
    if (in.is_open()) {
        while (in >> j) {
            if (j == 0) check += 1;
            if (j < 0) x += j;
        }
    }
    cout << check << " " << x;
    return 0;
}