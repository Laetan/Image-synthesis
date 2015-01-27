
#ifndef __BASEOBJECT_H
#define __BASEOBJECT_H

#include <stdlib.h>
#include <string>
#include "Color.h"


class CRTBaseObject
{
public:

    //CRTColor getColor() const;
    //void setColor(const CRTColor &value);
    CRTColor color;
protected :

    std::string id;

} ;

#endif
