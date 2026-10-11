#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& vec, bool decreasing = false) {
    for(int i = 0; i < vec.size(); i++) {
        bool swapped = false;

        for(int j = 1; j < (vec.size() - i); j++) {
            if(!decreasing && vec[j] > vec[j - 1]) {
                swap(vec[j], vec[j - 1]);
                swapped = true;
            } else if(decreasing && vec[j] < vec[j - 1]) {
                swap(vec[j], vec[j - 1]);
                swapped = true;
            }

            if(!swapped) break;
        }
    }
}

int main() {
    vector<int> vec = {1, 10, 30, 20, 40};
    bubbleSort(vec, false);

    for(auto it: vec) {
        cout << it << ' ';
    }
}