
#include "../header/signature.h"
#include "../header/params.h"
#include "../header/request.h"
#include "../header/binanceAPI.h"
#include "json/json.h"



inline std::unordered_map<std::string, std::string> convertParam(std::string fromCoin, std::string toCoin)
{
	std::unordered_map<std::string, std::string> urlParameter =
	{
		{"fromAsset",fromCoin},
		{"toAsset",toCoin},
	};
	return urlParameter;
}




inline std::unordered_map<std::string, std::string> klinesParam(std::string coin, std::string time)
{
	std::unordered_map<std::string, std::string> urlParameter =
	{
		{"symbol",coin},
		{"interval",time},

	};
	return urlParameter;
}

inline std::unordered_map<std::string, std::string> orderParam(std::string coin,std::string side,std::string type,std::string amount) {

	std::unordered_map<std::string, std::string> urlParameter =
	{
		{"symbol",coin},
		{"side",side},
		{"type",type},
		{"quantity",amount}
				
	};
	return urlParameter;
}

