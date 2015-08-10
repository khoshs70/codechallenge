#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;



#define LEFT(x)	((x << 1) + 1)
#define RIGHT(x) ((x + 1) << 1)
#define PARENT(x) (((x + 1) >> 1) - 1)

void MaxHeapify(int Ary[], int nIndex, int nHeapSize)
{
    int nL = LEFT(nIndex);
    int nR = RIGHT(nIndex);
    int nLargest;

    if (nL <= nHeapSize && Ary[nIndex] < Ary[nL])
    {
        nLargest = nL;
    }
    else
    {
        nLargest = nIndex;
    }

    if (nR <= nHeapSize && Ary[nLargest] < Ary[nR])
    {
        nLargest = nR;
    }

    if (nLargest != nIndex)
    {
        // 调整后可能仍然违反堆性质
        swap(Ary[nLargest], Ary[nIndex]);
        MaxHeapify(Ary, nLargest, nHeapSize);
    }
}

void BuildMaxHeap(int Ary[], int nHeapSize)
{
    for (int i = PARENT(nHeapSize); i >= 0; --i)
    {
        MaxHeapify(Ary, i, nHeapSize);
    }
}

void HeapSort(int Ary[], int nCount)
{
    int nHeapSize = nCount - 1;
    BuildMaxHeap(Ary, nHeapSize);

    for (int i = nHeapSize; i >= 1; --i)
    {
        swap(Ary[0], Ary[i]);
        --nHeapSize;
        MaxHeapify(Ary, 0, nHeapSize);
    }
}

// merge sort

void stlheap() {
    int arr[] = { 5,6,9};
    std::vector<int> v1(arr, arr + 3);
    std::make_heap(v1.begin(), v1.end());

    int myints[] = { 10, 20, 30, 5, 15 };
    std::vector<int> v(myints, myints + 5);

    std::make_heap(v.begin(), v.end());
    std::cout << "initial max heap   : " << v.front() << '\n';

    std::pop_heap(v.begin(), v.end());
    v.pop_back();
    std::cout << "max heap after pop : " << v.front() << '\n';

    v.push_back(99); std::push_heap(v.begin(), v.end());
    std::cout << "max heap after push: " << v.front() << '\n';

    std::sort_heap(v.begin(), v.end());

    std::cout << "final sorted range :";
    for (unsigned i = 0; i<v.size(); i++)
        std::cout << ' ' << v[i];

    std::cout << '\n';

}

void sortstudy() {
    //stlheap();
    int arr[] = { 5, 6, 9, 11,4,8,10 };
    //BuildMaxHeap(arr, 2);
    HeapSort(arr,7);
}