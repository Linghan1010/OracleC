/*
 * WoodItem.h
 *
 *  Created on: Aug 24, 2015
 *      Author: Esteban
 *  Editor: Linghan Zhang
 */


#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#ifndef WOODITEM_H_
#define WOODITEM_H_

class WoodItem {

public:

	std::string type;
	double baseDeliveryTime;
	double price;

	// Member functions declaration
	WoodItem();
	WoodItem(std::string woodType);
};
#include "WoodItem.h"
#include <iostream>
#include <sstream>

using namespace std;
/*
 * Empty constructor
 */
WoodItem::WoodItem(){
	type = "";
	baseDeliveryTime = 0.0;
	price = 0.0;
}

/*
 * Method to initialize a tic tac toe game
 * Initializes board and turn
 */
WoodItem::WoodItem(std::string woodType) {
	type = woodType;
	if(type == "Cherry")
	{
		baseDeliveryTime = 2.5;
        price = 5.95;		
	}
	else if(type == "Curly Maple")
	{
		baseDeliveryTime = 1.5;
		price = 6.00;
	}
	else if(type == "Genuine Mahogany")
	{
		baseDeliveryTime = 3;
		price = 9.60;
	}
	else if(type == "Wenge")
	{
		baseDeliveryTime = 5;
		price = 22.35;
	}
	else if(type == "White Oak")
	{
		baseDeliveryTime = 2.3;
		price = 6.70;
	}
	else if(type == "Sawdust")
	{
		baseDeliveryTime = 1;
		price = 1,5;
	}
	else
	{
		cerr<<"Fail to create this wooditem: we don't provide that kind of wood now, please check later." <<endl;
		exit(-1);
	}
}
#endif /* WOODITEM_H_ */
