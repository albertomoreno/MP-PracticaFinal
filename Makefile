
SRC = src
INC = include
OBJ = obj
BIN = bin

CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/revelar $(BIN)/ocultar $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/signal.o $(OBJ)/procesar.o

# ************ Generación de documentación ******************
#documentacion:
#	doxygen doc/doxys/Doxyfile
	
# ************ Compilación de ejecutables ************
$(BIN)/revelar: $(OBJ)/imagenES.o $(OBJ)/procesar.o $(OBJ)/revelar.o
	$(CXX) $(OBJ)/imagenES.o $(OBJ)/procesar.o $(OBJ)/revelar.o -o $(BIN)/revelar

$(BIN)/ocultar: $(OBJ)/imagenES.o $(OBJ)/procesar.o $(OBJ)/ocultar.o
	$(CXX) $(OBJ)/imagenES.o $(OBJ)/procesar.o $(OBJ)/ocultar.o -o $(BIN)/ocultar

# ************ Compilación de módulos ************
$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

$(OBJ)/signal.o: $(SRC)/signal.cpp $(INC)/signal.h
	$(CXX) $(CPPFLAGS) $(SRC)/signal.cpp -o $(OBJ)/signal.o

$(OBJ)/procesar.o: $(SRC)/procesar.cpp $(INC)/procesar.h
	$(CXX) $(CPPFLAGS) $(SRC)/procesar.cpp -o $(OBJ)/procesar.o

$(OBJ)/revelar.o: $(SRC)/revelar.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/revelar.cpp -o $(OBJ)/revelar.o

$(OBJ)/ocultar.o: $(SRC)/ocultar.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/ocultar.cpp -o $(OBJ)/ocultar.o

# ************ Limpieza ************
clean:
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper: clean
	-rm $(BIN)/* doc/html/*
