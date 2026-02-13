Alternating Sum Generator
Overview

This is a C++ console-based program that manages two dynamic arrays using alternating insertion.
The program computes pairwise sums of elements from both arrays sequentially when requested.

The system maintains internal state and caches previously computed sums to avoid recomputation.

How It Works

Numbers entered by the user are inserted alternately:

First number → arr1

Second number → arr2

Third number → arr1

Fourth number → arr2

and so on

When the user enters +:

The program computes the next pairwise sum.

If the sum was already computed earlier, the cached result is returned.

If no further pairs are available, an error is displayed.

The program continues running until the user enters q.

Internally, the program uses:

Three std::vector<int> containers (arr1, arr2, sums)

A boolean flag to alternate insertion

An index pointer to track sum progression

Exception handling (std::stoi) for input validation

Accepted Inputs
Input	Description
Integer (e.g., 5, -3, 100)	Inserted alternately into arrays
+	Computes next pairwise sum
q	Terminates the program

All other inputs result in an error message.

Edge Cases Handled

1.Invalid Input
Non-integer strings (e.g., abc, @, 1a) are rejected.

2.Negative Numbers
Supported and inserted normally.

3.Multi-digit Numbers
Fully supported.

4.Repeated + After Completion
If all possible sums have been computed, the program prints: Error: Array size exceeded

5.Cached Results
If + is pressed multiple times for already computed indices, the program reuses stored results instead of recalculating.
