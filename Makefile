
SRC = src
INC = include
OBJ = obj

CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/signal.o

# ************ Generación de documentación ******************
#documentacion:
#	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

$(OBJ)/signal.o: $(SRC)/signal.cpp $(INC)/signal.h
	$(CXX) $(CPPFLAGS) $(SRC)/signal.cpp -o $(OBJ)/signal.o

# ************ Limpieza ************
clean:
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper: clean
	-rm $(BIN)/* doc/html/*
