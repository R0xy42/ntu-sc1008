
# SC1008 C++ Mock Quiz Set
Based on your uploaded lecture slides and labs:
- Week 8: C++ basics
- Week 9: linked list
- Week 10: class and object
- Week 11: inheritance and polymorphism
- Week 12: templates and STL
- Labs on linked list, multiple inheritance, std::list

Use this like the real test:
- 90 minutes
- Closed book
- Try Mock A first under time pressure
- Use Mock B as a second full paper

---

## Mock Quiz A

### Part I - Multiple Choice (30 questions)

Choose ONE best answer.

1. Which statement about C++ references is correct?
   A. A reference can be reseated to refer to another variable later.
   B. A reference must be initialized when declared.
   C. A reference occupies no role in parameter passing.
   D. A reference always means dynamic memory.

2. Which declaration means "p is a pointer to a constant int"?
   A. `int * const p;`
   B. `const int * p;`
   C. `int & const p;`
   D. `int const & * p;`

3. Suppose `string s = "hello";`. What does `s.find('l')` return?
   A. The character `'l'`
   B. The number of occurrences of `'l'`
   C. The index of the first `'l'`
   D. A boolean

4. Which is the correct header for `std::string`?
   A. `#include <cstring>`
   B. `#include <string>`
   C. `#include <str>`
   D. `#include <iostream>`

5. What is the main purpose of a class?
   A. To guarantee dynamic allocation
   B. To define a user-defined type that bundles data and behavior
   C. To replace all structures in C++
   D. To avoid constructors

6. Which access specifier makes members accessible only inside the class and its friends?
   A. `public`
   B. `protected`
   C. `private`
   D. `virtual`

7. Which function is called automatically when an object is created?
   A. destructor
   B. constructor
   C. friend function
   D. overloaded operator

8. Which statement about constructors is correct?
   A. A constructor has a return type.
   B. A constructor name must be different from the class name.
   C. A constructor can be overloaded.
   D. A class can have many destructors.

9. Consider:
   ```cpp
   class A {
   public:
       A() { cout << "A"; }
       ~A() { cout << "~A"; }
   };
   int main() {
       A x;
   }
   ```
   What is printed?
   A. `A`
   B. `~A`
   C. `A~A`
   D. `~AA`

10. Which statement about initializer lists is correct?
    A. They run after the constructor body.
    B. They are used to initialize base classes and members before the constructor body.
    C. They are only for static members.
    D. They are identical to assignment inside the constructor body in all cases.

11. Which situation most clearly requires a user-defined copy constructor?
    A. A class only storing `int` and `double`
    B. A class containing a raw pointer owning dynamic memory
    C. A class with no data members
    D. A class with only `const` member functions

12. What is the problem with shallow copy for a class owning heap memory?
    A. It copies too slowly.
    B. It creates two independent deep copies.
    C. Multiple objects may point to the same memory and later double-delete.
    D. It disables operator overloading.

13. What does `this` point to inside a non-static member function?
    A. The class definition
    B. The current object
    C. The base-class object only
    D. The heap manager

14. Why is `operator<<` often implemented as a friend non-member function?
    A. Because `<<` can never be overloaded as a member
    B. Because the left operand is usually `ostream`
    C. Because friend functions are always virtual
    D. Because member functions cannot access `cout`

15. Which statement about friend functions is correct?
    A. A friend function is a member function of the class by default.
    B. A friend function can access private members of the class that declares it as friend.
    C. A friend function is inherited automatically.
    D. A friend function must be virtual.

16. In inheritance, a derived-class object is:
    A. unrelated to the base class
    B. a special kind of base-class object
    C. always larger than any base class
    D. forbidden from accessing inherited members

17. When a derived object is created, what is the constructor order?
    A. Derived first, then base
    B. Base first, then derived
    C. Member functions first, then base
    D. Random order chosen by compiler

