
#include "zipios++/zipios-config.h"

#include "zipios++/meta-iostreams.h"
#include <vector>


#include "zipios++/simplesmartptr.h"

#include <cassert>

using namespace zipios ;

using std::cerr ;
using std::cout ;
using std::endl ;
using std::auto_ptr ;
using std::ofstream ;
using std::vector ;

/* We don't want Bogus in the doxygen generated class index :-) */
#ifndef DOXYGEN

class Bogus {
public:
  Bogus(bool &isAlive) : _isAlive(isAlive) {}
  ~Bogus() { _isAlive = false; }
protected:
  friend SimpleSmartPointer< Bogus > ;
  friend SimpleSmartPointer< const Bogus > ;

  void           ref() const { _refcount.ref() ;          }
  unsigned int unref() const { return _refcount.unref() ; }
  unsigned int getReferenceCount() const { return _refcount.getReferenceCount() ; }
  ReferenceCount< Bogus > _refcount ;
  bool &_isAlive;
};

typedef SimpleSmartPointer< Bogus > SPBogus ;

#endif

int main() {
  bool isAlive = true;
  {
    Bogus *p = new Bogus(isAlive);
    SPBogus sp1( p ) ;
    assert( sp1.getReferenceCount() == 1 );
    {
      SPBogus sp2 ;
      sp2 = sp1 ;
      assert( sp1.getReferenceCount() == 2 );
      { 
	SPBogus sp3 ;
	sp3 = p ;
	assert( sp1.getReferenceCount() == 3 );
      }
      assert( sp1.getReferenceCount() == 2 );
      assert( isAlive );
    }
    assert( sp1.getReferenceCount() == 1 );
    assert( isAlive );
  }
  assert( ! isAlive );
}
   

/** \file
    \anchor test_zip_anchor
    Source code to a small program that tests the functionality of Zipios++.
*/

/*
  Zipios++ - a small C++ library that provides easy access to .zip files.
  Copyright (C) 2000  Thomas S�ndergaard
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*/