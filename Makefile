GCC = g++
CFLAGS = -Wall -Werror -Wextra -pedantic

all: exam3d exam5

exam3d: exam3d.cpp     
	$(GCC) $(CFLAGS) -o exam3d exam3d.cpp

exam5: exam5.cpp
	$(GCC) $(CLFAGS) -o exam5 exam5.cpp

