#include "element.h"

Element::Element()
{
}
char* Element::getContenue(){
    if(feu != NULL)return feu->className();
    else if(agent != NULL) return agent->className();
    return "";
}
