#include <iostream>
#include <chrono>
#include "MyVector-proj5.h"
#include "Queue1-proj5.h"
#include "MyList-proj5.h"
#include "Queue3-proj5.h"

using namespace std;
using namespace std::chrono;

int main() {
    Queue1<int> q1;
    Queue3<int> q3;

    auto start = high_resolution_clock::now();
    for(int i = 0; i < 10000; i++) {
        q1.enqueue(i);
    }

    int derp;

    for(int i = 0; i < 10000; i++) {
        q1.dequeue(derp);
    }
    auto end = high_resolution_clock::now();

    cout << "Queue 1: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";

    start = high_resolution_clock::now();
    for(int i = 0; i < 10000; i++) {
        q3.enqueue(i);
    }

    for(int i = 0; i < 10000; i++) {
        q3.dequeue(derp);
    }
    end = high_resolution_clock::now();

    cout << "Queue 3: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";
    cout << endl;

    return 0;
}