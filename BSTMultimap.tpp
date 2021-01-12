#include <iostream>
using namespace std;
#include <queue>
#include "BSTForwardIterator.hpp"

template <class key_t, class val_t>
BSTMultimap<key_t, val_t>::BSTMultimap(){
    sentinel = 0;
    root = sentinel;
    numItems = 0;
}

template<class key_t, class val_t>
void BSTMultimap<key_t, val_t>::insert(const key_t& key, const val_t& val)
{
    BSTNode<key_t, val_t>* temp = new BSTNode<key_t, val_t>(key, val);
    insertNode(temp);
}

template<class key_t, class val_t>
void BSTMultimap<key_t, val_t>::insertNode(BSTNode<key_t, val_t>* newNode)
{
    BSTNode<key_t, val_t>* nextNode = root;
    BSTNode<key_t, val_t>* currNode = sentinel;
    
    while(nextNode != sentinel)
    {
        currNode = nextNode;
        if(newNode->getKey() < currNode->getKey())
        {
            nextNode = currNode->getLeftChild();
        }
        else
        {
            nextNode = currNode->getRightChild();
        }
    }
    newNode->setParent(currNode);
    newNode->setLeftChild(sentinel);
    newNode->setRightChild(sentinel);
    
    if(currNode == sentinel)
    {
        root = newNode;
    }

    else if(newNode->getKey() < currNode->getKey()){
        currNode->setLeftChild(newNode);
    }
    
    else
    {
        currNode->setRightChild(newNode);
    }
    numItems += 1;
}




template <class key_t, class val_t>
int BSTMultimap<key_t, val_t>::getSize(){
    return numItems;
}

template <class key_t, class val_t>
bool BSTMultimap<key_t, val_t>::isEmpty(){
    if(numItems == 0){
        return true;
    }
    return false;
}
template <class key_t, class val_t>
bool BSTMultimap<key_t, val_t>::contains(const key_t& key) const{

    BSTNode<key_t, val_t>* curNode;
    curNode = root;
    while(curNode != 0){
        if(curNode->getKey() == key){
            return true;
        }
        else if(curNode->getKey() > key){
            curNode = curNode->getLeftChild();
        }
        else{
            curNode = curNode->getRightChild();
        }
    }

    return false;

}

template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::clear(){

    
    queue<BSTNode<key_t, val_t>*>* q = new queue<BSTNode<key_t, val_t>*>;
    q->push(root);
    // BSTNode<key_t, val_t>* test;
    // test = q->front();
    // cout << "TESTING: " << test->getKey() << endl;
    // cout << "root = " << root->getKey() << endl;
    // cout << "Left Child = " << root->getLeftChild()->getKey() << endl;
    // cout << "Right Child = " << root->getRightChild()->getKey() << endl;
    BSTNode<key_t, val_t>* temp;
    
    while(!q->empty()){
    temp = q->front();
    if(temp->getLeftChild() == sentinel || temp->getRightChild() == sentinel){
        q->pop();
        delete temp;
    }
    else{
        q->push(temp->getLeftChild());
        q->push(temp->getRightChild());
        q->pop();
        delete temp;
    }
}
}

template <class key_t, class val_t>
BSTMultimap<key_t, val_t>::~BSTMultimap(){
    clear();
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t,val_t>::getMin() const{
    BSTNode<key_t, val_t>* min;
    min = root;

    if(numItems == 0){
        min = sentinel;
        return BSTForwardIterator<key_t, val_t>(min, sentinel);
    }
    else{
         while(min->getLeftChild() != sentinel){
             min = min->getLeftChild();
    }

    return BSTForwardIterator<key_t, val_t>(min, sentinel);
    }
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::getMax() const{
     BSTNode<key_t, val_t>* max;
     max = root;

     if(numItems == 0){
         max = sentinel;
         return BSTForwardIterator<key_t, val_t>(max, sentinel);
     }

     else{
         while(max->getRightChild() != sentinel){
             max = max->getRightChild();
         }
         return BSTForwardIterator<key_t, val_t>(max, sentinel);
     }
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::findFirst(const key_t& key) const{
    BSTForwardIterator<key_t, val_t> iter = getMin();
    if(contains(key) == false)
    {
        BSTForwardIterator<key_t, val_t> sentVal(sentinel, sentinel);
        return sentVal;
    }
    
    while(iter.getKey() != key){
            iter.next();
    }

    return iter;
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::findLast(const key_t& key) const{
    BSTForwardIterator<key_t,val_t> iter = getMax();
    if(contains(key) == false)
    {
        
        BSTForwardIterator<key_t, val_t> sentVal(sentinel, sentinel);
        return sentVal;
    }
    
    while(iter.getKey() != key)
    {
        iter.prev();
    }
    return iter;

}



template<class Key_t, class val_t>
void BSTMultimap<Key_t, val_t>::transplant(BSTNode<Key_t, val_t>* nodeToReplace, BSTNode<Key_t, val_t>* replacementNode){
    
    if(nodeToReplace->getParent() == sentinel){
        root = nodeToReplace;
    }
    
    else if(nodeToReplace == nodeToReplace->getParent()->getLeftChild())
    {
        nodeToReplace->getParent()->setLeftChild(replacementNode);
    }
    
    else{
        nodeToReplace->getParent()->setRightChild(replacementNode);
    }
    
    if(replacementNode != sentinel){
        replacementNode->setParent(nodeToReplace->getParent());
    }
}


template<class Key_t, class val_t>
BSTForwardIterator<Key_t, val_t> BSTMultimap<Key_t, val_t>::remove(const BSTForwardIterator<Key_t, val_t>& pos){
    
    BSTForwardIterator<Key_t, val_t> temp = pos;
    temp.next();
    
    if(pos.current->getLeftChild() == sentinel){
        transplant(pos.current, pos.current->getRightChild());
    
    }
    else if(pos.current->getRightChild() == sentinel){
        transplant(pos.current, pos.current->getLeftChild());
    }
    
    else{
        root = pos.current->getRightChild();
        BSTForwardIterator<Key_t, val_t> tmp = getMin();
        
        if(tmp.current->getParent() != pos.current){
            transplant(tmp.current, tmp.current->getRightChild());
            tmp.current->setRightChild(pos.current->getRightChild());
            tmp.current->getRightChild()->setParent(tmp.current);
        }
        transplant(pos.current, tmp.current);
        tmp.current->setLeftChild(pos.current->getLeftChild());
        tmp.current->getLeftChild()->setParent(tmp.current);
        }
    return temp;
}
