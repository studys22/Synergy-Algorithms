#include <iostream>
#include <memory>
using namespace std;

int main() {
    unique_ptr<int> ptr (new int (5));
    cout << *ptr << endl;
    *ptr = 10;
    cout << *ptr << endl;
}
