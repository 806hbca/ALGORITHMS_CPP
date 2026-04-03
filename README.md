# Algorithms and Data Structures — Visual Studio Solution

Collection of C++ implementations of classic algorithms and data structures. Each project is a separate Visual Studio console application.

---

## Search Algorithms

### Lab 01 — Linear Search (`lab_01_linear_search`)
Sequential scan through an array comparing each element with a key. Returns `1` (found) or `0` (not found) and the iteration count. Reads input from `inp.txt`.

### Lab 02 — Binary Search (`lab_02_binary_search`)
First sorts the array with merge sort, then uses binary search on the sorted result. Reports the position of the found element and the number of comparisons. Reads from `inp.txt`.

### Lab 03 — Interpolation Search (`lab_03_interpolation_search`)
Search for sorted non-uniformly distributed arrays. Uses the linear interpolation formula to estimate the probable position of the key, reducing comparisons compared to binary search. Reads from `inp.txt`.

---

## Sorting Algorithms (Internal)

### Lab 04 — Counting Sort (`lab_04_counting_sort`)
Finds min/max of the array, allocates a count array for each value in the range, then reconstructs the sorted sequence. Works for integer arrays with a bounded range.

### Lab 05 — Merge Sort (`lab_05_merge_sort`)
Classic recursive merge sort. Prints intermediate array state after each merge step for visualization. Reads from `inp.txt`.

### Lab 06 — Quick Sort (`lab_06_quick_sort`)
Quicksort using the middle element as pivot and a two-pointer partition. Prints the array after each partition step. Reads from `inp.txt`.

### Lab 07 — Quick Sort (Hoare / Lomuto) (`lab_07_quick_sort_hoar`)
Quicksort with Lomuto partition scheme using the last element as pivot. The `posit()` function partitions in-place and returns the pivot's final index. Hardcoded test array `{9,3,7,1,5,8,2,6,4,0}`.

### Lab 08 — Shell Sort (`lab_08_shell_sort`)
Shell sort with gap sequence `h = n/2`, halved each pass. Includes a version with step-by-step printing and a vector-based version. Hardcoded test array.

### Lab 09 — Bucket Sort (`lab_09_bucket_sort`)
Groups numbers into buckets by digit count (using `log10`), sorts each bucket with selection sort, then merges all buckets into the final array. Reads from `inp.txt`.

---

## Sorting Algorithms (External)

### Lab 10 — External Sort (`lab_10_external_sort`)
External merge sort for data that does not fit in memory. Implements three strategies:
- **Natural merge** (`marge`) — merges naturally ordered runs from two files.
- **Balanced merge** (`marge_mod`) — splits into two temporary files, merges back.
- **Fibonacci polyphase sort** (`strange_sort`) — distributes runs following Fibonacci proportions across multiple tapes for fewer merge passes.

Reads from `inp.txt` / `inp_N.txt`.

---

## String Matching Algorithms

### Lab 11 — Z-Algorithm (`lab_11_z_algorithm`)
Builds the Z-array for the combined string `pattern + "$" + text`. Each `Z[i]` gives the length of the longest substring starting at `i` that matches a prefix of the combined string. Prints all match positions. Hardcoded pattern `"aba"` in text `"abaorpaba"`.

### Lab 12 — Knuth-Morris-Pratt (`lab_12_kmp`)
KMP pattern matching. Precomputes the failure function (prefix table) for the pattern, then scans the text in a single pass, never backtracking. Counts non-overlapping occurrences. Hardcoded pattern `"abcabca"`.

### Lab 13 — Boyer-Moore (`lab_13_boyer_moore`)
Boyer-Moore string search. Builds a bad-character shift table from the reversed pattern, then slides the pattern right-to-left, skipping sections using the table. Hardcoded pattern `"aababa"` in text `"waababaababafh"`.

---

## Data Structures

### Lab 14 — Singly Linked List (`lab_14_linked_list`)
Linked list with `Node` (data + next pointer) and `List` (head/tail) structs. Implements `push_back()` for appending elements and traversal for printing.

### Lab 15 — Stack (`lab_15_stack`)
Array-based stack with `push()`, `pop()`, `print()`, and overflow detection. Constructor accepts capacity. Reads initial elements from `inp.txt`, pops twice, then pushes a new value.

### Lab 16 — Queue (`lab_16_queue`)
Queue (FIFO) built on a linked list. Implements `put()` (enqueue), `get()` (dequeue), `remove(int)` to delete all nodes with a given value, and `print()`. Tests with values `1,2,3,3,3,4,3,5` and removes all `3`s.

---

## Excluded from repository (.gitignore)

| Folder | Reason |
|--------|--------|
| `ConsoleApplication49/` | Incomplete — external sort stub with a buggy print helper |
| `Hash_table/` | Empty — only VS template "Hello World" |
| `MegaOutsidesort/` | Empty — variable declarations with no sorting logic |
| `bloch/` | Empty — only VS template "Hello World" |
| `x64/`, `Debug/`, `Release/` | Build artifacts |
