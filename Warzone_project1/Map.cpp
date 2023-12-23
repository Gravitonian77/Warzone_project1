//
// Created by garvi on 2023-12-20.
//

#include "Map.h"
#include <iostream>
#include "fstream"
#include <map>
#include <sstream>

using namespace std;

Territory::Territory() = default;

Territory::Territory(string name, int x, int y, string continent, vector<string> t) {
    this->name = name;
    this->x = x;
    this->y = y;
    this->continent = continent;
    this->adj_territory = t;
}

Territory::Territory(const Territory &t) {
    this->name = t.name;
    this->x = t.x;
    this->y = t.y;
    this->continent = t.continent;
    this->adj_territory = t.adj_territory;
}

const string &Territory::getName() const {
    return name;
}

void Territory::setName(const string &name) {
    Territory::name = name;
}

int Territory::getX() const {
    return x;
}

void Territory::setX(int x) {
    Territory::x = x;
}

int Territory::getY() const {
    return y;
}

void Territory::setY(int y) {
    Territory::y = y;
}

const string &Territory::getContinent() const {
    return continent;
}

void Territory::setContinent(const string &continent) {
    Territory::continent = continent;
}

const vector<string> &Territory::getAdjTerritory() const {
    return adj_territory;
}

void Territory::setAdjTerritory(const vector<string> &adjTerritory) {
    adj_territory = adjTerritory;
}

MapLoader::MapLoader() = default;

const vector<Territory*>& MapLoader::getTerritories() const {
    return territories;
}

MapLoader::MapLoader(std::string map_file_name) {
    ifstream file(map_file_name);
    string line;
    map<string, int> continents;
    vector<Territory *> territories;
    bool in_territory_section = false;

    if (file.is_open()) {
        cout << "File opened successfully." << endl;
        while (getline(file, line)) {
            if (line.empty())
                continue;
            else
                cout << "Reading line: " << line << endl;

            if (line[0] == '[') {
                in_territory_section = (line == "[Territories]");
                continue;
            }

            istringstream iss(line);
            string key;
            if (getline(iss, key, '=')) {
                //cout << "Reading continent: " << key <<endl;
                string value;
                if (getline(iss, value)) {
                    if (line[0] != '[') {
                        if (isdigit(value[0])) {
                            continents[key] = stoi(value);
                            cout << "Bonus value of " << key << ": " << continents[key] << endl;
                        }

                    } else {
                        cout << "Line skipped or not enough parts: " << line << endl;
                    }
                }
            }
            if (in_territory_section) {
                istringstream lineStream(line);
                string part;
                vector<string> parts;

                while (getline(lineStream, part, ',')) {
                    parts.push_back(part);
                }

                if (parts.size() >= 4) {
                    string territory_name = parts[0];
                    cout << "Loaded territory: " << territory_name << endl;
                    int x = stoi(parts[1]);
                    int y = stoi(parts[2]);
                    string continent = parts[3];
                    vector<string> adjacent_territories(parts.begin() + 4, parts.end());
                    territories.push_back(new Territory(territory_name, x, y, continent, adjacent_territories));
                } else {
                    cout << "Line skipped or not enough parts: " << line << endl;
                }
            }

        }

        file.close();
    }else{
        cout << "Unable to open file";
    }

}