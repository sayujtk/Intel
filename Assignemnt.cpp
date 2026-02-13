#include <iostream>
#include <vector>
#include <string>
using namespace std;

// This class manages two arrays and generates alternating sums
class AlternatingSum {
private:
    vector<int> arr1;  
    vector<int> arr2;   
    vector<int> sums;   // Stores already computed sums (caching)

    int currentIndex;   // Tracks next index to compute
    bool insertInFirst; // Controls alternating insertion

public:
    // Constructor initializes state
    AlternatingSum() : currentIndex(0), insertInFirst(true) {}

    // Inserts value alternately into arr1 and arr2
    void insert(int val) {
        if (insertInFirst) {
            arr1.push_back(val);
            cout << "Inserted " << val << " into arr1\n";
        } else {
            arr2.push_back(val);
            cout << "Inserted " << val << " into arr2\n";
        }

        // Flip insertion target for next time
        insertInFirst = !insertInFirst;
    }

    // Computes the next sum based on currentIndex
    void computeNextSum() {

        // Case 1: Sum already computed earlier → reuse cached value
        if (currentIndex < sums.size()) {
            cout << "Already computed: " << sums[currentIndex] << endl;
            currentIndex++;
        }

        // Case 2: New computation possible
        else if (currentIndex < arr1.size() && currentIndex < arr2.size()) {
            int s = arr1[currentIndex] + arr2[currentIndex]; // compute sum
            sums.push_back(s);  // store it for future reuse
            cout << s << endl;
            currentIndex++;
        }

        // Case 3: No more elements available
        else {
            cout << "Error: Array size exceeded\n";
        }
    }
};

int main() {
    AlternatingSum obj;  // Object that manages logic
    string input;        // Stores user input as string

    cout << "Enter numbers (alternating), + to compute sum, q to quit\n";

    while (true) {
        cin >> input;  // Take input as string

        // Exit condition
        if (input == "q") {
            break;
        }

        // Trigger next sum computation
        else if (input == "+") {
            obj.computeNextSum();
        }

        // Try to treat input as integer
        else {
            try {
                int val = stoi(input);  // Convert string to integer
                obj.insert(val);        // Insert alternately
            }
            catch (...) {
                // If conversion fails → invalid input
                cout << "Error: Invalid input. Please enter integers, +, or q.\n";
            }
        }
    }
}
