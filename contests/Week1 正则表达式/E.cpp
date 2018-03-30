#include <bits/stdc++.h>
using namespace std;

const char ans[] = "Forty-two";

char buf[1024];

int main()
{
	while (fgets(buf, sizeof(buf), stdin) != nullptr)
	{
		char *head = buf, *tail;
		while ((head = strstr(head, "What is")) != nullptr)
		{
			if ((tail = strpbrk(head, "?.")) != 0) {
				if (*tail == '?') {
					*tail = 0;
					printf("%s %s.\n", ans, head+5);
				}
				head = tail+1;
			}
		}
	}
}
