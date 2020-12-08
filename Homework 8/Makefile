JC = javac
JFLAGS = -classpath .
JD = javadoc
JDFLAGS = -protected -splitindex -use -author -version -d ./javadoc
RM = rm

CLASSES = \
		Main.java \
		Collection.java \
		Set.java \
		List.java \
		Queue.java \
		HashSet.java \
		ArrayList.java \
		LinkedList.java

all : Main.class

classes : $(CLASSES:.java=.class)

%.class : %.java
	$(JC) $(JFLAGS) $<

doc:
	$(JD) $(JDFLAGS) *.java com/ozanselte/*.java

clean:
	$(RM) *.class com/ozanselte/*.class

cleandoc:
	$(RM) -r ./javadoc