/*******************************************************************
*
*  DESCRIPTION: Atomic Model PIN Verifier
*
*  AUTHOR: Hesham Saadawi
*
*  EMAIL: hsaadawi@scs.carleton.ca
*
*
*  DATE: 18/10/2002
*
*******************************************************************/
#ifndef __PINVERIFIER_H
#define __PINVERIFIER_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
class Distribution ;

/** declarations **/
class PINverifier: public Atomic
{
public:
	PINverifier( const string &name = "PINverifier" ) ;	 // Default constructor

	~PINverifier();					// Destructor

	virtual string className() const
		{return "PINverifier";}

protected:
	Model &initFunction()
		{    PIN_OK = 0;
             no_of_trials = 0;
                      return *this;}

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &pin_in ;
    Port & get_pin;
    Port &get_amnt ;
    Port & eject;
    int   PIN_OK;
	Distribution *dist ;
    int pin , no_of_trials;
    double randnumber;

	Distribution &distribution()
			{return *dist;}
};	// class PINverifier


#endif    //__PINVERIFIER_H
