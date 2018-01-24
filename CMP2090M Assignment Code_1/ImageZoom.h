#pragma once
#include "Image.h"
//#include <cstdio> 
//#include <iostream>
//#include <cstdlib> 
//#include <cstdio> 
//#include<iostream>
//#include<string>

// class declaration
class ImageZoom :// inherits functions from the Image base class, even the private data, does not hold any private data, they are inherited from the base image class, the functions as well
	public Image
{
public:
		// Rgb structure, i.e. a pixel, group of data elements grouped together under one name
		//constructor of the image object, 
		ImageZoom() : Image() {};
		// if the image has something inside, and if there is rgb thats empty it will be filled as black
		ImageZoom (const unsigned int &_w, const unsigned int &_h, const Rgb &c = Rgb(0)) : Image(_w,_h,c)
		{// derive all from the base class
		}
		int Width(int wi); //calling the following functions from different classess, giving us different output(like image short, image zoomed, image float) applies polymorphism
		int Height(int he); 
		unsigned int getWidth(); 
		unsigned int getHeight();
		std::string imgType();
		void data_type(); 
		float getSize(); 

		//POLYMORPHISM BELOW- the display function on the console and into the log file
		void DisplayFunction(std::string caller);
	virtual ~ImageZoom();
};

