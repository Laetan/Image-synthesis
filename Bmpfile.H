
//	This class Copyright 1997, Chris Losinger
//	This is free to use and modify provided my name is
//	included.

#define WIDTHBYTES(bits)    (((bits) + 31) / 32 * 4)
#define BMP_HEADERSIZE (3 * 2 + 4 * 12)
#define BMP_BYTESPERLINE (width, bits) ((((width) * (bits) + 31) / 32) * 4)
#define BMP_PIXELSIZE(width, height, bits) (((((width) * (bits) + 31) / 32) * 4) * height)

#include <string>

typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef unsigned char BYTE;
typedef unsigned int UINT;

class BMPFile
{
public:
	// parameters
    std::string m_errorText;
	DWORD m_bytesRead;

public:

	// operations

	BMPFile();

    void SaveBMP(std::string fileName,		// output path
							BYTE * buf,				// RGB buffer
							UINT width,				// size
							UINT height);
};
