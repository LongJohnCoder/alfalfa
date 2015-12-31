#include "filesystem.hh"
#include "exception.hh"

#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <memory>

using namespace std;

void FileSystem::create_directory( const string & path )
{
  SystemCall( "mkdir " + path,
	      mkdir( path.c_str(), S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH ) );
}

string FileSystem::append( const string & path1, const string & path2 )
{
  return path1 + "/" + path2;
}

string FileSystem::get_realpath( const string & path )
{
  char resolved_path[ PATH_MAX ];

  if ( realpath( path.c_str(), resolved_path ) == nullptr ) {
    throw unix_error( "realpath (" + path + ")" );
  }

  return resolved_path;
}
