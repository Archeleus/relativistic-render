/*
 * background.cpp
 *
 *  Created on: 4 Nov 2010
 *      Author: alex
 */
#include "background.h"
#include "pbrt.h"
#include <ImageMagick/Magick++.h>

using namespace Magick;

Background::Background(){
	infile.read(PbrtOptions.backgroundImage);
	Pixels view(infile);
}

void Background::get_colour(size_t x, size_t y){
	t = infile.pixelColor(x, y);
	colours[0] = t.red(); colours[1] = t.green(); colours[2] = t.blue();
}
