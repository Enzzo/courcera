#include <fstream>
#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    std::string bus;
    std::string stop;
    std::vector<std::string> stops;
};

std::istream& operator >> (std::istream& is, Query& q) {
    // Реализуйте эту функцию
    std::string mode;
    is >> mode;
    if (mode == "NEW_BUS") {
        q.type = QueryType::NewBus;
        int count;
        is >> q.bus >> count;
        std::string s;

        q.stops.resize(count);
        for (size_t i = 0; i < count; i++) {
            is >> s;
            q.stops[i] = s;
        }

    }
    else if (mode == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    }
    else if (mode == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    }
    else if (mode == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }
    return is;
}

struct BusesForStopResponse {
    // Наполните полями эту структуру
    std::vector<std::string> buses;
};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r) {
    // Реализуйте эту функцию
    if (r.buses.size() == 0)os << "No stop";
    else {
        bool first = true;
        for (const std::string& s : r.buses) {
            if (!first) os << ' ';
            os << s;
            first = false;
        }
    }
    return os;
}

struct StopsForBusResponse {
    // Наполните полями эту структуру
    std::string bus;
    std::vector<std::string> stops;
    std::map<std::string, std::vector<std::string>> stops_to_bus;
};

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r) {
    // Реализуйте эту функцию
    if (r.stops.size() == 0)
        os << "No bus";
    else {

        for (const std::string& stop : r.stops) {
            os << "Stop " << stop << ": ";
            if (r.stops_to_bus.at(stop).size() == 1) {
                os << "no interchange";
            }
            else {
                for (const std::string& other_bus : r.stops_to_bus.at(stop)) {
                    if (r.bus != other_bus) {
                        os << other_bus << " ";
                    }
                }
            }
            os << std::endl;
        }

    }
    return os;
}

struct AllBusesResponse {
    // Наполните полями эту структуру
    std::map<std::string, std::vector<std::string>> buses;
    std::map<std::string, std::vector<std::string>> stops;
};

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r) {

    if (r.buses.empty()) {
        os << "No buses";
    }
    else {
        for (const auto& bus_item : r.buses) {
            os << "Bus " << bus_item.first << ": ";
            for (const std::string& stop : bus_item.second) {
                os << stop << " ";
            }
            os << std::endl;
        }
    }

    // Реализуйте эту функцию
    return os;
}

class BusManager {
public:
    void AddBus(const std::string& bus, const std::vector<std::string>& stops) {
        // Реализуйте этот метод
        buses_to_stop[bus] = stops;
        for (const std::string s : stops) {
            stops_to_bus[s].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const std::string& stop) const {
        // Реализуйте этот метод
        BusesForStopResponse r;
        if(stops_to_bus.count(stop) > 0)
            r.buses = stops_to_bus.at(stop);
        return r;
    }
   
    StopsForBusResponse GetStopsForBus(const std::string& bus) const {
        // Реализуйте этот метод
        StopsForBusResponse r;
        if (buses_to_stop.count(bus) > 0) {
            r.stops = buses_to_stop.at(bus);
            r.stops_to_bus = stops_to_bus;
            r.bus = bus;
        }
        return r;
    }
    
    AllBusesResponse GetAllBuses() const {
        // Реализуйте этот метод
        return { buses_to_stop, stops_to_bus };
    }
private:
    std::map<std::string, std::vector<std::string>> buses_to_stop;
    std::map<std::string, std::vector<std::string>> stops_to_bus;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
    int query_count;
    Query q;

    std::ifstream ifs("input.txt");

    ifs >> query_count;
    //std::cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        ifs >> q;
        //std::cin >> q;
        switch (q.type) {
        case QueryType::NewBus:
            bm.AddBus(q.bus, q.stops);
            break;
        case QueryType::BusesForStop:
            std::cout << bm.GetBusesForStop(q.stop) << std::endl;
            break;
        
        case QueryType::StopsForBus:
            std::cout << bm.GetStopsForBus(q.bus) << std::endl;
            break;
          
        case QueryType::AllBuses:
            std::cout << bm.GetAllBuses() << std::endl;
            break;
            
        }
    }

    return 0;
}