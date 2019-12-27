// Copyright 2019 Braulio Duarte
#include <ctype.h>
#include <stdio.h>
#include <math.h>    // for sqrt()
#include <iostream>
#include <vector>
#include <memory>    // for smart_pointers
#include <string>  // for strlen()
#include "Body.hpp"

using std::vector;
using std::cin;
using std::unique_ptr;
using std::cout;
using std::endl;
using std::string;

bool DEBUG = false;
const double GRAVITY = 6.67300E-11;

void loadVector(vector<unique_ptr<Body>> &particleVector,
		int particleNumber, double scalledRadius);

bool validateArguments(int argc, char* argv[]);
void calculateAndSetNetForce(vector<unique_ptr<Body>> & vBodies);
void calculateAndSetAcceleration(vector<unique_ptr<Body>> & vBodies);
void calculateAndSetNewVelocity(vector<unique_ptr<Body>> & vBodies, double t);
void calculateAndSetNewPosition(vector<unique_ptr<Body>> & vBodies, double t,
				  double universeRadius);

int main(int argc, char *argv[]) {

  if(!validateArguments(argc, argv)) {return 1;}

  double secs = std::atof(argv[1]);
  double secondsPerStep = std::atof(argv[2]);
  double timeElapsed = 0;

  int particleNumber;                            //used to store particle number
  double universeRadius;                         //used to store universeRadius
  
  sf::RenderWindow window(sf::VideoMode(600,600), "NBody Simulation");
  sf::Event event;
  
  sf::Image bgImage;
  sf::Texture bgTexture;
  sf::Sprite bgSprite;
  
  if(!bgImage.loadFromFile("nbody/starfield_alpha.png")) {
    std::cerr << "Failed reading image, exiting program\n";
    exit(1);
  }
  bgTexture.loadFromImage(bgImage);
  bgSprite.setTexture(bgTexture);
  bgSprite.setScale(.24, .28);

  //vector of unique pointers to Body
  vector<unique_ptr<Body>> particleVector;     //to represent planets

                                             //input is < from textfile
  cin >> particleNumber;                     //read particle number   
  cin >> universeRadius;                     //read universe number
    
  //function to load input values, instantiate Bodies, and place them inside vector
  loadVector(particleVector, particleNumber, universeRadius); 

  int i = 0;
  if(!DEBUG){
    while(window.isOpen()) {
      while(window.pollEvent(event)) {
	if(event.type == sf::Event::Closed) {
	  window.close();
	  break;
	}
	
	while(timeElapsed <= secs) {
	  timeElapsed += secondsPerStep;

	  calculateAndSetNetForce(particleVector);

	  calculateAndSetAcceleration(particleVector);

	  calculateAndSetNewVelocity(particleVector, secondsPerStep);

	  calculateAndSetNewPosition(particleVector, secondsPerStep, universeRadius);
	  //sleep(sf::seconds(0.01f));
	  if(!DEBUG){
	    window.clear(sf::Color::Black);
	    window.draw(bgSprite);
	    
	    for(int i = 0; i < particleNumber; i++) {
	      printf(" %e %e %e %e %e ",
		     particleVector.at(i)->getPosX(),
		     particleVector.at(i)->getPosY(),
		     particleVector.at(i)->getVelocityX(),
		     particleVector.at(i)->getVelocityY(),
		     particleVector.at(i)->getMass());
	      cout << particleVector.at(i)->getName() << endl;

	      window.draw(*particleVector.at(i));
	    }
	    window.display();
	    if(i == 0) sleep(sf::seconds(2.0f));
	  }
	  printf("Drew %dth time, timeElapsed = %f\n", i++, timeElapsed);	

	}
      }
    }
  }
  return 0;
}

void calculateAndSetNetForce(vector<unique_ptr<Body>> & vBodies){
  //sum up all pairwise gravitational forces

  for(unsigned i = 0; i < vBodies.size(); i++) {//each iteration will sum up for 1 planet
    double netForceX = 0;
    double netForceY = 0;
    //iterate through all planets to sum up pairwise forces applied to planet i
    for(unsigned x = 0; x < vBodies.size(); x++) {
      if(x != i) {
	double differenceX = vBodies.at(x)->getPosX() - vBodies.at(i)->getPosX();
	double differenceY = vBodies.at(x)->getPosY() - vBodies.at(i)->getPosY();
	double r = sqrt(differenceX*differenceX + differenceY*differenceY);
	double f = (GRAVITY*vBodies.at(x)->getMass()*vBodies.at(i)->getMass() )
	           / (r*r);
	netForceX += (differenceX / r) * f;
	netForceY += (differenceY / r) * f;
      }
    }
    vBodies.at(i)->setNetForceX(netForceX);
    vBodies.at(i)->setNetForceY(netForceY);
  }
}

void calculateAndSetAcceleration(vector<unique_ptr<Body>> & vBodies) {
 
  for(unsigned i = 0; i < vBodies.size(); i++)
    {
      vBodies.at(i)->setAccelerationX(vBodies.at(i)->getNetForceX() /
				      vBodies.at(i)->getMass());
      vBodies.at(i)->setAccelerationY(vBodies.at(i)->getNetForceY() /
				      vBodies.at(i)->getMass());
    }
}

void calculateAndSetNewVelocity(vector<unique_ptr<Body>> & vBodies, double t) {
  for(unsigned i = 0; i < vBodies.size(); i++) {
    vBodies.at(i)->setVelocityX( vBodies.at(i)->getVelocityX() +
				 t * vBodies.at(i)->getAccelerationX());
    vBodies.at(i)->setVelocityY( vBodies.at(i)->getVelocityY() +
				 t * vBodies.at(i)->getAccelerationY());

  }
}

 void calculateAndSetNewPosition(vector<unique_ptr<Body>> & vBodies, double t,
				 double universeRadius) {
  for(unsigned i = 0; i < vBodies.size(); i++) {
    vBodies.at(i)->setPositionX(vBodies.at(i)->getPosX() +
				t * vBodies.at(i)->getVelocityX());
    vBodies.at(i)->setPositionY(vBodies.at(i)->getPosY() +
				t * vBodies.at(i)->getVelocityY());
    vBodies.at(i)->setPosition(universeRadius);
  }
}

void loadVector(vector<unique_ptr<Body>> &particleVector,
		int particleNumber, double universeRadius) {
  for(int i = 0; i < particleNumber; i++) {
    particleVector.emplace(particleVector.end(),
			   new Body());
    cin >> *(particleVector.at(i));
    particleVector.at(i)->setPosition(universeRadius);
  }

  
}
bool validateArguments(int argc, char* argv[]){
  string temp = "";
  if(argc != 3){
    cout << "Please enter correct arguments\n"
	 << "Expecting L a double length of simulation in seconds"
         << ",and S a double number of steps\n"
	 << "Exeting program\n";
    return false;
  }
  size_t sizeL = strlen(argv[1]); //size of argument for L                        
  size_t sizeN = strlen(argv[2]); //size of argument for N
  
  for(unsigned int i = 0; i < sizeL; i++){
    if(! (isdigit(argv[1][i]) || argv[1][i] == '.') ) {
      cout << "First argument was not a positive number\n"
	   << "Exeting Program\n";
      return false;
    }
  }
  
  for(unsigned int i = 0; i < sizeN; i++){
    if(!(isdigit(argv[2][i]) || argv[2][i] == '.')) {
      cout << "Second argument was not a positive number\n"
	   << "Exeting Program\n";
      return false;
    }
  }
  
  return true; //passed all tests arguments validated                                   
}//end of validateArgumen
