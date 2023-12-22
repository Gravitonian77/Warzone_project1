//
// Created by garvi on 2023-12-20.
//

#include "Map.h"
#include <iostream>
#include "fstream"
#include <map>

using namespace std;

Territory::Territory() = default;

Territory::Territory(int x, int y, Territory * t) {
    this->x = x;
    this->y = y;
    this->next_territory = t;
}

Territory::Territory(const Territory &t) {
    this->x = t.x;
    this->y = t.y;
    this->next_territory = t.next_territory;
}

MapLoader::MapLoader() = default;

MapLoader::MapLoader(std::string map_file_name){
	ifstream  file(map_file_name);
	string line;
	map<string, int> continents;
	vector<string> terriotries;

	if(file.is_open()){
		while(getline(file, line)){
			if(line.empty())
				continue;


		}
	}
}