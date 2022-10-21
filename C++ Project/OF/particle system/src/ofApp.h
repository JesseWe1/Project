#pragma once

#include "ofMain.h"

class particle {
public:
    // with each object containing an x and y position, and a vector direction as vx and vy and a size
    ofColor color;
    float size;
    glm::vec2 force, position, direction;
	//glm::vec3 force, position, direction;

    //define two methods that the particle object understands
    void update();
    void draw();
    
    // define a particle contructor and a destructor 
    // the contructor is expecting to be passed an initial x and y co-ordinate for the new particle
    particle(int x, int y, int hue);
	//particle(int x, int y, int z, int hue);
    ~particle();


};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
	

    // define a vector
    vector<particle> particles;
    int hue;
	//ofEasyCam cam;
	//ofLight light;
	//int maxParticles;
};
