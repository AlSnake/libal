#include <assert.h>
#include <stdio.h>

#include "al/al.h"

int test_version(void)
{
	assert(al_get_version() == 0.1f);
	return 1;
}

int main(void)
{
	assert(test_version() == 1);
	return 0;
}
