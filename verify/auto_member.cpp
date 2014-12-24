
#include <iostream>

class foo
{
public:
	//auto	mem;
	int	mem;
};

int
main(int argc, char *argv[])
{
	foo	f;
	f.mem = 100;
	f.mem = f.mem;
	return 0;
}
