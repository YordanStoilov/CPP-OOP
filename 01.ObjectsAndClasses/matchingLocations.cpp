#include <iostream>
#include <string>
#include <vector>
#include <sstream>


class Location{
public:
    Location(std::istream& stream){

        std::string data;
        getline(stream, data);
        std::istringstream iss(data);
        std::string element;

        std::getline(iss, element, ',');
        name = element;

        std::getline(iss, element, ',');
        lattitude = std::stod(element);

        std::getline(iss, element, ',');
        longitude = std::stod(element);
    }
    const std::string getName(){
        return name;
    }
    const double getLattitude(){
        return lattitude;
    }
    const double getLongtitude(){
        return longitude;
    }
    const void printInfo(){
        std::cout << name << ',' << lattitude << ',' << longitude << '\n';
    }

private:
    std::string name;
    double lattitude;
    double longitude;
};

class LocationManager{
public:
    LocationManager(std::istream& stream){
        buildLocationObjectsFromInput(stream);
    }
    void findLocationsFromInput(std::istream& stream){
        std::string line;
        getline(stream, line);
        
        while (true){
            getline(stream, line);
            std::vector<std::string> data;

            std::string buffer;
            std::istringstream iss(line);
            if (line == "."){
                    break;
                }

            while (iss >> buffer){
                data.push_back(buffer);
            }
            if (data.size() == 1){
                findLocation(data[0]);
            } 
            else if (data.size() == 2) {
                double lat = std::stod(data[0]);
                double lon = std::stod(data[1]);
                findLocation(lat, lon);
            }
        }
    }

private:
    const void findLocation(std::string& name){
        for (Location& location : locations){
            if (location.getName() == name){
                location.printInfo();
            }
        }
    }
    const void findLocation(double lat, double lon){
        for (Location& location : locations){
            if (location.getLattitude() == lat && location.getLongtitude() == lon){
                location.printInfo();
            }
        }
    }
    void buildLocationObjectsFromInput(std::istream& stream){
        while (true){
            if (stream.peek() == '.'){
                break;
            }
            Location location(stream);
            locations.push_back(location);
        }
    }
    std::vector<Location> locations;
};

int main(){
    LocationManager lm(std::cin);
    lm.findLocationsFromInput(std::cin);
}