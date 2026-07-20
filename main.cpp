#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    cin.ignore();
    
    // Using in-memory structure for now
    // Key: string index, Value: set of integers
    map<string, set<int>> database;
    
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        
        // Parse command
        size_t space1 = line.find(' ');
        if (space1 == string::npos) {
            continue; // Invalid command
        }
        
        string cmd = line.substr(0, space1);
        
        if (cmd == "insert") {
            size_t space2 = line.find(' ', space1 + 1);
            if (space2 == string::npos) {
                continue; // Invalid insert
            }
            
            string index = line.substr(space1 + 1, space2 - space1 - 1);
            string value_str = line.substr(space2 + 1);
            int value = stoi(value_str);
            
            database[index].insert(value);
        }
        else if (cmd == "delete") {
            size_t space2 = line.find(' ', space1 + 1);
            if (space2 == string::npos) {
                continue; // Invalid delete
            }
            
            string index = line.substr(space1 + 1, space2 - space1 - 1);
            string value_str = line.substr(space2 + 1);
            int value = stoi(value_str);
            
            auto it = database.find(index);
            if (it != database.end()) {
                it->second.erase(value);
                if (it->second.empty()) {
                    database.erase(it);
                }
            }
        }
        else if (cmd == "find") {
            string index = line.substr(space1 + 1);
            
            auto it = database.find(index);
            if (it == database.end() || it->second.empty()) {
                cout << "null\n";
            } else {
                bool first = true;
                for (int val : it->second) {
                    if (!first) cout << " ";
                    cout << val;
                    first = false;
                }
                cout << "\n";
            }
        }
    }
    
    return 0;
}
