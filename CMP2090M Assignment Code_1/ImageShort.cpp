#include "ImageShort.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include<string>
// the class functions definitions
const ImageShort::Rgb ImageShort::kBlack = ImageShort::Rgb(0);
const ImageShort::Rgb ImageShort::kWhite = ImageShort::Rgb(1);
const ImageShort::Rgb ImageShort::kRed = ImageShort::Rgb(1, 0, 0);
const ImageShort::Rgb ImageShort::kGreen = ImageShort::Rgb(0, 1, 0);
const ImageShort::Rgb ImageShort::kBlue = ImageShort::Rgb(0, 0, 1);

ImageShort::ImageShort() : w(0), h(0), pixels(nullptr)
{ /* empty ImageShort */
}

ImageShort::ImageShort(const unsigned int & _w, const unsigned int & _h, const Rgb & c) : w(_w), h(_h), pixels(NULL)
{
	//std::cout << "default ImageShort class called" << std::endl;
	pixels = new Rgb[w * h];
	for (unsigned int i = 0; i < (w * h); ++i)
		pixels[i] = c;
}

void ImageShort::Width(int wi)
{
	this->w = wi;
}

void ImageShort::Height(int he) { this->h = he; }

unsigned int ImageShort::getWidth()
{
	return w;
}

unsigned int ImageShort::getHeight()
{
	return h;
}

void ImageShort::data_type()
{
	std::cout << "SHORT" << std::endl; //polymorphism applied
}

std::string ImageShort::imgType()
{
	return "SHORT";
}

float ImageShort::getSize()
{
	return ((this->w*this->h) * 3.f) / (1024.f*1024.f);
}

inline ImageShort::Rgb::Rgb() : r(0), g(0), b(0) {}

inline ImageShort::Rgb::Rgb(short c) : r(c), g(c), b(c) {}

inline ImageShort::Rgb::Rgb(short _r, short _g, short _b) : r(_r), g(_g), b(_b) {}

bool ImageShort::Rgb::operator!=(const Rgb & c)const
{
	return c.r != r || c.g != g || c.b != b;
}

ImageShort::Rgb & ImageShort::Rgb::operator*=(const Rgb & rgb)
{
	r *= rgb.r, g *= rgb.g, b *= rgb.b; return *this;
}

ImageShort::Rgb & ImageShort::Rgb::operator+=(const Rgb & rgb)
{
	r += rgb.r, g += rgb.g, b += rgb.b; return *this;
}

void ImageShort::DisplayFunction(std::string caller)
{
	//setcolor(15);
	std::ofstream outputInfo;// create a file object 
	outputInfo.open("outputInfo.txt", std::ios_base::app);
	outputInfo << "Exporting data into text file...\n" << std::endl;
	// displays in the console
	std::cout << "The width of the " << caller << " image is: " << getWidth() << " px." << std::endl;
	std::cout << "The height of the " << caller << " image is: "  << getHeight() << " px." << std::endl ;
	std::cout << "The size of the " << caller << " image in MB is: "  << getSize()  << std::endl ;
	std::cout << "The data type of the " << caller << " image is: "  << imgType() << std::endl ;
		// imports in to the log txt file
	outputInfo << "The width of the " << caller << " image is: " << getWidth() << " px." << std::endl;
	outputInfo << "The height of the " << caller << " image is: " << getHeight() << " px."  << std::endl;
	outputInfo << "The size of the " << caller << " image in MB is: " << getSize()  << std::endl;
	outputInfo << "The data type of the " << caller << " image is: " << imgType()  << std::endl;
	outputInfo << "\n";
	outputInfo.close();
	//setcolor(7);
}


