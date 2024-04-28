#include "cinema.h"

int main() {
	User user("Stiv", "134f53s1");
	user.set_login("Stuart");
	CString test = user.get_login();
	test.print();
	return 0;
}
