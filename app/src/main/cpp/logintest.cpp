#include <jni.h>
#include "include/jni_log.h"
#include "include/curl/curl.h"
// Write C++ code here.
//
// Do not forget to dynamically load the C++ library into your application.
//
// For instance,
//
// In MainActivity.java:
//    static {
//       System.loadLibrary("logintest");
//    }
//
// Or, in MainActivity.kt:
//    companion object {
//      init {
//         System.loadLibrary("logintest")
//      }
//    }


#define URL "https://mat1.gtimg.com/pingjs/ext2020/qqindex2018/dist/img/qq_logo_2x.png"

static void
test_easy_curl(const char *cert){
    CURL *curl;
    CURLcode res;
    char error[1024];

    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, URL);
#ifdef __ANDROID__
    //curl_easy_setopt(curl, CURLOPT_CAINFO, cert);
#endif
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2);
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER   , error );

    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
}


extern "C"
JNIEXPORT void JNICALL
Java_com_reverccqin_logintest_ui_login_LoginActivity_httpCurl(JNIEnv *env, jclass clazz) {
    // TODO: implement httpCurl()
    test_easy_curl(NULL);
    LOGD("httpCurl!");
}