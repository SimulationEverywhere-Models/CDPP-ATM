/*******************************************************************
*
*  DESCRIPTION: Atomic Model Card Reader
*
*  AUTHOR: AUTHOR: Hesham Saadawi
*
*  EMAIL: mailto://hsaadawi@scs.carleton.ca
*
*
*  DATE: 18/10/2002
*
*******************************************************************/

/** include files **/
#include <math.h>            // fabs( ... )
#include <stdlib.h>
#include "randlib.h"         // Random numbers library
#include "CardReader.h"      // base header
#include "message.h"         // InternalMessage ....
#include "distri.h"          // class Distribution
#include "mainsimu.h"        // class MainSimulator
#include "strutil.h"         // str2float( ... )

/*******************************************************************
* Function Name: CardReader
* Description: constructor
********************************************************************/
CardReader::CardReader( const string &name )
: Atomic( name )
, card_in( addInputPort( "card_in" ) )
, eject( addInputPort( "eject" ) )
, card_out( addOutputPort( "card_out" ) )
, cardno_out( addOutputPort( "cardno_out" ) )
{
	try
	{
		dist = Distribution::create( MainSimulator::Instance().getParameter( description(), "distribution" ) );

		MASSERT( dist );

		for ( register int i = 0 ; i < dist->varCount() ; i++ )
		{
			string parameter( MainSimulator::Instance().getParameter( description(), dist->getVar(i) ) ) ;
			dist->setVar( i, str2float( parameter ) ) ;
		}
	} catch( InvalidDistribution &e )
	{
		e.addText( "The model " + description() + " has distribution problems!" ) ;
		e.print(cerr);
		MTHROW( e ) ;
	} catch( MException &e )
	{
		MTHROW( e ) ;
	}
}

/*******************************************************************
* Function Name: externalFunction
* Description: the CardReader receives the Card , or Eject request
********************************************************************/
Model &CardReader::externalFunction( const ExternalMessage &msg )
{
  if ( this->state() == passive )
  {
    if (msg.port() == card_in && empty_reader )
     {
       card_entered = 1;
       eject_requested = 0;
       // get a random number of 3 digits to be our card number
        randnumber =  ((double)rand()/(double)RAND_MAX ) * 1000;
        holdIn( active, Time( static_cast<float>( fabs( distribution().get() ) ) ) ) ;
     }
    if (msg.port() == eject && !empty_reader )
     {
       eject_requested = 1;
       card_entered = 0;
       holdIn( active, Time( static_cast<float>( fabs( distribution().get() ) ) ) ) ;
     }
  }
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &CardReader::internalFunction( const InternalMessage & )
{
    if (card_entered == 1)
    {
        empty_reader = false ;
    }
    else
      if ( eject_requested == 1)
         {
         empty_reader = true;
         }
    passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &CardReader::outputFunction( const InternalMessage &msg )
{

      if ( card_entered == 1 )
        {
         card_no_stored = (int) randnumber;
         sendOutput( msg.time(), cardno_out, card_no_stored );
        }
      else
          // Eject card has been requested
        {
         sendOutput( msg.time(), card_out , 1 );
         }
	return *this;
}

CardReader::~CardReader()
{
	delete dist;
}
