#pragma once
template <typename T1, typename T2>
class APair
{
private:
	T1 a;
	T2 b;
public:
	T1 & first();
	T2 & second();
	T1 first() const { return a; }
	T2 second() const { return b; }
	APair(const T1 & aval, const T2 & bval) : a(aval), b(bval) {}
	APair() {}
};

template<typename T1, typename T2>
T1 & APair<T1, T2>::first()
{
	return a;
}

template<typename T1, typename T2>
T2 & APair<T1, T2>::second()
{
	return b;
}