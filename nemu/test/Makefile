all: expr run

expr: expr.c
	@rm -rf expr
	@gcc expr.c -o expr -g

run:
	@./expr

clean:
	@rm -rf expr core.*
