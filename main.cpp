#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int fast_arrays_unique_amount(vector<int> a, vector<int> b) {
    int amount = 0;

    if (a.size() > b.size()) {
        swap(a, b);
    }

    unordered_set<int> set;

    amount += a.size();

    for (int i : a) {
        set.insert(i);
    }

    for (int i : b) {
        if (set.count(i) == 0) {
            amount++;
        }
    }

    return amount;
}

bool test1() {
    vector<int> a = {1, 2, 3, 4};
    vector<int> b = {5, 6, 7};
    return fast_arrays_unique_amount(a, b) == 7;
}

bool test2() {
    vector<int> a = {1, 2, 3, 4};
    vector<int> b = {1, 2, 3, 4, 5, 6, 7};
    return fast_arrays_unique_amount(a, b) == 7;
}

bool test3() {
    vector<int> a = {};
    vector<int> b = {5, 6, 7};
    return fast_arrays_unique_amount(a, b) == 3;
}

bool test4() {
    vector<int> a;
    vector<int> b;

    for (int i = 0; i < 10000; i++) {
        a.push_back(-i - 1);
    }

    for (int i = 0; i < 10000; i++) {
        b.push_back(i);
    }

    return fast_arrays_unique_amount(a, b) == 20000;
}

bool test5() {
    vector<int> a;
    vector<int> b;

    for (int i = 0; i < 100000; i++) {
        a.push_back(i + 1);
    }

    for (int i = 0; i < 100000; i++) {
        b.push_back(i);
    }

    return fast_arrays_unique_amount(a, b) == 100001;
}

bool test6() {
    vector<int> a;
    vector<int> b;

    for (int i = 0; i < 1000000; i++) {
        a.push_back(i * 10);
    }

    for (int i = 0; i < 1000000; i++) {
        b.push_back(i);
    }

    return fast_arrays_unique_amount(a, b) == 1900000;
}

int main() {
    vector<bool> tests = {test1(), test2(), test3(), test4(), test5(), test6()};

    for (int i = 0; i < tests.size(); i++) {
        cout << "test" << i + 1;
        if (tests[i]) {
            cout << " passed";
        } else {
            cout << " failed";
        }
        cout << endl;
    }

    return 0;
}