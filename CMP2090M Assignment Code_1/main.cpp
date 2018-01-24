//main.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include<chrono>
#include <windows.h>
#include<cmath>
#include <math.h>
#include<stdio.h>
#include<stdlib.h>
#include "Image.h"
#include"rwPPM.h"
#include"ImageShort.h"
#include"Functions.h"
#include"ImageZoom.h"

int main()
{
	Functions allF;// instance of my functions class accessor
	//As an example, read one ppm file and write it out to testPPM.ppm
	//We need to specify the dimensions of the image
	//****************************************************
	
	// load 13 pictures then read the RGB values for each pixel (from 13 images) then divide the total value by 13 and store.... then divide by the total number of pixels.... this comes out as 1 value per pixel.
	// create a new image object to store the RGB values from the mean of the 13 images.
	// do this for all pictures , then save all values wihin array 1d array(from the code given to us... )

	std::string Menu[8] = { "Mean blending", "Median blending", "Sigma clipped","Nearest neighbor x2 algorithm","Nearest neighbor x4 algorithm","Bilinear interpolation algorithm","\nRun all in one Go, whoow..." ,"\n\nExit"};
	int pointer = 0;
	
	while (true)
	{
		system("cls");
		std::cout << "********************************************************************************************************" << std::endl;
		std::cout << "*********************                                                             **********************" << std::endl;
		std::cout << "**********                                                                                    **********" << std::endl;
		allF.setcolor(15);
		std::cout << "*                    Image Stacker / Image Scaler by Kostadin Yankov - 16603905                        *" << std::endl;
		allF.setcolor(7);
		std::cout << "**********                                                                                    **********" << std::endl;
		std::cout << "*********************                                                             **********************" << std::endl;
		std::cout << "********************************************************************************************************\n" << std::endl;
		//(advancedCtutorials,2013) menu system
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "---Menu---    ... p.s.  Press ENTER to start/repeat,any other button will take you to back to the MENU.  \n";
		std::cout << "\n                                            To use the MENU simply press Up / Down arrows." << std::endl;
		for (int i = 0; i < 8; ++i)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				std::cout << Menu[i] << std::endl;
				allF.setcolor(15);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				std::cout << Menu[i] << std::endl;
			}
		}
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 7;
				}
				Sleep(70);
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == 8)
				{
					pointer = 0;
				}
				Sleep(70);
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (pointer)
				{
				case 0:
				{
					std::cout << "\n\n\nStarting Mean blending...";
					allF.CreateMeanPic();
					system("pause");
				} break;

				case 1:
				{
					std::cout << "\n\n\nStarting Median blending...";
					allF.MedianFunction();
					system("pause");
				} break;

				case 2:
				{
					std::cout << "\n\n\nStarting Sigma clipped...";
					allF.SigmaClippedMean();
					system("pause");
				} break;

				case 3:
				{
					std::cout << "\n\n\nStarting Nearest neighbor x2 algorithm...";
					Image *holdingImage= new ImageZoom(0, 0);// object to hold the otput from the function x2, had memory leek here,..... sorted
					holdingImage=&allF.Nearest_Neighbour2x();// dereference in order to stop memory leek
					delete holdingImage->pixels;// avoiding memory leek :)
					holdingImage = NULL;// avoiding memory leek :)
					system("pause");
				} break;

				case 4:
				{
					std::cout << "\n\n\nStarting Nearest neighbor x4 algorithm...";
					allF.Nearest_Neighbour4x();
					system("pause");
				} break;

				case 5:
				{
					allF.setcolor(15);
					std::cout << "\n\n\nStarting Bilinear interpolation algorithm...";
					allF.Bilinear_Interpolation();
					allF.setcolor(7);
					system("pause");
				} break;

				case 6:
				{
					allF.setcolor(15);
					std::cout << "\nYou chose to Run it all in one Go, whoow...\n                                                  ... it will take a minute.\n                                                                                 ... literally." << std::endl;
					auto start = std::chrono::system_clock::now();
					allF.CreateMeanPic();
					allF.MedianFunction();
					allF.SigmaClippedMean();
					allF.Nearest_Neighbour2x();
					allF.Nearest_Neighbour4x();
					allF.Bilinear_Interpolation();
					allF.setcolor(7);
					allF.setcolor(15);
					auto end = std::chrono::system_clock::now();
					std::cout << "\nTime for total program to run: " << ((std::chrono::duration<float>)(end - start)).count() << " seconds." << std::endl;
					allF.setcolor(7);
					system("pause");
				}break;

				case 7:
				{
					allF.setcolor(12);
					std::cout << "\n\n\n                              Exiting...                   Bye bye...      ";
					Sleep(1000);
					exit(EXIT_SUCCESS);
				} break;
				}
				break; 
			}
		}
		Sleep(100);
	}
	std::cin.get();
	return 0;
}


	

