#include "OldPhoneBook.h"
#include <iostream>
using namespace std;

OldPhoneBook::OldPhoneBook(string userName) : mUserName{userName} {
    cout << userName << "'s phonebook has been created." << endl;    
    cout << "************** Welcome to Phonebook! **************" << endl;
}

void OldPhoneBook::addContact(string name, string number, string nickname) {
    Contact newContact {name, number, nickname};
    mContactList.push_back(newContact);

    cout << "New contact is just added. [" << newContact.mName << ", "
    << newContact.mNumber << ", " << newContact.mNickname << "]" << endl;
}

void OldPhoneBook::searchContact(int idx, bool bookmark) {
    if (idx == 0) {
        cout << "Contact List: " << endl;
        int cnt = 1;
        for (const Contact contact : mContactList) {
            cout << "[" << cnt << "] " << contact.mName  << endl;
            ++cnt;
        }
    } else if (idx < 0 || idx > mContactList.size()) {
        cout << "Invalid index." << endl;
    } else if (idx > 0 && bookmark != true) {
        cout << "[" << idx << "] " << mContactList.at(idx-1).mName << " / " 
        << mContactList.at(idx-1).mNumber << " / " << mContactList.at(idx-1).mNickname << endl; 
    }

    if (idx > 0 && bookmark == true){
        mContactList[idx-1].mBookmarked = true;
    }    
}

void OldPhoneBook::removeContact(int idx) {
    if (idx > 0) {
        mContactList.erase(mContactList.begin()+idx-1);
    } else {                                                // When the index is negative number or zero,
        cout << "Invalid index." << endl;
    }
}

void OldPhoneBook::removeContact(string number) {
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

void OldPhoneBook::bookmarkListUp() {
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

void OldPhoneBook::exit() {
    cout << "The phonebook is terminated." << endl;
    std::exit(0);
}

/* Memo: Print error! ==> by Enum / */