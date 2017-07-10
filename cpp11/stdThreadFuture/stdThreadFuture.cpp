// stdThreadFuture.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "boost\thread\thread.hpp"
#include "boost\thread\future.hpp"
#include <windows.h>

namespace use_thread
{
	void Hello()
	{
		printf(" Hello()");
	};
	void useThread()
	{
		boost::thread t(&Hello);
		t.join();

	}
}


namespace use_promise
{
	void userPromise()
	{
		boost::promise<int> pr;
		boost::thread t([](boost::promise<int>& pr){ pr.set_value_at_thread_exit(9);}, std::ref(pr));		
		boost::unique_future<int> f =  pr.get_future();
		t.join();
		f.wait();
		do 
		{
			if (f.is_ready() && f.has_value())
			{
				printf("%d", f.get());
				break;
			}
			Sleep(500);
		} while (1);
	}
}

namespace package_task_use
{
	void packageTaskUse()
	{
		boost::packaged_task<int> pt([](){return 7;});
		boost::unique_future<int> fut = pt.get_future();
		boost::thread t(boost::move(pt));		
		t.join();
		fut.wait();
		printf("%d", fut.get());

	}
}

namespace async_use
{
	int show(int a)
	{
		printf("%d", a);
		return a;
	}
	void asyncUse()
	{
		boost::unique_future<int> uf = boost::async(boost::launch::async, boost::bind(&show, 15));
		
		do 
		{
			boost::future_status sta = uf.wait_for(boost::chrono::seconds(1));
			if (sta == boost::future_status::ready)
			{
				printf("boost::future_status::ready = %d", uf.get());
				break;
			}

		} while (1);
		

	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	//use_thread::useThread();
	//use_promise::userPromise();

	//package_task_use::packageTaskUse();

	async_use::asyncUse();
	system("pause");
	return 0;
}

