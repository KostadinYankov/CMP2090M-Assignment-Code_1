#pragma once
//*********************************************
//Image class to hold and allow manipulation of images once read into the code
//from https://www.scratchapixel.com/
//*********************************************
#include <iostream>
#include <cstdlib> 
#include <cstdio> 
#include<string>

class Image // default image class amended from the basic given code, holds private variables
{
private:
	unsigned int w, h; // Image resolution 
public  :
	// Rgb structure, i.e. a pixel, group of data elements grouped together under one name
	  struct Rgb
	{
		// when createing an image this creates the 1d array for all of the pixels
		Rgb();
		Rgb(unsigned char c);
		Rgb(unsigned char _r, unsigned char _g, unsigned char _b);
		bool operator != (const Rgb &c) const;
		Rgb& operator *= (const Rgb &rgb);
		Rgb& operator += (const Rgb &rgb);
		unsigned char r, g, b;
	};
	//constructor of the image object, 
	  Image(); 
	// if the image has something inside, and if there is rgb thats empty it will be filled as black
	  Image(const unsigned int &_w, const unsigned int &_h, const Rgb &c = kBlack); 
	//deconstructor of image
	~Image() {}
	Rgb *pixels; // 1D array of pixels 
	static const Rgb kBlack, kWhite, kRed, kGreen, kBlue; // Preset colors 
	void Width(int wi);
	void Height(int he); 
	unsigned int getWidth(); 
	unsigned int getHeight(); 
	void data_type(); 
	std::string imgType(); 
	float getSize(); 

	//POLYMORPHISM BELOW - the inherited function from the zoomed class displays different information, depending ot the class
	virtual void DisplayFunction(std::string caller);
};


