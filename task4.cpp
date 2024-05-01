#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int n = 10, val;
mutex mt;

void print(bool odd) {
    while (true) {
        if (val >= n) break;
        if (val % 2 == odd) continue;
        mt.lock();
        val++;
        cout << val << ' ';
        mt.unlock();
    }
}

int main() {
    val = 0;
    thread t1(print, true);
    thread t2(print, false);  
    t1.join();
    t2.join();
    cout << endl;
}