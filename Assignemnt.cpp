#include <iostream>
#include <vector>
#include <string>
#include <optional>
#include <limits>
#include <stdexcept>

// Manages alternating insertions into two sequences
// and provides cached pairwise sum computation.
class AlternatingSum {
private:
    std::vector<long long> arr1;
    std::vector<long long> arr2;
    std::vector<long long> sums;   // Cache of computed pair sums

    std::size_t currentIndex = 0;  // Tracks next pair to compute
    bool insertInFirst = true;     // Controls alternating insertion

    // Performs checked addition to prevent signed overflow.
    long long safeAdd(long long a, long long b) const {
        if ((b > 0 && a > std::numeric_limits<long long>::max() - b) ||
            (b < 0 && a < std::numeric_limits<long long>::min() - b)) {
            throw std::overflow_error("Integer overflow during addition");
        }
        return a + b;
    }

public:
    // Inserts values alternately into arr1 and arr2.
    void insert(long long val) {
        if (insertInFirst) {
            arr1.push_back(val);
        } else {
            arr2.push_back(val);
        }
        insertInFirst = !insertInFirst;
    }

    // Checks whether a new pair is available for computation.
    bool hasNextPair() const {
        return currentIndex < arr1.size() &&
               currentIndex < arr2.size();
    }

    // Returns next pairwise sum (cached if previously computed).
    std::optional<long long> computeNextSum() {
        // Reuse cached result if already computed.
        if (currentIndex < sums.size()) {
            return sums[currentIndex++];
        }

        // Compute and cache new result if pair exists.
        if (hasNextPair()) {
            long long result = safeAdd(arr1[currentIndex], arr2[currentIndex]);
            sums.push_back(result);
            currentIndex++;
            return result;
        }

        // No complete pair available.
        return std::nullopt;
    }

    // Utility methods for inspection/testing.
    std::size_t availablePairs() const {
        return std::min(arr1.size(), arr2.size());
    }

    std::size_t computedCount() const {
        return sums.size();
    }
};

int main() {
    AlternatingSum obj;
    std::string input;

    std::cout << "Enter integers (alternating), '+' to compute next sum, 'q' to quit\n";

    while (true) {
        if (!(std::cin >> input)) {
            break;  // Exit on EOF or input failure
        }

        if (input == "q") {
            break;
        }
        else if (input == "+") {
            auto result = obj.computeNextSum();
            if (result.has_value()) {
                std::cout << *result << "\n";
            } else {
                std::cout << "No complete pair available for computation.\n";
            }
        }
        else {
            try {
                std::size_t pos = 0;
                long long value = std::stoll(input, &pos);

                // Ensure full string was parsed as a valid integer.
                if (pos != input.length()) {
                    throw std::invalid_argument("Trailing characters");
                }

                obj.insert(value);
            }
            catch (const std::invalid_argument&) {
                std::cout << "Invalid input. Please enter a valid integer, '+', or 'q'.\n";
            }
            catch (const std::out_of_range&) {
                std::cout << "Number out of range for 64-bit integer.\n";
            }
        }
    }

    return 0;
}
