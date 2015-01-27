
#include "Scene.h"
#include "Color.h"
#include "Bmpfile.H"
#include "Ray.h"

 void CRTScene::Render(std::string sFilename, int nWidth, int nHeight)
{
     unsigned char *buf;
     buf = (unsigned char*)malloc(3*nWidth*nHeight*sizeof(unsigned char));
     CRTColor color(1,0,0);
     BMPFile bmp;
     for(int i = 0; i<nHeight; i++){
         for(int j=0; j<nWidth; j++){
             CRTRay ray;
             ray.setVOrigine(CRTVector(j,i,0));
             ray.setVDirection(CRTVector(0,0,1));
             int k(0);
             for(k = 0; k<spheres.size();k++){
                 if(spheres.at(k).getNearestItersectionDistance(ray)<=0.0){
                    buf[3*(i*nWidth+j)] = (unsigned char)spheres.at(k).color.m_fB*255;
                    buf[3*(i*nWidth+j)+1] =(unsigned char) spheres.at(k).color.m_fG*255;
                    buf[3*(i*nWidth+j)+2] = (unsigned char) spheres.at(k).color.m_fR*255;
                    break;
                 }
             }
            if(k>=spheres.size()){
                buf[3*(i*nWidth+j)] = buf[3*(i*nWidth+j)+1] = buf[3*(i*nWidth+j)+2] = 255;
            }

         }

     }

    bmp.SaveBMP(sFilename,buf, nWidth,nHeight);
    free(buf);
 }

 void CRTScene::addSphere(const CRTSphere &value)
 {
     spheres.push_back(value);
 }

