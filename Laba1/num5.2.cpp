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
    list<int> list1 = {-2, 5, 10, -10, 15, 9, -23, 4, 95};
    list<int> positive;
    for (auto iter = list1.begin(); iter != list1.end(); ++iter){
        if (*iter >= 0) {positive.push_back(*iter);}
    }
    for (auto iter = positive.begin(); iter != positive.end(); ++iter){
        positive.emplace(iter, 25);
    }
    print(positive);
}
