// 2. Design, Develop and Implement a Program in C for the following operations on Strings
// a. Read a main String (STR), a Pattern String (PAT) and a Replace String (REP)
// b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in STR with REP if PAT exists in STR.
// Report suitable messages in case PAT does not exist in STR.Support the program with functions for each of the above operations.
// Don't use Built-in functions.

#include <stdio.h>
#define MAX 100

char str[MAX], pat[MAX], rep[MAX], ans[MAX];
int i, j, c, m, k, patternExist = 0;

// c and m are index for main string
// i is index for pattern string
// j is inedx for ans string
// k is index for rep string

void input(char *string, int length)
{
	fgets(string, length, stdin);
	for (int x = 0; x <= length; x++)
	{
		if (string[x] == '\n')
		{
			string[x] = '\0';
			break;
		}
	}
}

void matchString()
{
	i = m = c = j = 0;
	while (str[c] != '\0')
	{
		if (str[m] == pat[i])
		{
			i++;
			m++;
			if (pat[i] == '\0')
			{
				for (k = 0; rep[k] != '\0'; k++, j++)
					ans[j] = rep[k];
				i = 0;
				c = m;
				patternExist = 1;
			}
		}
		else
		{
			ans[j] = str[c];
			j++;
			c++;
			m = c;
			i = 0;
		}
	}
	ans[j] = '\0';
}

int main()
{
	printf("\nEnter a string: \n");
	input(str, MAX);
	printf("\nEnter a search string: \n");
	input(pat, MAX);
	printf("\nEnter a replace string: \n");
	input(rep, MAX);
	matchString();
	if (patternExist)
		printf("\nThe resultant string is \"%s\".\n", ans);
	else
		printf("\nPattern not found.\n");
	return 0;
}
