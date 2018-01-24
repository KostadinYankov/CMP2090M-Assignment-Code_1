#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include<chrono>
#include<cmath>
#include <math.h>
#include "Image.h"
#include<Windows.h>
#include"rwPPM.h"
#include"ImageShort.h"
#include"Functions.h"
#include"ImageF.h"
#include"ImageZoom.h"
// the class functions definitions

//(kozettt, 2014) font color
std::string Functions::setcolor(unsigned short color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
	return "";
}

Image Functions::MeanFunction() 
{
	setcolor(11);
	std::cout << "\nMean function called." << std::endl;
	setcolor(7);
	ImageShort *meanImg = new ImageShort(3264, 2448);// create an object to hold the values
	Image *imgTemp = new(std::nothrow) Image(0, 0);

	auto start = std::chrono::system_clock::now();
	for (int i = 1; i <= 13; i++)
	{
		std::string myString = "Images/ImageStacker_set1/IMG_" + std::to_string(i) + ".ppm";// read the image and store it into my string2
		const char *myString2 = myString.c_str();
		delete[] imgTemp->pixels;
		*imgTemp = rwPPM::readPPM(myString2);
		//create a loop that goes through each picture
		for (int z = 0; z < (3264 * 2448); z++)
		{

			//adds the rgb values into my mean image
			meanImg->pixels[z].r += imgTemp->pixels[z].r;
			meanImg->pixels[z].g += imgTemp->pixels[z].g;
			meanImg->pixels[z].b += imgTemp->pixels[z].b;
		}
	}
	// goes through each mean pixel /13 r.g.b
	for (int z = 0; z < (3264 * 2448); z++)
	{
		imgTemp->pixels[z].r = meanImg->pixels[z].r / 13;
		imgTemp->pixels[z].g = meanImg->pixels[z].g / 13;
		imgTemp->pixels[z].b = meanImg->pixels[z].b / 13;
	}
	auto end = std::chrono::system_clock::now();
	
	meanImg->DisplayFunction ("Mean");
	setcolor(15);
	std::cout << "Total time for Mean operations is: " << ((std::chrono::duration<float>)(end - start)).count()<<" seconds." << std::endl;
	setcolor(7);
	delete[] meanImg->pixels;
	meanImg = NULL;
	return *imgTemp;
}

void Functions::CreateMeanPic()// outputs actual image from mean, while the mean function itself returns a tempImage, which later on it can be used for sigma calculations
{
	Image *actualImageFromMean = new Image(0, 0);
	*actualImageFromMean = MeanFunction();
	rwPPM::writePPM(*actualImageFromMean, "meanPPM.ppm");
	delete[] actualImageFromMean->pixels;
	actualImageFromMean = NULL;
}

