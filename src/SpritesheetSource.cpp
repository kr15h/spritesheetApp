#include "SpritesheetSource.h"

void SpritesheetSource::setup(){
	name = "Spritesheet Source";
	
	image.load("spritesheet.png");
	
	allocate(500, 500);
	
	numFrames = image.getWidth() / getWidth();
	currentFrame = 0;
	frameRate = 30;
	lastNextFrameCall = 0.0f;
	isPlaying = true;
	
	cout << "numFrames: " << numFrames << endl;
	
	dstRect = ofRectangle(0, 0, getWidth(), getHeight());
}

void SpritesheetSource::update(){
	srcRect = ofRectangle(currentFrame * getWidth(), 0, getWidth(), getHeight());
	
	if(isPlaying == true){
		float secondsPerFrame = 1.0f / (float)frameRate;
		float now = ofGetElapsedTimef();
		float deltaTime = now - lastNextFrameCall;
	
		if(deltaTime >= secondsPerFrame){
			nextFrame();
			lastNextFrameCall = now;
		}
	}
	
	cout << "currentFrame: " << currentFrame << endl;
}

void SpritesheetSource::draw(){
	ofClear(0);
	
	image.drawSubsection(
		dstRect.x, dstRect.y, dstRect.width, dstRect.height,
		srcRect.x, srcRect.y, srcRect.width, srcRect.height);
}

void SpritesheetSource::nextFrame(){
	currentFrame = currentFrame + 1;
	if(currentFrame >= 4){
		currentFrame = 0;
	}
}

void SpritesheetSource::stop(){
	isPlaying = false;
}

void SpritesheetSource::play(){
	isPlaying = true;
}

void SpritesheetSource::toggle(){
	isPlaying = !isPlaying;
}

void SpritesheetSource::setFrame(int frameNum){
	if(frameNum >= numFrames){
		return;
	}
	if(frameNum < 0){
		return;
	}
	currentFrame = frameNum;
}
