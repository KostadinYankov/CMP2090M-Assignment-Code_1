#include "ImageZoom.h"
#include <iostream>
#include <fstream>
#include <sstream>
// the class functions definitions
ImageZoom::~ImageZoom()
{
}

int ImageZoom::Width(int wi)
{
	 Image::Width(wi); 
}

int ImageZoom::Height(int he)
{
	 Image::Height(he); 
}

unsigned int ImageZoom::getWidth()
{
	return Image::getWidth();
}

unsigned int ImageZoom::getHeight()
{
	return Image::getHeight();
}

std::string ImageZoom::imgType()
{
	return "CHAR... in Zoom class";
}

void ImageZoom::data_type()
{
	std::cout << "CHAR... in Zoom class" << std::endl;
}

float ImageZoom::getSize()
{
	return ((this->getWidth()*this->getHeight()) * 3.f) / (1024.f*1024.f);
}

//polymorphism. below
//calling the following function from different classess, giving us different output(like image short, image zoomed) 
void ImageZoom::DisplayFunction(std::string caller)
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
	 //imports in to the log txt file
	outputInfo << "The width of the " << caller << " image is: " << getWidth() << " px." << std::endl;
	outputInfo << "The height of the " << caller << " image is: " << getHeight() << " px." << std::endl;
	outputInfo << "The size of the " << caller << " image in MB is: " << getSize() << std::endl;
	outputInfo << "The data type of the " << caller << " image is: " << imgType() << std::endl;
	outputInfo << "\n";
	outputInfo.close();
	//setcolor(7);
}
