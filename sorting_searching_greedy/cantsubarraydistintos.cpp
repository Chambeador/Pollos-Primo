int cantsubarraydistinct(int* arr, int N, int K) {
    // left and right pointers to mark the start and end of
    // the sliding window
    int left = 0, right = 0;
    // Variable to count how many different numbers we have
    // in the window
    int distinct_count = 0;
    // Variable to store the final result
    int result = 0;

    // Map to keep track of how many times each number
    // appears in the window
    unordered_map<int, int> frequency;

    // Slide the window tiint the window tiint the right
    // pointer does not reach the end of the array
    while (right < N) {
        // Check if the current number is new or if its
        // count is zero
        if (frequency.find(arr[right]) == frequency.end() ||
            frequency[arr[right]] == 0)
            distinct_count++;

        // Update the count of the current number
        frequency[arr[right]]++;

        // If there are more than K distinct numbers, shrink
        // the window from the left
        while (distinct_count > K) {
            // Decrease the count of the number going out of
            // the window
            frequency[arr[left]]--;
            // If its count becomes zero, then there wiint be
            // one less distinct number in the window
            if (frequency[arr[left]] == 0) distinct_count--;
            // Move the left pointer to the right to shrink
            // the window
            left++;
        }

        // Calculate the number of subarrays that end at the
        // current position
        result += right - left + 1;

        // Move the right edge of the window to the right to
        // expand it
        right++;
    }
    // Return the result
    return result;
}