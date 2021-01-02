#include <bits/stdc++.h>
using namespace std;

// ============================================ Node Classes =================================== //
class SinglyNode {
    public:
        char data[100];
        SinglyNode* next;
};

class DoublyNode {
    public:
        char data[100];
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
        void create();
        void initialize();
        void print();
        void addNode();
        void deleteNode();
        void addNodeAfterIndex();
        void addNodeAfterValue();
        void bulkAddNodes();
};

void SinglyLinkedList :: create() {
    head = new SinglyNode();
    head->next = NULL;
    size = 0;
    cout << "Linked list Initialized.\n";
}

void SinglyLinkedList :: initialize() {
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
            case 99:
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
    int n = 1;

    while (temp->next != NULL) {
        temp = temp->next;
        cout << n++ << ". " << temp->data << "\n";
    }
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
    string value;
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
    string value;
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

// ==================================== Single Headed List Holder class ======================== //
class SinglyListNode {
    public:
        string name;
        SinglyLinkedList node;
        SinglyListNode* next;
        SinglyListNode* prev;
};

class SinglyListHolder {
    private:
        SinglyListNode* head;
        int menuOption;
        int size;
    public:
        void create();
        void initialize();
        void addList();
        void continueEditingList();
        void print();
        void printAllLists();
};

void SinglyListHolder :: create() {
    head = new SinglyListNode();
    head->next = NULL;
    head->prev = NULL;
} 

void SinglyListHolder :: initialize() {
    cout << "\nChoose an option: ";
    
    do {
        cout << "\n1. Add a new single headed list.";
        cout << "\n2. Delete a list.";
        cout << "\n3. Continue editing a list.";
        cout << "\n4. Print all list names.";
        cout << "\n5. Print all lists.";
        cout << "\n99. Exit.\n\n>> ";
        cin >> menuOption;

        switch(menuOption) {
            case 1:
                addList();
                break;
            case 3:
                continueEditingList();
            case 4:
                print();
                break;
            case 5:
                printAllLists();
                break;
            case 99:
                break;
            default:
                cout << "Please choose a valid option. \n>>";
                break;
        }
    } while(menuOption != 99);
}

void SinglyListHolder :: addList() {
    SinglyListNode* temp;
    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    SinglyListNode* newNode;
    newNode = new SinglyListNode();
    cout << "\nName this list.\n>> ";
    cin >> newNode->name;
    newNode->next = NULL;
    newNode->prev = NULL;
    temp->next = newNode;

    size++;

    newNode->node.create();
    newNode->node.initialize();
}

void SinglyListHolder :: print() {
    SinglyListNode* temp;
    temp = head;
    int n = 1;

    while (temp->next != NULL) {
        temp = temp->next;
        cout << n++ << "." << temp->name << "\n";
    }

    cout << endl;
}

void SinglyListHolder :: continueEditingList() {
    string name;

    cout << "\nType the list name you want to continue from.\nSaved lists: \n";
    print();
    cout << ">> ";
    cin >> name;

    SinglyListNode* temp;
    temp = head;

    bool found = false;
    while (true) {
        if (temp->name == name) {
            found = true;
            break;
        } else temp = temp->next;
    }

    if (!found) {
        cout << "\nRecheck the name and try again!";
        return;
    } else {
        temp->node.initialize();
    }
}

void SinglyListHolder :: printAllLists() {
    SinglyListNode* temp;
    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
        cout << "\nPrinting : " << temp->name << endl;
        temp->node.print();
    }
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
                SinglyListHolder object;
                object.create();
                object.initialize();
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