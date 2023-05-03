#include "dynamicArray.h"
#include <cassert>
#include <iostream>

void testDynamicArray()
{
    DynamicArray<int> arr;

    // Test push_back and getSize
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    assert(arr.getSize() == 3);

    // Test operator[]
    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr[2] == 3);

    // Test pop_back
    arr.pop_back();
    assert(arr.getSize() == 2);

    // Test insertAt
    arr.insertAt(1, 4);
    assert(arr.getSize() == 3);
    assert(arr[1] == 4);

    // Test deleteAt
    arr.deleteAt(1);
    assert(arr.getSize() == 2);
    assert(arr[1] == 2);

    std::cout << "All tests passed!" << std::endl;
}
