#pragma once
#include <iostream>

std::string getTimestamp();
   
std::string encryptWithHMAC(const char* key, const char* data);