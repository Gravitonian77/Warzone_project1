//
// Created by garvi on 2023-12-19.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;

#ifndef WARZONE_PROJECT1_MAP_H
#define WARZONE_PROJECT1_MAP_H

class Territory;

class Map{
private:
    map<string, int> continents;
    list<Territory*> territories;
public:
    Map();
    void initiate_territories(vector<Territory*> territories);
};

class Territory{
private:
    string name;
    int x;
    int y;
    string continent;
	vector<string> adj_territory;
public:
	Territory();
    Territory(string, int, int, string, vector<string> t);
	Territory(const Territory& t);

    const string &getName() const;
    int getX() const;
    void setX(int x);
    void setName(const string &name);
    int getY() const;
    void setY(int y);
    const string &getContinent() const;
    void setContinent(const string &continent);
    const vector<string> &getAdjTerritory() const;
    void setAdjTerritory(const vector<string> &adjTerritory);
};


class MapLoader{
public:

	MapLoader();
	MapLoader(string map_file_name);
	MapLoader(const MapLoader& map);
	const string &getMapFileName() const;
	void setMapFileName(const string &mapFileName);
    const vector<Territory*>& getTerritories() const;

private:
	string map_file_name;
    //replace these 2 attributes with a Map object
    map<string, int> continents;
    vector<Territory*> territories;
};

#endif //WARZONE_PROJECT1_MAP_H
