#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int *process(string &pattern) {
	int *lps = new int[pattern.size()];
	memset(lps, 0, (pattern.size())*sizeof(int));
	int len=0, i=0;
	while(i < pattern.size()) {
		if(i==0)
			lps[i++] = 0;
		if(pattern[i] == pattern[len])
			lps[i++] = ++len;
		else
			if (len != 0)
				len = lps[len-1];
			else
				lps[i++] = 0;
	}
	return lps;
}

vector<int> kmp(string &text, string &pattern, int *lps) {
	vector<int> check;
	int j=0, i=0;
	while(i<text.size()) {
		if(text[i] == pattern[j]){
			j++;
			i++;
		}

		if(j == pattern.size()) {
			check.push_back(i-j);
			j = lps[pattern.size()-1];
		}
		else if (i < text.size() && pattern[j] != text[i])
		{
			if (j != 0)
				j = lps[j-1];
			else
				i++;
		}
	}
	return check;
}

int main()
{
	string pattern, text;
	cin >> pattern;
	int *lps = process(pattern);
	cin >> text;
	vector<int> check = kmp(text, pattern, lps);
	if(check.size() == 0)
		printf("Pattern not found anywhere in the text.\n");
	else {
		for(int i=0; i<check.size(); i++)
			printf("Pattern found at the following index in text :%d\n", check[i]);
	}
	return 0;
}
