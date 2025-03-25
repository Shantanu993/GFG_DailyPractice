//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
    vector<string> camelCase(vector<string> &arr, string &pat) {
        // code here
        // vector for storing matched words
    vector<string> res;
    for (string word : arr) {

        int i = 0, j = 0;
        while (i < word.length() && j < pat.length()) {

            // If ith character of word is a lowercase
            // character, move to next character
            if (islower(word[i])) {
                i++;
            }

            // If ith character of word is an uppercase
            // character and does not match with the jth
            // character of pattern, move to the next word
            else if (word[i] != pat[j]) {
                break;
            }

            // If ith character of word is an uppercase
            // character and matches with the jth character
            // of pattern move to the next characters
            else {
                i++;
                j++;
            }
        }

        // If all characters of pattern matched, then insert
        // the word in result
        if (j == pat.length())
            res.push_back(word);
    }

    return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore(); // Clear the buffer after reading t
    while (t--) {
        string input;
        vector<string> arr;

        // Read the line of words
        getline(cin, input);
        stringstream ss(input);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        string pat;
        cin >> pat;
        cin.ignore(); // Clear the buffer after reading pat

        // Create an instance of the Solution class
        Solution ob;
        vector<string> ans = ob.camelCase(arr, pat);
        if (ans.empty()) {
            cout << "[]\n";
        } else {
            // Sort results before printing
            sort(ans.begin(), ans.end());
            for (const auto& u : ans)
                cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends