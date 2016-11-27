#pragma once

#include "ofMain.h"
#include "Settings.h"
#include "ofxPiMapper.h"
#include "CustomSource.h"
#include "CrossSource.h"
#include "VideoSource.h"
#include "SpritesheetSource.h"

#include "ofxOsc.h"

class ofApp : public ofBaseApp {
	public:
		void setup();
		void update();
		void draw();
	
		void keyPressed(int key);

		ofxPiMapper piMapper;

		// By using a custom source that is derived from FboSource
		// you will be able to see the source listed in sources editor
		CustomSource * customSource;
		CrossSource * crossSource;
		SpritesheetSource * spritesheetSource;
	
		ofxOscReceiver oscReceiver;
	
		vector<ofxOscSender *> oscSenders;
	
		bool isSender;
};