void Functions::MedianFunction()
{
	setcolor(11);
	std::cout << "\nMedian function called." << std::endl;
	setcolor(7);
	auto start = std::chrono::system_clock::now();
	Image *medianImg = new Image(3264, 2448);// new object that will hold the final image
											 // read all images
											 // sort values in each array
											 // add 7th value from the array into empty image
											 // sort from 1-13 and save value 7
											 //do this for 7 million times
											 // write the actual image
											 //delete images to free memory
	Image *image1 = new Image(0, 0);
	image1 = &rwPPM::readPPM("Images/ImageStacker_set1/IMG_1.ppm");
	Image *image2 = new Image(0, 0);
	image2 = &rwPPM::readPPM("Images/ImageStacker_set1/IMG_2.ppm");
	Image *image3 = new Image(0, 0);
	image3 = &rwPPM::readPPM("Images/ImageStacker_set1/IMG_3.ppm");
	Image *image4 = new Image(0, 0);
	image4 = &rwPPM::readPPM("Images/ImageStacker_set1/IMG_4.ppm");
	Image *image5 = new Image(0, 0);
	image5 = &rwPPM::readPPM("Images/ImageStacker_set1/IMG_5.ppm");
	Image *image6 = new Image(0, 0);
	image6 = &rwPPM::readPPM("Images/ImageStacker_set1/IMG_6.ppm");
	Image *image7 = new Image(0, 0);
	image7 = &rwPPM::readPPM("Images/ImageStacker_set1/IMG_7.ppm");
	Image *image8 = new Image(0, 0);
	image8 = &rwPPM::readPPM("Images/ImageStacker_set1/IMG_8.ppm");
	Image *image9 = new Image(0, 0);
	image9 = &rwPPM::readPPM("Images/ImageStacker_set1/IMG_9.ppm");
	Image *image10 = new Image(0, 0);
	image10 = &rwPPM::readPPM("Images/ImageStacker_set1/IMG_10.ppm");
	Image *image11 = new Image(0, 0);
	image11 = &rwPPM::readPPM("Images/ImageStacker_set1/IMG_11.ppm");
	Image *image12 = new Image(0, 0);
	image12 = &rwPPM::readPPM("Images/ImageStacker_set1/IMG_12.ppm");
	Image *image13 = new Image(0, 0);
	image13 = &rwPPM::readPPM("Images/ImageStacker_set1/IMG_13.ppm");

	//	creater arrays 3 x [13] holding pixels to be sorted
	unsigned char rArr[13];
	unsigned char gArr[13];
	unsigned char bArr[13];

	for (int z = 0; z < (3264 * 2448); z++)// for each pixel, save the pixel value to the array
	{
		rArr[0] = image1->pixels[z].r;
		rArr[1] = image2->pixels[z].r;
		rArr[2] = image3->pixels[z].r;
		rArr[3] = image4->pixels[z].r;
		rArr[4] = image5->pixels[z].r;
		rArr[5] = image6->pixels[z].r;
		rArr[6] = image7->pixels[z].r;
		rArr[7] = image8->pixels[z].r;
		rArr[8] = image9->pixels[z].r;
		rArr[9] = image10->pixels[z].r;
		rArr[10] = image11->pixels[z].r;
		rArr[11] = image12->pixels[z].r;
		rArr[12] = image13->pixels[z].r;

		gArr[0] = image1->pixels[z].g;
		gArr[1] = image2->pixels[z].g;
		gArr[2] = image3->pixels[z].g;
		gArr[3] = image4->pixels[z].g;
		gArr[4] = image5->pixels[z].g;
		gArr[5] = image6->pixels[z].g;
		gArr[6] = image7->pixels[z].g;
		gArr[7] = image8->pixels[z].g;
		gArr[8] = image9->pixels[z].g;
		gArr[9] = image10->pixels[z].g;
		gArr[10] = image11->pixels[z].g;
		gArr[11] = image12->pixels[z].g;
		gArr[12] = image13->pixels[z].g;

		bArr[0] = image1->pixels[z].b;
		bArr[1] = image2->pixels[z].b;
		bArr[2] = image3->pixels[z].b;
		bArr[3] = image4->pixels[z].b;
		bArr[4] = image5->pixels[z].b;
		bArr[5] = image6->pixels[z].b;
		bArr[6] = image7->pixels[z].b;
		bArr[7] = image8->pixels[z].b;
		bArr[8] = image9->pixels[z].b;
		bArr[9] = image10->pixels[z].b;
		bArr[10] = image11->pixels[z].b;
		bArr[11] = image12->pixels[z].b;
		bArr[12] = image13->pixels[z].b;
		//sort the values from the rgb using STL sort algorithm  
		// here i found that using the integrated STL sort function, works slower than the insertion sort algorithm
		//std::sort(std::begin(rArr), std::end(rArr));
		//std::sort(std::begin(gArr), std::end(gArr));
		//std::sort(std::begin(bArr), std::end(bArr));
		//save the 7th only into a new picture
		//medianImg->pixels[z].g = gArr[7];
		//medianImg->pixels[z].b = bArr[7];
		unsigned char readyArr[13];
		unsigned char holdPlace = 0;
		readyArr[0] = rArr[0];

		// here using the Insertion sort algorithm, appears to work faster than the STL sort function
		for (int i = 1; i < 13; i++)// goes through redarray
		{
			if (rArr[i] >= readyArr[holdPlace])//prepares my red values
			{
				holdPlace++;
				readyArr[holdPlace] = rArr[i];
			}
			else
			{
				for (int q = 0; q <= holdPlace; q++)
				{
					if (rArr[i] <= readyArr[q])
					{
						for (int y = holdPlace; y >= q; y--)
						{
							readyArr[y + 1] = readyArr[y];
						}
						readyArr[q] = rArr[i];
						q = holdPlace;
					}
				}
				holdPlace++;
			}
		}
		medianImg->pixels[z].r = readyArr[7];
		// when the pixels are sorted we get the 7th value for the reds
		readyArr[0] = gArr[0];//start again for the blue values
		holdPlace = 0;// reset the place holder
		for (int i = 1; i < 13; i++)
		{
			if (gArr[i] >= readyArr[holdPlace])
			{
				holdPlace++;
				readyArr[holdPlace] = gArr[i];
			}
			else
			{
				for (int q = 0; q <= holdPlace; q++)
				{
					if (gArr[i] <= readyArr[q])
					{
						for (int y = holdPlace; y >= q; y--)
						{
							readyArr[y + 1] = readyArr[y];
						}
						readyArr[q] = gArr[i];
						q = holdPlace;
					}
				}
				holdPlace++;
			}
		}
		medianImg->pixels[z].g = readyArr[7];
		readyArr[0] = bArr[0];//start again for the blue values
		holdPlace = 0;// reset the place holder
		for (int i = 1; i < 13; i++)
		{
			if (bArr[i] >= readyArr[holdPlace])
			{
				holdPlace++;
				readyArr[holdPlace] = bArr[i];
			}
			else 
			{
				for (int q = 0; q <= holdPlace; q++) 
				{
					if (bArr[i] <= readyArr[q]) 
					{
						for (int y = holdPlace; y >= q; y--) 
						{
							readyArr[y + 1] = readyArr[y];
						}
						readyArr[q] = bArr[i];
						q = holdPlace;
					}
				}
				holdPlace++;
			}
		}
		medianImg->pixels[z].b = readyArr[7];
	}
	rwPPM::writePPM(*medianImg, "medianImageFinal.ppm");
	medianImg->DisplayFunction("Median");
	delete[] medianImg->pixels;
	delete[]image1->pixels;
	delete[]image2->pixels;
	delete[]image3->pixels;
	delete[]image4->pixels;
	delete[]image5->pixels;
	delete[]image6->pixels;
	delete[]image7->pixels;
	delete[]image8->pixels;
	delete[]image9->pixels;
	delete[]image10->pixels;
	delete[]image11->pixels;
	delete[]image12->pixels;
	delete[]image13->pixels;
	medianImg = NULL;
	image2 = NULL;
	image3 = NULL;
	image4 = NULL;
	image5 = NULL;
	image6 = NULL;
	image7 = NULL;
	image8 = NULL;
	image9 = NULL;
	image10 = NULL;
	image11 = NULL;
	image12 = NULL;
	image13 = NULL;
	
	auto end = std::chrono::system_clock::now();
	setcolor(15);
	std::cout << "Total time for Median operations is: " << ((std::chrono::duration<float>)(end - start)).count() <<" seconds."<< std::endl;
	setcolor(7);
}

