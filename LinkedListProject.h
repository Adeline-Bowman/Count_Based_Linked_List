#ifndef LINKEDLISTPROJECT_H__
#define LINKEDLISTPROJECT_H__

#include <memory>
#include <string>

using namespace std;

// Node structure representing each command in the linked list.
struct node {
  string command;   // Stores the command string.
  int useCount;     // Tracks how many times the command has been used.
  int timeSinceUse; // Tracks time since last use (used for decay mechanism).
  node* next;       // Pointer to the next node, or nullptr if this is the last node.
  node* prev;       // Pointer to the previous node (used for doubly linked list).
  bool accessed;    // Indicates whether the command was accessed recently.
};

// Linked List Invariant: Traversing via 'next' links should always reach a
// nullptr reference, ensuring no circular references exist.

class LinkedListCountBased {
public:
  // Constructor: Initializes class variables and pointers.
  LinkedListCountBased();

  // Destructor: Frees allocated memory for all nodes.
  ~LinkedListCountBased();

  // Creates a new node with a given command and returns a pointer to it.
  node* init_node(string command);

  // Returns a space-separated string of all commands from top to bottom.
  string report();

  // Appends a node with a given command to the end of the linked list.
  void append_command(string command);

  // Appends an existing node to the end of the list.
  void append(node* new_node);

  // Inserts a new node with a given command at the specified offset.
  void insert_data(int offset, string command);

  // Inserts an existing node at the specified offset within the list.
  void insert(int offset, node* newNode);

  // Removes the node at the specified offset and frees its memory.
  // If the offset is invalid, no action is taken.
  void remove(int offset);

  // Returns the total number of nodes in the linked list.
  int size();

  // Checks if the list contains a node with the specified command.
  bool contains(string command);

  // Returns the top pointer (head) of the linked list.
  node* get_top();

  // Sets a given node as the top pointer of the linked list.
  void set_top(node* top_ptr);

  // Applies exponential decay to `useCount` values over time.
  void decay();

  // Reorganizes the list based on `useCount`, moving frequently used commands forward.
  void reorganize();

  // Updates the use count of a command, creating a new node if it doesn't exist.
  void updateCount(string command);

private:
  node* top_ptr_;      // Pointer to the first node in the list.
  int decayThreshold;  // Threshold for applying decay to command frequency.
  int size_;           // Tracks the total number of nodes in the list.
  // Optionally add: node* tailPtr to optimize append operations.
};

#endif // LINKEDLISTPROJECT_H__