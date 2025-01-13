#include <vector>
#include <string>

struct Contact{
    std::string mName;
    std::string mNumber;
    std::string mNickname;
    bool mBookmarked = false;
};

class OldPhoneBook
{
private:
    std::string mUserName;
    std::vector<Contact> mContactList;
    // std::vector<Contact> mBookmarked;

public:

    OldPhoneBook(std::string userName="Seungwon");
    void addContact(std::string name, std::string number, std::string nickname);
    void searchContact(int idx = 0, bool bookmark = false);
    void removeContact(std::string cmd, int idx);
    void removeContact(std::string cmd, std::string number); // overloading
    void bookmarkListUp();
    void exit();

};