18. When a derived object is destroyed, what is the destructor order?
    A. Base first, then derived
    B. Derived first, then base
    C. Only derived destructor runs
    D. Only base destructor runs

19. Which inherited members are directly accessible inside a derived class?
    A. Base `private` members
    B. Base `protected` and `public` members, subject to inheritance mode
    C. Only base `public` members
    D. Only base `private` members

20. A derived class declares a function with the same name as one in the base class but a different parameter list. This is primarily:
    A. overriding
    B. pure virtual dispatch
    C. function hiding / redefining by name
    D. multiple inheritance

21. Which case is true overriding?
    A. Same name, different parameters, base function non-virtual
    B. Same name, same parameters, base function virtual
    C. Different name, same return type
    D. Same scope, same name, different parameters

22. What is runtime polymorphism based on in this course?
    A. macros
    B. function overloading
    C. virtual functions
    D. templates only

23. Why should a polymorphic base class usually have a virtual destructor?
    A. To allow multiple inheritance
    B. To ensure correct derived destruction via a base pointer
    C. To make objects smaller
    D. To prevent slicing

24. What does `Base *p = new Derived; p->show();` require so that `Derived::show()` is called?
    A. `show()` must be `static`
    B. `show()` must be `virtual` in the base class
    C. `p` must be a reference
    D. `Derived` must have no constructor

25. What is object slicing?
    A. Splitting a vector into parts
    B. Deleting only part of an array
    C. Copying a derived object into a base object, losing the derived part
    D. Calling a destructor twice

26. A class containing at least one pure virtual function is:
    A. overloaded
    B. abstract
    C. final
    D. shallow-copied

27. Which template declaration is valid?
    A. `template <typename T> T maximum(T a, T b);`
    B. `typename <T> T maximum(T a, T b);`
    C. `template T maximum(T a, T b);`
    D. `class <T> T maximum(T a, T b);`

28. In `vector<int>::iterator it;`, what is `it`?
    A. an integer
    B. an iterator that can traverse a `vector<int>`
    C. a pointer to the whole vector object
    D. a map key

29. For STL algorithm ranges, `[begin, end)` means:
    A. both begin and end included
    B. begin excluded, end included
    C. begin included, end excluded
    D. both excluded

30. Which statement is correct?
    A. `std::list` supports random access with `operator[]`
    B. `std::vector` stores elements contiguously
    C. `std::map` allows duplicate keys by default
    D. `sort(v.begin(), v.end())` works on every possible container in the same way

### Part II - Coding (4 questions)

31. Linked List - Get Nth Node Value
Write the function:
```cpp
int getNthNodeValue(const MarkNode* head, int n);
```
Return the value stored in the nth node of a singly linked list.
- `n >= 1`
- If the list is too short or `head == nullptr`, return `-1`

Structure:
```cpp
struct MarkNode {
    int mark;
    MarkNode* next;
};
```

32. Linked List - Delete All Occurrences
Write the function:
```cpp
void deleteAllOccurrences(StringNode*& head, const string& target);
```
Delete all nodes whose `name == target` from a singly linked list.

Structure:
```cpp
struct StringNode {
    string name;
    StringNode* next;
};
```

Requirements:
- Correctly handle deleting from the head
- Correctly handle consecutive matching nodes
- Do not leak memory

33. OOP - Deep Copy Class
Complete a class `ScoreList` that owns a dynamic array:
```cpp
class ScoreList {
private:
    int* data;
    int size;
public:
    ScoreList(int n);
    ScoreList(const ScoreList& other);
    ~ScoreList();
    void set(int index, int value);
    int get(int index) const;
};
```
Requirements:
- Constructor allocates an array of size `n` and initializes all elements to `0`
- Copy constructor performs deep copy
- Destructor releases memory
- `set` and `get` assume valid index

34. Templates / STL - Frequency Counter
Write a function:
```cpp
map<string, int> countWords(const vector<string>& words);
```
Return a map storing the frequency of each word in the vector.

