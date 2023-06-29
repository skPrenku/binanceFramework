
#include "../header/assets.h"
#include "../header/colorCode.h"
#include "json/json.h"
#include <iomanip>

bool hasEndingUSDT(std::string const& fullString) {
	std::string ending = "USDT";
	if (fullString.length() >= ending.length()) {
		return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
	}
	else {
		return false;
	}
}

void loadUserAssets( const std::string &response) {
//	pAssetList.push_back({ "test", 0.123123, 332 });
	Json::Value Root;
	Json::Reader reader;

	if (reader.parse(response, Root)) {

		const Json::Value Asset = Root;		

		for (int i = 0 ; i <(int) Asset.size(); i++)
		{		
			color(Asset[i]["asset"].asString(), Yellow); std::cout << " ";
			color(Asset[i]["free"].asString(), Cyan);
			std::cout << "\n";
		}
	}
}

void loadBnbAssets(const std::string& response) {
	Json::Value Root;
	Json::Reader reader;
	if (reader.parse(response, Root)) {

		const Json::Value Asset = Root;

		for (int i = 0; i < (int)Asset.size(); i++)
		{
			if (hasEndingUSDT(Asset[i]["symbol"].asString()))
			{
				tAssetList.push_back({ Asset[i]["symbol"].asString(), Asset[i]["price"].asString()});
				color(Asset[i]["symbol"].asString(), Yellow); std::cout << " "; color(Asset[i]["price"].asString(), Cyan);
				std::cout << "\n";
			}

		}
	}
	std::cout << tAssetList[0].coinName << " "<<std::fixed<<std::setprecision(8) << std::stold(tAssetList[0].balance);
}