
#ifndef __SCENE_H
#define __SCENE_H

#include <stdlib.h>
#include <string>
#include <vector>
#include "Sphere.h"

class CRTScene
{
public:
    void Render(std::string sFilename, int nWidth, int nHeight);
    void addSphere(const CRTSphere &value);

protected:
    std::vector<CRTSphere> spheres;

} ;

#endif
