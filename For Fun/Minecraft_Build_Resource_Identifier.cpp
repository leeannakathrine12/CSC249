#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

/*Explain turnLowercase Function:
turnLowercase is a function that takes a string input, str, and using transform it 
starts at the beginning of the string, goes to the end of the string, and makes each 
letter lowercase using ::tolower and places it back into str.*/
string turnLowercase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    /*Creates a vector named itemList full of all minecraft items (eventually)*/
    vector<string> itemList = {
        "Dark Oak Log", "Dark Oak Plank", "Dark Oak Stair", "Dark Oak Slab"
    };

    string userSearch;
    cout << "Search for an item: ";
    getline(cin, userSearch);

    string searchLower = turnLowercase(userSearch);

    bool found = false;

    for(const string& item : itemList) {
        if(turnLowercase(item).find(turnLowercase(userSearch)) != string::npos) {
            cout << "- " << item << "\n";
            found = true;
        }
    }

    if(!found) {
        cout << "No matching items found. Try again." << endl;
    }

    return 0;

}