
/**
 * This recursive helper function inserts a key-value pair into a subtree 
 * of the tree, or throws a runtime_error if the key is already present.
 */
template <typename K, typename V>
AVLTreeNode<K,V>*
AVLTree<K,V>::insertInSubtree(AVLTreeNode<K,V>* current, K key, V value) {
  if (current==NULL){
    size++;
    return new AVLTreeNode<K,V>(key,value);
  }
  if (key<current->key){
    current->left = insertInSubtree(current->left, key, value);
  } else if (key > current->key){
    current->right = insertInSubtree(current->right, key, value);
  } else {
    throw std::runtime_error("AVLTree::insert attempted with duplicate key");
  }

  return balance(current);
}

/**
 * This recursive helper function updates key-value pair in the subtree 
 * of the tree, or throws a runtime_error if the key is not present.
 */
template <typename K, typename V>
void AVLTree<K,V>::updateInSubtree(AVLTreeNode<K,V>* current, K key, V value) {
  if (current==NULL){
    throw std::runtime_error("AVLTree::update attempted with key not in tree");
  }
  if (key<current->key){
    updateInSubtree(current->left, key, value);
  } else if (key > current->key){
    updateInSubtree(current->right, key, value);
  } else {
    current->value = value;
  }
}


/**
 * This recursive helper function removes a key-value pair from a subtree 
 * of the tree, or throws a runtime_error if that key was not present.
 *
 * It returns a pointer to the root of the subtree.  This root is often
 * the node that was passed as an argument to the function (current) but
 * might be a different node if current contains the key we are removing
 * from the tree.
 */
template <typename K, typename V>
AVLTreeNode<K,V>* 
AVLTree<K,V>::removeFromSubtree(AVLTreeNode<K,V>* current, 
                                  K key) {
  if (current == NULL) {
    throw std::runtime_error("AVLTree::remove called on key not in tree.");
  }

  if (key == current->key) {       // We've found the node to remove
    AVLTreeNode<K,V>* toReturn;
    if(current->left == NULL && current->right==NULL){ //this is a leaf
      size--;
      toReturn = NULL;
      delete current;
    } else if (current->left == NULL) {
      toReturn = current->right;
      size--;
      delete current;
    } else if (current->right == NULL){
      toReturn = current->left;
      size--;
      delete current;
    } else {
      current->key = getMinInSubtree(current->right);
      current->value = findInSubtree(current->right, current->key);
      current->right = removeFromSubtree(current->right, current->key);
      toReturn = current;
    }
    return balance(toReturn);
  }

  if (key < current->key) {
    current->left = removeFromSubtree(current->left, key);
  } else {
    current->right = removeFromSubtree(current->right, key);
  }
  return balance(current);
}


/**
 * Returns true if a key is contained in a subtree of the tree, and
 * false otherwise.
 */
template <typename K, typename V>
bool AVLTree<K,V>::containsInSubtree(AVLTreeNode<K,V>* current, K key) {
  if(current == NULL){
    return false;
  }
  if(key == current->key){
    return true;
  } else if (key < current->key){
    return containsInSubtree(current->left, key);
  } else {
    return containsInSubtree(current->right, key);
  }
}


/**
 * Given a key, returns the value for that key from a subtree of the tree.
 * Throws a runtime_error if the key is not in the subtree.
 */
template <typename K, typename V>
V AVLTree<K,V>::findInSubtree(AVLTreeNode<K,V>* current, K key) {
  if(current == NULL){
    throw std::runtime_error("AVLTree::find called on key not in tree");
  }
  if(key == current->key){
    return current->value;
  } else if (key < current->key){
    return findInSubtree(current->left, key);
  } else {
    return findInSubtree(current->right, key);
  }
}


/**
 * Returns the largest key in a subtree of the tree.
 */
template <typename K, typename V>
K AVLTree<K,V>::getMaxInSubtree(AVLTreeNode<K,V>* current) {
  if (current->right == NULL) {
    return current->key;
  }
  return getMaxInSubtree(current->right);
}


/**
 * Returns the smallest key in a subtree of the tree.
 */
template <typename K, typename V>
K AVLTree<K,V>::getMinInSubtree(AVLTreeNode<K,V>* current) {
  if (current->left == NULL) {
    return current->key;
  }
  return getMinInSubtree(current->left);
}


/**
 * Recursively builds a post-order iterator for a subtree of the tree.
 */
template <typename K, typename V>
void AVLTree<K,V>::buildPostOrder(AVLTreeNode<K,V>* current,
                                       Queue< Pair<K,V> >* it) {
  if (current == NULL) {
    return;
  }
  buildPostOrder(current->left, it);
  buildPostOrder(current->right, it);
  it->enqueue( Pair<K,V>(current->key, current->value) );
}

/**
 * Recursively builds a pre-order iterator for a subtree of the tree.
 */
template <typename K, typename V>
void AVLTree<K,V>::buildPreOrder(AVLTreeNode<K,V>* current,
                                      Queue< Pair<K,V> >* it) {
  if(current==NULL){
    return;
  }

  it->enqueue( Pair<K,V>(current->key, current->value));
  buildPreOrder(current->left, it);
  buildPreOrder(current->right, it);
}


/**
 * Recursively builds an in-order iterator for a subtree of the tree.
 */
template <typename K, typename V>
void AVLTree<K,V>::buildInOrder(AVLTreeNode<K,V>* current,
                                     Queue< Pair<K,V> >* it) {
  if(current==NULL){
    return;
  }
  buildInOrder(current->left, it);
  it->enqueue( Pair<K,V>(current->key, current->value));
  buildInOrder(current->right, it);
}


