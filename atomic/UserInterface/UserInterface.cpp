/*******************************************************************
*
*  DESCRIPTION: Atomic Model User Interface
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
#include "UserInterface.h"  // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

/*******************************************************************
* Function Name: Balanceverifier
* Description: constructor
********************************************************************/
UserInterface::UserInterface( const string &name )
: Atomic( name )
, get_pin( addInputPort( "get_pin" ) )
, get_amnt( addInputPort( "get_amnt" ) )
, cardno( addInputPort( "cardno" ) )
, amnt_out( addOutputPort( "amnt_out" ) )
, pin_out( addOutputPort( "pin_out" ) )
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
* Description: the UserInterface receives the Get Amount, or Get PIN request
********************************************************************/
Model &UserInterface::externalFunction( const ExternalMessage &msg )
{
  if ( this->state() == passive)
  {
    if (msg.port() == get_pin || msg.port() == cardno )
     {
       pin_entered = 1;
       amnt_entered = 0;
     }
    if (msg.port() == get_amnt )
     {
       amnt_entered = 1;
       pin_entered = 0;
     }
	holdIn( active, Time( static_cast<float>( fabs( distribution().get() ) ) ) ) ;
    // get a random number of 3 digits to be our simple PIN or amount entered
    randnumber =  ((double)rand()/(double)RAND_MAX ) * 1000;
  }
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &UserInterface::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &UserInterface::outputFunction( const InternalMessage &msg )
{

      if ( pin_entered == 1 )
        {
         pin = (int) randnumber;
         sendOutput( msg.time(), pin_out, pin );
        }
      else
        {
         amnt = (int) randnumber;
         sendOutput( msg.time(), amnt_out , amnt );
         }
	return *this;
}

UserInterface::~UserInterface()
{
	delete dist;
}
