#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;
int nl, l;
int max(int p, int q) {
	return ((p>=q) ? p:q);
}
string func(string &pre, int start, int end) {
    int i;
	nl = 0;
	l = 0;
	if(pre[start] == 'l')
		return "l";
	else {
		for(i=(start+1); i<=end; i++) {
			if(pre[i] == 'l')
				l++;
			else
				nl++;
			if(nl == (l-1))
				break;
		}
    return func(pre, start+1, i) + pre[start] + func(pre, i+1, end));
    }
}

int main()
{
	int cases;
	string pre;
	scanf("%d", &cases);
	while(cases--) {
		cin >> pre;
		cout << func(pre, 0, pre.size()-1) << endl;
	}
	return 0;
}

