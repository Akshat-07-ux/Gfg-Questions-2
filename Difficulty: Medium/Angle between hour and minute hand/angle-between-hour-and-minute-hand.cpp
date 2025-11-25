class Solution {
public:
    double getAngle(string& s) {
        int HH = stoi(s.substr(0, 2));
        int MM = stoi(s.substr(3, 5));

        HH %= 12;

        double minute_angle = MM * 6.0;
        double hour_angle = HH * 30.0 + MM * 0.5;

        double diff = fabs(hour_angle - minute_angle);
        
        return min(diff, 360.0 - diff);
    }
};
