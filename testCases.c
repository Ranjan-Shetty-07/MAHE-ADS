#include<stdlib.h>
#include "LinkedListDataStructure.h"
#include <assert.h>

void test(){
    int32_t val  ;
    /*
    *New Empty list
    */
    sList linkedlist = newList();
    assert(linkedlist.head == NULL);
    assert(linkedlist.tail == NULL);
    assert(linkedlist.length == 0);

    /*
    *Add new node to tail
    */
    val = 68;
    linkedlist = addtail(&linkedlist , val);
    assert(linkedlist.tail->data == 68);
    assert(linkedlist.tail->next == NULL);

    /*
    *Add new node to head
    */
    val  =  32;
    linkedlist = addHead(&linkedlist , val);
    assert(linkedlist.head->data == 32);

    val  =  352;
    linkedlist = addHead(&linkedlist , val);
    assert(linkedlist.head->data == 352);
    assert(linkedlist.length == 3);

    /*
    *Add new node to tail
    */
    val = 234;
    linkedlist = addtail(&linkedlist , val);
    assert(linkedlist.tail->data == 234);
    assert(linkedlist.tail->next == NULL);

    /*
    *Delete node at head
    */
    linkedlist = delHead(&linkedlist);
    assert(linkedlist.head->data == 32);

}

void test_case_2(){

    int32_t val;
    sList linkedlist = newList();


    val = 68;
    linkedlist = addtail(&linkedlist , val);
    assert(linkedlist.tail->data == 68);

    val  =  352;
    linkedlist = addHead(&linkedlist , val);
    assert(linkedlist.head->data == 352);


    val = 34;
    linkedlist = addtail(&linkedlist , val);
    assert(linkedlist.tail->data == 34);


    val  =  2;
    linkedlist = addHead(&linkedlist , val);
    assert(linkedlist.head->data == 2);

    uint8_t find = findKey(&linkedlist , 34);
    assert(find == 1);

    int32_t len = length(&linkedlist);
    assert(len == 4);

    linkedlist = delHead(&linkedlist);
    assert(linkedlist.head->data == 352);

    linkedlist = deltail(&linkedlist);
    assert(linkedlist.tail->data == 68);

    int32_t lens = length(&linkedlist);
    assert(lens == 2);

}

void test_case_3(){
    int32_t val;
    sList linkedlist = newList();

    val  =  35;
    linkedlist = addHead(&linkedlist , val);
    assert(linkedlist.head->data == 35);

    val  =  52;
    linkedlist = addHead(&linkedlist , val);
    assert(linkedlist.head->data == 52);

    val  =  42;
    linkedlist = addHead(&linkedlist , val);
    assert(linkedlist.head->data == 42);

    val  =  89;
    linkedlist = addHead(&linkedlist , val);
    assert(linkedlist.head->data == 89);

    val  =  12;
    linkedlist = addHead(&linkedlist , val);
    assert(linkedlist.head->data == 12);

    assert( maxi(&linkedlist) == 89);
    assert( mini(&linkedlist) == 12);

     val  =  67;
    linkedlist = addAt(&linkedlist ,3, val);

    printList(linkedlist);

    sList reversedlist = reverseList(&linkedlist);
    assert(reversedlist.head->data == 35);

    printList(reversedlist);


    assert(isSame(&reversedlist , &reversedlist) == 1 );



}

void test_case_4(){
    int32_t val;
    sList linkedlist = newList();

    val  =  35;
    linkedlist = addHead(&linkedlist , val);
    assert(linkedlist.head->data == 35);

    val  =  52;
    linkedlist = addHead(&linkedlist , val);
    assert(linkedlist.head->data == 52);

    val  =  35;
    linkedlist = addHead(&linkedlist , val);
    assert(linkedlist.head->data == 35);

    val  =  89;
    linkedlist = addHead(&linkedlist , val);
    assert(linkedlist.head->data == 89);

    val  =  12;
    linkedlist = addHead(&linkedlist , val);
    assert(linkedlist.head->data == 12);

    sList uList =  newList();
    uList = unionList(&linkedlist,&linkedlist);
    assert(uList.head->data == 35);

    /*
    *
    */

    val  =  89;
    sList list2 = newList();
    list2 = addHead(&list2 , val);


    val  =  12;
    list2 = addHead(&list2 , val);


    sList iList = newList();
    iList = intersection(&linkedlist,&list2);
    assert(iList.length == 2);

    sList uniList = newList();
    uniList = uniqueList(&linkedlist);
    assert(uniList.head->data == 52);
}
