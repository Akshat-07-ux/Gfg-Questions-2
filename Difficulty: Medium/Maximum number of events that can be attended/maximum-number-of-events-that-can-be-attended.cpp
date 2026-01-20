class Solution {
  public:
    int maxEvents(int start[], int end[], int N) {
        // Create a vector of pairs to store start and end times together
        vector<pair<int, int>> events;
        for (int i = 0; i < N; i++) {
            events.push_back({start[i], end[i]});
        }

        // Sort events based on their starting day
        sort(events.begin(), events.end());

        // Min-heap to store the end days of available events
        priority_queue<int, vector<int>, greater<int>> pq;

        int i = 0, day = 0, count = 0;

        // Continue until all events are processed and the heap is empty
        while (i < N || !pq.empty()) {
            // If no events are currently available, jump to the next available event's start day
            if (pq.empty()) {
                day = events[i].first;
            }

            // Add all events that start on the current day to the priority queue
            while (i < N && events[i].first <= day) {
                pq.push(events[i].second);
                i++;
            }

            // Remove events that ended before the current day
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            // Attend the event that ends the earliest
            if (!pq.empty()) {
                pq.pop();
                count++;
                day++; // Move to the next day
            }
        }

        return count;
    }
};