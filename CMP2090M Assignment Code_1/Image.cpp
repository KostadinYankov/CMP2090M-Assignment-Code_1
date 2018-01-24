#include "Image.h"
#include <iostream>
#include <fstream>
#include <sstream>
// the class functions definitions
const Image::Rgb Image::kBlack = Image::Rgb(0);
const Image::Rgb Image::kWhite = Image::Rgb(1);
const Image::Rgb Image::kRed = Image::Rgb(1, 0, 0);
const Image::Rgb Image::kGreen = Image::Rgb(0, 1, 0);
const Image::Rgb Image::kBlue = Image::Rgb(0, 0, 1);

Image::Image() : w(0), h(0), pixels(nullptr)
{ /* empty image */ }

Image::Image(const unsigned int & _w, const unsigned int & _h, const Rgb & c) :	w(_w), h(_h), pixels(NULL)
{
	//std::cout << "default image class called" << std::endl;
	pixels = new Rgb[w * h];
	for (unsigned int i = 0; i < (w * h); ++i)
		pixels[i] = c;
}

void Image::Width(int wi)
{
	this->w = wi;
}

void Image::Height(int he) { this->h = he; }

unsigned int Image::getWidth()
{
	return w;
}

unsigned int Image::getHeight()
{
	return h;
}

void Image::data_type()
{  std::cout << "CHAR" << std::endl; //polymorphism applied
}

std::string Image::imgType()
{
	return "CHAR";
}

float Image::getSize()
{
	return ((this->w*this->h) * 3.f) / (1024.f*1024.f);
}

inline Image::Rgb::Rgb() : r(0), g(0), b(0) {}

inline Image::Rgb::Rgb(unsigned char c) : r(c), g(c), b(c) {}

inline Image::Rgb::Rgb(unsigned char _r, unsigned char _g, unsigned char _b) : r(_r), g(_g), b(_b) {}

bool Image::Rgb::operator!=(const Rgb & c)const
{
	return c.r != r || c.g != g || c.b != b;
}

Image::Rgb & Image::Rgb::operator*=(const Rgb & rgb) 
{
	r *= rgb.r, g *= rgb.g, b *= rgb.b; return *this;
}

Image::Rgb & Image::Rgb::operator+=(const Rgb & rgb)
{
	r += rgb.r, g += rgb.g, b += rgb.b; return *this;
}

void Image::DisplayFunction(std::string caller)
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