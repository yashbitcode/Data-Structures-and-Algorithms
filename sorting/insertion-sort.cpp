#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& vec, bool decreasing = false) {
    for(int i = 1; i < vec.size(); i++) {
        int key = vec[i];
        int j = (i - 1);

        while(j >= 0 && ((decreasing && key < vec[j]) || (!decreasing && key > vec[j]))) {
            vec[j + 1] = vec[j];
            j--;
        }

        vec[j + 1] = key;
    }
}

int main() {
    vector<int> vec = {1, 31, 12, 54, 23, 12};
    insertionSort(vec, true);

    for(auto it: vec) {
        cout << it << ' ';
    }

    cout << endl;

    insertionSort(vec);

    for(auto it: vec) {
        cout << it << ' ';
    }
}