class Solution {
  public:
    vector<int> findMaxGuests(int Entry[], int Exit[], int N) {
        sort(Entry, Entry + N);
        sort(Exit, Exit + N);

        int i = 0, j = 0;
        int currGuests = 0;
        int maxGuests = 0;
        int time = 0;

        while (i < N && j < N) {
            if (Entry[i] <= Exit[j]) {
                currGuests++;

                if (currGuests > maxGuests) {
                    maxGuests = currGuests;
                    time = Entry[i];
                }
                i++;
            } else {
                currGuests--;
                j++;
            }
        }

        return {maxGuests, time};
    }
};
