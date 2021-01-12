#include "BSTNode.hpp"
#include "BSTMultimap.hpp"

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t>::BSTForwardIterator(BSTNode<key_t, val_t>* node, BSTNode<key_t, val_t>* sentinel){
    current = node;
    sentinel = sentinel;
}

template <class key_t, class val_t>
void BSTForwardIterator<key_t, val_t>::next(){
    BSTNode<key_t, val_t>* parent;

    if(current == sentinel){
        return;
    }
    
    if(current->getRightChild() != sentinel)
    {
        current = current->getRightChild();
        while(current->getLeftChild() != sentinel){
            current = current->getLeftChild();
        }
    }
    
    else if(current->getParent() != sentinel)
    {
        parent = current->getParent();
        while(parent != sentinel && current == parent->getRightChild())
    {
        current = parent;
        parent = parent->getParent();
    }
    
    current = parent;
}
}

//reverse of next to get previous (cormen)
template <class Key_t, class val_t>
void BSTForwardIterator<Key_t, val_t>::prev(){
    BSTNode<Key_t, val_t>* parent;
    if(current == sentinel){
        return;
    }
    if(current->getLeftChild() != sentinel)
    {
        current = current->getLeftChild();
        while(current->getRightChild() != sentinel){
            current = current->getRightChild();
        }
    }
    else if(current->getParent() != sentinel){
        parent = current->getParent();
        while(parent != sentinel && current == parent->getLeftChild()){
            current = parent;
            parent = parent->getParent();
        }
        
        current = parent;
    }
}



template <class key_t, class val_t>
bool BSTForwardIterator<key_t, val_t>::isPastEnd() const{

    if(current == sentinel){
        return true;
    }
    return false;
}

template <class key_t, class val_t>
const key_t& BSTForwardIterator<key_t, val_t>::getKey() const{
    return current->getKey();
}

template <class key_t, class val_t>
const val_t& BSTForwardIterator<key_t, val_t>::getValue() const{
    return current->getValue();
}

template <class key_t, class val_t>
void BSTForwardIterator<key_t, val_t>::setValue(const val_t& newVal){
    current->setValue(newVal);
}


