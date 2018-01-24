#pragma once
#include <cstdlib> 
#include <cstdio> 
#include<iostream>
#include<string>

class Image;//default class		
class ImageZoom;// Zoomed derived class from Image 
class ImageShort;// class that uses chort data type, for the mean
class ImageF;// class that uses float data type, for the sigma
//function declarations
class Functions 
{public:

	std::string setcolor(unsigned short color);//changes color in console
	Image MeanFunction();//calculates mean
	void CreateMeanPic();
	void MedianFunction();//calculates median
	void SigmaClippedMean();//calculates sigma 
	Image Nearest_Neighbour2x();// applies NN 2x algorithm
	void Nearest_Neighbour4x();// uses NNx4 and does it again in order to acheive an omage 4x zoomed
	void Bilinear_Interpolation();
};