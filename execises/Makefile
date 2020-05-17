cc = g++
out = remove_intervals 
src := ${out:=.cpp}
run:
	$(cc) $(src) -o $(out) -std=c++11 
	./$(out)
profile: 
	$(cc) $(src) -o $(out) -lprofiler -std=c++11 -L /home/xuyou/gperftools/build/lib
	CPUPROFILE=profile ./$(out)
	pprof --text $(out) profile 
clean:
	rm profile
