#include <iostream>
#include "./utils/common.h"

void swap(int &i, int &j) {
    int temp = i;
    i = j;
    j = temp;
}

int main() {

    vector<int> maxHeap{1,3,4,5};
    swap(maxHeap[0], maxHeap[1]);
    std::cout << maxHeap[0] << "," << maxHeap[1] << std::endl;
    return 0;
}

