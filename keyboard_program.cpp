#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

int getdistance(string word) {
    // Define the keyboard layout and map each letter to its position
    unordered_map<char, pair<int, int>> keyboard = {
        {'Q', {0, 0}}, {'W', {0, 1}}, {'E', {0, 2}}, {'R', {0, 3}}, {'T', {0, 4}}, 
        {'Y', {0, 5}}, {'U', {0, 6}}, {'I', {0, 7}}, {'O', {0, 8}}, {'P', {0, 9}},
        {'A', {1, 0}}, {'S', {1, 1}}, {'D', {1, 2}}, {'F', {1, 3}}, {'G', {1, 4}}, 
        {'H', {1, 5}}, {'J', {1, 6}}, {'K', {1, 7}}, {'L', {1, 8}},
        {'Z', {2, 0}}, {'X', {2, 1}}, {'C', {2, 2}}, {'V', {2, 3}}, {'B', {2, 4}}, 
        {'N', {2, 5}}, {'M', {2, 6}}
    };
    
    // Start at 'Q'
    pair<int, int> current_position = keyboard['Q'];
    int total_distance = 0;

    // Iterate through each letter in the word
    for (char letter : word) {
        // Get the position of the target letter
        pair<int, int> target_position = keyboard[letter];
        
        // Calculate the Manhattan distance
        int distance = abs(current_position.first - target_position.first) + abs(current_position.second - target_position.second);
        
        // Add the distance to the total
        total_distance += distance;
        
        // Update the current position
        current_position = target_position;
    }

    return total_distance;
}

int main() {
    string word = "QWSZ";
    cout << getdistance(word) << endl;  // Output: 3
    return 0;
}
