#pragma once
//*********************************************
//ImageShort class to hold and allow manipulation of ImageShorts once read into the code
//from https://www.scratchapixel.com/
//*********************************************
#include <cstdlib> 
#include <cstdio> 
#include<iostream>
#include <fstream>
#include <sstream>
#include<string>


// class declaration
class ImageShort
{
private:
	unsigned int w, h; // Image resolution 
public:
	// Rgb structure, i.e. a pixel, group of data elements grouped together under one name
	struct Rgb
	{
		// when createing an image this creates the 1d array for all of the pixels
		Rgb();
		Rgb(short c);
		Rgb(short _r, short _g, short _b);
		bool operator != (const Rgb &c) const;
		Rgb& operator *= (const Rgb &rgb);
		Rgb& operator += (const Rgb &rgb);
		short r, g, b;
	};
	//constructor of the image object, 
	ImageShort();
	// if the image has something inside, and if there is rgb thats empty it will be filled as black
	ImageShort(const unsigned int &_w, const unsigned int &_h, const Rgb &c = kBlack);
	//deconstructor of image
	~ImageShort() {}
	Rgb *pixels; // 1D array of pixels 
	static const Rgb kBlack, kWhite, kRed, kGreen, kBlue; // Preset colors 
	void Width(int wi);//encapsulation
	void Height(int he);
	unsigned int getWidth();
	unsigned int getHeight();
	void data_type();
	std::string imgType();
	float getSize();
	void DisplayFunction(std::string caller);
}; 
   