void Functions::SigmaClippedMean() {
	setcolor(11);
	std::cout << "\nSigma clipped function called."<<std::endl;
	setcolor(7);
	std::cout << "Calculating mean..." << std::endl;
	ImageF *imgTemp = new ImageF(0, 0);
	ImageF *meanInput = new ImageF(0, 0);
	*meanInput = rwPPM::readPPMF("Images/ImageStacker_set1/IMG_1.ppm");
	auto start = std::chrono::system_clock::now();
	// calls mean calculations
	for (int i = 1; i <= 13; i++)
	{
		std::string myString = "Images/ImageStacker_set1/IMG_" + std::to_string(i) + ".ppm";
		const char *myString2 = myString.c_str();
		delete[] imgTemp->pixels;
		*imgTemp = rwPPM::readPPMF(myString2);
		//create a loop that goes through each pixel
		for (int z = 0; z < (3264 * 2448); z++)
		{
			//adds the rgb values into my mean image
			meanInput->pixels[z].r += imgTemp->pixels[z].r;
			meanInput->pixels[z].g += imgTemp->pixels[z].g;
			meanInput->pixels[z].b += imgTemp->pixels[z].b;
		}
	}
	// goes through each mean pixel /13
	for (int z = 0; z < (3264 * 2448); z++)
	{
		meanInput->pixels[z].r = meanInput->pixels[z].r / 13;
		meanInput->pixels[z].g = meanInput->pixels[z].g / 13;
		meanInput->pixels[z].b = meanInput->pixels[z].b / 13;
	}

	auto end = std::chrono::system_clock::now();
	std::cout << "Time for mean operations is: " << ((std::chrono::duration<float>)(end - start)).count() <<" seconds."<< std::endl;
	ImageF *deviation = new ImageF(3264, 2448);
	std::cout << "Calculating deviation..." << std::endl;
	for (int i = 1; i <= 13; i++)
	{

		std::string myString = "Images/ImageStacker_set1/IMG_" + std::to_string(i) + ".ppm";
		const char *myString2 = myString.c_str();
		delete[] imgTemp->pixels;
		*imgTemp = rwPPM::readPPMF(myString2);
		for (int z = 0; z < (3264 * 2448); z++)
		{

			//Calculate deviation from mean + square it for each pixel 
			deviation->pixels[z].r += ((imgTemp->pixels[z].r - meanInput->pixels[z].r) * (imgTemp->pixels[z].r - meanInput->pixels[z].r));
			deviation->pixels[z].g += ((imgTemp->pixels[z].g - meanInput->pixels[z].g) * (imgTemp->pixels[z].g - meanInput->pixels[z].g));
			deviation->pixels[z].b += ((imgTemp->pixels[z].b - meanInput->pixels[z].b) * (imgTemp->pixels[z].b - meanInput->pixels[z].b));
		}
		//pow((imgTemp->pixels[z].r - meanInput->pixels[z].r), 2);
	}
	// create new variable datatype so the deviation will deviation uses short- where chardeviation is unsigned char , to write the image using the write function
	//Find mean of all deviations , Calculate Standard Deviation by taking the square root :
	for (int z = 0; z <(3264 * 2448); z++)
	{
		deviation->pixels[z].r = sqrt(deviation->pixels[z].r / 13);
		deviation->pixels[z].g = sqrt(deviation->pixels[z].g / 13);
		deviation->pixels[z].b = sqrt(deviation->pixels[z].b / 13);
	}

	//create sigma factor variable
	float S = 1.6f;
	float minSr = 0.0;
	float maxSr = 0.0;
	float minSg = 0.0;
	float maxSg = 0.0;
	float minSb = 0.0;
	float maxSb = 0.0;
	ImageF *quantityfinalSigmaImage = new ImageF(3264, 2448); //hold number of sweet spots found per pixel
	ImageF *finalSigmaImage = new ImageF(3264, 2448);

	std::cout << "Calculating sigma..." << std::endl;
	for (int i = 1; i <= 13; i++)
	{
		std::string myString = "Images/ImageStacker_set1/IMG_" + std::to_string(i) + ".ppm";
		const char *myString2 = myString.c_str();
		delete[] imgTemp->pixels;
		*imgTemp = rwPPM::readPPMF(myString2);
		// find minimium and maximum values
		for (int z = 0; z < (3264 * 2448); z++)// for each pixel we need minimum and maximum values
		{
			minSr = meanInput->pixels[z].r - (S*deviation->pixels[z].r);
			maxSr = meanInput->pixels[z].r + (S*deviation->pixels[z].r);

			minSg = meanInput->pixels[z].g - (S*deviation->pixels[z].g);
			maxSg = meanInput->pixels[z].g + (S*deviation->pixels[z].g);

			minSb = meanInput->pixels[z].b - (S*deviation->pixels[z].b);
			maxSb = meanInput->pixels[z].b + (S*deviation->pixels[z].b);
			//exclud min and max values
			if (imgTemp->pixels[z].r < maxSr && imgTemp->pixels[z].r > minSr)
			{
				quantityfinalSigmaImage->pixels[z].r++;
				finalSigmaImage->pixels[z].r += imgTemp->pixels[z].r;
			}
			if (imgTemp->pixels[z].g < maxSg && imgTemp->pixels[z].g > minSg)
			{
				quantityfinalSigmaImage->pixels[z].g++;
				finalSigmaImage->pixels[z].g += imgTemp->pixels[z].g;
			}
			if (imgTemp->pixels[z].b < maxSb && imgTemp->pixels[z].b > minSb)
			{
				quantityfinalSigmaImage->pixels[z].b++;
				finalSigmaImage->pixels[z].b += imgTemp->pixels[z].b;
			}
		}
	}
	//average the sweet spot values that are left 
	for (int z = 0; z < (3264 * 2448); z++)
	{
		finalSigmaImage->pixels[z].r /= quantityfinalSigmaImage->pixels[z].r;
		finalSigmaImage->pixels[z].g /= quantityfinalSigmaImage->pixels[z].g;
		finalSigmaImage->pixels[z].b /= quantityfinalSigmaImage->pixels[z].b;
	}
	setcolor(15);
	std::cout << "Total time for sigma clipped operations is: " << ((std::chrono::duration<float>)(end - start)).count() <<" seconds."<< std::endl;
	setcolor(7);
	rwPPM::writePPMF(*finalSigmaImage, "sigmaClippedMeanFinal.ppm");
	finalSigmaImage->DisplayFunction("Sigma Clipped");
	delete meanInput->pixels;
	delete imgTemp->pixels;
	delete deviation->pixels;
	delete finalSigmaImage->pixels;
	delete quantityfinalSigmaImage->pixels;
	meanInput = NULL;
	imgTemp->pixels = NULL;
	deviation->pixels = NULL;
	finalSigmaImage->pixels = NULL;
	quantityfinalSigmaImage->pixels = NULL;

}

