#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include"rwPPM.h"
#include<chrono>
// the class functions definitions
Image rwPPM::readPPM(const char *filename)
{
	//auto start = std::chrono::system_clock::now();
	std::ifstream inputFileStream;
	inputFileStream.open(filename, std::ios::binary);
	Image src;
	try 
	{
		if (inputFileStream.fail()) 
		{
			throw("Can't open the input file - is it named correctly/is it in the right directory?");
		}
		std::string header;
		int w, h, b;
		inputFileStream >> header;
		//if (header.c_str()!="P6")
		if (strcmp(header.c_str(), "P6") != 0)
			throw("Can't read the input file - is it in binary format (Has P6 in the header)?");
		inputFileStream >> w >> h >> b;
		src.Width(w);
		src.Height(h);
		//std::cout << w << " " << h << std::endl;
		src.pixels = new Image::Rgb[w * h]; // this is throw an exception if bad_alloc 
		inputFileStream.ignore(256, '\n'); // skip empty lines in necessary until we get to the binary data 
		unsigned char pix[3]; // read each pixel one by one and convert bytes to floats 
		for (int i = 0; i < w * h; ++i) 
		{
			inputFileStream.read(reinterpret_cast<char *>(pix), 3);
			src.pixels[i].r = pix[0];
			src.pixels[i].g = pix[1];
			src.pixels[i].b = pix[2];
		}
		inputFileStream.close();
	}
	catch (const char *error) 
	{
		fprintf(stderr, "%s\n", error);
		inputFileStream.close();

	}
	//Confirm image read
	//Delete this to prevent multiple lines output
	//auto end = std::chrono::system_clock::now();
	std::cout << "Image read... " << std::endl;
	return src;
}

//Open a .ppm file in notepad++ to see this header (caution: they are large files!)
ImageF rwPPM::readPPMF(const char *filename)
{
	std::ifstream ifs;
	ifs.open(filename, std::ios::binary);
	ImageF src;
	try 
	{
		if (ifs.fail()) 
		{
			throw("Can't open the input file - is it named correctly/is it in the right directory?");
		}
		std::string header;
		int w, h, b;
		ifs >> header;
		if (strcmp(header.c_str(), "P6") != 0) throw("Can't read the input file - is it in binary format (Has P6 in the header)?");
		ifs >> w >> h >> b;
		src.Width(w);
		src.Height(h);
		//std::cout << w << " " << h << std::endl;
		src.pixels = new ImageF::Rgb[w * h]; // this is throw an exception if bad_alloc 
		ifs.ignore(256, '\n'); // skip empty lines in necessary until we get to the binary data 
		unsigned char pix[3]; // read each pixel one by one and convert bytes to floats 
		for (int i = 0; i < w * h; ++i) 
		{
			ifs.read(reinterpret_cast<char *>(pix), 3);
			src.pixels[i].r = pix[0] / 255.f;
			src.pixels[i].g = pix[1] / 255.f;
			src.pixels[i].b = pix[2] / 255.f;
		}
		ifs.close();
	}
	catch (const char *err) 
	{
		fprintf(stderr, "%s\n", err);
		ifs.close();
	}

	//Confirm image read
	//Delete this to prevent multiple lines output
	std::cout << "Image read..." << std::endl;
	return src;
}

