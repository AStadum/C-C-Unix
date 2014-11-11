#ifndef __PLAYERQUEUE_H__
#define __PLAYERQUEUE_H__

#include "Player.h"



typedef struct node
    {    
        Player player;  // The node struct holds player objects and
        node* next;        // contains pointers to point to other adjacent
        node* prev;        // nodes within the linked list. 
    }* nodePtr;
    

class PlayerQueue
{
    
private:
    
    nodePtr head;
    nodePtr tail;
    nodePtr temp;
    nodePtr entry;
    nodePtr current;
    int numberOfNodes;
public:
    PlayerQueue();  // Ctor
    ~PlayerQueue(); // Dtor

    void enqueue(Player name); // Add player
    Player dequeue();           // Remove player

    bool findPlayer(std::string playerName);  // Find player; used by removeKey
    bool removeHelper(std::string playerName);
    Player removeKey(std::string playerName); // Find and remove specified player
    bool isEmpty();
    int getSize();
    void printQueue();        // Print queue to console
    void testPrint();        // Prints just head and tail players
    void freePointers(nodePtr link); // Used by Dtor, frees allocated memory
    void dumpQueue();
    nodePtr getHead();
    nodePtr getTail();
};

#endif

