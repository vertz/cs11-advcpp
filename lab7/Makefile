CC	     =  gcc
CXX          =  g++

CFLAGS       = -Wall -g
CXXFLAGS     = -Wall -Wnon-virtual-dtor -g
CXXFLAGS    += -std=c++0x

# flags for boost
BOOST_INC       = boost
CXXFLAGS       += -I $(BOOST_INC)

# Src files for the raytracer
RAYTRACER_CXXSRCS  = rt.cc
RAYTRACER_CXXSRCS += Vector3F.cc Color.cc
RAYTRACER_CXXSRCS += PlaneObject.cc SphereObject.cc CylinderObject.cc
RAYTRACER_CXXSRCS += Scene.cc Camera.cc Ray.cc Light.cc
RAYTRACER_OBJS     = $(RAYTRACER_CXXSRCS:.cc=.o);

### Build rules for programs
rt              : $(RAYTRACER_OBJS)
	            $(CXX) -o $@ $^ $(LDFLAGS)

# C compilation implicit rule 
%.o             : %.c 
	            $(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

# C++ compilation implicit rule
%.o             : %.cc
	            $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

#tell make that "clean" is not a file name!
.PHONY: clean

#Clean the build directory
clean: 
	rm -f *.o *~
 

