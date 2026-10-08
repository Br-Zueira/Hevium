SOURCE_DIR=com/craftinginterpreters/lox
PATH_TARGET=$(SOURCE_DIR)/Lox.java
TOOLS_PATH=com/craftinginterpreters/tool
TARGET=com.craftinginterpreters.lox.Lox

compile:
	javac $(PATH_TARGET)

clean:
	rm -f com/craftinginterpreters/*/*.class

test:
	java $(TARGET)

ctest: compile test

full: clean ctest

OUTDIR=$(SOURCE_DIR)

tools:
	javac $(TOOLS_PATH)/GenerateAst.java
	java $(TOOLS_PATH)/GenerateAst $(OUTDIR)

.PHONY: clean test compile ctest full tools