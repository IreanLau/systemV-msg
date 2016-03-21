#.a是静态库  ar静态库打包  r? v?  c创建 

libmy_function.a:my_function.o
	ar -rc $@ $^
my_function.o:my_function.c
	gcc -c my_function.c
.PHONY:clean
clean:
	rm -rf libmy_function.a *.o lib

.PHONY:output
output:
	mkdir -p lib
	cp libmy_function.a lib
	cp my_function.h lib
