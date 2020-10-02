/*******************************************************************
*
*  DESCRIPTION: Atomic Model Balance Verifier
*
*  AUTHOR: Hesham Saadawi
*
*  EMAIL: hsaadawi@scs.carleton.ca
*
*
*  DATE: 18/10/2002
*
*******************************************************************/
#ifndef __BALANCEVERIFIER_H
#define __BALANCEVERIFIER_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
class Distribution ;

/** declarations **/
class Balanceverifier: public Atomic
{
public:
	Balanceverifier( const string &name = "Balanceverifier" ) ;	 // Default constructor

	~Balanceverifier();					// Destructor

	virtual string className() const
		{return "Balanceverifier";}

protected:
	Model &initFunction()
		{    balance_OK = 0;
                      return *this;}

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &amnt_in ;
	Port &amnt_out ;
    Port & get_amnt_out;
    int   balance_OK;
	Distribution *dist ;
    double amnt;
    double randnumber;

	Distribution &distribution()
			{return *dist;}
};	// class Balanceverifier


#endif    //__BALANCEVERIFIER_H
