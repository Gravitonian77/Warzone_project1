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
    static map<string, int> continents;
    list<Territory*> territories;
public:
    Map();
    void initiate_territories(vector<Territory*> territories);
    const list<Territory*> &getTerritories() const;
    void set_territories(const list<Territory *> &territories);
    void establish_graph_edges();
    Territory* find_territory_by_name(const string& name);
};

class Territory{
private:
    string name;
    int x;
    int y;
    string continent;
	vector<string> adj_territory_names;
    list<Territory*> adj_territories;
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
    const vector<string> &get_adj_territory_names() const;
    void set_adj_territory_names(const vector<string> &adjTerritory);
    list<Territory *> & get_adj_territory();
    void set_adj_territory(const list<Territory *> &adjTerritories);
};


class MapLoader{
public:

	MapLoader();
	MapLoader(string map_file_name);
	MapLoader(const MapLoader& map);
	const string &getMapFileName() const;
	void setMapFileName(const string &mapFileName);
    static const vector<Territory*>& get_territories();

private:
	string map_file_name;
    map<string, int> continents;
    static vector<Territory*> territories;
public:
    const map<string, int> &getContinents() const;
    void setContinents(const map<string, int> &continents);
};

#endif //WARZONE_PROJECT1_MAP_H
