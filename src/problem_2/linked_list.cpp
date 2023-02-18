#include "linked_list.h"

template<class T>
void LinkedList<T>::push_front(const T &value) {
    /*
     * TODO: homework
     */
    ListNode<T> *pPtr = new ListNode<T>(value);
    pPtr->next=head->next;
    head->next=pPtr;
    num_of_element++;
}

template<class T>
void LinkedList<T>::push_back(const T &value) {
    /*
     * TODO: homework
     */
    ListNode<T> *nPtr = head;
    while(nPtr->next!=NULL)nPtr=nPtr->next;
    nPtr->next=new ListNode<T>(value);
    nPtr->next->next=NULL;
    num_of_element++;
}

template<class T>
void LinkedList<T>::pop_back() {
    /*
     * TODO: homework
     */

    if(head->next==NULL);
    else{
        ListNode<T> *nPtr = head;
        while(nPtr->next->next!=NULL)nPtr=nPtr->next;
        delete nPtr->next;
        nPtr->next=NULL;
        num_of_element--;
    }


}

template<class T>
void LinkedList<T>::pop_front() {
    /*
     * TODO: homework
     */
    if(head->next==NULL);
    else{
        ListNode<T> *nPtr = head->next;
        head->next=nPtr->next;
        delete nPtr;
        num_of_element--;
    }

}

template<class T>
void LinkedList<T>::remove(T &val) {
    /*
     * TODO: homework
     */
    if(head->next==NULL);
    else{
        ListNode<T> *nPtr = head;
        while(nPtr->next!=NULL){
            if(nPtr->next->val==val){
                ListNode<T> *rPtr = nPtr->next;
                nPtr->next=rPtr->next;
                delete rPtr;
                num_of_element--;
            }
            else nPtr=nPtr->next;
        }
    }
}

/*
 * merge in ascending order
 */
template<class T>
void LinkedList<T>::merge(const List<T> &ot) {
    /*
     * TODO: homework
     */
    const List<T> *lPtr = &ot;
    const LinkedList<T> * ll = dynamic_cast<const LinkedList<T>*>(lPtr);

    ListNode<T> *nPtr1 = head;
    ListNode<T> *nPtr2 = ll->head;

    if(nPtr2->next==NULL);
    else{
        while(nPtr1->next!=NULL&&nPtr2->next!=NULL){
            if(nPtr1->next->val<=nPtr2->next->val)nPtr1=nPtr1->next;
            else{
                ListNode<T> *pPtr = new ListNode<T>(nPtr2->next->val);
                pPtr->next=nPtr1->next;
                nPtr1->next=pPtr;
                nPtr1=nPtr1->next;
                nPtr2=nPtr2->next;
                num_of_element++;
            }
        }
        while(nPtr2->next!=NULL){
            nPtr1->next=new ListNode<T>(nPtr2->next->val);
            nPtr1=nPtr1->next;
            nPtr1->next=NULL;
            nPtr2=nPtr2->next;
            num_of_element++;
        }
    }
}

template<class T>
void LinkedList<T>::reverse_iterative() {
    /*
     * TODO: homework
     */
    if(num_of_element>1){
        ListNode<T> *pivot = head->next;
        ListNode<T> *ptr = pivot;
        ListNode<T> *prev = pivot;

        while(pivot->next!=NULL){
            ptr = pivot->next;
            pivot->next=ptr->next;
            ptr->next = prev;
            head->next=ptr;
            prev = ptr;
        }
    }
}