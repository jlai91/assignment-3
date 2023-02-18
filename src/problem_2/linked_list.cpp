#include "linked_list.h"

template<class T>
void LinkedList<T>::push_front(const T &value) {
    //push pointer with new node
    ListNode<T> *pPtr = new ListNode<T>(value);
    //pushed node points to 1st element of list
    pPtr->next=head->next;
    //head points to pushed node
    head->next=pPtr;
    //increments list size
    num_of_element++;
}

template<class T>
void LinkedList<T>::push_back(const T &value) {
    //push pointer set to head
    ListNode<T> *pPtr = head;
    //move push pointer to end of the list
    while(pPtr->next!=NULL)pPtr=pPtr->next;
    //creates new node at end of the list with value
    pPtr->next=new ListNode<T>(value);
    //sets new node to point to NULL
    pPtr->next->next=NULL;
    //increments list size
    num_of_element++;
}

template<class T>
void LinkedList<T>::pop_back() {
    //checks if list is empty
    if(head->next==NULL);
    else{
        //removal pointer starts at head
        ListNode<T> *rPtr = head;
        //move removal pointer to 2nd-to-last element of the list
        while(rPtr->next->next!=NULL)rPtr=rPtr->next;
        //deletes last element of list
        delete rPtr->next;
        //sets 2nd-to-last (now last) element to point to NULL
        rPtr->next=NULL;
        //decrement list size
        num_of_element--;
    }
}

template<class T>
void LinkedList<T>::pop_front() {
    //checks if list is empty
    if(head->next==NULL);
    else{
        //removal pointer set to front of list
        ListNode<T> *rPtr = head->next;
        //head points 2 elements ahead
        head->next=rPtr->next;
        //deletes removal pointer node
        delete rPtr;
        //decrements list size
        num_of_element--;
    }

}

template<class T>
void LinkedList<T>::remove(T &val) {
    //checks if list is empty
    if(head->next==NULL);
    else{
        //navigation pointer set to the head
        ListNode<T> *nPtr = head;
        //traverses list to end
        while(nPtr->next!=NULL){
            //if node value matches reference value
            if(nPtr->next->val==val){
                //removal pointer set to node
                ListNode<T> *rPtr = nPtr->next;
                //previous node points 2 elements ahead
                nPtr->next=rPtr->next;
                //deletes removal pointer node
                delete rPtr;
                //decrements list size
                num_of_element--;
            }
            //continues traversal if value does not match
            else nPtr=nPtr->next;
        }
    }
}

/*
 * merge in ascending order
 */
template<class T>
void LinkedList<T>::merge(const List<T> &ot) {

    //Dynamic casts second list to make its elements accessible
    //(I actually don't know if there's a more efficient method to do this, I'm just copying it from Assignment 2)
    const List<T> *lPtr = &ot;
    const LinkedList<T> * ll = dynamic_cast<const LinkedList<T>*>(lPtr);

    //Navigation pointers for 1st and 2nd List, both set at heads
    ListNode<T> *nPtr1 = head;
    ListNode<T> *nPtr2 = ll->head;

    //checks if 2nd List is empty. If so, 1st list alone is effectively the merged result
    if(nPtr2->next==NULL);
    else{
        //if both lists have content
        while(nPtr1->next!=NULL&&nPtr2->next!=NULL){
            //traverses 1st list if nav pointer value is less than 2nd list's
            if(nPtr1->next->val<=nPtr2->next->val)nPtr1=nPtr1->next;
            else{
                //inserts new node with 2nd list's value if less than 1st list's
                ListNode<T> *pPtr = new ListNode<T>(nPtr2->next->val);
                pPtr->next=nPtr1->next;
                nPtr1->next=pPtr;
                //advances both list pointers
                nPtr1=nPtr1->next;
                nPtr2=nPtr2->next;
                num_of_element++;
            }
        }
        //if list 1 pointer reaches end
        while(nPtr2->next!=NULL){
            //adds the remainder of list 2 to list 1
            nPtr1->next=new ListNode<T>(nPtr2->next->val);
            nPtr1=nPtr1->next;
            nPtr1->next=NULL;
            nPtr2=nPtr2->next;
            num_of_element++;
        }
        //there is no need to address if list 2 pointer reaches end before list 1 because list 1 replaces merged list and shouldn't add to itself
    }
}

template<class T>
void LinkedList<T>::reverse_iterative() {
    //checks if list has at least 2 elements
    if(num_of_element>1){
        //list can be reversed by sequentially removing and inserting each element to the front of the list as you traverse it
        //the start of the list is the end of the reversed list, create a pivot pointer that begins the reversal sequence and ends when the pivot becomes the last element of the list
        ListNode<T> *pivot = head->next;
        //navigation pointer to move elements across the pivot to the front of the list
        ListNode<T> *ptr = pivot;
        //previous element pointer to link the newly moved element to
        ListNode<T> *prev = pivot;

        //continues until pivot becomes end
        while(pivot->next!=NULL){
            //pointer in front of pivot
            ptr = pivot->next;
            //pivot points in front of pointer (2 elements forward)
            pivot->next=ptr->next;
            //pointer points to last-moved element at the front of list (initially pivot), making it second on the list
            ptr->next = prev;
            //head points to pointer, making pointer element front of the list
            head->next=ptr;
            //last-moved element set to pointer
            prev = ptr;
        }
    }
}