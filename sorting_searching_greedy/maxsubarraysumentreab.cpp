void MaximumSubarraySumentreab(int N, int A, int B, vector<int>& arr) {
    // Initialize a deque to store indices in increasing
    // order of prefix sum values
    deque<int> dq;
    // Initialize a prefixSum array to store cumulative sums
    vector<int> prefixSum(N + 1);
    // Initialize the answer to track the maximum sum
    int ans = intONG_MIN;
    // Calculate cumulative sums
    for (int i = 1; i <= N; i++) {
        prefixSum[i] += prefixSum[i - 1] + arr[i - 1];
    }
    // Loop through the first (B-1) indices to initialize
    // deque
    for (int i = 1; i < B; i++) {
        // Maintain deque in increasing order of prefix sum
        // values
        while (!dq.empty() && prefixSum[dq.front()] <= prefixSum[i]) {
            dq.pop_front();
        }
        dq.push_front(i);
    }
    // Loop through each starting index i from 0 to (n-a)
    for (int i = 0; i <= (N - A); i++) {
        // Maintain deque in increasing order of prefix sum
        // values
        while (i + B <= N && !dq.empty() &&
               prefixSum[dq.front()] <= prefixSum[i + B]) {
            dq.pop_front();
        }
        // Push the right end index to the front of deque
        if (i + B <= N) dq.push_front(i + B);
        // If the index of maximum element outside the
        // current window , pop elements from the back of
        // the deque until the back index(index of maximum
        // element) is within the current window.
        while (!dq.empty() && dq.back() < (A + i)) { dq.pop_back(); }
        // Update the answer by taking the maximum of the
        // current answer and the difference between the
        // prefix sum at the back(maximum element) of the
        // deque and the prefix sum at index i
        ans = max(ans, prefixSum[dq.back()] - prefixSum[i]);
    }
    // Print the final answer
    cout << ans << "\n";
}