#pragma once
#include <iostream>
#include <unordered_map>
#include <map>
#include "request.h"



inline std::unordered_map<std::string, std::string> convertParam(std::string fromCoin, std::string toCoin);

inline std::unordered_map<std::string, std::string> assetParam(std::string coin);

inline std::unordered_map<std::string, std::string> klinesParam(std::string coin, std::string time);

inline std::unordered_map<std::string, std::string> orderParam(std::string coin, std::string side, std::string type, std::string amount);

inline std::unordered_map<std::string, std::string> accSnapshot(std::string type);
