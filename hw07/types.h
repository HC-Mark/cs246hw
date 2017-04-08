/* types.h

   Declares concrete movie and cast_member types.
*/

#ifndef TYPES_H_
#define TYPES_H_

#include "abstract_types.h"

#include "llist.h"
#include "array.h"

// the abstract_types.h file includes the typedefs, so we don't need to here.

struct cast_member {
  char* name;
  llist movies;
};

struct movie {
  char* name;
  array cast;
};

#endif
