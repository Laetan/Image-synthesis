
#ifndef __SPHERE_H
#define __SPHERE_H

#include "Object.h"

#include "Vector3d.h"
#include "Ray.h"

class CRTSphere: public CRTObject
{
public:
    float getNearestItersectionDistance(const CRTRay &rRay);
    float getR() const;
    void setR(float value);

    CRTVector getPosition() const;
    void setPosition(const CRTVector &value);

protected:
    CRTVector position;
    float R;
} ;

#endif
