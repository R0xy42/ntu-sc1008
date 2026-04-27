# SC1008 C++ Practical Coding Set 2

This set is designed to match the style of your uploaded lab `.cpp` files:
- linked list from scratch
- template + dynamic array
- map + iterators
- inheritance + polymorphism

Suggested timing:
- Q1: 20-25 min
- Q2: 15-20 min
- Q3: 15-20 min
- Q4: 20-25 min

---

## Q1. From scratch: Student Linked List Manager

Write a complete C++ program from scratch.

### Task
Create a singly linked list program that stores students. Each node contains:
- `int id`
- `string name`
- `StudentNode* next`

### You must implement
1. `appendNode(StudentNode*& head, int id, const string& name)`
2. `insertNodeAtPos(StudentNode*& head, int id, const string& name, int pos)`
   - `pos` is 1-indexed
   - if `pos <= 1`, insert at head
   - if `pos` is larger than the list length + 1, insert at end
3. `deleteByName(StudentNode*& head, const string& targetName)`
   - delete **all** nodes whose name equals `targetName`
4. `reverseList(StudentNode*& head)`
   - reverse the list in place
5. `printList(const StudentNode* head)`
   - output format: `(id, name) -> (id, name) -> NULL`
6. `freeList(StudentNode*& head)`

### Menu
Your program should repeatedly process commands:
- `1` Append node
- `2` Insert node at position
- `3` Delete all nodes by name
- `4` Reverse list
- `5` Print list
- `6` Exit

### Example interaction
Not fixed exactly, but the logic should behave like this:

```text
1) Append Node
2) Insert Node At Position
3) Delete All Nodes By Name
4) Reverse List
5) Print List
6) Exit
Enter command:
```

### What this question is testing
- head update via `Node*&`
- insertion and deletion edge cases
- keeping the list connected
- safe deletion
- three-pointer reversal

---

## Q2. Starter code: Merge Two Sorted Arrays (Template)

This is a harder version of your `MergeArrays.cpp`.

### Task
Complete the TODO parts.

You must write:
1. a template function `mergeSortedArrays()` that merges two **already sorted** arrays into one new sorted array
2. a template function `printAndDeallocate()`

### Requirements
- both input arrays are sorted in ascending order
- allocate a new dynamic array of size `size1 + size2`
- use the standard two-pointer merge idea
- the merged result must stay sorted
- after printing, deallocate the merged array using `delete[]`

Use this starter file:
- `SC1008_Q2_MergeSortedArrays_Starter.cpp`

---

## Q3. Starter code: PhoneBook Plus with Prefix Search

This is a harder version of your `Phonebook.cpp`.

### Task
Complete the TODO parts inside class `PhoneBook`.

You must implement:
1. constructor
2. `addContact(const string& name, const string& number)`
3. `removeContact(const string& name)`
4. `findContact(const string& name) const`
   - return the phone number if found
   - otherwise return `"Not Found!"`
5. `displayAllContacts() const`
   - print all contacts in ascending key order
6. `displayContactsByPrefix(const string& prefix) const`
   - print only contacts whose names start with `prefix`
   - if none exists, print `No matched contact.`

### Notes
- use `map<string, string>`
- use iterators or range-based loop
- do not crash when the map is empty

Use this starter file:
- `SC1008_Q3_PhoneBookPlus_Starter.cpp`

---

## Q4. Starter code: Shape Collection with Polymorphism

This is an extended version of your `ShapeAreas.cpp`.

### Task
Complete the TODO parts.

You must implement:
1. abstract base class `Shape`
   - constructor
   - virtual destructor
   - pure virtual `calArea()`
   - virtual `getType() const`
2. derived class `Circle`
   - constructor
   - destructor
   - override `calArea()`
   - override `getType()`
3. derived class `Rectangle`
   - constructor
   - destructor
   - override `calArea()`
   - override `getType()`
4. derived class `Triangle`
   - constructor
   - destructor
   - override `calArea()` using `0.5 * base * height`
   - override `getType()`

### Output behavior
When command 4 is chosen:
- first call `calArea()` for every shape
- then print:

```text
Circle Area: ...
Rectangle Area: ...
Triangle Area: ...
```

### What this question is testing
- abstract classes
- constructor/destructor order
- overriding
- virtual dispatch through `Shape*`
- `vector<Shape*>`
- dynamic memory cleanup

Use this starter file:
- `SC1008_Q4_ShapeCollection_Starter.cpp`

