#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int maxProfit(vector<int> &prices) {
        int ans = 0;
        int jump = 0;
        int previous, i;
        vector<int> *input = &prices;
        if(input->size() == 0)
            return 0;
        int start = input->at(0);
        for(i = 1; i < input->size(); i++)
        {
            if(input->at(i) < start)
            {
                if(jump == 0)
                    start = input->at(i);
                else
                {
                    ans += (previous - start);
                    jump = 0;
                }
            }
            else if(input->at(i) = start)
                continue;
            else
            {
                if(i == (input->size()-1))
                    ans += (previous - start);
                else
                    jump++;
            }

            previous = input->at(i);
        }
        return ans;
    }

int main()
{
	vector<int> *input;
	input->push_back(33);
	input->push_back(32);
	input->push_back(37);
	input->push_back(37);
	input->push_back(54);
	input->push_back(20);
	input->push_back(20);
	input->push_back(18);
	input->push_back(58);
	input->push_back(1);
	input->push_back(2);
	input->push_back(3);
	printf("%d\n", maxProfit(input));
	return 0;
}
