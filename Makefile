SYS=$(shell uname)
APP=Thankful.exe
OBJS=main.o
ifneq (, $(findstring Darwin, $(SYS)))
SDLLIBS=$(shell sdl-config --static-libs)
SDLFLAGS=$(shell sdl-config --cflags)
else ifneq (, $(findstring mingw, $(SYS)))
SDLLIBS=BLADEPUTSTUFFHERE
SDLFLAGS=BLADEYOUCANPROBABLYDELETETHIS
endif

all: $(APP)

$(APP) : $(OBJS)
	g++ -o $(APP) $(OBJS) $(SDLLIBS) $(SDLFLAGS)

%.o : %.cpp
	g++ $< -c
