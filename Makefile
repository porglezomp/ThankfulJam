SYS=$(shell uname)
APP=Thankful.exe
OBJS=main.o Player.o vec2.o Laser.o Util.o menu.o draw.o
ifneq (, $(findstring Darwin, $(SYS)))
SDLLIBS=$(shell sdl-config --static-libs)
SDLFLAGS=$(shell sdl-config --cflags)
else
SDLLIBS=-lmingw32 -lSDLmain -lSDL -lopengl32
endif

all: $(APP)

$(APP) : $(OBJS)
	g++ -o $(APP) $(OBJS) $(SDLLIBS) $(SDLFLAGS)

%.o : %.cpp
	g++ $< -c

clean:
	rm *.o
	rm $(APP)
