
.PHONY: all mtest totest mgame togame iplace ibot itest clean

all: mtest mgame

togame: bin/game.exe
	bin/game.exe

totest: bin/test.exe
	bin/test.exe

mgame: iplace ibot bin
	g++ -o bin/game.exe code/bot/mutation.cpp code/bot/cons_and_des_bot.cpp code/bot/micro.cpp code/bot/turn.cpp code/place/spawn_one.cpp code/place/cons_and_des.cpp code/place/generate_place.cpp code/place/print_place.cpp code/place/spawn_bot.cpp code/place/spawn_wall.cpp code/place/spawn_food.cpp code/place/spawn_poison.cpp

mtest: iplace itest bin
	g++ -o bin/test.exe code/test/testing_place.cpp code/place/cons_and_des.cpp code/place/generate_place.cpp code/place/spawn_bot.cpp code/place/spawn_wall.cpp code/place/spawn_food.cpp code/place/spawn_poison.cpp

iplace: code/place/spawn_one.cpp code/place/cons_and_des.cpp code/place/generate_place.cpp code/place/print_place.cpp code/place/spawn_bot.cpp code/place/spawn_wall.cpp code/place/spawn_food.cpp code/place/spawn_poison.cpp

ibot: code/bot/cons_and_des_bot.cpp code/bot/micro.cpp code/bot/turn.cpp code/bot/mutation.cpp

itest: code/test/testing_place.cpp

bin:
	mkdir bin;

clean:
	rm bin/*