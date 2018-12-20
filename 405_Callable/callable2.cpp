#include <iostream>
#include <functional>
using namespace std;


template<typename F, typename ... Types>
decltype(auto) chronometry(F&& f, Types&& ... args)
{
	std::forward<F>(f)(std::forward<Types>(args)...); 
}

int main()
{
						//// 이 자리는 Function Object가 다 올수 있어야 한다.
						//// F&&로 받는 이유
	chronometry(less<int>(), 10, 20);
}