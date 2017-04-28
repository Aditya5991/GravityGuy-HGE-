#include "precompiled.h"
#include "Level1.h"
#include "SolidTile.h"
#include "VoidTile.h"
#include "Utils.h"
#include "hgefont.h"
#include "Camera.h"
#include "CoinManager.h"

Level1::Level1(){
}

void Level1::Update(){
}

void Level1::Render(){
	double xLimit = GAME_WIDTH / TILE_SIZE;
	double yLimit = GAME_HEIGHT / TILE_SIZE;
	double xOffsetPixel = CAMERA->GetX() / TILE_SIZE;
	double yOffsetPixel = CAMERA->GetY() / TILE_SIZE;

	for(int y = 3; y < _height; y++){
		double yy = y - yOffsetPixel;
		/*if(yy < -1 || yy > yLimit)
			continue;*/
		for(int x = 0; x < _width; x++){
			double xx = x - xOffsetPixel;
			/*if(xx < -1 || xx > xLimit){
				continue;
			}*/
			if(xx >= 100){
				int a=0;
			}
			_tiles[y][x]->Render(xx, yy);
		}
	}
}

void Level1::Load(){
	std::string levelFilePath = "../Resources/Levels/Level1.txt";
	std::ifstream levelFile(levelFilePath);

	if(levelFile.is_open()){
		std::string line;
		getline(levelFile, line);
		int spaceIndex = line.find_first_of(" ");
		_width = std::stoi(line.substr(0, spaceIndex));
		_height = std::stoi(line.substr(spaceIndex + 1));

		int x = 0;
		while (getline(levelFile, line)){
			_tiles.push_back(std::vector<ITile*>());
			int y = 0;
			while(y < _width){
				int typeOfTile = line[y] - 48;
				switch(typeOfTile){
				case 1:
				{
					_tiles[x].push_back(new SolidTile());
					break;
				}
				case 0:
				{
					COIN_MANAGER->AddCoin(y*32, x*32);
					_tiles[x].push_back(new VoidTile());
					break;
				}
				default:
					_tiles[x].push_back(new VoidTile());
				}
				y++;

			}
			x++;
		}
	}
}

void Level1::SetOffset(double xOffset, double yOffset){
}

Level1::~Level1(void){
}
