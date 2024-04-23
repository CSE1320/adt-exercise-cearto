all:
	@gcc -std=c11 -g -Wall src/*.c src/*.h -o ./array -lm
clean:
	rm ./mysolution
	@echo Cleanup complete!
run: all
	@./array
test:
	python ../scripts/sanitycheck.py 
mem: 
	@valgrind ./array
install:
	pip install python-benedict
submit:
	@echo "You are in the wrong folder. cd .. and run make submit from the project directory"

# INSTRUCTOR ONLY
solution:
	gcc -std=c11 -g -Wall -I../include ../obj/*.o src/problem.c -o ./mysolution -lm
	python ../scripts/sanitycheck.py 
update: 
	python ../scripts/generate_solutions.py 


	