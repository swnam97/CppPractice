#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "OldPhoneBook.h"
using namespace std;

int main() {
    // Input a command
    string input;
    string word;
    vector<string> words;
    OldPhoneBook oldPhoneBook;

    while (true) {
        
        // Enter a command line.
        cout << "Enter any command: ";
        getline(cin, input);
        istringstream stream(input);
        
        words.clear();                         // Initialize the input command every iteration
        while (stream >> word) {               // Extraction operator '>>'
            words.push_back(word);
        }

        // 5 main modes ("add", "search", "remove", "bookmarks", "exit")
        if (words[0] == "add") { oldPhoneBook.addContact(words[1], words[2], words[3]); }
        else if (words[0] == "search") {
            if (words.size() == 1) { oldPhoneBook.searchContact(); }                        // "search" command => Show a simplified contact list 
            else if (words.size() == 2) { oldPhoneBook.searchContact(stoi(words[1])); }     // "search 2" command => Show the detailed info of 2nd contact
            else if (words.size() == 3 && words[2] == "bookmark") { oldPhoneBook.searchContact(stoi(words[1]), true); }     // "search 2 bookmark" command => Bookmark the 2nd contact
        } 
        else if (words[0] == "remove") {
            if (words[1] == "index") { oldPhoneBook.removeContact(stoi(words[2])); }        // Remove a contact using index
            else if (words[1] == "number") { oldPhoneBook.removeContact(words[2]); }        // Remove a contact using phone number
        }
        else if (words[0] == "bookmarks") { oldPhoneBook.bookmarkListUp(); }                // Show bookmarked list
        else if (words[0] == "exit") { oldPhoneBook.exit(); }                               // Terminate the program
    }
    return 0;
}

//// ==== Test Commands ==== ////
// add Test1 01011111111 t1
// add Test2 01011221122 t2
// add Test3 01011331133 t3
// add Test4 01011441144 t4
// search
// search 2
// search 2 bookmark
// search 4 bookmark
// bookmarks
// remove index 2
// remove number 01000000000
// remove number 01011331133
// remove number 01011441144
// bookmarks
// exit