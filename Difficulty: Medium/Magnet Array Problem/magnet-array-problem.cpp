class Solution {
  public:
    // Helper function to calculate the net force at a given point 'mid'
    double getNetForce(double mid, double magnets[], int n) {
        double netForce = 0;
        for (int i = 0; i < n; i++) {
            netForce += 1.0 / (mid - magnets[i]);
        }
        return netForce;
    }

    void nullPoints(int n, double magnets[], double getAnswer[]) {
        // There are n-1 equilibrium points, one in each interval [magnets[i], magnets[i+1]]
        for (int i = 0; i < n - 1; i++) {
            double low = magnets[i];
            double high = magnets[i + 1];
            
            // Binary search for the point where net force is zero
            // 100 iterations provide more than enough precision for 2 decimal places
            for (int iter = 0; iter < 100; iter++) {
                double mid = low + (high - low) / 2.0;
                double force = getNetForce(mid, magnets, n);
                
                // If force is positive, the equilibrium is to the right
                if (force > 0) {
                    low = mid;
                } else {
                    // If force is negative, the equilibrium is to the left
                    high = mid;
                }
            }
            getAnswer[i] = low;
        }
    }
};