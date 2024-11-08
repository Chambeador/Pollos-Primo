int cantsesubarrsumaequis(vector<int>& arr, int x, int n)
{
    // Map to store the frequency of prefix sums
    map<int, int> prefSums;

    prefSums[0] = 1;
    int pref = 0;
    int cnt = 0;

    // Calculate the prefix sum at every index, and find the
    // count of subarrays with sum = pref - x
    for (int i = 0; i < n; ++i) {
        pref += arr[i];
        cnt += (prefSums[pref - x]);
        prefSums[pref]++;
    }
    return cnt;
}
