SOURCE_DIR=com/craftinginterpreters/lox
PATH_TARGET=$(SOURCE_DIR)/Lox.java
TOOLS_PATH=com/craftinginterpreters/tool
TARGET=com.craftinginterpreters.lox.Lox

compile: $(PATH_TARGET); javac $(PATH_TARGET)

clean: ; rm -f com/craftinginterpreters/*/*.class

test: ; java $(TARGET)

ctest: compile test

full: clean ctest

OUTDIR=$(SOURCE_DIR)

tools:
	javac $(TOOLS_PATH)/GenerateAst.java
	java $(TOOLS_PATH)/GenerateAst $(OUTDIR)

MODULE=AstPrinter

ctest_apart:
	$(MAKE) clean
	javac $(SOURCE_DIR)/$(MODULE).java
	java $(SOURCE_DIR)/$(MODULE)

.PHONY: clean test compile ctest full tools ctest_apart