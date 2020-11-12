#include <stdlib.h>
#include "LinkedListDataStructure.h"
#include <assert.h>

static Node* _get_new_node_(int32_t val){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = NULL;

    return newnode;
}

sList newList(){
    sList newList = {NULL , NULL , 0};
    return newList;
}
sList addHead(sList* eList , int32_t data){
    assert(eList != NULL);
    Node *newNode = _get_new_node_(data);
    if(eList->head == NULL){
        eList->head = newNode;
        eList->tail = newNode;
    }
    else{
        newNode->next = eList->head;
        eList->head = newNode;
    }

    ++eList->length;

    return *eList;
}

sList addtail(sList *eList , int32_t data){
    Node *newNode = _get_new_node_(data);
    if(eList->tail == NULL){
        eList->head = newNode;
        eList->tail = newNode;
    }
    else{
        eList->tail->next = newNode;
        eList->tail = newNode;
    }
    ++eList->length;
    return *eList;
}

sList deltail(sList *eList ){
   assert(eList != NULL);
    Node *last, *cur;

    if(eList->tail != NULL){
        last = eList->tail;
        if(eList->head == eList->tail){
            eList->head = eList->tail = NULL;
        }
        else{
            for(cur = eList->head; cur->next != last; cur=cur->next);
            eList->tail =cur;
            cur->next = NULL;
        }
        --eList->length;
        free(last);
    }
    return *eList;
}

sList delHead(sList *eList ){
    sList templist = *eList;
    templist.head = eList->head->next;
    Node *tempNode = eList->head;

    free(tempNode);
    --templist.length;
    return templist;
}
uint8_t findKey(sList *eList , int32_t key){
    assert(eList != NULL);

    if(eList->head != NULL){
        Node *temp = eList->head;
        uint32_t len = eList->length;
        while(len !=0){
            if(temp->data == key){

                return 1;
                //break;
            }

            temp = temp->next;

            --len;
        }
    }
return 0;

}

int32_t length(sList *eList){
    assert(eList != NULL);
    return eList->length;
}

/*For printing full list
 *
 */

void printList(sList *eList){
    Node *ptr = eList->head;
    int32_t len = eList->length;
    printf("Length Data - %d\n" , len);
    while(len !=0){
        printf("List Data - %d\n" , ptr->data);
        ptr = ptr->next;
        --len;
    }
}

int32_t maxi(sList *eList){
    Node *temp = eList->head;
    int32_t len = eList->length;

    int32_t max = temp->data;
    while(len != 0){
        if(temp->data >= max){
            max = temp->data;
        }
      temp = temp->next;
      --len;
    }
     return max;
}
int32_t mini(sList *eList){
 Node *temp = eList->head;
    int32_t len = eList->length;

    int32_t min = temp->data;
    while(len != 0){
        if(temp->data <= min){
            min = temp->data;
        }
      temp = temp->next;
      --len;
    }
     return min;
}

sList addAt(sList *eList ,int8_t index , int32_t data){
    assert(eList != NULL);
    int8_t len = 0;
    if(index == 0){
        *eList = addHead(eList , data);
    }
    else if(index == eList->length){
        *eList = addtail(eList , data);
    }
    else{
        Node *newNode = _get_new_node_(data);
        Node *tempNode = eList->head;
        while(len != eList->length){
            if(len == index-1){
                newNode->next = tempNode->next;
                tempNode->next = newNode;
                ++eList->length;
                break;
            }
            tempNode = tempNode->next;
            ++len;
        }
    }
    return *eList;
}
sList delAt(sList *eList ,int32_t data){
    assert(eList != NULL);
    int8_t len = eList->length;
    if(data == eList->head->data){
        *eList = delHead(&eList);
    }
    else if(data == eList->tail->data){
        *eList = deltail(&eList);
    }
    else{
        Node *prevNode = eList->head;
        Node *curNode = prevNode->next;
        while(len != 1){
            if(curNode->data == data){
                prevNode->next = curNode->next;
                free(curNode);
                --eList->length;

                break;
            }
            prevNode = curNode;
            curNode = curNode->next;
            --len;
        }
    }
    return *eList;
}

sList reverseList(sList *eList){
    sList newlist = newList();
    int32_t datas;
    int8_t len = eList->length;
    while(len != 0){
        Node *node = eList->head;

        eList->head = eList->head->next;
        datas = node->data;

        newlist = addHead(&newlist , datas);


        --len;
    }
    return newlist;
}
int8_t isSame(sList *list1 , sList *list2){
    assert(list1 != NULL);
    assert(list2 != NULL);
    int8_t len = list1->length;

    Node *node1 = list1->head, *node2 =list2->head;

    while(len != 0){
        if(node1->data != node2->data){
            return 0;
            //break;
        }
        node1 = node1->next;
        node2 = node2->next;
        --len;
    }
    return 1;
}
sList unionList(sList *list1 , sList *list2){
    sList uList = newList();
    int8_t len = list1->length;
    int8_t len2 = list2->length;
    Node *temp = list1->head;
    Node *temp2 = list2->head;

    while(len != 0){
        uList = addHead(&uList , temp->data);

        temp = temp->next;
        --len;
    }
    while(len2 != 0){
        uList = addHead(&uList , temp2->data);
        temp2 = temp2->next;
        --len2;
    }
return uList;
}
sList intersection(sList *list1 , sList *list2){
    Node *n1 = list1->head;
    sList interList = newList();
    int8_t len = list1->length;

    while(len != 0){
        if (findKey(list2 , n1->data) == 1){

            interList = addHead(&interList,n1->data);
        }
        n1 = n1->next;
        --len;
    }
    return interList;
}
sList uniqueList(sList *list1 ){
    Node *n1 = list1->head;
    sList uqList = newList();
    uqList = addHead(&uqList , n1->data);
    n1 = n1->next;
    int8_t len = list1->length;
    while(len != 1){
        if (findKey(&uqList , n1->data) == 0 ){
            uqList = addHead(&uqList , n1->data);
            n1 = n1->next;
        }
        --len;
    }
    return uqList;
}
