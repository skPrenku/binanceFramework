#pragma once
#include <iostream>
#include <unordered_map>
#include "curl/curl.h"

class binance
{
public:

	//store all binance assets with balance bigger than 0; first-> NAME, second->BALANCE
	std::unordered_map<std::string, int64_t> assetList;

	CURL* curl = curl_easy_init();;
	// time of this client started
	std::time_t clientStartTime = 0;
	binance();
	//ping binance API server
	int ping();

	// get binance server time
	std::string time();

	// get binance server status
	std::string serverStatus();
	// binance asset/token 24hr ticker
	std::string ticker24(std::string assetName);

	// asset/token actual Price
	std::string coinPrice(std::string assetName);

	// binance kandle statistics coinpairs = assetName{BTCUSDT} , time{1h,1s,45m,1d,1w etc...}
	std::string kandleLines(std::string assetName, std::string time);

	std::string placeOrder(std::string asset, std::string side, std::string type, std::string amount);

	std::string convert(std::string fromCoin, std::string toCoin, std::string fromAmount);

	//list avaible coins with balances
	std::string allAssets();

	//list all positive coins/assets with No Zero balance
	std::string userAssets();

	~binance();

};