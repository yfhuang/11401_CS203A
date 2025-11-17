# Compilers
CC      := gcc
CXX     := g++

# Flags (adjust as you like)
CFLAGS   := -std=c23 -Wall -Wextra -Wpedantic -g
CXXFLAGS := -std=c++23 -Wall -Wextra -Wpedantic -g

# ==== C version ====
C_SRCS := C/main.c C/hash_fn.c
C_OBJS := $(C_SRCS:.c=.o)
C_BIN  := C/hash_function

# ==== C++ version ====
CXX_SRCS := CXX/main.cpp CXX/hash_fn.cpp
CXX_OBJS := $(CXX_SRCS:.cpp=.o)
CXX_BIN  := CXX/hash_function_cpp

# Default target: build both
all: $(C_BIN) $(CXX_BIN)

# Build C executable
$(C_BIN): $(C_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Build C++ executable
$(CXX_BIN): $(CXX_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Object file rules (C)
C/%.o: C/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Object file rules (C++)
CXX/%.o: CXX/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Convenience targets
c: $(C_BIN)
cxx: $(CXX_BIN)

clean:
	$(RM) $(C_OBJS) $(CXX_OBJS) $(C_BIN) $(CXX_BIN)

.PHONY: all clean c cxx
