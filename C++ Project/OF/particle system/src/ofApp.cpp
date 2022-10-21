#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0, 0, 0);
    hue = 0;
	//maxParticles = 2000;
	//ofEnableLighting();
	//ofEnableDepthTest();
	//light.setPosition(0, -600, 300);

	//ofSetSphereResolution(4);//increse the number will make the particle more smoother
}

//--------------------------------------------------------------
void ofApp::update(){
	//set the maxparticles, if it goes bigger it will erase
	//if (particles.size() > maxParticles) {
		//particles.erase(particles.begin());
	//}
	for (int i=0; i<particles.size();i++){
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
	//cam.begin();
	//ofRotateDeg(180, 0, 0, 1); // Translate the camera
	//light.enable();
	//ofDrawAxis(400);
	//for (int i = 0; i < particles.size(); i++) {
	//	particles[i].draw();
	//}
	//light.disable();
	//cam.end();
    ofSetColor(255);
    for (int i=0; i<particles.size();i++){
        particles[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
        case 'F':
            ofToggleFullscreen();
            break;
		//case ' ':
			//int numParticles = 200;
			//for (int i = 0; i < numParticles; i++) {
			//	particle newParticle(0, 0, 0, hue);
				//push the new particle
			//	particles.push_back(newParticle);
			//}
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    // when the mouse is clicked and dragged make a new particle object
    particle newParticle( mouseX, mouseY , hue );
    // push the new particle
    particles.push_back(newParticle);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
     hue = ofRandom( 255); // pick random hue on each button press
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}


//--------------------------------------------------------------

particle::particle(int startX, int startY, int hue){
    // this is called when we make a new object
    position = glm::vec2(startX, startY);
    force = glm::vec2(0, 0.02);
    direction = glm::vec2( ofRandom( -2.0, 2.0), ofRandom( -2.0, 2.0) );
    size = 30;
    color.setHsb(hue,  255,  255, 200);
	//position = glm::vec3(startX, startY, startY);
	//force = glm::vec3(0, 0.02, 0.02);
	//direction = glm::vec3(ofRandom(-2.0, 2.0), ofRandom(-2.0, 2.0), ofRandom(-2.0, 2.0));
	//size = 30;
	//color.setHsb(hue, 255, 255, 200);
}
//--------------------------------------------------------------

particle::~particle(){
    // destructor
}
//--------------------------------------------------------------

void particle::update(){
    // update the particle x,y position by incrementing each by the velocity vx and vy
    position += direction ;
    direction +=  force;
        if (size > 1){
            size -=0.07;
        }
        float brightness = color.getBrightness();
        float myHue = color.getHue();
    
        if (brightness >20){
           // color.setBrightness( brightness -=0.5 );
            color.setHue( myHue -=0.5 );
    
        }
}

//--------------------------------------------------------------

void particle::draw(){
    ofSetColor(color);
    ofDrawCircle(position, size);
	//ofSpherePrimitive circles;
	//circles.set(5, 5);
	//circles.setPosition(position);
	//circles.draw();
}
