TARGET = geometry

#------------------------------------------------
# Version	                                                                     
#------------------------------------------------
LIB_MAJOR = 1
LIB_MINOR = 0

#------------------------------------------------
# Debug code generation 	                                                                     
#------------------------------------------------
DEBUG = 1

#------------------------------------------------
# absolute or relative path to project root directory                                                                    
#------------------------------------------------
PRJ_DIR	= .

#------------------------------------------------
# Object directory                                                           
#------------------------------------------------
OBJ_DIR	= $(PRJ_DIR)/objs

######## !!!!!!!! Remove 

JAVA_HOME = /Library/Java/JavaVirtualMachines/jdk1.8.0_202.jdk/Contents/Home

ifeq ($(JAVA_HOME),)
	ERR := $(error Not found path to JDK. Please check JAVA_HOME)
endif

#------------------------------------------------
# Debug flags                                                    
#------------------------------------------------
ifeq ($(DEBUG), 1)
	GDB_FLAG = -g3 -ggdb3 -O0
	OPTIMIZE = -O0
else
	GDB_FLAG = 
	OPTIMIZE = 
endif

#------------------------------------------------
# Detect the OS                                                       
#------------------------------------------------
ifeq ($(OS),Windows_NT)
    CCFLAGS += -D WIN32
    ifeq ($(PROCESSOR_ARCHITEW6432),AMD64)
        CCFLAGS += -D AMD64
		  LFLAGS += -shared -Wl,--out-implib,$(LIBNAME)$(LIB_MAJOR).$(LIB_MINOR).a
        LIBNAME  = lib$(TARGET).
        LIBSUFF = .dll 
    else
        ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
            CCFLAGS += -D AMD64
        endif
        ifeq ($(PROCESSOR_ARCHITECTURE),x86)
            CCFLAGS += -D IA32
        endif
    endif
else
    UNAME_S := $(shell uname -s)
    UNAME_V := $(shell uname -v)
    ifeq ($(UNAME_S),Linux)
        CFLAGS  += -D LINUX -D TARGET="$(UNAME_V)"
        INC_DIR += -I $(JAVA_HOME)/include -I $(JAVA_HOME)/include/linux
        LFLAGS  += -shared
        LIBNAME  = lib$(TARGET).so.
        LIBSUFF  = 
    endif
    ifeq ($(UNAME_S),Darwin)
        CFLAGS  += -D OSX -D TARGET="$(UNAME_V)"
        INC_DIR += -I $(JAVA_HOME)/include -I $(JAVA_HOME)/include/darwin
        LFLAGS  += -single_module -dynamiclib -undefined dynamic_lookup
        LIBNAME  = lib$(TARGET).
        LIBSUFF  = .dylib
    endif
    UNAME_P := $(shell uname -p)
    ifeq ($(UNAME_P),x86_64)
        CCFLAGS += -D AMD64
    endif
    ifneq ($(filter %86,$(UNAME_P)),)
        CCFLAGS += -D IA32
    endif
    ifneq ($(filter arm%,$(UNAME_P)),)
        CCFLAGS += -D ARM
    endif
endif

#------------------------------------------------
# Compiler settings                                                 
#------------------------------------------------
CC	=	$(CROSS)gcc

#------------------------------------------------
# Include directory for header files   
# INC_DIR  += -I $(PRJ_DIR)/common                                                  
#------------------------------------------------
INC_DIR  += -I .

#------------------------------------------------
# Warning level                                                
#------------------------------------------------
WARN  = -Wall
WARN += -Wextra 
WARN += -std=c99

#------------------------------------------------
# Compiler flags                                              
#------------------------------------------------
CFLAGS	+= $(GDB_FLAG) $(OPTIMIZE) $(WARN) $(INC_DIR)
CFLAGS  += -fPIC -c 

#------------------------------------------------
# Linker flags                                              
#------------------------------------------------
LFLAGS  +=  

#------------------------------------------------
# COM source files                                             
#------------------------------------------------
COM_SRC	= com_units_geometry_Geometry.c \
geometry.c

#------------------------------------------------
# generate list of all required object files                                     
#------------------------------------------------
TARGET_OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o, $(COM_SRC))

#------------------------------------------------
# Rules                                         
#------------------------------------------------

all: compiling $(TARGET_OBJS)
	@echo - Linking $(LIBNAME)$(LIB_MAJOR).$(LIB_MINOR)$(LIBSUFF)
	@$(CC) $(LFLAGS) -o ./$(LIBNAME)$(LIB_MAJOR).$(LIB_MINOR)$(LIBSUFF) $(TARGET_OBJS)
    
show:
	@echo JAVA_HOME: 
	@echo $(JAVA_HOME) 
	@echo TARGET_OBJS:
	@echo $(TARGET_OBJS)
	@echo INC_DIR:
	@echo $(INC_DIR) 
   
compiling:
	@echo Build Target: $(TARGET) 

install:
	@ if [[ $EUID -ne 0 ]]; then \
	echo "Must be run as root"; \
	exit 1; \
	fi
	
	cp -p $(LIBNAME)* /usr/local/lib
	
clean:
	@rm -f lib$(TARGET)*.*
	@rm -f $(OBJ_DIR)/*.d 
	@rm -f $(OBJ_DIR)/*.o 
	@rm -f $(OBJ_DIR)/*.elf

$(OBJ_DIR)/%.o : %.c
	@echo - Compiling : $(<F)
	@$(CC) $(CFLAGS) $< -o $@ -MMD
