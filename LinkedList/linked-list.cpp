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

class LinkedList {
    private:
    Node *startingNode;

    public:
    LinkedList() {
        startingNode = NULL;
    }

    void insertAtHead(int data) {

    }

    void insertAtTail(int data) {
        //POINT 1) We have a list like:
        //1 -> 2 -> 3 -> NULL

        //So appending the node means in the last

        //POINT 2) first create a node;
        Node *newNode = new Node(data);

        //POINT 3) and check if the list is empty
        //how we will check? by checking if the starting node is empty or not
        if(startingNode == NULL) {
            startingNode = newNode;
            cout << "Created List" << endl;
        } else {
            //POINT 4) else we can point a pointer to the starting node and then
            //we will make it move till last node
            Node *currentNode = startingNode;

            while (currentNode->nextNode != NULL)
            {
                currentNode = currentNode->nextNode;
            }
            //after we have reached till last node we can then change the
            //address of the last node, by pointing it to newly created node
            currentNode->nextNode = newNode;
        }
    }

    void print() {
        Node *currentNode = startingNode;
        while (currentNode != NULL)
        {
            cout << currentNode->data << " ";
            currentNode = currentNode->nextNode;
        }
        cout << endl;
    }
};

int main() {

    LinkedList list;

    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtTail(40);
    list.insertAtTail(50);

    list.print();

    return 0;
}