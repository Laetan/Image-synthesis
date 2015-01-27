
#include "Ray.h"

CRTVector CRTRay::vOrigine() const
{
    return m_vOrigine;
}

void CRTRay::setVOrigine(const CRTVector &vOrigine)
{
    m_vOrigine = vOrigine;
}
CRTVector CRTRay::vDirection() const
{
    return m_vDirection;
}

void CRTRay::setVDirection(const CRTVector &vDirection)
{
    m_vDirection = vDirection;
}

