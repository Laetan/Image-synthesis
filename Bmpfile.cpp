
//#include "..\stdafx.h"
#include "bmpfile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include <stdio.h>

#define BITMAP_ID 0x4D42 // ID bitmap universel
#define BI_RGB 0x0 // ID compression bitmap universel. Pas de compression
#define BI_RLE8 0x1 // ID compression bitmap universel. Compression 8 bits par pixel
#define BI_RLE4 0x2 // ID compression bitmap universel. Compression 4 bits par pixel

typedef struct BITMAPFILEHEADER
{
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
} BITMAPFILEHEADER ;

typedef struct BITMAPINFOHEADER{
  DWORD  biSize;
  DWORD  biWidth;
  DWORD  biHeight;
  WORD   biPlanes;
  WORD   biBitCount;
  DWORD  biCompression;
  DWORD  biSizeImage;
  DWORD  biXPelsPerMeter;
  DWORD  biYPelsPerMeter;
  DWORD  biClrUsed;
  DWORD  biClrImportant;

} BITMAPINFOHEADER;

BMPFile::BMPFile()
{
	m_errorText="OK";
}

////////////////////////////////////////////////////////////////////////////
//	write a 24-bit BMP file
//
//	image MUST be a packed buffer (not DWORD-aligned)
//	image MUST be vertically flipped !
//	image MUST be BGR, not RGB !
//

void BMPFile::SaveBMP(std::string fileName,		// output path
							BYTE * buf,				// BGR buffer
							UINT width,				// pixels
							UINT height)
{
	short res1=0;
    short res2=0;
    long pixoff=54;
    long compression=0;
    long cmpsize=0;
    long colors=0;
    long impcol=0;
	char m1='B';
	char m2='M';

	m_errorText="OK";

	DWORD widthDW = WIDTHBYTES(width * 24);

	long bmfsize=sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) +
  							widthDW * height;	
	long byteswritten=0;

	BITMAPINFOHEADER header;
  	header.biSize=40; 						// header size
	header.biWidth=width;
	header.biHeight=height;
	header.biPlanes=1;
	header.biBitCount=24;					// RGB encoded, 24 bit
	header.biCompression=BI_RGB;			// no compression
	header.biSizeImage=0;
	header.biXPelsPerMeter=0;
	header.biYPelsPerMeter=0;
	header.biClrUsed=0;
	header.biClrImportant=0;

	FILE *fp;	
	fopen_s(&fp,fileName.c_str(),"wb");
	if (fp==NULL) {
		m_errorText="Can't open file for writing";
		return;
	}

	// should probably check for write errors here...
	
	fwrite((BYTE  *)&(m1),1,1,fp); byteswritten+=1;
	fwrite((BYTE  *)&(m2),1,1,fp); byteswritten+=1;
	fwrite((long  *)&(bmfsize),4,1,fp);	byteswritten+=4;
	fwrite((int  *)&(res1),2,1,fp); byteswritten+=2;
	fwrite((int  *)&(res2),2,1,fp); byteswritten+=2;
	fwrite((long  *)&(pixoff),4,1,fp); byteswritten+=4;

	fwrite((BITMAPINFOHEADER *)&header,sizeof(BITMAPINFOHEADER),1,fp);
	byteswritten+=sizeof(BITMAPINFOHEADER);
	
	long row=0;
	long rowidx;
	long row_size;
	row_size=header.biWidth*3;
    long rc;
	for (row=0;row<(long)header.biHeight;row++) {
		rowidx=(long unsigned)row*row_size;						      

		// write a row
		rc=(long)fwrite((void  *)(buf+rowidx),row_size,1,fp);
		if (rc!=1) {
			m_errorText="fwrite error\nGiving up";
			break;
		}
		byteswritten+=row_size;	

		// pad to DWORD
		for (DWORD count=row_size;count<widthDW;count++) {
			char dummy=0;
			fwrite(&dummy,1,1,fp);
			byteswritten++;							  
		}

	}
           
	fclose(fp);
}
