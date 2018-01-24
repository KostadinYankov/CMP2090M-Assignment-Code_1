#pragma once
#include <cstdlib> 
#include <cstdio> 
#include<iostream>

class ImageF {
private:
	unsigned int w, h; // ImageF resolution 
public:
	ImageF ();
	//Rgb structure, i.e. a pixel, group of data elements grouped together under one name
	struct Rgb
	{
		// when createing an ImageF this creates the 1d array for all of the pixels
		Rgb();
		Rgb(float c); 
		Rgb(float _r, float _g, float _b); 
		bool operator != (const Rgb &c) const;
		Rgb& operator *= (const Rgb &rgb);
		Rgb& operator += (const Rgb &rgb);
		float r, g, b;
	};
	//constructor of the ImageF object, 
	// if the ImageF has something inside, and if there is rgb thats empty it will be filled as black
	ImageF(const unsigned int &_w, const unsigned int &_h, const Rgb &c = kBlack);
	//deconstructor of ImageF
	~ImageF()
	{
	}
	Rgb *pixels; // 1D array of pixels 
	static const Rgb kBlack, kWhite, kRed, kGreen, kBlue; // Preset colors 
	void Width( int wi); //encapsulation
	void Height(int he); 
	unsigned int getWidth(); 
	unsigned int getHeight(); 
	void data_type();
	std::string imgType(); 
	float getSize(); 
	void DisplayFunction(std::string caller);
}; 

