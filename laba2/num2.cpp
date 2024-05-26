#include <iostream>
#include <fstream>

using namespace std;
int main() {
    ifstream in("a.txt");
    ofstream out("a2.txt");
    double check = 0;
    if (in.is_open()) {
        while (in >> check) {
            if (check != 0) out << check / 5 << " ";
        }
    }
    in.close();
    out.close();
    ifstream in2("a2.txt");
    double check2 = 0;
    while (in2 >> check2) {
    cout << check2 << " ";
    }
    return 0;
}