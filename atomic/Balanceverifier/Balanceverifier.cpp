/*******************************************************************
*
*  DESCRIPTION: Atomic Model Balance Verifier
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
#include "Balanceverifier.h"  // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

/*******************************************************************
* Function Name: Balanceverifier
* Description: constructor
********************************************************************/
Balanceverifier::Balanceverifier( const string &name )
: Atomic( name )
, amnt_in( addInputPort( "amnt_in" ) )
, amnt_out( addOutputPort( "amnt_out" ) )
, get_amnt_out( addOutputPort( "get_amnt_out" ) )
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
* Description: the Balanceverifier receives the Amount
********************************************************************/
Model &Balanceverifier::externalFunction( const ExternalMessage &msg )
{
  if ( this->state() == passive)
   {
	holdIn( active, Time( static_cast<float>( fabs( distribution().get() ) ) ) ) ;
    amnt = msg.value();
    // According to CD++ manual, random() fn should return a number
    // between 0 and 1. But this doesn't happen and it returns a number
    // of 10 digits.
    //randnumber = random()/1e+10;

    randnumber = (double)rand()/(double)RAND_MAX;
    if ( randnumber <= 0.8)
        balance_OK = 1;
    else
        balance_OK = 0;

    // assume the balance is always OK for testing puposes
    //balance_OK = 0;
   }
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Balanceverifier::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Balanceverifier::outputFunction( const InternalMessage &msg )
{
      if ( balance_OK == 1 )
         sendOutput( msg.time(), amnt_out, amnt );
      else
        {
         // sendOutput( msg.time(), amnt_out, randnumber );   // for testing only
         sendOutput( msg.time(), get_amnt_out, 1 );
         }
	return *this;
}

Balanceverifier::~Balanceverifier()
{
	delete dist;
}
