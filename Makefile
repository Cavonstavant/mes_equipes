##
## EPITECH PROJECT, 2022
## B-PSU-400-NAN-4-1-malloc-constant.vigneron
## File description:
## Makefile
##

NAME := my_teams

$(NAME):
	cmake .
	make

clean:
	cmake . && make clean
	rm -rf libs/

fclean:
	cmake . && make fclean

re:
	cmake . && make re
	rm -rf libs/

all:
	cmake . && make
	rm -rf libs/

tests:
	cmake -B ./build-with-coverage -G
	"Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -DENABLE_CODE_COVERAGE=ON
	cmake --build ./build-with-coverage
	cd ./build-with-coverage ; ctest
	mkdir coverage-report
	find . -name "*.gcda" -exec cp {} coverage-report/ \;
	find . -name "*.gcno" -exec cp {} coverage-report \;
	cd coverage-report
	gcovr -r ../../

user_journey:
	cmake --build ./build
	cd ./build ; ctest --verbose

.PHONY: all clean fclean re tests