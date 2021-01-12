
template <class key_t, class val_t>
RBTMultimap<key_t, val_t>::RBTMultimap() : BSTMultimap<key_t, val_t>(){
	key_t skey;
	val_t sval;

	RBTNode<key_t, val_t>* sent = new RBTNode<key_t, val_t>(skey, sval, false);

	this->sentinel = sent;
	this->root = this->sentinel;
}

template <class key_t, class val_t>
RBTMultimap<key_t, val_t>::~RBTMultimap(){
	delete this->sentinel;
    this->clear();
}


template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::insert(const key_t& key, const val_t& value){
	RBTNode<key_t, val_t>* insNode = new RBTNode<key_t, val_t>(key, value, false);

	this->insertNode(insNode);
	this->insertFixup(insNode);

}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::rotateLeft(BSTNode<key_t, val_t>* node){
	BSTNode<key_t, val_t>* y; 
	y = node->getRightChild();
	node -> setRightChild(y->getLeftChild());

	if(y->getLeftChild() != this->sentinel){
		y -> getLeftChild()->setParent(node);
	}
	y->setParent(node->getParent());

	if(node->getParent() == this->sentinel){
		this->root = y;
	}

	else if(node == node->getParent()->getLeftChild()){
		node->getParent()->setLeftChild(y);
	}

	else{
		node->getParent()->setRightChild(y);
	}

	y->setLeftChild(node);
	node->setParent(y);

}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::rotateRight(BSTNode<key_t, val_t>* node){
	BSTNode<key_t, val_t>* y; 
	y = node->getLeftChild();
	node -> setLeftChild(y->getRightChild());

	if(y->getRightChild() != this->sentinel){
		y -> getRightChild()->setParent(node);
	}
	y->setParent(node->getParent());

	if(node->getParent() == this->sentinel){
		this->root = y;
	}

	else if(node == node->getParent()->getRightChild()){
		node->getParent()->setRightChild(y);
	}

	else{
		node->getParent()->setLeftChild(y);
	}

	y->setRightChild(node);
	node->setParent(y);

}


template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::insertFixup(RBTNode<key_t, val_t>* insertedNode){
	
	RBTNode<key_t, val_t>* y;
	while(insertedNode->getParent() != this->sentinel && insertedNode->getParent()->isRed()){
		if(insertedNode->getParent() == insertedNode->getParent()->getParent()->getLeftChild()){
			y = insertedNode->getParent()->getParent()->getRightChild();

			if(y->isRed() == true){
				insertedNode->setIsRed(false);
				y->setIsRed(false);
				insertedNode->getParent()->getParent()->setIsRed(true);
				insertedNode = insertedNode->getParent()->getParent();
			}

			else{
				if(insertedNode == insertedNode->getParent()->getRightChild()){
					insertedNode = insertedNode->getParent();
					rotateLeft(insertedNode);
				}

				insertedNode->getParent()->setIsRed(false);
				insertedNode->getParent()->getParent()->setIsRed(true);
				rotateRight(insertedNode->getParent()->getParent());
			}
		}

		else{
			y = insertedNode->getParent()->getParent()->getLeftChild();

			if(y->isRed() == true){
				insertedNode->setIsRed(false);
				y->setIsRed(false);
				insertedNode->getParent()->getParent()->setIsRed(true);
				insertedNode = insertedNode->getParent()->getParent();
			}

			else{
				if(insertedNode == insertedNode->getParent()->getLeftChild()){
					insertedNode = insertedNode->getParent();
					rotateRight(insertedNode);
				}

				insertedNode->getParent()->setIsRed(false);
				insertedNode->getParent()->getParent()->setIsRed(true);
				rotateLeft(insertedNode->getParent()->getParent());
		}
	}

}

	RBTNode<key_t, val_t>* root = dynamic_cast<RBTNode<key_t, val_t>* >(this->root);
	//this->root = root;
}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::transplant(BSTNode<key_t, val_t>* nodeToReplace, BSTNode<key_t, val_t>* replacementNode){
	if(nodeToReplace == this->root){
		nodeToReplace = replacementNode;
	}

	else if(nodeToReplace == nodeToReplace->getParent()->getLeftChild()){
		nodeToReplace->getParent()->setLeftChild(replacementNode);
		replacementNode->setParent(nodeToReplace->getParent());
	}

	else{
		nodeToReplace->getParent()->setRightChild(replacementNode);
		replacementNode->setParent(nodeToReplace->getParent());
	}

}


// template <class key_t, class val_t>
// BSTForwardIterator<key_t, val_t> RBTMultimap<key_t, val_t>::remove(const BSTForwardIterator<key_t, val_t>& pos){
// 	RBTNode<key_t, val_t>* toRem = pos.current; 
// 	RBTNode<key_t, val_t>* y = toRem;
// 	RBTNode<key_t, val_t>* x;

// 	bool yColor = y->isRed();

// 	if(toRem->getLeftChild() == this->sentinel){
// 		x = toRem->getRightChild();
// 		transplant(toRem, toRem->getRightChild());
// 	}

