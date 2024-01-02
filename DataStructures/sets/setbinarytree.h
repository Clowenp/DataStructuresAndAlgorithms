#ifndef __SETBINARYTREE__H_
#define __SETBINARYTREE__H_

template<typename T> 
class BTree {
    T data;
    BTree* left;
    BTree* right;

    public:
    // default
    BTree() {

    }

    // copy ctor
    BTree(BTree& other) {

    }

    // move ctor
    BTree(Btree&& other) {

    }

    // copy assignment operator
    Btree& BTree(Btree& other) {

    }

    // move assignment operator
    Btree& BTree(Btree&& other) {

    }

    // destructor
    ~BTree() {

    }

    // === METHODS ===
    void add(T data) {

    }
    bool remove(T data) {

    }
    bool find(T data) {

    }
};

// Set is basically a wrapper for BTree
template<typename T>
class Set {
    BTree<T> data;

    public:
    // default
    Set() {

    }

    // copy ctor
    Set(Set& other) {

    }

    // move ctor
    Set(Set&& other) {

    }

    // copy assignment operator
    Set& Set(Set& other) {

    }

    // move assignment operator
    Set& Set(Set&& other) {

    }

    // destructor
    ~Set() {

    }

    // === METHODS ===
    void add(T data) {
        // calls add on Btree
    }
    bool remove(T data) {
        // calls remove on Btree
    }
    bool find(T data) {
        // calls find on Btree
    }

};

#endif