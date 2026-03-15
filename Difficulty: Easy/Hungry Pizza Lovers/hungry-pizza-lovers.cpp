vector<int> permute(vector<vector<int>> &arr, int n) {
    // Vector to store {completion_time, original_index}
    vector<pair<long long, int>> completionData;

    for (int i = 0; i < n; i++) {
        // x[i] = arr[i][0], y[i] = arr[i][1]
        // Completion time = arrival + processing
        long long finishTime = (long long)arr[i][0] + arr[i][1];
        
        // Store 1-based index (i + 1)
        completionData.push_back({finishTime, i + 1});
    }

    // Sort the vector. 
    // By default, std::sort on pairs sorts by the first element,
    // and then the second element if the first ones are equal.
    sort(completionData.begin(), completionData.end());

    // Extract the sorted indices into the result vector
    vector<int> result;
    for (int i = 0; i < n; i++) {
        result.push_back(completionData[i].second);
    }

    return result;
}