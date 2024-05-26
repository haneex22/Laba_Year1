#include <iostream>
#include <string>
#include <queue>
using namespace std;

void enqueue(queue<string>& b, string x){
    b.push(x);}

void dequeue(queue<string>& b){
    b.pop();}

int main(){
    queue<string> ochered;
    enqueue(ochered, "one");
    enqueue(ochered, "two");
    enqueue(ochered, "three");
    enqueue(ochered, "four");
    queue<string> ochered2 = ochered;
    while(ochered2.empty() == 0){
        cout << ochered2.front() << " ";
        ochered2.pop();
    }
    cout << endl;
    dequeue(ochered);
    enqueue(ochered, "five");

    queue<string> ochered3 = ochered;
    while(ochered3.empty() == 0){
        cout << ochered3.front() << " ";
        ochered3.pop();
    }
    int x = 0;
    queue<string> ochered4 = ochered;
    while(ochered4.empty() == 0){
        x += (ochered4.front()).length();
        ochered4.pop();
    }
    cout << endl << x;
}
