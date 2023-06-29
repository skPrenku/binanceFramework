#include "../header/bnbClient.h"
#include "../header/params.h"
#include "../header/binanceAPI.h"
#include "../header/signature.h"
#include "json/json.h"

binance::binance() {
	this->clientStartTime = std::time(0);
}

binance::~binance() {
	curl_easy_cleanup(this->curl);
	curl_global_cleanup();
}

int binance::ping()
{
	Get::Request( this->curl, binancePing, "");

	return 0;
};

std::string binance::time()
{
	return Get::Request( this->curl, binanceTime, "");
};

//list coins 24hr ticker , or specific coin // "" = EMPTY or "BTCUSDT" for a specific coin
std::string binance::ticker24(std::string assetPair)
{
	if(assetPair.empty())
	return Get::Request(this->curl, binanceTicker24, "");
	else
	return Get::Request(this->curl, binanceTicker24,"symbol=" + assetPair);
};

//returns specific coin Price "BTCUSDT"
std::string  binance::coinPrice(std::string assetName)
{
	std::unordered_map<std::string, std::string> orderParameter =
	{
					{"symbol", assetName}
	};
	return Get::Request(this->curl, binancePrice, prepareRequest(orderParameter));
};

//return kandle statistic data for specific coin/time ..ex: (DOTUSDT for assetName, and time = 1s,1h,1d,1w,1m)
std::string binance::kandleLines(std::string assetName, std::string time)
{
	std::unordered_map<std::string, std::string> orderParameter =
	{
					{"symbol", assetName},
					{"interval", time}
	};
	return Get::Request( this->curl, binanceKlines, prepareRequest(orderParameter ));
};

//ex.: placeorder("BTCUSDT","MARKET","SELL","3");
std::string binance::placeOrder(std::string asset, std::string side, std::string type, std::string amount)
{
	std::unordered_map<std::string, std::string> orderParameter =
	{
			{"symbol", "BNBUSDT"},
			{"side", "BUY"},
			{"type", "LIMIT"},
			{"timeInForce", "GTC"},
			{"quantity", "1"},
			{"price", "50"},
			{"recvWindow","20000"}

	};
	return Post::Request( this->curl, "/api/v3/order/test", prepareSignedRequest(orderParameter));
};

//returns server Status
std::string binance::serverStatus() 
{

	return Get::Request( this->curl, binanceStatus, "");
};

std::string binance::allAssets() 
{

	return Get::Request( this->curl, binancePrice, "");
}

std::string binance::userAssets() 
{
	return Post::Request( this->curl, binanceUserAssets ,  getTimeAndSig());
}

//we convert assets by asking for a quoteID, of both coins, after we get the quoteID we sent a second request with the quoteID we got, this function returns the STATUS ->//PROCESS/ACCEPT_SUCCESS/SUCCESS/FAIL
//std::string binance::convert(std::string fromCoin, std::string toCoin, std::string fromAmount)
//{
//	//std::unordered_map<std::string, std::string> reqParameter
//	//{
//	//	{"fromAsset",fromCoin},
//	//	{"toAsset",toCoin},
//	//	{"fromAmount",fromAmount}
//	//};
//
//
//	std::string req = Post::Request(this->curl, binanceConvertRequest, prepareSignedRequest("fromAsset=DOTUSDT&toAsset=USDT&fromAmount=2"));
//	std::cout << "First request: " << req << std::endl;
//	Json::Value root;
//	Json::Reader reader;
//	reader.parse(req, root);
//	Sleep(2000);
//	const Json::Value responseQID = root["quoteId"];
//	
//
//	return "0";//orderStatus.asString();
//}
//
