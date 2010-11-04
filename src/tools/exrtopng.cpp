/*
 * 	Converts exr to png
 *	Usage: exrtopng input.exr outputfilename.png
 *  Created on: 3 Nov 2010
 *      Author: alex
 */
#include <ImageMagick/Magick++.h>
#include <string>
#include <iostream>

using namespace std;
using namespace Magick;

void convert(string filename, string outfile){
	Image in;
	in.read(filename);
	in.write(outfile);
}

int main(int argc, char **argv){
	if(argc < 2){
		cout << "Usage: exrtopng inputfile.exr outputfilename\n";
		exit(1);
	}

	string input = argv[1];
	int dot = input.find(".");
	string extension = input.substr(dot+1);
	if(extension != "exr"){
		cout << extension << " files are not supported." << endl;
		exit(1);
	}
	string outfilename = argv[2];
	convert(input, outfilename);

return 0;
}
