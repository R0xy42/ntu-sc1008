
# SC1008 C++ Mock Quiz Answer Key

---

## Mock Quiz A - MCQ Answers

1. B
2. B
3. C
4. B
5. B
6. C
7. B
8. C
9. C
10. B
11. B
12. C
13. B
14. B
15. B
16. B
17. B
18. B
19. B
20. C
21. B
22. C
23. B
24. B
25. C
26. B
27. A
28. B
29. C
30. B

### Mock Quiz A - Coding Reference Answers

31. Get Nth Node Value
```cpp
int getNthNodeValue(const MarkNode* head, int n) {
    const MarkNode* cur = head;
    int count = 1;

    while (cur != nullptr) {
        if (count == n) {
            return cur->mark;
        }
        cur = cur->next;
        ++count;
    }
    return -1;
}
```

32. Delete All Occurrences
```cpp
void deleteAllOccurrences(StringNode*& head, const string& target) {
    while (head != nullptr && head->name == target) {
        StringNode* garbage = head;
        head = head->next;
        delete garbage;
    }

    StringNode* cur = head;
    while (cur != nullptr && cur->next != nullptr) {
        if (cur->next->name == target) {
            StringNode* garbage = cur->next;
            cur->next = cur->next->next;
            delete garbage;
        } else {
            cur = cur->next;
        }
    }
}
```

33. Deep Copy Class
```cpp
class ScoreList {
private:
    int* data;
    int size;

public:
    ScoreList(int n) : size(n) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = 0;
        }
    }

    ScoreList(const ScoreList& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    ~ScoreList() {
        delete[] data;
    }

    void set(int index, int value) {
        data[index] = value;
    }

    int get(int index) const {
        return data[index];
    }
};
```

34. Frequency Counter
```cpp
#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

map<string, int> countWords(const vector<string>& words) {
    map<string, int> freq;
    for (size_t i = 0; i < words.size(); ++i) {
        freq[words[i]]++;
    }
    return freq;
}

int main() {
    vector<string> words = {"apple", "banana", "apple", "cat"};
    map<string, int> freq = countWords(words);

    map<string, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); ++it) {
        cout << it->first << " -> " << it->second << endl;
    }
    return 0;
}
```

---

## Mock Quiz B - MCQ Answers

1. B
2. B
3. B
4. B
5. A
6. C
7. B
8. B
9. A
10. A
11. B
12. C
13. B
14. B
15. A
16. A
17. C
18. B
19. A
20. C
21. B
22. A
23. C
24. C
25. A
26. B
27. B
28. C
29. A
30. B

### Mock Quiz B - Coding Reference Answers

31. Reverse Linked List
```cpp
void reverseLinkedList(StringNode*& head) {
    StringNode* prev = nullptr;
    StringNode* cur = head;

    while (cur != nullptr) {
        StringNode* nextNode = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextNode;
    }

    head = prev;
}
```

32. Insert at End
```cpp
void insertNodeAtEnd(IntNode*& head, int value) {
    IntNode* newNode = new IntNode;
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    IntNode* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = newNode;
}
```

33. Trace the Output
Output:
```txt
B D G d b
```
Without spaces:
```txt
BDGdb
```

Reason:
- `new Derived` constructs base first, then derived -> `BD`
- `p->f()` uses virtual dispatch -> `G`
- `delete p` with virtual destructor calls derived destructor first, then base destructor -> `db`

34. Generic Maximum
```cpp
template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}
```

Example use:
```cpp
cout << myMax(3, 7) << endl;
cout << myMax(2.5, 1.8) << endl;
```

---

## High-Yield Reminders

### 1. Initializer list vs assignment
`A(int x) : data(x) {}` initializes `data`.
Doing `data = x;` in the constructor body means `data` was already initialized before assignment.

### 2. Construction / destruction order
- construction: base first, then derived
- destruction: derived first, then base
- member objects are constructed before the constructor body runs

### 3. Shallow vs deep copy
For raw owning pointers:
- shallow copy -> copy address only
- deep copy -> allocate new memory and copy values

### 4. Overloading vs overriding vs hiding
- overloading: same name, different parameter list, same scope
- overriding: base function is virtual, same signature in derived
- hiding/redefining: derived declares same function name and hides base overloads by name lookup

### 5. STL iterator basics
- dereference current element: `*it`
- increment iterator: `++it`
- common range: `[begin(), end())`

### 6. map iterator
For `map<string, int>::iterator it`:
- `it->first` is key
- `it->second` is value

### 7. list vs vector
- `vector`: contiguous storage, fast random access, cheap push_back
- `list`: doubly linked list, no random access by index, cheap insert/erase when position is known

### 8. Linked list deletion
Before deleting a node, preserve the needed links first.
After `delete`, do not access that node again.
