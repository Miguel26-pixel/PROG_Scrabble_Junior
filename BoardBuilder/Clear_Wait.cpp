#include "Board.h"
#include "BoardBuilder.h"
#include <time.h>
#include <concrt.h>


void clean() {
	system("cls");
}
void wait() {
	Concurrency::wait(100);
}