#include "shell.h"
/**
 * fileExistsInDirectory - Check if a file exists in a given directory.
 * @filename: The name of the file to check.
 * Return: 1 if the file exists.
 */
int fileExists(const char *filename)
{
	if (access(filename, F_OK) != -1)/*The file exists*/
		return 1;
	else/*The file does not exist*/
		return 0;
}