Then write code to print the result in the format:
```cpp
word -> count
```
using a map iterator.

---

## Mock Quiz B

### Part I - Multiple Choice (30 questions)

1. Which statement about pass-by-reference is true?
   A. It always creates a copy.
   B. It allows a function to modify the caller's variable.
   C. It works only for classes.
   D. It cannot be used with `const`.

2. Which function declaration promises not to modify the object?
   A. `void show();`
   B. `void show() const;`
   C. `const void show();`
   D. `void const show();`

3. Suppose `string s = "abcde";`. What does `s.substr(1, 3)` return?
   A. `"abc"`
   B. `"bcd"`
   C. `"cde"`
   D. `"bcde"`

4. Which stream object is commonly used for standard output?
   A. `cin`
   B. `cout`
   C. `cerrin`
   D. `getline`

5. Which is true about `new` and `delete`?
   A. Memory allocated with `new` should be released with `delete`
   B. Memory allocated with `new` should be released with `free`
   C. `delete` can be used on stack objects
   D. `new` cannot allocate arrays

6. Which of the following is NOT a valid reason to write a destructor?
   A. To release dynamically allocated memory owned by the object
   B. To print tracing information for learning constructor/destructor order
   C. To return an integer status code
   D. To close/release owned resources

7. Which statement about a default constructor is correct?
   A. A class may have many different default constructors.
   B. A default constructor can be called with no arguments.
   C. A default constructor must always be written by the programmer.
   D. It cannot coexist with parameterized constructors.

8. Consider:
   ```cpp
   class A {
   public:
       A() { cout << "0"; }
       A(int x) { cout << x; }
   };
   class B {
   public:
       A x, y;
       B(int n) : x(n) {
           y = A(n + 1);
           cout << "B";
       }
   };
   int main() {
       B b(3);
   }
   ```
   What is printed?
   A. `34B`
   B. `304B`
   C. `340B`
   D. `034B`

9. In the previous question, why was `y` not constructed by `A(n + 1)` directly?
   A. Because `y` is initialized before the constructor body, using its default constructor
   B. Because assignment and initialization are always identical
   C. Because `A(int)` is private
   D. Because member objects cannot use parameterized constructors

10. Which statement about copy construction is correct?
    A. `A b = a;` may call the copy constructor.
    B. Copy constructors must return `A`.
    C. Copy constructors must be `static`.
    D. A copy constructor always takes no arguments.

11. What is the usual signature of a copy constructor?
    A. `A(A other);`
    B. `A(const A& other);`
    C. `void A(const A& other);`
    D. `A& A(const A& other);`

12. Which of the following most directly indicates shallow copy danger?
    A. A class with only `int x;`
    B. A class with `string name;`
    C. A class with `double* ptr;`
    D. A class with `bool flag;`

13. Which statement about `this->member` is correct?
    A. It refers to a global variable named `member`
    B. It explicitly refers to the current object's member
    C. It can only be used in friend functions
    D. It is required in every member access

14. Which is a valid overloaded operator member function form?
    A. `operator+(A rhs);`
    B. `A operator+(const A& rhs) const;`
    C. `A + (const A& rhs);`
    D. `friend operator+(A rhs);`

15. Why might `operator<<` be declared as a friend?
    A. To allow direct access to private data when printing
    B. Because all overloaded operators must be friends
    C. Because friends are inherited
    D. Because friends are constructors

16. With `class Derived : public Base`, which statement is true?
    A. Base public members stay public in Derived
    B. Base private members become protected in Derived
    C. Base protected members become private automatically
    D. Base constructors are not involved

17. Which inheritance form can directly create a diamond problem in larger hierarchies?
    A. single inheritance
    B. multilevel inheritance
    C. multiple inheritance
    D. function overloading

18. Which statement about function overloading is correct?
    A. Same function name and same parameter list in the same scope
    B. Same function name and different parameter list in the same scope
    C. Different function names with same return type
    D. Only derived classes can overload

