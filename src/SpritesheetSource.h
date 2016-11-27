#pragma once

#include "ofMain.h"
#include "FboSource.h"

class SpritesheetSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
	
		ofImage image;
	
		int numFrames;
		int currentFrame;
		int frameRate;
	
		float lastNextFrameCall;
	
		bool isPlaying;
	
		void nextFrame();
		void stop();
		void play();
		void toggle();
		void setFrame(int frameNum);
	
		ofRectangle srcRect;
		ofRectangle dstRect;
};
