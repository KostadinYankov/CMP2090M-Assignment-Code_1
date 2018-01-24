#include "ImageF.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include<string>
// the class functions definitions
const ImageF::Rgb ImageF::kBlack = ImageF::Rgb(0);
const ImageF::Rgb ImageF::kWhite = ImageF::Rgb(1);
const ImageF::Rgb ImageF::kRed = ImageF::Rgb(1, 0, 0);
const ImageF::Rgb ImageF::kGreen = ImageF::Rgb(0, 1, 0);
const ImageF::Rgb ImageF::kBlue = ImageF::Rgb(0, 0, 1);

ImageF::ImageF() : w(0), h(0), pixels(nullptr)
{ /* empty ImageF */
}

ImageF::ImageF (const unsigned int & _w, const unsigned int & _h, const Rgb & c) :w(_w), h(_h), pixels(NULL)
{
	//std::cout << "default ImageF class called" << std::endl;
	pixels = new Rgb[w * h];

	for (unsigned int i = 0; i < (w * h); ++i)
		pixels[i] = c;
}

void ImageF::Width(int wi)
{
	this->w = wi;
}

void ImageF::Height(int he) { this->h = he; }

unsigned int ImageF::getWidth()
{
	return w;
}

unsigned int ImageF::getHeight()
{
	return h;
}

void ImageF::data_type()
{
	std::cout << "FLOAT" << std::endl; //polymorphism applied
}

std::string ImageF::imgType()
{
	return "FLOAT";
}

float ImageF::getSize()
{
	return ((this->w*this->h) * 3.f) / (1024.f*1024.f);
}

inline ImageF::Rgb::Rgb() : r(0), g(0), b(0) {}

inline ImageF::Rgb::Rgb(float c) : r(c), g(c), b(c) {}

inline ImageF::Rgb::Rgb(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {}

bool ImageF::Rgb::operator!=(const Rgb & c)const
{
	return c.r != r || c.g != g || c.b != b;
}

ImageF::Rgb & ImageF::Rgb::operator*=(const Rgb & rgb)
{
	r *= rgb.r, g *= rgb.g, b *= rgb.b; return *this;
}

ImageF::Rgb & ImageF::Rgb::operator+=(const Rgb & rgb)
{
	r += rgb.r, g += rgb.g, b += rgb.b; return *this;
}

void ImageF::DisplayFunction(std::string caller)
{
	//setcolor(15);
	std::ofstream outputInfo;// create a file object 
	outputInfo.open("outputInfo.txt", std::ios_base::app);
	outputInfo << "Exporting data into text file...\n" << std::endl;
	// displays in the console
	std::cout << "The width of the " << caller << " image is: " << getWidth() << " px." << std::endl;
	std::cout << "The height of the " << caller << " image is: " << getHeight() << " px." << std::endl;
	std::cout << "The size of the " << caller << " image in MB is: " << getSize() << std::endl;
	std::cout << "The data type of the " << caller << " image is: " << imgType() << std::endl;
	// imports in to the log txt file
	outputInfo << "The width of the " << caller << " image is: " << getWidth() << " px." << std::endl;
	outputInfo << "The height of the " << caller << " image is: " << getHeight() << " px." << std::endl;
	outputInfo << "The size of the " << caller << " image in MB is: " << getSize() << std::endl;
	outputInfo << "The data type of the " << caller << " image is: " << imgType() << std::endl;
	outputInfo << "\n";
	outputInfo.close();
	//setcolor(7);
}
