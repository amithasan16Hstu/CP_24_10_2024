#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// Function to process the input and return result
string process_string(const string &s) {
    stringstream ss(s);
    string x, y;
    vector<string> a;
    ss >> x;  // First part (x)
    
    string temp;
    while (ss >> temp) {
        a.push_back(temp);  // Middle part (a)
    }
    
    y = a.back();  // Last part (y)
    a.pop_back();  // Remove the last element from a (since it's y)

    // If x == y, return "NO", else return "YES RB" followed by R's of the size of a
    return (x == y) ? "NO" : ("YES RB" + string(a.size(), 'R'));
}

int main() {
    string line;
    vector<string> inputs;
    
    // Read input until EOF
    while (getline(cin, line)) {
        inputs.push_back(line);
    }
    
    // Process every second string starting from index 2
    for (size_t i = 2; i < inputs.size(); i += 2) {
        cout << process_string(inputs[i]) << endl;
    }

    return 0;
}
