//
// Created by garvi on 2023-12-20.
//

#include "Map.h"
#include <iostream>
#include "fstream"
#include <map>

using namespace std;

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