all: bindist

test: bindist
	./$<

bindist: main.cc
	$(CXX) -o $@ $<

clean:
	$(RM) *~

distclean: clean
	$(RM) bindist
