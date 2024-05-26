#include <iostream>
#include <deque>
using namespace std;
void perehod(deque<int>& b1, deque<int>& b2) {
    while (b1.empty() == 0) {
        b2.push_back(b1.front());
        b1.pop_front();
    }
}
void print(deque<int>& b1){
    while (b1.empty() == 0) {
        cout << b1.front() << " ";
        b1.pop_front();
    }
}
int main(){
    deque<int> ochered1 = {26, 95, 63, 18};
    deque<int> ochered2 = {1, 2, 3, 4};

    auto p1 = ochered1.begin();
    auto p2 = ochered1.end();
    auto p3 = ochered2.begin();
    auto p4 = ochered2.end();

    perehod(ochered1, ochered2);
    print(ochered2);
    cout << &p3 << " " << &p4 << endl;
    return 0;
}
