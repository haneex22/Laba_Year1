#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream in("a.txt");
    int check = -1;
    int sum = 0, counter = 0, j;
    if (in.is_open()){
        ++check;
        while (in >> j){
            if (check % 2 == 0 && j > 0){
                counter++;
                sum += j;
            }
        }
    }
    cout << sum / counter;
    return 0;
}
