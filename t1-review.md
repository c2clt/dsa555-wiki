## Q1:

What is the run time of the following functions:

```c
int f1(int n){
    int rc=1;                 // 1
    for(int i=0;i<5;i++){     // 1 + 2 * n
        rc+=1;                // 1 * n
    }
    return rc;               // 1
}
```


## Q2:

What is the run time of the following functions:

```c
int f1(int n){
    int rc=1;
    for(int i=0;i<n;i+=2){
        rc+=1;
    }
    return rc;
}
```
## Q3:

Suppose that the function function1(n) has a run time of O(n) and function2(n) has a run time of O(n^2)  What is the run time of f1(n)?

```c
int f1(int n){
    function1(n);
    function2(n);
}
```

## Q4:

Write the following function recursively:

```
bool isPalindrome(const char* s)
```
s is a null terminated character string.  This function returns true if s is a palindrome.  A palindrome is a string that reads the same forwards and backwards.  Thus:   noon, mom, dad are all palindromes.   table, texture, glass are not palindromes.

the above function can be a wrapper to a function that actually does the work

Try to write the function to O(n) run time where n is the length of s.

## Q5
Given the following:

```c
class Stack{
   ...
public:
   void push(int v);      
   void pop();           
   int top();            
   bool isEmpty();        
};
```
 and
```c
class Queue{
   ...
 public:
   void enqueue(int v);
   void dequeue();
   int front();
   bool isEmpty();   

};
```
Write the function:
```c 
void ReOrder(int newarr[], int arr[],int size);
```


This function creates newarr from the values in arr using the following rules:

```
size is length of arr
The value 0 separates arr into "chunks"
Each "chunk" can hold both positive and negative values in any order
```

When creating newarr, each chunk must satisfy the following rules

```
All negative values go before all positive values
All negative values are added in the same order as their original order.
All positive values are added opposite to their original order
The 0 that was used to separate each chunk is not added to newarr.
```

Example:
 
```
Suppose arr={-3,2,-1,5,1,-4,0,11,12,13,-11,-12};
then when you create newarr, newarr should have the following:
{-3,-1,-4,1,5,2,-11,-12,13,12,11}
```


## Q6:

When using a singly linked list to implement a stack, is it better for insertions to occur at the front or back of the list (or does it matter)?  Why?


## Q7:
The following show a table of keys and the hash index of these keys within a table of size 10

| key | hashIdx |
|---|---|
| alpha | 8|
| beta | 9|
| gamma | 8|
| apple | 4 |
| orange | 4 | 
| cherry | 5 |


#### part a

Draw an empty array of size 10 that represents a linear probing table.

#### part b
Insert the keys in the following order and show the final array:

* beta
* alpha
* gamma
* apple
* cherry
* orange


#### part c

remove apple from table in part b, what does final array look like

#### part d

remove beta from table in part c, what does final array look like

#### part e

If you used tombstones in the previous parts, redo this question (parts A to D) without tombstones.  If you did it without tombstones, redo this question (parts A to D)  with tombstones 

## Q8:

Describe what you will need to implement a queue using an array such that you have O(1) runtimes for enqueue() and dequeue() operations.  Do this WITHOUT using code (ie what do you need, why do you need it, but don't just code dump)

## Q9:

A self adjusting linked list is a linked list where a successful search causes the list to adjust so that the found item is moved to the front (and thus allowing successive search for same item to be more readily found).
 
Given the following class declarations for a singly linked self adjusting linked list:
 
```cpp
template <class T>
clsss SelfAdjustingList{
    struct Node{
        T value_;
        Node* next_;
        Node(const T& data=T{},Node* next=nullptr){...}
    };
    Node* front_;
    Node* back_;
 
public:
    class const_iterator{
       friend class SelfAdjustingList;
       Node* curr_;
       const_iterator(Node* n){...}
    public:
        const_iterator(){...}
	const_iterator operator++(){...}
	const_iterator operator++(int){...}
	const_iterator operator--(){...}
	const_iterator operator--(int){...}
	bool operator==(const_iterator rhs){...}
	bool operator!=(const_iterator rhs){...}
	const T& operator*()const{...}
    };
    class iterator:public const_iterator{
        friend class SelfAdjustingList;
        iterator(Node* n):const_iterator(n){...}
    public:
	iterator();
	iterator operator++(){...}
	iterator operator++(int){...}
	iterator operator--(){...}
	iterator operator--(int){...}
	T& operator*(){...}
	const T& operator*()const{...}
    };
     iterator begin(){...}
    iterator end(){...}
     const_iterator begin() const{...}
    const_iterator end() const{...}
};
```

Write the following member function:
```cpp 
iterator SelfAdjustingList::search(const T& v){
    SelAdjustingList::iterator it;
    for(it = begin(); it != end(); it++){
    	if(*it == v){
	    SelfAjustingList::iterator old = it;
	    SelfAjustingList::iterator pit = --it;
	    it++;
	    if(it.curr_->next_ != back_){
	         SelfAjustingList::iterator nit = ++it;
	         pit.curr_->next_ = nit.curr_;
	    }
	    else{
	    	pit.curr_->next_ = back_;
	    }
	}
	
	return old;
    }
    
    return end();
}
```
* This function searches for v within the list and returns an iterator to the node where v is found.  If not found, function returns end()
* The list will be adjusted so that the found node is moved so that it becomes the first data node in the list
* You can make use of any function you see in the declaration above.  Any other function you wish to use must be written
* Function must have run time of O(n)


