Alternating Sum Generator
Overview

A C++ console application that alternately inserts user-provided integers into two internal sequences and computes pairwise sums sequentially.

The system maintains internal state and caches computed results to prevent redundant calculations. It also performs overflow-safe arithmetic and strict input validation.

Behavior

• Integers are inserted alternately:

  • 1st → arr1

  • 2nd → arr2

  • 3rd → arr1

  • 4th → arr2

  • and so on

• Enter + to compute the next pairwise sum.

  • Previously computed sums are returned from cache.

  • If no complete pair exists, a message is displayed.

• Enter q to terminate the program.

Internal Design

• std::vector<long long> used for storage

• Cached sum tracking to avoid recomputation

• Checked arithmetic to prevent signed integer overflow

• Strict numeric parsing using std::stoll

• Clear separation between computation logic and I/O

## Accepted Inputs

| Input                         | Action                          |
|--------------------------------|---------------------------------|
| Integer (e.g., 5, -3, 100)     | Inserted alternately            |
| `+`                            | Compute next pairwise sum       |
| `q`                            | Exit program                    |

All other inputs are rejected.


Edge Cases Handled

• Invalid or malformed numeric input (e.g., abc, 1a)

• Out-of-range values for 64-bit integers

• Negative and multi-digit numbers

• Repeated + after all valid pairs are computed

• Signed integer overflow during addition

• Repeated sum requests served from cache
