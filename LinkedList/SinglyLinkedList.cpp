#include <iostream>
using namespace std;

//creating Node
class Node {
    public:

    int data;
    Node *nextNode;

    Node(int data) {
        this->data = data;
        this->nextNode = NULL;
    }
};


//creating linked list class
class LinkedList {
    private:
    Node *startingNode;

    public:
    //constructor for initializing the list
    LinkedList() {
        startingNode = NULL;
    }

    //for checking if the list is empty or not
    bool isEmpty() {
        if(startingNode == NULL)
            return true;
        else
            return false;
    }

    //get number of data/nodes
    int length() {
        int countNodes = 0;
        if(this->isEmpty()) {
            return countNodes;
        } else {
            Node *currentNode = startingNode;
            while (currentNode != NULL)
            {
                currentNode = currentNode->nextNode;
                countNodes++;
            }
            return countNodes;
        }
    }

    //inserting at begining
    void insertAtHead(int data) {
        Node *newNode = new Node(data);

        if(this->isEmpty()) {
            startingNode = newNode;
        } else {
            newNode->nextNode = startingNode;
            startingNode = newNode;
        }
    }

    //insert at end
    void insertAtTail(int data) {
        Node *newNode = new Node(data);

        if(this->isEmpty()) {

            startingNode = newNode;
            cout << "Created List" << endl;

        } else {

            Node *currentNode = startingNode;

            while (currentNode->nextNode != NULL)
            {
                currentNode = currentNode->nextNode;
            }

            currentNode->nextNode = newNode;
        }
    }

    //insert at provided index
    void insertAt(int data, int index = 0) {
        if(index > this->length() || index < 0) {
            cout << "\nInvalid index" << endl;
            return;
        } else if(index == 0) {
            insertAtHead(data);
        } else if (index == this->length()) {
            insertAtTail(data);
        } else {
            Node *newNode = new Node(data);
            Node *currentNode = startingNode;
            for (int i = 0; i < index - 1; i++)
            {
                currentNode = currentNode->nextNode;
            }
            newNode->nextNode = currentNode->nextNode;
            currentNode->nextNode = newNode;  
        }
    }

    //delete data at begin
    int deleteAtHead() {
        int deletedData;
        if(this->isEmpty()) {
            cout << "\nList is already empty" << endl;
        } else if(this->length() == 1) {
            Node *currentNode = startingNode;
            deletedData = currentNode->data;
            startingNode = NULL;
            delete currentNode;
            return deletedData;
        } else {
            Node *currentNode = startingNode;
            startingNode = startingNode->nextNode;
            deletedData = currentNode->data;
            delete currentNode;
            return deletedData;
        }
    }

    //delete data/node at end
    int deleteAtTail() {
        int deletedData;
        if(this->isEmpty()) {
            cout << "\nList is already empty" << endl;
        } else if(this->length() == 1){
            Node *currentNode = startingNode;
            deletedData = currentNode->data;
            startingNode = NULL;
            delete currentNode;
            return deletedData;
        } else {
            Node *currentNode = startingNode;
            while (currentNode->nextNode->nextNode != NULL)
            {
                currentNode = currentNode->nextNode;
            }
            deletedData = currentNode->nextNode->data;
            currentNode->nextNode = NULL;
            delete currentNode->nextNode;
            return deletedData;
        }
    }

    //delete data/node at provided index
    int deleteAt(int index = 0) {
        int deletedData;
        // cout << this->length() << endl;
        if(this->isEmpty()) {
            cout << "\nList is already empty" << endl;
        } else if(index > this->length() - 1 || index < 0){
            cout << "\nInvalid index" << endl;
        } else if(index == 0) {
            deletedData = deleteAtHead();
            return deletedData;
        } else if(index == this->length() - 1) {
            deletedData = deleteAtTail();
            return deletedData;
        } else {
            Node *currentNode = startingNode;
            for (int i = 0; i < index - 1; i++)
            {
                currentNode = currentNode->nextNode;
            }
            Node *deletingNode = currentNode->nextNode;
            currentNode->nextNode = currentNode->nextNode->nextNode;
            deletedData = deletingNode->data;
            delete deletingNode;
            return deletedData;
        }
    }


