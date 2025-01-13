#include <iostream>
#include <string>
#include <cstring>
#include <chrono>
using namespace std;
using namespace chrono;

int main(int argc, char* argv[]){
    // Start the timer
    auto start = chrono::high_resolution_clock::now();

    if (argc < 3) {
        cout << "[Error] Enter appropriate arguments!" << endl;
        return -1;
    }

    if (string(argv[1]) == "up"){
        int i = 2;          // Input strings appear starting from argv[2]
        while (i < argc) {
            int j = 0; 
            while (j < strlen(argv[i])) {
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
            while (j < strlen(argv[i])) {
                if (*(argv[i]+j) <= 90 && *(argv[i]+j) >= 65) {
                    *(argv[i]+j) += 32;
                }
                ++j;
            } 
            ++i;
        }
    } else {
        cout << "[Error] Wrong arguments!: " << argv[1] << endl;
    }

    for (int i=2; i<argc; ++i) {
        cout << argv[i] << " ";
    }

    // End the timer
    auto end = chrono::high_resolution_clock::now();

    // Calculate the elapsed time
    auto duration = chrono::duration_cast<nanoseconds>(end-start);
    // cout << "Time consumed: " << duration.count() << " milliseconds" << endl;
    cout << "Time consumed: " << duration.count() << " nanoseconds" << endl;

    return 0;

}