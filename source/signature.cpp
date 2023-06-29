#include <string>
#include <chrono>
#include "openssl/hmac.h"
#include "../header/signature.h"


 std::string getTimestamp() 
 {
    long long ms_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    return std::to_string(ms_since_epoch);
}

 std::string encryptWithHMAC(const char* key, const char* data) 
 {
    unsigned char* result;
    static char res_hexstring[64];
    int result_len = 32;
    std::string signature;

    result =  HMAC(EVP_sha256(), key, strlen((char*)key), const_cast<unsigned char*>(reinterpret_cast<const unsigned char*>(data)), strlen((char*)data), NULL, NULL);
    for (int i = 0; i < result_len; i++) {
        sprintf(&(res_hexstring[i * 2]), "%02x", result[i]);

    }

    for (int i = 0; i < 64; i++) {
        signature += res_hexstring[i];
    }

    return signature;
}