#include <stdlib.h>
#include <stdbool.h>

#include "intSortedSetADT.h"
#include "intLinkedListSortedSetADT.h"

IntSortedSetADT mkSSet() {
    IntSortedSetADT newset = malloc(sizeof(struct intSortedSet));
    if (newset == NULL){
        return NULL;
    }
    newset->first = NULL;
    newset->last = NULL;
    newset->size = 0;
    return newset;
}

_Bool dsSSet(IntSortedSetADT *ssptr) {
    if (ssptr == NULL || *ssptr == NULL){
         return false;
    }
    ListNodePtr curr = (*ssptr)->first;
    while (curr != NULL) {
        ListNodePtr next = curr->next;
        free(curr);
        curr = next;
    }
    free(*ssptr);
    *ssptr = NULL;
    return true;
}

_Bool sset_add(IntSortedSetADT ss, const int elem) {
    if (ss == NULL) {
        return false;
    }
    ListNodePtr prev = NULL, curr = ss->first;
    while (curr != NULL && curr->elem < elem) {
        prev = curr;
        curr = curr->next;
    }
    if (curr != NULL && curr->elem == elem) {
        return false;
    }

    ListNodePtr newNode = malloc(sizeof(struct listNode));
    if (newNode == NULL) {
        return false;
    }
    newNode->elem = elem;
    newNode->next = curr;

    if (prev == NULL) {
        ss->first = newNode;
    } else {
        prev->next = newNode;
    }
    if (curr == NULL) {
        ss->last = newNode;
    }
    ss->size++;
    return true;
}

_Bool sset_remove(IntSortedSetADT ss, const int elem) {
    if (ss == NULL){
        return false;
    }
    ListNodePtr prev = NULL, curr = ss->first;
    while (curr != NULL && curr->elem < elem) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL || curr->elem != elem){
        return false;
    }
    if (prev == NULL){
        ss->first = curr->next;
    }
    else{
        prev->next = curr->next;
    }

    if (curr == ss->last){
        ss->last = prev;
    }
    free(curr);
    ss->size--;
    return true;
}

_Bool sset_member(const IntSortedSetADT ss, const int elem) {
    if (ss == NULL){ 
        return false;
    }
    ListNodePtr curr = ss->first;
    while (curr != NULL && curr->elem < elem){
         curr = curr->next;
    }
    return (curr != NULL && curr->elem == elem);
}

_Bool isEmptySSet(const IntSortedSetADT ss) {
    if (ss == NULL){
        return false;
    }
    return (ss->size == 0);
}

int sset_size(const IntSortedSetADT ss) {
    return (ss == NULL) ? -1 : ss->size;
}

_Bool sset_extract(IntSortedSetADT ss, int *ptr) {
    if (ss == NULL || ss->first == NULL || ptr == NULL){
        return false;
    }
    ListNodePtr node = ss->first;
    *ptr = node->elem;
    ss->first = node->next;
    if (ss->first == NULL){
        ss->last = NULL;
    }
    free(node);
    ss->size--;
    return true;
}

_Bool sset_equals(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if (s1 == NULL || s2 == NULL || s1->size != s2->size){
        return false;
    }
    ListNodePtr n1 = s1->first, n2 = s2->first;
    while (n1 != NULL && n2 != NULL) {
        if (n1->elem != n2->elem){
            return false;
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    return true;
}

_Bool sset_subseteq(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if (s1 == NULL || s2 == NULL) return false;

    ListNodePtr c1 = s1->first, c2 = s2->first;
    while (c1 != NULL) {
        while (c2 != NULL && c2->elem < c1->elem) c2 = c2->next;
        if (c2 == NULL || c2->elem != c1->elem) return false;
        c1 = c1->next;
    }
    return true;
}

_Bool sset_subset(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    return sset_subseteq(s1, s2) && (s1->size < s2->size);
}

IntSortedSetADT sset_union(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if(!s1 || !s2){
        return NULL;
    }
    IntSortedSetADT result = mkSSet();
    if (s1->size !=0 ) {
        ListNodePtr curr = s1->first;
        while (curr != NULL) {
            sset_add(result, curr->elem);
            curr = curr->next;
        }
    }
    if (s2->size !=0) {
        ListNodePtr curr = s2->first;
        while (curr != NULL) {
            sset_add(result, curr->elem);
            curr = curr->next;
        }
    }
    return result;
}

IntSortedSetADT sset_intersection(const IntSortedSetADT s1, const IntSortedSetADT s2) {
     if(!s1 || !s2){
        return NULL;
    }
    IntSortedSetADT result = mkSSet();
    if (s1->size ==0  || s2->size ==0) { 
        return result;
    }
    ListNodePtr a = s1->first;
    while (a != NULL) {
        if (sset_member(s2, a->elem)) {
            sset_add(result, a->elem);
        }
        a = a->next;
    }
    return result;
}

IntSortedSetADT sset_subtraction(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if(!s1 || !s2){
        return NULL;
    }
    IntSortedSetADT result = mkSSet();
    if (result == NULL) { 
        return NULL;
    }
    if (s1 == NULL) { 
        return result;
    }
    ListNodePtr curr = s1->first;
    while (curr != NULL) {
        if (s2 == NULL || !sset_member(s2, curr->elem)) {
            sset_add(result, curr->elem);
        }
        curr = curr->next;
    }
    return result;
}

_Bool sset_min(const IntSortedSetADT ss, int *ptr) {
    if (ss == NULL || ss->first == NULL || ptr == NULL) return false;
    *ptr = ss->first->elem;
    return true;
}

_Bool sset_max(const IntSortedSetADT ss, int *ptr) {
    if (ss == NULL || ss->last == NULL || ptr == NULL) return false;
    *ptr = ss->last->elem;
    return true;
}

_Bool sset_extractMin(IntSortedSetADT ss, int *ptr) {
    return sset_extract(ss, ptr);
}

_Bool sset_extractMax(IntSortedSetADT ss, int *ptr) {
    if (ss == NULL || ss->last == NULL || ptr == NULL){
        return false;
    }
    ListNodePtr curr = ss->first, prev = NULL;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    *ptr = curr->elem;
    if (prev == NULL) {
        ss->first = NULL;
        ss->last = NULL;
    } else {
        prev->next = NULL;
        ss->last = prev;
    }

    free(curr);
    ss->size--;
    return true;
}

