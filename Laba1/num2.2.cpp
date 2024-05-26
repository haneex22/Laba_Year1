#include <iostream>
#include <string>
#include <queue>
using namespace std;

void enqueue(queue<double>& b, double x){
    b.push(x);}

void dequeue(queue<double>& b){
    b.pop();}

int main(){
    queue<double> ochered;
    enqueue(ochered, -2.1);
    enqueue(ochered, 1.3);
    enqueue(ochered, -1.34);
    enqueue(ochered, 3.3);
    queue<double> ochered2 = ochered;
    while(ochered2.empty() == 0){
        cout << ochered2.front() << " ";
        ochered2.pop();
    }
    cout << endl;
    dequeue(ochered);
    enqueue(ochered, 2.9);

    queue<double> ochered3 = ochered;
    while(ochered3.empty() == 0){
        cout << ochered3.front() << " ";
        ochered3.pop();
    }
    double x = 0;
    queue<double> ochered4 = ochered;
    while(ochered4.empty() == 0){
        if (ochered4.front() < 0){x+=ochered4.front();}
        ochered4.pop();    
    }
    cout << endl << x;
}
