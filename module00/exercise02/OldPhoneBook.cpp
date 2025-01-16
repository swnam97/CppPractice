#include "OldPhoneBook.h"
#include <iostream>
using namespace std;

OldPhoneBook::OldPhoneBook(string userName) : mUserName{userName}
{
    cout << userName << "'s phonebook has been created." << endl;    
}

void OldPhoneBook::addContact(string name, string number, string nickname)
{
    Contact newContact {name, number, nickname};
    mContactList.push_back(newContact);

    cout << "New contact is just added. [" << newContact.mName << ", "
    << newContact.mNumber << ", " << newContact.mNickname << "]" << endl;
}

void OldPhoneBook::searchContact(int idx, bool bookmark)
{
    if (idx == 0) {
        cout << "Contact List: " << endl;
        int cnt = 1;
        for (const Contact contact : mContactList) {
            cout << "[" << cnt << "] " << contact.mName  << endl;
            // cout << "[" << cnt << "] " << contact.mName << " / " << contact.mNumber
            // << " / " << contact.mNickname << endl;
            ++cnt;
        }
    } else if (idx < 0) {
        // Print error! ==> by Enum
        cout << "Invalid index." << endl;
    } else if (idx > 0 && bookmark != true) {
        cout << "[" << idx << "] " << mContactList.at(idx-1).mName << " / " 
        << mContactList.at(idx-1).mNumber << " / " << mContactList.at(idx-1).mNickname << endl; 
    }

    if (idx > 0 && bookmark == true){
        mContactList[idx-1].mBookmarked = true;
    }    
}

void OldPhoneBook::removeContact(string cmd, int idx)
{
    if (cmd == "index" && idx > 0) {
        mContactList.erase(mContactList.begin()+idx-1);
    } else if (cmd == "index" && idx <= 0) {
        cout << "Invalid index." << endl;
    }
    else { cout << "Invalid command." << endl; } 
}

void OldPhoneBook::removeContact(string cmd, string number)
{
    if (cmd == "number") {
        int cnt = 0;
        for (const Contact contact : mContactList) {
            if (contact.mNumber == number) {
                mContactList.erase(mContactList.begin() + cnt);
                cout << "The phone number is just removed." << endl;
                break;
            }

            if (cnt+1 == mContactList.size()) {
                cout << "The phone number doesn't exist in the phonebook." << endl;
            }
            ++cnt;
        }
    }
    else { cout << "Invalid command." << endl; } 
}

void OldPhoneBook::bookmarkListUp()
{
    cout << "Bookmarked List: " << endl;
    int cnt = 1;
    for (const Contact contact : mContactList) {
        if (contact.mBookmarked == true) {
            cout << "[" << cnt << "] " << contact.mName << " / " << contact.mNumber << " / " 
            << contact.mNickname << endl;
        }
        ++cnt;
    }
}

void OldPhoneBook::exit()
{
    cout << "The phonebook is terminated." << endl;
    std::exit(0);
    // break;

}
