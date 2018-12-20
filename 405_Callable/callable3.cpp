#include <iostream>
#include <functional>
using namespace std;

template<typename F, typename ... Types>
decltype(auto) chronometry(F&& f, Types&& ... args)
{
//	std::forward<F>(f)(std::forward<Types>(args)...);

	//f(std::forward<Types>(args)...);

	return  invoke(std::forward<F>(f), 
							std::forward<Types>(args)...);

}

class Dialog
{
public:
	void Close() {} 
};

int main()
{
	Dialog dlg;
	//// 멤버함수 포인터와 객체를 전달한다면?
	chronometry(&Dialog::Close, &dlg);
	
//	void (Dialog::*f)() = &Dialog::Close;

//	(dlg.*f)();		//// 멤버함수 부르는 법
//	f(&dlg);			//// 우리가 원하는 법
//	invoke(f, &dlg);	//// 우리가 원하는 방식으로 멤버함수를 부르는법
}