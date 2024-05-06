# copiado de https://github.com/brunomaletta/Biblioteca/blob/master/Codigo/Extra/makefile
CXX = g++
CXXFLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer -g -Wall -Wshadow -std=c++17 -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts #-fuse-ld=gold

clean:
	rm -f a a2 a3 gen in out out2
