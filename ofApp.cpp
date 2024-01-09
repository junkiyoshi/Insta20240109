#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofColor color;
	float radius = 120;
	float len = 60;

	for (int y = -230; y <= 230; y += 230) {

		for (int i = 0; i < 7; i++) {

			float left_deg_start = ofRandom(360) + ofGetFrameNum() * ofRandom(3, 7);
			float right_deg_start = ofRandom(360) + ofGetFrameNum() * ofRandom(3, 7);

			vector<glm::vec2> vertices;
			for (float deg = left_deg_start; deg < left_deg_start + 20; deg += 1) {

				vertices.push_back(glm::vec2(-180 + (radius - len * 0.5) * cos(deg * DEG_TO_RAD), y + (radius - len * 0.5) * sin(deg * DEG_TO_RAD)));
			}

			for (float deg = right_deg_start; deg < right_deg_start + 20; deg += 1) {

				vertices.push_back(glm::vec2(180 + (radius - len * 0.5) * cos(deg * DEG_TO_RAD), y + (radius - len * 0.5) * sin(deg * DEG_TO_RAD)));
			}

			int hue = ofMap(i, 0, 7, 0, 255);
			color.setHsb(hue, 200, 255);

			ofFill();
			ofSetColor(color);

			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);

			ofNoFill();
			ofSetColor(0);

			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);
		}
	}

	/*
	int start = 50;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}