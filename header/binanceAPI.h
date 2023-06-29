
#pragma once

//binance REST API defs

#define binanceURL "https://api.binance.com"
//#define binanceURL "https://testnet.binance.vision"


////////////////////////////////////////////////////////////////////////////////////////////////////
//                                binance API CALLs
////////////////////////////////////////////////////////////////////////////////////////////////////
//								GET API CALLS for binance
#define	binanceAggTrades	"/api/v3/aggTrades"
#define	binanceAvgPrice		"/api/v3/avgPrice"
#define	binanceDepth		"/api/v3/depth"
#define	binanceExchangeInfo	"/api/v3/exchangeInfo"
#define	binanceKlines		"/api/v3/klines"
#define	binancePing			"/api/v3/ping"
#define	binanceTicker		"/api/v3/ticker"
#define	binanceTicker24		"/api/v3/ticker/24hr"
#define	binanceBookTicker	"/api/v3/ticker/bookTicker"
#define	binancePrice		"/api/v3/ticker/price"
#define	binanceTime			"/api/v3/time"
#define	binanceTrades		"/api/v3/trades"
#define	binanceUiKlines		"/api/v3/uiKlines"
#define binanceStatus		"/sapi/v1/system/status"



////////////////////////////////////////////////////////////////////////////////////////////////////
//							POST API CALLS for binance
#define binanceOrder			"/api/v3/order"

	//to convert our assets we need to have a quoteID wich we get 
	//from requesting it from the server and use it to do the convert
#define binanceConvertRequest	"/sapi/v1/convert/getQuote"
#define binanceConvertAccept	"/sapi/v1/convert/getQuote"

#define binanceUserAssets		"/sapi/v3/asset/getUserAsset"
#define binanceMyCoins			"/sapi/v1/accountSnapshot"
#define binanceAllCoins			"/sapi/v1/capital/config/getall"
////////////////////////////////////////////////////////////////////////////////////////////////////



//public binance API ERROR Codes

#define BNB_BAN_WARNING			429 //reduce comunication speed ASAP if u get this errorCODE 
#define BNB_BAN_PERMANENT		418

#define BNB_UNKNOWN_ERR			-1000
#define BNB_NOT_AUTHORIZED		-1002
#define BNB_TOO_MANY_REQ		-1003
#define BNB_SRV_BUSY			-1004
#define BNB_TIMEOUT				-1007
#define BNB_INVALID_TIMESTAMP	-1021
#define BNB_INVALID_SIGNATURE	-1022


