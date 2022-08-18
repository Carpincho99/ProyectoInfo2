#variables
#EJECUTABLE := $(notdir $(shell pwd))
EJECUTABLE := main

SRC_PATH := src
INC_PATH := inc
OUT_PATH := build
#OBJ_PATH := $(OUT_PATH)/obj
OBJ_PATH := build

#indicamos los directorios de busqueda de sources
# https://www.gnu.org/software/make/manual/html_node/General-Search.html
# https://www.gnu.org/software/make/manual/html_node/Selective-Search.html#Selective-Search
vpath %.c $(SRC_PATH)
vpath %.o $(OBJ_PATH)

SOURCES := $(wildcard $(SRC_PATH)/*.c)
OBJS := $(subst $(SRC_PATH),$(OBJ_PATH),$(SOURCES:.c=.o))
OBJ_FILES := $(notdir $(OBJS))

#regla de compilacion
%.o: %.c
	gcc -Wall -c $< -o $(OBJ_PATH)/$@ -I $(INC_PATH)

#regla de linkeo
$(EJECUTABLE): $(OBJ_FILES)
	#gcc $(OBJS) -o $(OUT_PATH)/$(EJECUTABLE)
	gcc $(OBJS) -o $(EJECUTABLE)

#regla clean
clean:
	rm -f $(OBJS) $(OUT_PATH)/$(EJECUTABLE)
