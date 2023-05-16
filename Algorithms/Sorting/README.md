# Sorting Algorithms

## Algorithm Time Complexities

| Algorithm        | Best Time Complexity | Average Time Complexity | Worst Time Complexity |
|------------------|----------------------|-------------------------|-----------------------|
| Counting Sort    | O(n + k)            | O(n + k)               | O(n + k)             |
| Heap Sort        | O(n log n)          | O(n log n)             | O(n log n)           |
| Insertion Sort   | O(n)                | O(n^2)                 | O(n^2)               |
| Merge Sort       | O(n log n)          | O(n log n)             | O(n log n)           |
| Quick Sort       | O(n log n)          | O(n log n)             | O(n^2)               |
| Radix Sort       | O(nk)               | O(nk)                  | O(nk)                |
| Selection Sort   | O(n^2)              | O(n^2)                 | O(n^2)               |

## Algorithm Space Complexities

| Algorithm        | Space Complexity |
|------------------|------------------|
| Counting Sort    | O(n + k)        |
| Heap Sort        | O(1)            |
| Insertion Sort   | O(1)            |
| Merge Sort       | O(n)            |
| Quick Sort       | O(log n)        |
| Radix Sort       | O(n + k)        |
| Selection Sort   | O(1)            |

## Brief Description of Each Algorithm

1. **Counting Sort** is an integer sorting algorithm that works by counting the number of objects that have each distinct key value. It is efficient when the range of input data (k) is not significantly greater than the number of objects to be sorted (n).

2. **Heap Sort** is a comparison-based sorting algorithm that uses a binary heap data structure. It works by first building a max heap and then swapping the first and last element, and heapifying the rest.

3. **Insertion Sort** is a simple sorting algorithm that builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.

4. **Merge Sort** is an efficient, stable, comparison-based sorting algorithm. It works on the principle of Divide and Conquer. Merge sort first divides the array into equal halves and then combines them in a sorted manner.

5. **Quick Sort** is a comparison sort, meaning that it can sort items of any type for which a "less-than" relation is defined. It is efficient for large-sized data sets as its average and worst-case complexity are O(n log n).

6. **Radix Sort** is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping keys by the individual digits which share the same significant position and value.

7. **Selection Sort** is a simple comparison-based algorithm, which improves on the bubble sort by making only one exchange for every pass through the list. It looks for the largest value as it makes a pass and, after completing the pass, places it in the proper location.
