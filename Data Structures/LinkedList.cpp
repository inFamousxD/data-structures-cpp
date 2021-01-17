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
        SinglyNode* returnHead();
};

void SinglyLinkedList :: create() {
    head = new SinglyNode();
    head->next = NULL;
    size = 0;
    cout << "Linked list Initialized.\n";
}

SinglyNode* SinglyLinkedList :: returnHead() {
    return head;
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
        void deleteList();
        void continueEditingList();
        void print();
        void printAllLists();
        void mergeLists();
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
        cout << "\n6. Merge 2 lists.";
        cout << "\n99. Exit.\n\n>> ";
        cin >> menuOption;

        switch(menuOption) {
            case 1:
                addList();
                break;
            case 2:
                deleteList();
                break;
            case 3:
                continueEditingList();
            case 4:
                print();
                break;
            case 5:
                printAllLists();
                break;
            case 6:
                mergeLists();
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

void SinglyListHolder :: deleteList() {
    SinglyListNode* temp;
    temp = head;

    string name;
    print();
    cout << "\nEnter the name of list you want to delete.\n>> ";
    cin >> name;

    bool found = false;
    
    while (true) {
        if (temp->name == name) {
            found = true;
            break;
        } else if (temp->next == NULL) break;
        else temp = temp->next;
    }

    if (!found) {
        cout << "List with queried name doesn't exist!\n";
        return;
    } else {
        if (temp == head) head = head->next;
        else {
            SinglyListNode* temp2;
            temp2 = head;

            while (temp2->next != temp) temp2 = temp2->next;
            temp2->next = temp->next;
        }
        size--;
    }
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

void SinglyListHolder :: mergeLists() {
    print();
    string name1, name2;
    cout << "\nEnter names of lists you want to merge.\nList 1\n>> ";
    cin >> name1;
    cout << "\nList 2\n>> ";
    cin >> name2;

    SinglyListNode* temp1;
    SinglyListNode* temp2;
    temp1 = head;
    temp2 = head;

    bool found = false;
    while (true) {
        if (temp1->name == name1) {
            found = true;
            break;
        } else temp1 = temp1->next;
    }

    if (!found) {
        cout << "\nRecheck the name and try again!";
        return;
    } else {
        found = false;
        while (true) {
            if (temp2->name == name2) {
                found = true;
                break;
            } else temp2 = temp2->next;
        }

        if (!found) {
            cout << "\nRecheck the name and try again!";
            return;
        } else {
            SinglyNode* list1;
            list1 = temp1->node.returnHead();

            while(list1->next != NULL)
                list1 = list1->next;

            list1->next = temp2->node.returnHead()->next;
        }
    }
}

// ==================================== Double headed Linked List =============================== //

class DoublyLinkedList {
    private:
        DoublyNode* head;
        DoublyNode* tail;
        int menuOption;
        int size;
    public:
        void create();
        void initialize();
        void print();
        void addNode();
        void deleteNode();
        void addNodeAfterValue();
        void addNodeAfterIndex();
        void bulkAddNodes();
        DoublyNode* returnHead();
        DoublyNode* returnTail();
};

DoublyNode* DoublyLinkedList :: returnHead() {
    return head;
}

DoublyNode* DoublyLinkedList :: returnTail() {
    return tail;
}

void DoublyLinkedList :: create() {
    head = new DoublyNode();
    head->next = NULL;
    head->prev = NULL;

    tail = new DoublyNode();
    tail = head;

    size = 0;
    cout << "Linked list Initialized.\n";
}

void DoublyLinkedList :: initialize() {
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

void DoublyLinkedList :: addNode() {
    DoublyNode* newNode;
    newNode = new DoublyNode();

    cout << "Enter data field for new node.\n>> ";
    cin >> newNode->data;

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    size++;
}

void DoublyLinkedList :: print() {
    DoublyNode* temp;
    temp = head;
    int n = 1;

    do {
        temp = temp->next;
        cout << setfill('0') << setw(3) << n++ << ". " << temp->data << "\n";
    } while(temp != tail);
}

void DoublyLinkedList :: addNodeAfterIndex() {
    int index;
    cout << "\nEnter the index at which a new node shall be added.\n>> ";
    cin >> index;

    if (index > size) {
        cout << "Linked list index out of bounds!";
        return;
    } else {
        bool direction = true;
        DoublyNode* temp;
        if (size - index >= size/2) { 
            temp = tail;
            direction = false;
        } else {
            temp = head;
            direction = true;
        }

        if (direction) {
            for (int i = 0; i < index; ++i)
                if (temp->next != NULL) temp = temp->next;
        } else {
            for (int i = 0; i < size-index; ++i)
                if (temp->prev != NULL) temp = temp->prev;
        }

        DoublyNode* newNode;
        newNode = new DoublyNode();

        cout << "Enter data field for new node.\n>> ";
        cin >> newNode->data;

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;

        if (index == 0) head = temp;
        size++;
    }
}

void DoublyLinkedList :: addNodeAfterValue() {
    string value;
    cout << "\nEnter the value after which node shall be added.\n>> ";
    cin >> value;

    DoublyNode* temp;

    bool found = false;

}

void DoublyLinkedList :: deleteNode() {
    string value;
    cout << "Enter the value to be deleted.\n>> ";
    cin >> value;

    DoublyNode* temp;
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
        if (temp == tail) {
            tail = tail->prev;
        } else if (temp == head) {
            head = head->next;
        } else { 
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
    }
}

void DoublyLinkedList :: bulkAddNodes() {
    int nodesToAdd;
    cout << "\nEnter how many nodes you want to add.\n>> ";
    cin >> nodesToAdd;

    for (int i = 0; i < nodesToAdd; ++i) {
        addNode();
    }
}

// ==================================== Double headed Linked List Holder ======================== //

class DoublyListNode {
    public:
        string name;
        DoublyLinkedList node;
        DoublyListNode* next;
        DoublyListNode* prev;
};

class DoublyListHolder {
    private:
        DoublyListNode* head;
        int menuOption;
        int size;
    public:
        void create();
        void initialize();
        void addList();
        void deleteList();
        void continueEditingList();
        void print();
        void printAllLists();
        void mergeLists();
};

void DoublyListHolder :: create() {
    head = new DoublyListNode();
    head->next = NULL;
    head->prev = NULL;
} 

void DoublyListHolder :: initialize() {
    cout << "\nChoose an option: ";
    
    do {
        cout << "\n1. Add a new double headed list.";
        cout << "\n2. Delete a list.";
        cout << "\n3. Continue editing a list.";
        cout << "\n4. Print all list names.";
        cout << "\n5. Print all lists.";
        cout << "\n6. Merge 2 lists.";
        cout << "\n99. Exit.\n\n>> ";
        cin >> menuOption;

        switch(menuOption) {
            case 1:
                addList();
                break;
            case 2:
                deleteList();
                break;
            case 3:
                continueEditingList();
            case 4:
                print();
                break;
            case 5:
                printAllLists();
                break;
            case 6:
                mergeLists();
                break;
            case 99:
                break;
            default:
                cout << "Please choose a valid option. \n>>";
                break;
        }
    } while(menuOption != 99);
}

void DoublyListHolder :: addList() {
    DoublyListNode* temp;
    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    DoublyListNode* newNode;
    newNode = new DoublyListNode();
    cout << "\nName this list.\n>> ";
    cin >> newNode->name;
    newNode->next = NULL;
    newNode->prev = NULL;
    temp->next = newNode;

    size++;

    newNode->node.create();
    newNode->node.initialize();
}

void DoublyListHolder :: deleteList() {
    DoublyListNode* temp;
    temp = head;

    string name;
    print();
    cout << "\nEnter the name of list you want to delete.\n>> ";
    cin >> name;

    bool found = false;
    
    while (true) {
        if (temp->name == name) {
            found = true;
            break;
        } else if (temp->next == NULL) break;
        else temp = temp->next;
    }

    if (!found) {
        cout << "List with queried name doesn't exist!\n";
        return;
    } else {
        if (temp == head) head = head->next;
        else {
            DoublyListNode* temp2;
            temp2 = head;

            while (temp2->next != temp) temp2 = temp2->next;
            temp2->next = temp->next;
        }
        size--;
    }
}

void DoublyListHolder :: print() {
    DoublyListNode* temp;
    temp = head;
    int n = 1;

    while (temp->next != NULL) {
        temp = temp->next;
        cout << n++ << "." << temp->name << "\n";
    }

    cout << endl;
}

void DoublyListHolder :: continueEditingList() {
    string name;

    cout << "\nType the list name you want to continue from.\nSaved lists: \n";
    print();
    cout << ">> ";
    cin >> name;

    DoublyListNode* temp;
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

void DoublyListHolder :: printAllLists() {
    DoublyListNode* temp;
    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
        cout << "\nPrinting : " << temp->name << endl;
        temp->node.print();
    }
}

void DoublyListHolder :: mergeLists() {
    print();
    string name1, name2;
    cout << "\nEnter names of lists you want to merge.\nList 1\n>> ";
    cin >> name1;
    cout << "\nList 2\n>> ";
    cin >> name2;

    DoublyListNode* temp1;
    DoublyListNode* temp2;
    temp1 = head;
    temp2 = head;

    bool found = false;
    while (true) {
        if (temp1->name == name1) {
            found = true;
            break;
        } else temp1 = temp1->next;
    }

    if (!found) {
        cout << "\nRecheck the name and try again!";
        return;
    } else {
        found = false;
        while (true) {
            if (temp2->name == name2) {
                found = true;
                break;
            } else temp2 = temp2->next;
        }

        if (!found) {
            cout << "\nRecheck the name and try again!";
            return;
        } else {
            DoublyNode* list1Tail;
            list1Tail = temp1->node.returnTail();
            list1Tail->next = temp2->node.returnHead()->next;
            temp2->node.returnHead()->next->prev = list1Tail;
            list1Tail = temp2->node.returnTail();
        }
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
                SinglyListHolder slh;
                slh.create();
                slh.initialize();
                break;
            case 2:
                DoublyListHolder dlh;
                dlh.create();
                dlh.initialize();
                break;
            case 99:
                break;
            default:
                cout << "Please choose a valid option. \n>> ";
        }
    } while (menuOption != 99);

    return 0;
}