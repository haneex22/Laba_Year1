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
    forward_list<int> list = {-5, -12, 6, 3, -7, 0};
    
    for (auto iter = list.begin(); iter != list.end(); ++iter){
        if (*iter < 0){ 
            iter = list.emplace_after(iter, 10);}
    }
    print(list);
    return 0;
}
