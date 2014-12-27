//#include "stdafx.h" //you may have to remove this depending on you compiler
#include <iostream>
#include<cstdio>

using namespace std;

struct Pizza_Analysis    //defining the struct
{
	char company_name[35];
	double  dia_of_pizza;
	double weight_of_pizza;
};

int main()
{
	int num_of_companies;


        //using new to allocate the structur
	Pizza_Analysis *ps = new Pizza_Analysis;
    int *array = new int[4];
    array[14] = 4;
    printf("%d\n",array[14]); 
	
	cout << "How many companies do you want to look at? ";
	cin >> num_of_companies;
	cin.get();
        
        //the struct array at work
	for(int i=0; i<1; i++)
	{
		cout << "\n\nPlease enter company name. ";
		cin.getline(ps->company_name,35);

		cout <<"\n\nPlease enter the diameter of the pizza. ";
		cin >> ps->dia_of_pizza;

		cout <<"\n\nPlease enter the weight of the pizza. ";
		cin >> ps->weight_of_pizza;
		
		cin.get();
	}
	
	cout << endl << endl;
         
         //the struct array at work
         // prints the input to screen
	for(int i=0; i<1; i++)
	{
		cout << "Company Name : " << ps->company_name << endl 
		 << "diameter of pizza : " << ps->dia_of_pizza << endl
		 << "Weight of pizza : " << ps->weight_of_pizza << endl <<endl;
	};


	delete [] ps;
	system("pause");//you may have to remove this depending on you compiler
	return 0;
}
