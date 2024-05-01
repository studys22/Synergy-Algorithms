#include <iostream>
#include <list>
using namespace std;

int main() {
    int val, n = 5;
    list<int> l;
    cout << "Элементов к вводу: " << n << "\nВводите: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        l.push_back(val);
    }
    int valueToRemove;
    cout << "Введите значение для удаления: ";
    cin >> valueToRemove;
    l.remove(valueToRemove);
    for (int val : l) {
        cout << val << ' ';
    }
    cout << endl;
}
