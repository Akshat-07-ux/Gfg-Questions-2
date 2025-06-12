#include <string>
using namespace std;

string to_upper(string str) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';  // convert to uppercase
        }
    }
    return str;
}
