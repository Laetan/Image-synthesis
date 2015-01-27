#include <iostream>
#include "Scene.h"
#include "Sphere.h"
#include "Color.h"
using namespace std;

int main()
{
    CRTScene Scene;
    CRTSphere sp1,sp2,sp3,sp4;
    sp1.setPosition(CRTVector(100,100,0));
    sp1.setR(40);
    sp1.color = CRTColor(1,1,1);
    sp2.setPosition(CRTVector(100,100,0));
    sp2.setR(50);
    sp2.color = CRTColor(1,0,0);
    Scene.addSphere(sp1);
    Scene.addSphere(sp2);
    sp3.setPosition(CRTVector(200,100,0));
    sp3.setR(40);
    sp3.color = CRTColor(1,1,1);
    sp4.setPosition(CRTVector(200,100,0));
    sp4.setR(50);
    sp4.color = CRTColor(1,0,0);
    Scene.addSphere(sp3);
    Scene.addSphere(sp4);
    Scene.Render("yoyo.bmp", 300,200);
    return 0;
}

