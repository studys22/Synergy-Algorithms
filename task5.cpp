#include <iostream>
#include <memory>
using namespace std;


template <typename T>
class elem {
public:
    shared_ptr<elem<T> > next;
    T val;

    elem() {
        this->next = nullptr;
        this->val = 0;
    }

    elem(T val) {
        this->next = nullptr;
        this->val = val;
    }
};

template <typename T>
class spisok {
public:
    spisok() {
        this->head = nullptr;
        this->last = nullptr;
    }

    void add(T val) {
        shared_ptr<elem<T> > new_last;
        new_last = make_shared<elem<T> >(val);
        if (head == nullptr) {
            head = new_last;
        }
        else {
            last->next = new_last;
        }
        last = new_last;
    }

    void print() {
        bool first = true;
        for (auto t = head; t != nullptr; t = t->next) {
            if (!first) {
                cout << ' ';
            }
            else {
                first = false;
            }
            cout << t->val;
        }
        cout << endl;
    }

    void sort() {
        shared_ptr<elem<T> > cur = head->next;
        shared_ptr<elem<T> > prev_cur = head;
        while (cur != nullptr) {
            T val = cur->val;
            shared_ptr<elem<T> > t = head;
            shared_ptr<elem<T> > prev = nullptr;
            while (t->val < val && t != cur) {
                prev = t;
                t = t->next;
            }
            if (t == cur) {
                prev_cur = cur;
                cur = cur->next;
                continue;
            }
            if (prev == nullptr) {
                head = cur;
            }
            else {
                prev->next = cur;
            }
            prev_cur->next = cur->next;
            cur->next = t;

            cur = prev_cur->next;
        }
    }

private:
    shared_ptr<elem<T> > head, last;
};

int main() {
    int n;
    cin >> n;
    spisok<int> sp;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        sp.add(t);
    }
    sp.sort();
    sp.print();
}