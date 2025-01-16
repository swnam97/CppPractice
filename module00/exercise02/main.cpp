#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "OldPhoneBook.h"
using namespace std;

int main() {
    // Input a command
    string input;
    vector<string> words;
    OldPhoneBook oldPhoneBook;
    cout << "************** Welcome to Phonebook! **************" << endl;

    while (true) {
        
        // Enter a command line.
        cout << "Enter any command: ";
        getline(cin, input);

        istringstream stream(input);
        string word;

        words.clear();
        // Extraction operator(>>)
        while (stream >> word) {
            words.push_back(word);
        }

        if (words[0] == "add") { oldPhoneBook.addContact(words[1], words[2], words[3]); }
        else if (words[0] == "search") 
        {
            if (words.size() == 1) { oldPhoneBook.searchContact(); }
            else if (words.size() == 2) { oldPhoneBook.searchContact(stoi(words[1])); }
            else if (words.size() == 3 && words[2] == "bookmark") { oldPhoneBook.searchContact(stoi(words[1]), true); }
        } 
        else if (words[0] == "remove")
        {
            if (words[1] == "index") { oldPhoneBook.removeContact(words[1], stoi(words[2])); }
            else if (words[1] == "number") { oldPhoneBook.removeContact(words[1], words[2]); }
        }
        else if (words[0] == "bookmarks") { oldPhoneBook.bookmarkListUp(); }
        else if (words[0] == "exit") { oldPhoneBook.exit(); }
        
        // OldPhoneBook();
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