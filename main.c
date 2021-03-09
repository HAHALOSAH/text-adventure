#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int currentX = 5;
int currentY = 5;
int gold = 10;
int inv;
char invMap[][10] = {
	"key",
	"map"
}
void saveGame() {
	const char *filedir;
	
	if ((filedir = getenv("HOME")) == NULL) {
		filedir = getpwuid(getuid())->pw_dir;
	}
	strcat(filedir, "/.text-adventure-save");
	
	char *saveData;
	strcpy(saveData, (char *) currentX);
	strcat(saveData, "\n");
	strcat(saveData, (char *) currentY);
	strcat(saveData, "\n");
	strcat(saveData, (char *) gold);
	strcat(saveData, "\n");
	strcat(saveData, (char *) inv);
	strcat(saveData, "\n");

	FILE *saveFile;
	saveFile = fopen(filedir);
	fputs(saveFile, saveData);
	fclose(saveFile);
}
int main() {
	printf("\n");
	saveGame();
	return 0;
}
