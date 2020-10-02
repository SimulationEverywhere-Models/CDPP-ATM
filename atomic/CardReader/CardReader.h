/*******************************************************************
*
*  DESCRIPTION: Atomic Model Card Reader
*
*  AUTHOR: Hesham Saadawi
*
*  EMAIL: hsaadawi@scs.carleton.ca
*
*
*  DATE: 18/10/2002
*
*******************************************************************/
#ifndef __CARDREADER_H
#define __CARDREADER_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
class Distribution ;

/** declarations **/
class CardReader: public Atomic
{
public:
	CardReader( const string &name = "CardReader" ) ;	 // Default constructor

	~CardReader();					// Destructor

	virtual string className() const
		{return "CardReader";}

protected:
	Model &initFunction()
		{   card_no_stored = card_entered = eject_requested  = 0;
            empty_reader = true;
                      return *this;}

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &card_in ;
    const Port &eject ;
	Port &card_out ;
    Port & cardno_out;
    int   card_no_stored, card_entered, eject_requested;
    bool empty_reader;
	Distribution *dist ;

    double randnumber;

	Distribution &distribution()
			{return *dist;}
};	// class CardReader


#endif    //__CARDREADER_H
