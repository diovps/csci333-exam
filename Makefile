GCC = g++
CFLAGS = -Wall -Werror -Wextra -pedantic

all: exam3d exam5

exam3d: exam3d.cpp     
	$(GCC) $(CFLAGS) -o exam3d exam3d.cpp

exam5: exam5.cpp
	$(GCC) $(CFLAGS) -o exam5 exam5.cpp

clean:
	rm -f exam5
	rm -f exam3d
