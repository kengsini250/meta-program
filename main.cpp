#include <iostream>
#include <string>

class Text
{
public:
	virtual std::string GET(const std::string str) const
	{
		return str;
	}
};

template <class X = Text>
class PartA : public X
{
public:
	using X::X;

	virtual std::string GET(const std::string& str) const
	{
		return "std::cout<<\"" + X::GET(str) + "\"<<'\\n';";
	}
};

template <class X = Text>
class Main : public X
{
public:
	using X::X;

	virtual std::string GET(const std::string& str) const
	{
		return "int main()\n{\n" + X::GET(str) + "\n}";
	}
};

template <class X = Text>
class Head : public X
{
public:
	using X::X;

	virtual std::string GET(const std::string& str) const
	{
		return "#include<iostream>\n" + X::GET(str);
	}
};

int main()
{
	Head<Main<PartA<>>> c;
	std::cout << c.GET("meta program");
}
