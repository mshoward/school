#ifndef INCLUDES
#define INCLUDES
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>


//don't touch the order of these
/* when I implement the mysql client, I might end up having
 * to bring in the whole library and include them here in a sub-directory
 * to make things easier on myself
 **/
 
//includes headers first

#include "includes/parser-sqli.hpp"
#include "includes/honeyd_parser.hpp"
#include "includes/honeyD_log.hpp"
#include "includes/parser.hpp"

//classes definitions after

#include "classes/honeyd_parser.cpp"
#include "classes/honeyD_log.cpp"






#endif