/**
 * Performs a post-order traversal of the tree, deleting each node from the
 * heap after we have already traversed its children.
 */
template <typename K, typename V>
void AVLTree<K,V>::traverseAndDelete(AVLTreeNode<K,V>* current) {
  if (current == NULL) {
    return;  //nothing to delete
  }
  traverseAndDelete(current->left);
  traverseAndDelete(current->right);
  delete current;
}

template <typename K, typename V>
void AVLTree<K,V>::computeHeightFromChildren(AVLTreeNode<K,V>* current){
  if(current == NULL) return;
  //calculate left and right children's heights
  int leftHeight  = (current->left) ? current->left->height : -1;
  int rightHeight  = (current->right) ? current->right->height : -1;

  //update the current node's height
  current->height = (leftHeight > rightHeight) ? leftHeight + 1 
                                               : rightHeight + 1;
}

/**
 * balance: Computes the height of a node and rebalances the tree rooted
 * at the node if necessary, maintaining the AVL balance property.
 *
 * Inputs:  current, a pointer to a node in the AVL tree.
 * Returns: a pointer to the root of the subtree.  This will usually be
 *          the argument to the function (current) if no rebalancing
 *          was needed, but can be a different node in the tree if a
 *          tree rotation was needed to balance the tree.
 *
 * This function assumes:
 *   (1) current->left->height and current->right->height are the correct
 *       heights of the left and right children.
 *   (2) The AVL tree rooted at this node was balanced before a single
 *       insert or remove, and therefore the current difference in height
 *       of current's subtrees is at most two.
 */
template <typename K, typename V>
AVLTreeNode<K,V>*
AVLTree<K,V>::balance(AVLTreeNode<K,V>* current) {
  if(current == NULL) return current;

  computeHeightFromChildren(current);
  //calculate left and right children's heights
  int leftHeight  = (current->left) ? current->left->height : -1;
  int rightHeight  = (current->right) ? current->right->height : -1;


  // detect imbalance
  if (leftHeight > rightHeight+1) {       // Left subtree is too tall.
    int leftGrand = (current->left->left) ? current->left->left->height : -1;
    int rightGrand = (current->left->right) ? current->left->right->height : -1;
    
    if (leftGrand > rightGrand) {
      return rightRotate(current);  // left-outer grandchild is too tall.
    }
    return leftRightRotate(current);    // left-inner grandchild is too tall.
  }
  
  if (rightHeight > leftHeight+1) {       // Right subtree is too tall.
    int leftGrand = (current->right->left) ? current->right->left->height : -1;
    int rightGrand = (current->right->right) ? current->right->right->height 
                                             : -1;
    
    if (rightGrand > leftGrand) {
      return leftRotate(current);  // left-outer grandchild is too tall.
    }
    return rightLeftRotate(current);    // left-inner grandchild is too tall.
  }

  return current;                         // We were already balanced.
}

/**
 * rightRotate:  rebalances the tree in the case that the left-left
 *               grandchild is too tall.
 * @param current, a pointer to the root of the subtree we are rebalancing.
 * @return: a pointer to the new root of the rebalanced subtree.
 */
template <typename K, typename V>
AVLTreeNode<K,V>*
AVLTree<K,V>::rightRotate(AVLTreeNode<K,V>* current) {

  AVLTreeNode<K,V>* newRoot = current->left;  // B is new root


  current->left = newRoot->right;  // transfer C to D's left
  newRoot->right = current; // move D to B's right
 
  computeHeightFromChildren(current);//D's height may change due to new child(C)
  computeHeightFromChildren(newRoot);  // B's height may have changed
                                 // C, E, and A have same heights
  return newRoot;
}

/**
 * leftRotate:  rebalances the tree in the case that the right-right
 *               grandchild is too tall.
 * @param current, a pointer to the root of the subtree we are rebalancing.
 * @return: a pointer to the new root of the rebalanced subtree.
 */
template <typename K, typename V>
AVLTreeNode<K,V>*
AVLTree<K,V>::leftRotate(AVLTreeNode<K,V>* current) {

  AVLTreeNode<K,V>* newRoot = current->right;  // B is new root


  current->right = newRoot->left;  // transfer C to D's left
  newRoot->left = current; // move D to B's right
 
  computeHeightFromChildren(current);  // D's height may change due to new child (C)
  computeHeightFromChildren(newRoot);  // B's height may have changed
                                 // C, E, and A have same heights
  return newRoot;
}

/**
 * leftRightRotate:  rebalances the tree in the case that the left-right
 *               grandchild is too tall.
 * @param current, a pointer to the root of the subtree we are rebalancing.
 * @return: a pointer to the new root of the rebalanced subtree.
 */
template <typename K, typename V>
AVLTreeNode<K,V>* AVLTree<K,V>::leftRightRotate(AVLTreeNode<K,V>* current) {
  current->left = leftRotate(current->left);
  return rightRotate(current);
}

/**
 * rightLeftRotate:  rebalances the tree in the case that the right-left
 *               grandchild is too tall.
 * @param current, a pointer to the root of the subtree we are rebalancing.
 * @return: a pointer to the new root of the rebalanced subtree.
 */
template <typename K, typename V>
AVLTreeNode<K,V>* AVLTree<K,V>::rightLeftRotate(AVLTreeNode<K,V>* current) {
  current->right = rightRotate(current->right);
  return leftRotate(current);
}

