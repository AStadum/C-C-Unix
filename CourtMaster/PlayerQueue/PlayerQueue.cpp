// Author: Grant Harris

#include "PlayerQueue.h"
#include <string>
#include <iostream>

/*The PlayerQueue is used to hold a number of Player objects -- these
* represent the players waiting to play. Since any number of players    
* may sign up at one time, I used a dynamic data structure-- the linked
* list. The list is made up of node structs which hold pointers to next
* and previous nodes as well as Player objects.
*
* typedef: node* = nodePtr
*/
PlayerQueue::PlayerQueue():numberOfNodes(0){
    head = NULL;
    tail = NULL;        // Constructor
    temp = NULL;        // Initialize all pointers to null
    entry = NULL;
}

/* Increments through the list, printing Player names using
 * functions from the Player class.*/ 
void PlayerQueue::printQueue(){
    temp = head;
    std::cout<<std::endl;

    while(temp !=NULL){
        std::cout<< temp-> player.getName() <<"  ";
        temp = temp->next;
    }
    std::cout<<std::endl;
}

/* This list implements an abstract data type, the priority queue.
*  The enqueue() function adds a player to the end of the queue.
*  Queues operate in a first-in first-out manner.
*/
void PlayerQueue::enqueue(Player name){

    entry = new node;           // Create a new node that holds the new player
    entry->next = NULL;         // The new node floats around, unconnected to anything
    entry->prev = NULL;        
    entry->player = name;       

    if(head == NULL){           // Check: list is empty, new node becomes the head 
        head = entry;           // of the list.
        head->next = NULL;
        head->prev = NULL;      // New head points to nothing, it is the lone node
        tail = head;
        entry = NULL;
        numberOfNodes++;        // Increment number of nodes
        delete entry;           // We used "new" keyword, we must deallocate memory
        
    }
    else if(head != NULL){      // Check: list already exists, add node to the end
        tail->next = entry;     // of the list.
        entry->prev = tail;     // Update head and tail pointers
        tail = entry;
        tail -> next = NULL;
        entry = NULL;
        numberOfNodes++;        // Increment number of nodes
        delete entry;           // Deallocate memory to avoid leaks
    }
    delete entry;            // free node pointer
}

/* The queue works as a first-in first-out data type.
*  Dequeue first checks if the list is empty or not;
*  if the list is not empty, then the dequeue() function
*  removes one node from the head of the list, returning
*  the player object the node held.
*/
Player PlayerQueue::dequeue(){

    Player nullObj("empty");        // Since this function returns a Player object,
    if(head == NULL){               // and it is not possible to return NULL for this
                                    // reason, we must create a "dummy" node to return
        return nullObj;             // to prompt the user.
    }
     

     else if(head != NULL && head-> next == NULL){      // Check: Just the head node exists;
        temp = head;                                    // delete node and free variables.
        head->next = NULL;
        head->prev = NULL;
        head = NULL;                        // I ran into a problem here with memory leaks.       
        Player tempPlayer = temp->player;   // The problem occurred because temp was not being
        numberOfNodes--;                    // freed. To fix the problem I created a temporary
        delete temp;                        // player object to hold what will be returned, and
        return tempPlayer;                  // followed by deleting temp.  
    }                                            


    else if(head != NULL && head->next != NULL){   // Check: list already exists, remove from head
        temp = head;
        head = head->next;                  // Update head pointer
        temp->prev = NULL;                  // Isolate temp
        temp->next = NULL;
        head->prev = NULL;
        numberOfNodes--;                    // Decrement number of nodes
        Player tempPlayer = temp->player;   // Use temporary object for reasons stated
        delete temp;                        // above.
        return tempPlayer;
    } 
    return nullObj;                         // No list exists -- return "NULL"
}
/* The removeHelper() function searches throughout the list and 
*  checks each player's name against the user input parameter.
*  If the player is in the list, it returns true.
*  If the player is not in the list, it will return false.
*  This function is used in conjunction with removeKey.
*  This function uses "temp" to hold the value to be deleted.
*  For this reason, removeHelper is never called alone -- it 
*  would create a memory leak. The leak is taken care of in removeKey().
*/
bool PlayerQueue::removeHelper(std::string playerName){

    temp = head;                                        // Global pointer temp set to head
    while(temp != NULL){                                // Traverse the list
        if(temp->player.getName() == playerName) // If the player exists, then
            return true;                         // temp is set to this player.
        temp = temp->next;
    }
    return false;
}

