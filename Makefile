
SRC = src
INC = include
OBJ = obj
BIN = bin

CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c -Werror

all: $(BIN)/buscar_Wally $(BIN)/filtrar 
#$(BIN)/ocultar $(BIN)/revelar

# ************ Generación de documentación ******************
#documentacion:
#	doxygen doc/doxys/Doxyfile
	
# ************ Compilación de ejecutables ************
$(BIN)/revelar: $(OBJ)/imagenES.o $(OBJ)/procesar.o $(OBJ)/revelar.o $(OBJ)/imagen.o 
	$(CXX) $(OBJ)/imagenES.o $(OBJ)/procesar.o $(OBJ)/revelar.o $(OBJ)/imagen.o -o $(BIN)/revelar

$(BIN)/ocultar: $(OBJ)/imagenES.o $(OBJ)/procesar.o $(OBJ)/ocultar.o $(OBJ)/imagen.o 
	$(CXX) $(OBJ)/imagenES.o $(OBJ)/procesar.o $(OBJ)/ocultar.o $(OBJ)/imagen.o -o $(BIN)/ocultar

$(BIN)/filtrar: $(OBJ)/imagen.o $(OBJ)/signal.o $(OBJ)/conversiones.o $(OBJ)/correlacion.o $(OBJ)/filtrar.o $(OBJ)/imagenES.o
	$(CXX) $^ -o $(BIN)/filtrar

$(BIN)/buscar_Wally: $(OBJ)/imagen.o $(OBJ)/signal.o $(OBJ)/conversiones.o $(OBJ)/correlacion.o $(OBJ)/buscar_Wally.o $(OBJ)/imagenES.o $(OBJ)/procesar.o
	$(CXX) $^ -o $(BIN)/buscar_Wally


# ************ Compilación de módulos ************
$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

$(OBJ)/signal.o: $(SRC)/signal.cpp $(INC)/signal.h
	$(CXX) $(CPPFLAGS) $(SRC)/signal.cpp -o $(OBJ)/signal.o

$(OBJ)/procesar.o: $(SRC)/procesar.cpp $(INC)/procesar.h
	$(CXX) $(CPPFLAGS) $(SRC)/procesar.cpp -o $(OBJ)/procesar.o

$(OBJ)/conversiones.o: $(SRC)/conversiones.cpp $(INC)/conversiones.h
	$(CXX) $(CPPFLAGS) $(SRC)/conversiones.cpp -o $(OBJ)/conversiones.o

$(OBJ)/correlacion.o: $(SRC)/correlacion.cpp $(INC)/correlacion.h
	$(CXX) $(CPPFLAGS) $(SRC)/correlacion.cpp -o $(OBJ)/correlacion.o

$(OBJ)/revelar.o: $(SRC)/revelar.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/revelar.cpp -o $(OBJ)/revelar.o

$(OBJ)/ocultar.o: $(SRC)/ocultar.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/ocultar.cpp -o $(OBJ)/ocultar.o

$(OBJ)/filtrar.o: $(SRC)/filtrar.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/filtrar.cpp -o $(OBJ)/filtrar.o

$(OBJ)/buscar_Wally.o: $(SRC)/buscar_Wally.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/buscar_Wally.cpp -o $(OBJ)/buscar_Wally.o

# ************ Limpieza ************
clean:
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper: clean
	-rm $(BIN)/* doc/html/*
