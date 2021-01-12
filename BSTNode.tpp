
template <class key_t, class val_t>
BSTNode<key_t, val_t>::BSTNode(const key_t& key, const val_t& val){
    myKey = key;
    value = val;
    parent = 0;
    right = 0;
    left = 0;
}

template <class key_t, class val_t>
const val_t& BSTNode<key_t, val_t>::getValue(){
    return value;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setValue(const val_t& val){
    value = val;
}

template <class key_t, class val_t>
const key_t& BSTNode<key_t, val_t>::getKey(){
    return myKey;
}


template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setKey(const key_t& key){
    myKey = key;
}


template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getLeftChild()const{
    return left;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setLeftChild(BSTNode* node){
    left = node;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getRightChild()const{
    return right;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setRightChild(BSTNode* node){
    right = node;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getParent()const{
    return parent;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setParent(BSTNode* node){
    parent = node;
}




