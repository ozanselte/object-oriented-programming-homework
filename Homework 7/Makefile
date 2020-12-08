JC = javac
JFLAGS = -classpath .
JD = javadoc
JDFLAGS = -protected -splitindex -use -author -version -d ./javadoc
RM = rm

all : Main.class

%.class : %.java
	$(JC) $(JFLAGS) $<

doc:
	$(JD) $(JDFLAGS) *.java com/ozanselte/*.java

clean:
	$(RM) *.class com/ozanselte/*.class

cleandoc:
	$(RM) -r ./javadoc