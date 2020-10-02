/*******************************************************************
*
*  DESCRIPTION: Atomic Model Cash Dispenser
*
*  AUTHOR: Hesham Saadawi
*
*  EMAIL: hsaadawi@scs.carleton.ca
*
*
*  DATE: 18/10/2002
*
*******************************************************************/
#ifndef __CASHDISPENSER_H
#define __CASHDISPENSER_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
class Distribution ;

/** declarations **/
class Cashdispenser: public Atomic
{
public:
	Cashdispenser( const string &name = "Cashdispenser" ) ;	 // Default constructor

	~Cashdispenser();					// Destructor

	virtual string className() const
		{return "Cashdispenser";}

protected:
	Model &initFunction()
		{return *this;}

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &in ;
	Port &out ;
	Distribution *dist ;
    double amnt;

	Distribution &distribution()
			{return *dist;}
};	// class Cashdispenser


#endif    //__CASHDISPENSER_H
