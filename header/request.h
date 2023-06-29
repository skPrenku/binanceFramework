#pragma once
#include <iostream>
#include <string>
#include <unordered_map>


#define CURL_STATICLIB 
#include "curl/curl.h"





std::string prepareSignedRequest(std::unordered_map < std::string, std::string> &param);
std::string prepareSignedRequest(std::string param);
std::string addSignature(std::string param);
std::string prepareRequest(std::unordered_map<std::string, std::string> &param);
std::string prepareRequest(std::string param);
std::string getTimeAndSig();


size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);

namespace Get { 
     
     static std::string srvResponse;   

     std::string Request(CURL* curl, std::string bnbAPI, std::string query);
}


namespace Post {

    static std::string srvResponse;
   
    std::string Request( CURL *ptr, std::string bnbAPI, std::string query);
}