19. Which statement about redefining / hiding is correct?
    A. A derived function with the same name can hide base overloads
    B. Hiding occurs only when functions are virtual
    C. Hiding requires the same return type
    D. Hiding is the same as overriding

20. Which statement about overriding is correct?
    A. It happens only with non-virtual base functions
    B. It is resolved statically at compile time
    C. It uses the same signature and a virtual base function
    D. It requires different parameter types

21. What does the keyword `override` help with?
    A. It forces multiple inheritance
    B. It asks the compiler to check that a virtual function is truly overriding
    C. It makes the function private
    D. It allocates memory automatically

22. Why can `Base* p = new Derived;` be useful?
    A. It allows runtime polymorphism through a base interface
    B. It copies Derived into Base immediately
    C. It disables virtual dispatch
    D. It avoids destructors

23. Which statement about pure virtual functions is correct?
    A. They must have a normal function body in the base class
    B. They make derived classes impossible
    C. They define an interface that concrete derived classes should implement
    D. They are the same as friend functions

24. Which declaration makes `Shape` abstract?
    A. `void area();`
    B. `virtual void area();`
    C. `virtual double area() const = 0;`
    D. `double area() const override;`

25. Which statement about templates is correct?
    A. Templates avoid rewriting similar code for multiple data types
    B. Templates work only with built-in types
    C. Templates are runtime-only features
    D. Class templates cannot have destructors

26. In `template <class T1, class T2> class PairBox { ... };`, `T1` and `T2` are:
    A. function names
    B. template type parameters
    C. iterators
    D. macros

27. Which container is usually best for frequent insertions/removals at both ends in this course?
    A. `vector`
    B. `list`
    C. `map`
    D. raw array only

28. Which STL container does NOT support random access by index?
    A. `vector`
    B. `string`
    C. `list`
    D. array

29. Which expression is commonly used to traverse a map?
    A. `for (it = m.begin(); it != m.end(); ++it)`
    B. `for (it = m[0]; it < m[size]; ++it)`
    C. `while (m++)`
    D. `for (it = m.front(); it != m.back(); ++it)`

30. For a map iterator `it`, which is true?
    A. `it->first` is the value and `it->second` is the key
    B. `it->first` is the key and `it->second` is the value
    C. both are keys
    D. both are values

### Part II - Coding (4 questions)

31. Linked List - Reverse Linked List
Write:
```cpp
void reverseLinkedList(StringNode*& head);
```
for
```cpp
struct StringNode {
    string name;
    StringNode* next;
};
```
Reverse the list in place.

32. Linked List - Insert at End
Write:
```cpp
void insertNodeAtEnd(IntNode*& head, int value);
```
for
```cpp
struct IntNode {
    int value;
    IntNode* next;
};
```
Requirements:
- allocate a new node
- append it to the tail
- if the list is empty, make the new node the head

33. Inheritance / Polymorphism - Trace the Output
Without running, determine the output:
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "B"; }
    virtual ~Base() { cout << "b"; }
    virtual void f() { cout << "F"; }
};

class Derived : public Base {
public:
    Derived() { cout << "D"; }
    ~Derived() { cout << "d"; }
    void f() override { cout << "G"; }
};

int main() {
    Base* p = new Derived;
    p->f();
    delete p;
    return 0;
}
```

34. Templates / STL - Generic Maximum
Write a function template:
```cpp
template <typename T>
T myMax(T a, T b);
```
that returns the larger of the two values.

Then show one example call with `int` and one with `double`.

---
## Extra Focus Drill Topics
These are the highest-yield weak-spot topics based on your notes and uploaded materials:
- linked list pointer updates, especially deleting from head and reversing
- constructor order, destructor order, initializer list vs assignment
- copy constructor and shallow vs deep copy
- overriding vs overloading vs hiding
- template syntax outside class definitions
- iterator basics, map iterator access, list vs vector differences
