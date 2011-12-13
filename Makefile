all: binomdist

test: binomdist
	./$<

binomdist: main.cc
	$(CXX) -o $@ $<

clean:
	$(RM) *~

distclean: clean
	$(RM) binomdist
