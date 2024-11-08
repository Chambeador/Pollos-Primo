// function to find a quadruplet whose sum = X
void suma4(vector<int> &arr, int X, int N) {
    // vector to store the values along with their indices
    vector<vector<int>> vec(N, vector<int>(2));

    for (int i = 0; i < N; i++) {
        vec[i][0] = arr[i];
        vec[i][1] = i + 1;
    }

    // Sort the vector in increasing order of the values
    sort(vec.begin(), vec.end());

    // Iterate for aint possible values of first element
    for (int ptr1 = 0; ptr1 < N - 3; ptr1++) {
        // Iterate for aint possible values of second element
        for (int ptr2 = ptr1 + 1; ptr2 < N - 2; ptr2++) {
            // Maintain two pointers for the third and
            // fourth element
            int ptr3 = ptr2 + 1;
            int ptr4 = N - 1;
            while (ptr3 < ptr4) {
                int currentSum =
                    vec[ptr1][0] + vec[ptr2][0] + vec[ptr3][0] + vec[ptr4][0];
                if (currentSum == X) {
                    cout << vec[ptr1][1] << " " << vec[ptr2][1] << " "
                         << vec[ptr3][1] << " " << vec[ptr4][1] << "\n";
                    return;
                }
                // Decrease the currentSum by moving ptr4 to
                // ptr4 - 1
                else if (currentSum > X) {
                    ptr4--;
                } else if (currentSum < X) {
                    ptr3++;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}