    //for printing the list
    void print() {

        if(this->isEmpty()) {
            cout << "\n[]" << endl;
            return;
        } else {
            Node *currentNode = startingNode;
            while (currentNode != NULL)
            {
                cout << currentNode->data << " ";
                currentNode = currentNode->nextNode;
            }
            cout << endl;
        }

    }
};


int main() {

    LinkedList list;

    list.print();

    return 0;
}



/*
DOCUMENTATION: (Explanation)

PREQUISITS:
1) OOP concept
    - Class
    - Methods
    - Object creation
    - Constructors

So the main idea of linked list to link the Nodes with each other
Here A node represent a block of data

 ------------------------------------------
|     DATA     |  address of new/next node |
 ------------------------------------------

---------------------------------------------------------------------------------------------------------------
1) To repesent a node we need a 'DATA' and a self referencing 'POINTER'

class Node {
    public:

    int data;
    Node *nextNode;
};

Then we need a constructor to make what we call a "default object"
How we do that?

class Node {
    public:

    int data;
    Node *nextNode;

    Node(int userData) {
        this->data = userData;
        this->nextNode = NULL;
    }
};

---------------------------------------------------------------------------------------------------------------
After constructing the Node we need to contruct the linked-list now

class LinkedList {
    private:
    Node *head;

    public:
    LinkedList() {
        head = NULL;
    }

};

---------------------------------------------------------------------------------------------------------------
now we want is we need to insert at Head

for this first we need:
    - To check if the list is empty or not? if Yes:
        - then point the head towards this newly created node;
    - else:
        - we have to first point the newly created node to the head so that it get's linked to the list
          and then we can change the head pointer to this newly created node;


Psuedo code:

void insertAtHead() {
    create new node;

    if(list is empty) {
        - point head towards newly created node;
    } else {
        - first link newly created node towards head;
        - now change head to this newly created node;
    }
}

code:

void insertAtHead(int data) {
    Node *new_node = new Node(data);

    if(this->isEmpty()) {
        head = new_node;
    } else {
        new_node->nextNode = head;
        head = new_node;
    }
}

---------------------------------------------------------------------------------------------------------------
Now insert at tail
Since we want to add the node to end we have to traverse
the list till we reach to end then we can add the newly created node

psuedo code:

void insertAtTail(int data) {
    Create a node first;

    if(list is empty) {
        - point the head towards newly created node;
    } else {
        - traverse till last node
        - then add node
    }
}


code:

void insertAtTail(int data) {
    Node *new_node = new Node(data);

    if(this->isEmpty()) {
        head = new_node;
    } else {
        Node *current_node = head;

        while(current_node->nextNode != NULL) {
            current_node = current_node->nextNode;
        }

        current_node->next = new_node;
    }
}
---------------------------------------------------------------------------------------------------------------
What if we want to insert a node in a specific index? How do we do that?

Logic:
    if (indexProvided is greater than list.length() OR indexProvided is less than 0th index):
        - then user has obviously entered wrong index, so we throw err.
    
    else if (index == 0):
        - then user want to add node at head, so we can use the insertAtHead() logic right?
    
    else if (index == list.length()):
        - then user want to add node at tail, so we can use the insertAtTail() logic.
    
    else user is trying to add the data between head and tail so:
        - make a current pointer from the starting node and traverse till the index
        - the first link the newly node to the current pointer's next node;
        - link the current node to new node;
    

pseudo code:

void insertAt(int data, int index) {
    if(index > this->length() || index < 0){
        cout << "Invalid index" << endl;
    } else if(index == 0) {
        - Then the user want to add the data at 0th index
        - insertAtHead(data);
    } else if (index == this->length()) {
        
    } else {

    }
}


*/