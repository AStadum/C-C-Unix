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
    tail = NULL;
    temp = NULL;        // Initialize all pointers to null
    entry = NULL;
    current = NULL;
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

    entry = new node;
    entry->next = NULL;
    entry->prev = NULL;        // Create a new node that holds the new player
    entry->player = name;

    if(head == NULL){          // Check: list is empty, new node becomes the head 
        head = entry;          // of the list.
        head->next = NULL;
        head->prev = NULL;
        tail = head;
        entry = NULL;
        numberOfNodes++;
        delete entry;
        
    }
    else if(head != NULL){   // Check: list already exists, add node to the end
        tail->next = entry;  // of the list.
        entry->prev = tail;
        tail = entry;
        tail -> next = NULL;
        entry = NULL;
        numberOfNodes++;
        delete entry;
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

    Player nullObj("empty");  // Since this function returns a Player object,
    if(head == NULL){                    // and it is not possible to return NULL for this
                                        // reason, we must create a "dummy" node to return
        return nullObj;                 // to prompt the user.
    }
     

     else if(head != NULL && head-> next == NULL){      // Check: Just the head node exists;
        temp = head;                                   // delete node and free variables.
        Player tempPlayer = temp->player;        // The problem occurred because temp was not being
        head->next = NULL;
        head->prev = NULL;
        head = NULL;                               // I ran into a problem here with memory leaks.       
        numberOfNodes--;
        delete temp;                            // freed. To fix the problem I created a temporary
        return tempPlayer;                        // player object to hold what will be returned, and
    }                                            // follow by deleting temp.


    else if(head != NULL && head->next != NULL){   // Check: list already exists, remove from head
        temp = head;
        head = head->next;
        temp->prev = NULL;
        temp->next = NULL;
        head->prev = NULL;
        numberOfNodes--;
        Player tempPlayer = temp->player;        // Using another temp object for reasons stated
        delete temp;                            // above.
        return tempPlayer;
    } 
    return nullObj;
}
/* The removeHelper() function searches throughout the list and 
*  checks each player's name against the user input parameter.
*  If the player is in the list, it returns true.
*  If the player is not in the list, it will return false.
*/
bool PlayerQueue::removeHelper(std::string playerName){

    temp = head;
    while(temp != NULL){
        if(temp->player.getName() == playerName)
            return true;
        temp = temp->next;
    }
    return false;
}

/* The removeKey() function uses removeHelper() to determine
*  whether the node that the user wishes to delete is already
*  in the list. The presence of findPlayer() and removeKey() give
*  this implementation into a double-linked priority queue.
*/ 
Player PlayerQueue::removeKey(std::string playerName){

    if(removeHelper(playerName)){      // Check if the player is in the list

        if(numberOfNodes == 1){
                                               // If so, create a temp pointer, fix the
            Player tempPlayer = temp->player;  // hole in the chain, and return the player
            numberOfNodes--;                  // accordingly.
            delete temp;
            head = NULL;
            return tempPlayer;
        }
        else if(numberOfNodes ==2){
            if(temp == head){
                Player tempPlayer = temp->player;
                head = tail;
                tail->prev = NULL;
                numberOfNodes--;
                delete temp;
                return tempPlayer;
            }
            else if(temp == tail){
                Player tempPlayer = temp->player;
                tail = head;
                head->next = NULL;
                numberOfNodes--;
                delete temp;
                return tempPlayer;
            }

        }
        else if(numberOfNodes >2 && temp!=tail&& temp!=head){   // Middle of the list
            Player tempPlayer = temp->player;
            nodePtr x = temp->prev;
            x->next = temp->next;
            temp->next->prev = x;        
            numberOfNodes--;
            delete temp;
            return tempPlayer;
        }
        else if(numberOfNodes >2 && temp == head){   // Big list, deleting head
            Player tempPlayer = temp->player;
            head = head->next;
            head->prev = NULL;
            numberOfNodes--;
            delete temp;
            return tempPlayer;
        }
        else if(numberOfNodes >2 && temp == tail){
            Player tempPlayer = temp->player;
            tail = tail->prev;
            tail->next = NULL;
            numberOfNodes--;
            delete temp;
            return tempPlayer;
        }

        //std::cout<<"Removekey if statement worked"<<std::endl;
        //delete temp;
       // return tempPlayer;
    }
    Player nullObject("Player not in the queue.");  // If not then return a null object.
    return nullObject;
}

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

bool PlayerQueue::isEmpty(){
    if(numberOfNodes <=0)
        return true;
    else return false;
}

int PlayerQueue::getSize(){
    return numberOfNodes;
}
/*Prints head and tail player values. */
void PlayerQueue::testPrint(){

     std::cout<<"(test print)Head: "<< head->player.getName()<<std::endl;
     std::cout<<"(test print)Tail: "<<tail->player.getName()<<std::endl;
    
}

nodePtr PlayerQueue::getHead()
{
    if(head != NULL)
        return head;
    else
        return NULL;
}

nodePtr PlayerQueue::getTail()
{
    if(tail != NULL)
        return tail;
    else
        return NULL;
}

void PlayerQueue::dumpQueue(){

    nodePtr i = head;
    
    while (i != NULL) {
        head = head-> next;
        delete i;
        i = head;
    }
    head = tail = NULL;
    numberOfNodes = 0;
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
