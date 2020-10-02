/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Amir Barylko & Jorge Beyoglonian 
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*
*  DATE: 27/6/1998
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "queue.h"                // class Queue
#include "generat.h"             // class Generator
#include "cpu.h"                 // class CPU
#include "Cashdispenser.h"        // class Cashdispenser
#include "Balanceverifier.h"        // class Balanceverifier
#include "pinverifier.h"        // class PINverifier
#include "UserInterface.h"        // class UserInterface
#include "transduc.h"             // class Transducer
#include "trafico.h"              // class Trafico


void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Queue>() , "Queue" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Generator>() , "Generator" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CPU>() , "CPU" ) ;
    SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Cashdispenser>() , "Cashdispenser" ) ;
    SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Balanceverifier>() , "Balanceverifier" ) ;
    SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<PINverifier>() , "PINverifier" ) ;
    SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<UserInterface>() , "UserInterface" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Transducer>() , "Transducer" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Trafico>() , "Trafico" ) ;
}
