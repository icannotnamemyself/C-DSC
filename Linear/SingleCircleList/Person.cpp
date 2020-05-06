#include "type.h"
#include "stdlib.h"
Person CreatePerson(int pass, int index){
    Person p = (Person)malloc(sizeof (struct person));
    p->pass = pass;
    p->index = index;
    return p;
}
