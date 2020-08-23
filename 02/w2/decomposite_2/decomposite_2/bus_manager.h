#pragma once
#include "responses.h"

class BusManager {
public:
    void AddBus(const std::string&, const std::vector<std::string>&);

    BusesForStopResponse GetBusesForStop(const std::string&) const;

    StopsForBusResponse GetStopsForBus(const std::string&) const;

    AllBusesResponse GetAllBuses() const;
private:
    std::map<std::string, std::vector<std::string>> buses_to_stops;
    std::map<std::string, std::vector<std::string>> stops_to_buses;
};