#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &vec, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;

    vector<int> temp;

    // 
    while (i <= mid && j <= high)
    {
        if (vec[i] <= vec[j])
            temp.push_back(vec[i++]);
        else
            temp.push_back(vec[j++]);
    }

    while (i <= mid)
    {
        temp.push_back(vec[i++]);
    }

    while (j <= high)
    {
        temp.push_back(vec[j++]);
    }

    // combined N

    for (int k = 0; k < temp.size(); k++) // N
    {
        vec[k + low] = temp[k];
    }
}

void mergeSort(vector<int> &vec, int low, int high) // logn -> levels
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    
    mergeSort(vec, low, mid);
    mergeSort(vec, mid + 1, high);

    merge(vec, low, mid, high); // for each level 'n' base processing
}

int main()
{
    vector<int> vec = {2, 10, 5, 4, 18, 15, 1};

    mergeSort(vec, 0, vec.size() - 1); // TC - nlogn, SC - n

    cout << endl;
    for (auto it : vec)
    {
        cout << it << " ";
    }
}