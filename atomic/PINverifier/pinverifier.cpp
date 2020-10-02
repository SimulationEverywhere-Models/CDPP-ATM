/*******************************************************************
*
*  DESCRIPTION: Atomic Model PIN Verifier
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
#include <stdlib.h>           // for rand function.
#include "PINverifier.h"     // base header
#include "message.h"        // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

/*******************************************************************
* Function Name: Balanceverifier
* Description: constructor
********************************************************************/
PINverifier::PINverifier( const string &name )
: Atomic( name )
, pin_in( addInputPort( "pin_in" ) )
, get_pin( addOutputPort( "get_pin" ) )
, get_amnt( addOutputPort( "get_amnt" ) )
, eject( addOutputPort( "eject" ) )
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
* Description: the PINverifier receives the Amount
********************************************************************/
Model &PINverifier::externalFunction( const ExternalMessage &msg )
{
   if ( this->state() == passive)
   {
	holdIn( active, Time( static_cast<float>( fabs( distribution().get() ) ) ) ) ;
    pin = (int) msg.value();
    // According to CD++ manual, random() fn should return a number
    // between 0 and 1. But this doesn't happen and it returns a number
    // of 10 digits.
    //randnumber = random()/1e+10;

    randnumber = (double)rand()/(double)RAND_MAX;
    if ( randnumber <= 0.9)
       {
        PIN_OK = 1;
        no_of_trials = 0;   //Once I get PIN OK, I delete history
       }
    else
        {
        PIN_OK = 0;
        no_of_trials = no_of_trials + 1;
        }
    // assume the PIN is always OK for testing puposes
    //PIN_OK = 0;
   }

	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &PINverifier::internalFunction( const InternalMessage & )
{
      if ( PIN_OK == 0 && no_of_trials >= 3)
         // Reset no_of_trials as card has been ejected
         {
             no_of_trials = 0;
         }

	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &PINverifier::outputFunction( const InternalMessage &msg )
{

      if ( PIN_OK == 1)
         sendOutput( msg.time(), get_amnt, 1 );
      else
        if ( no_of_trials < 3)
         //ask to repeat PIN entry
        {
         //sendOutput( msg.time(), get_amnt, randnumber );   // for testing only
          sendOutput( msg.time(), get_pin, 1 );
         }
        else
          // exceeded 3 trials, then eject the card
          {
            sendOutput( msg.time(), eject, 1 );
          }
	return *this;
}

PINverifier::~PINverifier()
{
	delete dist;
}
