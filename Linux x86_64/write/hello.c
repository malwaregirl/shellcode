#include <unistd.h>
#include <stdio.h>

__attribute__((section(".text")))
unsigned char shellcode[] = "\x48\x31\xc0\x48\x31\xff\x48\x31\xd2\x50\x68\x68\x65\x6c\x6c\x48\xff\xc0\x48\xff\xc7\x48\x89\xe6\xb2\x04\x0f\x05\x48\x31\xc0\x48\x31\xff\xb0\x3c\x0f\x05";
int main() {

	/* Cast to a function pointer and then call the function */
	int (*ret)() = (int(*)())shellcode;
	ret();
}