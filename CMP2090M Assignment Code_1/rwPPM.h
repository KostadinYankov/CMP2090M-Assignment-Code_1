#pragma once
#include "Image.h"
#include"ImageF.h"
#include"ImageZoom.h"
// class declaration
class rwPPM // create read/write class
{
public:	
	static Image readPPM(const char *filename);//default reader 
	static ImageF readPPMF(const char *filename);// reader that reads Floats
	static void writePPM( Image &img, const char *filename);//default Writer
	static void writePPMF( ImageF &img, const char *filename);// Writer that Writes Floats
	static void writePPM( ImageZoom &img, const char *filename);// the zoom-write function name of the the function is the same but the object is different ------- overloading function ticked
};
