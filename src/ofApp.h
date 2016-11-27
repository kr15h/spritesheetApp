#pragma once

#include "ofMain.h"
#include "Settings.h"
#include "ofxPiMapper.h"
#include "CustomSource.h"
#include "CrossSource.h"
#include "VideoSource.h"
#include "SpritesheetSource.h"

#include "ofxOsc.h"

// Sorry, all the comments are gone.

class ofApp : public ofBaseApp {
	public:
		void setup();
		void update();
		void draw();
	
		void keyPressed(int key);

		ofxPiMapper piMapper;

		CustomSource * customSource;
		CrossSource * crossSource;
		SpritesheetSource * spritesheetSource;
	
		ofxOscReceiver oscReceiver;
	
		vector<ofxOscSender *> oscSenders;
	
		bool isSender;
};
