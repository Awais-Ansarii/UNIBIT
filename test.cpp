#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find all pairs of integers in the array that sum up to the target value
vector<vector<int>> findCombinations(vector<int> arr, int target) {
    vector<vector<int>> result; // Initialize result vector
    for (int i = 0; i < arr.size(); i++) { // Iterate over the array
        for (int j = i + 1; j < arr.size(); j++) { // Iterate over the rest of the array
            if (arr[i] + arr[j] == target) { // If the sum of the two integers equals the target value
                result.push_back({arr[i], arr[j]}); // Add the pair to the result vector
            }
        }
    }
    return result; // Return the result vector
}

// Function to merge a 2D vector into a 1D vector and sort it in ascending order
vector<int> mergeAndSort(vector<vector<int>> arr) {
    vector<int> result; // Initialize result vector
    for (auto &i : arr) { // Iterate over the 2D vector
        for (int j : i) { // Iterate over each inner vector
            result.push_back(j); // Add each element to the result vector
        }
    }
    sort(result.begin(), result.end()); // Sort the result vector in ascending order
    return result; // Return the sorted result vector
}

int main() {
    vector<int> input = {1, 3, 2, 2, -4, -6, -2, 8}; // Input array
    int target = 4; // Target value

    // Find all pairs of integers in the input array that sum up to the target value
    vector<vector<int>> firstCombination = findCombinations(input, target);
    cout << "First Combination For " << target << " : [ ";
    for (auto &i : firstCombination) {
        cout << "[";
        for (int j : i) {
            cout << j << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;

    // Merge the 2D vector into a 1D vector and sort it in ascending order
    vector<int> mergedArray = mergeAndSort(firstCombination);
    cout << "Merge Into a single Array : [ ";
    for (int i : mergedArray) {
        cout << i << ",";
    }
    cout << "]" << endl;

    target *= 2; // Double the target value

    // Find all pairs of integers in the input array that sum up to the doubled target value
    firstCombination = findCombinations(input, target);
    cout << "Second Combination For " << target << " : [ ";
    for (auto &i : firstCombination) {
        cout << "[";
        for (int j : i) {
            cout << j << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;

    return 0;
}
