CXX=g++
CXXFLAGS=-std=c++11 -I $(ANTLR_HOME)/include
LDFLAGS=-lantlr4-runtime -L $(ANTLR_HOME)/lib
DEPS=tinyrexxLexer.cpp tinyrexxParser.cpp
TDEPS=MyListener.h
OBJS=tinyrexxParser.o tinyrexxLexer.o
SCOBJS=syncheck.o
TOBJS=translate.o MyListener.o
ANTLRS=tinyrexxBaseListener.h \
        tinyrexxLexer.cpp \
        tinyrexxLexer.tokens \
        tinyrexxParser.cpp \
        tinyrexxLexer.h \
        tinyrexxListener.cpp \
        tinyrexxParser.h \
        tinyrexxBaseListener.cpp \
        tinyrexx.interp \
        tinyrexxLexer.interp \
        tinyrexxListener.h \
        tinyrexx.tokens

syncheck: $(SCOBJS) $(OBJS) $(DEPS)
	$(CXX) -o syncheck $(SCOBJS) $(OBJS) $(LDFLAGS)

translate: $(TOBJS) $(OBJS) $(TDEPS) $(DEPS) 
	$(CXX) -o translate $(TOBJS) $(OBJS) $(LDFLAGS)	

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(DEPS): tinyrexx.g4
	antlr4 -Dlanguage=Cpp tinyrexx.g4

clean:
	rm -f $(OBJS) $(TOBJS) $(SCOBJS) syncheck translate $(ANTLRS)

