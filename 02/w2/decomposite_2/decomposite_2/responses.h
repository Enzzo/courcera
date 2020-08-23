#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>

/*
struct BusesForStopResponse
ostream& operator << (ostream& os, const BusesForStopResponse& r)
struct StopsForBusResponse
ostream& operator << (ostream& os, const StopsForBusResponse& r)
struct AllBusesResponse
ostream& operator << (ostream& os, const AllBusesResponse& r)
*/


struct BusesForStopResponse {
    std::vector<std::string> buses;
};

std::ostream& operator << (std::ostream&, const BusesForStopResponse&);

struct StopsForBusResponse {
    std::string bus;
    std::vector<std::pair<std::string, std::vector<std::string>>> stops_for_buses;
};

std::ostream& operator << (std::ostream&, const StopsForBusResponse&);

struct AllBusesResponse {
    std::map<std::string, std::vector<std::string>> buses_to_stops;
};

std::ostream& operator << (std::ostream&, const AllBusesResponse&);