Image Functions::Nearest_Neighbour2x()
{
	setcolor(11);
	std::cout << "\nNearest neighbour x2 function called." << std::endl;
	setcolor(7);
	Image *originalImage = new Image(0, 0);
	*originalImage = rwPPM::readPPM("Images/Zoom/zIMG_1.ppm"); // read original image
	Image *expandedImage = new (std::nothrow)ImageZoom(originalImage->getHeight() * 2, originalImage->getWidth() * 2); // make image twice as the original on size

	for (unsigned int i = 0; i < originalImage->getWidth(); i++)// loop through each row (width)
	{
		for (unsigned int j = 0; j < originalImage->getHeight(); j++)// loop through each column(height)
		{
			int a = (i*originalImage->getWidth()) + j; //reference the location of the pixel to copy
			int b = ((i*expandedImage->getWidth() * 2) + (j * 2)); // position where the new information will be copied
			int c = ((i*expandedImage->getWidth() * 2) + (j * 2) + 1);// the pixel position + 1 so it will be a copy of the same pixeel;

			expandedImage->pixels[b].r = originalImage->pixels[a].r;
			expandedImage->pixels[b].g = originalImage->pixels[a].g;
			expandedImage->pixels[b].b = originalImage->pixels[a].b;

			expandedImage->pixels[c].r = originalImage->pixels[a].r;
			expandedImage->pixels[c].g = originalImage->pixels[a].g;
			expandedImage->pixels[c].b = originalImage->pixels[a].b;
		}
	}
	delete originalImage->pixels;
	originalImage = NULL;
	for (unsigned int currentRow = 0; currentRow < expandedImage->getWidth() - 1; currentRow += 2)// row
	{
		for ( unsigned int currentColumn = 0; currentColumn < expandedImage->getHeight(); currentColumn++)// column
		{
			int a = (currentRow*expandedImage->getWidth()) + currentColumn; // reference the pixel we are going to copy
			int b = (((currentRow + 1)*expandedImage->getWidth()) + currentColumn); // this referes to the same pixel in the next row
			expandedImage->pixels[b].r = expandedImage->pixels[a].r;
			expandedImage->pixels[b].g = expandedImage->pixels[a].g;
			expandedImage->pixels[b].b = expandedImage->pixels[a].b;
		}
	}
	rwPPM::writePPM(*expandedImage, "nNx2zoom.ppm");
	expandedImage->DisplayFunction("Zoomed x2");
	return *expandedImage;
}

