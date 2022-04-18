#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int>::size_type size;

    vector<int> arr1; //usual dynamic allocation
    size = arr1.capacity();
    cout << "arr1 growing with usual dynamic allocation:\n";
    for (int i = 0; i < 50; ++i) {
        arr1.push_back(i);
        if (size != arr1.capacity()) {
            size = arr1.capacity();
            cout << "capacity changed to:" << size << '\n';
        }
    }

    vector<int> arr2; //using reserve
    size = arr2.capacity();
    arr2.reserve(50); // use of reserve function
    cout << "arr2 growing with using reverse:\n";
    for (int i = 0; i < 50; ++i) {
        arr2.push_back(i);
        if (size != arr2.capacity()) {
            size = arr2.capacity();
            cout << "capacity changed to:" << size << '\n';
        }
    }

    return 0;
}
