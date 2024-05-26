#include <iostream>
#include <forward_list>
using namespace std;
void print(forward_list<int> x){
    while(x.empty() == 0){
        auto iter = x.begin();
        cout << *iter << " ";
        iter++;
        x.pop_front();
    }
}

int main(){
    forward_list<int> list = {1, 5, -2, 6, 78, -2, 16, 19, -2};
    auto iter1 = list.begin();
    auto iter2 = list.begin();
    iter1++;
    iter1++;
    for (iter1; iter1 != list.end(); ++iter1){
        if (*iter1 == -2){  
            iter1 = list.erase_after(iter2);}
        else iter2++;
    }
    auto iter = list.begin();
    for (auto iterd = list.begin(); iterd != list.end(); ++iterd) {
        iter = iterd;
    }
    list.insert_after(iter, 33);
    print(list);
    return 0;
}
