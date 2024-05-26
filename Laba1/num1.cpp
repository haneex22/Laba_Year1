#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> numbers;
    numbers.push(5);
    numbers.push(-5);
    numbers.push(13);
    numbers.push(2);
    numbers.push(-6);
    numbers.push(1);

    queue<int> numbers2 = numbers;
    queue<int> numbers3 = numbers; 
    int positivenum = 0;
    for (int i = 0; i < (int)numbers.size(); ++i){
        if (numbers2.front() > 0) {positivenum++;}
            numbers2.pop();
    }
    for (int i = 0; i < (int)numbers.size(); ++i){
        cout << numbers3.front() << " ";
        numbers3.pop(); 
    }
    cout << endl << positivenum;
    return 0;
}
