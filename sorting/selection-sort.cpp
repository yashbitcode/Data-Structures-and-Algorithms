#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& vec, bool decreasing = false) {
    for(int i = 0; i < vec.size(); i++) {
        int track = i;

        for(int j = (i + 1); j < vec.size(); j++) {
            if(!decreasing && vec[j] > vec[track]) track = j;
            else if(decreasing && vec[j] < vec[track]) track = j;
        }

        swap(vec[i], vec[track]);
    }
}

int main() {
    vector<int> vec = {5, 3, 2, 1};
    selectionSort(vec);

    for(auto it: vec) {
        cout << it << ' ';
    }
}