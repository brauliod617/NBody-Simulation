#include "Body.hpp"


Body::Body(double iPosX, double iPosY, double iVelX,
	   double iVelY, double mass, std::string name):
  _initialVelocityX(iVelX), _initialVelocityY(iVelY),
  _mass(mass), _name(name)
{
  _initialPosX = iPosX;
  _initialPosY = iPosY;
}

void Body::draw(sf::RenderTarget &target,
		sf::RenderStates states) const {
  target.draw(_sprite, states);
}

void Body::setPosition(double universeRadius) {
  double x = ( ((_initialPosX) / (universeRadius))* 300 ) + 300;
  double y = ( ((_initialPosY) / (universeRadius))* 300 ) + 300;
  _sprite.setPosition(x,y);
}

std::istream& operator >> (std::istream & lhs, Body& rhs) {
  
  lhs >> rhs._initialPosX >> rhs._initialPosY >> rhs._initialVelocityX
      >> rhs._initialVelocityY >> rhs._mass >> rhs._name;

  if( ! rhs._image.loadFromFile("nbody/" + rhs._name) ) {
    std::cerr << "Failed reading image, exiting program\n";
    exit(1);
  }
  //set image on texture
  rhs._texture.loadFromImage(rhs._image);
  //set texture to sprite
  rhs._sprite.setTexture(rhs._texture);
  
  
  return lhs;
}
