
Target = graphic

SRC = ./src/

Sources =	$(SRC)main.cpp \
		$(SRC)Random.cpp \
		$(SRC)Settings.cpp \
		$(SRC)Core.cpp \
		$(SRC)HudText.cpp \
		$(SRC)Image.cpp \
		$(SRC)MyEventReceiver.cpp \
		$(SRC)MainMenu.cpp \
		$(SRC)ErrorMenu.cpp \
		$(SRC)SettingsMenu.cpp \
		$(SRC)Zappy.cpp \
		$(SRC)ZappyCmd.cpp \
		$(SRC)Mesh.cpp \
		$(SRC)Map.cpp \
		$(SRC)AEntity.cpp \
		$(SRC)Egg.cpp \
		$(SRC)Resources.cpp \
		$(SRC)Camera.cpp \
		$(SRC)EntityManager.cpp \
		$(SRC)Player.cpp \
		$(SRC)Network.cpp \
		$(SRC)Box.cpp \

IRRLITCHT = ./irrlicht-1.8.4/

# general compiler settings
CPPFLAGS = -I$(IRRLITCHT)include -I/usr/X11R6/include -I./include/
CXXFLAGS = -O3 -ffast-math -g -std=c++11
CXXFLAGS += -pthread
#CXXFLAGS = -g -Wall

#default target is Linux
all: all_linux

ifeq ($(HOSTTYPE), x86_64)
LIBSELECT=64
endif

# target specific settings
all_linux: LDFLAGS = -L/usr/X11R6/lib$(LIBSELECT) -L$(IRRLITCHT)lib/Linux -lIrrlicht -lGL -lXxf86vm -lXext -lX11 -lXcursor -lsfml-audio
all_linux clean_linux: SYSTEM=Linux
all_win32: LDFLAGS = -L$(IRRLITCHT)lib/Win32-gcc -lIrrlicht
static_win32: LDFLAGS += -lgdi32 -lopengl32 -ld3dx9d -lwinmm -lm -lsfml-audio
static_win32: CPPFLAGS += -D_IRR_STATIC_LIB_
static_win32 all_win32 clean_win32: SYSTEM=Win32-gcc
static_win32 all_win32 clean_win32: SUF=.exe
# name of the binary - only valid for targets which set SYSTEM
DESTPATH = $(Target)$(SUF)

all_linux all_win32 static_win32:
	$(warning Building...)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(Sources) -o $(DESTPATH) $(LDFLAGS)

clean: clean_linux clean_win32
	$(warning Cleaning...)

clean_linux clean_win32:
	@$(RM) $(DESTPATH)

re:	clean all

install:
	-sudo dnf install SFML-devel
	-sudo apt-get install libsfml-dev
	wget "http://downloads.sourceforge.net/irrlicht/irrlicht-1.8.4.zip"
	unzip "irrlicht-1.8.4.zip"
	make -C "irrlicht-1.8.4/source/Irrlicht/"
	-rm -f "irrlicht-1.8.4.zip"
	echo "DONE: If successful run 'make'"

.PHONY: all all_win32 clean clean_linux clean_win32 static_win32 re install
