//============================================================================
// Name        : HardwoodSellerC.cpp
// Author      : Esteban Parra
// Version     : 1
// Copyright   : It's free
// Description : Main class for the Hardwood Seller
// Editor: Linghan Zhang
//============================================================================

#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "WoodItem.h"

using namespace std;


vector<string> InputItem;

void readInputFile(FILE *fd) ;
void checkInput(vector<string> Input);
void orderMake(string wood, double price, double time, int weight);
double deliveryTime(int weight,double base);

int main(int argc, char *argv[]) {
	FILE *fd;
    if(argc != 2)
	{
		cerr<<"please input the filename."<<endl;
		exit(1);
	}
	fd=fopen(argv[1],"r");
	if(fd == NULL)
	{
		cerr<<"cannnot open the file."<<endl;
		exit(1);
	}
	readInputFile(fd);
	checkInput(InputItem);
	return 0;
}

/*
 * Method to read the input file
 */
void readInputFile(FILE *fd) 
{
	char buf[100];
	char *tok;
 
	while(fgets(buf,100,fd))
	{
		tok = strtok(buf,";:");
		while(tok != NULL)
		{
			//cout<<tok<<endl;
			InputItem.push_back(tok);
			tok = strtok(NULL, ";:");
		}
	}
	fclose(fd);	
}

void checkInput(vector<string> Input)
{
	int i;
	int weight;
	char *trk;
	char buf[100];
	string IDinfo;
	WoodItem item;
	
	if(Input.size() < 4)
	{
		cerr<< "didn't input enough information, please follow the input format strictly." << endl;
	    exit(1);
	}
	else
	{
        for(i=0; i < 2; i++)
		{
			IDinfo += Input[i];
			IDinfo +=";";
		}
		IDinfo = IDinfo + Input[2];
		cout<<IDinfo;
		for(i=3; i < Input.size(); i = i+2)
		{
			WoodItem item(Input[i]);
			strcpy(buf, Input[i+1].c_str());
			sscanf(buf,"%d",&weight);
			//cout<<"------------------------"<<endl;
			//cout<<item.type<<" "<<item.price<<" "<<item.baseDeliveryTime<<" "<<weight<<endl;
			orderMake(item.type, item.price, item.baseDeliveryTime, weight);
		}     		 			 
	}
}

void orderMake(string wood, double price, double time, int weight)
{
	double totalprice;
	double totaltime = deliveryTime(weight,time);
	totalprice = price * weight;
	cout<< wood << ":";
	cout<<weight<<"BF "<<price<<"dollars/BF "<< totaltime << "hours "<<totalprice<<"dollars "<<endl;
}

/*
 * Method to compute the deliveryTime
 */
double deliveryTime(int weight,double base) {
	double dTime;
	if(weight >=1 && weight <=100)
		dTime = base;
	else if(weight >= 101&&weight <= 200)
		dTime = 2*base;
	else if(weight >= 201 && weight <= 300)
		dTime = 3*base;
	else if(weight >= 301 && weight <= 400)
		dTime = 4*base;
	else if(weight >= 401 && weight <= 500)
		dTime = 5*base;
	else if(weight >= 501 && weight <= 1000)
		dTime = 5.5*base;
	else if(weight < 1)
	{
		cerr<<"please check the amount of wood: too few." << endl;
	    exit(1);
	}  
	else
	{
		cerr<<"please check the amount of wood: too much." << endl;
	    exit(1);
	}
	return dTime;
}


