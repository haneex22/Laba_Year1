#include <iostream>
#include <list>
using namespace std;

void print(list<int> x){
    while(x.empty() == 0){
        auto iter = x.begin();
        cout << *iter << " ";
        iter++;
        x.pop_front();
    }
}

int main(){
    list<int> list1 = {5, 6, 12, 95, 26, 110, -23, -520, 10, -77};
    list<int> chetn;

    int *p {&list1.front()};
    for (auto iter = list1.begin(); iter != list1.end(); ++iter){
        if (*iter % 2 == 0){
            chetn.push_back(*iter);
        }
    }
    int *p1 {&chetn.front()};
    if (chetn.empty()){ 
        cout << "nil" << endl;}
    else print(chetn);
    return 0;
}
