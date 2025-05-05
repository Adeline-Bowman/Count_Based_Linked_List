# Self-Organizing Linked List for Terminal Command Suggestions

## Introduction
This project explores a **self-organizing linked list** to improve efficiency in command-line interfaces. The idea is that terminals should intelligently **adapt to user behavior**, learning command patterns over time. Instead of prioritizing **recency**, this implementation focuses on **frequency**, ensuring frequently used commands stay easily accessible.

Most systems reorder based on **recent usage**, but **count-based self-organizing lists** offer a better experience when multiple users interact with a terminal. This project builds upon traditional linked lists and adds **decay mechanisms**, ensuring older commands gradually lose priority to maintain relevance.

## Core Approach
The core data structure is a **self-organizing singly linked list**. Each **node** represents a command and tracks:
- **Command string** (`command`)
- **Usage count** (`useCount`)
- **Last usage timestamp** (`timeSinceUse`)

Every time a command is accessed:
1. **Usage count increases**.
2. **Decay function applies**, gradually reducing the count if unused.
3. **Reordering occurs**, moving higher-frequency commands to the front using insertion sort.

This ensures **adaptive command suggestions** without permanent ranking dominance.

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


