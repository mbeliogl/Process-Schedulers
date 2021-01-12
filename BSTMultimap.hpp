#ifndef BSTMULTIMAP_H
#define BSTMULTIMAP_H
#include "BSTNode.hpp"
#include <string>
using namespace std;
#include "BSTForwardIterator.hpp"

template <class key_t, class val_t>
class BSTMultimap{

    protected:
    BSTNode<key_t, val_t>* root;
    BSTNode<key_t, val_t>* sentinel;
    int numItems;

    public:
    BSTMultimap();
    virtual void insert(const key_t& key, const val_t& val);
    virtual void insertNode(BSTNode<key_t, val_t>* newNode);
    virtual int getSize();
    virtual bool isEmpty();
    virtual bool contains(const key_t& key) const;
    virtual void clear();
    ~BSTMultimap();
    virtual BSTForwardIterator<key_t, val_t> getMax() const;
    virtual BSTForwardIterator<key_t, val_t> getMin() const;
    virtual BSTForwardIterator<key_t, val_t> findFirst(const key_t& key) const;
    virtual BSTForwardIterator<key_t, val_t> findLast(const key_t& key) const;

    virtual void transplant(BSTNode<key_t, val_t>* nodeToReplace, BSTNode<key_t, val_t>* replacementNode);

    virtual BSTForwardIterator<key_t, val_t> remove(const BSTForwardIterator<key_t, val_t>& pos);

    //virtual string toString(); //will not be graded. For testing only

};

#include "BSTMultimap.tpp"





#endif