#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct mountain{
    string name;
    int height;
};

int main(){
    string name;
    int height;
    stack<mountain> gory; 
    gory.push({"Everest", 8848});
    gory.push({"Elbrus", 5642});
    gory.push({"Kazbek", 5032});
    cout << "Введите название горы и высоту: ";
    cin >> name >> height;
    gory.push({name, height});
    stack<mountain> gory2 = gory; 
    while (gory2.empty() == 0) {
        mountain info = gory2.top();
        cout << info.name << " " << info.height << endl;
        gory2.pop();}
    stack<mountain> gory3 = gory;
    double x = 0;
    double g = 0;
    while (gory3.empty() == 0) {
        mountain info2 = gory3.top();
        x += info2.height;
        g++;
        gory3.pop();
    }
    cout << x/g;
    return 0;
}
