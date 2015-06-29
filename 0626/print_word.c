#include <stdio.h>
int main()
{
	enum states
	{
		before, inside, after
	}state;

	int c;
	state = before;
	while((c = getchar()) != EOF)
	{
		switch(state)
		{
			case before:
				if(c == '\n')
					putchar(c);
				else if(c != ' ')
				{
					putchar(c);
					state = inside;
				}
				break;
			case inside:
				switch(c)
				{
					case '\n':
						putchar(c);
						state = before;break;
					case ' ':
						state = after;break;
					default:
						putchar(c);
				}
				break;
			case after:
				if(c == '\n')
				{
					putchar(c);
					state = before;
				}
		}
	}
	return 0;
}







