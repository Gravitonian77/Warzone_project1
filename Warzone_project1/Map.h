//
// Created by garvi on 2023-12-19.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef WARZONE_PROJECT1_MAP_H
#define WARZONE_PROJECT1_MAP_H

class Map{

};

class Territory{
private:
    int x, y;
	Territory* next_territory;
public:
	Territory();
    Territory(int, int, Territory*);
	Territory(const Territory& t);
};

class MapLoader{
public:
	MapLoader();
	MapLoader(string map_file_name);
	MapLoader(const MapLoader& map);
	const string &getMapFileName() const;
	void setMapFileName(const string &mapFileName);

private:
	string map_file_name;
};

#endif //WARZONE_PROJECT1_MAP_H
