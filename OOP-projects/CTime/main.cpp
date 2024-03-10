#include "ctime.h"
#include <iostream>
int main() {
	int compare;
	CTime t1, t4;
	CTime t2(12, 56, 17);
	CTime t3(t2);
	t2.output();
	t3.output();
	t1.input();
	t1.assign(t4);
	t4.output();
	t2.set_values(20, 4, 3);
	t2.output();
	t2.add_hours(6);
	t2.output();
	compare = t3.compare(t2);
	std::cout << compare << std::endl;

}