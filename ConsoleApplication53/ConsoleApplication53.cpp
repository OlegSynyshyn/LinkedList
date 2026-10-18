// ConsoleApplication53.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class List {
    int data[100];
    int next[100];
    int head = -1;
    int count = 0;






public:
    void insert(int pos, int x) {
        if (pos < 0 || pos > count || count == 100)
            return;

        int n = count++;
        data[n] = x;

        if (pos == 0) {
            next[n] = head;
            head = n;
        }
        else {
            int p = head;

            for (int i = 0; i < pos - 1; i++)
                p = next[p];

            next[n] = next[p];
            next[p] = n;
        }
    }

    void remove(int pos) {
        if (pos < 0 || pos >= count)
            return;

        if (pos == 0)
            head = next[head];
        else {
            int p = head;

            for (int i = 0; i < pos - 1; i++)
                p = next[p];

            next[p] = next[next[p]];
        }
    }



    int& operator[](int pos) {
        int p = head;

        for (int i = 0; i < pos; i++)
            p = next[p];

        return data[p];
    }

    friend ostream& operator<<(ostream& out, List& a) {
        int p = a.head;

        while (p != -1) {
            out << a.data[p] << " ";
            p = a.next[p];
        }

        return out;
    }
};

int main() {
    List a;

    a.insert(0, 5);


    a.insert(1, 15);
    a.insert(2, 25);

    cout << a << endl;

    a.remove(1);
    cout << a << endl;

    cout << a[1] << endl;

    return 0;
}