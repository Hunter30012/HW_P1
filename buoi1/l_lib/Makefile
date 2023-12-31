
CUR_DIR := .
INC_DIR := $(CUR_DIR)/inc
BIN_DIR := $(CUR_DIR)/bin
LIB_DIR := $(CUR_DIR)/lib
OBJ_DIR := $(CUR_DIR)/obj
SCR_DIR := $(CUR_DIR)/src
LIB_SHARED_DRI := $(LIB_DIR)/shared
LIB_STATIC_DRI := $(LIB_DIR)/static

LIB_NAME := math

create_obj:
	gcc -c -fPIC $(SCR_DIR)/math.c -o $(OBJ_DIR)/math.o -I $(INC_DIR)
	gcc -c -fPIC $(SCR_DIR)/version.c -o $(OBJ_DIR)/version.o -I $(INC_DIR)
	gcc -c -fPIC $(CUR_DIR)/main.c -o $(OBJ_DIR)/main.o -I $(INC_DIR)

create_sharedlib:
	gcc -shared $(OBJ_DIR)/math.o $(OBJ_DIR)/version.o -o $(LIB_SHARED_DRI)/lib$(LIB_NAME).so

create_staticlib:
	ar rcs $(LIB_STATIC_DRI)/lib$(LIB_NAME).a $(OBJ_DIR)/math.o $(OBJ_DIR)/version.o

install_shared:
	cp -f $(LIB_SHARED_DRI)/lib$(LIB_NAME).so /usr/lib

install_static:
	cp -f $(LIB_STATIC_DRI)/lib$(LIB_NAME).a /usr/lib

linking_sharedlib:
	gcc $(OBJ_DIR)/main.o -L$(LIB_SHARED_DRI) -l$(LIB_NAME) -o $(BIN_DIR)/use-shared-library

linking_staticlib:
	gcc $(OBJ_DIR)/main.o -L$(LIB_STATIC_DRI) -l$(LIB_NAME) -o $(BIN_DIR)/statically-linked

all_shared: create_obj create_sharedlib install_shared linking_sharedlib

all_static: create_obj create_staticlib install_static linking_staticlib

clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(LIB_SHARED_DRI)/*.so
	rm -rf $(BIN_DIR)/*
	rm -rf $(LIB_STATIC_DRI)/*.a