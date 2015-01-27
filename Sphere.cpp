
#include "Sphere.h"
#include "math.h"


float CRTSphere::getNearestItersectionDistance(const CRTRay &rRay)
{
    float minT =  -1*(rRay.vDirection().x*(rRay.vOrigine().x-position.x)+rRay.vDirection().y*(rRay.vOrigine().y-position.y)+rRay.vDirection().z*(rRay.vOrigine().z-position.z));
    minT/= rRay.vDirection().x*rRay.vDirection().x+rRay.vDirection().y*rRay.vDirection().y+rRay.vDirection().z*rRay.vDirection().z;

    return minT*minT*(rRay.vDirection().x*rRay.vDirection().x+rRay.vDirection().y*rRay.vDirection().y+rRay.vDirection().z*rRay.vDirection().z)- minT*2*(rRay.vDirection().x*(rRay.vOrigine().x-position.x)+rRay.vDirection().y*(rRay.vOrigine().y-position.y)+rRay.vDirection().z*(rRay.vOrigine().z-position.z))+pow(rRay.vOrigine().x-position.x,2)+pow(rRay.vOrigine().y-position.y,2)+pow(rRay.vOrigine().z-position.z,2) - R*R;
}
float CRTSphere::getR() const
{
    return R;
}

void CRTSphere::setR(float value)
{
    R = value;
}
CRTVector CRTSphere::getPosition() const
{
    return position;
}

void CRTSphere::setPosition(const CRTVector &value)
{
    position = value;
}


