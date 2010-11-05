/*
 * background.h
 *
 *  Created on: 4 Nov 2010
 *      Author: alex
 */

#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include <ImageMagick/Magick++.h>

class Background{
public:
	float colours[3];
	Magick::Image infile;
	Magick::ColorRGB t;
	void read();
	Background();
	void get_colour(size_t, size_t);
};

extern Background bground;

#endif /* BACKGROUND_H_ */
