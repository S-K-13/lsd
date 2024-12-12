//C++ program to maintain club member‘s information using singly linked list.

#include <iostream>
using namespace std;

class Node {
public:
    int prn;
    string name;
    Node *next;

    Node(int prn, string name) {
        this->prn = prn;
        this->name = name;
        this->next = nullptr;
    }
};

class SLL 
{
private:
    Node *head;
    Node *last;

public:
    SLL() 
    {
        head = nullptr;
        last = nullptr;
    }

    void createClub() {
        if (head == nullptr) {
            cout << "Enter PRN and Name of President: ";
            int prn;
            string name;
            cin >> prn >> name;
            head = new Node(prn, name);

            cout << "Enter PRN and Name of Secretary: ";
            cin >> prn >> name;
            last = new Node(prn, name);
            head->next = last;
        }
        else {
            cout << "Club is already created.\n";
        }
    }

    void addMember() {
        if (head == nullptr || last == nullptr) {
            cout << "Club is not yet created.\n";
            return;
        }

        cout << "Enter PRN and Name of new Member: ";
        int prn;
        string name;
        cin >> prn >> name;

        Node *newNode = new Node(prn, name);
        Node *temp = head;

        while (temp->next != last) {
            temp = temp->next;
        }

        newNode->next = last;
        temp->next = newNode;
    }

    void deleteMember(int prn) {
        if (head == nullptr || last == nullptr) {
            cout << "Club is not yet created.\n";
            return;
        }

        Node *temp = head;
        Node *prev = nullptr;

        if (head->prn == prn) { 
            cout << "Cannot delete President.\n";
            return;
        }
        if (last->prn == prn) { 
            cout << "Cannot delete Secretary.\n";
            return;
        }

        while (temp != nullptr && temp->prn != prn) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Member not found.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Member deleted successfully.\n";
    }

    int totalMembers() {
        int count = 0;
        Node *temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void displayClub() {
        if (head == nullptr) {
            cout << "Club is empty.\n";
            return;
        }

        Node *temp = head;
        cout << "Club Members:\n";
        while (temp != nullptr) {
            cout << temp->prn << "\t" << temp->name << endl;
            temp = temp->next;
        }
    }

    void displayReverse(Node *temp) {
        if (temp == nullptr)
            return;
        displayReverse(temp->next);
        cout << temp->prn << "\t" << temp->name << endl;
    }

    void displayClubReverse() {
        if (head == nullptr) {
            cout << "Club is empty.\n";
            return;
        }
        cout << "Club Members in Reverse Order:\n";
        displayReverse(head);
    }

    void concatenate(SLL& other) {
        if (last != nullptr && other.head != nullptr) {
            last->next = other.head; 
            last = other.last;       
        }
    }
};

int main() {
    SLL club1, club2;
    int choice, prn;

    while (true) {
        cout << "\n1. Create Club\n2. Add Member\n3. Delete Member\n4. Display Club\n5. Display Club in Reverse\n6. Concatenate Clubs\n7. Total Members\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                club1.createClub();
                break;
            case 2:
                club1.addMember();
                break;
            case 3:
                cout << "Enter PRN of member to delete: ";
                cin >> prn;
                club1.deleteMember(prn);
                break;
            case 4:
                club1.displayClub();
                break;
            case 5:
                club1.displayClubReverse();
                break;
            case 6:
                club2.createClub();
                club1.concatenate(club2);
                cout << "Clubs concatenated successfully.\n";
                break;
            case 7:
                cout << "Total Members: " << club1.totalMembers() << endl;
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
