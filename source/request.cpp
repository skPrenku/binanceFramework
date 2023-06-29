#include "../header/signature.h"
#include "../header/request.h"
#include "../header/config.h"
#include "../header/binanceAPI.h"

std::string prepareRequest(std::unordered_map<std::string, std::string> &param) {
    std::string Request = "";

    if (!param.empty()) {
        for (auto it = param.begin(); it != param.end(); ++it)
        {
            if (it == param.begin()) {
                Request.append(it->first + "=" + it->second);
            }
            else {
                Request += '&';
                Request.append(it->first + "=" + it->second);
            }
        }
    }

    return  Request;
}

std::string prepareRequest(std::string param) 
{
    return  param + "&timestamp=" + getTimestamp();
}

std::string prepareSignedRequest(std::unordered_map < std::string, std::string> &param)
{
    std::string Request = "";

    if (!param.empty()) {


            for (auto it = param.begin(); it != param.end(); ++it)
            {
                if (it == param.begin())
                {
                    Request.append(it->first + "=" + it->second);
                }
                else {
                    Request += '&';
                    Request.append(it->first + "=" + it->second);
                }
            }
    }

    Request.append("&timestamp=");
    Request.append(getTimestamp());

    std::string signature = encryptWithHMAC(apiSecret.c_str(), Request.c_str());
    Request.append("&signature=");
    Request.append(signature);

    return  Request;
}

std::string prepareSignedRequest(std::string param)
{
    std::string Request = param;

    Request.append("&timestamp=");
    Request.append(getTimestamp());

    std::string signature = encryptWithHMAC(apiSecret.c_str(), Request.c_str());
    Request.append("&signature=");
    Request.append(signature);

    return  Request;
}

std::string addSignature(std::string param)
{
    std::string Request = param;
    std::string signature = encryptWithHMAC(apiSecret.c_str(), Request.c_str());
    Request.append("&signature=");
    Request.append(signature);

    return  Request;
}
   
std::string getTimeAndSig() 
{
    std::string Request;
    Request.append("timestamp=");
    Request.append(getTimestamp());

    std::string signature = encryptWithHMAC(apiSecret.c_str(), Request.c_str());
    Request.append("&signature=");
    Request.append(signature);

    return Request;
}
 size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
     ((std::string*)userp)->append((char*)contents, size * nmemb);

    return size * nmemb;
}


std::string Get::Request(CURL* curl, std::string bnbAPI ,std::string query)    // use function to prepare Request prepareRequest()
{
    std::string url = binanceURL +  bnbAPI + '?' + query;
    CURLcode res;

    srvResponse.clear();
    if (curl) {


            curl_slist* hdr = NULL;
            hdr = curl_slist_append(hdr, ("X-MBX-APIKEY:" + apiKey).c_str());
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, hdr);



        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &srvResponse);
        res = curl_easy_perform(curl);

        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        if (res != CURLE_OK)
            printf("Error CURL: %d", res);



    }

    return srvResponse;
}


std::string Post::Request( CURL *curl,std::string bnbAPI, std::string query/* use function to prepare Request prepareSignedPOSTRequest()*/)
{
    curl = curl_easy_init();
    
    CURLcode res;
    std::string binanceUrl = binanceURL + bnbAPI + '?' + query;
    srvResponse.clear();
    curl = curl_easy_init();
    if (curl) {


            curl_slist* hdr = NULL;
            hdr = curl_slist_append(hdr, ("X-MBX-APIKEY:" + apiKey).c_str());
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, hdr);
        

        curl_easy_setopt(curl, CURLOPT_URL, binanceUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, query.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &srvResponse);
        res = curl_easy_perform(curl);


        if (res != CURLE_OK)
            printf("Error CURL: %d", res);

    }
   // curl_easy_cleanup(curl);
    return srvResponse;
}