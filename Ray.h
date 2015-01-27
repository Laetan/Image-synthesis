
#ifndef __RAY_H
#define __RAY_H

#include "Vector3d.h"

class CRTRay
{
public:

    CRTVector vOrigine() const;
    void setVOrigine(const CRTVector &vOrigine);

    CRTVector vDirection() const;
    void setVDirection(const CRTVector &vDirection);

protected:
    CRTVector m_vOrigine,m_vDirection;

} ;

#endif
