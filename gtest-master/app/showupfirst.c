#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"


void showupfirst(text txt)
{
    process_backward(txt, show_upfirst);
}

static void show_upfirst(int index, char *contents){
    assert(contents != NULL);
    UNUSED(index);
    int i, len;
    len = strlen(contents);
    
    if((contents[0] >= 'a') && (contents[0] <= 'z'))
	printf("%c", contents[0] - 'a'+ 'A');
	else printf("%c", contents[0]);

    for(i = 1; i < len; i++)
	if((contents[i] >= 'a')
	   && (contents[i] <= 'z') && (contents[i-1] == ' '))
	printf("%c", contents[i] - 'a'+ 'A');
	else printf("%c", contents[i]);
}
