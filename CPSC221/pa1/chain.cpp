#include "chain.h"
#include "chain_given.cpp"

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain() {
  /* your code here
  delete every node in the chain
  starting at head_ keep going till back to head_
  */

  /*
  for (int i = 0; i < length_; i++) {
    Node* curr = head_->next;
    head_->next = NULL;
    head_->prev = NULL;
    delete head_;
    head_ = curr;
    delete curr;
    }
   */
   clear();


}

/**
 * Inserts a new node at the end of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */

void Chain::insertBack(const Block & ndata){
    /*your code here*/
    Node * data = new Node(ndata);
    Node * end = head_->prev;
    data->prev = end;
    data->next = head_;
    end->next = data;
    head_->prev = data;
    length_++;
}


/**
 * Modifies the Chain by moving the subchain of len Nodes,
 * starting at position startPos, dist positions toward the
 * end of the chain.  If startPos + len - 1 + dist > length
 * then dist = length - startPos - len + 1 (to prevent gaps
 * in the new chain).
 * The subchain occupies positions (startPos + dist) through
 * (startPos + dist + len - 1) of the resulting chain.
 * The order of subchain nodes is not changed in the move.
 * You may assume that: 1 <= startPos <= length - len + 1,
 * 0 <= dist <= length, and 0 <= len <= length.
 */
void Chain::moveBack(int startPos, int len, int dist){
    /*your code here*/

    Node *pstrt, *plen, *plendst;
    if (startPos + len-1 + dist > length_) {
        dist = length_ - startPos - len + 1;
    }
    if (len != 0 && dist != 0){
        pstrt = walk(head_, startPos);
        plen = walk(pstrt, len-1);
        plendst = walk(plen, dist);

        plen->next->prev = pstrt->prev;
        pstrt->prev->next = plen->next;
        plen->next = plendst->next;
        plen->next->prev = plen;
        plendst->next = pstrt;
        pstrt->prev = plendst;
    }


}

/**
 * Modfies the current chain such that a node at position i swaps with a node at position n-i
 * That is node a node with distance x from the sentinel node, should swap with another node of distance x
 * Should only touch nodes within limit distance of the sentinel
 *
 * @param limit the maximum distance from the sentinel to swap at, so at most 2*limit nodes should be affected
 *      You may assume that 2*limit <= _length, so there will always be enough nodes to swap
 *
 */
void Chain::mirrorSwap(int limit){
    /* your code here */
    for (int i = 0; i < limit; i++) {
      Node* front = walk(head_, i+1);
      Node* back = walk(head_, length_-i);
      Node* temp = front->prev;

      front->prev = back->prev;
      front->prev->next = front;

      back->prev = temp;
      back->prev->next = back;

      temp = front->next;
      front->next = back->next;
      front->next->prev = front;

      back->next = temp;
      back->next->prev = back;
    }
}



/**
 * Removes every block where the average saturation is greater than 'threshold'
 * Should also update _length to accurately reflect the new chain length
 *
 * eg: if we set threshold = 0, the function will remove all blocks with color
 * @param threshold the maximum allowable saturation value in a block
 */
void Chain::lazyFilter(double threshold){
    /* your code here */
    Node* curr = head_->next;
    Node* temp;
    while (curr != head_) {
        temp = curr;
        curr = curr->next;
        double sat = temp->data.avgSaturation();
        if (sat > threshold) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            length_--;
        }
    }
}

/*
* Modifies both the current chain and the "other" chain by removing
* nodes from the other chain and adding them between the nodes
* of the current chain -- one "other" node between two current nodes --
* until one of the two chains is exhausted.  Then the rest of the
* nodes in the non-empty chain follow.
* The length of the resulting chain should be the sum of the lengths
* of current and other. The other chain should have only
* the head_ sentinel at the end of the operation.
* The weave fails and the original
* chains should be unchanged if block sizes are different.
* In that case, the result of the function should be:
* cout << "Block sizes differ." << endl;
*/


void Chain::weave(Chain & other) { // leaves other empty.
  /* your code here */
  if(height_ != other.height_ || width_ != other.width_){
      cout << "Block sizes differ." << endl;
  } else {
      Node* curr = head_ -> next;
      Node* oth = other.head_ -> next;
      while (curr != head_ && oth != other.head_) {
          Node *oth1 = oth->next;
          oth->next->prev = oth->prev;
          oth->prev->next = oth->next;
          oth->prev = curr;
          oth->next = curr->next;
          curr->next->prev = oth;
          curr->next = oth;
          curr = curr->next->next;
          length_++;
          oth = oth1;
      } while (oth != other.head_){
          Node* oth1 = oth -> next;
          curr = head_ -> prev;
          oth -> next -> prev = oth -> prev;
          oth -> prev -> next = oth -> next;
          oth -> prev = curr;
          oth -> next = curr -> next;
          curr -> next -> prev = oth;
          curr -> next = oth;
          length_++;
          oth = oth1;
      }
      other.head_ -> next = other.head_;
      other.head_ -> prev = other.head_;
  }
}


/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class except for the sentinel head_. Sets length_
 * to zero.  After clear() the chain represents an empty chain.
 */
void Chain::clear() {
  /* your code here */
  length_ = 0;
  height_ = 0;
  width_  = 0;


  Node* curr = head_ -> next;
  while (curr != head_) {
      Node* n = curr;
      curr = curr->next;
      delete n;
  }



}

/**
 * Makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const& other) {
  /* your code here */
  length_=other.length_;
  width_=other.width_;
  height_=other.height_;

  for (unsigned i=1; i <= other.length_; i++){
    insertBack(walk(other.head_, i)->data);
  }
}
