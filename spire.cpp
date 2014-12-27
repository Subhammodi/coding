void solution(int N) {
    for(int i=1; i<=N; i++) {
        if(i%3 != 0 && i%5 != 0 && i%7 != 0)
            printf("%d\n", i);
        else {
            if(i%3 == 0)
                printf("Fizz");
            if(i%5 == 0)
                printf("Buzz");
            if(i%7 == 0)
                printf("Woof");
            printf("\n");
        }
    }
}

int digit(int n) {
    int res = 1;
    while(n/10) {
        res++;
        n /= 10;
    }
    return res;
}

int valid(string s) {
    int start = 0, end = s.size()-1;
    while(s[start] == ' ') {
        start++;
    }
    while(s[end] == ' ') {
        end--;
        if(start > end)
            return INT_MAX;
    }
    s = s.substr(start, end-start+1);
    if(s.size() > 11)
        return INT_MAX;
    else if(s.size() == 11) {
        if(s == "+1000000000" || s == "-1000000000")
            return atoi(s.c_str());
        else
            return INT_MAX;
    }
    else {
        int ans = atoi(s.c_str());
        if(ans > 1000000000)
            return INT_MAX;
        else if(ans == 0) {
            if(s.size() == 1 && s[0] == '0')
                return 0;
            if(s.size() == 2 && (s[0] == '+' || s[0] == '-') && s[1] == '0')
                return 0;
            else
                return INT_MAX;
        }
        else {
            if(ans < 0) {
                if(digit(-1*ans) == (s.size()-1))
                    return ans;
                return INT_MAX;
            }
            else {
                if(s[0] == '+') {
                    if(digit(ans) == (s.size()-1))
                        return ans;
                    return INT_MAX;
                }
                else {
                    if(digit(ans) == (s.size()))
                        return ans;
                    return INT_MAX;
                }
            }
            
        }
    }
}