void Functions::Nearest_Neighbour4x()
{
	setcolor(11);
	std::cout << "\nNearest neighbour x4 function called." << std::endl;
	setcolor(7);
	setcolor(11);
	std::cout << "Prepares the enlarging using the ";
	setcolor(7);
	Image *originalImage = new ImageZoom(0, 0);
	originalImage = &Nearest_Neighbour2x();
	
	Image *expandedImage4x = new (std::nothrow)ImageZoom(originalImage->getHeight() * 2, originalImage->getWidth() * 2); // make image twice as the original on size

	for (unsigned int i = 0; i < originalImage->getWidth(); i++)// row
	{
		for (unsigned int j = 0; j < originalImage->getHeight(); j++)// column
		{
			int a = (i*originalImage->getWidth()) + j; //reference the location of the pixel to copy
			int b = ((i*expandedImage4x->getWidth() * 2) + (j * 2)); // position where the new information will be copied
			int c = ((i*expandedImage4x->getWidth() * 2) + (j * 2) + 1);

			expandedImage4x->pixels[b].r = originalImage->pixels[a].r;
			expandedImage4x->pixels[b].g = originalImage->pixels[a].g;
			expandedImage4x->pixels[b].b = originalImage->pixels[a].b;

			expandedImage4x->pixels[c].r = originalImage->pixels[a].r;
			expandedImage4x->pixels[c].g = originalImage->pixels[a].g;
			expandedImage4x->pixels[c].b = originalImage->pixels[a].b;
		}
	}
	delete originalImage->pixels;
	originalImage = NULL;
	for (unsigned int currentRow = 0; currentRow < expandedImage4x->getWidth() - 1; currentRow += 2)// row
	{
		for (unsigned int currentColumn = 0; currentColumn < expandedImage4x->getHeight(); currentColumn++)// column
		{
			int a = (currentRow*expandedImage4x->getWidth()) + currentColumn; // reference the pixel we are going to copy
			int b = (((currentRow + 1)*expandedImage4x->getWidth()) + currentColumn); // this referes to the same pixel in the next row
			expandedImage4x->pixels[b].r = expandedImage4x->pixels[a].r;
			expandedImage4x->pixels[b].g = expandedImage4x->pixels[a].g;
			expandedImage4x->pixels[b].b = expandedImage4x->pixels[a].b;
		}
	}
	rwPPM::writePPM(*expandedImage4x, "nNx4zoom.ppm");
	expandedImage4x->DisplayFunction("Zoomed x4");
	
	delete expandedImage4x->pixels;
	expandedImage4x = NULL;
}

