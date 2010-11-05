/*
 * 	Batch converts exr to png
 *	If not in batch mode, usage: exrtopng [infile.exr] [outfile.exr]
 *	Linux only.
 *  Created on: 3 Nov 2010
 *      Author: alex
 */
#include <ImageMagick/Magick++.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <vector>

using namespace std;
using namespace Magick;

vector<string> files;
vector<string> n_files;
string path;

void getPath(){
	char pathname[256];
	getcwd(pathname, sizeof(pathname));
	path.assign(pathname);
}



bool checkExt(string filename, string ext){
	int dot = filename.find(".");
	string extension = filename.substr(dot+1);
	if(extension != ext) return false;
	return true;
}

void listDir(){
	DIR *dp;
	struct dirent *dirp;
	dp = opendir(path.c_str());
	while((dirp = readdir(dp)) != NULL){
		string temp = string(dirp->d_name);
		if(checkExt(temp, "exr"))
			files.push_back(string(dirp->d_name));

	}
	closedir(dp);

	for(unsigned int i = 0; i < files.size(); i++){
		//string r = "converted_" + files[i];
		string r = files[i].substr(0, files[i].find("."));
		r += ".png";
		n_files.push_back(r);
	}
}

void convert(string filename, string outfile){
	Image in;
	in.read(filename);
	in.write(outfile);
}

int main(int argc, char **argv){

	if(argc > 1){
		string in, out;
		in = argv[1]; out = argv[2];
		if(checkExt(in, "exr"))
			convert(in, out);
		else{
			cout << in << " is not an exr file." << endl;
			exit(1);
		}
	}
	else{
		getPath();
			listDir();
			for(size_t i = 0; i < files.size(); i++){
				cout << "Converting " << files[i] << " to " << n_files[i] << endl;
				convert(files[i], n_files[i]);
			}
			printf("Done\n");

	}

	return 0;
}
