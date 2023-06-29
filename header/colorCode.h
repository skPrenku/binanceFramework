#pragma once
#include <iostream>

#define Black           "30" 
#define BlackBG			"40"
#define Red             "31"
#define RedBG			"41"
#define Green           "32"  
#define GreenBG         "42"
#define Yellow          "33" 
#define YellowBG        "43"
#define Blue            "34" 
#define BlueBG			"44"
#define Magenta         "35" 
#define MagentaBG		"45"
#define Cyan            "36" 
#define CyanBG			"46"
#define White           "37"  
#define WhiteBG			"47"
#define BrightBlack     "90"  
#define	BrigtBlackBG	"100"
#define BrightRed       "91"
#define	BrightRedBG		"101"
#define BrightGreen     "92"  
#define	BrightGreenBG   "102"
#define BrightYellow    "93"  
#define BrightYellowBG  "103"
#define BrightBlue      "94" 
#define BrightBlueBG    "104"
#define BrightMagenta   "95" 
#define BrightMagentaBG "105"
#define BrightCyan      "96"  
#define BrightCyanBG    "106"
#define BrightWhite     "97" 
#define BrightWhiteBG   "107"

inline void color(std::string data, std::string colorCode)
{
    std::cout << "\x1B[" << colorCode << "m" << data << "\x1B[0m";
}