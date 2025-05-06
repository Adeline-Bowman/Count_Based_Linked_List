#include "LinkedListProject.h"
#include <iostream>

void runTests() {
    LinkedListCountBased list;

    // Test: Append commands
    std::cout << "Appending commands...\n";
    list.append_command("git status");
    list.append_command("git commit -m 'Initial commit'");
    list.append_command("git push origin main");
    std::cout << "Report: " << list.report() << "\n";

    // Test: Check contains function
    std::cout << "Checking if 'git status' exists...\n";
    std::cout << (list.contains("git status") ? "Exists\n" : "Not found\n");

    // Test: Remove a command
    std::cout << "Removing 'git commit -m 'Initial commit''...\n";
    list.remove(1);
    std::cout << "Report after removal: " << list.report() << "\n";

    // Test: Size function
    std::cout << "List size: " << list.size() << "\n";

    // Test: Update use count
    std::cout << "Updating use count for 'git status'...\n";
    list.updateCount("git status");
    list.updateCount("git status");
    list.updateCount("git push origin main");

    // Print use counts
    std::cout << "Use counts after updates:\n";
    node* current = list.get_top();
    while (current) {
        std::cout << current->command << " (use count: " << current->useCount << ")\n";
        current = current->next;
    }

    // Test: Apply decay
    std::cout << "Applying decay...\n";
    list.decay();

    // Print use counts after decay
    std::cout << "Use counts after decay:\n";
    current = list.get_top();
    while (current) {
        std::cout << current->command << " (use count: " << current->useCount << ")\n";
        current = current->next;
    }

    // Test: Reorganize list based on use count
    std::cout << "Reorganizing list...\n";
    list.reorganize();
    std::cout << "Report after reorganization: " << list.report() << "\n";

    // Print final use counts after reorganization
    std::cout << "Final use counts after reorganization:\n";
    current = list.get_top();
    while (current) {
        std::cout << current->command << " (use count: " << current->useCount << ")\n";
        current = current->next;
    }
}

int main() {
    runTests();
    return 0;
}