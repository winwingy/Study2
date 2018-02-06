// CurlUse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <curl.h>
#include <easy.h>
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"wldap32.lib")


size_t readFun(void* ptr, size_t size, size_t nmemb, void *userptr)
{
	printf((char*)ptr);
	for (int i = 0; i < nmemb; ++i)
	{
		//printf((char*)ptr);
	}
	return 1;
}


int _tmain(int argc, _TCHAR* argv[])
{
	CURL *curl_ = ::curl_easy_init(); 

	::curl_easy_setopt(curl_, CURLOPT_URL, "http://www.66ip.cn/?sxb=%B9%E3%B6%AB&tqsl=10&ports%5B%5D2=&ktip=&sxa=&radio=radio&submit=%CC%E1++%C8%A1");

	::curl_easy_setopt(curl_, CURLOPT_HTTPGET, 1);
	::curl_easy_setopt(curl_, CURLOPT_READFUNCTION, &readFun); 

	::curl_easy_setopt(curl_, CURLOPT_PROXY, "58.251.230.3:9000");
	//::curl_easy_setopt(curl_, CURLOPT_PROXYUSERPWD,"user:pwd");


	auto res = ::curl_easy_perform(curl_);
 	::curl_easy_reset(curl_);


	::curl_easy_cleanup(curl_);
	system("pause");
	return 0;
}

