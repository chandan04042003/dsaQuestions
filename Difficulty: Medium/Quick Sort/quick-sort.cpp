//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(const vector<int>& arr) {
    for (int num : arr)
        printf("%d ", num);
    printf("\n");
}


// } Driver Code Ends
class Solution {
  public:
    // Function that takes the last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to the left of pivot and all greater elements to the right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high]; // Pivot element
        int i = low - 1;       // Index of smaller element

        for (int j = low; j <= high - 1; j++) {
            // If current element is smaller than or equal to pivot
            if (arr[j] <= pivot) {
                i++; // Increment the index of the smaller element
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]); // Place pivot in its correct position
        return i + 1;                // Return the partition index
    }

public:
    // Function to sort an array using the Quick Sort algorithm
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            // Partition the array and get the pivot index
            int pivotIndex = partition(arr, low, high);

            // Recursively sort the subarrays
            quickSort(arr, low, pivotIndex - 1);  // Left subarray
            quickSort(arr, pivotIndex + 1, high); // Right subarray
        }
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    scanf("%d", &T);
    getchar(); // to consume newline after T

    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        ob.quickSort(arr, 0, arr.size() - 1);
        printArray(arr);
    }

    return 0;
}

// } Driver Code Ends