#include <iostream>
#include <string>
using namespace std;


//Односвязный список
struct NODE {
    char value;
    struct NODE* next;
};
struct DbCircleList {
    size_t size;
    struct NODE* head;
};
void addNode(DbCircleList* list, char elem)
{
    NODE* newElem = new NODE;
    newElem->value = elem;
    if (list->size == 0)
    {
        list->head = newElem;
        list->head->next = list->head;
    }
    else
    {
        struct NODE* temp;
        temp = list->head;
        list->head = newElem;
        newElem->next = temp;
    }
    ++list->size;
}
void printList(DbCircleList* list)
{
    NODE* tmp = list->head;
    cout << "List values: " << endl;
    for (int i = 0; i < list->size; ++i)
    {
        cout << "Value: " << tmp->value << endl;
        tmp = tmp->next;
    }
}


int main() {
    DbCircleList* list = new DbCircleList;
    list->size = 0;
    list->head = NULL;

    addNode(list, '4');
    addNode(list, '3');
    addNode(list, '2');
    addNode(list, '1');

    //printList(list); //это для проверки списка


    //это надо показать на дизассембле
    cout << "Value: " << list->head->next->next->value;
}
