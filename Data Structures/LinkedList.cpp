#include <bits/stdc++.h>
using namespace std;

// ============================================ Node Classes =================================== //
class SinglyNode {
    public:
        int data;
        SinglyNode* next;
};

class DoublyNode {
    public:
        int data;
        DoublyNode* prev;
        DoublyNode* next;
};

// ==================================== Single headed Linked list class ======================== //
class SinglyLinkedList {
    private:
        SinglyNode* head;
        int menuOption;
        int size;
    public:
        void initialize();
        void print();
        void addNode();
        void deleteNode();
        void addNodeAfterIndex();
        void addNodeAfterValue();
        void bulkAddNodes();
};

void SinglyLinkedList :: initialize() {
    head = new SinglyNode();
    head->next = NULL;

    size = 0;

    cout << "Linked list Initialized.\n";
    do {
        cout << "\nChoose an option : \n\n1. Add a node.\n2. Delete a node (value).\n3. Print the entire list.\n";
        cout << "4. Add a node after (value).\n5. Add a node at (index).\n6. Bulk add nodes.\n99. Exit\n\n>> ";
        cin >> menuOption;
        switch(menuOption) {
            case 1:
                addNode();
                break;
            case 2: 
                deleteNode();
                break;
            case 3:
                print();
                break;
            case 4:
                addNodeAfterValue();
                break;
            case 5:
                addNodeAfterIndex();
                break;
            case 6:
                bulkAddNodes();
                break;
            default:
                cout << "Please choose a valid option. \n>>";
                break;
        }
    } while(menuOption != 99);
}

void SinglyLinkedList :: print() {
    SinglyNode* temp;
    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
        cout << temp->data << " ";
    }
    cout << endl;
}

void SinglyLinkedList :: addNode() {
    SinglyNode* temp;
    temp = head;

    while (temp->next != NULL)
        temp = temp->next;
    
    SinglyNode* newNode;
    newNode = new SinglyNode();

    cout << "Enter data field for new node.\n>> ";
    cin >> newNode->data;
    temp->next = newNode;
    newNode->next = NULL;
    size++;
}

void SinglyLinkedList :: deleteNode() {
    int value;
    cout << "Enter the value to be deleted.\n>> ";
    cin >> value;

    SinglyNode* temp;
    temp = head;

    bool found = false;
    
    while (true) {
        if (temp->data == value) {
            found = true;
            break;
        } else if (temp->next == NULL) break;
        else temp = temp->next;
    }

    if (!found) {
        cout << "Node with queried value doesn't exist!\n";
        return;
    } else {
        if (temp == head) head = head->next;
        else {
            SinglyNode* temp2;
            temp2 = head;

            while (temp2->next != temp) temp2 = temp2->next;
            temp2->next = temp->next;
        }
        size--;
    }
}

void SinglyLinkedList :: addNodeAfterValue() {
    int value;
    cout << "\nEnter the value after which node shall be added.\n>> ";
    cin >> value;

    SinglyNode* temp;
    temp = head;

    bool found = false;
    
    while (true) {
        if (temp->data == value) {
            found = true;
            break;
        } else if (temp->next == NULL) break;
        else temp = temp->next;
    }

    if (!found) {
        cout << "Node with queried value doesn't exist!\n";
        return;
    } else {
        SinglyNode* newNode;
        newNode = new SinglyNode();

        cout << "Enter data field for new node.\n>> ";
        cin >> newNode->data;
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
}

void SinglyLinkedList :: addNodeAfterIndex() {
    int index;
    cout << "\nEnter the index at which a new node shall be added.\n>> ";
    cin >> index;

    if (index > size) {
        cout << "Linked list index out of bounds!";
        return;
    } else {
        SinglyNode* temp;
        temp = head;
        for (int i = 0; i < index && temp->next != NULL; ++i) temp = temp->next;

        SinglyNode* newNode;
        newNode = new SinglyNode();

        cout << "Enter data field for new node.\n>> ";
        cin >> newNode->data;
        newNode->next = temp->next;
        temp->next = newNode;
        if (index == 0) head = temp;
        size++;
    }
}

void SinglyLinkedList :: bulkAddNodes() {
    int count;
    cout << "\nEnter how many nodes to bulk add.\n>> ";
    cin >> count;

    for (int i = 0; i < count; ++i) addNode();
}

// =================================================== Main ===================================== //
int main() {
    cin.tie(0);
    cout << "Linked Lists practice code.\n";
    cout << "Choose an option :";
    
    int menuOption;
    
    do {
        cout << "\n\n1. Single headed Linked List. \n2. Double headed Linked List. \n99. Exit. \n\n>> ";
        cin >> menuOption;
        switch(menuOption) {
            case 1:
                SinglyLinkedList list;
                list.initialize();
                break;
            case 2:
                break;
            case 99:
                break;
            default:
                cout << "Please choose a valid option. \n>> ";
        }
    } while (menuOption != 99);

    return 0;
}