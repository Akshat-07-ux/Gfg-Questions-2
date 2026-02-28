class Solution {
  public:
    long long makeProductOne(int arr[], int N) {
        long long steps = 0;
        int negative_count = 0;
        int zero_count = 0;

        for (int i = 0; i < N; i++) {
            if (arr[i] == 0) {
                zero_count++;
                steps++; // Cost to change 0 to 1 (or -1) is always 1 step
            } 
            else if (arr[i] < 0) {
                negative_count++;
                // Cost to change negative number to -1
                steps += (-1 - arr[i]);
            } 
            else {
                // Cost to change positive number to 1
                steps += (arr[i] - 1);
            }
        }

        // If the number of -1s is odd and we have NO zeros to flip the sign,
        // we must change one -1 to 1, which adds 2 steps (-1 -> 0 -> 1).
        if (negative_count % 2 != 0 && zero_count == 0) {
            steps += 2;
        }

        return steps;
    }
};