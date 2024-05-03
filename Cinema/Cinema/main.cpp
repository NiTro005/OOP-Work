#include "cinema.h"

int main() {
	Admin user("Stiv", "134f53s1");
	user.set_login("Stuart");
	user.addMovie("Marvel", "Mstitely voina", 2.45, 8.5);
	CString test = user.get_login();
	test.print();
	return 0;
}
