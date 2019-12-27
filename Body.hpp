#ifndef BODY_HPP
#define BODY_HPP

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Body: public sf::Drawable
{
public:
  Body(double iPosX, double iPosY, double iVelX,
       double iVelY, double mass, std::string name);
  Body() {}
  
  void draw (sf::RenderTarget &target,
	     sf::RenderStates states = sf::RenderStates::Default) const override;

  void setPosition(double universalRadius);
  void setNetForceX(double newForce) { _netForceX = newForce;}
  void setNetForceY(double newForce) { _netForceY = newForce;}
  void setAccelerationX(double acceleration) {_accelerationX = acceleration;}
  void setAccelerationY(double acceleration) {_accelerationY = acceleration;}
  void setVelocityX(double velocity) {_initialVelocityX = velocity; }
  void setVelocityY(double velocity) {_initialVelocityY = velocity; }
  void setPositionX(double positionX) {_initialPosX = positionX; }
  void setPositionY(double positionY) {_initialPosY = positionY; }
  
  double getAccelerationX() { return _accelerationX; }
  double getAccelerationY() { return _accelerationY; }
  double getPosX() {return _initialPosX; }
  double getPosY() {return _initialPosY; }
  double getVelocityX() {return _initialVelocityX; }
  double getVelocityY() {return _initialVelocityY; }
  double getMass() { return _mass; }
  double getNetForceX() { return _netForceX; }
  double getNetForceY() { return _netForceY; }
  std::string getName() { return _name; }
  
  friend std::istream& operator >> (std::istream& lhf, Body& rhs);
  
private:
  double _initialPosX;
  double _initialPosY;
  double _initialVelocityX;
  double _initialVelocityY;
  double _mass;
  double _netForceX;
  double _netForceY;
  double _accelerationX;
  double _accelerationY;
  
 
  std::string _name;
  sf::Image _image;
  sf::Texture _texture;
  sf::Sprite _sprite;
};

#endif
