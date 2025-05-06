# Self-Organizing Linked List for Terminal Command Suggestions

## Introduction
This project explores a **self-organizing linked list** to improve efficiency in command-line interfaces. The idea is that terminals should intelligently **adapt to user behavior**, learning command patterns over time. Instead of prioritizing **recency**, this implementation focuses on **frequency**, ensuring frequently used commands stay easily accessible.

Most systems reorder based on **recent usage**, but **count-based self-organizing lists** offer a better experience when multiple users interact with a terminal. This project builds upon traditional linked lists and adds **decay mechanisms**, ensuring older commands gradually lose priority to maintain relevance.

## **LinkedListCountBased Class**
### **Core Features**
- **Dynamic command tracking** using a **doubly linked list**.
- **Usage-based reorganization**: Frequently used commands move forward.
- **Exponential decay mechanism**: Reduces usage counts over time.
- **Efficient insertion, deletion, and lookup operations**.

### **Operations**
- **`append_command(string command)`**  
  Adds a new command to the end of the list.

- **`insert_data(int offset, string command)`**  
  Inserts a new command at a specific position in the list.

- **`remove(int offset)`**  
  Deletes the command at the specified position.

- **`contains(string command)`**  
  Checks if a command exists in the list.

- **`report()`**  
  Returns a space-separated string of all commands in the list.

---

## **Command Tracking & Optimization**
### **Usage-Based Reorganization**
- **`updateCount(string command)`**  
  - Increases the usage count of a command.
  - If the command does not exist, it is added to the list.
  - The list is reorganized to prioritize frequently used commands.

### **Exponential Decay**
- **`decay()`**  
  - Reduces the `useCount` of all commands by **10%** over time.
  - Helps prevent stale commands from dominating the list.

---

## **Node Structure**
Each command is stored in a **node**, which contains:

```cpp
struct node {
  string command;   // Stores the command string.
  int useCount;     // Tracks how many times the command has been used.
  int timeSinceUse; // Tracks time since last use (used for decay mechanism).
  node* next;       // Pointer to the next node, or nullptr if this is the last node.
  node* prev;       // Pointer to the previous node (used for doubly linked list).
  bool accessed;    // Indicates whether the command was accessed recently.
};

```

## **Code Demonstration**
The test suite demonstrates the core functionalities of the linked list, including:
- **Appending commands**
- **Checking if a command exists**
- **Removing a command**
- **Updating command usage counts**
- **Applying decay to usage counts**
- **Reorganizing the list based on usage frequency**

### **Running the Test File**
 - To compile and run the test suite, follow these steps:
 - **Navigate to the directory where your test file is located**  
   -git clone "git@github.com:Adeline-Bowman/Count_Based_Linked_List.git"
 - **Compile the test file using g++**
   - g++ -I . test.cpp LinkedListProject.cpp -o test_linked_list
 - **Run the test executable**
   - ./test_linked_list

## Challenges
### 1. Implementing Exponential Decay
- Commands **lose priority** over time, preventing outdated usage patterns.
- Finding the **optimal decay rate** is key: too fast disrupts usability, too slow causes stagnation.

### 2. Maintaining Performance Efficiency
- A **self-organizing linked list** improves access time but increases **insertion/deletion costs**.
- The approach is most effective when **patterns are predictable**, but optimizing reordering remains a challenge.

## Why This Application?
While **self-organizing lists** are common, most implementations rely on:
- **Move-to-front (recency)** — good for immediate relevance but lacks long-term learning.
- **Transpose (bubble-up)** — limited ability to adapt to deeper command usage trends.

By combining **count-based ordering** with **decay mechanisms**, this project **learns from user behavior**. This approach is ideal for **terminal command suggestions**, balancing **frequency and recency**.

Real-world applications include:
- **GitHub submission workflows**, where repetitive commands become cumbersome.
- **Autocomplete systems**, improving personalized recommendations.