void rwPPM::writePPM( Image &img, const char *filename)
{
	auto start = std::chrono::system_clock::now();
	//std::cout << filename << std::endl;
	std::cout << "Writing image ..." << std::endl;
	if (img.getWidth() == 0 || img.getHeight() == 0) { fprintf(stderr, "Can't save an empty image\n"); return; }
	std::ofstream ofs;
	try 
	{
		ofs.open(filename, std::ios::binary); // need to spec. binary mode for Windows users 
		if (ofs.fail()) throw("Can't open output file");
		ofs << "P6\n" << img.getWidth() << " " << img.getHeight() << "\n255\n";
		//std::cout << "P6\n" << img.getWidth() << " " << img.getHeight() << "\n255\n";
		unsigned char r, g, b;
		// loop over each pixel in the image, clamp and convert to byte format
		for (unsigned int i = 0; i < (img.getWidth() * img.getHeight()); i++) 
		{
			r = static_cast<unsigned char>(img.pixels[i].r);
			g = static_cast<unsigned char>(img.pixels[i].g);
			b = static_cast<unsigned char>(img.pixels[i].b);
			ofs << r << g << b;
		}
		ofs.close();
		//Confirm image write
		//std::cout << "Image written" << std::endl;
	}
	catch (const char *error) 
	{
		fprintf(stderr, "%s\n", error);
		ofs.close();
	}
	auto end = std::chrono::system_clock::now();
	
	std::cout << "				Image written in ... " << ((std::chrono::duration<float>)(end - start)).count() <<" seconds."<< std::endl;
}

void rwPPM::writePPMF( ImageF &img, const char *filename)
{
	auto start = std::chrono::system_clock::now();
	//std::cout << filename << std::endl;
	std::cout << "Writing image ..." << std::endl;
	if (img.getWidth() == 0 || img.getHeight() == 0) { fprintf(stderr, "Can't save an empty image\n"); return; }
	std::ofstream ofs;
	try 
	{
		ofs.open(filename, std::ios::binary); // need to spec. binary mode for Windows users 
		if (ofs.fail()) throw("Can't open output file");
		ofs << "P6\n" << img.getWidth() << " " << img.getHeight() << "\n255\n";
		//std::cout << "P6\n" << img.getWidth() << " " << img.getHeight() << "\n255\n";
		unsigned char r, g, b;
		// loop over each pixel in the image, clamp and convert to byte format
		for (unsigned int i = 0; i < img.getWidth() * img.getHeight(); ++i) 
		{
			r = static_cast<unsigned char>(std::min(1.f, img.pixels[i].r) * 255);
			g = static_cast<unsigned char>(std::min(1.f, img.pixels[i].g) * 255);
			b = static_cast<unsigned char>(std::min(1.f, img.pixels[i].b) * 255);
			ofs << r << g << b;
		}
		ofs.close();
	}
	catch ( const char *err)
	{
		fprintf(stderr, "%s\n", err);
		ofs.close();
	}
	//Confirm image write
	auto end = std::chrono::system_clock::now();
	std::cout << "				Image written in ... " << ((std::chrono::duration<float>)(end - start)).count() << " seconds." << std::endl;
}

void rwPPM::writePPM( ImageZoom &img, const char *filename)// for polymorhism...., to write the zoomed image with zoomed datatype, size, etc... all have been outputted to the log .txt file
{//calling different functions from different classess, giving us different output(like image short, image zoomed, image float) applies polymorphism
	auto start = std::chrono::system_clock::now();
	std::cout << "Writing image ..." << std::endl;
	if (img.getWidth() == 0 || img.getHeight() == 0) { fprintf(stderr, "Can't save an empty image\n"); return; }
	std::ofstream ofs;
	try 
	{
		ofs.open(filename, std::ios::binary); // need to spec. binary mode for Windows users 
		if (ofs.fail()) throw("Can't open output file");
		ofs << "P6\n" << img.getWidth() << " " << img.getHeight() << "\n255\n";
		//std::cout << "P6\n" << img.getWidth() << " " << img.getHeight() << "\n255\n";
		unsigned char r, g, b;
		// loop over each pixel in the image, clamp and convert to byte format
		for (unsigned int i = 0; i < (img.getWidth() * img.getHeight()); i++)
		{
			r = static_cast<unsigned char>(img.pixels[i].r);
			g = static_cast<unsigned char>(img.pixels[i].g);
			b = static_cast<unsigned char>(img.pixels[i].b);
			ofs << r << g << b;
		}
		ofs.close();
	}
	catch (const char *error) 
	{
		fprintf(stderr, "%s\n", error);
		ofs.close();
	}
	auto end = std::chrono::system_clock::now();
	std::cout << "				Image written in: " << ((std::chrono::duration<float>)(end - start)).count() <<" seconds."<< std::endl;
}