TARGET=com.craftinginterpreters.Lox
PATH_TARGET=com/craftinginterpreters/lox/Lox.java

compile:
	javac $(TARGET).java

clean:
	rm -f com/craftinginterpreters/lox/*.class

test:
	java $(TARGET)

ctest: compile test

full: clean ctest