void Functions::Bilinear_Interpolation()
{
	setcolor(11);
	std::cout << "\nBilinear interpolation function called." << std::endl;
	setcolor(7);
	Image *originalImage = new Image(0, 0);// create an imaje object to read the original image into
	*originalImage = rwPPM::readPPM("Images/Zoom/zIMG_1.ppm"); // read original image
	ImageZoom *bilinear_Image = new (std::nothrow)ImageZoom(originalImage->getHeight() * 2, originalImage->getWidth() * 2); // make image twice as the original on size in order to populate later on

	for (unsigned int i = 0; i < originalImage->getWidth(); i++)// row
	{
		for (unsigned int j = 0; j < originalImage->getHeight(); j++)// column
		{
			int a = (i*originalImage->getWidth()) + j; //reference the location of the pixel to copy
			int b = ((i*bilinear_Image->getWidth() * 2) + (j * 2)); // position where the new information will be copied
			//int c = ((i*bilinear_Image->getWidth() * 2) + (j * 2) + 1);// the pixel position + 1 so it will be a copy of the same pixeel;
			bilinear_Image->pixels[b].r = originalImage->pixels[a].r;
			bilinear_Image->pixels[b].g = originalImage->pixels[a].g;
			bilinear_Image->pixels[b].b = originalImage->pixels[a].b;
		}
	}

	delete originalImage->pixels;
	originalImage = NULL;
	// x = horizontal axis
	// y = vertical axis
	unsigned int position;// speaks for itself
	for (unsigned int y = 0; y < bilinear_Image->getHeight(); y += 2)// averiging the middle pixel value and populate it for each row
	{
		for (unsigned int x = 1; x < bilinear_Image->getWidth()-1; x += 2)
		{
			position = y*bilinear_Image->getWidth() + x;
			bilinear_Image->pixels[position].r = (((bilinear_Image->pixels[position-1].r) + (bilinear_Image->pixels[position+1].r)) / 2);
			bilinear_Image->pixels[position].g = (((bilinear_Image->pixels[position-1].g) + (bilinear_Image->pixels[position+1].g)) / 2);
			bilinear_Image->pixels[position].b = (((bilinear_Image->pixels[position-1].b) + (bilinear_Image->pixels[position+1].b)) / 2);
		}
	}
	unsigned int positionPlus, positionMinus;// to use inside for position +1 and -1
	for (unsigned int y = 1; y < bilinear_Image->getHeight()-1; y +=2)// averiging the middle pixel value and populate it for each row where before was black, using height
	{
		for (unsigned int x = 0; x < bilinear_Image->getWidth(); x ++)
		{
			position = y*bilinear_Image->getWidth() + x;
			positionMinus = (y-1)*bilinear_Image->getWidth() + x;
			positionPlus = (y + 1)*bilinear_Image->getWidth() + x;
			bilinear_Image->pixels[position].r = (((bilinear_Image->pixels[positionMinus].r) + (bilinear_Image->pixels[positionPlus].r)) / 2);
			bilinear_Image->pixels[position].g = (((bilinear_Image->pixels[positionMinus].g) + (bilinear_Image->pixels[positionPlus].g)) / 2);
			bilinear_Image->pixels[position].b = (((bilinear_Image->pixels[positionMinus].b) + (bilinear_Image->pixels[positionPlus].b)) / 2);
		}
	}
	rwPPM::writePPM(*bilinear_Image, "Bilinear_Image.ppm");
	bilinear_Image->DisplayFunction("Bilinear");
	delete bilinear_Image->pixels;
	bilinear_Image = NULL;
}
