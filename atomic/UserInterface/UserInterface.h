/*******************************************************************
*
*  DESCRIPTION: Atomic Model User Interface
*
*  AUTHOR: Hesham Saadawi
*
*  EMAIL: hsaadawi@scs.carleton.ca
*
*
*  DATE: 18/10/2002
*
*******************************************************************/
#ifndef __USERINTERFACE_H
#define __USERINTERFACE_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
class Distribution ;

/** declarations **/
class UserInterface: public Atomic
{
public:
	UserInterface( const string &name = "UserInterface" ) ;	 // Default constructor

	~UserInterface();					// Destructor

	virtual string className() const
		{return "UserInterface";}

protected:
	Model &initFunction()
		{   amnt = pin = amnt_entered = pin_entered = 0;
                      return *this;}

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &get_pin ;
    const Port &get_amnt ;
    const Port &cardno ;
	Port &amnt_out ;
    Port & pin_out;
    int   pin, pin_entered, amnt_entered, amnt;
	Distribution *dist ;

    double randnumber;

	Distribution &distribution()
			{return *dist;}
};	// class UserInterface


#endif    //__USERINTERFACE_H
