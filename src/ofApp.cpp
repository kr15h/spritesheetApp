#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);

	ofx::piMapper::VideoSource::enableAudio = false;

	crossSource = new CrossSource();
	customSource = new CustomSource();
	spritesheetSource = new SpritesheetSource();
	
	piMapper.registerFboSource(crossSource);
	piMapper.registerFboSource(customSource);
	piMapper.registerFboSource(spritesheetSource);
	
	piMapper.setup();
	
	ofSetFullscreen(Settings::instance()->getFullscreen());
	
	oscReceiver.setup(54321);
	
	ofxOscSender * sender1 = new ofxOscSender();
	ofxOscSender * sender2 = new ofxOscSender();
	ofxOscSender * sender3 = new ofxOscSender();
	
	sender1->setup("192.168.0.36", 54321);
	sender2->setup("192.168.0.37", 54321);
	sender3->setup("192.168.0.33", 54321);
	
	oscSenders.push_back(sender1);
	oscSenders.push_back(sender2);
	//oscSenders.push_back(sender3);
	
	isSender = false;
}

void ofApp::update(){
	while(oscReceiver.hasWaitingMessages()){
		ofxOscMessage message;
		oscReceiver.getNextMessage(message);
		
		cout << "Received OSC message: " << message.getAddress() << endl;
		
		if(message.getAddress() == "/spritesheet/frame"){
			spritesheetSource->stop();
			int frameNum = message.getArgAsInt(0);
			spritesheetSource->setFrame(frameNum);
		}
	}
	
	if(isSender == true){
		ofxOscMessage m;
		m.setAddress("/spritesheet/frame");
		m.addIntArg(spritesheetSource->currentFrame);
		for(int i = 0; i < oscSenders.size(); i += 1){
			oscSenders[i]->sendMessage(m);
		}
	}

	piMapper.update();
}

void ofApp::draw(){
	piMapper.draw();
}

void ofApp::keyPressed(int key){
	if(key == ' '){
		spritesheetSource->toggle();
	}else if(key == '5'){
		spritesheetSource->setFrame(0);
	}else if(key == '6'){
		spritesheetSource->setFrame(1);
	}else if(key == '7'){
		spritesheetSource->setFrame(2);
	}else if(key == '8'){
		spritesheetSource->setFrame(3);
	}
}
