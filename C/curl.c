#include <curl/curl.h>
#include <stdio.h>

int main(void){
  
  CURL *request;

  curl_global_init(CURL_GLOBAL_ALL);

  /* get a curl handle */
  request = curl_easy_init();
  
  if(request) {

    curl_easy_setopt(request, CURLOPT_URL, "http://ifconfig.me");
    curl_easy_setopt(request, CURLOPT_PROXY, "socks5://127.0.0.1:9050");
  
    curl_easy_cleanup(request);
  }
  curl_global_cleanup();
  return 0;

}


