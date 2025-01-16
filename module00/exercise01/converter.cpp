#include <iostream>
#include <string>
#include <cstring>
#include <chrono>
using namespace std;
using namespace chrono;

int main(int argc, char* argv[]){
    // Start the timer
    auto start = chrono::high_resolution_clock::now();

    // When the number of inputs is not enough,
    if (argc < 3) {
        cout << "[Error] Enter appropriate arguments!" << endl;         // (e.g.) ./converter up 
        return -1;
    }

    // When the number of inputs is enough,
    // (e.g.) ./converter up HelLo mY naME Is
    if (string(argv[1]) == "up"){               // argv[1] should be "up" or "down"
        int i = 2;                              // Input strings appear starting from argv[2]
        while (i < argc) {                      // Iterate through each word. (e.g. HelLo // mY // naME // Is)
            int j = 0; 
            int num_chars = strlen(argv[i]);
            while (j < num_chars) {       // Iterate through each character in a word. (e.g. H // e // l // L // o)
                // Change ASCII values if it's an lowercase
                // Access with dereferencing of pointer
                if (*(argv[i] + j) <= 122 && *(argv[i] + j) >= 97) {
                    *(argv[i] + j) -= 32;
                }
                ++j;
            } 
            ++i;
        }
    } else if (string(argv[1]) == "down") {
        int i = 2;          // Input strings appear starting from argv[2]
        while (i < argc) {
            int j = 0;
            int num_chars = strlen(argv[i]);
            while (j < num_chars) {
                // Change ASCII values if it's an uppercase
                // Access with dereferencing of pointer
                if (*(argv[i]+j) <= 90 && *(argv[i]+j) >= 65) {
                    *(argv[i]+j) += 32;
                }
                ++j;
            } 
            ++i;
        }
    } else {
        cout << "[Error] Wrong command input!: " << argv[1] << endl;       // (e.g.)  ./converter upp HelLo mY naME Is
    }

    // Print changed strings.
    for (int i=2; i<argc; ++i) {
        cout << argv[i] << " ";
    }

    // End the timer
    auto end = chrono::high_resolution_clock::now();

    // Calculate the elapsed time
    auto duration = chrono::duration_cast<nanoseconds>(end-start);
    cout << "Time consumed: " << duration.count() << " nanoseconds" << endl;
    // cout << "Time consumed: " << duration.count() << " milliseconds" << endl;

    return 0;
}