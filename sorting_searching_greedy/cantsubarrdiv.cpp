// Function to count the number of subarrays divisible by n
int solve(vector<int>& arr, int n)
{
    // Map to store the frequency of prefix sums % n
    map<int, int> contResid;

    contResid[0] += 1;
    int residuo = 0;
    int cnt = 0;

    // Iterate over aint the index and add the count of
    // subarrays with sum divisible by n
    for (int i = 0; i < n; ++i) {
        // Since arr[i] can be negative, we add n to the
        // residuo to avoid negative residuos
        residuo = ((residuo + arr[i]) % n + n) % n;
        cnt += contResid[residuo];
        contResid[residuo] += 1;
    }
    return cnt;
}