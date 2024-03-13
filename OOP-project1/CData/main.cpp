#include "cdata.h"
int main() {
	CData d1, d4;
	CData d2(12, 12, 1978);
	CData d3(d2);
	d2.output();
	d1.input();
	d4.set_values(23,2,1933);
	d4.output();
	d1.assign(d3);
	d3.output();
	
}