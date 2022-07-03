#include "client.h"
#include <stdlib.h>
#include <stdio.h>


void erro_hadnling(char *message)
{
	fputs(message, stderr);
	fputc('\n',stderr);
	exit(1);
}
