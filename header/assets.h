#pragma once
#include <iostream>
#include <vector>

struct positiveAsset 
{
	std::string	 coinName;
	std::string	 balance;

};

struct totalAsset 
{
	std::string	 coinName;
	std::string	 balance;
};



void loadUserAssets(const std::string& response);
void loadBnbAssets(const std::string& response);
bool hasEndingUSDT(std::string const& fullString);

static std::vector<positiveAsset> pAssetList;
static std::vector<totalAsset> tAssetList;