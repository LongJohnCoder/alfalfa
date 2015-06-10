#ifndef RASTER_POOL_HH
#define RASTER_POOL_HH

#include "raster.hh"

class RasterPool;

class RasterHandle
{
private:
  std::shared_ptr< Raster > raster_;

public:
  RasterHandle( MutableRasterHandle && raster );

  operator const Raster & () const { return *raster_; }

  const Raster & get( void ) const { return *raster_; }
};

class MutableRasterHandle
{
private:
  std::unique_ptr< Raster > raster_;

public:
  MutableRasterHandle( const unsigned int display_width, const unsigned int display_height );

  MutableRasterHandle( const unsigned int display_width, const unsigned int display_height, RasterPool & raster_pool );

  operator const Raster & () const { return *raster_; }
  operator Raster & () { return *raster_; }

  const Raster & get( void ) const { return *raster_; }
  Raster & get( void ) { return *raster_; }
};

#endif /* RASTER_POOL_HH */
