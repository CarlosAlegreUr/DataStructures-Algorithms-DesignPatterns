#include "set.h"
#include "testSet.h"
#include <cassert>

void test_insert_and_contains() {
    Set set;
    assert(set.insert(1) == true);
    assert(set.contains(1) == true);
    assert(set.insert(1) == false);
    assert(set.contains(1) == true);
}

void test_remove() {
    Set set;
    assert(set.insert(1) == true);
    assert(set.remove(1) == true);
    assert(set.contains(1) == false);
    assert(set.remove(1) == false);
}

void test_size() {
    Set set;
    assert(set.size() == 0);
    assert(set.insert(1) == true);
    assert(set.size() == 1);
    assert(set.insert(2) == true);
    assert(set.size() == 2);
    assert(set.remove(1) == true);
    assert(set.size() == 1);
}

void run_tests() {
    test_insert_and_contains();
    test_remove();
    test_size();
}
