#include "LinkedListProject.h"

// Constructor: Initializes class variables and pointers.
LinkedListCountBased::LinkedListCountBased() : top_ptr_(nullptr), size_(0), decayThreshold(10) {
}

// Destructor: Frees allocated memory by traversing the list.
LinkedListCountBased::~LinkedListCountBased() {
    node* current = top_ptr_;
    while (current != nullptr) {
        node* next = current->next;
        delete current;
        current = next;
    }
}

// Creates a new node with a given command.
node* LinkedListCountBased::init_node(string command) {
    node* newNode = new node{command, 1, 0, nullptr, nullptr, true};
    return newNode;
}

// Returns a space-separated string of all commands in the list.
string LinkedListCountBased::report() {
    string ret;
    node* current = top_ptr_;
    while (current != nullptr) {
        ret += current->command + " ";
        current = current->next;
    }
    return ret;
}

// Creates and appends a new node with a given command.
void LinkedListCountBased::append_data(string command) {
    node* newNode = init_node(command);
    append(newNode);
}

// Appends a new node to the end of the list.
void LinkedListCountBased::append(node* newNode) {
    if (top_ptr_ == nullptr) {
        top_ptr_ = newNode;
    } else {
        node* current = top_ptr_;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    size_++;
}

// Inserts a new node at a given offset.
void LinkedListCountBased::insert(int offset, node* newNode) {
    if (offset < 0 || offset > size_) {
        return;
    }

    if (offset == 0) { // Insert at the beginning.
        newNode->next = top_ptr_;
        if (top_ptr_) {
            top_ptr_->prev = newNode;
        }
        top_ptr_ = newNode;
    } else {
        node* current = top_ptr_;
        for (int i = 0; i < offset - 1 && current != nullptr; ++i) {
            current = current->next;
        }

        if (current == nullptr) {
            append(newNode);
        } else {
            newNode->prev = current;
            newNode->next = current->next;
            if (current->next) {
                current->next->prev = newNode;
            }
            current->next = newNode;
        }
    }
    size_++;
}

// Removes a node at a given offset.
void LinkedListCountBased::remove(int offset) {
    if (offset < 0 || offset >= size_ || top_ptr_ == nullptr) {
        return;
    }

    node* current = top_ptr_;
    if (!current) return;  // Fix: Prevent dereferencing nullptr

    if (offset == 0) { // Remove first node.
        top_ptr_ = top_ptr_->next;
        if (top_ptr_) {
            top_ptr_->prev = nullptr;
        }
        delete current;
    } else {
        for (int i = 0; i < offset && current != nullptr; ++i) {
            current = current->next;
        }
        
        if (!current) return;  // Fix: Ensure valid access before deletion

        if (current->prev) {
            current->prev->next = current->next;
        }
        if (current->next) {
            current->next->prev = current->prev;
        }
        delete current;
    }
    size_--;
}

// Checks if the list contains a node with a given command.
bool LinkedListCountBased::contains(string command) {
    node* current = top_ptr_;
    while (current != nullptr) {
        if (current->command == command) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Updates the use count of a command and reorganizes the list if needed.
void LinkedListCountBased::updateCount(string command) {
    node* current = top_ptr_;
    while (current) {
        if (current->command == command) {
            current->useCount++;
            return;
        }
        current = current->next;
    }
    append_data(command);
    reorganize(); // Ensure sorting happens after addition.
}

// Applies exponential decay to use counts.
void LinkedListCountBased::decay() {
    node* current = top_ptr_;
    while (current) {
        current->useCount = static_cast<int>(current->useCount * 0.9);
        current = current->next;
    }
}

// Reorganizes the list based on use count using insertion-based sorting.
void LinkedListCountBased::reorganize() {
    if (top_ptr_ == nullptr || top_ptr_->next == nullptr) {
        return;
    }

    node* current = top_ptr_->next;
    while (current) {
        node* nextNode = (current) ? current->next : nullptr; // Fix: Ensure nextNode is initialized safely

        // Find the correct position to move current node forward.
        node* temp = (current->prev) ? current->prev : nullptr; // Fix: Ensure temp is initialized safely
        while (temp && temp->useCount < current->useCount) {
            temp = temp->prev;  // Move backward until correct position is found.
        }

        // Remove current node from its original position.
        if (current->prev) {
            current->prev->next = current->next;
        }
        if (current->next) {
            current->next->prev = current->prev;
        }

        // Insert current node in the new position.
        if (temp == nullptr) { // Move to front.
            current->next = top_ptr_;
            top_ptr_->prev = current;
            top_ptr_ = current;
            current->prev = nullptr;
        } else { // Insert after `temp`.
            current->next = temp->next;
            current->prev = temp;
            if (temp->next) {
                temp->next->prev = current;
            }
            temp->next = current;
        }

        current = nextNode; // Move to the next node safely.
    }
}

// Returns the total number of nodes in the linked list.
int LinkedListCountBased::size() {
    return size_; // Directly use tracked `size_` instead of recalculating.
}

// Returns the top pointer of the list.
node* LinkedListCountBased::get_top() {
    return top_ptr_;
}

// Sets the given pointer as the top pointer.
void LinkedListCountBased::set_top(node* top_ptr) {
    top_ptr_ = top_ptr;
}