/* The removeKey() function uses removeHelper() to determine
*  whether the node that the user wishes to delete is already
*  in the list. The presence of removeHelper() and removeKey() turn
*  this implementation into a double-linked priority queue.
*/ 
Player PlayerQueue::removeKey(std::string playerName){

    if(removeHelper(playerName)){       // Check if the player is in the list

        if(numberOfNodes == 1){         // Just the head node exists, delete node
                                               
            Player tempPlayer = temp->player;   // Create a temporary class to hold data
            numberOfNodes--;                    // Decrement number of nodes
            delete temp;                        // Delete temp. * Prevents mem leaks
            head = NULL;
            return tempPlayer;                  // Return deleted player
        }
        else if(numberOfNodes ==2){             // 2 nodes exist
            if(temp == head){                   // Check if the node to be deleted is the head
                Player tempPlayer = temp->player;
                head = tail;                    // Set the new head and tail
                tail->prev = NULL;              // Decrement number of nodes
                numberOfNodes--;                // Return deleted player
                delete temp;
                return tempPlayer;
            }
            else if(temp == tail){              // Check if the node to be delete is the tail
                Player tempPlayer = temp->player;
                tail = head;                    // Set new head and tail
                head->next = NULL;              
                numberOfNodes--;                // Decrement number of nodes
                delete temp;                    // Delete temp and return the player
                return tempPlayer;
            }

        }
        else if(numberOfNodes >2 && temp!=tail&& temp!=head){   // Node is in the middle of list
            Player tempPlayer = temp->player;           // Create temporary player to hold data
            nodePtr x = temp->prev;                     // Create temp node pointer
            x->next = temp->next;                       // Fixing the link in the chain
            temp->next->prev = x;                         
            numberOfNodes--;                            // Decrement number of nodes
            delete temp;                                // Delete temp to avoid mem leaks
            return tempPlayer;                          // Return deleted player
        }
        else if(numberOfNodes >2 && temp == head){      // Big list, deleting head
            Player tempPlayer = temp->player;           // Create temporary player to hold data
            head = head->next;                          // Update head
            head->prev = NULL;                          
            numberOfNodes--;                            // Decrement number of nodes
            delete temp;                                // Delete temp to avoid mem leaks
            return tempPlayer;                          // Return deleted player
        }
        else if(numberOfNodes >2 && temp == tail){      // Big list, deleting tail
            Player tempPlayer = temp->player;           // Create temporary player
            tail = tail->prev;
            tail->next = NULL;                          // Update tail
            numberOfNodes--;                            // Decrement number of nodes
            delete temp;
            return tempPlayer;                          // Avoid mem leaks and return deleted player
        }
    }
    Player nullObject("Player not in the queue.");  // Create and return a "null" object to 
    return nullObject;                              //  prompt user that the object was not there. 
}

/* The findPlayer() function increments through the linked list
*  and searches the name of each player within the list.
*  If the player is found, return true. Else return false. */
bool PlayerQueue::findPlayer(std::string playerName){   
    temp = head;

    while(temp != NULL){
        if(temp->player.getName() == playerName){
            return true;
        }
        temp = temp->next;
    }
    temp = NULL;
    return false;
}

/* isEmpty() uses the numberOfNodes variable to determine if 
*  any number of nodes exist. If the list is empty, return true.
*  Else return false. */
bool PlayerQueue::isEmpty(){
    if(numberOfNodes <=0)
        return true;
    else return false;
}

/* getSize() returns the numberOfNodes variable */
int PlayerQueue::getSize(){
    return numberOfNodes;
}
/*Prints head and tail player values. */
void PlayerQueue::testPrint(){

    if(numberOfNodes >0){
     std::cout<<"Head: "<< head->player.getName()<<std::endl;
     std::cout<<"Tail: "<<tail->player.getName()<<std::endl;
    }
}

/* Returns the address value of the pointer to the head
*  of the linked list. */
nodePtr PlayerQueue::getHead()
{
    if(head != NULL)
        return head;
    else
        return NULL;
}

/* Returns the address value of the pointer to the tail
*  of the linked list. */
nodePtr PlayerQueue::getTail()
{
    if(tail != NULL)
        return tail;
    else
        return NULL;
}

/* The dumpQueue() function runs though the list and deletes
*  all of the nodes. It then resets the head and tail pointer 
*  values to NULL. */
void PlayerQueue::dumpQueue(){

    nodePtr i = head;       // Create temporary node pointer
    
    while (i != NULL) {     // Search each node in the list
        head = head-> next; // Delete the current node and move
        delete i;           //  to the next
        i = head;
    }
    head = tail = NULL;
    numberOfNodes = 0;
    delete i;
}
/*Iterates through the linked list, deleting nodes. Used by the
* destructor.*/
void PlayerQueue::freePointers(nodePtr link){
    
    while (link){
        nodePtr old = link;
        link = link->next;
        old->next = NULL;
        delete old;
    }
}

/*Dtor*/
PlayerQueue::~PlayerQueue(){
    freePointers(this->head);
}