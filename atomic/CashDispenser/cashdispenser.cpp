/*******************************************************************
*
*  DESCRIPTION: Atomic Model Cash Dispenser
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
#include "cashdispenser.h"  // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

/*******************************************************************
* Function Name: Cashdispenser
* Description: constructor
********************************************************************/
Cashdispenser::Cashdispenser( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, out( addOutputPort( "out" ) )
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
* Description: the CPU receives one job
********************************************************************/
Model &Cashdispenser::externalFunction( const ExternalMessage &msg )
{
   if ( this->state() == passive)
    {
	holdIn( active, Time( static_cast<float>( fabs( distribution().get() ) ) ) ) ;
    amnt = msg.value();
    }
	return *this ;

}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Cashdispenser::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Cashdispenser::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), out, amnt );
	return *this;
}

Cashdispenser::~Cashdispenser()
{
	delete dist;
}
