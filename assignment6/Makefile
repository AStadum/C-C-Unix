CXX = g++

CXXFLAGS = -g -std=c++11 
# Uncomment the CXXFLAGS definition below to use the parallel MR runtime
#CXXFLAGS = -g -std=c++11 -pthread -Wl,--no-as-needed -DPARALLEL_MR

all: test-wordCount test-sentenceStats test-phrases

%.o : %.cpp
	$(CXX) -c $< $(CXXFLAGS) 

WC_OBJECTS = test-wordCount.o wordCount.o ioutils.o	
test-wordCount: $(WC_OBJECTS)
	$(CXX) -o $@ $(WC_OBJECTS) $(CXXFLAGS) $(LDFLAGS)
	
AVG_OBJECTS = test-wordAvgSize.o wordAvgSize.o ioutils.o
test-wordAvgSize: $(AVG_OBJECTS)
	$(CXX) -o $@ $(AVG_OBJECTS) $(CXXFLAGS)

Sentence_OBJECTS = test-sentenceStats.o SentenceStats.o ioutils.o
test-sentenceStats: $(Sentence_OBJECTS)
	$(CXX) -o $@ $(Sentence_OBJECTS) $(CXXFLAGS)

Phrases_OBJECTS = test-phrases.o phrases.o ioutils.o
test-phrases: $(Phrases_OBJECTS)
	$(CXX) -o $@ $(Phrases_OBJECTS) $(CXXFLAGS)

clean:
	$(RM) *.o test-wordCount