// 	else if(toRem->getRightChild() == this->sentinel){
// 		x = toRem->getLeftChild();
// 		transpant(toRem, toRem->getLeftChild());
// 	}

// 	else{
// 		y = pos.getMin();
// 		yColor = y->isRed();
// 		x = y->getRightChild();
// 		if()
// 	}

// }

































template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::printDOT(std::string filename)
{
   using namespace std;
   ofstream fout(filename.c_str());

   long long counter = 1;
   map<RBTNode<key_t, val_t>*, long long> nodeToCounter;
   nodeToCounter[dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel)] = counter;
   counter++;

   fout << "digraph RBTMultimap {" << endl;

   fout << "\t node" << nodeToCounter[dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel)] << " [label=\"nil\", style=filled, color=grey, fontcolor=white];" << endl;

   if(this->root != this->sentinel)
   {
      RBTNode<key_t, val_t>* rt = dynamic_cast<RBTNode<key_t, val_t>* >(this->root);
      if(!nodeToCounter[rt])
      {
	 nodeToCounter[rt] = counter;
	 counter++;
      }
      if(!nodeToCounter[rt->getParent()])
      {
	 nodeToCounter[rt->getParent()] = counter;
	 counter++;
      }
      fout << "\t node" << nodeToCounter[rt] << " -> node" << nodeToCounter[rt->getParent()] << " [constraint=false, tailport=n, headport=s";
      if(rt->getParent() == this->sentinel)
      {
	 fout << ", color=grey];" << endl;
      }
      else
      {
	 //The root's parent is something weird!! Make the arrow orange so it sticks out
	 fout << ", color=orange];" << endl;
      }

      map<RBTNode<key_t, val_t>*, bool> printed;
   
      queue<RBTNode<key_t, val_t>* > q;
      q.push(rt);
      while(!q.empty())
      {
	 RBTNode<key_t, val_t>* node = q.front();
	 q.pop();

	 printed[node] = true;
      
	 //Set up node's appearance
	 if(!nodeToCounter[node])
	 {
	    nodeToCounter[node] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " [label=\"k: " << node->getKey() << "\", style=filled, color=";
	 if(node->isRed())
	 {
	    fout << "red";
	 }
	 else
	 {
	    fout << "black, fontcolor=white";
	 }
	 fout << "];" << endl;

	 //Set up child links
	 //First the left node
	 if(!nodeToCounter[node->getLeftChild()])
	 {
	    nodeToCounter[node->getLeftChild()] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " -> node" << nodeToCounter[node->getLeftChild()] << " [tailport=sw";    
	 if(node->getLeftChild() == this->sentinel)
	 {
	    fout << ", color=grey";
	 }
	 else if(printed[node->getLeftChild()])
	 {
	    fout << ", color=orange";
	 }
	 else
	 {
	    q.push(node->getLeftChild());
	 }

	 if(node->getLeftChild() != this->sentinel)
	 {
	    if(node->getLeftChild()->getParent() == node)
	    {
	       //The child's parent pointer points right back,
	       //so draw the second arrow
	       fout << ", dir=both];" << endl;
	    }
	    else
	    {
	       //The child node's parent pointer is not correct!
	       //Draw it in orange so it sticks out
	       fout << "];" << endl;
	       if(!nodeToCounter[node->getLeftChild()->getParent()])
	       {
		  nodeToCounter[node->getLeftChild()->getParent()] = counter;
		  counter++;
	       }
	       fout << "\t node" << nodeToCounter[node->getLeftChild()] << " -> node" << nodeToCounter[node->getLeftChild()->getParent()] << " [tailport=n, color=orange];" << endl;
	    }
	 }
	 else
	 {
	    fout << "];" << endl;
	 }

	 //Now the right node
	 if(!nodeToCounter[node->getRightChild()])
	 {
	    nodeToCounter[node->getRightChild()] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " -> node" << nodeToCounter[node->getRightChild()] << " [tailport=se";    
	 if(node->getRightChild() == this->sentinel)
	 {
	    fout << ", color=grey";
	 }
	 else if(printed[node->getRightChild()])
	 {
	    fout << ", color=orange";
	 }
	 else
	 {
	    q.push(node->getRightChild());
	 }

	 if(node->getRightChild() != this->sentinel)
	 {
	    if(node->getRightChild()->getParent() == node)
	    {
	       //The child's parent pointer points right back,
	       //so draw the second arrow
	       fout << ", dir=both];" << endl;
	    }
	    else
	    {
	       //The child node's parent pointer is not correct!
	       //Draw it in orange so it sticks out
	       fout << "];" << endl;
	       if(!nodeToCounter[node->getRightChild()->getParent()])
	       {
		  nodeToCounter[node->getRightChild()->getParent()] = counter;
		  counter++;
	       }
	       fout << "\t node" << nodeToCounter[node->getRightChild()] << " -> node" << nodeToCounter[node->getRightChild()->getParent()] << " [tailport=n, color=orange];" << endl;
	    }
	 }
	 else
	 {
	    fout << "];" << endl;
	 }
      }
   }
   fout << "}" << endl;
}

