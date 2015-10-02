#include <stdio.h>
#include <string.h>

typedef enum {
	COM, PHO, CHAO, BANH_MI,

} menu;

void thongbao(menu state) {

	switch (state) {

	case 1: {
		printf(" Ban da chon COM ! \n");
		state = PHO;
	}
		break;

	case 2: {
		printf(" Ban da chon PHO ! \n");
		state = CHAO;
	}
		break;

	case 3: {
		printf(" Ban da chon CHAO ! \n");
		state = BANH_MI;
	}
		break;

	}

}
int main() {
	menu mon_an;
	mon_an = COM;
	do {
		thongbao(mon_an);
	} while (mon_an != BANH_MI);
	return 0;

}
