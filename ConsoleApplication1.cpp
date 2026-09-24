#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int find(int value, int arr[], int size) {
    int index=-1;
    for (int i = 0; i < size; i++) {
        
        if (arr[i] == value)
            index = i;
    }
    if (index == -1)
        return -1;
    if (index != 0) {
        swap(arr[index], arr[index - 1]);
        index--;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i];
    }
    return index;
}
int main() {
    int m[] = { 1,2,3,4,5};
    int size = 5;
    find(7, m, size);
   
        return 0;
    
}
