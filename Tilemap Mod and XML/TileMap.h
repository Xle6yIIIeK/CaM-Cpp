#ifndef LEVEL_H
#define LEVEL_H
#include "tinyxml.h"

struct Object
{
	int GetPropertyInt(std::string name);				//object property number in our list
	float GetPropertyFloat(std::string name);
	std::string GetPropertyString(std::string name);
	
	std::string name;		//declare a variable type "std::string name"
	std::string type;		//declare a variable type "std::string type"
	sf::Rect<float> rect;		//type Rect with non-integer values
	std::map<std::string, std::string> properties;		//create an associative array. key is a string type, value is a string type
	sf::Sprite sprite;					//declare sprite
};
struct Layer							//Layeres
{
	int opacity;						//opacity Layer
	std::vector<sf::Sprite> tiles;				//put tiles into the vector
};
class Level										//Main Class - Level
{
public:
	bool LoadFromFile(std::string filename);		//return false if load has be fail
	Object GetObject(std::string name);
	std::vector<Object> GetObjects(std::string name);	//Get object from level
	std::vector<Object> GetAllObjects();			//Get all objects from level
	void Draw(sf::RenderTarget* target);			//Draw 
	sf::Vector2i GetTileSize();				//Get size tiles
private:
	int width, height, tileWidth, tileHeight;		//in TMX File, width height in the beginning, and after size tile
	int firstTileID;					//get ID first tile
	sf::Rect<float> drawingBounds;				//tile drawing distance
	sf::Texture tilesetImage;				//Texture map
	std::vector<Object> objects;				//Massive type object, which we created
	std::vector<Layer> layers;
};
///////////////////////////////////////
#endif