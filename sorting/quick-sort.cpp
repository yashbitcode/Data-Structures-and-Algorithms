#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& vec, int low, int high, bool decreasing = false) {
    int pivot = vec[low];
    int i = low + 1;
    int j = high;

    while(i <= j) {
        while(i <=j && ((!decreasing && vec[i] <= pivot) || (decreasing && vec[i] >= pivot))) i++;
        while(i <=j && ((!decreasing && vec[j] > pivot) || (decreasing && vec[j] < pivot))) j--;

        if(i <= j) swap(vec[i++], vec[j--]);
    }

    swap(vec[j], vec[low]);

    return j;
}

void quickSort(vector<int>& vec, int low, int high, bool decreasing = false) {
    if(low >= high) return;

    int part = partition(vec, low, high, decreasing);
    quickSort(vec, low, part - 1, decreasing);
    quickSort(vec, part + 1, high, decreasing);
}

int main() {
    vector<int> vec = {7, 6, 5, 4, 3, 2, 1};
    // vector<int> vec = {2, 1, 5, 4, 18, 15, 10};

    for(auto it: vec) {
        cout << it << ' ';
    }

    cout << endl;

    quickSort(vec, 0, vec.size() - 1, false);
    
    for(auto it: vec) {
        cout << it << ' ';
    }

    cout << endl;
}