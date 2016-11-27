#include "CustomSource.h"

void CustomSource::setup(){
	name = "The Hedgehog Source";
	
	image.load("http://www.businesscat.happyjar.com/wp-content/uploads/2016/11/2016-11-18-Trapped.png");
	
	allocate(image.getWidth(), image.getHeight());
}

void CustomSource::update(){
	
}

void CustomSource::draw(){
	ofClear(0);
	image.draw(0, 0);
}