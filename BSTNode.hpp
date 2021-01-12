#ifndef BSTNODE_H
#define BSTNODE_H

template <class key_t, class val_t>
class BSTNode{
    
    protected:
    key_t myKey;
    val_t value;
    BSTNode<key_t, val_t>* parent;
    BSTNode<key_t, val_t>* right;
    BSTNode<key_t, val_t>* left;
    
    public:
    BSTNode(const key_t& key, const val_t& val);
    
    virtual const val_t& getValue();
    virtual void setValue(const val_t& val);
    virtual const key_t& getKey();
    virtual void setKey(const key_t& key);
    virtual BSTNode* getLeftChild() const;
    virtual void setLeftChild(BSTNode* node);
    virtual BSTNode* getRightChild() const;
    virtual void setRightChild(BSTNode* node);
    virtual BSTNode* getParent() const;
    virtual void setParent(BSTNode* node);
      
    
};

#include "BSTNode.tpp"






#endif